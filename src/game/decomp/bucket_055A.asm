// Auto-generated scaffold unit: bucket_055A.asm
#include "../include/common.h"

// Offset: 0x0055A0D0
undefined FUN_0055a0d0() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055a0d0()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0055a0d0                                                 XREF[2]:     FUN_00559eba:00559f2f(c), 
    //                                                                                                         FUN_00559eba:00559f4d(c)  
    //         0055a0d0     MOV        EDX,dword ptr [ESP + Stack[0x8]]
    //         0055a0d4     PUSH       ESI
    //         0055a0d5     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         0055a0d9     PUSH       EDI
    //         0055a0da     TEST       EDX,EDX
    //         0055a0dc     MOV        EAX,ESI
    //         0055a0de     LEA        ECX,[EDX + -0x1]
    //         0055a0e1     JZ         LAB_0055a0f3
    //                               LAB_0055a0e3                                                 XREF[1]:     0055a0f1(j)  
    //         0055a0e3     CMP        word ptr [EAX],0x0
    //         0055a0e7     JZ         LAB_0055a0f9
    //         0055a0e9     ADD        EAX,0x2
    //         0055a0ec     MOV        EDI,ECX
    //         0055a0ee     DEC        ECX
    //         0055a0ef     TEST       EDI,EDI
    //         0055a0f1     JNZ        LAB_0055a0e3
    //                               LAB_0055a0f3                                                 XREF[1]:     0055a0e1(j)  
    //         0055a0f3     CMP        word ptr [EAX],0x0
    //         0055a0f7     JNZ        LAB_0055a100
    //                               LAB_0055a0f9                                                 XREF[1]:     0055a0e7(j)  
    //         0055a0f9     SUB        EAX,ESI
    //         0055a0fb     SAR        EAX,0x1
    //         0055a0fd     POP        EDI
    //         0055a0fe     POP        ESI
    //         0055a0ff     RET
    //                               LAB_0055a100                                                 XREF[1]:     0055a0f7(j)  
    //         0055a100     POP        EDI
    //         0055a101     MOV        EAX,EDX
    //         0055a103     POP        ESI
    //         0055a104     RET
}

// Offset: 0x0055A110
undefined crtCompareStringA() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined ___crtCompareStringA()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               ___crtCompareStringA                                         XREF[1]:     __mbsnbicoll:00559ad5(c)  
    //         0055a110     MOV        EAX,[DAT_00888448]
    //         0055a115     SUB        ESP,0x18
    //         0055a118     TEST       EAX,EAX
    //         0055a11a     PUSH       EBX
    //         0055a11b     MOV        EBX,dword ptr [->KERNEL32.DLL::CompareStringA]   = 0048abe4
    //         0055a121     PUSH       EBP
    //         0055a122     PUSH       ESI
    //         0055a123     PUSH       EDI
    //         0055a124     JNZ        LAB_0055a174
    //         0055a126     PUSH       0x1
    //         0055a128     PUSH       s_                                               = ""
    //         0055a12d     PUSH       0x1
    //         0055a12f     PUSH       s_                                               = ""
    //         0055a134     PUSH       0x0
    //         0055a136     PUSH       0x0
    //         0055a138     CALL       EBX=>KERNEL32.DLL::CompareStringA
    //         0055a13a     TEST       EAX,EAX
    //         0055a13c     JZ         LAB_0055a14a
    //         0055a13e     MOV        dword ptr [DAT_00888448],0x2
    //         0055a148     JMP        LAB_0055a174
    //                               LAB_0055a14a                                                 XREF[1]:     0055a13c(j)  
    //         0055a14a     PUSH       0x1
    //         0055a14c     PUSH       u_                                               = u""
    //         0055a151     PUSH       offset DAT_fffffff4
    //         0055a153     PUSH       u_                                               = u""
    //         0055a158     PUSH       0x0
    //         0055a15a     PUSH       0x0
    //         0055a15c     CALL       dword ptr [->KERNEL32.DLL::CompareStringW]       = 0048ba5a
    //         0055a162     TEST       EAX,EAX
    //         0055a164     JZ         LAB_0055a330
    //         0055a16a     MOV        dword ptr [DAT_00888448],0x1
    //                               LAB_0055a174                                                 XREF[2]:     0055a124(j), 0055a148(j)  
    //         0055a174     MOV        ESI,dword ptr [ESP + Stack[0x10]]
    //         0055a178     TEST       ESI,ESI
    //         0055a17a     JLE        LAB_0055a18e
    //         0055a17c     MOV        EBP,dword ptr [ESP + Stack[0xc]]
    //         0055a180     PUSH       ESI
    //         0055a181     PUSH       EBP=>DAT_fffffff8
    //         0055a182     CALL       FUN_0055a3e0                                     undefined FUN_0055a3e0()
    //         0055a187     ADD        ESP,0x8
    //         0055a18a     MOV        ESI,EAX
    //         0055a18c     JMP        LAB_0055a192
    //                               LAB_0055a18e                                                 XREF[1]:     0055a17a(j)  
    //         0055a18e     MOV        EBP,dword ptr [ESP + 0x34]
    //                               LAB_0055a192                                                 XREF[1]:     0055a18c(j)  
    //         0055a192     MOV        EDI,dword ptr [ESP + 0x40]
    //         0055a196     TEST       EDI,EDI
    //         0055a198     JLE        LAB_0055a1ae
    //         0055a19a     MOV        EAX,dword ptr [ESP + 0x3c]
    //         0055a19e     PUSH       EDI
    //         0055a19f     PUSH       EAX=>DAT_fffffff8
    //         0055a1a0     CALL       FUN_0055a3e0                                     undefined FUN_0055a3e0()
    //         0055a1a5     ADD        ESP,0x8
    //         0055a1a8     MOV        dword ptr [ESP + 0x40],EAX
    //         0055a1ac     MOV        EDI,EAX
    //                               LAB_0055a1ae                                                 XREF[1]:     0055a198(j)  
    //         0055a1ae     MOV        EAX,[DAT_00888448]
    //         0055a1b3     CMP        EAX,0x2
    //         0055a1b6     JNZ        LAB_0055a1d4
    //         0055a1b8     MOV        ECX,dword ptr [ESP + 0x3c]
    //         0055a1bc     MOV        EDX,dword ptr [ESP + 0x30]
    //         0055a1c0     MOV        EAX,dword ptr [ESP + 0x2c]
    //         0055a1c4     PUSH       EDI
    //         0055a1c5     PUSH       ECX=>DAT_fffffff8
    //         0055a1c6     PUSH       ESI=>DAT_fffffff4
    //         0055a1c7     PUSH       EBP=>DAT_fffffff0
    //         0055a1c8     PUSH       EDX
    //         0055a1c9     PUSH       EAX
    //         0055a1ca     CALL       EBX=>KERNEL32.DLL::CompareStringA
    //         0055a1cc     POP        EDI
    //         0055a1cd     POP        ESI
    //         0055a1ce     POP        EBP
    //         0055a1cf     POP        EBX
    //         0055a1d0     ADD        ESP,0x18
    //         0055a1d3     RET
    //                               LAB_0055a1d4                                                 XREF[1]:     0055a1b6(j)  
    //         0055a1d4     CMP        EAX,0x1
    //         0055a1d7     JNZ        LAB_0055a3cd
    //         0055a1dd     MOV        EBX,dword ptr [ESP + 0x44]
    //         0055a1e1     XOR        EAX,EAX
    //         0055a1e3     TEST       EBX,EBX
    //         0055a1e5     MOV        dword ptr [ESP + 0x10],EAX
    //         0055a1e9     MOV        dword ptr [ESP + 0x38],EAX
    //         0055a1ed     JNZ        LAB_0055a1f5
    //         0055a1ef     MOV        EBX,dword ptr [___lc_codepage]
    //                               LAB_0055a1f5                                                 XREF[1]:     0055a1ed(j)  
    //         0055a1f5     TEST       ESI,ESI
    //         0055a1f7     JZ         LAB_0055a201
    //         0055a1f9     TEST       EDI,EDI
    //         0055a1fb     JNZ        LAB_0055a2fc
    //                               LAB_0055a201                                                 XREF[1]:     0055a1f7(j)  
    //         0055a201     CMP        ESI,EDI
    //         0055a203     JNZ        LAB_0055a212
    //         0055a205     MOV        EAX,0x2
    //         0055a20a     POP        EDI
    //         0055a20b     POP        ESI
    //         0055a20c     POP        EBP
    //         0055a20d     POP        EBX
    //         0055a20e     ADD        ESP,0x18
    //         0055a211     RET
    //                               LAB_0055a212                                                 XREF[1]:     0055a203(j)  
    //         0055a212     CMP        EDI,0x1
    //         0055a215     JLE        LAB_0055a224
    //         0055a217     MOV        EAX,0x1
    //         0055a21c     POP        EDI
    //         0055a21d     POP        ESI
    //         0055a21e     POP        EBP
    //         0055a21f     POP        EBX
    //         0055a220     ADD        ESP,0x18
    //         0055a223     RET
    //                               LAB_0055a224                                                 XREF[1]:     0055a215(j)  
    //         0055a224     CMP        ESI,0x1
    //         0055a227     JLE        LAB_0055a236
    //         0055a229     MOV        EAX,0x3
    //         0055a22e     POP        EDI
    //         0055a22f     POP        ESI
    //         0055a230     POP        EBP
    //         0055a231     POP        EBX
    //         0055a232     ADD        ESP,0x18
    //         0055a235     RET
    //                               LAB_0055a236                                                 XREF[1]:     0055a227(j)  
    //         0055a236     LEA        ECX,[ESP + 0x14]
    //         0055a23a     PUSH       ECX
    //         0055a23b     PUSH       EBX=>DAT_fffffff8
    //         0055a23c     CALL       dword ptr [->KERNEL32.DLL::GetCPInfo]            = 0048b87e
    //         0055a242     TEST       EAX,EAX
    //         0055a244     JNZ        LAB_0055a24e
    //         0055a246     POP        EDI
    //         0055a247     POP        ESI
    //         0055a248     POP        EBP
    //         0055a249     POP        EBX
    //         0055a24a     ADD        ESP,0x18
    //         0055a24d     RET
    //                               LAB_0055a24e                                                 XREF[1]:     0055a244(j)  
    //         0055a24e     TEST       ESI,ESI
    //         0055a250     JLE        LAB_0055a29d
    //         0055a252     CMP        dword ptr [ESP + 0x14],0x2
    //         0055a257     JNC        LAB_0055a266
    //         0055a259     MOV        EAX,0x3
    //         0055a25e     POP        EDI
    //         0055a25f     POP        ESI
    //         0055a260     POP        EBP
    //         0055a261     POP        EBX
    //         0055a262     ADD        ESP,0x18
    //         0055a265     RET
    //                               LAB_0055a266                                                 XREF[1]:     0055a257(j)  
    //         0055a266     MOV        CL,byte ptr [ESP + 0x1a]
    //         0055a26a     LEA        EAX,[ESP + 0x1a]
    //         0055a26e     TEST       CL,CL
    //         0055a270     JZ         LAB_0055a290
    //                               LAB_0055a272                                                 XREF[1]:     0055a28e(j)  
    //         0055a272     MOV        DL,byte ptr [EAX + 0x1]
    //         0055a275     TEST       DL,DL
    //         0055a277     JZ         LAB_0055a290
    //         0055a279     MOV        CL,byte ptr [EBP]
    //         0055a27c     MOV        BL,byte ptr [EAX]
    //         0055a27e     CMP        CL,BL
    //         0055a280     JC         LAB_0055a286
    //         0055a282     CMP        CL,DL
    //         0055a284     JBE        LAB_0055a2ef
    //                               LAB_0055a286                                                 XREF[1]:     0055a280(j)  
    //         0055a286     MOV        CL,byte ptr [EAX + 0x2]
    //         0055a289     ADD        EAX,0x2
    //         0055a28c     TEST       CL,CL
    //         0055a28e     JNZ        LAB_0055a272
    //                               LAB_0055a290                                                 XREF[2]:     0055a270(j), 0055a277(j)  
    //         0055a290     MOV        EAX,0x3
    //         0055a295     POP        EDI
    //         0055a296     POP        ESI
    //         0055a297     POP        EBP
    //         0055a298     POP        EBX
    //         0055a299     ADD        ESP,0x18
    //         0055a29c     RET
    //                               LAB_0055a29d                                                 XREF[1]:     0055a250(j)  
    //         0055a29d     TEST       EDI,EDI
    //         0055a29f     JLE        LAB_0055a2fc
    //         0055a2a1     CMP        dword ptr [ESP + 0x14],0x2
    //         0055a2a6     JNC        LAB_0055a2b5
    //         0055a2a8     MOV        EAX,0x1
    //         0055a2ad     POP        EDI
    //         0055a2ae     POP        ESI
    //         0055a2af     POP        EBP
    //         0055a2b0     POP        EBX
    //         0055a2b1     ADD        ESP,0x18
    //         0055a2b4     RET
    //                               LAB_0055a2b5                                                 XREF[1]:     0055a2a6(j)  
    //         0055a2b5     MOV        CL,byte ptr [ESP + 0x1a]
    //         0055a2b9     LEA        EAX,[ESP + 0x1a]
    //         0055a2bd     TEST       CL,CL
    //         0055a2bf     JZ         LAB_0055a2e2
    //                               LAB_0055a2c1                                                 XREF[1]:     0055a2e0(j)  
    //         0055a2c1     MOV        DL,byte ptr [EAX + 0x1]
    //         0055a2c4     TEST       DL,DL
    //         0055a2c6     JZ         LAB_0055a2e2
    //         0055a2c8     MOV        ECX,dword ptr [ESP + 0x3c]
    //         0055a2cc     MOV        BL,byte ptr [EAX]
    //         0055a2ce     MOV        CL,byte ptr [ECX]
    //         0055a2d0     CMP        CL,BL
    //         0055a2d2     JC         LAB_0055a2d8
    //         0055a2d4     CMP        CL,DL
    //         0055a2d6     JBE        LAB_0055a2ef
    //                               LAB_0055a2d8                                                 XREF[1]:     0055a2d2(j)  
    //         0055a2d8     MOV        CL,byte ptr [EAX + 0x2]
    //         0055a2db     ADD        EAX,0x2
    //         0055a2de     TEST       CL,CL
    //         0055a2e0     JNZ        LAB_0055a2c1
    //                               LAB_0055a2e2                                                 XREF[2]:     0055a2bf(j), 0055a2c6(j)  
    //         0055a2e2     MOV        EAX,0x1
    //         0055a2e7     POP        EDI
    //         0055a2e8     POP        ESI
    //         0055a2e9     POP        EBP
    //         0055a2ea     POP        EBX
    //         0055a2eb     ADD        ESP,0x18
    //         0055a2ee     RET
    //                               LAB_0055a2ef                                                 XREF[2]:     0055a284(j), 0055a2d6(j)  
    //         0055a2ef     MOV        EAX,0x2
    //         0055a2f4     POP        EDI
    //         0055a2f5     POP        ESI
    //         0055a2f6     POP        EBP
    //         0055a2f7     POP        EBX
    //         0055a2f8     ADD        ESP,0x18
    //         0055a2fb     RET
    //                               LAB_0055a2fc                                                 XREF[2]:     0055a1fb(j), 0055a29f(j)  
    //         0055a2fc     MOV        EDI,dword ptr [->KERNEL32.DLL::MultiByteToWide   = 0048b8da
    //         0055a302     PUSH       0x0
    //         0055a304     PUSH       0x0=>DAT_fffffff8
    //         0055a306     PUSH       ESI=>DAT_fffffff4
    //         0055a307     PUSH       EBP=>DAT_fffffff0
    //         0055a308     PUSH       0x9
    //         0055a30a     PUSH       EBX
    //         0055a30b     CALL       EDI=>KERNEL32.DLL::MultiByteToWideChar
    //         0055a30d     MOV        EBP,EAX
    //         0055a30f     TEST       EBP,EBP
    //         0055a311     JNZ        LAB_0055a31b
    //         0055a313     POP        EDI
    //         0055a314     POP        ESI
    //         0055a315     POP        EBP
    //         0055a316     POP        EBX
    //         0055a317     ADD        ESP,0x18
    //         0055a31a     RET
    //                               LAB_0055a31b                                                 XREF[1]:     0055a311(j)  
    //         0055a31b     LEA        EDX,[EBP + EBP*0x1]
    //         0055a31f     PUSH       EDX
    //         0055a320     CALL       malloc                                           undefined malloc()
    //         0055a325     ADD        ESP,0x4
    //         0055a328     MOV        dword ptr [ESP + 0x44],EAX
    //         0055a32c     TEST       EAX,EAX
    //         0055a32e     JNZ        LAB_0055a33a
    //                               LAB_0055a330                                                 XREF[1]:     0055a164(j)  
    //         0055a330     XOR        EAX,EAX
    //         0055a332     POP        EDI
    //         0055a333     POP        ESI
    //         0055a334     POP        EBP
    //         0055a335     POP        EBX
    //         0055a336     ADD        ESP,0x18
    //         0055a339     RET
    //                               LAB_0055a33a                                                 XREF[1]:     0055a32e(j)  
    //         0055a33a     PUSH       EBP
    //         0055a33b     PUSH       EAX=>DAT_fffffff8
    //         0055a33c     MOV        EAX,dword ptr [ESP + 0x3c]
    //         0055a340     PUSH       ESI=>DAT_fffffff4
    //         0055a341     PUSH       EAX=>DAT_fffffff0
    //         0055a342     PUSH       0x1
    //         0055a344     PUSH       EBX
    //         0055a345     CALL       EDI=>KERNEL32.DLL::MultiByteToWideChar
    //         0055a347     TEST       EAX,EAX
    //         0055a349     JZ         LAB_0055a3ad
    //         0055a34b     MOV        ECX,dword ptr [ESP + 0x40]
    //         0055a34f     MOV        EDX,dword ptr [ESP + 0x3c]
    //         0055a353     PUSH       0x0
    //         0055a355     PUSH       0x0=>DAT_fffffff8
    //         0055a357     PUSH       ECX=>DAT_fffffff4
    //         0055a358     PUSH       EDX=>DAT_fffffff0
    //         0055a359     PUSH       0x9
    //         0055a35b     PUSH       EBX
    //         0055a35c     CALL       EDI=>KERNEL32.DLL::MultiByteToWideChar
    //         0055a35e     MOV        ESI,EAX
    //         0055a360     TEST       ESI,ESI
    //         0055a362     JZ         LAB_0055a3ad
    //         0055a364     LEA        EAX,[ESI + ESI*0x1]
    //         0055a367     PUSH       EAX
    //         0055a368     CALL       malloc                                           undefined malloc()
    //         0055a36d     ADD        ESP,0x4
    //         0055a370     MOV        dword ptr [ESP + 0x38],EAX
    //         0055a374     TEST       EAX,EAX
    //         0055a376     JZ         LAB_0055a3ad
    //         0055a378     MOV        ECX,dword ptr [ESP + 0x40]
    //         0055a37c     MOV        EDX,dword ptr [ESP + 0x3c]
    //         0055a380     PUSH       ESI
    //         0055a381     PUSH       EAX=>DAT_fffffff8
    //         0055a382     PUSH       ECX=>DAT_fffffff4
    //         0055a383     PUSH       EDX=>DAT_fffffff0
    //         0055a384     PUSH       0x1
    //         0055a386     PUSH       EBX
    //         0055a387     CALL       EDI=>KERNEL32.DLL::MultiByteToWideChar
    //         0055a389     TEST       EAX,EAX
    //         0055a38b     JZ         LAB_0055a3ad
    //         0055a38d     MOV        EAX,dword ptr [ESP + 0x38]
    //         0055a391     MOV        ECX,dword ptr [ESP + 0x44]
    //         0055a395     MOV        EDX,dword ptr [ESP + 0x30]
    //         0055a399     PUSH       ESI
    //         0055a39a     PUSH       EAX=>DAT_fffffff8
    //         0055a39b     MOV        EAX,dword ptr [ESP + 0x34]
    //         0055a39f     PUSH       EBP=>DAT_fffffff4
    //         0055a3a0     PUSH       ECX=>DAT_fffffff0
    //         0055a3a1     PUSH       EDX
    //         0055a3a2     PUSH       EAX
    //         0055a3a3     CALL       dword ptr [->KERNEL32.DLL::CompareStringW]       = 0048ba5a
    //         0055a3a9     MOV        ESI,EAX
    //         0055a3ab     JMP        LAB_0055a3b1
    //                               LAB_0055a3ad                                                 XREF[4]:     0055a349(j), 0055a362(j), 
    //                                                                                                         0055a376(j), 0055a38b(j)  
    //         0055a3ad     MOV        ESI,dword ptr [ESP + 0x10]
    //                               LAB_0055a3b1                                                 XREF[1]:     0055a3ab(j)  
    //         0055a3b1     MOV        ECX,dword ptr [ESP + 0x44]
    //         0055a3b5     PUSH       ECX
    //         0055a3b6     CALL       free                                             undefined free()
    //         0055a3bb     MOV        EDX,dword ptr [ESP + 0x3c]
    //         0055a3bf     ADD        ESP,0x4
    //         0055a3c2     PUSH       EDX
    //         0055a3c3     CALL       free                                             undefined free()
    //         0055a3c8     ADD        ESP,0x4
    //         0055a3cb     MOV        EAX,ESI
    //                               LAB_0055a3cd                                                 XREF[1]:     0055a1d7(j)  
    //         0055a3cd     POP        EDI
    //         0055a3ce     POP        ESI
    //         0055a3cf     POP        EBP
    //         0055a3d0     POP        EBX
    //         0055a3d1     ADD        ESP,0x18
    //         0055a3d4     RET
}

// Offset: 0x0055A3E0
undefined FUN_0055a3e0() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055a3e0()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0055a3e0                                                 XREF[2]:     ___crtCompareStringA:0055a182(c), 
    //                                                                                                         ___crtCompareStringA:0055a1a0(c)  
    //         0055a3e0     MOV        EDX,dword ptr [ESP + Stack[0x8]]
    //         0055a3e4     PUSH       ESI
    //         0055a3e5     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         0055a3e9     TEST       EDX,EDX
    //         0055a3eb     PUSH       EDI
    //         0055a3ec     MOV        EAX,ESI
    //         0055a3ee     LEA        ECX,[EDX + -0x1]
    //         0055a3f1     JZ         LAB_0055a400
    //                               LAB_0055a3f3                                                 XREF[1]:     0055a3fe(j)  
    //         0055a3f3     CMP        byte ptr [EAX],0x0
    //         0055a3f6     JZ         LAB_0055a400
    //         0055a3f8     INC        EAX
    //         0055a3f9     MOV        EDI,ECX
    //         0055a3fb     DEC        ECX
    //         0055a3fc     TEST       EDI,EDI
    //         0055a3fe     JNZ        LAB_0055a3f3
    //                               LAB_0055a400                                                 XREF[2]:     0055a3f1(j), 0055a3f6(j)  
    //         0055a400     CMP        byte ptr [EAX],0x0
    //         0055a403     JNZ        LAB_0055a40a
    //         0055a405     SUB        EAX,ESI
    //         0055a407     POP        EDI
    //         0055a408     POP        ESI
    //         0055a409     RET
    //                               LAB_0055a40a                                                 XREF[1]:     0055a403(j)  
    //         0055a40a     POP        EDI
    //         0055a40b     POP        ESI
    //         0055a40c     MOV        EAX,EDX
    //         0055a40e     RET
}

// Offset: 0x0055A410
undefined crtsetenv() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined ___crtsetenv()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0055a4ea(W), 0055a587(R)  
    //                               ___crtsetenv                                                 XREF[1]:     ___wtomb_environ:00559b44(c)  
    //         0055a410     PUSH       ECX
    //         0055a411     PUSH       EBX
    //         0055a412     PUSH       EBP
    //         0055a413     PUSH       ESI
    //         0055a414     PUSH       EDI
    //         0055a415     MOV        EDI,dword ptr [ESP + Stack[0x4]]
    //         0055a419     TEST       EDI,EDI
    //         0055a41b     JZ         LAB_0055a5ce
    //         0055a421     PUSH       0x3d
    //         0055a423     PUSH       EDI
    //         0055a424     CALL       __mbschr                                         undefined __mbschr()
    //         0055a429     MOV        ESI,EAX
    //         0055a42b     ADD        ESP,0x8
    //         0055a42e     TEST       ESI,ESI
    //         0055a430     JZ         LAB_0055a5ce
    //         0055a436     CMP        EDI,ESI
    //         0055a438     JZ         LAB_0055a5ce
    //         0055a43e     MOV        DL,byte ptr [ESI + 0x1]
    //         0055a441     MOV        ECX,dword ptr [___initenv]
    //         0055a447     XOR        EAX,EAX
    //         0055a449     TEST       DL,DL
    //         0055a44b     SETZ       AL
    //         0055a44e     MOV        EBP,EAX
    //         0055a450     MOV        EAX,[__environ]
    //         0055a455     CMP        EAX,ECX
    //         0055a457     JNZ        LAB_0055a467
    //         0055a459     PUSH       EAX
    //         0055a45a     CALL       FUN_0055a6a0                                     undefined FUN_0055a6a0()
    //         0055a45f     ADD        ESP,0x4
    //         0055a462     MOV        [__environ],EAX
    //                               LAB_0055a467                                                 XREF[1]:     0055a457(j)  
    //         0055a467     TEST       EAX,EAX
    //         0055a469     JNZ        LAB_0055a4e2
    //         0055a46b     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         0055a46f     TEST       EAX,EAX
    //         0055a471     JZ         LAB_0055a48e
    //         0055a473     MOV        EAX,[__wenviron]
    //         0055a478     TEST       EAX,EAX
    //         0055a47a     JZ         LAB_0055a48e
    //         0055a47c     CALL       ___wtomb_environ                                 undefined ___wtomb_environ()
    //         0055a481     TEST       EAX,EAX
    //         0055a483     JZ         LAB_0055a4dd
    //         0055a485     OR         EAX,0xffffffff
    //         0055a488     POP        EDI
    //         0055a489     POP        ESI
    //         0055a48a     POP        EBP
    //         0055a48b     POP        EBX
    //         0055a48c     POP        ECX
    //         0055a48d     RET
    //                               LAB_0055a48e                                                 XREF[2]:     0055a471(j), 0055a47a(j)  
    //         0055a48e     TEST       EBP,EBP
    //         0055a490     JZ         LAB_0055a49a
    //         0055a492     XOR        EAX,EAX
    //         0055a494     POP        EDI
    //         0055a495     POP        ESI
    //         0055a496     POP        EBP
    //         0055a497     POP        EBX
    //         0055a498     POP        ECX
    //         0055a499     RET
    //                               LAB_0055a49a                                                 XREF[1]:     0055a490(j)  
    //         0055a49a     PUSH       0x4
    //         0055a49c     CALL       malloc                                           undefined malloc()
    //         0055a4a1     ADD        ESP,0x4
    //         0055a4a4     MOV        [__environ],EAX
    //         0055a4a9     TEST       EAX,EAX
    //         0055a4ab     JZ         LAB_0055a5ce
    //         0055a4b1     MOV        dword ptr [EAX],0x0
    //         0055a4b7     MOV        EAX,[__wenviron]
    //         0055a4bc     TEST       EAX,EAX
    //         0055a4be     JNZ        LAB_0055a4dd
    //         0055a4c0     PUSH       0x4
    //         0055a4c2     CALL       malloc                                           undefined malloc()
    //         0055a4c7     ADD        ESP,0x4
    //         0055a4ca     MOV        [__wenviron],EAX
    //         0055a4cf     TEST       EAX,EAX
    //         0055a4d1     JZ         LAB_0055a5ce
    //         0055a4d7     MOV        dword ptr [EAX],0x0
    //                               LAB_0055a4dd                                                 XREF[2]:     0055a483(j), 0055a4be(j)  
    //         0055a4dd     MOV        EAX,[__environ]
    //                               LAB_0055a4e2                                                 XREF[1]:     0055a469(j)  
    //         0055a4e2     MOV        EBX,EAX
    //         0055a4e4     MOV        EAX,ESI
    //         0055a4e6     SUB        EAX,EDI
    //         0055a4e8     PUSH       EAX
    //         0055a4e9     PUSH       EDI
    //         0055a4ea     MOV        dword ptr [ESP + local_4],EAX
    //         0055a4ee     CALL       FUN_0055a620                                     undefined FUN_0055a620()
    //         0055a4f3     MOV        ESI,EAX
    //         0055a4f5     ADD        ESP,0x8
    //         0055a4f8     TEST       ESI,ESI
    //         0055a4fa     JL         LAB_0055a5df
    //         0055a500     CMP        dword ptr [EBX],0x0
    //         0055a503     JZ         LAB_0055a5df
    //         0055a509     TEST       EBP,EBP
    //         0055a50b     JZ         LAB_0055a5d7
    //         0055a511     MOV        ECX,dword ptr [EBX + ESI*0x4]
    //         0055a514     LEA        EDI,[EBX + ESI*0x4]
    //         0055a517     PUSH       ECX
    //         0055a518     CALL       free                                             undefined free()
    //         0055a51d     MOV        EAX,dword ptr [EDI]
    //         0055a51f     ADD        ESP,0x4
    //         0055a522     TEST       EAX,EAX
    //         0055a524     JZ         LAB_0055a539
    //         0055a526     MOV        EAX,EDI
    //                               LAB_0055a528                                                 XREF[1]:     0055a537(j)  
    //         0055a528     MOV        EDX,dword ptr [EAX + 0x4]
    //         0055a52b     ADD        EAX,0x4
    //         0055a52e     MOV        dword ptr [EDI],EDX
    //         0055a530     INC        ESI
    //         0055a531     MOV        ECX,dword ptr [EAX]
    //         0055a533     MOV        EDI,EAX
    //         0055a535     TEST       ECX,ECX
    //         0055a537     JNZ        LAB_0055a528
    //                               LAB_0055a539                                                 XREF[1]:     0055a524(j)  
    //         0055a539     LEA        EAX,[ESI*0x4 + 0x0]
    //         0055a540     PUSH       EAX
    //         0055a541     PUSH       EBX
    //         0055a542     CALL       realloc                                          undefined realloc()
    //         0055a547     ADD        ESP,0x8
    //         0055a54a     TEST       EAX,EAX
    //         0055a54c     JZ         LAB_0055a553
    //         0055a54e     MOV        [__environ],EAX
    //                               LAB_0055a553                                                 XREF[1]:     0055a54c(j)  
    //         0055a553     MOV        EDI,dword ptr [ESP + Stack[0x4]]
    //                               LAB_0055a557                                                 XREF[2]:     0055a5da(j), 0055a60e(j)  
    //         0055a557     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         0055a55b     TEST       EAX,EAX
    //         0055a55d     JZ         LAB_0055a5c6
    //         0055a55f     OR         ECX,0xffffffff
    //         0055a562     XOR        EAX,EAX
    //         0055a564     SCASB.RE   ES:EDI
    //         0055a566     NOT        ECX
    //         0055a568     INC        ECX
    //         0055a569     PUSH       ECX
    //         0055a56a     CALL       malloc                                           undefined malloc()
    //         0055a56f     MOV        EBX,EAX
    //         0055a571     ADD        ESP,0x4
    //         0055a574     TEST       EBX,EBX
    //         0055a576     JZ         LAB_0055a5c6
    //         0055a578     MOV        EDI,dword ptr [ESP + Stack[0x4]]
    //         0055a57c     OR         ECX,0xffffffff
    //         0055a57f     XOR        EAX,EAX
    //         0055a581     SCASB.RE   ES:EDI
    //         0055a583     NOT        ECX
    //         0055a585     SUB        EDI,ECX
    //         0055a587     MOV        EAX,dword ptr [ESP + local_4]
    //         0055a58b     MOV        EDX,ECX
    //         0055a58d     MOV        ESI,EDI
    //         0055a58f     MOV        EDI,EBX
    //         0055a591     SHR        ECX,0x2
    //         0055a594     MOVSD.REP  ES:EDI,ESI
    //         0055a596     MOV        ECX,EDX
    //         0055a598     AND        ECX,0x3
    //         0055a59b     NEG        EBP
    //         0055a59d     MOVSB.REP  ES:EDI,ESI
    //         0055a59f     SBB        EBP,EBP
    //         0055a5a1     MOV        byte ptr [EBX + EAX*0x1],0x0
    //         0055a5a5     LEA        EAX,[EBX + EAX*0x1 + 0x1]
    //         0055a5a9     NOT        EBP
    //         0055a5ab     AND        EBP,EAX
    //         0055a5ad     PUSH       EBP
    //         0055a5ae     PUSH       EBX
    //         0055a5af     CALL       dword ptr [->KERNEL32.DLL::SetEnvironmentVaria   = 0048b786
    //         0055a5b5     PUSH       EBX
    //         0055a5b6     CALL       free                                             undefined free()
    //         0055a5bb     ADD        ESP,0x4
    //         0055a5be     XOR        EAX,EAX
    //         0055a5c0     POP        EDI
    //         0055a5c1     POP        ESI
    //         0055a5c2     POP        EBP
    //         0055a5c3     POP        EBX
    //         0055a5c4     POP        ECX
    //         0055a5c5     RET
    //                               LAB_0055a5c6                                                 XREF[3]:     0055a55d(j), 0055a576(j), 
    //                                                                                                         0055a5e1(j)  
    //         0055a5c6     XOR        EAX,EAX
    //         0055a5c8     POP        EDI
    //         0055a5c9     POP        ESI
    //         0055a5ca     POP        EBP
    //         0055a5cb     POP        EBX
    //         0055a5cc     POP        ECX
    //         0055a5cd     RET
    //                               LAB_0055a5ce                                                 XREF[6]:     0055a41b(j), 0055a430(j), 
    //                                                                                                         0055a438(j), 0055a4ab(j), 
    //                                                                                                         0055a4d1(j), 0055a5fc(j)  
    //         0055a5ce     POP        EDI
    //         0055a5cf     POP        ESI
    //         0055a5d0     POP        EBP
    //         0055a5d1     OR         EAX,0xffffffff
    //         0055a5d4     POP        EBX
    //         0055a5d5     POP        ECX
    //         0055a5d6     RET
    //                               LAB_0055a5d7                                                 XREF[1]:     0055a50b(j)  
    //         0055a5d7     MOV        dword ptr [EBX + ESI*0x4],EDI
    //         0055a5da     JMP        LAB_0055a557
    //                               LAB_0055a5df                                                 XREF[2]:     0055a4fa(j), 0055a503(j)  
    //         0055a5df     TEST       EBP,EBP
    //         0055a5e1     JNZ        LAB_0055a5c6
    //         0055a5e3     TEST       ESI,ESI
    //         0055a5e5     JGE        LAB_0055a5e9
    //         0055a5e7     NEG        ESI
    //                               LAB_0055a5e9                                                 XREF[1]:     0055a5e5(j)  
    //         0055a5e9     LEA        ECX,[ESI*0x4 + 0x8]
    //         0055a5f0     PUSH       ECX
    //         0055a5f1     PUSH       EBX
    //         0055a5f2     CALL       realloc                                          undefined realloc()
    //         0055a5f7     ADD        ESP,0x8
    //         0055a5fa     TEST       EAX,EAX
    //         0055a5fc     JZ         LAB_0055a5ce
    //         0055a5fe     MOV        dword ptr [EAX + ESI*0x4],EDI
    //         0055a601     MOV        dword ptr [EAX + ESI*0x4 + 0x4],0x0
    //         0055a609     MOV        [__environ],EAX
    //         0055a60e     JMP        LAB_0055a557
}

// Offset: 0x0055A620
undefined FUN_0055a620() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055a620()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0055a620                                                 XREF[1]:     ___crtsetenv:0055a4ee(c)  
    //         0055a620     PUSH       EBX
    //         0055a621     PUSH       ESI
    //         0055a622     MOV        ESI,dword ptr [__environ]
    //         0055a628     PUSH       EDI
    //         0055a629     MOV        EAX,dword ptr [ESI]
    //         0055a62b     TEST       EAX,EAX
    //         0055a62d     JZ         LAB_0055a681
    //         0055a62f     MOV        EDI,dword ptr [ESP + Stack[0x8]]
    //         0055a633     MOV        EBX,dword ptr [ESP + Stack[0x4]]
    //                               LAB_0055a637                                                 XREF[1]:     0055a65b(j)  
    //         0055a637     PUSH       EDI
    //         0055a638     PUSH       EAX
    //         0055a639     PUSH       EBX
    //         0055a63a     CALL       __mbsnbicoll                                     undefined __mbsnbicoll()
    //         0055a63f     ADD        ESP,0xc
    //         0055a642     TEST       EAX,EAX
    //         0055a644     JNZ        LAB_0055a653
    //         0055a646     MOV        EAX,dword ptr [ESI]
    //         0055a648     MOV        AL,byte ptr [EAX + EDI*0x1]
    //         0055a64b     CMP        AL,0x3d
    //         0055a64d     JZ         LAB_0055a670
    //         0055a64f     TEST       AL,AL
    //         0055a651     JZ         LAB_0055a670
    //                               LAB_0055a653                                                 XREF[1]:     0055a644(j)  
    //         0055a653     MOV        EAX,dword ptr [ESI + 0x4]
    //         0055a656     ADD        ESI,0x4
    //         0055a659     TEST       EAX,EAX
    //         0055a65b     JNZ        LAB_0055a637
    //         0055a65d     MOV        EAX,ESI
    //         0055a65f     MOV        ESI,dword ptr [__environ]
    //         0055a665     SUB        EAX,ESI
    //         0055a667     SAR        EAX,0x2
    //         0055a66a     NEG        EAX
    //         0055a66c     POP        EDI
    //         0055a66d     POP        ESI
    //         0055a66e     POP        EBX
    //         0055a66f     RET
    //                               LAB_0055a670                                                 XREF[2]:     0055a64d(j), 0055a651(j)  
    //         0055a670     MOV        EDX,dword ptr [__environ]
    //         0055a676     MOV        EAX,ESI
    //         0055a678     SUB        EAX,EDX
    //         0055a67a     SAR        EAX,0x2
    //         0055a67d     POP        EDI
    //         0055a67e     POP        ESI
    //         0055a67f     POP        EBX
    //         0055a680     RET
    //                               LAB_0055a681                                                 XREF[1]:     0055a62d(j)  
    //         0055a681     MOV        EAX,ESI
    //         0055a683     MOV        ESI,dword ptr [__environ]
    //         0055a689     SUB        EAX,ESI
    //         0055a68b     POP        EDI
    //         0055a68c     SAR        EAX,0x2
    //         0055a68f     POP        ESI
    //         0055a690     POP        EBX
    //         0055a691     NEG        EAX
    //         0055a693     RET
}

// Offset: 0x0055A6A0
undefined FUN_0055a6a0() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055a6a0()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0055a6a0                                                 XREF[1]:     ___crtsetenv:0055a45a(c)  
    //         0055a6a0     PUSH       EDI
    //         0055a6a1     MOV        EDI,dword ptr [ESP + Stack[0x4]]
    //         0055a6a5     XOR        ECX,ECX
    //         0055a6a7     TEST       EDI,EDI
    //         0055a6a9     JNZ        LAB_0055a6af
    //         0055a6ab     XOR        EAX,EAX
    //         0055a6ad     POP        EDI
    //         0055a6ae     RET
    //                               LAB_0055a6af                                                 XREF[1]:     0055a6a9(j)  
    //         0055a6af     MOV        EDX,dword ptr [EDI]
    //         0055a6b1     PUSH       ESI
    //         0055a6b2     TEST       EDX,EDX
    //         0055a6b4     PUSH       EBX
    //         0055a6b5     LEA        EAX,[EDI + 0x4]
    //         0055a6b8     JZ         LAB_0055a6c4
    //                               LAB_0055a6ba                                                 XREF[1]:     0055a6c2(j)  
    //         0055a6ba     MOV        EDX,dword ptr [EAX]
    //         0055a6bc     INC        ECX
    //         0055a6bd     ADD        EAX,0x4
    //         0055a6c0     TEST       EDX,EDX
    //         0055a6c2     JNZ        LAB_0055a6ba
    //                               LAB_0055a6c4                                                 XREF[1]:     0055a6b8(j)  
    //         0055a6c4     LEA        EAX,[ECX*0x4 + 0x4]
    //         0055a6cb     PUSH       EAX
    //         0055a6cc     CALL       malloc                                           undefined malloc()
    //         0055a6d1     MOV        ESI,EAX
    //         0055a6d3     ADD        ESP,0x4
    //         0055a6d6     TEST       ESI,ESI
    //         0055a6d8     MOV        EBX,ESI
    //         0055a6da     JNZ        LAB_0055a6e6
    //         0055a6dc     PUSH       0x9
    //         0055a6de     CALL       __amsg_exit                                      undefined __amsg_exit()
    //         0055a6e3     ADD        ESP,0x4
    //                               LAB_0055a6e6                                                 XREF[1]:     0055a6da(j)  
    //         0055a6e6     MOV        EAX,dword ptr [EDI]
    //         0055a6e8     TEST       EAX,EAX
    //         0055a6ea     JZ         LAB_0055a703
    //                               LAB_0055a6ec                                                 XREF[1]:     0055a701(j)  
    //         0055a6ec     PUSH       EAX
    //         0055a6ed     ADD        EDI,0x4
    //         0055a6f0     CALL       __strdup                                         undefined __strdup()
    //         0055a6f5     MOV        dword ptr [ESI],EAX
    //         0055a6f7     MOV        EAX,dword ptr [EDI]
    //         0055a6f9     ADD        ESP,0x4
    //         0055a6fc     ADD        ESI,0x4
    //         0055a6ff     TEST       EAX,EAX
    //         0055a701     JNZ        LAB_0055a6ec
    //                               LAB_0055a703                                                 XREF[1]:     0055a6ea(j)  
    //         0055a703     MOV        EAX,EBX
    //         0055a705     MOV        dword ptr [ESI],0x0
    //         0055a70b     POP        EBX
    //         0055a70c     POP        ESI
    //         0055a70d     POP        EDI
    //         0055a70e     RET
}

// Offset: 0x0055A710
undefined strdup() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __strdup()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __strdup                                                     XREF[1]:     FUN_0055a6a0:0055a6f0(c)  
    //         0055a710     PUSH       EBX
    //         0055a711     PUSH       ESI
    //         0055a712     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         0055a716     PUSH       EDI
    //         0055a717     TEST       ESI,ESI
    //         0055a719     JZ         LAB_0055a75a
    //         0055a71b     MOV        EDI,ESI
    //         0055a71d     OR         ECX,0xffffffff
    //         0055a720     XOR        EAX,EAX
    //         0055a722     SCASB.RE   ES:EDI
    //         0055a724     NOT        ECX
    //         0055a726     PUSH       ECX
    //         0055a727     CALL       malloc                                           undefined malloc()
    //         0055a72c     MOV        EDX,EAX
    //         0055a72e     ADD        ESP,0x4
    //         0055a731     TEST       EDX,EDX
    //         0055a733     JZ         LAB_0055a75a
    //         0055a735     MOV        EDI,ESI
    //         0055a737     OR         ECX,0xffffffff
    //         0055a73a     XOR        EAX,EAX
    //         0055a73c     SCASB.RE   ES:EDI
    //         0055a73e     NOT        ECX
    //         0055a740     SUB        EDI,ECX
    //         0055a742     MOV        ESI,EDI
    //         0055a744     MOV        EBX,ECX
    //         0055a746     MOV        EDI,EDX
    //         0055a748     MOV        EAX,EDI
    //         0055a74a     SHR        ECX,0x2
    //         0055a74d     MOVSD.REP  ES:EDI,ESI
    //         0055a74f     MOV        ECX,EBX
    //         0055a751     AND        ECX,0x3
    //         0055a754     MOVSB.REP  ES:EDI,ESI
    //         0055a756     POP        EDI
    //         0055a757     POP        ESI
    //         0055a758     POP        EBX
    //         0055a759     RET
    //                               LAB_0055a75a                                                 XREF[2]:     0055a719(j), 0055a733(j)  
    //         0055a75a     POP        EDI
    //         0055a75b     POP        ESI
    //         0055a75c     XOR        EAX,EAX
    //         0055a75e     POP        EBX
    //         0055a75f     RET
}

// Offset: 0x0055A760
int opfx(ostream* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall ostream::opfx(void)                                                            *
    //                              *********************************************************************************************************
    //                              int __thiscall opfx(ostream * this)
    //              int               EAX:4          <RETURN>
    //              ostream *         ECX:4 (auto)   this
    //                               ?opfx@ostream@@QAEHXZ                                        XREF[3]:     operator<<:0055a833(c), 
    //                               ostream::opfx                                                             operator<<:0055af3c(c), 
    //                                                                                                         operator<<:0055b007(c)  
    //         0055a760     MOV        EAX,dword ptr [this->field0_0x0]
    //         0055a762     MOV        EDX,dword ptr [EAX + 0x4]
    //         0055a765     MOV        EAX,dword ptr [ECX + EDX*0x1 + this->field5_0x8]
    //         0055a769     ADD        this,EDX
    //         0055a76b     TEST       EAX,EAX
    //         0055a76d     JZ         LAB_0055a777
    //         0055a76f     OR         AL,0x2
    //         0055a771     MOV        dword ptr [ECX + this->field5_0x8],EAX
    //         0055a774     XOR        EAX,EAX
    //         0055a776     RET
    //                               LAB_0055a777                                                 XREF[1]:     0055a76d(j)  
    //         0055a777     MOV        this,dword ptr [ECX + this->field29_0x20]
    //         0055a77a     TEST       this,this
    //         0055a77c     JZ         LAB_0055a783
    //         0055a77e     CALL       ostream::flush                                   ostream * flush(ostream * this)
    //                               LAB_0055a783                                                 XREF[1]:     0055a77c(j)  
    //         0055a783     MOV        EAX,0x1
    //         0055a788     RET
}

// Offset: 0x0055A790
void osfx(ostream* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall ostream::osfx(void)                                                           *
    //                              *********************************************************************************************************
    //                              void __thiscall osfx(ostream * this)
    //              void              <VOID>         <RETURN>
    //              ostream *         ECX:4 (auto)   this
    //                               ?osfx@ostream@@QAEXXZ                                        XREF[3]:     operator<<:0055a84f(c), 
    //                               ostream::osfx                                                             operator<<:0055afbb(c), 
    //                                                                                                         operator<<:0055b0f6(c)  
    //         0055a790     PUSH       ESI
    //         0055a791     MOV        ESI,this
    //         0055a793     MOV        EAX,dword ptr [ESI]
    //         0055a795     MOV        this,dword ptr [EAX + 0x4]
    //         0055a798     MOV        dword ptr [ECX + ESI*0x1 + this->field45_0x30]
    //         0055a7a0     MOV        EDX,dword ptr [ESI]
    //         0055a7a2     MOV        EAX,dword ptr [EDX + 0x4]
    //         0055a7a5     ADD        EAX,ESI
    //         0055a7a7     MOV        this,dword ptr [EAX + 0x24]
    //         0055a7aa     TEST       this,0x20
    //         0055a7ad     JZ         LAB_0055a7c9
    //         0055a7af     MOV        this,dword ptr [EAX + 0x4]
    //         0055a7b2     MOV        EDX,dword ptr [this->field0_0x0]
    //         0055a7b4     CALL       dword ptr [EDX + 0x4]
    //         0055a7b7     CMP        EAX,-0x1
    //         0055a7ba     JNZ        LAB_0055a7c9
    //         0055a7bc     MOV        EAX,dword ptr [ESI]
    //         0055a7be     MOV        this,dword ptr [EAX + 0x4]
    //         0055a7c1     MOV        dword ptr [ECX + ESI*0x1 + this->field5_0x8],0x6
    //                               LAB_0055a7c9                                                 XREF[2]:     0055a7ad(j), 0055a7ba(j)  
    //         0055a7c9     MOV        EDX,dword ptr [ESI]
    //         0055a7cb     MOV        EAX,dword ptr [EDX + 0x4]
    //         0055a7ce     MOV        this,dword ptr [EAX + ESI*0x1 + 0x24]
    //         0055a7d2     TEST       this,0x40
    //         0055a7d5     JZ         LAB_0055a81f
    //         0055a7d7     PUSH       DAT_00591e68
    //         0055a7dc     CALL       fflush                                           undefined fflush()
    //         0055a7e1     ADD        ESP,0x4
    //         0055a7e4     CMP        EAX,-0x1
    //         0055a7e7     JNZ        LAB_0055a7fb
    //         0055a7e9     MOV        this,dword ptr [ESI]
    //         0055a7eb     MOV        EDX,dword ptr [ECX + this->x_floatused]
    //         0055a7ee     MOV        this,dword ptr [EDX + ESI*0x1 + 0x8]
    //         0055a7f2     OR         this,0x2
    //         0055a7f5     LEA        EAX,[EDX + ESI*0x1 + 0x8]
    //         0055a7f9     MOV        dword ptr [EAX],this
    //                               LAB_0055a7fb                                                 XREF[1]:     0055a7e7(j)  
    //         0055a7fb     PUSH       DAT_00591e88
    //         0055a800     CALL       fflush                                           undefined fflush()
    //         0055a805     ADD        ESP,0x4
    //         0055a808     CMP        EAX,-0x1
    //         0055a80b     JNZ        LAB_0055a81f
    //         0055a80d     MOV        EAX,dword ptr [ESI]
    //         0055a80f     MOV        this,dword ptr [EAX + 0x4]
    //         0055a812     LEA        EAX,[ECX + ESI*0x1 + this->field5_0x8]
    //         0055a816     MOV        this,dword ptr [ECX + ESI*0x1 + this->field5_0
    //         0055a81a     OR         this,0x2
    //         0055a81d     MOV        dword ptr [EAX],this
    //                               LAB_0055a81f                                                 XREF[2]:     0055a7d5(j), 0055a80b(j)  
    //         0055a81f     POP        ESI
    //         0055a820     RET
}

// Offset: 0x0055A830
ostream* operator(ostream* this_, char* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: class ostream & __thiscall ostream::operator<<(char const *)                                  *
    //                              *********************************************************************************************************
    //                              ostream * __thiscall operator<<(ostream * this, char * param_1)
    //              ostream *         EAX:4          <RETURN>
    //              ostream *         ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     0055a83c(R)  
    //                               ??6ostream@@QAEAAV0@PBD@Z                                    XREF[6]:     operator<<:00446722(c), 
    //                               ostream::operator<<                                                       operator<<:0046a82f(c), 
    //                                                                                                         operator<<:0046a855(c), 
    //                                                                                                         operator<<:0046a87c(c), 
    //                                                                                                         operator<<:0046a8a3(c), 
    //                                                                                                         operator<<:0046a8c2(c)  
    //         0055a830     PUSH       ESI
    //         0055a831     MOV        ESI,this
    //         0055a833     CALL       ostream::opfx                                    int opfx(ostream * this)
    //         0055a838     TEST       EAX,EAX
    //         0055a83a     JZ         LAB_0055a854
    //         0055a83c     MOV        EAX,dword ptr [ESP + param_1]
    //         0055a840     MOV        this,ESI
    //         0055a842     PUSH       EAX
    //         0055a843     PUSH       s_                                               = ""
    //         0055a848     CALL       ostream::writepad                                ostream * writepad(ostream * this, char * par
    //         0055a84d     MOV        this,ESI
    //         0055a84f     CALL       ostream::osfx                                    void osfx(ostream * this)
    //                               LAB_0055a854                                                 XREF[1]:     0055a83a(j)  
    //         0055a854     MOV        EAX,ESI
    //         0055a856     POP        ESI
    //         0055a857     RET        0x4
}

// Offset: 0x0055A860
ostream* flush(ostream* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: class ostream & __thiscall ostream::flush(void)                                               *
    //                              *********************************************************************************************************
    //                              ostream * __thiscall flush(ostream * this)
    //              ostream *         EAX:4          <RETURN>
    //              ostream *         ECX:4 (auto)   this
    //                               ?flush@ostream@@QAEAAV1@XZ                                   XREF[2]:     opfx:0055a77e(c), 
    //                               ostream::flush                                                            ipfx:0055b742(c)  
    //         0055a860     PUSH       ESI
    //         0055a861     MOV        ESI,this
    //         0055a863     MOV        EAX,dword ptr [ESI]
    //         0055a865     MOV        this,dword ptr [EAX + 0x4]
    //         0055a868     MOV        this,dword ptr [ECX + ESI*0x1 + this->x_floatu
    //         0055a86c     MOV        EDX,dword ptr [this->field0_0x0]
    //         0055a86e     CALL       dword ptr [EDX + 0x4]
    //         0055a871     CMP        EAX,-0x1
    //         0055a874     JNZ        LAB_0055a888
    //         0055a876     MOV        EAX,dword ptr [ESI]
    //         0055a878     MOV        this,dword ptr [EAX + 0x4]
    //         0055a87b     LEA        EAX,[ECX + ESI*0x1 + this->field5_0x8]
    //         0055a87f     MOV        this,dword ptr [ECX + ESI*0x1 + this->field5_0
    //         0055a883     OR         this,0x2
    //         0055a886     MOV        dword ptr [EAX],this
    //                               LAB_0055a888                                                 XREF[1]:     0055a874(j)  
    //         0055a888     MOV        EAX,ESI
    //         0055a88a     POP        ESI
    //         0055a88b     RET
}

// Offset: 0x0055A890
undefined ostream(ostream* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: __thiscall ostream::ostream(void)                                                          *
    //                              *********************************************************************************************************
    //                              undefined __thiscall ostream(ostream * this)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              ostream *         ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0055a89a(W)  
    //                               ??0ostream@@IAE@XZ                                           XREF[1]:     ostream_withassign:0055ab31(c)  
    //                               ostream::ostream
    //         0055a890     PUSH       this
    //         0055a891     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0055a895     PUSH       ESI
    //         0055a896     TEST       EAX,EAX
    //         0055a898     MOV        ESI,this
    //         0055a89a     MOV        dword ptr [ESP + local_4],0x0
    //         0055a8a2     JZ         LAB_0055a8b2
    //         0055a8a4     LEA        this,[ESI + 0x8]
    //         0055a8a7     MOV        dword ptr [ESI],ostream::`vbtable'
    //         0055a8ad     CALL       ios::ios                                         undefined ios(ios * this)
    //                               LAB_0055a8b2                                                 XREF[1]:     0055a8a2(j)  
    //         0055a8b2     MOV        EAX,dword ptr [ESI]
    //         0055a8b4     MOV        this,dword ptr [EAX + 0x4]=>DAT_0057803c         = 00000008h
    //         0055a8b7     MOV        EAX,ESI
    //         0055a8b9     MOV        dword ptr [this->field0_0x0 + ESI*0x1],ostream   = 0055a8d0
    //         0055a8c0     MOV        dword ptr [ESI + 0x4],0x0
    //         0055a8c7     POP        ESI
    //         0055a8c8     POP        this
    //         0055a8c9     RET        0x4
}

// Offset: 0x0055A900
undefined ostream(ostream* this_, streambuf* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall ostream::ostream(class streambuf *)                                                *
    //                              *********************************************************************************************************
    //                              undefined __thiscall ostream(ostream * this, streambuf * param_1)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              ostream *         ECX:4 (auto)   this
    //              streambuf *       Stack[0x4]:4   param_1                   XREF[1]:     0055a94f(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0055a945(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0055a96a(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0055a929(W)  
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[2]:     0055a91f(W), 0055a93d(W)  
    //                               ??0ostream@@QAE@PAVstreambuf@@@Z                             XREF[1]:     ostream_withassign:0055abe6(c)  
    //                               ostream::ostream
    //         0055a900     PUSH       -0x1
    //         0055a902     PUSH       FUN_00561ef6
    //         0055a907     MOV        EAX,FS:[0x0]
    //         0055a90d     PUSH       EAX
    //         0055a90e     MOV        dword ptr FS:[0x0],ESP
    //         0055a915     SUB        ESP,0x8
    //         0055a918     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         0055a91c     PUSH       ESI
    //         0055a91d     MOV        ESI,this
    //         0055a91f     MOV        dword ptr [ESP + local_14],0x0
    //         0055a927     TEST       EAX,EAX
    //         0055a929     MOV        dword ptr [ESP + local_10],ESI
    //         0055a92d     JZ         LAB_0055a94d
    //         0055a92f     LEA        this,[ESI + 0x8]
    //         0055a932     MOV        dword ptr [ESI],ostream::`vbtable'
    //         0055a938     CALL       ios::ios                                         undefined ios(ios * this)
    //         0055a93d     MOV        dword ptr [ESP + local_14],0x1
    //         0055a945     MOV        dword ptr [ESP + local_4],0x0
    //                               LAB_0055a94d                                                 XREF[1]:     0055a92d(j)  
    //         0055a94d     MOV        EAX,dword ptr [ESI]
    //         0055a94f     MOV        EDX,dword ptr [ESP + param_1]
    //         0055a953     PUSH       EDX
    //         0055a954     MOV        this,dword ptr [EAX + 0x4]=>DAT_0057803c         = 00000008h
    //         0055a957     MOV        dword ptr [this->field0_0x0 + ESI*0x1],ostream   = 0055a8d0
    //         0055a95e     MOV        EAX,dword ptr [ESI]
    //         0055a960     MOV        this,dword ptr [EAX + 0x4]=>DAT_0057803c         = 00000008h
    //         0055a963     ADD        this,ESI
    //         0055a965     CALL       ios::init                                        void init(ios * this, streambuf * param_1)
    //         0055a96a     MOV        this,dword ptr [ESP + local_c]
    //         0055a96e     MOV        dword ptr [ESI + 0x4],0x0
    //         0055a975     MOV        EAX,ESI
    //         0055a977     MOV        dword ptr FS:[0x0],this
    //         0055a97e     POP        ESI
    //         0055a97f     ADD        ESP,0x14
    //         0055a982     RET        0x8
}

// Offset: 0x0055A990
undefined ostream(ostream* this_, ostream* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: __thiscall ostream::ostream(class ostream const &)                                         *
    //                              *********************************************************************************************************
    //                              undefined __thiscall ostream(ostream * this, ostream * param_1)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              ostream *         ECX:4 (auto)   this
    //              ostream *         Stack[0x4]:4   param_1                   XREF[1]:     0055a9e2(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0055a9d5(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0055aa03(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0055a9b9(W)  
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[2]:     0055a9af(W), 0055a9cd(W)  
    //                               ??0ostream@@IAE@ABV0@@Z
    //                               ostream::ostream
    //         0055a990     PUSH       -0x1
    //         0055a992     PUSH       FUN_00561f1a
    //         0055a997     MOV        EAX,FS:[0x0]
    //         0055a99d     PUSH       EAX
    //         0055a99e     MOV        dword ptr FS:[0x0],ESP
    //         0055a9a5     SUB        ESP,0x8
    //         0055a9a8     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         0055a9ac     PUSH       ESI
    //         0055a9ad     MOV        ESI,this
    //         0055a9af     MOV        dword ptr [ESP + local_14],0x0
    //         0055a9b7     TEST       EAX,EAX
    //         0055a9b9     MOV        dword ptr [ESP + local_10],ESI
    //         0055a9bd     JZ         LAB_0055a9dd
    //         0055a9bf     LEA        this,[ESI + 0x8]
    //         0055a9c2     MOV        dword ptr [ESI],ostream::`vbtable'
    //         0055a9c8     CALL       ios::ios                                         undefined ios(ios * this)
    //         0055a9cd     MOV        dword ptr [ESP + local_14],0x1
    //         0055a9d5     MOV        dword ptr [ESP + local_4],0x0
    //                               LAB_0055a9dd                                                 XREF[1]:     0055a9bd(j)  
    //         0055a9dd     MOV        EAX,dword ptr [ESI]
    //         0055a9df     MOV        this,dword ptr [EAX + 0x4]=>DAT_0057803c         = 00000008h
    //         0055a9e2     MOV        EAX,dword ptr [ESP + param_1]
    //         0055a9e6     MOV        dword ptr [this->field0_0x0 + ESI*0x1],ostream   = 0055a8d0
    //         0055a9ed     MOV        EDX,dword ptr [EAX]
    //         0055a9ef     MOV        this,dword ptr [EDX + 0x4]
    //         0055a9f2     MOV        EDX,dword ptr [ECX + EAX*0x1 + this->x_floatus
    //         0055a9f6     MOV        EAX,dword ptr [ESI]
    //         0055a9f8     PUSH       EDX
    //         0055a9f9     MOV        this,dword ptr [EAX + 0x4]=>DAT_0057803c         = 00000008h
    //         0055a9fc     ADD        this,ESI
    //         0055a9fe     CALL       ios::init                                        void init(ios * this, streambuf * param_1)
    //         0055aa03     MOV        this,dword ptr [ESP + local_c]
    //         0055aa07     MOV        dword ptr [ESI + 0x4],0x0
    //         0055aa0e     MOV        EAX,ESI
    //         0055aa10     MOV        dword ptr FS:[0x0],this
    //         0055aa17     POP        ESI
    //         0055aa18     ADD        ESP,0x14
    //         0055aa1b     RET        0x8
}

// Offset: 0x0055AA20
void ostream(ostream* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall ostream::~ostream(void)                                                    *
    //                              *********************************************************************************************************
    //                              void __thiscall ~ostream(ostream * this)
    //              void              <VOID>         <RETURN>
    //              ostream *         ECX:4 (auto)   this
    //                               ??1ostream@@UAE@XZ                                           XREF[2]:     `scalar_deleting_destructor':0055a
    //                               ostream::~ostream                                                         ~ostream_withassign:0055ac1e(c)  
    //         0055aa20     MOV        EAX,dword ptr [this->field0_0x0 + DAT_fffffff8]
    //         0055aa23     MOV        EDX,dword ptr [EAX + 0x4]
    //         0055aa26     MOV        dword ptr [EDX + this->field0_0x0*0x1 + -0x8],   = 0055a8d0
    //         0055aa2e     RET
}

// Offset: 0x0055AA30
ostream* operator(ostream* this_, streambuf* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: class ostream & __thiscall ostream::operator=(class streambuf *)                           *
    //                              *********************************************************************************************************
    //                              ostream * __thiscall operator=(ostream * this, streambuf * param_1)
    //              ostream *         EAX:4          <RETURN>
    //              ostream *         ECX:4 (auto)   this
    //              streambuf *       Stack[0x4]:4   param_1
    //              undefined         Stack[-0x40]:1 local_40                  XREF[1]:     0055aa75(*)  
    //                               ??4ostream@@IAEAAV0@PAVstreambuf@@@Z
    //                               ostream::operator=
    //         0055aa30     MOV        EAX,FS:[0x0]
    //         0055aa36     PUSH       -0x1
    //         0055aa38     PUSH       FUN_00561f38
    //         0055aa3d     PUSH       EAX
    //         0055aa3e     MOV        dword ptr FS:[0x0],ESP
    //         0055aa45     SUB        ESP,0x34
    //         0055aa48     PUSH       ESI
    //         0055aa49     MOV        ESI,this
    //         0055aa4b     MOV        EAX,dword ptr [ESI]
    //         0055aa4d     MOV        this,dword ptr [EAX + 0x4]
    //         0055aa50     LEA        EAX,[this->field0_0x0 + ESI*0x1]
    //         0055aa53     MOV        this,dword ptr [ECX + ESI*0x1 + this->field25_
    //         0055aa57     TEST       this,this
    //         0055aa59     JZ         LAB_0055aa68
    //         0055aa5b     MOV        this,dword ptr [EAX + 0x4]
    //         0055aa5e     TEST       this,this
    //         0055aa60     JZ         LAB_0055aa68
    //         0055aa62     MOV        EDX,dword ptr [this->field0_0x0]
    //         0055aa64     PUSH       0x1
    //         0055aa66     CALL       dword ptr [EDX]
    //                               LAB_0055aa68                                                 XREF[2]:     0055aa59(j), 0055aa60(j)  
    //         0055aa68     MOV        EAX,dword ptr [ESI]
    //         0055aa6a     MOV        this,dword ptr [EAX + 0x4]
    //         0055aa6d     MOV        dword ptr [ECX + ESI*0x1 + this->x_floatused],
    //         0055aa75     LEA        this=>local_40,[ESP + 0x4]
    //         0055aa79     CALL       ios::ios                                         undefined ios(ios * this)
    //         0055aa7e     MOV        EDX,dword ptr [ESI]
    //         0055aa80     PUSH       EAX
    //         0055aa81     MOV        dword ptr [ESP + 0x44],0x0
    //         0055aa89     MOV        this,dword ptr [EDX + 0x4]
    //         0055aa8c     ADD        this,ESI
    //         0055aa8e     CALL       ios::operator=                                   ios * operator=(ios * this, ios * param_1)
    //         0055aa93     LEA        this,[ESP + 0x4]
    //         0055aa97     MOV        dword ptr [ESP + 0x40],0xffffffff
    //         0055aa9f     CALL       ios::~ios                                        void ~ios(ios * this)
    //         0055aaa4     MOV        EAX,dword ptr [ESI]
    //         0055aaa6     MOV        EDX,dword ptr [ESP + 0x48]
    //         0055aaaa     PUSH       EDX
    //         0055aaab     MOV        this,dword ptr [EAX + 0x4]
    //         0055aaae     MOV        dword ptr [ECX + ESI*0x1 + this->field25_0x1c]
    //         0055aab6     MOV        EAX,dword ptr [ESI]
    //         0055aab8     MOV        this,dword ptr [EAX + 0x4]
    //         0055aabb     ADD        this,ESI
    //         0055aabd     CALL       ios::init                                        void init(ios * this, streambuf * param_1)
    //         0055aac2     MOV        this,dword ptr [ESP + 0x38]
    //         0055aac6     MOV        EAX,ESI
    //         0055aac8     MOV        dword ptr FS:[0x0],this
    //         0055aacf     POP        ESI
    //         0055aad0     ADD        ESP,0x40
    //         0055aad3     RET        0x4
}

// Offset: 0x0055AAE0
undefined ostream_withassign(ostream_withassign* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall ostream_withassign::ostream_withassign(void)                                       *
    //                              *********************************************************************************************************
    //                              undefined __thiscall ostream_withassign(ostream_withassign * this)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              ostream_withas    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0055ab25(W)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[2]:     0055ab09(W), 0055ab44(R)  
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[2]:     0055aaff(W), 0055ab1d(W)  
    //                               ??0ostream_withassign@@QAE@XZ
    //                               ostream_withassign::ostream_withassign
    //         0055aae0     PUSH       -0x1
    //         0055aae2     PUSH       FUN_00561f66
    //         0055aae7     MOV        EAX,FS:[0x0]
    //         0055aaed     PUSH       EAX
    //         0055aaee     MOV        dword ptr FS:[0x0],ESP
    //         0055aaf5     SUB        ESP,0x8
    //         0055aaf8     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0055aafc     PUSH       ESI
    //         0055aafd     MOV        ESI,this
    //         0055aaff     MOV        dword ptr [ESP + local_14],0x0
    //         0055ab07     TEST       EAX,EAX
    //         0055ab09     MOV        dword ptr [ESP + local_10],ESI
    //         0055ab0d     JZ         LAB_0055ab2d
    //         0055ab0f     LEA        this,[ESI + 0x8]
    //         0055ab12     MOV        dword ptr [ESI],ostream_withassign::`vbtable'    = 0000000800000000h
    //         0055ab18     CALL       ios::ios                                         undefined ios(ios * this)
    //         0055ab1d     MOV        dword ptr [ESP + local_14],0x1
    //         0055ab25     MOV        dword ptr [ESP + local_4],0x0
    //                               LAB_0055ab2d                                                 XREF[1]:     0055ab0d(j)  
    //         0055ab2d     PUSH       0x0
    //         0055ab2f     MOV        this,ESI
    //         0055ab31     CALL       ostream::ostream                                 undefined ostream(ostream * this)
    //         0055ab36     MOV        EAX,dword ptr [ESI]
    //         0055ab38     MOV        this,dword ptr [EAX + 0x4]=>`vbtable'+4
    //         0055ab3b     MOV        EAX,ESI
    //         0055ab3d     MOV        dword ptr [this + ESI*0x1],ostream_withassign:   = 0055ab60
    //         0055ab44     MOV        this,dword ptr [ESP + local_10]
    //         0055ab48     MOV        dword ptr FS:[0x0],this
    //         0055ab4f     POP        ESI
    //         0055ab50     ADD        ESP,0x14
    //         0055ab53     RET        0x4
}

// Offset: 0x0055AB90
undefined ostream_withassign(ostream_withassign* this_, streambuf* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall ostream_withassign::ostream_withassign(class streambuf *)                          *
    //                              *********************************************************************************************************
    //                              undefined __thiscall ostream_withassign(ostream_withassign * this, s
    //              undefined         <UNASSIGNED>   <RETURN>
    //              ostream_withas    ECX:4 (auto)   this
    //              streambuf *       Stack[0x4]:4   param_1                   XREF[1]:     0055abdd(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0055abd5(W)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[2]:     0055abb9(W), 0055abf2(R)  
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[2]:     0055abaf(W), 0055abcd(W)  
    //                               ??0ostream_withassign@@QAE@PAVstreambuf@@@Z
    //                               ostream_withassign::ostream_withassign
    //         0055ab90     PUSH       -0x1
    //         0055ab92     PUSH       FUN_00561f86
    //         0055ab97     MOV        EAX,FS:[0x0]
    //         0055ab9d     PUSH       EAX
    //         0055ab9e     MOV        dword ptr FS:[0x0],ESP
    //         0055aba5     SUB        ESP,0x8
    //         0055aba8     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         0055abac     PUSH       ESI
    //         0055abad     MOV        ESI,this
    //         0055abaf     MOV        dword ptr [ESP + local_14],0x0
    //         0055abb7     TEST       EAX,EAX
    //         0055abb9     MOV        dword ptr [ESP + local_10],ESI
    //         0055abbd     JZ         LAB_0055abdd
    //         0055abbf     LEA        this,[ESI + 0x8]
    //         0055abc2     MOV        dword ptr [ESI],ostream_withassign::`vbtable'    = 0000000800000000h
    //         0055abc8     CALL       ios::ios                                         undefined ios(ios * this)
    //         0055abcd     MOV        dword ptr [ESP + local_14],0x1
    //         0055abd5     MOV        dword ptr [ESP + local_4],0x0
    //                               LAB_0055abdd                                                 XREF[1]:     0055abbd(j)  
    //         0055abdd     MOV        EAX,dword ptr [ESP + param_1]
    //         0055abe1     PUSH       0x0
    //         0055abe3     PUSH       EAX
    //         0055abe4     MOV        this,ESI
    //         0055abe6     CALL       ostream::ostream                                 undefined ostream(ostream * this, streambuf *
    //         0055abeb     MOV        this,dword ptr [ESI]
    //         0055abed     MOV        EAX,ESI
    //         0055abef     MOV        EDX,dword ptr [this + 0x4]=>`vbtable'+4
    //         0055abf2     MOV        this,dword ptr [ESP + local_10]
    //         0055abf6     MOV        dword ptr [EDX + ESI*0x1],ostream_withassign::   = 0055ab60
    //         0055abfd     MOV        dword ptr FS:[0x0],this
    //         0055ac04     POP        ESI
    //         0055ac05     ADD        ESP,0x14
    //         0055ac08     RET        0x8
}

// Offset: 0x0055AC10
void ostream_withassign(ostream_withassign* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall ostream_withassign::~ostream_withassign(void)                              *
    //                              *********************************************************************************************************
    //                              void __thiscall ~ostream_withassign(ostream_withassign * this)
    //              void              <VOID>         <RETURN>
    //              ostream_withas    ECX:4 (auto)   this
    //                               ??1ostream_withassign@@UAE@XZ                                XREF[1]:     `vector_deleting_destructor':0055a
    //                               ostream_withassign::~ostream_withassign
    //         0055ac10     MOV        EAX,dword ptr [this + DAT_fffffff8]
    //         0055ac13     MOV        EDX,dword ptr [EAX + 0x4]
    //         0055ac16     MOV        dword ptr [EDX + this*0x1 + -0x8],ostream_with   = 0055ab60
    //         0055ac1e     JMP        ostream::~ostream                                void ~ostream(ostream * this)
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055AC30
ostream* writepad(ostream* this_, char* param_2, char* param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * private: class ostream & __thiscall ostream::writepad(char const *,char const *)                      *
    //                              *********************************************************************************************************
    //                              ostream * __thiscall writepad(ostream * this, char * param_1, char *
    //              ostream *         EAX:4          <RETURN>
    //              ostream *         ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[9]:     0055ac33(R), 0055ac71(W), 0055ac77(W), 0055ac85(R), 
    //                                                                                     0055ac8e(W), 0055acdc(R), 0055ace4(W), 0055ad24(R), 
    //                                                                                     0055ad2d(W)  
    //              char *            Stack[0x8]:4   param_2                   XREF[1]:     0055ac44(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0055ac65(W), 0055acea(R)  
    //                               ?writepad@ostream@@AAEAAV1@PBD0@Z                            XREF[3]:     operator<<:0055a848(c), 
    //                               ostream::writepad                                                         operator<<:0055afb4(c), 
    //                                                                                                         operator<<:0055b0ef(c)  
    //         0055ac30     PUSH       this
    //         0055ac31     PUSH       EBX
    //         0055ac32     PUSH       EBP
    //         0055ac33     MOV        EBP,dword ptr [ESP + param_1]
    //         0055ac37     PUSH       ESI
    //         0055ac38     MOV        ESI,this
    //         0055ac3a     PUSH       EDI
    //         0055ac3b     MOV        EDI,EBP
    //         0055ac3d     OR         this,0xffffffff
    //         0055ac40     XOR        EAX,EAX
    //         0055ac42     SCASB.RE   ES:EDI
    //         0055ac44     MOV        EDI,dword ptr [ESP + param_2]
    //         0055ac48     NOT        this
    //         0055ac4a     DEC        this
    //         0055ac4b     MOV        EBX,this
    //         0055ac4d     OR         this,0xffffffff
    //         0055ac50     SCASB.RE   ES:EDI
    //         0055ac52     MOV        EAX,dword ptr [ESI]
    //         0055ac54     NOT        this
    //         0055ac56     DEC        this
    //         0055ac57     MOV        EDI,this
    //         0055ac59     MOV        this,dword ptr [EAX + 0x4]
    //         0055ac5c     MOV        EAX,dword ptr [ECX + ESI*0x1 + this->field45_0
    //         0055ac60     ADD        this,ESI
    //         0055ac62     LEA        EDX,[EBX + EDI*0x1]
    //         0055ac65     MOV        dword ptr [ESP + local_4],EDI
    //         0055ac69     CMP        EAX,EDX
    //         0055ac6b     JBE        LAB_0055ac77
    //         0055ac6d     SUB        EAX,EDI
    //         0055ac6f     SUB        EAX,EBX
    //         0055ac71     MOV        dword ptr [ESP + param_1],EAX
    //         0055ac75     JMP        LAB_0055ac7f
    //                               LAB_0055ac77                                                 XREF[1]:     0055ac6b(j)  
    //         0055ac77     MOV        dword ptr [ESP + param_1],0x0
    //                               LAB_0055ac7f                                                 XREF[1]:     0055ac75(j)  
    //         0055ac7f     TEST       byte ptr [ECX + this->field33_0x24],0xa
    //         0055ac83     JNZ        LAB_0055acee
    //         0055ac85     MOV        EAX,dword ptr [ESP + param_1]
    //         0055ac89     MOV        this,EAX
    //         0055ac8b     DEC        EAX
    //         0055ac8c     TEST       this,this
    //         0055ac8e     MOV        dword ptr [ESP + param_1],EAX
    //         0055ac92     JLE        LAB_0055acee
    //         0055ac94     LEA        EDI,[EAX + 0x1]
    //                               LAB_0055ac97                                                 XREF[1]:     0055ace8(j)  
    //         0055ac97     MOV        EDX,dword ptr [ESI]
    //         0055ac99     MOV        EAX,dword ptr [EDX + 0x4]
    //         0055ac9c     LEA        this,[EAX + ESI*0x1]
    //         0055ac9f     XOR        EAX,EAX
    //         0055aca1     MOV        AL,byte ptr [ECX + this->field41_0x2c]
    //         0055aca4     MOV        this,dword ptr [ECX + this->x_floatused]
    //         0055aca7     MOV        EDX,dword ptr [ECX + this->field25_0x1c]
    //         0055acaa     CMP        EDX,dword ptr [ECX + this->field29_0x20]
    //         0055acad     JNC        LAB_0055acbf
    //         0055acaf     MOV        byte ptr [EDX],AL
    //         0055acb1     MOV        EDX,dword ptr [ECX + this->field25_0x1c]
    //         0055acb4     AND        EAX,0xff
    //         0055acb9     INC        EDX
    //         0055acba     MOV        dword ptr [ECX + this->field25_0x1c],EDX
    //         0055acbd     JMP        LAB_0055acc5
    //                               LAB_0055acbf                                                 XREF[1]:     0055acad(j)  
    //         0055acbf     MOV        EDX,dword ptr [this->field0_0x0]
    //         0055acc1     PUSH       EAX
    //         0055acc2     CALL       dword ptr [EDX + 0x1c]
    //                               LAB_0055acc5                                                 XREF[1]:     0055acbd(j)  
    //         0055acc5     CMP        EAX,-0x1
    //         0055acc8     JNZ        LAB_0055acdc
    //         0055acca     MOV        EAX,dword ptr [ESI]
    //         0055accc     MOV        this,dword ptr [EAX + 0x4]
    //         0055accf     LEA        EAX,[ECX + ESI*0x1 + this->field5_0x8]
    //         0055acd3     MOV        this,dword ptr [ECX + ESI*0x1 + this->field5_0
    //         0055acd7     OR         this,0x6
    //         0055acda     MOV        dword ptr [EAX],this
    //                               LAB_0055acdc                                                 XREF[1]:     0055acc8(j)  
    //         0055acdc     MOV        this,dword ptr [ESP + param_1]
    //         0055ace0     DEC        EDI
    //         0055ace1     DEC        this
    //         0055ace2     TEST       EDI,EDI
    //         0055ace4     MOV        dword ptr [ESP + param_1],this
    //         0055ace8     JA         LAB_0055ac97
    //         0055acea     MOV        EDI,dword ptr [ESP + local_4]
    //                               LAB_0055acee                                                 XREF[2]:     0055ac83(j), 0055ac92(j)  
    //         0055acee     TEST       EBX,EBX
    //         0055acf0     JZ         LAB_0055ad18
    //         0055acf2     MOV        EDX,dword ptr [ESI]
    //         0055acf4     PUSH       EBX
    //         0055acf5     PUSH       EBP=>DAT_fffffff8
    //         0055acf6     MOV        EAX,dword ptr [EDX + 0x4]
    //         0055acf9     MOV        this,dword ptr [EAX + ESI*0x1 + 0x4]
    //         0055acfd     MOV        EDX,dword ptr [this->field0_0x0]
    //         0055acff     CALL       dword ptr [EDX + 0x14]
    //         0055ad02     CMP        EAX,EBX
    //         0055ad04     JZ         LAB_0055ad18
    //         0055ad06     MOV        EAX,dword ptr [ESI]
    //         0055ad08     MOV        this,dword ptr [EAX + 0x4]
    //         0055ad0b     LEA        EAX,[ECX + ESI*0x1 + this->field5_0x8]
    //         0055ad0f     MOV        this,dword ptr [ECX + ESI*0x1 + this->field5_0
    //         0055ad13     OR         this,0x6
    //         0055ad16     MOV        dword ptr [EAX],this
    //                               LAB_0055ad18                                                 XREF[2]:     0055acf0(j), 0055ad04(j)  
    //         0055ad18     MOV        EDX,dword ptr [ESI]
    //         0055ad1a     MOV        EAX,dword ptr [EDX + 0x4]
    //         0055ad1d     TEST       byte ptr [EAX + ESI*0x1 + 0x24],0x8
    //         0055ad22     JZ         LAB_0055ad8f
    //         0055ad24     MOV        EAX,dword ptr [ESP + param_1]
    //         0055ad28     MOV        this,EAX
    //         0055ad2a     DEC        EAX
    //         0055ad2b     TEST       this,this
    //         0055ad2d     MOV        dword ptr [ESP + param_1],EAX
    //         0055ad31     JLE        LAB_0055ad8f
    //         0055ad33     LEA        EDI,[EAX + 0x1]
    //                               LAB_0055ad36                                                 XREF[1]:     0055ad89(j)  
    //         0055ad36     MOV        EDX,dword ptr [ESI]
    //         0055ad38     MOV        EAX,dword ptr [EDX + 0x4]
    //         0055ad3b     LEA        this,[EAX + ESI*0x1]
    //         0055ad3e     XOR        EAX,EAX
    //         0055ad40     MOV        AL,byte ptr [ECX + this->field41_0x2c]
    //         0055ad43     MOV        this,dword ptr [ECX + this->x_floatused]
    //         0055ad46     MOV        EDX,dword ptr [ECX + this->field25_0x1c]
    //         0055ad49     MOV        EBX,dword ptr [ECX + this->field29_0x20]
    //         0055ad4c     CMP        EDX,EBX
    //         0055ad4e     JNC        LAB_0055ad60
    //         0055ad50     MOV        byte ptr [EDX],AL
    //         0055ad52     MOV        EDX,dword ptr [ECX + this->field25_0x1c]
    //         0055ad55     AND        EAX,0xff
    //         0055ad5a     INC        EDX
    //         0055ad5b     MOV        dword ptr [ECX + this->field25_0x1c],EDX
    //         0055ad5e     JMP        LAB_0055ad66
    //                               LAB_0055ad60                                                 XREF[1]:     0055ad4e(j)  
    //         0055ad60     MOV        EDX,dword ptr [this->field0_0x0]
    //         0055ad62     PUSH       EAX
    //         0055ad63     CALL       dword ptr [EDX + 0x1c]
    //                               LAB_0055ad66                                                 XREF[1]:     0055ad5e(j)  
    //         0055ad66     CMP        EAX,-0x1
    //         0055ad69     JNZ        LAB_0055ad7d
    //         0055ad6b     MOV        EAX,dword ptr [ESI]
    //         0055ad6d     MOV        this,dword ptr [EAX + 0x4]
    //         0055ad70     LEA        EAX,[ECX + ESI*0x1 + this->field5_0x8]
    //         0055ad74     MOV        this,dword ptr [ECX + ESI*0x1 + this->field5_0
    //         0055ad78     OR         this,0x6
    //         0055ad7b     MOV        dword ptr [EAX],this
    //                               LAB_0055ad7d                                                 XREF[1]:     0055ad69(j)  
    //         0055ad7d     MOV        this,dword ptr [ESP + 0x18]
    //         0055ad81     DEC        EDI
    //         0055ad82     DEC        this
    //         0055ad83     TEST       EDI,EDI
    //         0055ad85     MOV        dword ptr [ESP + 0x18],this
    //         0055ad89     JA         LAB_0055ad36
    //         0055ad8b     MOV        EDI,dword ptr [ESP + 0x10]
    //                               LAB_0055ad8f                                                 XREF[2]:     0055ad22(j), 0055ad31(j)  
    //         0055ad8f     MOV        EDX,dword ptr [ESI]
    //         0055ad91     PUSH       EDI
    //         0055ad92     MOV        EAX,dword ptr [EDX + 0x4]
    //         0055ad95     MOV        this,dword ptr [EAX + ESI*0x1 + 0x4]
    //         0055ad99     MOV        EAX,dword ptr [ESP + 0x20]
    //         0055ad9d     PUSH       EAX=>DAT_fffffff8
    //         0055ad9e     MOV        EDX,dword ptr [this->field0_0x0]
    //         0055ada0     CALL       dword ptr [EDX + 0x14]
    //         0055ada3     CMP        EAX,EDI
    //         0055ada5     JZ         LAB_0055adb9
    //         0055ada7     MOV        this,dword ptr [ESI]
    //         0055ada9     MOV        EDX,dword ptr [ECX + this->x_floatused]
    //         0055adac     MOV        this,dword ptr [EDX + ESI*0x1 + 0x8]
    //         0055adb0     OR         this,0x6
    //         0055adb3     LEA        EAX,[EDX + ESI*0x1 + 0x8]
    //         0055adb7     MOV        dword ptr [EAX],this
    //                               LAB_0055adb9                                                 XREF[1]:     0055ada5(j)  
    //         0055adb9     MOV        EAX,dword ptr [ESI]
    //         0055adbb     MOV        this,dword ptr [EAX + 0x4]
    //         0055adbe     TEST       byte ptr [ECX + ESI*0x1 + this->field33_0x24],
    //         0055adc3     JZ         LAB_0055ae1b
    //         0055adc5     MOV        EDI,dword ptr [ESP + 0x18]
    //         0055adc9     MOV        EDX,EDI
    //         0055adcb     DEC        EDI
    //         0055adcc     TEST       EDX,EDX
    //         0055adce     JLE        LAB_0055ae1b
    //         0055add0     INC        EDI
    //                               LAB_0055add1                                                 XREF[1]:     0055ae19(j)  
    //         0055add1     MOV        EAX,dword ptr [ESI]
    //         0055add3     MOV        this,dword ptr [EAX + 0x4]
    //         0055add6     XOR        EAX,EAX
    //         0055add8     MOV        AL,byte ptr [ECX + ESI*0x1 + this->field41_0x2c]
    //         0055addc     ADD        this,ESI
    //         0055adde     MOV        this,dword ptr [ECX + this->x_floatused]
    //         0055ade1     MOV        EDX,dword ptr [ECX + this->field25_0x1c]
    //         0055ade4     MOV        EBX,dword ptr [ECX + this->field29_0x20]
    //         0055ade7     CMP        EDX,EBX
    //         0055ade9     JNC        LAB_0055adfb
    //         0055adeb     MOV        byte ptr [EDX],AL
    //         0055aded     MOV        EDX,dword ptr [ECX + this->field25_0x1c]
    //         0055adf0     AND        EAX,0xff
    //         0055adf5     INC        EDX
    //         0055adf6     MOV        dword ptr [ECX + this->field25_0x1c],EDX
    //         0055adf9     JMP        LAB_0055ae01
    //                               LAB_0055adfb                                                 XREF[1]:     0055ade9(j)  
    //         0055adfb     MOV        EDX,dword ptr [this->field0_0x0]
    //         0055adfd     PUSH       EAX
    //         0055adfe     CALL       dword ptr [EDX + 0x1c]
    //                               LAB_0055ae01                                                 XREF[1]:     0055adf9(j)  
    //         0055ae01     CMP        EAX,-0x1
    //         0055ae04     JNZ        LAB_0055ae18
    //         0055ae06     MOV        EAX,dword ptr [ESI]
    //         0055ae08     MOV        this,dword ptr [EAX + 0x4]
    //         0055ae0b     LEA        EAX,[ECX + ESI*0x1 + this->field5_0x8]
    //         0055ae0f     MOV        this,dword ptr [ECX + ESI*0x1 + this->field5_0
    //         0055ae13     OR         this,0x6
    //         0055ae16     MOV        dword ptr [EAX],this
    //                               LAB_0055ae18                                                 XREF[1]:     0055ae04(j)  
    //         0055ae18     DEC        EDI
    //         0055ae19     JNZ        LAB_0055add1
    //                               LAB_0055ae1b                                                 XREF[2]:     0055adc3(j), 0055adce(j)  
    //         0055ae1b     MOV        EAX,ESI
    //         0055ae1d     POP        EDI
    //         0055ae1e     POP        ESI
    //         0055ae1f     POP        EBP
    //         0055ae20     POP        EBX
    //         0055ae21     POP        this
    //         0055ae22     RET        0x8
}

// Offset: 0x0055AE30
istream* get(istream* this_, char* param_2, int param_3, int param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: class istream & __thiscall istream::get(char *,int,int)                                    *
    //                              *********************************************************************************************************
    //                              istream * __thiscall get(istream * this, char * param_1, int param_2
    //              istream *         EAX:4          <RETURN>
    //              istream *         ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     0055ae3f(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0055ae43(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     0055ae71(R)  
    //                               ?get@istream@@IAEAAV1@PADHH@Z                                XREF[1]:     operator>>:00446753(c)  
    //                               istream::get
    //         0055ae30     PUSH       EBX
    //         0055ae31     PUSH       EBP
    //         0055ae32     PUSH       ESI
    //         0055ae33     PUSH       EDI
    //         0055ae34     MOV        ESI,this
    //         0055ae36     PUSH       0x1
    //         0055ae38     XOR        EDI,EDI
    //         0055ae3a     CALL       istream::ipfx                                    int ipfx(istream * this, int param_1)
    //         0055ae3f     MOV        EBX,dword ptr [ESP + param_1]
    //         0055ae43     MOV        EBP,dword ptr [ESP + param_2]
    //         0055ae47     TEST       EAX,EAX
    //         0055ae49     JZ         LAB_0055aedd
    //         0055ae4f     MOV        EAX,EBP
    //         0055ae51     DEC        EBP
    //         0055ae52     TEST       EAX,EAX
    //         0055ae54     JZ         LAB_0055aedc
    //         0055ae5a     TEST       EBP,EBP
    //         0055ae5c     JBE        LAB_0055aed9
    //                               LAB_0055ae5e                                                 XREF[1]:     0055ae8f(j)  
    //         0055ae5e     MOV        this,dword ptr [ESI]
    //         0055ae60     MOV        EDX,dword ptr [ECX + this->_fGline]
    //         0055ae63     MOV        this,dword ptr [EDX + ESI*0x1 + 0x4]
    //         0055ae67     CALL       streambuf::sgetc                                 int sgetc(streambuf * this)
    //         0055ae6c     CMP        EAX,-0x1
    //         0055ae6f     JZ         LAB_0055ae93
    //         0055ae71     CMP        EAX,dword ptr [ESP + param_3]
    //         0055ae75     JZ         LAB_0055aebd
    //         0055ae77     TEST       EBX,EBX
    //         0055ae79     JZ         LAB_0055ae7e
    //         0055ae7b     MOV        byte ptr [EDI + EBX*0x1],AL
    //                               LAB_0055ae7e                                                 XREF[1]:     0055ae79(j)  
    //         0055ae7e     MOV        EAX,dword ptr [ESI]
    //         0055ae80     MOV        this,dword ptr [EAX + 0x4]
    //         0055ae83     MOV        this,dword ptr [ECX + ESI*0x1 + this->_fGline]
    //         0055ae87     CALL       streambuf::stossc                                void stossc(streambuf * this)
    //         0055ae8c     INC        EDI
    //         0055ae8d     CMP        EDI,EBP
    //         0055ae8f     JC         LAB_0055ae5e
    //         0055ae91     JMP        LAB_0055aed9
    //                               LAB_0055ae93                                                 XREF[1]:     0055ae6f(j)  
    //         0055ae93     MOV        EDX,dword ptr [ESI]
    //         0055ae95     MOV        EAX,dword ptr [EDX + 0x4]
    //         0055ae98     MOV        this,dword ptr [EAX + ESI*0x1 + 0x8]
    //         0055ae9c     LEA        EAX,[EAX + ESI*0x1 + 0x8]
    //         0055aea0     OR         this,0x1
    //         0055aea3     TEST       EDI,EDI
    //         0055aea5     MOV        dword ptr [EAX],this
    //         0055aea7     JNZ        LAB_0055aed9
    //         0055aea9     MOV        this,dword ptr [ESI]
    //         0055aeab     MOV        EDX,dword ptr [ECX + this->_fGline]
    //         0055aeae     MOV        this,dword ptr [EDX + ESI*0x1 + 0x8]
    //         0055aeb2     OR         this,0x2
    //         0055aeb5     LEA        EAX,[EDX + ESI*0x1 + 0x8]
    //         0055aeb9     MOV        dword ptr [EAX],this
    //         0055aebb     JMP        LAB_0055aed9
    //                               LAB_0055aebd                                                 XREF[1]:     0055ae75(j)  
    //         0055aebd     MOV        EAX,dword ptr [ESI + 0x4]
    //         0055aec0     TEST       EAX,EAX
    //         0055aec2     JZ         LAB_0055aed9
    //         0055aec4     MOV        EAX,dword ptr [ESI + 0x8]
    //         0055aec7     INC        EAX
    //         0055aec8     MOV        dword ptr [ESI + 0x8],EAX
    //         0055aecb     MOV        EAX,dword ptr [ESI]
    //         0055aecd     MOV        this,dword ptr [EAX + 0x4]
    //         0055aed0     MOV        this,dword ptr [ECX + ESI*0x1 + this->_fGline]
    //         0055aed4     CALL       streambuf::stossc                                void stossc(streambuf * this)
    //                               LAB_0055aed9                                                 XREF[5]:     0055ae5c(j), 0055ae91(j), 
    //                                                                                                         0055aea7(j), 0055aebb(j), 
    //                                                                                                         0055aec2(j)  
    //         0055aed9     ADD        dword ptr [ESI + 0x8],EDI
    //                               LAB_0055aedc                                                 XREF[1]:     0055ae54(j)  
    //         0055aedc     INC        EBP
    //                               LAB_0055aedd                                                 XREF[1]:     0055ae49(j)  
    //         0055aedd     TEST       EBX,EBX
    //         0055aedf     JZ         LAB_0055aee9
    //         0055aee1     TEST       EBP,EBP
    //         0055aee3     JZ         LAB_0055aee9
    //         0055aee5     MOV        byte ptr [EDI + EBX*0x1],0x0
    //                               LAB_0055aee9                                                 XREF[2]:     0055aedf(j), 0055aee3(j)  
    //         0055aee9     MOV        dword ptr [ESI + 0x4],0x0
    //         0055aef0     MOV        EAX,ESI
    //         0055aef2     POP        EDI
    //         0055aef3     POP        ESI
    //         0055aef4     POP        EBP
    //         0055aef5     POP        EBX
    //         0055aef6     RET        0xc
}

// Offset: 0x0055AF00
ostream* operator(ostream* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: class ostream & __thiscall ostream::operator<<(int)                                           *
    //                              *********************************************************************************************************
    //                              ostream * __thiscall operator<<(ostream * this, int param_1)
    //              ostream *         EAX:4          <RETURN>
    //              ostream *         ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0055af45(R)  
    //              undefined         Stack[-0xc]:1  local_c                   XREF[2]:     0055af9a(*), 0055afa8(*)  
    //              undefined1        Stack[-0xd]:1  local_d                   XREF[1]:     0055af29(W)  
    //              undefined1        Stack[-0xe]:1  local_e                   XREF[1]:     0055af23(W)  
    //              undefined2        Stack[-0x10]:2 local_10                  XREF[2,2]:   0055af19(W), 0055af96(*), 0055af67(W), 0055af71(W)  
    //              undefined1        Stack[-0x11]:1 local_11                  XREF[1]:     0055af37(W)  
    //              undefined1        Stack[-0x12]:1 local_12                  XREF[1]:     0055af33(W)  
    //              undefined2        Stack[-0x14]:2 local_14                  XREF[4,1]:   0055af2e(W), 0055af80(W), 0055af90(W), 0055afac(*), 
    //                                                                                     0055af6b(W)  
    //                               ??6ostream@@QAEAAV0@H@Z                                      XREF[1]:     operator<<:0046a8bb(c)  
    //                               ostream::operator<<
    //         0055af00     SUB        ESP,0x14
    //         0055af03     MOV        AX,[s_%d]                                        = 6425h
    //         0055af09     MOV        DX,word ptr [s_]                                 = ""
    //         0055af10     PUSH       ESI
    //         0055af11     MOV        ESI,this
    //         0055af13     MOV        this,byte ptr [DAT_00584612]
    //         0055af19     MOV        word ptr [ESP + local_10],AX
    //         0055af1e     MOV        AL,[DAT_00578052]
    //         0055af23     MOV        byte ptr [ESP + local_e],this
    //         0055af27     MOV        this,ESI
    //         0055af29     MOV        byte ptr [ESP + local_d],0x0
    //         0055af2e     MOV        word ptr [ESP + local_14],DX
    //         0055af33     MOV        byte ptr [ESP + local_12],AL
    //         0055af37     MOV        byte ptr [ESP + local_11],0x0
    //         0055af3c     CALL       ostream::opfx                                    int opfx(ostream * this)
    //         0055af41     TEST       EAX,EAX
    //         0055af43     JZ         LAB_0055afc0
    //         0055af45     MOV        EDX,dword ptr [ESP + param_1]
    //         0055af49     TEST       EDX,EDX
    //         0055af4b     JZ         LAB_0055af95
    //         0055af4d     MOV        this,dword ptr [ESI]
    //         0055af4f     MOV        EAX,dword ptr [ECX + this->x_floatused]
    //         0055af52     MOV        EAX,dword ptr [ESI + EAX*0x1 + 0x24]
    //         0055af56     TEST       AL,0x60
    //         0055af58     JZ         LAB_0055af87
    //         0055af5a     TEST       AL,0x40
    //         0055af5c     JZ         LAB_0055af71
    //         0055af5e     SHR        EAX,0x4
    //         0055af61     NOT        AL
    //         0055af63     AND        AL,0x20
    //         0055af65     OR         AL,0x58
    //         0055af67     MOV        byte ptr [ESP + local_10+0x1],AL
    //         0055af6b     MOV        byte ptr [ESP + local_14+0x1],AL
    //         0055af6f     JMP        LAB_0055af76
    //                               LAB_0055af71                                                 XREF[1]:     0055af5c(j)  
    //         0055af71     MOV        byte ptr [ESP + local_10+0x1],0x6f
    //                               LAB_0055af76                                                 XREF[1]:     0055af6f(j)  
    //         0055af76     MOV        this,dword ptr [ECX + this->x_floatused]
    //         0055af79     TEST       byte ptr [ESI + this->field0_0x0*0x1 + 0x24],0
    //         0055af7e     JZ         LAB_0055af95
    //         0055af80     MOV        byte ptr [ESP + local_14],0x30
    //         0055af85     JMP        LAB_0055af95
    //                               LAB_0055af87                                                 XREF[1]:     0055af58(j)  
    //         0055af87     TEST       EDX,EDX
    //         0055af89     JLE        LAB_0055af95
    //         0055af8b     TEST       AH,0x4
    //         0055af8e     JZ         LAB_0055af95
    //         0055af90     MOV        byte ptr [ESP + local_14],0x2b
    //                               LAB_0055af95                                                 XREF[5]:     0055af4b(j), 0055af7e(j), 
    //                                                                                                         0055af85(j), 0055af89(j), 
    //                                                                                                         0055af8e(j)  
    //         0055af95     PUSH       EDX
    //         0055af96     LEA        EDX=>local_10,[ESP + 0xc]
    //         0055af9a     LEA        EAX=>local_c,[ESP + 0x10]
    //         0055af9e     PUSH       EDX
    //         0055af9f     PUSH       EAX
    //         0055afa0     CALL       sprintf                                          undefined sprintf()
    //         0055afa5     ADD        ESP,0xc
    //         0055afa8     LEA        this=>local_c,[ESP + 0xc]
    //         0055afac     LEA        EDX=>local_14,[ESP + 0x4]
    //         0055afb0     PUSH       this
    //         0055afb1     PUSH       EDX
    //         0055afb2     MOV        this,ESI
    //         0055afb4     CALL       ostream::writepad                                ostream * writepad(ostream * this, char * par
    //         0055afb9     MOV        this,ESI
    //         0055afbb     CALL       ostream::osfx                                    void osfx(ostream * this)
    //                               LAB_0055afc0                                                 XREF[1]:     0055af43(j)  
    //         0055afc0     MOV        EAX,ESI
    //         0055afc2     POP        ESI
    //         0055afc3     ADD        ESP,0x14
    //         0055afc6     RET        0x4
}

// Offset: 0x0055AFD0
ostream* operator(ostream* this_, double param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: class ostream & __thiscall ostream::operator<<(double)                                        *
    //                              *********************************************************************************************************
    //                              ostream * __thiscall operator<<(ostream * this, double param_1)
    //              ostream *         EAX:4          <RETURN>
    //              ostream *         ECX:4 (auto)   this
    //              double            Stack[0x4]:8   param_1                   XREF[1,1]:   0055b0ad(R), 0055b0a9(R)  
    //              undefined         Stack[-0x17]:1 local_17                  XREF[1]:     0055b0de(*)  
    //              undefined         Stack[-0x18]:1 local_18                  XREF[3]:     0055aff7(*), 0055b0b7(*), 0055b0c2(R)  
    //              undefined         Stack[-0x20]:1 local_20                  XREF[2]:     0055b044(*), 0055b0b2(*)  
    //              undefined1        Stack[-0x23]:1 local_23                  XREF[3]:     0055b038(*), 0055b04e(*), 0055b0ea(*)  
    //              undefined1        Stack[-0x24]:1 local_24                  XREF[4]:     0055b022(W), 0055b03e(*), 0055b0d5(W), 0055b0e2(*)  
    //                               ??6ostream@@QAEAAV0@N@Z                                      XREF[3]:     operator<<:0046a849(c), 
    //                               ostream::operator<<                                                       operator<<:0046a870(c), 
    //                                                                                                         operator<<:0046a89c(c)  
    //         0055afd0     MOV        EAX,0x24
    //         0055afd5     CALL       __alloca_probe                                   undefined __alloca_probe()
    //         0055afda     PUSH       EBX
    //         0055afdb     PUSH       EBP
    //         0055afdc     PUSH       ESI
    //         0055afdd     MOV        ESI,this
    //         0055afdf     PUSH       EDI
    //         0055afe0     XOR        EBP,EBP
    //         0055afe2     MOV        EDI,dword ptr [ESI + 0x4]
    //         0055afe5     MOV        EAX,dword ptr [ESI]
    //         0055afe7     NEG        EDI
    //         0055afe9     SBB        EDI,EDI
    //         0055afeb     MOV        dword ptr [ESI + 0x4],EBP
    //         0055afee     MOV        this,dword ptr [EAX + 0x4]
    //         0055aff1     AND        EDI,0xfffffff7
    //         0055aff4     ADD        EDI,0xf
    //         0055aff7     LEA        EBX=>local_18,[ESP + 0x1c]
    //         0055affb     MOV        EAX,dword ptr [ECX + ESI*0x1 + this->field37_0
    //         0055afff     CMP        EAX,EDI
    //         0055b001     JNC        LAB_0055b005
    //         0055b003     MOV        EDI,EAX
    //                               LAB_0055b005                                                 XREF[1]:     0055b001(j)  
    //         0055b005     MOV        this,ESI
    //         0055b007     CALL       ostream::opfx                                    int opfx(ostream * this)
    //         0055b00c     TEST       EAX,EAX
    //         0055b00e     JZ         LAB_0055b0fb
    //         0055b014     MOV        EAX,dword ptr [ESI]
    //         0055b016     MOV        EDX,dword ptr [EAX + 0x4]
    //         0055b019     MOV        this,dword ptr [ESI + EDX*0x1 + 0x24]
    //         0055b01d     TEST       this,0x4
    //         0055b020     JZ         LAB_0055b02c
    //         0055b022     MOV        byte ptr [ESP + local_24],0x2b
    //         0055b027     MOV        EBP,0x1
    //                               LAB_0055b02c                                                 XREF[1]:     0055b020(j)  
    //         0055b02c     MOV        EAX,dword ptr [EAX + 0x4]
    //         0055b02f     MOV        this,dword ptr [ESI + EAX*0x1 + 0x24]
    //         0055b033     TEST       this,0x1
    //         0055b036     JZ         LAB_0055b03e
    //         0055b038     MOV        byte ptr [ESP + EBP*0x1 + local_23],0x23
    //         0055b03d     INC        EBP
    //                               LAB_0055b03e                                                 XREF[1]:     0055b036(j)  
    //         0055b03e     LEA        this=>local_24,[ESP + 0x10]
    //         0055b042     PUSH       EDI
    //         0055b043     PUSH       this
    //         0055b044     LEA        EDX=>local_20,[ESP + 0x1c]
    //         0055b048     PUSH       s_%%%s.%.0ug                                     = "%%%s.%.0ug"
    //         0055b04d     PUSH       EDX
    //         0055b04e     MOV        byte ptr [ESP + EBP*0x1 + local_23],0x0
    //         0055b053     CALL       sprintf                                          undefined sprintf()
    //         0055b058     MOV        EDX,dword ptr [ESI]
    //         0055b05a     MOV        EBP,dword ptr [ios::floatfield]                  = 1800h
    //         0055b060     ADD        ESP,0x10
    //         0055b063     DEC        EAX
    //         0055b064     MOV        this,dword ptr [EDX + 0x4]
    //         0055b067     MOV        this,dword ptr [ESI + this->field0_0x0*0x1 + 0
    //         0055b06b     AND        this,EBP
    //         0055b06d     CMP        this,0x1000
    //         0055b073     JNZ        LAB_0055b07c
    //         0055b075     MOV        byte ptr [ESP + EAX*0x1 + 0x14],0x66
    //         0055b07a     JMP        LAB_0055b0a9
    //                               LAB_0055b07c                                                 XREF[1]:     0055b073(j)  
    //         0055b07c     CMP        this,0x800
    //         0055b082     JNZ        LAB_0055b089
    //                              language.dll match for 0x65: "1"
    //         0055b084     MOV        byte ptr [ESP + EAX*0x1 + 0x14],0x65
    //                               LAB_0055b089                                                 XREF[1]:     0055b082(j)  
    //         0055b089     MOV        EDX,dword ptr [EDX + 0x4]
    //         0055b08c     MOV        this,dword ptr [ESI + EDX*0x1 + 0x24]
    //         0055b090     TEST       this,0x2
    //         0055b093     JZ         LAB_0055b0a9
    //         0055b095     LEA        EDI,[ESP + EAX*0x1 + 0x14]
    //         0055b099     MOVSX      EAX,byte ptr [ESP + EAX*0x1 + 0x14]
    //         0055b09e     PUSH       EAX
    //         0055b09f     CALL       toupper                                          undefined toupper()
    //         0055b0a4     ADD        ESP,0x4
    //         0055b0a7     MOV        byte ptr [EDI],AL
    //                               LAB_0055b0a9                                                 XREF[2]:     0055b07a(j), 0055b093(j)  
    //         0055b0a9     MOV        this,dword ptr [ESP + param_1+0x4]
    //         0055b0ad     MOV        EDX,dword ptr [ESP + param_1]
    //         0055b0b1     PUSH       this
    //         0055b0b2     LEA        EAX=>local_20,[ESP + 0x18]
    //         0055b0b6     PUSH       EDX
    //         0055b0b7     LEA        this=>local_18,[ESP + 0x24]
    //         0055b0bb     PUSH       EAX
    //         0055b0bc     PUSH       this
    //         0055b0bd     CALL       sprintf                                          undefined sprintf()
    //         0055b0c2     MOV        this,byte ptr [ESP + local_18]
    //         0055b0c6     ADD        ESP,0x10
    //         0055b0c9     XOR        EAX,EAX
    //         0055b0cb     CMP        this,0x2b
    //         0055b0ce     JZ         LAB_0055b0d5
    //         0055b0d0     CMP        this,0x2d
    //         0055b0d3     JNZ        LAB_0055b0e2
    //                               LAB_0055b0d5                                                 XREF[1]:     0055b0ce(j)  
    //         0055b0d5     MOV        byte ptr [ESP + local_24],this
    //         0055b0d9     MOV        EAX,0x1
    //         0055b0de     LEA        EBX=>local_17,[ESP + 0x1d]
    //                               LAB_0055b0e2                                                 XREF[1]:     0055b0d3(j)  
    //         0055b0e2     LEA        EDX=>local_24,[ESP + 0x10]
    //         0055b0e6     PUSH       EBX
    //         0055b0e7     PUSH       EDX
    //         0055b0e8     MOV        this,ESI
    //         0055b0ea     MOV        byte ptr [ESP + EAX*0x1 + local_23],0x0
    //         0055b0ef     CALL       ostream::writepad                                ostream * writepad(ostream * this, char * par
    //         0055b0f4     MOV        this,ESI
    //         0055b0f6     CALL       ostream::osfx                                    void osfx(ostream * this)
    //                               LAB_0055b0fb                                                 XREF[1]:     0055b00e(j)  
    //         0055b0fb     MOV        EAX,ESI
    //         0055b0fd     POP        EDI
    //         0055b0fe     POP        ESI
    //         0055b0ff     POP        EBP
    //         0055b100     POP        EBX
    //         0055b101     ADD        ESP,0x24
    //         0055b104     RET        0x8
}

