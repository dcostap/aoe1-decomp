// Auto-generated scaffold unit: bucket_056A.cpp.asm
#include "../include/common.h"

// Offset: 0x0056A01A
undefined FUN_0056a01a() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056a01a()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056a01a
    //         0056a01a     MOV        EAX,dword ptr [EDI + -0x2]
    //         0056a01d     MOV        DL,AL
    //         0056a01f     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056a022     MOV        DL,AH
    //         0056a024     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056a027     BSWAP      EAX
    //         0056a029     MOV        DL,AH
    //         0056a02b     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056a02e     MOV        DL,AL
    //         0056a030     BSWAP      EAX
    //         0056a032     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056a038     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         0056a03e     BSWAP      EAX
    //         0056a040     MOV        AL,DL
    //         0056a042     BSWAP      EAX
    //         0056a044     MOV        dword ptr [EDI + -0x2],EAX
    //         0056a047     SUB        EDI,0x3
    //         0056a04a     SUB        ECX,0x5
    //                               LAB_0056a04d                                                 XREF[1]:     0056a07d(j)  
    //         0056a04d     MOV        EAX,dword ptr [EDI + -0x3]=>DAT_fffffffa
    //         0056a050     MOV        DL,AL
    //         0056a052     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056a055     MOV        DL,AH
    //         0056a057     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056a05a     BSWAP      EAX
    //         0056a05c     MOV        DL,AL
    //         0056a05e     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056a061     MOV        DL,AH
    //         0056a063     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056a066     BSWAP      EAX
    //         0056a068     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056a06e     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         0056a074     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffa
    //         0056a077     SUB        EDI,0x4
    //         0056a07a     SUB        ECX,0x4
    //         0056a07d     JA         LAB_0056a04d
    //         0056a07f     MOV        AX,word ptr [EDI + -0x1]=>DAT_fffffff8
    //         0056a083     MOV        DL,AL
    //         0056a085     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056a088     MOV        DL,AH
    //         0056a08a     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056a08d     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056a093     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         0056a099     MOV        word ptr [EDI + -0x1],AX=>DAT_fffffff8
    //         0056a09d     SUB        EDI,0x2
    //         0056a0a0     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x0056A0A6
undefined FUN_0056a0a6() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056a0a6()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056a0a6
    //         0056a0a6     SUB        ECX,0x3
    //                               LAB_0056a0a9                                                 XREF[1]:     0056a0d9(j)  
    //         0056a0a9     MOV        EAX,dword ptr [EDI + -0x3]=>DAT_fffffff9
    //         0056a0ac     MOV        DL,AL
    //         0056a0ae     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056a0b1     MOV        DL,AH
    //         0056a0b3     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056a0b6     BSWAP      EAX
    //         0056a0b8     MOV        DL,AL
    //         0056a0ba     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056a0bd     MOV        DL,AH
    //         0056a0bf     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056a0c2     BSWAP      EAX
    //         0056a0c4     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056a0ca     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         0056a0d0     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff9
    //         0056a0d3     SUB        EDI,0x4
    //         0056a0d6     SUB        ECX,0x4
    //         0056a0d9     JA         LAB_0056a0a9
    //         0056a0db     MOV        EAX,dword ptr [EDI + -0x3]=>DAT_fffffff9
    //         0056a0de     MOV        DL,AH
    //         0056a0e0     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056a0e3     BSWAP      EAX
    //         0056a0e5     MOV        DL,AH
    //         0056a0e7     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056a0ea     MOV        DL,AL
    //         0056a0ec     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056a0ef     BSWAP      EAX
    //         0056a0f1     MOV        DL,AL
    //         0056a0f3     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056a0f9     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         0056a0ff     MOV        AL,DL
    //         0056a101     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff9
    //         0056a104     SUB        EDI,0x3
    //         0056a107     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x0056A10D
undefined FUN_0056a10d() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056a10d()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056a10d
    //         0056a10d     MOV        DL,byte ptr [EDI]
    //         0056a10f     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056a112     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056a118     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         0056a11e     MOV        byte ptr [EDI],AL
    //         0056a120     DEC        EDI
    //         0056a121     SUB        ECX,0x4
    //                               LAB_0056a124                                                 XREF[1]:     0056a154(j)  
    //         0056a124     MOV        EAX,dword ptr [EDI + -0x3]=>DAT_fffffff8
    //         0056a127     MOV        DL,AL
    //         0056a129     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056a12c     MOV        DL,AH
    //         0056a12e     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056a131     BSWAP      EAX
    //         0056a133     MOV        DL,AL
    //         0056a135     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056a138     MOV        DL,AH
    //         0056a13a     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056a13d     BSWAP      EAX
    //         0056a13f     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056a145     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         0056a14b     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff8
    //         0056a14e     SUB        EDI,0x4
    //         0056a151     SUB        ECX,0x4
    //         0056a154     JA         LAB_0056a124
    //         0056a156     MOV        EAX,dword ptr [EDI + -0x3]=>DAT_fffffff8
    //         0056a159     MOV        DL,AH
    //         0056a15b     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056a15e     BSWAP      EAX
    //         0056a160     MOV        DL,AH
    //         0056a162     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056a165     MOV        DL,AL
    //         0056a167     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056a16a     BSWAP      EAX
    //         0056a16c     MOV        DL,AL
    //         0056a16e     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056a174     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         0056a17a     MOV        AL,DL
    //         0056a17c     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff8
    //         0056a17f     SUB        EDI,0x3
    //         0056a182     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x0056A188
undefined FUN_0056a188() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056a188()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056a188
    //         0056a188     MOV        AX,word ptr [EDI + -0x1]
    //         0056a18c     MOV        DL,AL
    //         0056a18e     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056a191     MOV        DL,AH
    //         0056a193     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056a196     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056a19c     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         0056a1a2     MOV        word ptr [EDI + -0x1],AX
    //         0056a1a6     SUB        EDI,0x2
    //         0056a1a9     SUB        ECX,0x5
    //                               LAB_0056a1ac                                                 XREF[1]:     0056a1dc(j)  
    //         0056a1ac     MOV        EAX,dword ptr [EDI + -0x3]=>DAT_fffffffb
    //         0056a1af     MOV        DL,AL
    //         0056a1b1     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056a1b4     MOV        DL,AH
    //         0056a1b6     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056a1b9     BSWAP      EAX
    //         0056a1bb     MOV        DL,AL
    //         0056a1bd     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056a1c0     MOV        DL,AH
    //         0056a1c2     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056a1c5     BSWAP      EAX
    //         0056a1c7     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056a1cd     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         0056a1d3     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffb
    //         0056a1d6     SUB        EDI,0x4
    //         0056a1d9     SUB        ECX,0x4
    //         0056a1dc     JA         LAB_0056a1ac
    //         0056a1de     MOV        EAX,dword ptr [EDI + -0x3]=>DAT_fffffff7
    //         0056a1e1     MOV        DL,AH
    //         0056a1e3     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056a1e6     BSWAP      EAX
    //         0056a1e8     MOV        DL,AH
    //         0056a1ea     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056a1ed     MOV        DL,AL
    //         0056a1ef     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056a1f2     BSWAP      EAX
    //         0056a1f4     MOV        DL,AL
    //         0056a1f6     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056a1fc     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         0056a202     MOV        AL,DL
    //         0056a204     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff7
    //         0056a207     SUB        EDI,0x3
    //         0056a20a     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x0056A210
undefined FUN_0056a210() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056a210()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056a210
    //         0056a210     MOV        EAX,dword ptr [EDI + -0x2]
    //         0056a213     MOV        DL,AL
    //         0056a215     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056a218     MOV        DL,AH
    //         0056a21a     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056a21d     BSWAP      EAX
    //         0056a21f     MOV        DL,AH
    //         0056a221     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056a224     MOV        DL,AL
    //         0056a226     BSWAP      EAX
    //         0056a228     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056a22e     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         0056a234     BSWAP      EAX
    //         0056a236     MOV        AL,DL
    //         0056a238     BSWAP      EAX
    //         0056a23a     MOV        dword ptr [EDI + -0x2],EAX
    //         0056a23d     SUB        EDI,0x3
    //         0056a240     SUB        ECX,0x6
    //                               LAB_0056a243                                                 XREF[1]:     0056a273(j)  
    //         0056a243     MOV        EAX,dword ptr [EDI + -0x3]=>DAT_fffffffa
    //         0056a246     MOV        DL,AL
    //         0056a248     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056a24b     MOV        DL,AH
    //         0056a24d     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056a250     BSWAP      EAX
    //         0056a252     MOV        DL,AL
    //         0056a254     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056a257     MOV        DL,AH
    //         0056a259     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056a25c     BSWAP      EAX
    //         0056a25e     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056a264     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         0056a26a     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffa
    //         0056a26d     SUB        EDI,0x4
    //         0056a270     SUB        ECX,0x4
    //         0056a273     JA         LAB_0056a243
    //         0056a275     MOV        EAX,dword ptr [EDI + -0x3]=>DAT_fffffff6
    //         0056a278     MOV        DL,AH
    //         0056a27a     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056a27d     BSWAP      EAX
    //         0056a27f     MOV        DL,AH
    //         0056a281     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056a284     MOV        DL,AL
    //         0056a286     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056a289     BSWAP      EAX
    //         0056a28b     MOV        DL,AL
    //         0056a28d     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056a293     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         0056a299     MOV        AL,DL
    //         0056a29b     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff6
    //         0056a29e     SUB        EDI,0x3
    //         0056a2a1     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x0056A2A7
undefined FUN_0056a2a7() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056a2a7()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056a2a7
    //         0056a2a7     MOV        EAX,EAX
    //         0056a2aa     MOV        EAX,EAX
    //         0056a2ad     MOV        EAX,EAX
    //         0056a2b0     MOV        EAX,EAX
    //         0056a2b3     MOV        EAX,EAX
    //         0056a2b6     MOV        EAX,EAX
    //         0056a2b9     MOV        EAX,EAX
    //         0056a2bc     MOV        EAX,EAX
    //         0056a2bf     MOV        EAX,EAX
    //         0056a2c2     MOV        EAX,EAX
    //         0056a2c5     MOV        EAX,EAX
    //         0056a2c8     MOV        EAX,EAX
    //         0056a2cb     MOV        EAX,EAX
    //         0056a2ce     MOV        EAX,EAX
    //         0056a2d1     MOV        EAX,EAX
    //         0056a2d4     MOV        EAX,EAX
    //         0056a2d7     MOV        EAX,EAX
    //         0056a2da     MOV        EAX,EAX
    //         0056a2dd     MOV        EAX,EAX
    //         0056a2e0     MOV        EAX,EAX
    //         0056a2e3     MOV        EAX,EAX
    //         0056a2e6     MOV        EAX,EAX
    //         0056a2e9     MOV        EAX,EAX
    //         0056a2ec     MOV        EAX,EAX
    //         0056a2ef     MOV        EAX,EAX
    //         0056a2f2     MOV        EAX,EAX
    //         0056a2f5     MOV        EAX,EAX
    //         0056a2f8     MOV        EAX,EAX
    //         0056a2fb     MOV        EAX,EAX
    //         0056a2fe     MOV        EAX,EAX
    //                               LAB_0056a300                                                 XREF[3]:     FUN_0056cc6c:0056cceb(*), 
    //                                                                                                         FUN_0056d0cc:0056d0f4(*), 
    //                                                                                                         FUN_0056d0fb:0056d120(*)  
    //         0056a300     ADD        byte ptr [EAX],DH
    //         0056a302     PUSH       ESI
    //         0056a303     ADD        byte ptr [EAX],AL
    //         0056a305     XOR        byte ptr [ESI],DL
    //         0056a308     ADD        byte ptr [EAX],DH
    //         0056a30a     PUSH       ESI
    //         0056a30b     ADD        byte ptr [EAX],AL
    //         0056a30d     XOR        byte ptr [ESI],DL
    //         0056a310     PUSH       ES
    //         0056a311     XOR        byte ptr [ESI],DL
    //         0056a314     PUSH       ES
    //         0056a315     XOR        byte ptr [ESI],DL
    //         0056a318     PUSH       ES
    //         0056a319     XOR        byte ptr [ESI],DL
    //         0056a31c     PUSH       ES
    //         0056a31d     XOR        byte ptr [ESI],DL
    //         0056a320     ADC        DH,byte ptr [EAX]
    //         0056a322     PUSH       ESI
    //         0056a323     ADD        byte ptr [EDX],DL
    //         0056a325     XOR        byte ptr [ESI],DL
    //         0056a328     ADC        DH,byte ptr [EAX]
    //         0056a32a     PUSH       ESI
    //         0056a32b     ADD        byte ptr [EBX],AH
    //         0056a32d     XOR        byte ptr [ESI],DL
    //         0056a330     XOR        byte ptr SS:[ESI],DL
    //         0056a334     XOR        byte ptr SS:[ESI],DL
    //         0056a338     XOR        byte ptr SS:[ESI],DL
    //         0056a33c     DEC        EBP
    //         0056a33d     XOR        byte ptr [ESI],DL
    //         0056a340     XOR        byte ptr FS:[ESI],DL
    //         0056a344     JZ         LAB_0056a376
    //         0056a346     PUSH       ESI
    //         0056a347     ADD        byte ptr [ESI + 0xa6005630],CL
    //         0056a34d     XOR        byte ptr [ESI],DL
    //         0056a350     SHL        byte ptr [EAX],0x56
    //         0056a353     ADD        DH,DL
    //         0056a355     XOR        byte ptr [ESI],DL
    //         0056a358     SALC
    //         0056a359     XOR        byte ptr [ESI],DL
    //         0056a35c     HLT
}

// Offset: 0x0056A35D
undefined FUN_0056a35d() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056a35d()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056a35d
    //         0056a35d     XOR        byte ptr [ESI],DL
    //         0056a360     OR         DH,byte ptr [ECX]
    //         0056a362     PUSH       ESI
    //         0056a363     ADD        byte ptr [ECX],AH
    //         0056a365     XOR        dword ptr [ESI],EDX
    //         0056a368     INC        EDX
    //         0056a369     XOR        dword ptr [ESI],EDX
    //         0056a36c     POP        ECX
    //         0056a36d     XOR        dword ptr [ESI],EDX
    //         0056a370     JNZ        LAB_0056a3a3
    //         0056a372     PUSH       ESI
}

// Offset: 0x0056A387
undefined FUN_0056a387() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056a387()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056a387
    //         0056a387     ADD        byte ptr [EDI + 0x33],CL
    //         0056a38a     PUSH       ESI
    //         0056a38b     ADD        DH,BL
    //         0056a38d     XOR        EDX,dword ptr [ESI]
    //         0056a390     IMUL       ESI,dword ptr [EDX],0x337d0056
    //         0056a396     PUSH       ESI
    //         0056a397     ADD        byte ptr [EDI],CL
    //         0056a399     XOR        AL,0x56
    //         0056a39b     ADD        BH,BH
    //         0056a39d     XOR        dword ptr [ESI],EDX
    //         0056a3a0     ADD        ESI,dword ptr [EBX]
    //         0056a3a2     PUSH       ESI
    //                               LAB_0056a3a3                                                 XREF[1]:     FUN_0056a35d:0056a370(j)  
    //         0056a3a3     ADD        byte ptr [EBP + 0x34],AL
    //         0056a3a6     PUSH       ESI
    //         0056a3a7     ADD        byte ptr [EBX],BL
    //         0056a3a9     XOR        DL,byte ptr [ESI]
    //         0056a3ac     TEST       dword ptr [EDX],ESI
    //         0056a3ae     PUSH       ESI
    //         0056a3af     ADD        byte ptr [EBX + 0x3e005633],DH
    //         0056a3b5     XOR        DL,byte ptr [ESI]
    //         0056a3b8     TEST       EAX,0x26005632
    //         0056a3bd     XOR        EDX,dword ptr [ESI]
    //         0056a3c0     JMPF       0x5632:LAB_d2005631
}

// Offset: 0x0056A3C7
undefined FUN_0056a3c7() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056a3c7()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056a3c7
    //         0056a3c7     ADD        byte ptr [EDI + 0x33],CL
    //         0056a3ca     PUSH       ESI
    //         0056a3cb     ADD        DH,BL
    //         0056a3cd     XOR        EDX,dword ptr [ESI]
    //         0056a3d0     IMUL       ESI,dword ptr [EDX],0x337d0056
    //         0056a3d6     PUSH       ESI
    //         0056a3d7     ADD        byte ptr [EDI],CL
    //         0056a3d9     XOR        AL,0x56
    //         0056a3db     ADD        BH,BH
    //         0056a3dd     XOR        dword ptr [ESI],EDX
    //         0056a3e0     ADD        ESI,dword ptr [EBX]
    //         0056a3e2     PUSH       ESI
    //         0056a3e3     ADD        byte ptr [EBP + 0x34],AL
    //         0056a3e6     PUSH       ESI
    //         0056a3e7     ADD        byte ptr [EBX],BL
    //         0056a3e9     XOR        DL,byte ptr [ESI]
    //         0056a3ec     TEST       dword ptr [EDX],ESI
    //         0056a3ee     PUSH       ESI
    //         0056a3ef     ADD        byte ptr [EBX + 0x3e005633],DH
    //         0056a3f5     XOR        DL,byte ptr [ESI]
    //         0056a3f8     TEST       EAX,0x26005632
    //         0056a3fd     XOR        EDX,dword ptr [ESI]
    //         0056a400     JMPF       0x5632:LAB_d2005631
}

// Offset: 0x0056A407
undefined FUN_0056a407() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056a407()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056a407
    //         0056a407     ADD        byte ptr [EDI + 0x33],CL
    //         0056a40a     PUSH       ESI
    //         0056a40b     ADD        DH,BL
    //         0056a40d     XOR        EDX,dword ptr [ESI]
    //         0056a410     IMUL       ESI,dword ptr [EDX],0x337d0056
    //         0056a416     PUSH       ESI
    //         0056a417     ADD        byte ptr [EDI],CL
    //         0056a419     XOR        AL,0x56
    //         0056a41b     ADD        BH,BH
    //         0056a41d     XOR        dword ptr [ESI],EDX
    //         0056a420     ADD        ESI,dword ptr [EBX]
    //         0056a422     PUSH       ESI
    //         0056a423     ADD        byte ptr [EBP + 0x34],AL
    //         0056a426     PUSH       ESI
    //         0056a427     ADD        byte ptr [EBX],BL
    //         0056a429     XOR        DL,byte ptr [ESI]
    //         0056a42c     TEST       dword ptr [EDX],ESI
    //         0056a42e     PUSH       ESI
    //         0056a42f     ADD        byte ptr [EBX + 0x3e005633],DH
    //         0056a435     XOR        DL,byte ptr [ESI]
    //         0056a438     TEST       EAX,0x26005632
    //         0056a43d     XOR        EDX,dword ptr [ESI]
    //         0056a440     JMPF       0x5632:LAB_d2005631
}

// Offset: 0x0056A447
undefined FUN_0056a447() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056a447()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056a447
    //         0056a447     ADD        byte ptr [EDI + 0x33],CL
    //         0056a44a     PUSH       ESI
    //         0056a44b     ADD        DH,BL
    //         0056a44d     XOR        EDX,dword ptr [ESI]
    //         0056a450     IMUL       ESI,dword ptr [EDX],0x337d0056
    //         0056a456     PUSH       ESI
    //         0056a457     ADD        byte ptr [EDI],CL
    //         0056a459     XOR        AL,0x56
    //         0056a45b     ADD        BH,BH
    //         0056a45d     XOR        dword ptr [ESI],EDX
    //         0056a460     ADD        ESI,dword ptr [EBX]
    //         0056a462     PUSH       ESI
    //         0056a463     ADD        byte ptr [EBP + 0x34],AL
    //         0056a466     PUSH       ESI
    //         0056a467     ADD        byte ptr [EBX],BL
    //         0056a469     XOR        DL,byte ptr [ESI]
    //         0056a46c     TEST       dword ptr [EDX],ESI
    //         0056a46e     PUSH       ESI
    //         0056a46f     ADD        byte ptr [EBX + 0x3e005633],DH
    //         0056a475     XOR        DL,byte ptr [ESI]
    //         0056a478     TEST       EAX,0x26005632
    //         0056a47d     XOR        EDX,dword ptr [ESI]
    //         0056a480     JMPF       0x5632:LAB_d2005631
}

// Offset: 0x0056A487
undefined FUN_0056a487() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056a487()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056a487
    //         0056a487     ADD        byte ptr [EDI + 0x33],CL
    //         0056a48a     PUSH       ESI
    //         0056a48b     ADD        DH,BL
    //         0056a48d     XOR        EDX,dword ptr [ESI]
    //         0056a490     IMUL       ESI,dword ptr [EDX],0x337d0056
    //         0056a496     PUSH       ESI
    //         0056a497     ADD        byte ptr [EDI],CL
    //         0056a499     XOR        AL,0x56
    //         0056a49b     ADD        BH,BH
    //         0056a49d     XOR        dword ptr [ESI],EDX
    //         0056a4a0     ADD        ESI,dword ptr [EBX]
    //         0056a4a2     PUSH       ESI
    //         0056a4a3     ADD        byte ptr [EBP + 0x34],AL
    //         0056a4a6     PUSH       ESI
    //         0056a4a7     ADD        byte ptr [EBX],BL
    //         0056a4a9     XOR        DL,byte ptr [ESI]
    //         0056a4ac     TEST       dword ptr [EDX],ESI
    //         0056a4ae     PUSH       ESI
    //         0056a4af     ADD        byte ptr [EBX + 0x3e005633],DH
    //         0056a4b5     XOR        DL,byte ptr [ESI]
    //         0056a4b8     TEST       EAX,0x26005632
    //         0056a4bd     XOR        EDX,dword ptr [ESI]
    //         0056a4c0     JMPF       0x5632:LAB_d2005631
}

// Offset: 0x0056A4C7
undefined FUN_0056a4c7() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056a4c7()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056a4c7
    //         0056a4c7     ADD        byte ptr [EDI + 0x33],CL
    //         0056a4ca     PUSH       ESI
    //         0056a4cb     ADD        DH,BL
    //         0056a4cd     XOR        EDX,dword ptr [ESI]
    //         0056a4d0     IMUL       ESI,dword ptr [EDX],0x337d0056
    //         0056a4d6     PUSH       ESI
    //         0056a4d7     ADD        byte ptr [EDI],CL
    //         0056a4d9     XOR        AL,0x56
    //         0056a4db     ADD        BH,BH
    //         0056a4dd     XOR        dword ptr [ESI],EDX
    //         0056a4e0     ADD        ESI,dword ptr [EBX]
    //         0056a4e2     PUSH       ESI
    //         0056a4e3     ADD        byte ptr [EBP + 0x34],AL
    //         0056a4e6     PUSH       ESI
    //         0056a4e7     ADD        byte ptr [EBX],BL
    //         0056a4e9     XOR        DL,byte ptr [ESI]
    //         0056a4ec     TEST       dword ptr [EDX],ESI
    //         0056a4ee     PUSH       ESI
    //         0056a4ef     ADD        byte ptr [EBX + 0x3e005633],DH
    //         0056a4f5     XOR        DL,byte ptr [ESI]
    //         0056a4f8     TEST       EAX,0x26005632
    //         0056a4fd     XOR        EDX,dword ptr [ESI]
    //         0056a500     ADD        byte ptr [EAX],DH
    //         0056a502     PUSH       ESI
    //         0056a503     ADD        byte ptr [EAX],AL
    //         0056a505     XOR        byte ptr [ESI],DL
    //         0056a508     ADD        byte ptr [EAX],DH
    //         0056a50a     PUSH       ESI
    //         0056a50b     ADD        byte ptr [EAX],AL
    //         0056a50d     XOR        byte ptr [ESI],DL
    //         0056a510     XOR        dword ptr [ESI + EDX*0x2],0x0
    //         0056a514     WAIT
    //         0056a515     XOR        AL,0x56
    //         0056a517     ADD        byte ptr [EBX + 0x9b005634],AL
    //         0056a51d     XOR        AL,0x56
    //         0056a51f     ADD        byte ptr [EBX + 0xd0005634],DH
    //         0056a525     XOR        AL,0x56
    //         0056a527     ADD        byte ptr [EBX + 0xf1005634],DH
    //         0056a52d     XOR        AL,0x56
    //         0056a52f     ADD        byte ptr [ESI*0x1 + 0x35370056],DL
    //         0056a536     PUSH       ESI
    //         0056a537     ADD        byte ptr [EBX + 0x35],BL
    //         0056a53a     PUSH       ESI
    //         0056a53b     ADD        byte ptr [EDX + 0xb9005635],CL
    //         0056a541     XOR        EAX,0x35d60056
    //         0056a546     PUSH       ESI
    //         0056a547     ADD        byte ptr [ESI + ESI*0x1],CL
    //         0056a54a     PUSH       ESI
    //         0056a54b     ADD        byte ptr [EAX + 0x36],AL
    //         0056a54e     PUSH       ESI
    //         0056a54f     ADD        byte ptr [EBP + 0x36],DH
    //         0056a552     PUSH       ESI
    //         0056a553     ADD        byte ptr [ESI + ESI*0x1 + 0x36df0056],AH
    //         0056a55a     PUSH       ESI
    //         0056a55b     ADD        byte ptr [ECX],BL
    //         0056a55d     AAA
    //         0056a55e     PUSH       ESI
    //         0056a55f     ADD        byte ptr [EAX + 0x37],CL
    //         0056a562     PUSH       ESI
    //         0056a563     ADD        byte ptr [EDI + ESI*0x1 + 0x56],BH
    //         0056a567     ADD        byte ptr [EBP + 0xf1005637],BH
    //         0056a56d     AAA
    //         0056a56e     PUSH       ESI
    //         0056a56f     ADD        byte ptr [EDX],DH
    //         0056a571     CMP        byte ptr [ESI],DL
    //         0056a574     INSB       ES:EDI,DX
    //         0056a575     CMP        byte ptr [ESI],DL
    //         0056a578     CMPSD      ES:EDI,ESI
    //         0056a579     CMP        byte ptr [ESI],DL
    //         0056a57c     IN         EAX,DX
    //         0056a57d     CMP        byte ptr [ESI],DL
    //         0056a580     XOR        EDI,dword ptr [ECX]
    //         0056a582     PUSH       ESI
    //         0056a583     ADD        DH,CL
    //         0056a585     CMP        DL,byte ptr [ESI]
    //         0056a588     STOSB      ES:EDI
    //         0056a589     CMP        EDX,dword ptr [ESI]
    //         0056a58c     XCHG       EAX,ESI
    //         0056a58d     CMP        AL,0x56
    //         0056a58f     ADD        byte ptr [DAT_fc00563a],AL
    //         0056a595     CMP        EDX,dword ptr [ESI]
    //         0056a598     JMP        LAB_5456fbd9
}

// Offset: 0x0056A59D
undefined FUN_0056a59d() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056a59d()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056a59d
    //         0056a59d     CMP        dword ptr [ESI],EDX
    //         0056a5a0     AND        BH,byte ptr [EBX]
    //         0056a5a2     PUSH       ESI
    //         0056a5a3     ADD        byte ptr [ECX + 0x3d],AL
    //         0056a5a6     PUSH       ESI
    //         0056a5a7     ADD        byte ptr [EAX + 0x39005639],CL
    //         0056a5ad     CMP        DL,byte ptr [ESI]
    //         0056a5b0     PUSH       EBP
    //         0056a5b1     CMP        AL,0x56
    //         0056a5b3     ADD        BL,AL
    //         0056a5b5     CMP        dword ptr [ESI],EDX
    //         0056a5b8     CMP        dword ptr [EDX],0x3b5d0056
    //         0056a5be     PUSH       ESI
    //         0056a5bf     ADD        byte ptr [EBX],DH
    //         0056a5c1     CMP        dword ptr [ESI],EDX
    //         0056a5c4     INTO
    //         0056a5c5     CMP        DL,byte ptr [ESI]
    //         0056a5c8     STOSB      ES:EDI
    //         0056a5c9     CMP        EDX,dword ptr [ESI]
    //         0056a5cc     XCHG       EAX,ESI
    //         0056a5cd     CMP        AL,0x56
    //         0056a5cf     ADD        byte ptr [DAT_fc00563a],AL
    //         0056a5d5     CMP        EDX,dword ptr [ESI]
    //         0056a5d8     JMP        LAB_5456fc19
}

// Offset: 0x0056A5DD
undefined FUN_0056a5dd() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056a5dd()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056a5dd
    //         0056a5dd     CMP        dword ptr [ESI],EDX
    //         0056a5e0     AND        BH,byte ptr [EBX]
    //         0056a5e2     PUSH       ESI
    //         0056a5e3     ADD        byte ptr [ECX + 0x3d],AL
    //         0056a5e6     PUSH       ESI
    //         0056a5e7     ADD        byte ptr [EAX + 0x39005639],CL
    //         0056a5ed     CMP        DL,byte ptr [ESI]
    //         0056a5f0     PUSH       EBP
    //         0056a5f1     CMP        AL,0x56
    //         0056a5f3     ADD        BL,AL
    //         0056a5f5     CMP        dword ptr [ESI],EDX
    //         0056a5f8     CMP        dword ptr [EDX],0x3b5d0056
    //         0056a5fe     PUSH       ESI
    //         0056a5ff     ADD        byte ptr [EBX],DH
    //         0056a601     CMP        dword ptr [ESI],EDX
    //         0056a604     INTO
    //         0056a605     CMP        DL,byte ptr [ESI]
    //         0056a608     STOSB      ES:EDI
    //         0056a609     CMP        EDX,dword ptr [ESI]
    //         0056a60c     XCHG       EAX,ESI
    //         0056a60d     CMP        AL,0x56
    //         0056a60f     ADD        byte ptr [DAT_fc00563a],AL
    //         0056a615     CMP        EDX,dword ptr [ESI]
    //         0056a618     JMP        LAB_5456fc59
}

// Offset: 0x0056A61D
undefined FUN_0056a61d() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056a61d()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056a61d
    //         0056a61d     CMP        dword ptr [ESI],EDX
    //         0056a620     AND        BH,byte ptr [EBX]
    //         0056a622     PUSH       ESI
    //         0056a623     ADD        byte ptr [ECX + 0x3d],AL
    //         0056a626     PUSH       ESI
    //         0056a627     ADD        byte ptr [EAX + 0x39005639],CL
    //         0056a62d     CMP        DL,byte ptr [ESI]
    //         0056a630     PUSH       EBP
    //         0056a631     CMP        AL,0x56
    //         0056a633     ADD        BL,AL
    //         0056a635     CMP        dword ptr [ESI],EDX
    //         0056a638     CMP        dword ptr [EDX],0x3b5d0056
    //         0056a63e     PUSH       ESI
    //         0056a63f     ADD        byte ptr [EBX],DH
    //         0056a641     CMP        dword ptr [ESI],EDX
    //         0056a644     INTO
    //         0056a645     CMP        DL,byte ptr [ESI]
    //         0056a648     STOSB      ES:EDI
    //         0056a649     CMP        EDX,dword ptr [ESI]
    //         0056a64c     XCHG       EAX,ESI
    //         0056a64d     CMP        AL,0x56
    //         0056a64f     ADD        byte ptr [DAT_fc00563a],AL
    //         0056a655     CMP        EDX,dword ptr [ESI]
    //         0056a658     JMP        LAB_5456fc99
}

// Offset: 0x0056A65D
undefined FUN_0056a65d() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056a65d()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056a65d
    //         0056a65d     CMP        dword ptr [ESI],EDX
    //         0056a660     AND        BH,byte ptr [EBX]
    //         0056a662     PUSH       ESI
    //         0056a663     ADD        byte ptr [ECX + 0x3d],AL
    //         0056a666     PUSH       ESI
    //         0056a667     ADD        byte ptr [EAX + 0x39005639],CL
    //         0056a66d     CMP        DL,byte ptr [ESI]
    //         0056a670     PUSH       EBP
    //         0056a671     CMP        AL,0x56
    //         0056a673     ADD        BL,AL
    //         0056a675     CMP        dword ptr [ESI],EDX
    //         0056a678     CMP        dword ptr [EDX],0x3b5d0056
    //         0056a67e     PUSH       ESI
    //         0056a67f     ADD        byte ptr [EBX],DH
    //         0056a681     CMP        dword ptr [ESI],EDX
    //         0056a684     INTO
    //         0056a685     CMP        DL,byte ptr [ESI]
    //         0056a688     STOSB      ES:EDI
    //         0056a689     CMP        EDX,dword ptr [ESI]
    //         0056a68c     XCHG       EAX,ESI
    //         0056a68d     CMP        AL,0x56
    //         0056a68f     ADD        byte ptr [DAT_fc00563a],AL
    //         0056a695     CMP        EDX,dword ptr [ESI]
    //         0056a698     JMP        LAB_5456fcd9
}

// Offset: 0x0056A69D
undefined FUN_0056a69d() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056a69d()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056a69d
    //         0056a69d     CMP        dword ptr [ESI],EDX
    //         0056a6a0     AND        BH,byte ptr [EBX]
    //         0056a6a2     PUSH       ESI
    //         0056a6a3     ADD        byte ptr [ECX + 0x3d],AL
    //         0056a6a6     PUSH       ESI
    //         0056a6a7     ADD        byte ptr [EAX + 0x39005639],CL
    //         0056a6ad     CMP        DL,byte ptr [ESI]
    //         0056a6b0     PUSH       EBP
    //         0056a6b1     CMP        AL,0x56
    //         0056a6b3     ADD        BL,AL
    //         0056a6b5     CMP        dword ptr [ESI],EDX
    //         0056a6b8     CMP        dword ptr [EDX],0x3b5d0056
    //         0056a6be     PUSH       ESI
    //         0056a6bf     ADD        byte ptr [EBX],DH
    //         0056a6c1     CMP        dword ptr [ESI],EDX
    //         0056a6c4     INTO
    //         0056a6c5     CMP        DL,byte ptr [ESI]
    //         0056a6c8     STOSB      ES:EDI
    //         0056a6c9     CMP        EDX,dword ptr [ESI]
    //         0056a6cc     XCHG       EAX,ESI
    //         0056a6cd     CMP        AL,0x56
    //         0056a6cf     ADD        byte ptr [DAT_fc00563a],AL
    //         0056a6d5     CMP        EDX,dword ptr [ESI]
    //         0056a6d8     JMP        LAB_5456fd19
}

// Offset: 0x0056A6DD
undefined FUN_0056a6dd() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056a6dd()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x66c   local_66c                 XREF[1]:     0056af69(*)  
    //              undefined4        Stack[-0x674   local_674                 XREF[1]:     0056af71(*)  
    //              undefined4        Stack[-0x7d0   local_7d0                 XREF[1]:     0056b149(*)  
    //                               FUN_0056a6dd
    //         0056a6dd     CMP        dword ptr [ESI],EDX
    //         0056a6e0     AND        BH,byte ptr [EBX]
    //         0056a6e2     PUSH       ESI
    //         0056a6e3     ADD        byte ptr [ECX + 0x3d],AL
    //         0056a6e6     PUSH       ESI
    //         0056a6e7     ADD        byte ptr [EAX + 0x39005639],CL
    //         0056a6ed     CMP        DL,byte ptr [ESI]
    //         0056a6f0     PUSH       EBP
    //         0056a6f1     CMP        AL,0x56
    //         0056a6f3     ADD        BL,AL
    //         0056a6f5     CMP        dword ptr [ESI],EDX
    //         0056a6f8     CMP        dword ptr [EDX],0x3b5d0056
    //         0056a6fe     PUSH       ESI
    //                               LAB_0056a6ff+1                                               XREF[0,6]:   _ASMDraw_HLine:0056c8eb(*), 
    //                                                                                                         _ASMDraw_HLine:0056c993(*), 
    //                                                                                                         FUN_0056cde6:0056ce75(*), 
    //                                                                                                         FUN_0056ce99:0056cf15(*), 
    //                                                                                                         FUN_0056d186:0056d1d1(*), 
    //                                                                                                         FUN_0056d1d8:0056d211(*)  
    //         0056a6ff     ADD        byte ptr [EAX],AL
    //         0056a701     XOR        byte ptr [ESI],DL
    //         0056a704     ADD        byte ptr [EAX],DH
    //         0056a706     PUSH       ESI
    //         0056a707     ADD        byte ptr [EAX],AL
    //         0056a709     XOR        byte ptr [ESI],DL
    //         0056a70c     ADD        byte ptr [EAX],DH
    //         0056a70e     PUSH       ESI
    //         0056a70f     ADD        byte ptr [EAX + 0xa000563d],AH
    //         0056a715     CMP        EAX,0x3da00056
    //         0056a71a     PUSH       ESI
    //         0056a71b     ADD        byte ptr [EAX + 0xa900563d],AH
    //         0056a721     CMP        EAX,0x3da90056
    //         0056a726     PUSH       ESI
    //         0056a727     ADD        byte ptr [ECX + 0xb500563d],CH
    //         0056a72d     CMP        EAX,0x3dc10056
    //         0056a732     PUSH       ESI
    //         0056a733     ADD        CL,AL
    //         0056a735     CMP        EAX,0x3dc10056
    //         0056a73a     PUSH       ESI
    //         0056a73b     ADD        AL,DL
    //         0056a73d     CMP        EAX,0x3ddf0056
    //         0056a742     PUSH       ESI
    //         0056a743     ADD        DL,CH
    //         0056a745     CMP        EAX,0x3dfc0056
    //         0056a74a     PUSH       ESI
    //         0056a74b     ADD        byte ptr [ESI],CL
    //         0056a74d     PUSH       ESI
    //         0056a74f     ADD        byte ptr [EAX],AH
    //         0056a751     PUSH       ESI
    //         0056a753     ADD        byte ptr [ESI],CH
    //         0056a755     PUSH       ESI
    //         0056a757     ADD        byte ptr [EBX + 0x3e],AL
    //         0056a75a     PUSH       ESI
    //         0056a75b     ADD        byte ptr [EAX + 0x3e],BL
    //         0056a75e     PUSH       ESI
    //         0056a75f     ADD        byte ptr [ESI + 0x3e],AH
    //         0056a762     PUSH       ESI
    //         0056a763     ADD        byte ptr [EDI + 0x3e],DH
    //         0056a766     PUSH       ESI
    //         0056a767     ADD        byte ptr [EDI + 0xa000563e],CL
    //         0056a76d     PUSH       ESI
    //         0056a76f     ADD        byte ptr [ECX + 0xc500563e],DH
    //         0056a775     PUSH       ESI
    //         0056a777     ADD        CL,BL
    //         0056a779     PUSH       ESI
    //         0056a77b     ADD        CH,CH
    //         0056a77d     PUSH       ESI
    //         0056a77f     ADD        byte ptr [ECX],AL
    //         0056a781     AAS
    //         0056a782     PUSH       ESI
    //         0056a783     ADD        byte ptr [EBX + 0xf700563f],AH
    //         0056a789     AAS
    //         0056a78a     PUSH       ESI
    //         0056a78b     ADD        byte ptr [EAX + EAX*0x2 + 0x56],DL
    //         0056a78f     ADD        byte ptr [EDX + 0x3f],BL
    //         0056a792     PUSH       ESI
    //         0056a793     ADD        byte ptr [ESI],DL
    //         0056a795     INC        EAX
    //         0056a796     PUSH       ESI
    //         0056a797     ADD        byte ptr [EBX + 0x40],DH
    //         0056a79a     PUSH       ESI
    //         0056a79b     ADD        byte ptr [ECX],DL
    //         0056a79d     AAS
    //         0056a79e     PUSH       ESI
    //         0056a79f     ADD        DL,AL
    //         0056a7a1     AAS
    //         0056a7a2     PUSH       ESI
    //         0056a7a3     ADD        byte ptr [EBP + 0x25005640],DL
    //         0056a7a9     AAS
    //         0056a7aa     PUSH       ESI
    //         0056a7ab     ADD        byte ptr [ESI + 0x3f],CH
    //         0056a7ae     PUSH       ESI
    //         0056a7af     ADD        byte ptr [EAX],BH
    //         0056a7b1     INC        EAX
    //         0056a7b2     PUSH       ESI
    //         0056a7b3     ADD        byte ptr [ESI],BH
    //         0056a7b5     AAS
    //         0056a7b6     PUSH       ESI
    //         0056a7b7     ADD        byte ptr [EDI + 0xdb00563f],AL
    //         0056a7bd     AAS
    //         0056a7be     PUSH       ESI
    //         0056a7bf     ADD        byte ptr [ECX],AL
    //         0056a7c1     AAS
    //         0056a7c2     PUSH       ESI
    //         0056a7c3     ADD        byte ptr [EBX + 0xf700563f],AH
    //         0056a7c9     AAS
    //         0056a7ca     PUSH       ESI
    //         0056a7cb     ADD        byte ptr [EAX + EAX*0x2 + 0x56],DL
    //         0056a7cf     ADD        byte ptr [EDX + 0x3f],BL
    //         0056a7d2     PUSH       ESI
    //         0056a7d3     ADD        byte ptr [ESI],DL
    //         0056a7d5     INC        EAX
    //         0056a7d6     PUSH       ESI
    //         0056a7d7     ADD        byte ptr [EBX + 0x40],DH
    //         0056a7da     PUSH       ESI
    //         0056a7db     ADD        byte ptr [ECX],DL
    //         0056a7dd     AAS
    //         0056a7de     PUSH       ESI
    //         0056a7df     ADD        DL,AL
    //         0056a7e1     AAS
    //         0056a7e2     PUSH       ESI
    //         0056a7e3     ADD        byte ptr [EBP + 0x25005640],DL
    //         0056a7e9     AAS
    //         0056a7ea     PUSH       ESI
    //         0056a7eb     ADD        byte ptr [ESI + 0x3f],CH
    //         0056a7ee     PUSH       ESI
    //         0056a7ef     ADD        byte ptr [EAX],BH
    //         0056a7f1     INC        EAX
    //         0056a7f2     PUSH       ESI
    //         0056a7f3     ADD        byte ptr [ESI],BH
    //         0056a7f5     AAS
    //         0056a7f6     PUSH       ESI
    //         0056a7f7     ADD        byte ptr [EDI + 0xdb00563f],AL
    //         0056a7fd     AAS
    //         0056a7fe     PUSH       ESI
    //         0056a7ff     ADD        byte ptr [ECX],AL
    //         0056a801     AAS
    //         0056a802     PUSH       ESI
    //         0056a803     ADD        byte ptr [EBX + 0xf700563f],AH
    //         0056a809     AAS
    //         0056a80a     PUSH       ESI
    //         0056a80b     ADD        byte ptr [EAX + EAX*0x2 + 0x56],DL
    //         0056a80f     ADD        byte ptr [EDX + 0x3f],BL
    //         0056a812     PUSH       ESI
    //         0056a813     ADD        byte ptr [ESI],DL
    //         0056a815     INC        EAX
    //         0056a816     PUSH       ESI
    //         0056a817     ADD        byte ptr [EBX + 0x40],DH
    //         0056a81a     PUSH       ESI
    //         0056a81b     ADD        byte ptr [ECX],DL
    //         0056a81d     AAS
    //         0056a81e     PUSH       ESI
    //         0056a81f     ADD        DL,AL
    //         0056a821     AAS
    //         0056a822     PUSH       ESI
    //         0056a823     ADD        byte ptr [EBP + 0x25005640],DL
    //         0056a829     AAS
    //         0056a82a     PUSH       ESI
    //         0056a82b     ADD        byte ptr [ESI + 0x3f],CH
    //         0056a82e     PUSH       ESI
    //         0056a82f     ADD        byte ptr [EAX],BH
    //         0056a831     INC        EAX
    //         0056a832     PUSH       ESI
    //         0056a833     ADD        byte ptr [ESI],BH
    //         0056a835     AAS
    //         0056a836     PUSH       ESI
    //         0056a837     ADD        byte ptr [EDI + 0xdb00563f],AL
    //         0056a83d     AAS
    //         0056a83e     PUSH       ESI
    //         0056a83f     ADD        byte ptr [ECX],AL
    //         0056a841     AAS
    //         0056a842     PUSH       ESI
    //         0056a843     ADD        byte ptr [EBX + 0xf700563f],AH
    //         0056a849     AAS
    //         0056a84a     PUSH       ESI
    //         0056a84b     ADD        byte ptr [EAX + EAX*0x2 + 0x56],DL
    //         0056a84f     ADD        byte ptr [EDX + 0x3f],BL
    //         0056a852     PUSH       ESI
    //         0056a853     ADD        byte ptr [ESI],DL
    //         0056a855     INC        EAX
    //         0056a856     PUSH       ESI
    //         0056a857     ADD        byte ptr [EBX + 0x40],DH
    //         0056a85a     PUSH       ESI
    //         0056a85b     ADD        byte ptr [ECX],DL
    //         0056a85d     AAS
    //         0056a85e     PUSH       ESI
    //         0056a85f     ADD        DL,AL
    //         0056a861     AAS
    //         0056a862     PUSH       ESI
    //         0056a863     ADD        byte ptr [EBP + 0x25005640],DL
    //         0056a869     AAS
    //         0056a86a     PUSH       ESI
    //         0056a86b     ADD        byte ptr [ESI + 0x3f],CH
    //         0056a86e     PUSH       ESI
    //         0056a86f     ADD        byte ptr [EAX],BH
    //         0056a871     INC        EAX
    //         0056a872     PUSH       ESI
    //         0056a873     ADD        byte ptr [ESI],BH
    //         0056a875     AAS
    //         0056a876     PUSH       ESI
    //         0056a877     ADD        byte ptr [EDI + 0xdb00563f],AL
    //         0056a87d     AAS
    //         0056a87e     PUSH       ESI
    //         0056a87f     ADD        byte ptr [ECX],AL
    //         0056a881     AAS
    //         0056a882     PUSH       ESI
    //         0056a883     ADD        byte ptr [EBX + 0xf700563f],AH
    //         0056a889     AAS
    //         0056a88a     PUSH       ESI
    //         0056a88b     ADD        byte ptr [EAX + EAX*0x2 + 0x56],DL
    //         0056a88f     ADD        byte ptr [EDX + 0x3f],BL
    //         0056a892     PUSH       ESI
    //         0056a893     ADD        byte ptr [ESI],DL
    //         0056a895     INC        EAX
    //         0056a896     PUSH       ESI
    //         0056a897     ADD        byte ptr [EBX + 0x40],DH
    //         0056a89a     PUSH       ESI
    //         0056a89b     ADD        byte ptr [ECX],DL
    //         0056a89d     AAS
    //         0056a89e     PUSH       ESI
    //         0056a89f     ADD        DL,AL
    //         0056a8a1     AAS
    //         0056a8a2     PUSH       ESI
    //         0056a8a3     ADD        byte ptr [EBP + 0x25005640],DL
    //         0056a8a9     AAS
    //         0056a8aa     PUSH       ESI
    //         0056a8ab     ADD        byte ptr [ESI + 0x3f],CH
    //         0056a8ae     PUSH       ESI
    //         0056a8af     ADD        byte ptr [EAX],BH
    //         0056a8b1     INC        EAX
    //         0056a8b2     PUSH       ESI
    //         0056a8b3     ADD        byte ptr [ESI],BH
    //         0056a8b5     AAS
    //         0056a8b6     PUSH       ESI
    //         0056a8b7     ADD        byte ptr [EDI + 0xdb00563f],AL
    //         0056a8bd     AAS
    //         0056a8be     PUSH       ESI
    //         0056a8bf     ADD        byte ptr [ECX],AL
    //         0056a8c1     AAS
    //         0056a8c2     PUSH       ESI
    //         0056a8c3     ADD        byte ptr [EBX + 0xf700563f],AH
    //         0056a8c9     AAS
    //         0056a8ca     PUSH       ESI
    //         0056a8cb     ADD        byte ptr [EAX + EAX*0x2 + 0x56],DL
    //         0056a8cf     ADD        byte ptr [EDX + 0x3f],BL
    //         0056a8d2     PUSH       ESI
    //         0056a8d3     ADD        byte ptr [ESI],DL
    //         0056a8d5     INC        EAX
    //         0056a8d6     PUSH       ESI
    //         0056a8d7     ADD        byte ptr [EBX + 0x40],DH
    //         0056a8da     PUSH       ESI
    //         0056a8db     ADD        byte ptr [ECX],DL
    //         0056a8dd     AAS
    //         0056a8de     PUSH       ESI
    //         0056a8df     ADD        DL,AL
    //         0056a8e1     AAS
    //         0056a8e2     PUSH       ESI
    //         0056a8e3     ADD        byte ptr [EBP + 0x25005640],DL
    //         0056a8e9     AAS
    //         0056a8ea     PUSH       ESI
    //         0056a8eb     ADD        byte ptr [ESI + 0x3f],CH
    //         0056a8ee     PUSH       ESI
    //         0056a8ef     ADD        byte ptr [EAX],BH
    //         0056a8f1     INC        EAX
    //         0056a8f2     PUSH       ESI
    //         0056a8f3     ADD        byte ptr [ESI],BH
    //         0056a8f5     AAS
    //         0056a8f6     PUSH       ESI
    //         0056a8f7     ADD        byte ptr [EDI + 0xdb00563f],AL
    //         0056a8fd     AAS
    //         0056a8fe     PUSH       ESI
    //         0056a8ff     ADD        byte ptr [EAX],AL
    //         0056a901     XOR        byte ptr [ESI],DL
    //         0056a904     ADD        byte ptr [EAX],DH
    //         0056a906     PUSH       ESI
    //         0056a907     ADD        byte ptr [EAX],AL
    //         0056a909     XOR        byte ptr [ESI],DL
    //         0056a90c     ADD        byte ptr [EAX],DH
    //         0056a90e     PUSH       ESI
    //         0056a90f     ADD        byte ptr [EDX + 0xc3005640],BH
    //         0056a915     INC        EAX
    //         0056a916     PUSH       ESI
    //         0056a917     ADD        byte ptr [EDX + 0xc3005640],BH
    //         0056a91d     INC        EAX
    //         0056a91e     PUSH       ESI
    //         0056a91f     ADD        AH,CL
    //         0056a921     INC        EAX
    //         0056a922     PUSH       ESI
    //         0056a923     ADD        AL,BL
    //         0056a925     INC        EAX
    //         0056a926     PUSH       ESI
    //         0056a927     ADD        AH,CL
    //         0056a929     INC        EAX
    //         0056a92a     PUSH       ESI
    //         0056a92b     ADD        AL,BL
    //         0056a92d     INC        EAX
    //         0056a92e     PUSH       ESI
    //         0056a92f     ADD        DH,AH
    //         0056a931     INC        EAX
    //         0056a932     PUSH       ESI
    //         0056a933     ADD        CH,DH
    //         0056a935     INC        EAX
    //         0056a936     PUSH       ESI
    //         0056a937     ADD        byte ptr [ECX + EAX*0x2],AL
    //         0056a93a     PUSH       ESI
    //         0056a93b     ADD        byte ptr [EBX],DL
    //         0056a93d     INC        ECX
    //         0056a93e     PUSH       ESI
    //         0056a93f     ADD        byte ptr [EDX],AH
    //         0056a941     INC        ECX
    //         0056a942     PUSH       ESI
    //         0056a943     ADD        byte ptr [DAT_3f005641],CH
    //         0056a949     INC        ECX
    //         0056a94a     PUSH       ESI
    //         0056a94b     ADD        byte ptr [ECX + 0x41],DL
    //         0056a94e     PUSH       ESI
    //         0056a94f     ADD        byte ptr [EBX + 0x41],AH
    //         0056a952     PUSH       ESI
    //         0056a953     ADD        byte ptr [ECX + 0x41],DH
    //         0056a956     PUSH       ESI
    //         0056a957     ADD        byte ptr [ESI + 0x9b005641],AL
    //         0056a95d     INC        ECX
    //         0056a95e     PUSH       ESI
    //         0056a95f     ADD        byte ptr [ECX + 0xba005641],CH
    //         0056a965     INC        ECX
    //         0056a966     PUSH       ESI
    //         0056a967     ADD        DL,DL
    //         0056a969     INC        ECX
    //         0056a96a     PUSH       ESI
    //         0056a96b     ADD        BL,AH
    //         0056a96d     INC        ECX
    //         0056a96e     PUSH       ESI
    //         0056a96f     ADD        AH,DH
    //         0056a971     INC        ECX
    //         0056a972     PUSH       ESI
    //         0056a973     ADD        byte ptr [EAX],CL
    //         0056a975     INC        EDX
    //         0056a976     PUSH       ESI
    //         0056a977     ADD        byte ptr [EDX + EAX*0x2],BL
    //         0056a97a     PUSH       ESI
    //         0056a97b     ADD        byte ptr [EAX],DH
    //         0056a97d     INC        EDX
    //         0056a97e     PUSH       ESI
    //         0056a97f     ADD        byte ptr [EDX + EAX*0x2 + 0x56],AL
    //         0056a983     ADD        DH,AH
    //         0056a985     INC        EDX
    //         0056a986     PUSH       ESI
    //         0056a987     ADD        byte ptr [EDX],BH
    //         0056a989     INC        EBX
    //         0056a98a     PUSH       ESI
    //         0056a98b     ADD        byte ptr [EDI + 0x9d005643],DL
    //         0056a991     INC        EDX
    //         0056a992     PUSH       ESI
    //         0056a993     ADD        byte ptr [ECX + 0x43],BL
    //         0056a996     PUSH       ESI
    //         0056a997     ADD        byte ptr [ESI + 0x54005643],DH
    //         0056a99d     INC        EDX
    //         0056a99e     PUSH       ESI
    //         0056a99f     ADD        byte ptr [DAT_d8005643],AL
    //         0056a9a5     INC        EBX
    //         0056a9a6     PUSH       ESI
    //         0056a9a7     ADD        byte ptr [EAX + 0x42],CH
    //         0056a9aa     PUSH       ESI
    //         0056a9ab     ADD        byte ptr [ECX + 0x7b005642],DH
    //         0056a9b1     INC        EBX
    //         0056a9b2     PUSH       ESI
    //         0056a9b3     ADD        byte ptr [ECX + 0xca005642],AL
    //         0056a9b9     INC        EDX
    //         0056a9ba     PUSH       ESI
    //         0056a9bb     ADD        byte ptr [ESI],BL
    //         0056a9bd     INC        EBX
    //         0056a9be     PUSH       ESI
    //         0056a9bf     ADD        byte ptr [EDX + EAX*0x2 + 0x56],AL
    //         0056a9c3     ADD        DH,AH
    //         0056a9c5     INC        EDX
    //         0056a9c6     PUSH       ESI
    //         0056a9c7     ADD        byte ptr [EDX],BH
    //         0056a9c9     INC        EBX
    //         0056a9ca     PUSH       ESI
    //         0056a9cb     ADD        byte ptr [EDI + 0x9d005643],DL
    //         0056a9d1     INC        EDX
    //         0056a9d2     PUSH       ESI
    //         0056a9d3     ADD        byte ptr [ECX + 0x43],BL
    //         0056a9d6     PUSH       ESI
    //         0056a9d7     ADD        byte ptr [ESI + 0x54005643],DH
    //         0056a9dd     INC        EDX
    //         0056a9de     PUSH       ESI
    //         0056a9df     ADD        byte ptr [DAT_d8005643],AL
    //         0056a9e5     INC        EBX
    //         0056a9e6     PUSH       ESI
    //         0056a9e7     ADD        byte ptr [EAX + 0x42],CH
    //         0056a9ea     PUSH       ESI
    //         0056a9eb     ADD        byte ptr [ECX + 0x7b005642],DH
    //         0056a9f1     INC        EBX
    //         0056a9f2     PUSH       ESI
    //         0056a9f3     ADD        byte ptr [ECX + 0xca005642],AL
    //         0056a9f9     INC        EDX
    //         0056a9fa     PUSH       ESI
    //         0056a9fb     ADD        byte ptr [ESI],BL
    //         0056a9fd     INC        EBX
    //         0056a9fe     PUSH       ESI
    //         0056a9ff     ADD        byte ptr [EDX + EAX*0x2 + 0x56],AL
    //         0056aa03     ADD        DH,AH
    //         0056aa05     INC        EDX
    //         0056aa06     PUSH       ESI
    //         0056aa07     ADD        byte ptr [EDX],BH
    //         0056aa09     INC        EBX
    //         0056aa0a     PUSH       ESI
    //         0056aa0b     ADD        byte ptr [EDI + 0x9d005643],DL
    //         0056aa11     INC        EDX
    //         0056aa12     PUSH       ESI
    //         0056aa13     ADD        byte ptr [ECX + 0x43],BL
    //         0056aa16     PUSH       ESI
    //         0056aa17     ADD        byte ptr [ESI + 0x54005643],DH
    //         0056aa1d     INC        EDX
    //         0056aa1e     PUSH       ESI
    //         0056aa1f     ADD        byte ptr [DAT_d8005643],AL
    //         0056aa25     INC        EBX
    //         0056aa26     PUSH       ESI
    //         0056aa27     ADD        byte ptr [EAX + 0x42],CH
    //         0056aa2a     PUSH       ESI
    //         0056aa2b     ADD        byte ptr [ECX + 0x7b005642],DH
    //         0056aa31     INC        EBX
    //         0056aa32     PUSH       ESI
    //         0056aa33     ADD        byte ptr [ECX + 0xca005642],AL
    //         0056aa39     INC        EDX
    //         0056aa3a     PUSH       ESI
    //         0056aa3b     ADD        byte ptr [ESI],BL
    //         0056aa3d     INC        EBX
    //         0056aa3e     PUSH       ESI
    //         0056aa3f     ADD        byte ptr [EDX + EAX*0x2 + 0x56],AL
    //         0056aa43     ADD        DH,AH
    //         0056aa45     INC        EDX
    //         0056aa46     PUSH       ESI
    //         0056aa47     ADD        byte ptr [EDX],BH
    //         0056aa49     INC        EBX
    //         0056aa4a     PUSH       ESI
    //         0056aa4b     ADD        byte ptr [EDI + 0x9d005643],DL
    //         0056aa51     INC        EDX
    //         0056aa52     PUSH       ESI
    //         0056aa53     ADD        byte ptr [ECX + 0x43],BL
    //         0056aa56     PUSH       ESI
    //         0056aa57     ADD        byte ptr [ESI + 0x54005643],DH
    //         0056aa5d     INC        EDX
    //         0056aa5e     PUSH       ESI
    //         0056aa5f     ADD        byte ptr [DAT_d8005643],AL
    //         0056aa65     INC        EBX
    //         0056aa66     PUSH       ESI
    //         0056aa67     ADD        byte ptr [EAX + 0x42],CH
    //         0056aa6a     PUSH       ESI
    //         0056aa6b     ADD        byte ptr [ECX + 0x7b005642],DH
    //         0056aa71     INC        EBX
    //         0056aa72     PUSH       ESI
    //         0056aa73     ADD        byte ptr [ECX + 0xca005642],AL
    //         0056aa79     INC        EDX
    //         0056aa7a     PUSH       ESI
    //         0056aa7b     ADD        byte ptr [ESI],BL
    //         0056aa7d     INC        EBX
    //         0056aa7e     PUSH       ESI
    //         0056aa7f     ADD        byte ptr [EDX + EAX*0x2 + 0x56],AL
    //         0056aa83     ADD        DH,AH
    //         0056aa85     INC        EDX
    //         0056aa86     PUSH       ESI
    //         0056aa87     ADD        byte ptr [EDX],BH
    //         0056aa89     INC        EBX
    //         0056aa8a     PUSH       ESI
    //         0056aa8b     ADD        byte ptr [EDI + 0x9d005643],DL
    //         0056aa91     INC        EDX
    //         0056aa92     PUSH       ESI
    //         0056aa93     ADD        byte ptr [ECX + 0x43],BL
    //         0056aa96     PUSH       ESI
    //         0056aa97     ADD        byte ptr [ESI + 0x54005643],DH
    //         0056aa9d     INC        EDX
    //         0056aa9e     PUSH       ESI
    //         0056aa9f     ADD        byte ptr [DAT_d8005643],AL
    //         0056aaa5     INC        EBX
    //         0056aaa6     PUSH       ESI
    //         0056aaa7     ADD        byte ptr [EAX + 0x42],CH
    //         0056aaaa     PUSH       ESI
    //         0056aaab     ADD        byte ptr [ECX + 0x7b005642],DH
    //         0056aab1     INC        EBX
    //         0056aab2     PUSH       ESI
    //         0056aab3     ADD        byte ptr [ECX + 0xca005642],AL
    //         0056aab9     INC        EDX
    //         0056aaba     PUSH       ESI
    //         0056aabb     ADD        byte ptr [ESI],BL
    //         0056aabd     INC        EBX
    //         0056aabe     PUSH       ESI
    //         0056aabf     ADD        byte ptr [EDX + EAX*0x2 + 0x56],AL
    //         0056aac3     ADD        DH,AH
    //         0056aac5     INC        EDX
    //         0056aac6     PUSH       ESI
    //         0056aac7     ADD        byte ptr [EDX],BH
    //         0056aac9     INC        EBX
    //         0056aaca     PUSH       ESI
    //         0056aacb     ADD        byte ptr [EDI + 0x9d005643],DL
    //         0056aad1     INC        EDX
    //         0056aad2     PUSH       ESI
    //         0056aad3     ADD        byte ptr [ECX + 0x43],BL
    //         0056aad6     PUSH       ESI
    //         0056aad7     ADD        byte ptr [ESI + 0x54005643],DH
    //         0056aadd     INC        EDX
    //         0056aade     PUSH       ESI
    //         0056aadf     ADD        byte ptr [DAT_d8005643],AL
    //         0056aae5     INC        EBX
    //         0056aae6     PUSH       ESI
    //         0056aae7     ADD        byte ptr [EAX + 0x42],CH
    //         0056aaea     PUSH       ESI
    //         0056aaeb     ADD        byte ptr [ECX + 0x7b005642],DH
    //         0056aaf1     INC        EBX
    //         0056aaf2     PUSH       ESI
    //         0056aaf3     ADD        byte ptr [ECX + 0xca005642],AL
    //         0056aaf9     INC        EDX
    //         0056aafa     PUSH       ESI
    //         0056aafb     ADD        byte ptr [ESI],BL
    //         0056aafd     INC        EBX
    //         0056aafe     PUSH       ESI
    //                               LAB_0056aaff+1                                               XREF[0,2]:   FUN_0056cd45:0056cdc5(*), 
    //                                                                                                         FUN_0056d159:0056d17f(*)  
    //         0056aaff     ADD        byte ptr [EAX],AL
    //         0056ab01     XOR        byte ptr [ESI],DL
    //         0056ab04     ADD        byte ptr [EAX],DH
    //         0056ab06     PUSH       ESI
    //         0056ab07     ADD        byte ptr [EAX],AL
    //         0056ab09     XOR        byte ptr [ESI],DL
    //         0056ab0c     ADD        byte ptr [EAX],DH
    //         0056ab0e     PUSH       ESI
    //         0056ab0f     ADD        CH,BH
    //         0056ab11     INC        EBX
    //         0056ab12     PUSH       ESI
    //         0056ab13     ADD        CH,BH
    //         0056ab15     INC        EBX
    //         0056ab16     PUSH       ESI
    //         0056ab17     ADD        CH,BH
    //         0056ab19     INC        EBX
    //         0056ab1a     PUSH       ESI
    //         0056ab1b     ADD        CH,BH
    //         0056ab1d     INC        EBX
    //         0056ab1e     PUSH       ESI
    //         0056ab1f     ADD        byte ptr [EBX],CL
    //         0056ab21     INC        ESP
    //         0056ab22     PUSH       ESI
    //         0056ab23     ADD        byte ptr [EBX],CL
    //         0056ab25     INC        ESP
    //         0056ab26     PUSH       ESI
    //         0056ab27     ADD        byte ptr [EBX],CL
    //         0056ab29     INC        ESP
    //         0056ab2a     PUSH       ESI
    //         0056ab2b     ADD        byte ptr [ESI],BL
    //         0056ab2d     INC        ESP
    //         0056ab2e     PUSH       ESI
    //         0056ab2f     ADD        byte ptr [EBX],DH
    //         0056ab31     INC        ESP
    //         0056ab32     PUSH       ESI
    //         0056ab33     ADD        byte ptr [EBX],DH
    //         0056ab35     INC        ESP
    //         0056ab36     PUSH       ESI
    //         0056ab37     ADD        byte ptr [EBX],DH
    //         0056ab39     INC        ESP
    //         0056ab3a     PUSH       ESI
    //         0056ab3b     ADD        byte ptr [ESP + EAX*0x2 + 0x56],CL
    //         0056ab3f     ADD        byte ptr [EBP + 0x44],AH
    //         0056ab42     PUSH       ESI
    //         0056ab43     ADD        byte ptr [EDI + 0x44],DH
    //         0056ab46     PUSH       ESI
    //         0056ab47     ADD        byte ptr [EDI + 0x44],DH
    //         0056ab4a     PUSH       ESI
    //         0056ab4b     ADD        byte ptr [EDI + 0x44],DH
    //         0056ab4e     PUSH       ESI
    //         0056ab4f     ADD        byte ptr [EBP + 0xaf005644],DL
    //         0056ab55     INC        ESP
    //         0056ab56     PUSH       ESI
    //         0056ab57     ADD        byte ptr [EDI + 0xd1005644],CH
    //         0056ab5d     INC        ESP
    //         0056ab5e     PUSH       ESI
    //         0056ab5f     ADD        BL,CH
    //         0056ab61     INC        ESP
    //         0056ab62     PUSH       ESI
    //         0056ab63     ADD        byte ptr [ESI],AL
    //         0056ab65     INC        EBP
    //         0056ab66     PUSH       ESI
    //         0056ab67     ADD        byte ptr [EBX],CH
    //         0056ab69     INC        EBP
    //         0056ab6a     PUSH       ESI
    //         0056ab6b     ADD        byte ptr [ESI + 0x45],AL
    //         0056ab6e     PUSH       ESI
    //         0056ab6f     ADD        byte ptr [ESI + 0x45],AH
    //         0056ab72     PUSH       ESI
    //         0056ab73     ADD        byte ptr [EDI + 0xa8005645],AL
    //         0056ab79     INC        EBP
    //         0056ab7a     PUSH       ESI
    //         0056ab7b     ADD        BL,CL
    //         0056ab7d     INC        EBP
    //         0056ab7e     PUSH       ESI
    //         0056ab7f     ADD        DH,CH
    //         0056ab81     INC        EBP
    //         0056ab82     PUSH       ESI
    //         0056ab83     ADD        AH,DH
    //         0056ab85     INC        ESI
    //         0056ab86     PUSH       ESI
    //         0056ab87     ADD        byte ptr [ECX + 0x1f005647],AL
    //         0056ab8d     DEC        EAX
    //         0056ab8e     PUSH       ESI
    //         0056ab8f     ADD        byte ptr [EDX + 0x46],BH
    //         0056ab92     PUSH       ESI
    //         0056ab93     ADD        byte ptr [EDI + 0x54005647],DH
    //         0056ab99     DEC        EAX
    //         0056ab9a     PUSH       ESI
    //         0056ab9b     ADD        byte ptr [DAT_29005646],AL
    //         0056aba1     INC        EDI
    //         0056aba2     PUSH       ESI
    //         0056aba3     ADD        byte ptr [EDI + 0x25005648],CL
    //         0056aba9     INC        ESI
    //         0056abaa     PUSH       ESI
    //         0056abab     ADD        byte ptr [EDX + 0xf2005646],BL
    //         0056abb1     INC        EDI
    //         0056abb2     PUSH       ESI
    //         0056abb3     ADD        byte ptr [EBP + 0x46],CL
    //         0056abb6     PUSH       ESI
    //         0056abb7     ADD        AH,AL
    //         0056abb9     INC        ESI
    //         0056abba     PUSH       ESI
    //         0056abbb     ADD        byte ptr [ECX + 0x47],DL
    //         0056abbe     PUSH       ESI
    //         0056abbf     ADD        DH,CH
    //         0056abc1     INC        EBP
    //         0056abc2     PUSH       ESI
    //         0056abc3     ADD        AH,DH
    //         0056abc5     INC        ESI
    //         0056abc6     PUSH       ESI
    //         0056abc7     ADD        byte ptr [ECX + 0x1f005647],AL
    //         0056abcd     DEC        EAX
    //         0056abce     PUSH       ESI
    //         0056abcf     ADD        byte ptr [EDX + 0x46],BH
    //         0056abd2     PUSH       ESI
    //         0056abd3     ADD        byte ptr [EDI + 0x54005647],DH
    //         0056abd9     DEC        EAX
    //         0056abda     PUSH       ESI
    //         0056abdb     ADD        byte ptr [DAT_29005646],AL
    //         0056abe1     INC        EDI
    //         0056abe2     PUSH       ESI
    //         0056abe3     ADD        byte ptr [EDI + 0x25005648],CL
    //         0056abe9     INC        ESI
    //         0056abea     PUSH       ESI
    //         0056abeb     ADD        byte ptr [EDX + 0xf2005646],BL
    //         0056abf1     INC        EDI
    //         0056abf2     PUSH       ESI
    //         0056abf3     ADD        byte ptr [EBP + 0x46],CL
    //         0056abf6     PUSH       ESI
    //         0056abf7     ADD        AH,AL
    //         0056abf9     INC        ESI
    //         0056abfa     PUSH       ESI
    //         0056abfb     ADD        byte ptr [ECX + 0x47],DL
    //         0056abfe     PUSH       ESI
    //         0056abff     ADD        DH,CH
    //         0056ac01     INC        EBP
    //         0056ac02     PUSH       ESI
    //         0056ac03     ADD        AH,DH
    //         0056ac05     INC        ESI
    //         0056ac06     PUSH       ESI
    //         0056ac07     ADD        byte ptr [ECX + 0x1f005647],AL
    //         0056ac0d     DEC        EAX
    //         0056ac0e     PUSH       ESI
    //         0056ac0f     ADD        byte ptr [EDX + 0x46],BH
    //         0056ac12     PUSH       ESI
    //         0056ac13     ADD        byte ptr [EDI + 0x54005647],DH
    //         0056ac19     DEC        EAX
    //         0056ac1a     PUSH       ESI
    //         0056ac1b     ADD        byte ptr [DAT_29005646],AL
    //         0056ac21     INC        EDI
    //         0056ac22     PUSH       ESI
    //         0056ac23     ADD        byte ptr [EDI + 0x25005648],CL
    //         0056ac29     INC        ESI
    //         0056ac2a     PUSH       ESI
    //         0056ac2b     ADD        byte ptr [EDX + 0xf2005646],BL
    //         0056ac31     INC        EDI
    //         0056ac32     PUSH       ESI
    //         0056ac33     ADD        byte ptr [EBP + 0x46],CL
    //         0056ac36     PUSH       ESI
    //         0056ac37     ADD        AH,AL
    //         0056ac39     INC        ESI
    //         0056ac3a     PUSH       ESI
    //         0056ac3b     ADD        byte ptr [ECX + 0x47],DL
    //         0056ac3e     PUSH       ESI
    //         0056ac3f     ADD        DH,CH
    //         0056ac41     INC        EBP
    //         0056ac42     PUSH       ESI
    //         0056ac43     ADD        AH,DH
    //         0056ac45     INC        ESI
    //         0056ac46     PUSH       ESI
    //         0056ac47     ADD        byte ptr [ECX + 0x1f005647],AL
    //         0056ac4d     DEC        EAX
    //         0056ac4e     PUSH       ESI
    //         0056ac4f     ADD        byte ptr [EDX + 0x46],BH
    //         0056ac52     PUSH       ESI
    //         0056ac53     ADD        byte ptr [EDI + 0x54005647],DH
    //         0056ac59     DEC        EAX
    //         0056ac5a     PUSH       ESI
    //         0056ac5b     ADD        byte ptr [DAT_29005646],AL
    //         0056ac61     INC        EDI
    //         0056ac62     PUSH       ESI
    //         0056ac63     ADD        byte ptr [EDI + 0x25005648],CL
    //         0056ac69     INC        ESI
    //         0056ac6a     PUSH       ESI
    //         0056ac6b     ADD        byte ptr [EDX + 0xf2005646],BL
    //         0056ac71     INC        EDI
    //         0056ac72     PUSH       ESI
    //         0056ac73     ADD        byte ptr [EBP + 0x46],CL
    //         0056ac76     PUSH       ESI
    //         0056ac77     ADD        AH,AL
    //         0056ac79     INC        ESI
    //         0056ac7a     PUSH       ESI
    //         0056ac7b     ADD        byte ptr [ECX + 0x47],DL
    //         0056ac7e     PUSH       ESI
    //         0056ac7f     ADD        DH,CH
    //         0056ac81     INC        EBP
    //         0056ac82     PUSH       ESI
    //         0056ac83     ADD        AH,DH
    //         0056ac85     INC        ESI
    //         0056ac86     PUSH       ESI
    //         0056ac87     ADD        byte ptr [ECX + 0x1f005647],AL
    //         0056ac8d     DEC        EAX
    //         0056ac8e     PUSH       ESI
    //         0056ac8f     ADD        byte ptr [EDX + 0x46],BH
    //         0056ac92     PUSH       ESI
    //         0056ac93     ADD        byte ptr [EDI + 0x54005647],DH
    //         0056ac99     DEC        EAX
    //         0056ac9a     PUSH       ESI
    //         0056ac9b     ADD        byte ptr [DAT_29005646],AL
    //         0056aca1     INC        EDI
    //         0056aca2     PUSH       ESI
    //         0056aca3     ADD        byte ptr [EDI + 0x25005648],CL
    //         0056aca9     INC        ESI
    //         0056acaa     PUSH       ESI
    //         0056acab     ADD        byte ptr [EDX + 0xf2005646],BL
    //         0056acb1     INC        EDI
    //         0056acb2     PUSH       ESI
    //         0056acb3     ADD        byte ptr [EBP + 0x46],CL
    //         0056acb6     PUSH       ESI
    //         0056acb7     ADD        AH,AL
    //         0056acb9     INC        ESI
    //         0056acba     PUSH       ESI
    //         0056acbb     ADD        byte ptr [ECX + 0x47],DL
    //         0056acbe     PUSH       ESI
    //         0056acbf     ADD        DH,CH
    //         0056acc1     INC        EBP
    //         0056acc2     PUSH       ESI
    //         0056acc3     ADD        AH,DH
    //         0056acc5     INC        ESI
    //         0056acc6     PUSH       ESI
    //         0056acc7     ADD        byte ptr [ECX + 0x1f005647],AL
    //         0056accd     DEC        EAX
    //         0056acce     PUSH       ESI
    //         0056accf     ADD        byte ptr [EDX + 0x46],BH
    //         0056acd2     PUSH       ESI
    //         0056acd3     ADD        byte ptr [EDI + 0x54005647],DH
    //         0056acd9     DEC        EAX
    //         0056acda     PUSH       ESI
    //         0056acdb     ADD        byte ptr [DAT_29005646],AL
    //         0056ace1     INC        EDI
    //         0056ace2     PUSH       ESI
    //         0056ace3     ADD        byte ptr [EDI + 0x25005648],CL
    //         0056ace9     INC        ESI
    //         0056acea     PUSH       ESI
    //         0056aceb     ADD        byte ptr [EDX + 0xf2005646],BL
    //         0056acf1     INC        EDI
    //         0056acf2     PUSH       ESI
    //         0056acf3     ADD        byte ptr [EBP + 0x46],CL
    //         0056acf6     PUSH       ESI
    //         0056acf7     ADD        AH,AL
    //         0056acf9     INC        ESI
    //         0056acfa     PUSH       ESI
    //         0056acfb     ADD        byte ptr [ECX + 0x47],DL
    //         0056acfe     PUSH       ESI
    //         0056acff     ADD        byte ptr [EAX],AL
    //         0056ad01     XOR        byte ptr [ESI],DL
    //         0056ad04     ADD        byte ptr [EAX],DH
    //         0056ad06     PUSH       ESI
    //         0056ad07     ADD        byte ptr [EAX],AL
    //         0056ad09     XOR        byte ptr [ESI],DL
    //         0056ad0c     ADD        byte ptr [EAX],DH
    //         0056ad0e     PUSH       ESI
    //         0056ad0f     ADD        BH,CL
    //         0056ad11     DEC        EAX
    //         0056ad12     PUSH       ESI
    //         0056ad13     ADD        BH,AH
    //         0056ad15     DEC        EAX
    //         0056ad16     PUSH       ESI
    //         0056ad17     ADD        BH,CL
    //         0056ad19     DEC        EAX
    //         0056ad1a     PUSH       ESI
    //         0056ad1b     ADD        BH,AH
    //         0056ad1d     DEC        EAX
    //         0056ad1e     PUSH       ESI
    //         0056ad1f     ADD        BH,BH
    //         0056ad21     DEC        EAX
    //         0056ad22     PUSH       ESI
    //         0056ad23     ADD        byte ptr [ECX + ECX*0x2],BL
    //         0056ad26     PUSH       ESI
    //         0056ad27     ADD        BH,BH
    //         0056ad29     DEC        EAX
    //         0056ad2a     PUSH       ESI
    //         0056ad2b     ADD        byte ptr [ECX + ECX*0x2],BL
    //         0056ad2e     PUSH       ESI
    //         0056ad2f     ADD        byte ptr [DAT_60005649],BH
    //         0056ad35     DEC        ECX
    //         0056ad36     PUSH       ESI
    //         0056ad37     ADD        byte ptr [ECX + ECX*0x2 + 0x49b30056],AL
    //         0056ad3e     PUSH       ESI
    //         0056ad3f     ADD        DL,AH
    //         0056ad41     DEC        ECX
    //         0056ad42     PUSH       ESI
    //         0056ad43     ADD        DH,BH
    //         0056ad45     DEC        ECX
    //         0056ad46     PUSH       ESI
    //         0056ad47     ADD        byte ptr [EDX + ECX*0x2],DH
    //         0056ad4a     PUSH       ESI
    //         0056ad4b     ADD        byte ptr [EAX + 0x4a],CH
    //         0056ad4e     PUSH       ESI
    //         0056ad4f     ADD        byte ptr [EBP + 0xcb00564a],BL
    //         0056ad55     DEC        EDX
    //         0056ad56     PUSH       ESI
    //         0056ad57     ADD        byte ptr [ESI],AL
    //         0056ad59     DEC        EBX
    //         0056ad5a     PUSH       ESI
    //         0056ad5b     ADD        byte ptr [EAX + 0x4b],AL
    //         0056ad5e     PUSH       ESI
    //         0056ad5f     ADD        byte ptr [ESI + 0x4b],CH
    //         0056ad62     PUSH       ESI
    //         0056ad63     ADD        byte ptr [ECX + 0xe200564b],AH
    //         0056ad69     DEC        EBX
    //         0056ad6a     PUSH       ESI
    //         0056ad6b     ADD        byte ptr [DAT_5500564c],DL
    //         0056ad71     DEC        ESP
    //         0056ad72     PUSH       ESI
    //         0056ad73     ADD        byte ptr [ESI + 0xc800564c],CL
    //         0056ad79     DEC        ESP
    //         0056ad7a     PUSH       ESI
    //         0056ad7b     ADD        byte ptr [DAT_5200564d],CL
    //         0056ad81     DEC        EBP
    //         0056ad82     PUSH       ESI
    //         0056ad83     ADD        CH,CH
    //         0056ad85     DEC        ESI
    //         0056ad86     PUSH       ESI
    //         0056ad87     ADD        CL,CL
    //         0056ad89     DEC        EDI
    //         0056ad8a     PUSH       ESI
    //         0056ad8b     ADD        byte ptr [EBP + 0x24005650],DH
    //         0056ad91     DEC        ESI
    //         0056ad92     PUSH       ESI
    //         0056ad93     ADD        byte ptr [EBX],BL
    //         0056ad95     PUSH       EAX
    //         0056ad96     PUSH       ESI
    //         0056ad97     ADD        byte ptr [EAX],CL=>DAT_fffffffa
    //         0056ad99     PUSH       ECX
    //         0056ad9a     PUSH       ESI
    //         0056ad9b     ADD        byte ptr [EBX + 0x4d],DH
    //         0056ad9e     PUSH       ESI
    //         0056ad9f     ADD        byte ptr [ECX + 0x4f],AL
    //         0056ada2     PUSH       ESI
    //         0056ada3     ADD        byte ptr [EAX + 0x51],AH
    //         0056ada6     PUSH       ESI
    //         0056ada7     ADD        byte ptr [EDI + 0x5800564d],AH
    //         0056adad     DEC        ESI
    //         0056adae     PUSH       ESI
    //         0056adaf     ADD        byte ptr [EAX + EDX*0x2 + 0x56],DH
    //         0056adb3     ADD        DL,AH
    //         0056adb5     DEC        EBP
    //         0056adb6     PUSH       ESI
    //         0056adb7     ADD        byte ptr [EAX + 0x7c00564e],AH
    //         0056adbd     DEC        EDI
    //         0056adbe     PUSH       ESI
    //         0056adbf     ADD        byte ptr [EDX + 0x4d],DL
    //         0056adc2     PUSH       ESI
    //         0056adc3     ADD        CH,CH
    //         0056adc5     DEC        ESI
    //         0056adc6     PUSH       ESI
    //         0056adc7     ADD        CL,CL
    //         0056adc9     DEC        EDI
    //         0056adca     PUSH       ESI
    //         0056adcb     ADD        byte ptr [EBP + 0x24005650],DH
    //         0056add1     DEC        ESI
    //         0056add2     PUSH       ESI
    //         0056add3     ADD        byte ptr [EBX],BL
    //         0056add5     PUSH       EAX
    //         0056add6     PUSH       ESI
    //         0056add7     ADD        byte ptr [EAX],CL=>DAT_fffffffa
    //         0056add9     PUSH       ECX
    //         0056adda     PUSH       ESI
    //         0056addb     ADD        byte ptr [EBX + 0x4d],DH
    //         0056adde     PUSH       ESI
    //         0056addf     ADD        byte ptr [ECX + 0x4f],AL
    //         0056ade2     PUSH       ESI
    //         0056ade3     ADD        byte ptr [EAX + 0x51],AH
    //         0056ade6     PUSH       ESI
    //         0056ade7     ADD        byte ptr [EDI + 0x5800564d],AH
    //         0056aded     DEC        ESI
    //         0056adee     PUSH       ESI
    //         0056adef     ADD        byte ptr [EAX + EDX*0x2 + 0x56],DH
    //         0056adf3     ADD        DL,AH
    //         0056adf5     DEC        EBP
    //         0056adf6     PUSH       ESI
    //         0056adf7     ADD        byte ptr [EAX + 0x7c00564e],AH
    //         0056adfd     DEC        EDI
    //         0056adfe     PUSH       ESI
    //         0056adff     ADD        byte ptr [EDX + 0x4d],DL
    //         0056ae02     PUSH       ESI
    //         0056ae03     ADD        CH,CH
    //         0056ae05     DEC        ESI
    //         0056ae06     PUSH       ESI
    //         0056ae07     ADD        CL,CL
    //         0056ae09     DEC        EDI
    //         0056ae0a     PUSH       ESI
    //         0056ae0b     ADD        byte ptr [EBP + 0x24005650],DH
    //         0056ae11     DEC        ESI
    //         0056ae12     PUSH       ESI
    //         0056ae13     ADD        byte ptr [EBX],BL
    //         0056ae15     PUSH       EAX
    //         0056ae16     PUSH       ESI
    //         0056ae17     ADD        byte ptr [EAX],CL=>DAT_fffffffa
    //         0056ae19     PUSH       ECX
    //         0056ae1a     PUSH       ESI
    //         0056ae1b     ADD        byte ptr [EBX + 0x4d],DH
    //         0056ae1e     PUSH       ESI
    //         0056ae1f     ADD        byte ptr [ECX + 0x4f],AL
    //         0056ae22     PUSH       ESI
    //         0056ae23     ADD        byte ptr [EAX + 0x51],AH
    //         0056ae26     PUSH       ESI
    //         0056ae27     ADD        byte ptr [EDI + 0x5800564d],AH
    //         0056ae2d     DEC        ESI
    //         0056ae2e     PUSH       ESI
    //         0056ae2f     ADD        byte ptr [EAX + EDX*0x2 + 0x56],DH
    //         0056ae33     ADD        DL,AH
    //         0056ae35     DEC        EBP
    //         0056ae36     PUSH       ESI
    //         0056ae37     ADD        byte ptr [EAX + 0x7c00564e],AH
    //         0056ae3d     DEC        EDI
    //         0056ae3e     PUSH       ESI
    //         0056ae3f     ADD        byte ptr [EDX + 0x4d],DL
    //         0056ae42     PUSH       ESI
    //         0056ae43     ADD        CH,CH
    //         0056ae45     DEC        ESI
    //         0056ae46     PUSH       ESI
    //         0056ae47     ADD        CL,CL
    //         0056ae49     DEC        EDI
    //         0056ae4a     PUSH       ESI
    //         0056ae4b     ADD        byte ptr [EBP + 0x24005650],DH
    //         0056ae51     DEC        ESI
    //         0056ae52     PUSH       ESI
    //         0056ae53     ADD        byte ptr [EBX],BL
    //         0056ae55     PUSH       EAX
    //         0056ae56     PUSH       ESI
    //         0056ae57     ADD        byte ptr [EAX],CL=>DAT_fffffffa
    //         0056ae59     PUSH       ECX
    //         0056ae5a     PUSH       ESI
    //         0056ae5b     ADD        byte ptr [EBX + 0x4d],DH
    //         0056ae5e     PUSH       ESI
    //         0056ae5f     ADD        byte ptr [ECX + 0x4f],AL
    //         0056ae62     PUSH       ESI
    //         0056ae63     ADD        byte ptr [EAX + 0x51],AH
    //         0056ae66     PUSH       ESI
    //         0056ae67     ADD        byte ptr [EDI + 0x5800564d],AH
    //         0056ae6d     DEC        ESI
    //         0056ae6e     PUSH       ESI
    //         0056ae6f     ADD        byte ptr [EAX + EDX*0x2 + 0x56],DH
    //         0056ae73     ADD        DL,AH
    //         0056ae75     DEC        EBP
    //         0056ae76     PUSH       ESI
    //         0056ae77     ADD        byte ptr [EAX + 0x7c00564e],AH
    //         0056ae7d     DEC        EDI
    //         0056ae7e     PUSH       ESI
    //         0056ae7f     ADD        byte ptr [EDX + 0x4d],DL
    //         0056ae82     PUSH       ESI
    //         0056ae83     ADD        CH,CH
    //         0056ae85     DEC        ESI
    //         0056ae86     PUSH       ESI
    //         0056ae87     ADD        CL,CL
    //         0056ae89     DEC        EDI
    //         0056ae8a     PUSH       ESI
    //         0056ae8b     ADD        byte ptr [EBP + 0x24005650],DH
    //         0056ae91     DEC        ESI
    //         0056ae92     PUSH       ESI
    //         0056ae93     ADD        byte ptr [EBX],BL
    //         0056ae95     PUSH       EAX
    //         0056ae96     PUSH       ESI
    //         0056ae97     ADD        byte ptr [EAX],CL=>DAT_fffffffa
    //         0056ae99     PUSH       ECX
    //         0056ae9a     PUSH       ESI
    //         0056ae9b     ADD        byte ptr [EBX + 0x4d],DH
    //         0056ae9e     PUSH       ESI
    //         0056ae9f     ADD        byte ptr [ECX + 0x4f],AL
    //         0056aea2     PUSH       ESI
    //         0056aea3     ADD        byte ptr [EAX + 0x51],AH
    //         0056aea6     PUSH       ESI
    //         0056aea7     ADD        byte ptr [EDI + 0x5800564d],AH
    //         0056aead     DEC        ESI
    //         0056aeae     PUSH       ESI
    //         0056aeaf     ADD        byte ptr [EAX + EDX*0x2 + 0x56],DH
    //         0056aeb3     ADD        DL,AH
    //         0056aeb5     DEC        EBP
    //         0056aeb6     PUSH       ESI
    //         0056aeb7     ADD        byte ptr [EAX + 0x7c00564e],AH
    //         0056aebd     DEC        EDI
    //         0056aebe     PUSH       ESI
    //         0056aebf     ADD        byte ptr [EDX + 0x4d],DL
    //         0056aec2     PUSH       ESI
    //         0056aec3     ADD        CH,CH
    //         0056aec5     DEC        ESI
    //         0056aec6     PUSH       ESI
    //         0056aec7     ADD        CL,CL
    //         0056aec9     DEC        EDI
    //         0056aeca     PUSH       ESI
    //         0056aecb     ADD        byte ptr [EBP + 0x24005650],DH
    //         0056aed1     DEC        ESI
    //         0056aed2     PUSH       ESI
    //         0056aed3     ADD        byte ptr [EBX],BL
    //         0056aed5     PUSH       EAX
    //         0056aed6     PUSH       ESI
    //         0056aed7     ADD        byte ptr [EAX],CL=>DAT_fffffffa
    //         0056aed9     PUSH       ECX
    //         0056aeda     PUSH       ESI
    //         0056aedb     ADD        byte ptr [EBX + 0x4d],DH
    //         0056aede     PUSH       ESI
    //         0056aedf     ADD        byte ptr [ECX + 0x4f],AL
    //         0056aee2     PUSH       ESI
    //         0056aee3     ADD        byte ptr [EAX + 0x51],AH
    //         0056aee6     PUSH       ESI
    //         0056aee7     ADD        byte ptr [EDI + 0x5800564d],AH
    //         0056aeed     DEC        ESI
    //         0056aeee     PUSH       ESI
    //         0056aeef     ADD        byte ptr [EAX + EDX*0x2 + 0x56],DH
    //         0056aef3     ADD        DL,AH
    //         0056aef5     DEC        EBP
    //         0056aef6     PUSH       ESI
    //         0056aef7     ADD        byte ptr [EAX + 0x7c00564e],AH
    //         0056aefd     DEC        EDI
    //         0056aefe     PUSH       ESI
    //                               LAB_0056aeff+1                                               XREF[0,2]:   FUN_0056cf39:0056cfa5(*), 
    //                                                                                                         FUN_0056d218:0056d241(*)  
    //         0056aeff     ADD        byte ptr [EAX],AL=>DAT_fffffffa
    //         0056af01     XOR        byte ptr [ESI],DL
    //         0056af04     ADD        byte ptr [EAX],DH=>DAT_fffffffa
    //         0056af06     PUSH       ESI
    //         0056af07     ADD        byte ptr [EAX],AL=>DAT_fffffffa
    //         0056af09     XOR        byte ptr [ESI],DL
    //         0056af0c     ADD        byte ptr [EAX],DH=>DAT_fffffffa
    //         0056af0e     PUSH       ESI
    //         0056af0f     ADD        byte ptr [EDI + 0xbf005651],BH
    //         0056af15     PUSH       ECX
    //         0056af16     PUSH       ESI
    //         0056af17     ADD        byte ptr [EDI + 0xbf005651],BH
    //         0056af1d     PUSH       ECX
    //         0056af1e     PUSH       ESI
    //         0056af1f     ADD        CH,CL
    //         0056af21     PUSH       ECX
    //         0056af22     PUSH       ESI
    //         0056af23     ADD        CH,CL
    //         0056af25     PUSH       ECX
    //         0056af26     PUSH       ESI
    //         0056af27     ADD        CH,CL
    //         0056af29     PUSH       ECX
    //         0056af2a     PUSH       ESI
    //         0056af2b     ADD        DH,AH
    //         0056af2d     PUSH       ECX
    //         0056af2e     PUSH       ESI
    //         0056af2f     ADD        AH,BH
    //         0056af31     PUSH       ECX
    //         0056af32     PUSH       ESI
    //         0056af33     ADD        byte ptr [EDX + EDX*0x2],BL
    //         0056af36     PUSH       ESI
    //         0056af37     ADD        byte ptr [ESI],BH
    //         0056af39     PUSH       EDX
    //         0056af3a     PUSH       ESI
    //         0056af3b     ADD        byte ptr [EDI + 0x52],BL
    //         0056af3e     PUSH       ESI
    //         0056af3f     ADD        byte ptr [EAX + 0xa5005652],AL
    //         0056af45     PUSH       EDX
    //         0056af46     PUSH       ESI
    //         0056af47     ADD        BH,CL
    //         0056af49     PUSH       EDX
    //         0056af4a     PUSH       ESI
    //         0056af4b     ADD        BL,BH
    //         0056af4d     PUSH       EDX
    //         0056af4e     PUSH       ESI
    //         0056af4f     ADD        byte ptr [EBX],AH
    //         0056af51     PUSH       EBX
    //         0056af52     PUSH       ESI
    //         0056af53     ADD        byte ptr [EAX + 0x53],DL
    //         0056af56     PUSH       ESI
    //         0056af57     ADD        byte ptr [EBP + 0xb8005653],AL
    //         0056af5d     PUSH       EBX
    //         0056af5e     PUSH       ESI
    //         0056af5f     ADD        CH,AH
    //         0056af61     PUSH       EBX
    //         0056af62     PUSH       ESI
    //         0056af63     ADD        byte ptr [DAT_59005654],BL
    //         0056af69     PUSH       ESP=>local_66c
    //         0056af6a     PUSH       ESI
    //         0056af6b     ADD        byte ptr [ECX + 0xc6005654],DL
    //         0056af71     PUSH       ESP=>local_674
    //         0056af72     PUSH       ESI
    //         0056af73     ADD        byte ptr [DAT_46005655],AL
    //         0056af79     PUSH       EBP
    //         0056af7a     PUSH       ESI
    //         0056af7b     ADD        byte ptr [ESI + 0xc6005655],AL
    //         0056af81     PUSH       EBP
    //         0056af82     PUSH       ESI
    //         0056af83     ADD        byte ptr [EDI + EDX*0x2 + 0x56],AH
    //         0056af87     ADD        byte ptr [DAT_33005658],BH
    //         0056af8d     POP        ECX
    //         0056af8e     PUSH       ESI
    //         0056af8f     ADD        byte ptr [ESI + EDX*0x2 + 0x58900056],CH
    //         0056af96     PUSH       ESI
    //         0056af97     ADD        byte ptr [EDX + 0xf0005659],AL
    //         0056af9d     PUSH       EBP
    //         0056af9e     PUSH       ESI
    //         0056af9f     ADD        byte ptr [EBP + 0xdc005657],DH
    //         0056afa5     POP        ECX
    //         0056afa6     PUSH       ESI
    //         0056afa7     ADD        byte ptr [EBX],AH
    //         0056afa9     PUSH       ESI
    //         0056afaa     PUSH       ESI
    //         0056afab     ADD        BH,BL
    //         0056afad     PUSH       ESI
    //         0056afae     PUSH       ESI
    //         0056afaf     ADD        AH,CH
    //         0056afb1     POP        EAX
    //         0056afb2     PUSH       ESI
    //         0056afb3     ADD        byte ptr [EBX + 0x56],AH
    //         0056afb6     PUSH       ESI
    //         0056afb7     ADD        byte ptr [EDI + EDX*0x2],BL
    //         0056afba     PUSH       ESI
    //         0056afbb     ADD        CH,DH
    //         0056afbd     PUSH       EDI
    //         0056afbe     PUSH       ESI
    //         0056afbf     ADD        DH,AL
    //         0056afc1     PUSH       EBP
    //         0056afc2     PUSH       ESI
    //         0056afc3     ADD        byte ptr [EDI + EDX*0x2 + 0x56],AH
    //         0056afc7     ADD        byte ptr [DAT_33005658],BH
    //         0056afcd     POP        ECX
    //         0056afce     PUSH       ESI
    //         0056afcf     ADD        byte ptr [ESI + EDX*0x2 + 0x58900056],CH
    //         0056afd6     PUSH       ESI
    //         0056afd7     ADD        byte ptr [EDX + 0xf0005659],AL
    //         0056afdd     PUSH       EBP
    //         0056afde     PUSH       ESI
    //         0056afdf     ADD        byte ptr [EBP + 0xdc005657],DH
    //         0056afe5     POP        ECX
    //         0056afe6     PUSH       ESI
    //         0056afe7     ADD        byte ptr [EBX],AH
    //         0056afe9     PUSH       ESI
    //         0056afea     PUSH       ESI
    //         0056afeb     ADD        BH,BL
    //         0056afed     PUSH       ESI
    //         0056afee     PUSH       ESI
    //         0056afef     ADD        AH,CH
    //         0056aff1     POP        EAX
    //         0056aff2     PUSH       ESI
    //         0056aff3     ADD        byte ptr [EBX + 0x56],AH
    //         0056aff6     PUSH       ESI
    //         0056aff7     ADD        byte ptr [EDI + EDX*0x2],BL
    //         0056affa     PUSH       ESI
    //         0056affb     ADD        CH,DH
    //         0056affd     PUSH       EDI
    //         0056affe     PUSH       ESI
    //         0056afff     ADD        DH,AL
    //         0056b001     PUSH       EBP
    //         0056b002     PUSH       ESI
    //         0056b003     ADD        byte ptr [EDI + EDX*0x2 + 0x56],AH
    //         0056b007     ADD        byte ptr [DAT_33005658],BH
    //         0056b00d     POP        ECX
    //         0056b00e     PUSH       ESI
    //         0056b00f     ADD        byte ptr [ESI + EDX*0x2 + 0x58900056],CH
    //         0056b016     PUSH       ESI
    //         0056b017     ADD        byte ptr [EDX + 0xf0005659],AL
    //         0056b01d     PUSH       EBP
    //         0056b01e     PUSH       ESI
    //         0056b01f     ADD        byte ptr [EBP + 0xdc005657],DH
    //         0056b025     POP        ECX
    //         0056b026     PUSH       ESI
    //         0056b027     ADD        byte ptr [EBX],AH
    //         0056b029     PUSH       ESI
    //         0056b02a     PUSH       ESI
    //         0056b02b     ADD        BH,BL
    //         0056b02d     PUSH       ESI
    //         0056b02e     PUSH       ESI
    //         0056b02f     ADD        AH,CH
    //         0056b031     POP        EAX
    //         0056b032     PUSH       ESI
    //         0056b033     ADD        byte ptr [EBX + 0x56],AH
    //         0056b036     PUSH       ESI
    //         0056b037     ADD        byte ptr [EDI + EDX*0x2],BL
    //         0056b03a     PUSH       ESI
    //         0056b03b     ADD        CH,DH
    //         0056b03d     PUSH       EDI
    //         0056b03e     PUSH       ESI
    //         0056b03f     ADD        DH,AL
    //         0056b041     PUSH       EBP
    //         0056b042     PUSH       ESI
    //         0056b043     ADD        byte ptr [EDI + EDX*0x2 + 0x56],AH
    //         0056b047     ADD        byte ptr [DAT_33005658],BH
    //         0056b04d     POP        ECX
    //         0056b04e     PUSH       ESI
    //         0056b04f     ADD        byte ptr [ESI + EDX*0x2 + 0x58900056],CH
    //         0056b056     PUSH       ESI
    //         0056b057     ADD        byte ptr [EDX + 0xf0005659],AL
    //         0056b05d     PUSH       EBP
    //         0056b05e     PUSH       ESI
    //         0056b05f     ADD        byte ptr [EBP + 0xdc005657],DH
    //         0056b065     POP        ECX
    //         0056b066     PUSH       ESI
    //         0056b067     ADD        byte ptr [EBX],AH
    //         0056b069     PUSH       ESI
    //         0056b06a     PUSH       ESI
    //         0056b06b     ADD        BH,BL
    //         0056b06d     PUSH       ESI
    //         0056b06e     PUSH       ESI
    //         0056b06f     ADD        AH,CH
    //         0056b071     POP        EAX
    //         0056b072     PUSH       ESI
    //         0056b073     ADD        byte ptr [EBX + 0x56],AH
    //         0056b076     PUSH       ESI
    //         0056b077     ADD        byte ptr [EDI + EDX*0x2],BL
    //         0056b07a     PUSH       ESI
    //         0056b07b     ADD        CH,DH
    //         0056b07d     PUSH       EDI
    //         0056b07e     PUSH       ESI
    //         0056b07f     ADD        DH,AL
    //         0056b081     PUSH       EBP
    //         0056b082     PUSH       ESI
    //         0056b083     ADD        byte ptr [EDI + EDX*0x2 + 0x56],AH
    //         0056b087     ADD        byte ptr [DAT_33005658],BH
    //         0056b08d     POP        ECX
    //         0056b08e     PUSH       ESI
    //         0056b08f     ADD        byte ptr [ESI + EDX*0x2 + 0x58900056],CH
    //         0056b096     PUSH       ESI
    //         0056b097     ADD        byte ptr [EDX + 0xf0005659],AL
    //         0056b09d     PUSH       EBP
    //         0056b09e     PUSH       ESI
    //         0056b09f     ADD        byte ptr [EBP + 0xdc005657],DH
    //         0056b0a5     POP        ECX
    //         0056b0a6     PUSH       ESI
    //         0056b0a7     ADD        byte ptr [EBX],AH
    //         0056b0a9     PUSH       ESI
    //         0056b0aa     PUSH       ESI
    //         0056b0ab     ADD        BH,BL
    //         0056b0ad     PUSH       ESI
    //         0056b0ae     PUSH       ESI
    //         0056b0af     ADD        AH,CH
    //         0056b0b1     POP        EAX
    //         0056b0b2     PUSH       ESI
    //         0056b0b3     ADD        byte ptr [EBX + 0x56],AH
    //         0056b0b6     PUSH       ESI
    //         0056b0b7     ADD        byte ptr [EDI + EDX*0x2],BL
    //         0056b0ba     PUSH       ESI
    //         0056b0bb     ADD        CH,DH
    //         0056b0bd     PUSH       EDI
    //         0056b0be     PUSH       ESI
    //         0056b0bf     ADD        DH,AL
    //         0056b0c1     PUSH       EBP
    //         0056b0c2     PUSH       ESI
    //         0056b0c3     ADD        byte ptr [EDI + EDX*0x2 + 0x56],AH
    //         0056b0c7     ADD        byte ptr [DAT_33005658],BH
    //         0056b0cd     POP        ECX
    //         0056b0ce     PUSH       ESI
    //         0056b0cf     ADD        byte ptr [ESI + EDX*0x2 + 0x58900056],CH
    //         0056b0d6     PUSH       ESI
    //         0056b0d7     ADD        byte ptr [EDX + 0xf0005659],AL
    //         0056b0dd     PUSH       EBP
    //         0056b0de     PUSH       ESI
    //         0056b0df     ADD        byte ptr [EBP + 0xdc005657],DH
    //         0056b0e5     POP        ECX
    //         0056b0e6     PUSH       ESI
    //         0056b0e7     ADD        byte ptr [EBX],AH
    //         0056b0e9     PUSH       ESI
    //         0056b0ea     PUSH       ESI
    //         0056b0eb     ADD        BH,BL
    //         0056b0ed     PUSH       ESI
    //         0056b0ee     PUSH       ESI
    //         0056b0ef     ADD        AH,CH
    //         0056b0f1     POP        EAX
    //         0056b0f2     PUSH       ESI
    //         0056b0f3     ADD        byte ptr [EBX + 0x56],AH
    //         0056b0f6     PUSH       ESI
    //         0056b0f7     ADD        byte ptr [EDI + EDX*0x2],BL
    //         0056b0fa     PUSH       ESI
    //         0056b0fb     ADD        CH,DH
    //         0056b0fd     PUSH       EDI
    //         0056b0fe     PUSH       ESI
    //         0056b0ff     ADD        byte ptr [EAX],AL
    //         0056b101     XOR        byte ptr [ESI],DL
    //         0056b104     ADD        byte ptr [EAX],DH
    //         0056b106     PUSH       ESI
    //         0056b107     ADD        byte ptr [EAX],AL
    //         0056b109     XOR        byte ptr [ESI],DL
    //         0056b10c     ADD        byte ptr [EAX],DH
    //         0056b10e     PUSH       ESI
    //         0056b10f     ADD        byte ptr [EDI],BH
    //         0056b111     POP        EDX
    //         0056b112     PUSH       ESI
    //         0056b113     ADD        byte ptr [ECX + 0x5a],BL
    //         0056b116     PUSH       ESI
    //         0056b117     ADD        byte ptr [EDI],BH
    //         0056b119     POP        EDX
    //         0056b11a     PUSH       ESI
    //         0056b11b     ADD        byte ptr [ECX + 0x5a],BL
    //         0056b11e     PUSH       ESI
    //         0056b11f     ADD        byte ptr [EBX + 0x5a],DH
    //         0056b122     PUSH       ESI
    //         0056b123     ADD        byte ptr [EAX + 0x7300565a],BL
    //         0056b129     POP        EDX
    //         0056b12a     PUSH       ESI
    //         0056b12b     ADD        byte ptr [EAX + 0xc300565a],BL
    //         0056b131     POP        EDX
    //         0056b132     PUSH       ESI
    //         0056b133     ADD        BH,DH
    //         0056b135     POP        EDX
    //         0056b136     PUSH       ESI
    //         0056b137     ADD        byte ptr [ECX],CH
    //         0056b139     POP        EBX
    //         0056b13a     PUSH       ESI
    //         0056b13b     ADD        byte ptr [EDX + 0x5b],AH
    //         0056b13e     PUSH       ESI
    //         0056b13f     ADD        byte ptr [EBX + 0xcc00565b],BL
    //         0056b145     POP        EBX
    //         0056b146     PUSH       ESI
    //         0056b147     ADD        byte ptr [EDX],DL
    //         0056b149     POP        ESP=>local_7d0
    //         0056b14a     PUSH       ESI
    //         0056b14b     ADD        byte ptr [ESI + 0x5c],DL
    //         0056b14e     PUSH       ESI=>DAT_fffffff8
    //         0056b14f     ADD        byte ptr [ESI + 0xe300565c],BL
    //         0056b155     POP        ESP=>DAT_fffffff8
    //         0056b156     PUSH       ESI
    //         0056b157     ADD        byte ptr [EBX*0x2 + 0x5d870056],DH
    //         0056b15e     PUSH       ESI=>DAT_fffffff8
    //         0056b15f     ADD        AH,CL
    //         0056b161     POP        EBP=>DAT_fffffff8
    //         0056b162     PUSH       ESI=>DAT_fffffff8
    //         0056b163     ADD        byte ptr [ESI + EBX*0x2],BL
    //         0056b166     PUSH       ESI=>DAT_fffffff4
    //         0056b167     ADD        byte ptr [ESI + EBX*0x2 + 0x56],BH
    //         0056b16b     ADD        AH,CL
    //         0056b16d     POP        ESI=>DAT_fffffff4
    //         0056b16e     PUSH       ESI=>DAT_fffffff4
    //         0056b16f     ADD        byte ptr [DAT_8400565f],AH
    //         0056b175     POP        EDI=>DAT_fffffff4
    //         0056b176     PUSH       ESI=>DAT_fffffff4
    //         0056b177     ADD        CL,AH
    //         0056b179     POP        EDI=>DAT_fffffff4
    //         0056b17a     PUSH       ESI=>DAT_fffffff4
    //         0056b17b     ADD        byte ptr [EBP + 0x60],AL
    //         0056b17e     PUSH       ESI=>DAT_fffffff0
    //         0056b17f     ADD        byte ptr [ECX + 0xff005660],CH
    //         0056b185     BOUND      EDX,dword ptr [ESI]
    //         0056b188     CMP        AL,0x64
    //         0056b18a     PUSH       ESI
    //         0056b18b     ADD        byte ptr [ESI + 0xe7005665],BL
    //         0056b191     POPAD
    //         0056b192     PUSH       ESI
    //         0056b193     ADD        byte ptr [EBX + 0x19005664],DH
    //         0056b199     PUSH       SI
    //         0056b19b     ADD        BH,BL
    //         0056b19d     PUSHAD
    //         0056b19e     PUSH       ESI
    //         0056b19f     ADD        byte ptr [EAX + 0x63],BH
    //         0056b1a2     PUSH       ESI
    //         0056b1a3     ADD        byte ptr [EDI + 0x2a005666],BL
    //         0056b1a9     POPAD
    //         0056b1aa     PUSH       ESI=>DAT_fffffffa
    //         0056b1ab     ADD        byte ptr [EDX],DH
    //         0056b1ad     BOUND      EDX,dword ptr [ESI]
    //         0056b1b0     AAA
    //         0056b1b1     PUSH       ESI=>DAT_fffffff6
    //         0056b1b3     ADD        byte ptr [EDX + 0x93005661],AL
    //         0056b1b9     BOUND      EDX,dword ptr [ESI]
    //         0056b1bc     SHL        byte ptr [EBX + 0x56],0x1
    //         0056b1bf     ADD        byte ptr [ECX + 0xff005660],CH
    //         0056b1c5     BOUND      EDX,dword ptr [ESI]
    //         0056b1c8     CMP        AL,0x64
    //         0056b1ca     PUSH       ESI=>DAT_fffffff2
    //         0056b1cb     ADD        byte ptr [ESI + 0xe7005665],BL
    //         0056b1d1     POPAD
    //         0056b1d2     PUSH       ESI
    //         0056b1d3     ADD        byte ptr [EBX + 0x19005664],DH
    //         0056b1d9     PUSH       SI
    //         0056b1db     ADD        BH,BL
    //         0056b1dd     PUSHAD
    //         0056b1de     PUSH       ESI
    //         0056b1df     ADD        byte ptr [EAX + 0x63],BH
    //         0056b1e2     PUSH       ESI
    //         0056b1e3     ADD        byte ptr [EDI + 0x2a005666],BL
    //         0056b1e9     POPAD
    //         0056b1ea     PUSH       ESI
    //         0056b1eb     ADD        byte ptr [EDX],DH
    //         0056b1ed     BOUND      EDX,dword ptr [ESI]
    //         0056b1f0     AAA
    //         0056b1f1     PUSH       ESI
    //         0056b1f3     ADD        byte ptr [EDX + 0x93005661],AL
    //         0056b1f9     BOUND      EDX,dword ptr [ESI]
    //         0056b1fc     SHL        byte ptr [EBX + 0x56],0x1
    //         0056b1ff     ADD        byte ptr [ECX + 0xff005660],CH
    //         0056b205     BOUND      EDX,dword ptr [ESI]
    //         0056b208     CMP        AL,0x64
    //         0056b20a     PUSH       ESI=>DAT_fffffff8
    //         0056b20b     ADD        byte ptr [ESI + 0xe7005665],BL
    //         0056b211     POPAD
    //         0056b212     PUSH       ESI
    //         0056b213     ADD        byte ptr [EBX + 0x19005664],DH
    //         0056b219     PUSH       SI
    //         0056b21b     ADD        BH,BL
    //         0056b21d     PUSHAD
    //         0056b21e     PUSH       ESI
    //         0056b21f     ADD        byte ptr [EAX + 0x63],BH
    //         0056b222     PUSH       ESI
    //         0056b223     ADD        byte ptr [EDI + 0x2a005666],BL
    //         0056b229     POPAD
    //         0056b22a     PUSH       ESI
    //         0056b22b     ADD        byte ptr [EDX],DH
    //         0056b22d     BOUND      EDX,dword ptr [ESI]
    //         0056b230     AAA
    //         0056b231     PUSH       ESI
    //         0056b233     ADD        byte ptr [EDX + 0x93005661],AL
    //         0056b239     BOUND      EDX,dword ptr [ESI]
    //         0056b23c     SHL        byte ptr [EBX + 0x56],0x1
    //         0056b23f     ADD        byte ptr [ECX + 0xff005660],CH
    //         0056b245     BOUND      EDX,dword ptr [ESI]
    //         0056b248     CMP        AL,0x64
    //         0056b24a     PUSH       ESI
    //         0056b24b     ADD        byte ptr [ESI + 0xe7005665],BL
    //         0056b251     POPAD
    //         0056b252     PUSH       ESI
    //         0056b253     ADD        byte ptr [EBX + 0x19005664],DH
    //         0056b259     PUSH       SI
    //         0056b25b     ADD        BH,BL
    //         0056b25d     PUSHAD
    //         0056b25e     PUSH       ESI=>DAT_fffffff4
    //         0056b25f     ADD        byte ptr [EAX + 0x63],BH
    //         0056b262     PUSH       ESI=>DAT_fffffff0
    //         0056b263     ADD        byte ptr [EDI + 0x2a005666],BL
    //         0056b269     POPAD
    //         0056b26a     PUSH       ESI
    //         0056b26b     ADD        byte ptr [EDX],DH
    //         0056b26d     BOUND      EDX,dword ptr [ESI]
    //         0056b270     AAA
    //         0056b271     PUSH       ESI
    //         0056b273     ADD        byte ptr [EDX + 0x93005661],AL
    //         0056b279     BOUND      EDX,dword ptr [ESI]
    //         0056b27c     SHL        byte ptr [EBX + 0x56],0x1
    //         0056b27f     ADD        byte ptr [ECX + 0xff005660],CH
    //         0056b285     BOUND      EDX,dword ptr [ESI]
    //         0056b288     CMP        AL,0x64
    //         0056b28a     PUSH       ESI
    //         0056b28b     ADD        byte ptr [ESI + 0xe7005665],BL
    //         0056b291     POPAD
    //         0056b292     PUSH       ESI
    //         0056b293     ADD        byte ptr [EBX + 0x19005664],DH
    //         0056b299     PUSH       SI
    //         0056b29b     ADD        BH,BL
    //         0056b29d     PUSHAD
    //         0056b29e     PUSH       ESI=>DAT_fffffffa
    //         0056b29f     ADD        byte ptr [EAX + 0x63],BH
    //         0056b2a2     PUSH       ESI=>DAT_fffffff6
    //         0056b2a3     ADD        byte ptr [EDI + 0x2a005666],BL
    //         0056b2a9     POPAD
    //         0056b2aa     PUSH       ESI
    //         0056b2ab     ADD        byte ptr [EDX],DH
    //         0056b2ad     BOUND      EDX,dword ptr [ESI]
    //         0056b2b0     AAA
    //         0056b2b1     PUSH       ESI
    //         0056b2b3     ADD        byte ptr [EDX + 0x93005661],AL
    //         0056b2b9     BOUND      EDX,dword ptr [ESI]
    //         0056b2bc     SHL        byte ptr [EBX + 0x56],0x1
    //         0056b2bf     ADD        byte ptr [ECX + 0xff005660],CH
    //         0056b2c5     BOUND      EDX,dword ptr [ESI]
    //         0056b2c8     CMP        AL,0x64
    //         0056b2ca     PUSH       ESI
    //         0056b2cb     ADD        byte ptr [ESI + 0xe7005665],BL
    //         0056b2d1     POPAD
    //         0056b2d2     PUSH       ESI
    //         0056b2d3     ADD        byte ptr [EBX + 0x19005664],DH
    //         0056b2d9     PUSH       SI
    //         0056b2db     ADD        BH,BL
    //         0056b2dd     PUSHAD
    //         0056b2de     PUSH       ESI
    //         0056b2df     ADD        byte ptr [EAX + 0x63],BH
    //         0056b2e2     PUSH       ESI
    //         0056b2e3     ADD        byte ptr [EDI + 0x2a005666],BL
    //         0056b2e9     POPAD
    //         0056b2ea     PUSH       ESI
    //         0056b2eb     ADD        byte ptr [EDX],DH
    //         0056b2ed     BOUND      EDX,dword ptr [ESI]
    //         0056b2f0     AAA
    //         0056b2f1     PUSH       ESI
    //         0056b2f3     ADD        byte ptr [EDX + 0x93005661],AL
    //         0056b2f9     BOUND      EDX,dword ptr [ESI]
    //         0056b2fc     SHL        byte ptr [EBX + 0x56],0x1
    //                               LAB_0056b2ff+1                                               XREF[0,20+]  FUN_0056cc6c:0056cce5(*), 
    //                                                                                                         FUN_0056cd45:0056cdb3(*), 
    //                                                                                                         FUN_0056cde6:0056ce5a(*), 
    //                                                                                                         FUN_0056ce99:0056cefa(*), 
    //                                                                                                         FUN_0056cf39:0056cf93(*), 
    //                                                                                                         FUN_0056d0cc:0056d0e8(*), 
    //                                                                                                         FUN_0056d0fb:0056d119(*), 
    //                                                                                                         FUN_0056d159:0056d16d(*), 
    //                                                                                                         FUN_0056d186:0056d1b4(*), 
    //                                                                                                         FUN_0056d1d8:0056d1f4(*), 
    //                                                                                                         FUN_0056d218:0056d22d(*), 
    //                                                                                                         FUN_0056d44c:0056d468(*), 
    //                                                                                                         FUN_0056d47b:0056d499(*), 
    //                                                                                                         FUN_0056d4d9:0056d4ed(*), 
    //                                                                                                         FUN_0056d506:0056d534(*), 
    //                                                                                                         FUN_0056d558:0056d574(*), 
    //                                                                                                         FUN_0056d598:0056d5ad(*), 
    //                                                                                                         FUN_0056d887:0056d8fa(*), 
    //                                                                                                         FUN_0056d93a:0056d99a(*), 
    //                                                                                                         FUN_0056d9da:0056da31(*)  
    //         0056b2ff     ADD        byte ptr [EAX],AL
    //         0056b301     ADD        AL,0x8
    //         0056b303     OR         AL,0x10
    //         0056b305     ADC        AL,0x18
    //         0056b307     SBB        AL,0x20
    //         0056b309     AND        AL,0x28
    //         0056b30b     SUB        AL,0x30
    //         0056b30d     XOR        AL,0x38
    //         0056b30f     CMP        AL,0x40
    //         0056b311     INC        ESP
    //         0056b312     DEC        EAX
    //         0056b313     DEC        ESP
    //         0056b314     PUSH       EAX
    //         0056b315     PUSH       ESP
    //         0056b316     POP        EAX
    //         0056b317     POP        ESP
    //         0056b318     PUSHAD
    //         0056b319     PUSH       0x7874706c
    //         0056b31f     JL         LAB_0056b361
    //         0056b321     INC        ESP
    //         0056b322     DEC        EAX
    //         0056b323     DEC        ESP
    //         0056b324     PUSH       EAX
    //         0056b325     PUSH       ESP
    //         0056b326     POP        EAX
    //         0056b327     POP        ESP
    //         0056b328     PUSHAD
    //         0056b329     PUSH       0x7874706c
    //         0056b32f     JL         LAB_0056b371
    //         0056b331     INC        ESP
    //         0056b332     DEC        EAX
    //         0056b333     DEC        ESP
    //         0056b334     PUSH       EAX
    //         0056b335     PUSH       ESP
    //         0056b336     POP        EAX
    //         0056b337     POP        ESP
    //         0056b338     PUSHAD
    //         0056b339     PUSH       0x7874706c
    //         0056b33f     JL         LAB_0056b381
    //         0056b341     INC        ESP
    //         0056b342     DEC        EAX
    //         0056b343     DEC        ESP
    //         0056b344     PUSH       EAX
    //         0056b345     PUSH       ESP
    //         0056b346     POP        EAX
    //         0056b347     POP        ESP
    //         0056b348     PUSHAD
    //         0056b349     PUSH       0x7874706c
    //         0056b34f     JL         LAB_0056b391
    //         0056b351     INC        ESP
    //         0056b352     DEC        EAX
    //         0056b353     DEC        ESP
    //         0056b354     PUSH       EAX
    //         0056b355     PUSH       ESP
    //         0056b356     POP        EAX
    //         0056b357     POP        ESP
    //         0056b358     PUSHAD
    //         0056b359     PUSH       0x7874706c
    //         0056b35f     JL         LAB_0056b3a1
    //                               LAB_0056b361                                                 XREF[1]:     0056b31f(j)  
    //         0056b361     INC        ESP
    //         0056b362     DEC        EAX
    //         0056b363     DEC        ESP
    //         0056b364     PUSH       EAX
    //         0056b365     PUSH       ESP
    //         0056b366     POP        EAX
    //         0056b367     POP        ESP
    //         0056b368     PUSHAD
    //         0056b369     PUSH       0x7874706c
    //         0056b36f     JL         LAB_0056b3b1
    //                               LAB_0056b371                                                 XREF[1]:     0056b32f(j)  
    //         0056b371     INC        ESP
    //         0056b372     DEC        EAX
    //         0056b373     DEC        ESP
    //         0056b374     PUSH       EAX
    //         0056b375     PUSH       ESP
    //         0056b376     POP        EAX
    //         0056b377     POP        ESP
    //         0056b378     PUSHAD
    //         0056b379     PUSH       0x7874706c
    //         0056b37f     JL         LAB_0056b3c1
    //                               LAB_0056b381                                                 XREF[1]:     0056b33f(j)  
    //         0056b381     INC        ESP
    //         0056b382     DEC        EAX
    //         0056b383     DEC        ESP
    //         0056b384     PUSH       EAX
    //         0056b385     PUSH       ESP
    //         0056b386     POP        EAX
    //         0056b387     POP        ESP
    //         0056b388     PUSHAD
    //         0056b389     PUSH       0x7874706c
    //         0056b38f     JL         LAB_0056b3d1
    //                               LAB_0056b391                                                 XREF[1]:     0056b34f(j)  
    //         0056b391     INC        ESP
    //         0056b392     DEC        EAX
    //         0056b393     DEC        ESP
    //         0056b394     PUSH       EAX
    //         0056b395     PUSH       ESP
    //         0056b396     POP        EAX
    //         0056b397     POP        ESP
    //         0056b398     PUSHAD
    //         0056b399     PUSH       0x7874706c
    //         0056b39f     JL         LAB_0056b3e1
    //                               LAB_0056b3a1                                                 XREF[1]:     0056b35f(j)  
    //         0056b3a1     INC        ESP
    //         0056b3a2     DEC        EAX
    //         0056b3a3     DEC        ESP
    //         0056b3a4     PUSH       EAX
    //         0056b3a5     PUSH       ESP
    //         0056b3a6     POP        EAX
    //         0056b3a7     POP        ESP
    //         0056b3a8     PUSHAD
    //         0056b3a9     PUSH       0x7874706c
    //         0056b3af     JL         LAB_0056b3f1
    //                               LAB_0056b3b1                                                 XREF[1]:     0056b36f(j)  
    //         0056b3b1     INC        ESP
    //         0056b3b2     DEC        EAX
    //         0056b3b3     DEC        ESP
    //         0056b3b4     PUSH       EAX
    //         0056b3b5     PUSH       ESP
    //         0056b3b6     POP        EAX
    //         0056b3b7     POP        ESP
    //         0056b3b8     PUSHAD
    //         0056b3b9     PUSH       0x7874706c
    //         0056b3bf     JL         switchdataD_0056b400+1
    //                               LAB_0056b3c1                                                 XREF[1]:     0056b37f(j)  
    //         0056b3c1     INC        ESP
    //         0056b3c2     DEC        EAX
    //         0056b3c3     DEC        ESP
    //         0056b3c4     PUSH       EAX
    //         0056b3c5     PUSH       ESP
    //         0056b3c6     POP        EAX
    //         0056b3c7     POP        ESP
    //         0056b3c8     PUSHAD
    //         0056b3c9     PUSH       0x7874706c
    //         0056b3cf     JL         PTR_caseD_0_0056b410+1
    //                               LAB_0056b3d1                                                 XREF[1]:     0056b38f(j)  
    //         0056b3d1     INC        ESP
    //         0056b3d2     DEC        EAX
    //         0056b3d3     DEC        ESP
    //         0056b3d4     PUSH       EAX
    //         0056b3d5     PUSH       ESP
    //         0056b3d6     POP        EAX
    //         0056b3d7     POP        ESP
    //         0056b3d8     PUSHAD
    //         0056b3d9     PUSH       0x7874706c
    //         0056b3df     JL         PTR_caseD_0_0056b420+1
    //                               LAB_0056b3e1                                                 XREF[1]:     0056b39f(j)  
    //         0056b3e1     INC        ESP
    //         0056b3e2     DEC        EAX
    //         0056b3e3     DEC        ESP
    //         0056b3e4     PUSH       EAX
    //         0056b3e5     PUSH       ESP
    //         0056b3e6     POP        EAX
    //         0056b3e7     POP        ESP
    //         0056b3e8     PUSHAD
    //         0056b3e9     PUSH       0x7874706c
    //         0056b3ef     JL         PTR_caseD_0_0056b430+1
    //                               LAB_0056b3f1                                                 XREF[1]:     0056b3af(j)  
    //         0056b3f1     INC        ESP
    //         0056b3f2     DEC        EAX
    //         0056b3f3     DEC        ESP
    //         0056b3f4     PUSH       EAX
    //         0056b3f5     PUSH       ESP
    //         0056b3f6     POP        EAX
    //         0056b3f7     POP        ESP
    //         0056b3f8     PUSHAD
    //         0056b3f9     PUSH       0x7874706c
}

