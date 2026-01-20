// Auto-generated scaffold unit: bucket_0568.cpp.asm
#include "../include/common.h"

// Offset: 0x0056802D
undefined FUN_0056802d() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056802d()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056802d
    //         0056802d     MOV        AL,byte ptr [ESI]
    //         0056802f     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00568035     INC        ESI
    //         00568036     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         0056803c     MOV        byte ptr [EDI],AL
    //         0056803e     DEC        EDI
    //         0056803f     MOV        EAX,dword ptr [ESI]
    //         00568041     BSWAP      EAX
    //         00568043     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00568049     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         0056804f     ADD        ESI,0x4
    //         00568052     MOV        dword ptr [EDI + -0x3],EAX
    //         00568055     SUB        EDI,0x4
    //         00568058     MOV        EAX,dword ptr [ESI + -0x1]
    //         0056805b     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00568061     ADD        ESI,0x2
    //         00568064     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         0056806a     SHR        EAX,0x8
    //         0056806d     XCHG       AH,AL
    //         0056806f     MOV        word ptr [EDI + -0x1],AX=>DAT_fffffffa
    //         00568073     SUB        EDI,0x2
    //         00568076     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x0056807C
undefined FUN_0056807c() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056807c()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056807c                                                 XREF[1]:     00568098(j)  
    //         0056807c     MOV        EAX,dword ptr [ESI]
    //         0056807e     BSWAP      EAX
    //         00568080     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00568086     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         0056808c     ADD        ESI,0x4
    //         0056808f     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff9
    //         00568092     SUB        EDI,0x4
    //         00568095     SUB        ECX,0x4
    //         00568098     JA         FUN_0056807c
    //         0056809a     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005680A0
undefined FUN_005680a0() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005680a0()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005680a0
    //         005680a0     MOV        AL,byte ptr [ESI]
    //         005680a2     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005680a8     INC        ESI
    //         005680a9     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         005680af     MOV        byte ptr [EDI],AL
    //         005680b1     DEC        EDI
    //         005680b2     DEC        ECX
    //                               LAB_005680b3                                                 XREF[1]:     005680cf(j)  
    //         005680b3     MOV        EAX,dword ptr [ESI]
    //         005680b5     BSWAP      EAX
    //         005680b7     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005680bd     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         005680c3     ADD        ESI,0x4
    //         005680c6     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff8
    //         005680c9     SUB        EDI,0x4
    //         005680cc     SUB        ECX,0x4
    //         005680cf     JA         LAB_005680b3
    //         005680d1     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005680D7
undefined FUN_005680d7() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005680d7()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005680d7
    //         005680d7     MOV        EAX,dword ptr [ESI + -0x1]
    //         005680da     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005680e0     ADD        ESI,0x2
    //         005680e3     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         005680e9     SHR        EAX,0x8
    //         005680ec     XCHG       AH,AL
    //         005680ee     MOV        word ptr [EDI + -0x1],AX
    //         005680f2     SUB        EDI,0x2
    //         005680f5     SUB        ECX,0x2
    //                               LAB_005680f8                                                 XREF[1]:     00568114(j)  
    //         005680f8     MOV        EAX,dword ptr [ESI]
    //         005680fa     BSWAP      EAX
    //         005680fc     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00568102     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         00568108     ADD        ESI,0x4
    //         0056810b     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffb
    //         0056810e     SUB        EDI,0x4
    //         00568111     SUB        ECX,0x4
    //         00568114     JA         LAB_005680f8
    //         00568116     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x0056811C
undefined FUN_0056811c() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056811c()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056811c
    //         0056811c     MOV        EAX,dword ptr [ESI]
    //         0056811e     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00568124     ADD        ESI,0x3
    //         00568127     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         0056812d     MOV        byte ptr [EDI],AL
    //         0056812f     MOV        byte ptr [EDI + -0x1],AH
    //         00568132     SHR        EAX,0x10
    //         00568135     MOV        byte ptr [EDI + -0x2],AL
    //         00568138     SUB        EDI,0x3
    //         0056813b     SUB        ECX,0x3
    //                               LAB_0056813e                                                 XREF[1]:     0056815a(j)  
    //         0056813e     MOV        EAX,dword ptr [ESI]
    //         00568140     BSWAP      EAX
    //         00568142     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00568148     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         0056814e     ADD        ESI,0x4
    //         00568151     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffa
    //         00568154     SUB        EDI,0x4
    //         00568157     SUB        ECX,0x4
    //         0056815a     JA         LAB_0056813e
    //         0056815c     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568162
undefined FUN_00568162() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568162()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568162
    //         00568162     DEC        ECX
    //                               LAB_00568163                                                 XREF[1]:     0056817f(j)  
    //         00568163     MOV        EAX,dword ptr [ESI]
    //         00568165     BSWAP      EAX
    //         00568167     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056816d     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         00568173     ADD        ESI,0x4
    //         00568176     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff9
    //         00568179     SUB        EDI,0x4
    //         0056817c     SUB        ECX,0x4
    //         0056817f     JA         LAB_00568163
    //         00568181     MOV        AH,byte ptr [ESI]
    //         00568183     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00568189     INC        ESI
    //         0056818a     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         00568190     MOV        byte ptr [EDI],AH=>DAT_fffffff8
    //         00568192     DEC        EDI
    //         00568193     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568199
undefined FUN_00568199() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568199()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568199
    //         00568199     MOV        AL,byte ptr [ESI]
    //         0056819b     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005681a1     INC        ESI
    //         005681a2     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         005681a8     MOV        byte ptr [EDI],AL
    //         005681aa     DEC        EDI
    //         005681ab     SUB        ECX,0x2
    //                               LAB_005681ae                                                 XREF[1]:     005681ca(j)  
    //         005681ae     MOV        EAX,dword ptr [ESI]
    //         005681b0     BSWAP      EAX
    //         005681b2     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005681b8     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         005681be     ADD        ESI,0x4
    //         005681c1     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff8
    //         005681c4     SUB        EDI,0x4
    //         005681c7     SUB        ECX,0x4
    //         005681ca     JA         LAB_005681ae
    //         005681cc     MOV        AH,byte ptr [ESI]
    //         005681ce     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005681d4     INC        ESI
    //         005681d5     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         005681db     MOV        byte ptr [EDI],AH=>DAT_fffffffb
    //         005681dd     DEC        EDI
    //         005681de     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005681E4
undefined FUN_005681e4() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005681e4()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005681e4
    //         005681e4     MOV        EAX,dword ptr [ESI + -0x1]
    //         005681e7     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005681ed     ADD        ESI,0x2
    //         005681f0     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         005681f6     SHR        EAX,0x8
    //         005681f9     XCHG       AH,AL
    //         005681fb     MOV        word ptr [EDI + -0x1],AX
    //         005681ff     SUB        EDI,0x2
    //         00568202     SUB        ECX,0x3
    //                               LAB_00568205                                                 XREF[1]:     00568221(j)  
    //         00568205     MOV        EAX,dword ptr [ESI]
    //         00568207     BSWAP      EAX
    //         00568209     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056820f     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         00568215     ADD        ESI,0x4
    //         00568218     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffb
    //         0056821b     SUB        EDI,0x4
    //         0056821e     SUB        ECX,0x4
    //         00568221     JA         LAB_00568205
    //         00568223     MOV        AH,byte ptr [ESI]
    //         00568225     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056822b     INC        ESI
    //         0056822c     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         00568232     MOV        byte ptr [EDI],AH=>DAT_fffffffa
    //         00568234     DEC        EDI
    //         00568235     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x0056823B
undefined FUN_0056823b() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056823b()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056823b
    //         0056823b     MOV        EAX,dword ptr [ESI]
    //         0056823d     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00568243     ADD        ESI,0x3
    //         00568246     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         0056824c     MOV        byte ptr [EDI],AL
    //         0056824e     MOV        byte ptr [EDI + -0x1],AH
    //         00568251     SHR        EAX,0x10
    //         00568254     MOV        byte ptr [EDI + -0x2],AL
    //         00568257     SUB        EDI,0x3
    //         0056825a     SUB        ECX,0x4
    //                               LAB_0056825d                                                 XREF[1]:     00568279(j)  
    //         0056825d     MOV        EAX,dword ptr [ESI]
    //         0056825f     BSWAP      EAX
    //         00568261     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00568267     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         0056826d     ADD        ESI,0x4
    //         00568270     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffa
    //         00568273     SUB        EDI,0x4
    //         00568276     SUB        ECX,0x4
    //         00568279     JA         LAB_0056825d
    //         0056827b     MOV        AH,byte ptr [ESI]
    //         0056827d     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00568283     INC        ESI
    //         00568284     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         0056828a     MOV        byte ptr [EDI],AH=>DAT_fffffff9
    //         0056828c     DEC        EDI
    //         0056828d     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568293
undefined FUN_00568293() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568293()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568293
    //         00568293     SUB        ECX,0x2
    //                               LAB_00568296                                                 XREF[1]:     005682b2(j)  
    //         00568296     MOV        EAX,dword ptr [ESI]
    //         00568298     BSWAP      EAX
    //         0056829a     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005682a0     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         005682a6     ADD        ESI,0x4
    //         005682a9     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff9
    //         005682ac     SUB        EDI,0x4
    //         005682af     SUB        ECX,0x4
    //         005682b2     JA         LAB_00568296
    //         005682b4     MOV        EAX,dword ptr [ESI + -0x1]
    //         005682b7     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005682bd     ADD        ESI,0x2
    //         005682c0     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         005682c6     SHR        EAX,0x8
    //         005682c9     XCHG       AH,AL
    //         005682cb     MOV        word ptr [EDI + -0x1],AX=>DAT_fffffffb
    //         005682cf     SUB        EDI,0x2
    //         005682d2     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005682D8
undefined FUN_005682d8() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005682d8()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005682d8
    //         005682d8     MOV        AL,byte ptr [ESI]
    //         005682da     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005682e0     INC        ESI
    //         005682e1     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         005682e7     MOV        byte ptr [EDI],AL
    //         005682e9     DEC        EDI
    //         005682ea     SUB        ECX,0x3
    //                               LAB_005682ed                                                 XREF[1]:     00568309(j)  
    //         005682ed     MOV        EAX,dword ptr [ESI]
    //         005682ef     BSWAP      EAX
    //         005682f1     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005682f7     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         005682fd     ADD        ESI,0x4
    //         00568300     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff8
    //         00568303     SUB        EDI,0x4
    //         00568306     SUB        ECX,0x4
    //         00568309     JA         LAB_005682ed
    //         0056830b     MOV        EAX,dword ptr [ESI + -0x1]
    //         0056830e     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00568314     ADD        ESI,0x2
    //         00568317     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         0056831d     SHR        EAX,0x8
    //         00568320     XCHG       AH,AL
    //         00568322     MOV        word ptr [EDI + -0x1],AX=>DAT_fffffffa
    //         00568326     SUB        EDI,0x2
    //         00568329     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x0056832F
undefined FUN_0056832f() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056832f()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056832f
    //         0056832f     MOV        EAX,dword ptr [ESI + -0x1]
    //         00568332     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00568338     ADD        ESI,0x2
    //         0056833b     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         00568341     SHR        EAX,0x8
    //         00568344     XCHG       AH,AL
    //         00568346     MOV        word ptr [EDI + -0x1],AX
    //         0056834a     SUB        EDI,0x2
    //         0056834d     SUB        ECX,0x4
    //                               LAB_00568350                                                 XREF[1]:     0056836c(j)  
    //         00568350     MOV        EAX,dword ptr [ESI]
    //         00568352     BSWAP      EAX
    //         00568354     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056835a     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         00568360     ADD        ESI,0x4
    //         00568363     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffb
    //         00568366     SUB        EDI,0x4
    //         00568369     SUB        ECX,0x4
    //         0056836c     JA         LAB_00568350
    //         0056836e     MOV        EAX,dword ptr [ESI + -0x1]
    //         00568371     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00568377     ADD        ESI,0x2
    //         0056837a     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         00568380     SHR        EAX,0x8
    //         00568383     XCHG       AH,AL
    //         00568385     MOV        word ptr [EDI + -0x1],AX=>DAT_fffffff9
    //         00568389     SUB        EDI,0x2
    //         0056838c     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568392
undefined FUN_00568392() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568392()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568392
    //         00568392     MOV        EAX,dword ptr [ESI]
    //         00568394     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056839a     ADD        ESI,0x3
    //         0056839d     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         005683a3     MOV        byte ptr [EDI],AL
    //         005683a5     MOV        byte ptr [EDI + -0x1],AH
    //         005683a8     SHR        EAX,0x10
    //         005683ab     MOV        byte ptr [EDI + -0x2],AL
    //         005683ae     SUB        EDI,0x3
    //         005683b1     SUB        ECX,0x5
    //                               LAB_005683b4                                                 XREF[1]:     005683d0(j)  
    //         005683b4     MOV        EAX,dword ptr [ESI]
    //         005683b6     BSWAP      EAX
    //         005683b8     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005683be     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         005683c4     ADD        ESI,0x4
    //         005683c7     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffa
    //         005683ca     SUB        EDI,0x4
    //         005683cd     SUB        ECX,0x4
    //         005683d0     JA         LAB_005683b4
    //         005683d2     MOV        EAX,dword ptr [ESI + -0x1]
    //         005683d5     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005683db     ADD        ESI,0x2
    //         005683de     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         005683e4     SHR        EAX,0x8
    //         005683e7     XCHG       AH,AL
    //         005683e9     MOV        word ptr [EDI + -0x1],AX=>DAT_fffffff8
    //         005683ed     SUB        EDI,0x2
    //         005683f0     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005683F6
undefined FUN_005683f6() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005683f6()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005683f6
    //         005683f6     SUB        ECX,0x3
    //                               LAB_005683f9                                                 XREF[1]:     00568415(j)  
    //         005683f9     MOV        EAX,dword ptr [ESI]
    //         005683fb     BSWAP      EAX
    //         005683fd     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00568403     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         00568409     ADD        ESI,0x4
    //         0056840c     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff9
    //         0056840f     SUB        EDI,0x4
    //         00568412     SUB        ECX,0x4
    //         00568415     JA         LAB_005683f9
    //         00568417     MOV        EAX,dword ptr [ESI + -0x1]
    //         0056841a     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00568420     ADD        ESI,0x3
    //         00568423     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         00568429     MOV        byte ptr [EDI],AH=>DAT_fffffff8
    //         0056842b     SHR        EAX,0x10
    //         0056842e     MOV        byte ptr [EDI + -0x1],AL=>DAT_fffffffb
    //         00568431     MOV        byte ptr [EDI + -0x2],AH=>DAT_fffffffa
    //         00568434     SUB        EDI,0x3
    //         00568437     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x0056843D
undefined FUN_0056843d() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056843d()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056843d
    //         0056843d     MOV        AL,byte ptr [ESI]
    //         0056843f     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00568445     INC        ESI
    //         00568446     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         0056844c     MOV        byte ptr [EDI],AL
    //         0056844e     DEC        EDI
    //         0056844f     SUB        ECX,0x4
    //                               LAB_00568452                                                 XREF[1]:     0056846e(j)  
    //         00568452     MOV        EAX,dword ptr [ESI]
    //         00568454     BSWAP      EAX
    //         00568456     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056845c     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         00568462     ADD        ESI,0x4
    //         00568465     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff8
    //         00568468     SUB        EDI,0x4
    //         0056846b     SUB        ECX,0x4
    //         0056846e     JA         LAB_00568452
    //         00568470     MOV        EAX,dword ptr [ESI + -0x1]
    //         00568473     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00568479     ADD        ESI,0x3
    //         0056847c     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         00568482     MOV        byte ptr [EDI],AH=>DAT_fffffffb
    //         00568484     SHR        EAX,0x10
    //         00568487     MOV        byte ptr [EDI + -0x1],AL=>DAT_fffffffa
    //         0056848a     MOV        byte ptr [EDI + -0x2],AH=>DAT_fffffff9
    //         0056848d     SUB        EDI,0x3
    //         00568490     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568496
undefined FUN_00568496() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568496()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568496
    //         00568496     MOV        EAX,dword ptr [ESI + -0x1]
    //         00568499     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056849f     ADD        ESI,0x2
    //         005684a2     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         005684a8     SHR        EAX,0x8
    //         005684ab     XCHG       AH,AL
    //         005684ad     MOV        word ptr [EDI + -0x1],AX
    //         005684b1     SUB        EDI,0x2
    //         005684b4     SUB        ECX,0x5
    //                               LAB_005684b7                                                 XREF[1]:     005684d3(j)  
    //         005684b7     MOV        EAX,dword ptr [ESI]
    //         005684b9     BSWAP      EAX
    //         005684bb     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005684c1     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         005684c7     ADD        ESI,0x4
    //         005684ca     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffb
    //         005684cd     SUB        EDI,0x4
    //         005684d0     SUB        ECX,0x4
    //         005684d3     JA         LAB_005684b7
    //         005684d5     MOV        EAX,dword ptr [ESI + -0x1]
    //         005684d8     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005684de     ADD        ESI,0x3
    //         005684e1     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         005684e7     MOV        byte ptr [EDI],AH=>DAT_fffffffa
    //         005684e9     SHR        EAX,0x10
    //         005684ec     MOV        byte ptr [EDI + -0x1],AL=>DAT_fffffff9
    //         005684ef     MOV        byte ptr [EDI + -0x2],AH=>DAT_fffffff8
    //         005684f2     SUB        EDI,0x3
    //         005684f5     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005684FB
undefined FUN_005684fb() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005684fb()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005684fb
    //         005684fb     MOV        EAX,dword ptr [ESI]
    //         005684fd     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00568503     ADD        ESI,0x3
    //         00568506     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         0056850c     MOV        byte ptr [EDI],AL
    //         0056850e     MOV        byte ptr [EDI + -0x1],AH
    //         00568511     SHR        EAX,0x10
    //         00568514     MOV        byte ptr [EDI + -0x2],AL
    //         00568517     SUB        EDI,0x3
    //         0056851a     SUB        ECX,0x6
    //                               LAB_0056851d                                                 XREF[1]:     00568539(j)  
    //         0056851d     MOV        EAX,dword ptr [ESI]
    //         0056851f     BSWAP      EAX
    //         00568521     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00568527     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         0056852d     ADD        ESI,0x4
    //         00568530     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffa
    //         00568533     SUB        EDI,0x4
    //         00568536     SUB        ECX,0x4
    //         00568539     JA         LAB_0056851d
    //         0056853b     MOV        EAX,dword ptr [ESI + -0x1]
    //         0056853e     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00568544     ADD        ESI,0x3
    //         00568547     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         0056854d     MOV        byte ptr [EDI],AH=>DAT_fffffff9
    //         0056854f     SHR        EAX,0x10
    //         00568552     MOV        byte ptr [EDI + -0x1],AL=>DAT_fffffff8
    //         00568555     MOV        byte ptr [EDI + -0x2],AH=>DAT_fffffff7
    //         00568558     SUB        EDI,0x3
    //         0056855b     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568561
undefined FUN_00568561() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568561()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568561
    //         00568561     MOV        byte ptr [EDI],AL
    //         00568563     DEC        EDI
    //         00568564     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x0056856A
undefined FUN_0056856a() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056856a()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056856a
    //         0056856a     MOV        word ptr [EDI + -0x1],AX
    //         0056856e     SUB        EDI,0x2
    //         00568571     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568577
undefined FUN_00568577() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568577()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568577
    //         00568577     MOV        byte ptr [EDI],AL
    //         00568579     DEC        EDI
    //         0056857a     MOV        byte ptr [EDI],AL
    //         0056857c     DEC        EDI
    //         0056857d     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568583
undefined FUN_00568583() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568583()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568583
    //         00568583     MOV        word ptr [EDI + -0x2],AX
    //         00568587     MOV        byte ptr [EDI],AL
    //         00568589     SUB        EDI,0x3
    //         0056858c     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568592
undefined FUN_00568592() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568592()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568592
    //         00568592     MOV        byte ptr [EDI],AL
    //         00568594     DEC        EDI
    //         00568595     MOV        word ptr [EDI + -0x1],AX
    //         00568599     SUB        EDI,0x2
    //         0056859c     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005685A2
undefined FUN_005685a2() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005685a2()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005685a2
    //         005685a2     MOV        dword ptr [EDI + -0x3],EAX
    //         005685a5     SUB        EDI,0x4
    //         005685a8     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005685AE
undefined FUN_005685ae() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005685ae()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005685ae
    //         005685ae     MOV        word ptr [EDI + -0x2],AX
    //         005685b2     MOV        byte ptr [EDI],AL
    //         005685b4     SUB        EDI,0x3
    //         005685b7     MOV        byte ptr [EDI],AL
    //         005685b9     DEC        EDI
    //         005685ba     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005685C0
undefined FUN_005685c0() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005685c0()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005685c0
    //         005685c0     MOV        word ptr [EDI + -0x1],AX
    //         005685c4     SUB        EDI,0x2
    //         005685c7     MOV        word ptr [EDI + -0x1],AX
    //         005685cb     SUB        EDI,0x2
    //         005685ce     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005685D4
undefined FUN_005685d4() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005685d4()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005685d4
    //         005685d4     MOV        byte ptr [EDI],AL
    //         005685d6     DEC        EDI
    //         005685d7     MOV        word ptr [EDI + -0x2],AX
    //         005685db     MOV        byte ptr [EDI],AL
    //         005685dd     SUB        EDI,0x3
    //         005685e0     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005685E6
undefined FUN_005685e6() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005685e6()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005685e6
    //         005685e6     MOV        dword ptr [EDI + -0x3],EAX
    //         005685e9     SUB        EDI,0x4
    //         005685ec     MOV        byte ptr [EDI],AL
    //         005685ee     DEC        EDI
    //         005685ef     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005685F5
undefined FUN_005685f5() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005685f5()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005685f5
    //         005685f5     MOV        word ptr [EDI + -0x2],AX
    //         005685f9     MOV        byte ptr [EDI],AL
    //         005685fb     SUB        EDI,0x3
    //         005685fe     MOV        word ptr [EDI + -0x1],AX
    //         00568602     SUB        EDI,0x2
    //         00568605     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x0056860B
undefined FUN_0056860b() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056860b()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056860b
    //         0056860b     MOV        word ptr [EDI + -0x1],AX
    //         0056860f     SUB        EDI,0x2
    //         00568612     MOV        word ptr [EDI + -0x2],AX
    //         00568616     MOV        byte ptr [EDI],AL
    //         00568618     SUB        EDI,0x3
    //         0056861b     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568621
undefined FUN_00568621() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568621()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568621
    //         00568621     MOV        byte ptr [EDI],AL
    //         00568623     DEC        EDI
    //         00568624     MOV        dword ptr [EDI + -0x3],EAX
    //         00568627     SUB        EDI,0x4
    //         0056862a     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568630
undefined FUN_00568630() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568630()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568630
    //         00568630     MOV        dword ptr [EDI + -0x3],EAX
    //         00568633     SUB        EDI,0x4
    //         00568636     MOV        word ptr [EDI + -0x1],AX=>DAT_fffffffb
    //         0056863a     SUB        EDI,0x2
    //         0056863d     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568643
undefined FUN_00568643() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568643()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568643
    //         00568643     MOV        word ptr [EDI + -0x2],AX
    //         00568647     MOV        byte ptr [EDI],AL
    //         00568649     SUB        EDI,0x3
    //         0056864c     MOV        word ptr [EDI + -0x2],AX=>DAT_fffffffb
    //         00568650     MOV        byte ptr [EDI],AL
    //         00568652     SUB        EDI,0x3
    //         00568655     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x0056865B
undefined FUN_0056865b() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056865b()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056865b
    //         0056865b     MOV        word ptr [EDI + -0x1],AX
    //         0056865f     SUB        EDI,0x2
    //         00568662     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffb
    //         00568665     SUB        EDI,0x4
    //         00568668     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x0056866E
undefined FUN_0056866e() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056866e()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056866e
    //         0056866e     MOV        byte ptr [EDI],AL
    //         00568670     DEC        EDI
    //         00568671     MOV        dword ptr [EDI + -0x3],EAX
    //         00568674     SUB        EDI,0x4
    //         00568677     MOV        byte ptr [EDI],AL=>DAT_fffffffb
    //         00568679     DEC        EDI
    //         0056867a     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568680
undefined FUN_00568680() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568680()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568680
    //         00568680     MOV        dword ptr [EDI + -0x3],EAX
    //         00568683     SUB        EDI,0x4
    //         00568686     MOV        word ptr [EDI + -0x2],AX=>DAT_fffffffa
    //         0056868a     MOV        byte ptr [EDI],AL
    //         0056868c     SUB        EDI,0x3
    //         0056868f     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568695
undefined FUN_00568695() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568695()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568695
    //         00568695     MOV        word ptr [EDI + -0x2],AX
    //         00568699     MOV        byte ptr [EDI],AL
    //         0056869b     SUB        EDI,0x3
    //         0056869e     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffa
    //         005686a1     SUB        EDI,0x4
    //         005686a4     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005686AA
undefined FUN_005686aa() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005686aa()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005686aa
    //         005686aa     MOV        word ptr [EDI + -0x1],AX
    //         005686ae     SUB        EDI,0x2
    //         005686b1     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffb
    //         005686b4     SUB        EDI,0x4
    //         005686b7     MOV        byte ptr [EDI],AL=>DAT_fffffffa
    //         005686b9     DEC        EDI
    //         005686ba     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005686C0
undefined FUN_005686c0() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005686c0()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005686c0
    //         005686c0     MOV        byte ptr [EDI],AL
    //         005686c2     DEC        EDI
    //         005686c3     MOV        dword ptr [EDI + -0x3],EAX
    //         005686c6     SUB        EDI,0x4
    //         005686c9     MOV        word ptr [EDI + -0x1],AX=>DAT_fffffffa
    //         005686cd     SUB        EDI,0x2
    //         005686d0     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005686D6
undefined FUN_005686d6() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005686d6()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005686d6                                                 XREF[1]:     005686df(j)  
    //         005686d6     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff9
    //         005686d9     SUB        EDI,0x4
    //         005686dc     SUB        ECX,0x4
    //         005686df     JA         FUN_005686d6
    //         005686e1     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005686E7
undefined FUN_005686e7() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005686e7()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005686e7
    //         005686e7     MOV        byte ptr [EDI],AL
    //         005686e9     DEC        EDI
    //         005686ea     DEC        ECX
    //                               LAB_005686eb                                                 XREF[1]:     005686f4(j)  
    //         005686eb     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff8
    //         005686ee     SUB        EDI,0x4
    //         005686f1     SUB        ECX,0x4
    //         005686f4     JA         LAB_005686eb
    //         005686f6     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005686FC
undefined FUN_005686fc() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005686fc()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005686fc
    //         005686fc     MOV        word ptr [EDI + -0x1],AX
    //         00568700     SUB        EDI,0x2
    //         00568703     SUB        ECX,0x2
    //                               LAB_00568706                                                 XREF[1]:     0056870f(j)  
    //         00568706     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffb
    //         00568709     SUB        EDI,0x4
    //         0056870c     SUB        ECX,0x4
    //         0056870f     JA         LAB_00568706
    //         00568711     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568717
undefined FUN_00568717() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568717()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568717
    //         00568717     MOV        word ptr [EDI + -0x2],AX
    //         0056871b     MOV        byte ptr [EDI],AL
    //         0056871d     SUB        EDI,0x3
    //         00568720     SUB        ECX,0x3
    //                               LAB_00568723                                                 XREF[1]:     0056872c(j)  
    //         00568723     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffa
    //         00568726     SUB        EDI,0x4
    //         00568729     SUB        ECX,0x4
    //         0056872c     JA         LAB_00568723
    //         0056872e     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568734
undefined FUN_00568734() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568734()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568734
    //         00568734     DEC        ECX
    //                               LAB_00568735                                                 XREF[1]:     0056873e(j)  
    //         00568735     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff9
    //         00568738     SUB        EDI,0x4
    //         0056873b     SUB        ECX,0x4
    //         0056873e     JA         LAB_00568735
    //         00568740     MOV        byte ptr [EDI],AL=>DAT_fffffff8
    //         00568742     DEC        EDI
    //         00568743     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568749
undefined FUN_00568749() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568749()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568749
    //         00568749     MOV        byte ptr [EDI],AL
    //         0056874b     DEC        EDI
    //         0056874c     SUB        ECX,0x2
    //                               LAB_0056874f                                                 XREF[1]:     00568758(j)  
    //         0056874f     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff8
    //         00568752     SUB        EDI,0x4
    //         00568755     SUB        ECX,0x4
    //         00568758     JA         LAB_0056874f
    //         0056875a     MOV        byte ptr [EDI],AL=>DAT_fffffffb
    //         0056875c     DEC        EDI
    //         0056875d     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568763
undefined FUN_00568763() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568763()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568763
    //         00568763     MOV        word ptr [EDI + -0x1],AX
    //         00568767     SUB        EDI,0x2
    //         0056876a     SUB        ECX,0x3
    //                               LAB_0056876d                                                 XREF[1]:     00568776(j)  
    //         0056876d     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffb
    //         00568770     SUB        EDI,0x4
    //         00568773     SUB        ECX,0x4
    //         00568776     JA         LAB_0056876d
    //         00568778     MOV        byte ptr [EDI],AL=>DAT_fffffffa
    //         0056877a     DEC        EDI
    //         0056877b     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568781
undefined FUN_00568781() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568781()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568781
    //         00568781     MOV        word ptr [EDI + -0x2],AX
    //         00568785     MOV        byte ptr [EDI],AL
    //         00568787     SUB        EDI,0x3
    //         0056878a     SUB        ECX,0x4
    //                               LAB_0056878d                                                 XREF[1]:     00568796(j)  
    //         0056878d     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffa
    //         00568790     SUB        EDI,0x4
    //         00568793     SUB        ECX,0x4
    //         00568796     JA         LAB_0056878d
    //         00568798     MOV        byte ptr [EDI],AL=>DAT_fffffff9
    //         0056879a     DEC        EDI
    //         0056879b     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005687A1
undefined FUN_005687a1() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005687a1()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005687a1
    //         005687a1     SUB        ECX,0x2
    //                               LAB_005687a4                                                 XREF[1]:     005687ad(j)  
    //         005687a4     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff9
    //         005687a7     SUB        EDI,0x4
    //         005687aa     SUB        ECX,0x4
    //         005687ad     JA         LAB_005687a4
    //         005687af     MOV        word ptr [EDI + -0x1],AX=>DAT_fffffffb
    //         005687b3     SUB        EDI,0x2
    //         005687b6     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005687BC
undefined FUN_005687bc() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005687bc()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005687bc
    //         005687bc     MOV        byte ptr [EDI],AL
    //         005687be     DEC        EDI
    //         005687bf     SUB        ECX,0x3
    //                               LAB_005687c2                                                 XREF[1]:     005687cb(j)  
    //         005687c2     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff8
    //         005687c5     SUB        EDI,0x4
    //         005687c8     SUB        ECX,0x4
    //         005687cb     JA         LAB_005687c2
    //         005687cd     MOV        word ptr [EDI + -0x1],AX=>DAT_fffffffa
    //         005687d1     SUB        EDI,0x2
    //         005687d4     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005687DA
undefined FUN_005687da() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005687da()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005687da
    //         005687da     MOV        word ptr [EDI + -0x1],AX
    //         005687de     SUB        EDI,0x2
    //         005687e1     SUB        ECX,0x4
    //                               LAB_005687e4                                                 XREF[1]:     005687ed(j)  
    //         005687e4     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffb
    //         005687e7     SUB        EDI,0x4
    //         005687ea     SUB        ECX,0x4
    //         005687ed     JA         LAB_005687e4
    //         005687ef     MOV        word ptr [EDI + -0x1],AX=>DAT_fffffff9
    //         005687f3     SUB        EDI,0x2
    //         005687f6     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005687FC
undefined FUN_005687fc() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005687fc()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005687fc
    //         005687fc     MOV        word ptr [EDI + -0x2],AX
    //         00568800     MOV        byte ptr [EDI],AL
    //         00568802     SUB        EDI,0x3
    //         00568805     SUB        ECX,0x5
    //                               LAB_00568808                                                 XREF[1]:     00568811(j)  
    //         00568808     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffa
    //         0056880b     SUB        EDI,0x4
    //         0056880e     SUB        ECX,0x4
    //         00568811     JA         LAB_00568808
    //         00568813     MOV        word ptr [EDI + -0x1],AX=>DAT_fffffff8
    //         00568817     SUB        EDI,0x2
    //         0056881a     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568820
undefined FUN_00568820() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568820()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568820
    //         00568820     SUB        ECX,0x3
    //                               LAB_00568823                                                 XREF[1]:     0056882c(j)  
    //         00568823     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff9
    //         00568826     SUB        EDI,0x4
    //         00568829     SUB        ECX,0x4
    //         0056882c     JA         LAB_00568823
    //         0056882e     MOV        word ptr [EDI + -0x2],AX=>DAT_fffffffa
    //         00568832     MOV        byte ptr [EDI],AL=>DAT_fffffff8
    //         00568834     SUB        EDI,0x3
    //         00568837     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x0056883D
undefined FUN_0056883d() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056883d()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056883d
    //         0056883d     MOV        byte ptr [EDI],AL
    //         0056883f     DEC        EDI
    //         00568840     SUB        ECX,0x4
    //                               LAB_00568843                                                 XREF[1]:     0056884c(j)  
    //         00568843     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff8
    //         00568846     SUB        EDI,0x4
    //         00568849     SUB        ECX,0x4
    //         0056884c     JA         LAB_00568843
    //         0056884e     MOV        word ptr [EDI + -0x2],AX=>DAT_fffffff9
    //         00568852     MOV        byte ptr [EDI],AL=>DAT_fffffffb
    //         00568854     SUB        EDI,0x3
    //         00568857     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x0056885D
undefined FUN_0056885d() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056885d()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056885d
    //         0056885d     MOV        word ptr [EDI + -0x1],AX
    //         00568861     SUB        EDI,0x2
    //         00568864     SUB        ECX,0x5
    //                               LAB_00568867                                                 XREF[1]:     00568870(j)  
    //         00568867     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffb
    //         0056886a     SUB        EDI,0x4
    //         0056886d     SUB        ECX,0x4
    //         00568870     JA         LAB_00568867
    //         00568872     MOV        word ptr [EDI + -0x2],AX=>DAT_fffffff8
    //         00568876     MOV        byte ptr [EDI],AL=>DAT_fffffffa
    //         00568878     SUB        EDI,0x3
    //         0056887b     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568881
undefined FUN_00568881() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568881()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568881
    //         00568881     MOV        word ptr [EDI + -0x2],AX
    //         00568885     MOV        byte ptr [EDI],AL
    //         00568887     SUB        EDI,0x3
    //         0056888a     SUB        ECX,0x6
    //                               LAB_0056888d                                                 XREF[1]:     00568896(j)  
    //         0056888d     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffa
    //         00568890     SUB        EDI,0x4
    //         00568893     SUB        ECX,0x4
    //         00568896     JA         LAB_0056888d
    //         00568898     MOV        word ptr [EDI + -0x2],AX=>DAT_fffffff7
    //         0056889c     MOV        byte ptr [EDI],AL=>DAT_fffffff9
    //         0056889e     SUB        EDI,0x3
    //         005688a1     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005688A7
undefined FUN_005688a7() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005688a7()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005688a7
    //         005688a7     MOV        byte ptr [EDI],AL
    //         005688a9     DEC        EDI
    //         005688aa     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005688B0
undefined FUN_005688b0() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005688b0()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005688b0
    //         005688b0     MOV        byte ptr [EDI],AH
    //         005688b2     DEC        EDI
    //         005688b3     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005688B9
undefined FUN_005688b9() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005688b9()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005688b9
    //         005688b9     MOV        byte ptr [EDI + -0x1],AH
    //         005688bc     MOV        byte ptr [EDI],AL
    //         005688be     SUB        EDI,0x2
    //         005688c1     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005688C7
undefined FUN_005688c7() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005688c7()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005688c7
    //         005688c7     MOV        word ptr [EDI + -0x1],AX
    //         005688cb     SUB        EDI,0x2
    //         005688ce     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005688D4
undefined FUN_005688d4() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005688d4()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005688d4
    //         005688d4     MOV        byte ptr [EDI],AL
    //         005688d6     DEC        EDI
    //         005688d7     MOV        byte ptr [EDI],AH
    //         005688d9     DEC        EDI
    //         005688da     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005688E0
undefined FUN_005688e0() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005688e0()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005688e0
    //         005688e0     MOV        byte ptr [EDI],AL
    //         005688e2     MOV        word ptr [EDI + -0x2],AX
    //         005688e6     SUB        EDI,0x3
    //         005688e9     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005688EF
undefined FUN_005688ef() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005688ef()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005688ef
    //         005688ef     MOV        word ptr [EDI + -0x1],AX
    //         005688f3     MOV        byte ptr [EDI + -0x2],AH
    //         005688f6     SUB        EDI,0x3
    //         005688f9     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005688FF
undefined FUN_005688ff() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005688ff()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005688ff
    //         005688ff     MOV        word ptr [EDI + -0x1],AX
    //         00568903     SUB        EDI,0x2
    //         00568906     MOV        byte ptr [EDI],AH
    //         00568908     DEC        EDI
    //         00568909     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x0056890F
undefined FUN_0056890f() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056890f()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056890f
    //         0056890f     MOV        byte ptr [EDI],AL
    //         00568911     DEC        EDI
    //         00568912     MOV        word ptr [EDI + -0x1],AX
    //         00568916     SUB        EDI,0x2
    //         00568919     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x0056891F
undefined FUN_0056891f() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056891f()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056891f
    //         0056891f     MOV        dword ptr [EDI + -0x3],EAX
    //         00568922     SUB        EDI,0x4
    //         00568925     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x0056892B
undefined FUN_0056892b() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056892b()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056892b
    //         0056892b     MOV        byte ptr [EDI],AL
    //         0056892d     MOV        word ptr [EDI + -0x2],AX
    //         00568931     SUB        EDI,0x3
    //         00568934     MOV        byte ptr [EDI],AH
    //         00568936     DEC        EDI
    //         00568937     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x0056893D
undefined FUN_0056893d() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056893d()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056893d
    //         0056893d     MOV        word ptr [EDI + -0x1],AX
    //         00568941     SUB        EDI,0x2
    //         00568944     MOV        word ptr [EDI + -0x1],AX
    //         00568948     SUB        EDI,0x2
    //         0056894b     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568951
undefined FUN_00568951() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568951()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568951
    //         00568951     MOV        byte ptr [EDI],AL
    //         00568953     DEC        EDI
    //         00568954     MOV        word ptr [EDI + -0x1],AX
    //         00568958     MOV        byte ptr [EDI + -0x2],AH
    //         0056895b     SUB        EDI,0x3
    //         0056895e     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568964
undefined FUN_00568964() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568964()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568964
    //         00568964     MOV        dword ptr [EDI + -0x3],EAX
    //         00568967     SUB        EDI,0x4
    //         0056896a     MOV        byte ptr [EDI],AH
    //         0056896c     DEC        EDI
    //         0056896d     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568973
undefined FUN_00568973() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568973()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568973
    //         00568973     MOV        byte ptr [EDI],AL
    //         00568975     MOV        word ptr [EDI + -0x2],AX
    //         00568979     SUB        EDI,0x3
    //         0056897c     MOV        word ptr [EDI + -0x1],AX
    //         00568980     SUB        EDI,0x2
    //         00568983     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568989
undefined FUN_00568989() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568989()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568989
    //         00568989     MOV        word ptr [EDI + -0x1],AX
    //         0056898d     SUB        EDI,0x2
    //         00568990     MOV        word ptr [EDI + -0x1],AX
    //         00568994     MOV        byte ptr [EDI + -0x2],AH
    //         00568997     SUB        EDI,0x3
    //         0056899a     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005689A0
undefined FUN_005689a0() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005689a0()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005689a0
    //         005689a0     MOV        byte ptr [EDI],AL
    //         005689a2     DEC        EDI
    //         005689a3     MOV        dword ptr [EDI + -0x3],EAX
    //         005689a6     SUB        EDI,0x4
    //         005689a9     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005689AF
undefined FUN_005689af() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005689af()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005689af
    //         005689af     MOV        dword ptr [EDI + -0x3],EAX
    //         005689b2     SUB        EDI,0x4
    //         005689b5     MOV        word ptr [EDI + -0x1],AX=>DAT_fffffffb
    //         005689b9     SUB        EDI,0x2
    //         005689bc     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005689C2
undefined FUN_005689c2() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005689c2()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005689c2
    //         005689c2     MOV        byte ptr [EDI],AL
    //         005689c4     MOV        word ptr [EDI + -0x2],AX
    //         005689c8     SUB        EDI,0x3
    //         005689cb     MOV        word ptr [EDI + -0x1],AX
    //         005689cf     MOV        byte ptr [EDI + -0x2],AH=>DAT_fffffffb
    //         005689d2     SUB        EDI,0x3
    //         005689d5     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005689DB
undefined FUN_005689db() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005689db()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005689db
    //         005689db     MOV        word ptr [EDI + -0x1],AX
    //         005689df     SUB        EDI,0x2
    //         005689e2     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffb
    //         005689e5     SUB        EDI,0x4
    //         005689e8     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005689EE
undefined FUN_005689ee() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005689ee()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005689ee
    //         005689ee     MOV        byte ptr [EDI],AL
    //         005689f0     DEC        EDI
    //         005689f1     MOV        dword ptr [EDI + -0x3],EAX
    //         005689f4     SUB        EDI,0x4
    //         005689f7     MOV        byte ptr [EDI],AH=>DAT_fffffffb
    //         005689f9     DEC        EDI
    //         005689fa     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568A00
undefined FUN_00568a00() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568a00()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568a00
    //         00568a00     MOV        dword ptr [EDI + -0x3],EAX
    //         00568a03     SUB        EDI,0x4
    //         00568a06     MOV        word ptr [EDI + -0x1],AX=>DAT_fffffffb
    //         00568a0a     MOV        byte ptr [EDI + -0x2],AH=>DAT_fffffffa
    //         00568a0d     SUB        EDI,0x3
    //         00568a10     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568A16
undefined FUN_00568a16() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568a16()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568a16
    //         00568a16     MOV        byte ptr [EDI],AL
    //         00568a18     MOV        word ptr [EDI + -0x2],AX
    //         00568a1c     SUB        EDI,0x3
    //         00568a1f     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffa
    //         00568a22     SUB        EDI,0x4
    //         00568a25     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568A2B
undefined FUN_00568a2b() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568a2b()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568a2b
    //         00568a2b     MOV        word ptr [EDI + -0x1],AX
    //         00568a2f     SUB        EDI,0x2
    //         00568a32     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffb
    //         00568a35     SUB        EDI,0x4
    //         00568a38     MOV        byte ptr [EDI],AH=>DAT_fffffffa
    //         00568a3a     DEC        EDI
    //         00568a3b     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568A41
undefined FUN_00568a41() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568a41()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568a41
    //         00568a41     MOV        byte ptr [EDI],AL
    //         00568a43     DEC        EDI
    //         00568a44     MOV        dword ptr [EDI + -0x3],EAX
    //         00568a47     SUB        EDI,0x4
    //         00568a4a     MOV        word ptr [EDI + -0x1],AX=>DAT_fffffffa
    //         00568a4e     SUB        EDI,0x2
    //         00568a51     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568A57
undefined FUN_00568a57() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568a57()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568a57                                                 XREF[1]:     00568a60(j)  
    //         00568a57     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff9
    //         00568a5a     SUB        EDI,0x4
    //         00568a5d     SUB        ECX,0x4
    //         00568a60     JA         FUN_00568a57
    //         00568a62     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568A68
undefined FUN_00568a68() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568a68()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568a68
    //         00568a68     MOV        byte ptr [EDI],AL
    //         00568a6a     DEC        EDI
    //         00568a6b     DEC        ECX
    //                               LAB_00568a6c                                                 XREF[1]:     00568a75(j)  
    //         00568a6c     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff8
    //         00568a6f     SUB        EDI,0x4
    //         00568a72     SUB        ECX,0x4
    //         00568a75     JA         LAB_00568a6c
    //         00568a77     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568A7D
undefined FUN_00568a7d() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568a7d()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568a7d
    //         00568a7d     MOV        word ptr [EDI + -0x1],AX
    //         00568a81     SUB        EDI,0x2
    //         00568a84     SUB        ECX,0x2
    //                               LAB_00568a87                                                 XREF[1]:     00568a90(j)  
    //         00568a87     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffb
    //         00568a8a     SUB        EDI,0x4
    //         00568a8d     SUB        ECX,0x4
    //         00568a90     JA         LAB_00568a87
    //         00568a92     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568A98
undefined FUN_00568a98() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568a98()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568a98
    //         00568a98     MOV        byte ptr [EDI],AL
    //         00568a9a     MOV        word ptr [EDI + -0x2],AX
    //         00568a9e     SUB        EDI,0x3
    //         00568aa1     SUB        ECX,0x3
    //                               LAB_00568aa4                                                 XREF[1]:     00568aad(j)  
    //         00568aa4     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffa
    //         00568aa7     SUB        EDI,0x4
    //         00568aaa     SUB        ECX,0x4
    //         00568aad     JA         LAB_00568aa4
    //         00568aaf     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568AB5
undefined FUN_00568ab5() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568ab5()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568ab5
    //         00568ab5     DEC        ECX
    //                               LAB_00568ab6                                                 XREF[1]:     00568abf(j)  
    //         00568ab6     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff9
    //         00568ab9     SUB        EDI,0x4
    //         00568abc     SUB        ECX,0x4
    //         00568abf     JA         LAB_00568ab6
    //         00568ac1     MOV        byte ptr [EDI],AH=>DAT_fffffff8
    //         00568ac3     DEC        EDI
    //         00568ac4     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568ACA
undefined FUN_00568aca() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568aca()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568aca
    //         00568aca     MOV        byte ptr [EDI],AL
    //         00568acc     DEC        EDI
    //         00568acd     SUB        ECX,0x2
    //                               LAB_00568ad0                                                 XREF[1]:     00568ad9(j)  
    //         00568ad0     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff8
    //         00568ad3     SUB        EDI,0x4
    //         00568ad6     SUB        ECX,0x4
    //         00568ad9     JA         LAB_00568ad0
    //         00568adb     MOV        byte ptr [EDI],AH=>DAT_fffffffb
    //         00568add     DEC        EDI
    //         00568ade     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568AE4
undefined FUN_00568ae4() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568ae4()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568ae4
    //         00568ae4     MOV        word ptr [EDI + -0x1],AX
    //         00568ae8     SUB        EDI,0x2
    //         00568aeb     SUB        ECX,0x3
    //                               LAB_00568aee                                                 XREF[1]:     00568af7(j)  
    //         00568aee     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffb
    //         00568af1     SUB        EDI,0x4
    //         00568af4     SUB        ECX,0x4
    //         00568af7     JA         LAB_00568aee
    //         00568af9     MOV        byte ptr [EDI],AH=>DAT_fffffffa
    //         00568afb     DEC        EDI
    //         00568afc     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568B02
undefined FUN_00568b02() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568b02()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568b02
    //         00568b02     MOV        byte ptr [EDI],AL
    //         00568b04     MOV        word ptr [EDI + -0x2],AX
    //         00568b08     SUB        EDI,0x3
    //         00568b0b     SUB        ECX,0x4
    //                               LAB_00568b0e                                                 XREF[1]:     00568b17(j)  
    //         00568b0e     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffa
    //         00568b11     SUB        EDI,0x4
    //         00568b14     SUB        ECX,0x4
    //         00568b17     JA         LAB_00568b0e
    //         00568b19     MOV        byte ptr [EDI],AH=>DAT_fffffff9
    //         00568b1b     DEC        EDI
    //         00568b1c     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568B22
undefined FUN_00568b22() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568b22()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568b22
    //         00568b22     SUB        ECX,0x2
    //                               LAB_00568b25                                                 XREF[1]:     00568b2e(j)  
    //         00568b25     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff9
    //         00568b28     SUB        EDI,0x4
    //         00568b2b     SUB        ECX,0x4
    //         00568b2e     JA         LAB_00568b25
    //         00568b30     MOV        word ptr [EDI + -0x1],AX=>DAT_fffffffb
    //         00568b34     SUB        EDI,0x2
    //         00568b37     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568B3D
undefined FUN_00568b3d() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568b3d()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568b3d
    //         00568b3d     MOV        byte ptr [EDI],AL
    //         00568b3f     DEC        EDI
    //         00568b40     SUB        ECX,0x3
    //                               LAB_00568b43                                                 XREF[1]:     00568b4c(j)  
    //         00568b43     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff8
    //         00568b46     SUB        EDI,0x4
    //         00568b49     SUB        ECX,0x4
    //         00568b4c     JA         LAB_00568b43
    //         00568b4e     MOV        word ptr [EDI + -0x1],AX=>DAT_fffffffa
    //         00568b52     SUB        EDI,0x2
    //         00568b55     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568B5B
undefined FUN_00568b5b() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568b5b()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568b5b
    //         00568b5b     MOV        word ptr [EDI + -0x1],AX
    //         00568b5f     SUB        EDI,0x2
    //         00568b62     SUB        ECX,0x4
    //                               LAB_00568b65                                                 XREF[1]:     00568b6e(j)  
    //         00568b65     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffb
    //         00568b68     SUB        EDI,0x4
    //         00568b6b     SUB        ECX,0x4
    //         00568b6e     JA         LAB_00568b65
    //         00568b70     MOV        word ptr [EDI + -0x1],AX=>DAT_fffffff9
    //         00568b74     SUB        EDI,0x2
    //         00568b77     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568B7D
undefined FUN_00568b7d() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568b7d()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568b7d
    //         00568b7d     MOV        byte ptr [EDI],AL
    //         00568b7f     MOV        word ptr [EDI + -0x2],AX
    //         00568b83     SUB        EDI,0x3
    //         00568b86     SUB        ECX,0x5
    //                               LAB_00568b89                                                 XREF[1]:     00568b92(j)  
    //         00568b89     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffa
    //         00568b8c     SUB        EDI,0x4
    //         00568b8f     SUB        ECX,0x4
    //         00568b92     JA         LAB_00568b89
    //         00568b94     MOV        word ptr [EDI + -0x1],AX=>DAT_fffffff8
    //         00568b98     SUB        EDI,0x2
    //         00568b9b     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568BA1
undefined FUN_00568ba1() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568ba1()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568ba1
    //         00568ba1     SUB        ECX,0x3
    //                               LAB_00568ba4                                                 XREF[1]:     00568bad(j)  
    //         00568ba4     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff9
    //         00568ba7     SUB        EDI,0x4
    //         00568baa     SUB        ECX,0x4
    //         00568bad     JA         LAB_00568ba4
    //         00568baf     MOV        word ptr [EDI + -0x1],AX=>DAT_fffffffb
    //         00568bb3     MOV        byte ptr [EDI + -0x2],AH=>DAT_fffffffa
    //         00568bb6     SUB        EDI,0x3
    //         00568bb9     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568BBF
undefined FUN_00568bbf() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568bbf()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568bbf
    //         00568bbf     MOV        byte ptr [EDI],AL
    //         00568bc1     DEC        EDI
    //         00568bc2     SUB        ECX,0x4
    //                               LAB_00568bc5                                                 XREF[1]:     00568bce(j)  
    //         00568bc5     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff8
    //         00568bc8     SUB        EDI,0x4
    //         00568bcb     SUB        ECX,0x4
    //         00568bce     JA         LAB_00568bc5
    //         00568bd0     MOV        word ptr [EDI + -0x1],AX=>DAT_fffffffa
    //         00568bd4     MOV        byte ptr [EDI + -0x2],AH=>DAT_fffffff9
    //         00568bd7     SUB        EDI,0x3
    //         00568bda     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568BE0
undefined FUN_00568be0() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568be0()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568be0
    //         00568be0     MOV        word ptr [EDI + -0x1],AX
    //         00568be4     SUB        EDI,0x2
    //         00568be7     SUB        ECX,0x5
    //                               LAB_00568bea                                                 XREF[1]:     00568bf3(j)  
    //         00568bea     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffb
    //         00568bed     SUB        EDI,0x4
    //         00568bf0     SUB        ECX,0x4
    //         00568bf3     JA         LAB_00568bea
    //         00568bf5     MOV        word ptr [EDI + -0x1],AX=>DAT_fffffff9
    //         00568bf9     MOV        byte ptr [EDI + -0x2],AH=>DAT_fffffff8
    //         00568bfc     SUB        EDI,0x3
    //         00568bff     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568C05
undefined FUN_00568c05() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568c05()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568c05
    //         00568c05     MOV        byte ptr [EDI],AL
    //         00568c07     MOV        word ptr [EDI + -0x2],AX
    //         00568c0b     SUB        EDI,0x3
    //         00568c0e     SUB        ECX,0x6
    //                               LAB_00568c11                                                 XREF[1]:     00568c1a(j)  
    //         00568c11     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffa
    //         00568c14     SUB        EDI,0x4
    //         00568c17     SUB        ECX,0x4
    //         00568c1a     JA         LAB_00568c11
    //         00568c1c     MOV        word ptr [EDI + -0x1],AX=>DAT_fffffff8
    //         00568c20     MOV        byte ptr [EDI + -0x2],AH=>DAT_fffffff7
    //         00568c23     SUB        EDI,0x3
    //         00568c26     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568C2C
undefined FUN_00568c2c() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568c2c()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568c2c
    //         00568c2c     MOV        DL,byte ptr [EDI]
    //         00568c2e     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00568c31     MOV        byte ptr [EDI],AL
    //         00568c33     DEC        EDI
    //         00568c34     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568C3A
undefined FUN_00568c3a() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568c3a()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568c3a
    //         00568c3a     MOV        AX,word ptr [EDI + -0x1]
    //         00568c3e     MOV        DL,AL
    //         00568c40     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00568c43     MOV        DL,AH
    //         00568c45     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00568c48     MOV        word ptr [EDI + -0x1],AX
    //         00568c4c     SUB        EDI,0x2
    //         00568c4f     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568C55
undefined FUN_00568c55() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568c55()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568c55
    //         00568c55     MOV        DL,byte ptr [EDI]
    //         00568c57     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00568c5a     MOV        byte ptr [EDI],AL
    //         00568c5c     DEC        EDI
    //         00568c5d     MOV        DL,byte ptr [EDI]
    //         00568c5f     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00568c62     MOV        byte ptr [EDI],AL
    //         00568c64     DEC        EDI
    //         00568c65     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568C6B
undefined FUN_00568c6b() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568c6b()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568c6b
    //         00568c6b     MOV        EAX,dword ptr [EDI + -0x2]
    //         00568c6e     MOV        DL,AL
    //         00568c70     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00568c73     MOV        DL,AH
    //         00568c75     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00568c78     BSWAP      EAX
    //         00568c7a     MOV        DL,AH
    //         00568c7c     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00568c7f     BSWAP      EAX
    //         00568c81     MOV        dword ptr [EDI + -0x2],EAX
    //         00568c84     SUB        EDI,0x3
    //         00568c87     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568C8D
undefined FUN_00568c8d() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568c8d()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568c8d
    //         00568c8d     MOV        EAX,dword ptr [EDI + -0x3]
    //         00568c90     MOV        DL,AH
    //         00568c92     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00568c95     BSWAP      EAX
    //         00568c97     MOV        DL,AH
    //         00568c99     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00568c9c     MOV        DL,AL
    //         00568c9e     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00568ca1     BSWAP      EAX
    //         00568ca3     MOV        dword ptr [EDI + -0x3],EAX
    //         00568ca6     SUB        EDI,0x3
    //         00568ca9     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568CAF
undefined FUN_00568caf() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568caf()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568caf
    //         00568caf     MOV        AX,word ptr [EDI + -0x1]
    //         00568cb3     MOV        DL,AL
    //         00568cb5     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00568cb8     MOV        DL,AH
    //         00568cba     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00568cbd     MOV        word ptr [EDI + -0x1],AX
    //         00568cc1     SUB        EDI,0x2
    //         00568cc4     MOV        DL,byte ptr [EDI]
    //         00568cc6     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00568cc9     MOV        byte ptr [EDI],AL
    //         00568ccb     DEC        EDI
    //         00568ccc     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568CD2
undefined FUN_00568cd2() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568cd2()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568cd2
    //         00568cd2     MOV        DL,byte ptr [EDI]
    //         00568cd4     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00568cd7     MOV        byte ptr [EDI],AL
    //         00568cd9     DEC        EDI
    //         00568cda     MOV        AX,word ptr [EDI + -0x1]
    //         00568cde     MOV        DL,AL
    //         00568ce0     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00568ce3     MOV        DL,AH
    //         00568ce5     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00568ce8     MOV        word ptr [EDI + -0x1],AX
    //         00568cec     SUB        EDI,0x2
    //         00568cef     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568CF5
undefined FUN_00568cf5() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568cf5()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568cf5
    //         00568cf5     MOV        EAX,dword ptr [EDI + -0x3]
    //         00568cf8     MOV        DL,AL
    //         00568cfa     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00568cfd     MOV        DL,AH
    //         00568cff     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00568d02     BSWAP      EAX
    //         00568d04     MOV        DL,AL
    //         00568d06     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00568d09     MOV        DL,AH
    //         00568d0b     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00568d0e     BSWAP      EAX
    //         00568d10     MOV        dword ptr [EDI + -0x3],EAX
    //         00568d13     SUB        EDI,0x4
    //         00568d16     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568D1C
undefined FUN_00568d1c() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568d1c()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568d1c
    //         00568d1c     MOV        EAX,dword ptr [EDI + -0x2]
    //         00568d1f     MOV        DL,AL
    //         00568d21     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00568d24     MOV        DL,AH
    //         00568d26     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00568d29     BSWAP      EAX
    //         00568d2b     MOV        DL,AH
    //         00568d2d     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00568d30     BSWAP      EAX
    //         00568d32     MOV        dword ptr [EDI + -0x2],EAX
    //         00568d35     SUB        EDI,0x3
    //         00568d38     MOV        DL,byte ptr [EDI]
    //         00568d3a     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00568d3d     MOV        byte ptr [EDI],AL
    //         00568d3f     DEC        EDI
    //         00568d40     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568D46
undefined FUN_00568d46() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568d46()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568d46
    //         00568d46     MOV        AX,word ptr [EDI + -0x1]
    //         00568d4a     MOV        DL,AL
    //         00568d4c     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00568d4f     MOV        DL,AH
    //         00568d51     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00568d54     MOV        word ptr [EDI + -0x1],AX
    //         00568d58     SUB        EDI,0x2
    //         00568d5b     MOV        AX,word ptr [EDI + -0x1]
    //         00568d5f     MOV        DL,AL
    //         00568d61     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00568d64     MOV        DL,AH
    //         00568d66     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00568d69     MOV        word ptr [EDI + -0x1],AX
    //         00568d6d     SUB        EDI,0x2
    //         00568d70     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568D76
undefined FUN_00568d76() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568d76()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568d76
    //         00568d76     MOV        DL,byte ptr [EDI]
    //         00568d78     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00568d7b     MOV        byte ptr [EDI],AL
    //         00568d7d     DEC        EDI
    //         00568d7e     MOV        EAX,dword ptr [EDI + -0x3]
    //         00568d81     MOV        DL,AH
    //         00568d83     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00568d86     BSWAP      EAX
    //         00568d88     MOV        DL,AH
    //         00568d8a     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00568d8d     MOV        DL,AL
    //         00568d8f     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00568d92     BSWAP      EAX
    //         00568d94     MOV        dword ptr [EDI + -0x3],EAX
    //         00568d97     SUB        EDI,0x3
    //         00568d9a     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568DA0
undefined FUN_00568da0() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568da0()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568da0
    //         00568da0     MOV        EAX,dword ptr [EDI + -0x3]
    //         00568da3     MOV        DL,AL
    //         00568da5     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00568da8     MOV        DL,AH
    //         00568daa     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00568dad     BSWAP      EAX
    //         00568daf     MOV        DL,AL
    //         00568db1     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00568db4     MOV        DL,AH
    //         00568db6     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00568db9     BSWAP      EAX
    //         00568dbb     MOV        dword ptr [EDI + -0x3],EAX
    //         00568dbe     SUB        EDI,0x4
    //         00568dc1     MOV        DL,byte ptr [EDI]
    //         00568dc3     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00568dc6     MOV        byte ptr [EDI],AL
    //         00568dc8     DEC        EDI
    //         00568dc9     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568DCF
undefined FUN_00568dcf() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568dcf()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568dcf
    //         00568dcf     MOV        EAX,dword ptr [EDI + -0x2]
    //         00568dd2     MOV        DL,AL
    //         00568dd4     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00568dd7     MOV        DL,AH
    //         00568dd9     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00568ddc     BSWAP      EAX
    //         00568dde     MOV        DL,AH
    //         00568de0     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00568de3     BSWAP      EAX
    //         00568de5     MOV        dword ptr [EDI + -0x2],EAX
    //         00568de8     SUB        EDI,0x3
    //         00568deb     MOV        AX,word ptr [EDI + -0x1]
    //         00568def     MOV        DL,AL
    //         00568df1     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00568df4     MOV        DL,AH
    //         00568df6     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00568df9     MOV        word ptr [EDI + -0x1],AX
    //         00568dfd     SUB        EDI,0x2
    //         00568e00     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568E06
undefined FUN_00568e06() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568e06()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568e06
    //         00568e06     MOV        AX,word ptr [EDI + -0x1]
    //         00568e0a     MOV        DL,AL
    //         00568e0c     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00568e0f     MOV        DL,AH
    //         00568e11     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00568e14     MOV        word ptr [EDI + -0x1],AX
    //         00568e18     SUB        EDI,0x2
    //         00568e1b     MOV        EAX,dword ptr [EDI + -0x3]=>DAT_fffffffb
    //         00568e1e     MOV        DL,AH
    //         00568e20     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00568e23     BSWAP      EAX
    //         00568e25     MOV        DL,AH
    //         00568e27     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00568e2a     MOV        DL,AL
    //         00568e2c     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00568e2f     BSWAP      EAX
    //         00568e31     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffb
    //         00568e34     SUB        EDI,0x3
    //         00568e37     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568E3D
undefined FUN_00568e3d() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568e3d()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568e3d
    //         00568e3d     MOV        DL,byte ptr [EDI]
    //         00568e3f     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00568e42     MOV        byte ptr [EDI],AL
    //         00568e44     DEC        EDI
    //         00568e45     MOV        EAX,dword ptr [EDI + -0x3]
    //         00568e48     MOV        DL,AL
    //         00568e4a     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00568e4d     MOV        DL,AH
    //         00568e4f     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00568e52     BSWAP      EAX
    //         00568e54     MOV        DL,AL
    //         00568e56     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00568e59     MOV        DL,AH
    //         00568e5b     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00568e5e     BSWAP      EAX
    //         00568e60     MOV        dword ptr [EDI + -0x3],EAX
    //         00568e63     SUB        EDI,0x4
    //         00568e66     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568E6C
undefined FUN_00568e6c() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568e6c()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568e6c
    //         00568e6c     MOV        EAX,dword ptr [EDI + -0x3]
    //         00568e6f     MOV        DL,AL
    //         00568e71     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00568e74     MOV        DL,AH
    //         00568e76     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00568e79     BSWAP      EAX
    //         00568e7b     MOV        DL,AL
    //         00568e7d     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00568e80     MOV        DL,AH
    //         00568e82     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00568e85     BSWAP      EAX
    //         00568e87     MOV        dword ptr [EDI + -0x3],EAX
    //         00568e8a     SUB        EDI,0x4
    //         00568e8d     MOV        AX,word ptr [EDI + -0x1]=>DAT_fffffffb
    //         00568e91     MOV        DL,AL
    //         00568e93     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00568e96     MOV        DL,AH
    //         00568e98     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00568e9b     MOV        word ptr [EDI + -0x1],AX=>DAT_fffffffb
    //         00568e9f     SUB        EDI,0x2
    //         00568ea2     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568EA8
undefined FUN_00568ea8() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568ea8()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568ea8
    //         00568ea8     MOV        EAX,dword ptr [EDI + -0x2]
    //         00568eab     MOV        DL,AL
    //         00568ead     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00568eb0     MOV        DL,AH
    //         00568eb2     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00568eb5     BSWAP      EAX
    //         00568eb7     MOV        DL,AH
    //         00568eb9     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00568ebc     BSWAP      EAX
    //         00568ebe     MOV        dword ptr [EDI + -0x2],EAX
    //         00568ec1     SUB        EDI,0x3
    //         00568ec4     MOV        EAX,dword ptr [EDI + -0x3]=>DAT_fffffffa
    //         00568ec7     MOV        DL,AH
    //         00568ec9     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00568ecc     BSWAP      EAX
    //         00568ece     MOV        DL,AH
    //         00568ed0     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00568ed3     MOV        DL,AL
    //         00568ed5     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00568ed8     BSWAP      EAX
    //         00568eda     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffa
    //         00568edd     SUB        EDI,0x3
    //         00568ee0     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568EE6
undefined FUN_00568ee6() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568ee6()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568ee6
    //         00568ee6     MOV        AX,word ptr [EDI + -0x1]
    //         00568eea     MOV        DL,AL
    //         00568eec     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00568eef     MOV        DL,AH
    //         00568ef1     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00568ef4     MOV        word ptr [EDI + -0x1],AX
    //         00568ef8     SUB        EDI,0x2
    //         00568efb     MOV        EAX,dword ptr [EDI + -0x3]=>DAT_fffffffb
    //         00568efe     MOV        DL,AL
    //         00568f00     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00568f03     MOV        DL,AH
    //         00568f05     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00568f08     BSWAP      EAX
    //         00568f0a     MOV        DL,AL
    //         00568f0c     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00568f0f     MOV        DL,AH
    //         00568f11     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00568f14     BSWAP      EAX
    //         00568f16     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffb
    //         00568f19     SUB        EDI,0x4
    //         00568f1c     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568F22
undefined FUN_00568f22() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568f22()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568f22
    //         00568f22     MOV        DL,byte ptr [EDI]
    //         00568f24     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00568f27     MOV        byte ptr [EDI],AL
    //         00568f29     DEC        EDI
    //         00568f2a     MOV        EAX,dword ptr [EDI + -0x3]
    //         00568f2d     MOV        DL,AL
    //         00568f2f     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00568f32     MOV        DL,AH
    //         00568f34     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00568f37     BSWAP      EAX
    //         00568f39     MOV        DL,AL
    //         00568f3b     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00568f3e     MOV        DL,AH
    //         00568f40     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00568f43     BSWAP      EAX
    //         00568f45     MOV        dword ptr [EDI + -0x3],EAX
    //         00568f48     SUB        EDI,0x4
    //         00568f4b     MOV        DL,byte ptr [EDI]=>DAT_fffffffb
    //         00568f4d     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00568f50     MOV        byte ptr [EDI],AL=>DAT_fffffffb
    //         00568f52     DEC        EDI
    //         00568f53     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568F59
undefined FUN_00568f59() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568f59()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568f59
    //         00568f59     MOV        EAX,dword ptr [EDI + -0x3]
    //         00568f5c     MOV        DL,AL
    //         00568f5e     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00568f61     MOV        DL,AH
    //         00568f63     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00568f66     BSWAP      EAX
    //         00568f68     MOV        DL,AL
    //         00568f6a     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00568f6d     MOV        DL,AH
    //         00568f6f     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00568f72     BSWAP      EAX
    //         00568f74     MOV        dword ptr [EDI + -0x3],EAX
    //         00568f77     SUB        EDI,0x4
    //         00568f7a     MOV        EAX,dword ptr [EDI + -0x3]=>DAT_fffffff9
    //         00568f7d     MOV        DL,AH
    //         00568f7f     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00568f82     BSWAP      EAX
    //         00568f84     MOV        DL,AH
    //         00568f86     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00568f89     MOV        DL,AL
    //         00568f8b     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00568f8e     BSWAP      EAX
    //         00568f90     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff9
    //         00568f93     SUB        EDI,0x3
    //         00568f96     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568F9C
undefined FUN_00568f9c() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568f9c()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568f9c
    //         00568f9c     MOV        EAX,dword ptr [EDI + -0x2]
    //         00568f9f     MOV        DL,AL
    //         00568fa1     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00568fa4     MOV        DL,AH
    //         00568fa6     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00568fa9     BSWAP      EAX
    //         00568fab     MOV        DL,AH
    //         00568fad     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00568fb0     BSWAP      EAX
    //         00568fb2     MOV        dword ptr [EDI + -0x2],EAX
    //         00568fb5     SUB        EDI,0x3
    //         00568fb8     MOV        EAX,dword ptr [EDI + -0x3]=>DAT_fffffffa
    //         00568fbb     MOV        DL,AL
    //         00568fbd     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00568fc0     MOV        DL,AH
    //         00568fc2     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00568fc5     BSWAP      EAX
    //         00568fc7     MOV        DL,AL
    //         00568fc9     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00568fcc     MOV        DL,AH
    //         00568fce     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00568fd1     BSWAP      EAX
    //         00568fd3     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffa
    //         00568fd6     SUB        EDI,0x4
    //         00568fd9     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00568FDF
undefined FUN_00568fdf() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00568fdf()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00568fdf
    //         00568fdf     MOV        AX,word ptr [EDI + -0x1]
    //         00568fe3     MOV        DL,AL
    //         00568fe5     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00568fe8     MOV        DL,AH
    //         00568fea     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00568fed     MOV        word ptr [EDI + -0x1],AX
    //         00568ff1     SUB        EDI,0x2
    //         00568ff4     MOV        EAX,dword ptr [EDI + -0x3]=>DAT_fffffffb
    //         00568ff7     MOV        DL,AL
    //         00568ff9     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00568ffc     MOV        DL,AH
    //         00568ffe     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569001     BSWAP      EAX
    //         00569003     MOV        DL,AL
    //         00569005     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569008     MOV        DL,AH
    //         0056900a     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056900d     BSWAP      EAX
    //         0056900f     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffb
    //         00569012     SUB        EDI,0x4
    //         00569015     MOV        DL,byte ptr [EDI]=>DAT_fffffffa
    //         00569017     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056901a     MOV        byte ptr [EDI],AL=>DAT_fffffffa
    //         0056901c     DEC        EDI
    //         0056901d     JMP        dword ptr [DAT_0088c044]
}

