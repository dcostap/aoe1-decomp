// Auto-generated scaffold unit: bucket_0566.cpp.asm
#include "../include/common.h"

// Offset: 0x00566045
undefined FUN_00566045() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00566045()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00566045
    //         00566045     MOV        DL,byte ptr [EDI]
    //         00566047     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056604a     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00566050     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00566056     MOV        byte ptr [EDI],AH
    //         00566058     INC        EDI
    //         00566059     MOV        EAX,dword ptr [EDI]
    //         0056605b     MOV        DL,AL
    //         0056605d     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00566060     MOV        DL,AH
    //         00566062     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00566065     BSWAP      EAX
    //         00566067     MOV        DL,AL
    //         00566069     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056606c     MOV        DL,AH
    //         0056606e     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00566071     BSWAP      EAX
    //         00566073     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00566079     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056607f     MOV        dword ptr [EDI],EAX
    //         00566081     ADD        EDI,0x4
    //         00566084     MOV        AX,word ptr [EDI]
    //         00566087     MOV        DL,AL
    //         00566089     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056608c     MOV        DL,AH
    //         0056608e     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00566091     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00566097     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056609d     MOV        word ptr [EDI],AX
    //         005660a0     ADD        EDI,0x2
    //         005660a3     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005660A9
undefined FUN_005660a9() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005660a9()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005660a9                                                 XREF[1]:     005660d7(j)  
    //         005660a9     MOV        EAX,dword ptr [EDI]
    //         005660ab     MOV        DL,AL
    //         005660ad     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005660b0     MOV        DL,AH
    //         005660b2     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005660b5     BSWAP      EAX
    //         005660b7     MOV        DL,AL
    //         005660b9     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005660bc     MOV        DL,AH
    //         005660be     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005660c1     BSWAP      EAX
    //         005660c3     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         005660c9     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005660cf     MOV        dword ptr [EDI],EAX
    //         005660d1     ADD        EDI,0x4
    //         005660d4     SUB        ECX,0x4
    //         005660d7     JA         FUN_005660a9
    //         005660d9     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005660DF
undefined FUN_005660df() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005660df()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005660df
    //         005660df     MOV        DL,byte ptr [EDI]
    //         005660e1     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005660e4     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         005660ea     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005660f0     MOV        byte ptr [EDI],AH
    //         005660f2     INC        EDI
    //         005660f3     DEC        ECX
    //                               LAB_005660f4                                                 XREF[1]:     00566122(j)  
    //         005660f4     MOV        EAX,dword ptr [EDI]
    //         005660f6     MOV        DL,AL
    //         005660f8     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005660fb     MOV        DL,AH
    //         005660fd     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00566100     BSWAP      EAX
    //         00566102     MOV        DL,AL
    //         00566104     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00566107     MOV        DL,AH
    //         00566109     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056610c     BSWAP      EAX
    //         0056610e     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00566114     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056611a     MOV        dword ptr [EDI],EAX
    //         0056611c     ADD        EDI,0x4
    //         0056611f     SUB        ECX,0x4
    //         00566122     JA         LAB_005660f4
    //         00566124     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x0056612A
undefined FUN_0056612a() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056612a()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056612a
    //         0056612a     MOV        AX,word ptr [EDI]
    //         0056612d     MOV        DL,AL
    //         0056612f     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00566132     MOV        DL,AH
    //         00566134     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00566137     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         0056613d     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00566143     MOV        word ptr [EDI],AX
    //         00566146     ADD        EDI,0x2
    //         00566149     SUB        ECX,0x2
    //                               LAB_0056614c                                                 XREF[1]:     0056617a(j)  
    //         0056614c     MOV        EAX,dword ptr [EDI]
    //         0056614e     MOV        DL,AL
    //         00566150     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00566153     MOV        DL,AH
    //         00566155     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00566158     BSWAP      EAX
    //         0056615a     MOV        DL,AL
    //         0056615c     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056615f     MOV        DL,AH
    //         00566161     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00566164     BSWAP      EAX
    //         00566166     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         0056616c     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00566172     MOV        dword ptr [EDI],EAX
    //         00566174     ADD        EDI,0x4
    //         00566177     SUB        ECX,0x4
    //         0056617a     JA         LAB_0056614c
    //         0056617c     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00566182
undefined FUN_00566182() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00566182()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00566182
    //         00566182     MOV        EAX,dword ptr [EDI + -0x1]
    //         00566185     MOV        DL,AH
    //         00566187     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056618a     BSWAP      EAX
    //         0056618c     MOV        DL,AH
    //         0056618e     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00566191     MOV        DL,AL
    //         00566193     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00566196     BSWAP      EAX
    //         00566198     MOV        DL,AL
    //         0056619a     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         005661a0     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005661a6     MOV        AL,DL
    //         005661a8     MOV        dword ptr [EDI + -0x1],EAX
    //         005661ab     ADD        EDI,0x3
    //         005661ae     SUB        ECX,0x3
    //                               LAB_005661b1                                                 XREF[1]:     005661df(j)  
    //         005661b1     MOV        EAX,dword ptr [EDI]
    //         005661b3     MOV        DL,AL
    //         005661b5     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005661b8     MOV        DL,AH
    //         005661ba     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005661bd     BSWAP      EAX
    //         005661bf     MOV        DL,AL
    //         005661c1     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005661c4     MOV        DL,AH
    //         005661c6     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005661c9     BSWAP      EAX
    //         005661cb     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         005661d1     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005661d7     MOV        dword ptr [EDI],EAX
    //         005661d9     ADD        EDI,0x4
    //         005661dc     SUB        ECX,0x4
    //         005661df     JA         LAB_005661b1
    //         005661e1     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005661E7
undefined FUN_005661e7() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005661e7()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005661e7
    //         005661e7     DEC        ECX
    //                               LAB_005661e8                                                 XREF[1]:     00566216(j)  
    //         005661e8     MOV        EAX,dword ptr [EDI]
    //         005661ea     MOV        DL,AL
    //         005661ec     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005661ef     MOV        DL,AH
    //         005661f1     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005661f4     BSWAP      EAX
    //         005661f6     MOV        DL,AL
    //         005661f8     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005661fb     MOV        DL,AH
    //         005661fd     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00566200     BSWAP      EAX
    //         00566202     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00566208     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056620e     MOV        dword ptr [EDI],EAX
    //         00566210     ADD        EDI,0x4
    //         00566213     SUB        ECX,0x4
    //         00566216     JA         LAB_005661e8
    //         00566218     MOV        DL,byte ptr [EDI]
    //         0056621a     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056621d     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00566223     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00566229     MOV        byte ptr [EDI],AL
    //         0056622b     INC        EDI
    //         0056622c     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00566232
undefined FUN_00566232() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00566232()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00566232
    //         00566232     MOV        DL,byte ptr [EDI]
    //         00566234     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00566237     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         0056623d     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00566243     MOV        byte ptr [EDI],AH
    //         00566245     INC        EDI
    //         00566246     SUB        ECX,0x2
    //                               LAB_00566249                                                 XREF[1]:     00566277(j)  
    //         00566249     MOV        EAX,dword ptr [EDI]
    //         0056624b     MOV        DL,AL
    //         0056624d     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00566250     MOV        DL,AH
    //         00566252     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00566255     BSWAP      EAX
    //         00566257     MOV        DL,AL
    //         00566259     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056625c     MOV        DL,AH
    //         0056625e     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00566261     BSWAP      EAX
    //         00566263     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00566269     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056626f     MOV        dword ptr [EDI],EAX
    //         00566271     ADD        EDI,0x4
    //         00566274     SUB        ECX,0x4
    //         00566277     JA         LAB_00566249
    //         00566279     MOV        DL,byte ptr [EDI]
    //         0056627b     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056627e     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00566284     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056628a     MOV        byte ptr [EDI],AL
    //         0056628c     INC        EDI
    //         0056628d     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00566293
undefined FUN_00566293() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00566293()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00566293
    //         00566293     MOV        AX,word ptr [EDI]
    //         00566296     MOV        DL,AL
    //         00566298     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056629b     MOV        DL,AH
    //         0056629d     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005662a0     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         005662a6     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005662ac     MOV        word ptr [EDI],AX
    //         005662af     ADD        EDI,0x2
    //         005662b2     SUB        ECX,0x3
    //                               LAB_005662b5                                                 XREF[1]:     005662e3(j)  
    //         005662b5     MOV        EAX,dword ptr [EDI]
    //         005662b7     MOV        DL,AL
    //         005662b9     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005662bc     MOV        DL,AH
    //         005662be     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005662c1     BSWAP      EAX
    //         005662c3     MOV        DL,AL
    //         005662c5     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005662c8     MOV        DL,AH
    //         005662ca     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005662cd     BSWAP      EAX
    //         005662cf     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         005662d5     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005662db     MOV        dword ptr [EDI],EAX
    //         005662dd     ADD        EDI,0x4
    //         005662e0     SUB        ECX,0x4
    //         005662e3     JA         LAB_005662b5
    //         005662e5     MOV        DL,byte ptr [EDI]
    //         005662e7     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005662ea     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         005662f0     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005662f6     MOV        byte ptr [EDI],AL
    //         005662f8     INC        EDI
    //         005662f9     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005662FF
undefined FUN_005662ff() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005662ff()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005662ff
    //         005662ff     MOV        EAX,dword ptr [EDI + -0x1]
    //         00566302     MOV        DL,AH
    //         00566304     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00566307     BSWAP      EAX
    //         00566309     MOV        DL,AH
    //         0056630b     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056630e     MOV        DL,AL
    //         00566310     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00566313     BSWAP      EAX
    //         00566315     MOV        DL,AL
    //         00566317     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         0056631d     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00566323     MOV        AL,DL
    //         00566325     MOV        dword ptr [EDI + -0x1],EAX
    //         00566328     ADD        EDI,0x3
    //         0056632b     SUB        ECX,0x4
    //                               LAB_0056632e                                                 XREF[1]:     0056635c(j)  
    //         0056632e     MOV        EAX,dword ptr [EDI]
    //         00566330     MOV        DL,AL
    //         00566332     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00566335     MOV        DL,AH
    //         00566337     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056633a     BSWAP      EAX
    //         0056633c     MOV        DL,AL
    //         0056633e     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00566341     MOV        DL,AH
    //         00566343     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00566346     BSWAP      EAX
    //         00566348     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         0056634e     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00566354     MOV        dword ptr [EDI],EAX
    //         00566356     ADD        EDI,0x4
    //         00566359     SUB        ECX,0x4
    //         0056635c     JA         LAB_0056632e
    //         0056635e     MOV        DL,byte ptr [EDI]
    //         00566360     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00566363     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00566369     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056636f     MOV        byte ptr [EDI],AL
    //         00566371     INC        EDI
    //         00566372     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00566378
undefined FUN_00566378() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00566378()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00566378
    //         00566378     SUB        ECX,0x2
    //                               LAB_0056637b                                                 XREF[1]:     005663a9(j)  
    //         0056637b     MOV        EAX,dword ptr [EDI]
    //         0056637d     MOV        DL,AL
    //         0056637f     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00566382     MOV        DL,AH
    //         00566384     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00566387     BSWAP      EAX
    //         00566389     MOV        DL,AL
    //         0056638b     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056638e     MOV        DL,AH
    //         00566390     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00566393     BSWAP      EAX
    //         00566395     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         0056639b     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005663a1     MOV        dword ptr [EDI],EAX
    //         005663a3     ADD        EDI,0x4
    //         005663a6     SUB        ECX,0x4
    //         005663a9     JA         LAB_0056637b
    //         005663ab     MOV        AX,word ptr [EDI]
    //         005663ae     MOV        DL,AL
    //         005663b0     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005663b3     MOV        DL,AH
    //         005663b5     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005663b8     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         005663be     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005663c4     MOV        word ptr [EDI],AX
    //         005663c7     ADD        EDI,0x2
    //         005663ca     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005663D0
undefined FUN_005663d0() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005663d0()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005663d0
    //         005663d0     MOV        DL,byte ptr [EDI]
    //         005663d2     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005663d5     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         005663db     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005663e1     MOV        byte ptr [EDI],AH
    //         005663e3     INC        EDI
    //         005663e4     SUB        ECX,0x3
    //                               LAB_005663e7                                                 XREF[1]:     00566415(j)  
    //         005663e7     MOV        EAX,dword ptr [EDI]
    //         005663e9     MOV        DL,AL
    //         005663eb     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005663ee     MOV        DL,AH
    //         005663f0     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005663f3     BSWAP      EAX
    //         005663f5     MOV        DL,AL
    //         005663f7     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005663fa     MOV        DL,AH
    //         005663fc     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005663ff     BSWAP      EAX
    //         00566401     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00566407     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056640d     MOV        dword ptr [EDI],EAX
    //         0056640f     ADD        EDI,0x4
    //         00566412     SUB        ECX,0x4
    //         00566415     JA         LAB_005663e7
    //         00566417     MOV        AX,word ptr [EDI]
    //         0056641a     MOV        DL,AL
    //         0056641c     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056641f     MOV        DL,AH
    //         00566421     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00566424     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         0056642a     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00566430     MOV        word ptr [EDI],AX
    //         00566433     ADD        EDI,0x2
    //         00566436     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x0056643C
undefined FUN_0056643c() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056643c()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056643c
    //         0056643c     MOV        AX,word ptr [EDI]
    //         0056643f     MOV        DL,AL
    //         00566441     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00566444     MOV        DL,AH
    //         00566446     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00566449     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         0056644f     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00566455     MOV        word ptr [EDI],AX
    //         00566458     ADD        EDI,0x2
    //         0056645b     SUB        ECX,0x4
    //                               LAB_0056645e                                                 XREF[1]:     0056648c(j)  
    //         0056645e     MOV        EAX,dword ptr [EDI]
    //         00566460     MOV        DL,AL
    //         00566462     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00566465     MOV        DL,AH
    //         00566467     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056646a     BSWAP      EAX
    //         0056646c     MOV        DL,AL
    //         0056646e     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00566471     MOV        DL,AH
    //         00566473     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00566476     BSWAP      EAX
    //         00566478     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         0056647e     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00566484     MOV        dword ptr [EDI],EAX
    //         00566486     ADD        EDI,0x4
    //         00566489     SUB        ECX,0x4
    //         0056648c     JA         LAB_0056645e
    //         0056648e     MOV        AX,word ptr [EDI]
    //         00566491     MOV        DL,AL
    //         00566493     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00566496     MOV        DL,AH
    //         00566498     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056649b     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         005664a1     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005664a7     MOV        word ptr [EDI],AX
    //         005664aa     ADD        EDI,0x2
    //         005664ad     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005664B3
undefined FUN_005664b3() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005664b3()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005664b3
    //         005664b3     MOV        EAX,dword ptr [EDI + -0x1]
    //         005664b6     MOV        DL,AH
    //         005664b8     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005664bb     BSWAP      EAX
    //         005664bd     MOV        DL,AH
    //         005664bf     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005664c2     MOV        DL,AL
    //         005664c4     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005664c7     BSWAP      EAX
    //         005664c9     MOV        DL,AL
    //         005664cb     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         005664d1     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005664d7     MOV        AL,DL
    //         005664d9     MOV        dword ptr [EDI + -0x1],EAX
    //         005664dc     ADD        EDI,0x3
    //         005664df     SUB        ECX,0x5
    //                               LAB_005664e2                                                 XREF[1]:     00566510(j)  
    //         005664e2     MOV        EAX,dword ptr [EDI]
    //         005664e4     MOV        DL,AL
    //         005664e6     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005664e9     MOV        DL,AH
    //         005664eb     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005664ee     BSWAP      EAX
    //         005664f0     MOV        DL,AL
    //         005664f2     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005664f5     MOV        DL,AH
    //         005664f7     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005664fa     BSWAP      EAX
    //         005664fc     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00566502     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00566508     MOV        dword ptr [EDI],EAX
    //         0056650a     ADD        EDI,0x4
    //         0056650d     SUB        ECX,0x4
    //         00566510     JA         LAB_005664e2
    //         00566512     MOV        AX,word ptr [EDI]
    //         00566515     MOV        DL,AL
    //         00566517     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056651a     MOV        DL,AH
    //         0056651c     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056651f     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00566525     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056652b     MOV        word ptr [EDI],AX
    //         0056652e     ADD        EDI,0x2
    //         00566531     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00566537
undefined FUN_00566537() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00566537()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00566537
    //         00566537     SUB        ECX,0x3
    //                               LAB_0056653a                                                 XREF[1]:     00566568(j)  
    //         0056653a     MOV        EAX,dword ptr [EDI]
    //         0056653c     MOV        DL,AL
    //         0056653e     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00566541     MOV        DL,AH
    //         00566543     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00566546     BSWAP      EAX
    //         00566548     MOV        DL,AL
    //         0056654a     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056654d     MOV        DL,AH
    //         0056654f     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00566552     BSWAP      EAX
    //         00566554     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         0056655a     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00566560     MOV        dword ptr [EDI],EAX
    //         00566562     ADD        EDI,0x4
    //         00566565     SUB        ECX,0x4
    //         00566568     JA         LAB_0056653a
    //         0056656a     MOV        EAX,dword ptr [EDI]
    //         0056656c     MOV        DL,AL
    //         0056656e     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00566571     MOV        DL,AH
    //         00566573     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00566576     BSWAP      EAX
    //         00566578     MOV        DL,AH
    //         0056657a     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056657d     MOV        DL,AL
    //         0056657f     BSWAP      EAX
    //         00566581     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00566587     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056658d     BSWAP      EAX
    //         0056658f     MOV        AL,DL
    //         00566591     BSWAP      EAX
    //         00566593     MOV        dword ptr [EDI],EAX
    //         00566595     ADD        EDI,0x3
    //         00566598     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x0056659E
undefined FUN_0056659e() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056659e()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056659e
    //         0056659e     MOV        DL,byte ptr [EDI]
    //         005665a0     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005665a3     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         005665a9     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005665af     MOV        byte ptr [EDI],AH
    //         005665b1     INC        EDI
    //         005665b2     SUB        ECX,0x4
    //                               LAB_005665b5                                                 XREF[1]:     005665e3(j)  
    //         005665b5     MOV        EAX,dword ptr [EDI]
    //         005665b7     MOV        DL,AL
    //         005665b9     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005665bc     MOV        DL,AH
    //         005665be     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005665c1     BSWAP      EAX
    //         005665c3     MOV        DL,AL
    //         005665c5     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005665c8     MOV        DL,AH
    //         005665ca     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005665cd     BSWAP      EAX
    //         005665cf     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         005665d5     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005665db     MOV        dword ptr [EDI],EAX
    //         005665dd     ADD        EDI,0x4
    //         005665e0     SUB        ECX,0x4
    //         005665e3     JA         LAB_005665b5
    //         005665e5     MOV        EAX,dword ptr [EDI]
    //         005665e7     MOV        DL,AL
    //         005665e9     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005665ec     MOV        DL,AH
    //         005665ee     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005665f1     BSWAP      EAX
    //         005665f3     MOV        DL,AH
    //         005665f5     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005665f8     MOV        DL,AL
    //         005665fa     BSWAP      EAX
    //         005665fc     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00566602     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00566608     BSWAP      EAX
    //         0056660a     MOV        AL,DL
    //         0056660c     BSWAP      EAX
    //         0056660e     MOV        dword ptr [EDI],EAX
    //         00566610     ADD        EDI,0x3
    //         00566613     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00566619
undefined FUN_00566619() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00566619()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00566619
    //         00566619     MOV        AX,word ptr [EDI]
    //         0056661c     MOV        DL,AL
    //         0056661e     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00566621     MOV        DL,AH
    //         00566623     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00566626     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         0056662c     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00566632     MOV        word ptr [EDI],AX
    //         00566635     ADD        EDI,0x2
    //         00566638     SUB        ECX,0x5
    //                               LAB_0056663b                                                 XREF[1]:     00566669(j)  
    //         0056663b     MOV        EAX,dword ptr [EDI]
    //         0056663d     MOV        DL,AL
    //         0056663f     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00566642     MOV        DL,AH
    //         00566644     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00566647     BSWAP      EAX
    //         00566649     MOV        DL,AL
    //         0056664b     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056664e     MOV        DL,AH
    //         00566650     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00566653     BSWAP      EAX
    //         00566655     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         0056665b     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00566661     MOV        dword ptr [EDI],EAX
    //         00566663     ADD        EDI,0x4
    //         00566666     SUB        ECX,0x4
    //         00566669     JA         LAB_0056663b
    //         0056666b     MOV        EAX,dword ptr [EDI]
    //         0056666d     MOV        DL,AL
    //         0056666f     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00566672     MOV        DL,AH
    //         00566674     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00566677     BSWAP      EAX
    //         00566679     MOV        DL,AH
    //         0056667b     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056667e     MOV        DL,AL
    //         00566680     BSWAP      EAX
    //         00566682     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00566688     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056668e     BSWAP      EAX
    //         00566690     MOV        AL,DL
    //         00566692     BSWAP      EAX
    //         00566694     MOV        dword ptr [EDI],EAX
    //         00566696     ADD        EDI,0x3
    //         00566699     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x0056669F
undefined FUN_0056669f() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056669f()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056669f
    //         0056669f     MOV        EAX,dword ptr [EDI + -0x1]
    //         005666a2     MOV        DL,AH
    //         005666a4     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005666a7     BSWAP      EAX
    //         005666a9     MOV        DL,AH
    //         005666ab     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005666ae     MOV        DL,AL
    //         005666b0     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005666b3     BSWAP      EAX
    //         005666b5     MOV        DL,AL
    //         005666b7     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         005666bd     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005666c3     MOV        AL,DL
    //         005666c5     MOV        dword ptr [EDI + -0x1],EAX
    //         005666c8     ADD        EDI,0x3
    //         005666cb     SUB        ECX,0x6
    //                               LAB_005666ce                                                 XREF[1]:     005666fc(j)  
    //         005666ce     MOV        EAX,dword ptr [EDI]
    //         005666d0     MOV        DL,AL
    //         005666d2     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005666d5     MOV        DL,AH
    //         005666d7     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005666da     BSWAP      EAX
    //         005666dc     MOV        DL,AL
    //         005666de     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005666e1     MOV        DL,AH
    //         005666e3     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005666e6     BSWAP      EAX
    //         005666e8     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         005666ee     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005666f4     MOV        dword ptr [EDI],EAX
    //         005666f6     ADD        EDI,0x4
    //         005666f9     SUB        ECX,0x4
    //         005666fc     JA         LAB_005666ce
    //         005666fe     MOV        EAX,dword ptr [EDI]
    //         00566700     MOV        DL,AL
    //         00566702     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00566705     MOV        DL,AH
    //         00566707     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056670a     BSWAP      EAX
    //         0056670c     MOV        DL,AH
    //         0056670e     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00566711     MOV        DL,AL
    //         00566713     BSWAP      EAX
    //         00566715     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         0056671b     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00566721     BSWAP      EAX
    //         00566723     MOV        AL,DL
    //         00566725     BSWAP      EAX
    //         00566727     MOV        dword ptr [EDI],EAX
    //         00566729     ADD        EDI,0x3
    //         0056672c     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00566732
undefined FUN_00566732() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00566732()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00566732
    //         00566732     MOV        AL,byte ptr [ESI]
    //         00566734     MOV        byte ptr [EDI],AL
    //         00566736     INC        ESI
    //         00566737     INC        EDI
    //         00566738     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x0056673E
undefined FUN_0056673e() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056673e()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056673e
    //         0056673e     MOV        EAX,dword ptr [ESI]
    //         00566740     MOV        byte ptr [EDI],AL
    //         00566742     ADD        ESI,0x2
    //         00566745     MOV        byte ptr [EDI + 0x2],AH
    //         00566748     ADD        EDI,0x3
    //         0056674b     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00566751
undefined FUN_00566751() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00566751()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00566751
    //         00566751     MOV        EAX,dword ptr [ESI]
    //         00566753     MOV        byte ptr [EDI],AL
    //         00566755     ADD        ESI,0x3
    //         00566758     MOV        byte ptr [EDI + 0x2],AH
    //         0056675b     SHR        EAX,0x10
    //         0056675e     MOV        byte ptr [EDI + 0x4],AL
    //         00566761     ADD        EDI,0x5
    //         00566764     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x0056676A
undefined FUN_0056676a() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056676a()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056676a
    //         0056676a     MOV        EAX,dword ptr [ESI]
    //         0056676c     MOV        byte ptr [EDI],AL
    //         0056676e     ADD        ESI,0x4
    //         00566771     MOV        byte ptr [EDI + 0x2],AH
    //         00566774     SHR        EAX,0x10
    //         00566777     MOV        byte ptr [EDI + 0x4],AL
    //         0056677a     MOV        byte ptr [EDI + 0x6],AH
    //         0056677d     ADD        EDI,0x7
    //         00566780     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00566786
undefined FUN_00566786() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00566786()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00566786
    //         00566786     MOV        AL,byte ptr [ESI]
    //         00566788     INC        ESI
    //         00566789     MOV        byte ptr [EDI],AL
    //         0056678b     DEC        EDI
    //         0056678c     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00566792
undefined FUN_00566792() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00566792()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00566792
    //         00566792     MOV        EAX,dword ptr [ESI]
    //         00566794     ADD        ESI,0x2
    //         00566797     MOV        byte ptr [EDI],AL
    //         00566799     MOV        byte ptr [EDI + -0x1],AH
    //         0056679c     SUB        EDI,0x2
    //         0056679f     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005667A5
undefined FUN_005667a5() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005667a5()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005667a5
    //         005667a5     MOV        EAX,dword ptr [ESI]
    //         005667a7     ADD        ESI,0x3
    //         005667aa     MOV        byte ptr [EDI],AL
    //         005667ac     MOV        byte ptr [EDI + -0x1],AH
    //         005667af     SHR        EAX,0x10
    //         005667b2     MOV        byte ptr [EDI + -0x2],AL
    //         005667b5     SUB        EDI,0x3
    //         005667b8     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005667BE
undefined FUN_005667be() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005667be()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005667be
    //         005667be     MOV        EAX,dword ptr [ESI]
    //         005667c0     ADD        ESI,0x4
    //         005667c3     BSWAP      EAX
    //         005667c5     MOV        dword ptr [EDI + -0x3],EAX
    //         005667c8     SUB        EDI,0x4
    //         005667cb     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005667D1
undefined FUN_005667d1() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005667d1()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005667d1
    //         005667d1     MOV        EAX,dword ptr [ESI]
    //         005667d3     ADD        ESI,0x4
    //         005667d6     MOV        byte ptr [EDI],AL
    //         005667d8     MOV        byte ptr [EDI + -0x1],AH
    //         005667db     SHR        EAX,0x10
    //         005667de     MOV        byte ptr [EDI + -0x2],AL
    //         005667e1     MOV        byte ptr [EDI + -0x3],AH
    //         005667e4     SUB        EDI,0x4
    //         005667e7     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005667ED
undefined FUN_005667ed() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005667ed()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005667ed
    //         005667ed     MOV        EAX,dword ptr [ESI]
    //         005667ef     MOV        BL,byte ptr [ESI + 0x4]
    //         005667f2     BSWAP      EAX
    //         005667f4     MOV        dword ptr [EDI + -0x3],EAX
    //         005667f7     ADD        ESI,0x5
    //         005667fa     MOV        byte ptr [EDI + -0x4],BL
    //         005667fd     SUB        EDI,0x5
    //         00566800     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00566806
undefined FUN_00566806() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00566806()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00566806
    //         00566806     MOV        EAX,dword ptr [ESI]
    //         00566808     MOV        BL,byte ptr [ESI + 0x4]
    //         0056680b     MOV        byte ptr [EDI],AL
    //         0056680d     MOV        byte ptr [EDI + -0x4],BL
    //         00566810     MOV        byte ptr [EDI + -0x1],AH
    //         00566813     SHR        EAX,0x10
    //         00566816     MOV        byte ptr [EDI + -0x2],AL
    //         00566819     ADD        ESI,0x5
    //         0056681c     MOV        byte ptr [EDI + -0x3],AH
    //         0056681f     SUB        EDI,0x5
    //         00566822     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00566828
undefined FUN_00566828() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00566828()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00566828
    //         00566828     MOV        BL,byte ptr [ESI]
    //         0056682a     MOV        EAX,dword ptr [ESI + 0x1]
    //         0056682d     BSWAP      EAX
    //         0056682f     MOV        byte ptr [EDI],BL
    //         00566831     ADD        ESI,0x5
    //         00566834     MOV        dword ptr [EDI + -0x4],EAX
    //         00566837     SUB        EDI,0x5
    //         0056683a     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00566840
undefined FUN_00566840() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00566840()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00566840
    //         00566840     MOV        EAX,dword ptr [ESI]
    //         00566842     MOV        EBX,dword ptr [ESI + 0x4]
    //         00566845     BSWAP      EAX
    //         00566847     MOV        dword ptr [EDI + -0x3],EAX
    //         0056684a     MOV        byte ptr [EDI + -0x4],BL
    //         0056684d     ADD        ESI,0x6
    //         00566850     MOV        byte ptr [EDI + DAT_fffffffb],BH
    //         00566853     SUB        EDI,0x6
    //         00566856     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x0056685C
undefined FUN_0056685c() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056685c()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056685c
    //         0056685c     MOV        EAX,dword ptr [ESI]
    //         0056685e     MOV        EBX,dword ptr [ESI + 0x4]
    //         00566861     MOV        byte ptr [EDI + DAT_fffffffb],BH
    //         00566864     MOV        byte ptr [EDI + -0x1],AH
    //         00566867     MOV        byte ptr [EDI + -0x4],BL
    //         0056686a     MOV        byte ptr [EDI],AL
    //         0056686c     SHR        EAX,0x10
    //         0056686f     MOV        byte ptr [EDI + -0x2],AL
    //         00566872     ADD        ESI,0x6
    //         00566875     MOV        byte ptr [EDI + -0x3],AH
    //         00566878     SUB        EDI,0x6
    //         0056687b     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00566881
undefined FUN_00566881() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00566881()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00566881
    //         00566881     MOV        EAX,dword ptr [ESI]
    //         00566883     MOV        EBX,dword ptr [ESI + 0x2]
    //         00566886     BSWAP      EBX
    //         00566888     MOV        byte ptr [EDI],AL
    //         0056688a     ADD        ESI,0x6
    //         0056688d     MOV        byte ptr [EDI + -0x1],AH
    //         00566890     MOV        dword ptr [EDI + DAT_fffffffb],EBX
    //         00566893     SUB        EDI,0x6
    //         00566896     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x0056689C
undefined FUN_0056689c() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056689c()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056689c
    //         0056689c     MOV        BL,byte ptr [ESI]
    //         0056689e     MOV        BH,byte ptr [ESI + 0x5]
    //         005668a1     MOV        EAX,dword ptr [ESI + 0x1]
    //         005668a4     MOV        byte ptr [EDI],BL
    //         005668a6     BSWAP      EAX
    //         005668a8     MOV        dword ptr [EDI + -0x4],EAX
    //         005668ab     ADD        ESI,0x6
    //         005668ae     MOV        byte ptr [EDI + DAT_fffffffb],BH
    //         005668b1     SUB        EDI,0x6
    //         005668b4     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005668BA
undefined FUN_005668ba() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005668ba()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005668ba
    //         005668ba     MOV        EAX,dword ptr [ESI]
    //         005668bc     MOV        EBX,dword ptr [ESI + 0x4]
    //         005668bf     BSWAP      EAX
    //         005668c1     MOV        byte ptr [EDI + -0x4],BL
    //         005668c4     MOV        dword ptr [EDI + -0x3],EAX
    //         005668c7     SHR        EBX,0x8
    //         005668ca     ADD        ESI,0x7
    //         005668cd     MOV        byte ptr [EDI + DAT_fffffffb],BL
    //         005668d0     MOV        byte ptr [EDI + DAT_fffffffa],BH
    //         005668d3     SUB        EDI,0x7
    //         005668d6     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005668DC
undefined FUN_005668dc() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005668dc()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005668dc
    //         005668dc     MOV        EAX,dword ptr [ESI + -0x1]
    //         005668df     MOV        EBX,dword ptr [ESI + 0x3]
    //         005668e2     MOV        byte ptr [EDI],AH
    //         005668e4     SHR        EAX,0x10
    //         005668e7     MOV        byte ptr [EDI + -0x1],AL
    //         005668ea     ADD        ESI,0x7
    //         005668ed     MOV        byte ptr [EDI + -0x2],AH
    //         005668f0     BSWAP      EBX
    //         005668f2     MOV        dword ptr [EDI + DAT_fffffffa],EBX
    //         005668f5     SUB        EDI,0x7
    //         005668f8     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005668FE
undefined FUN_005668fe() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005668fe()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005668fe
    //         005668fe     MOV        EAX,dword ptr [ESI + 0x2]
    //         00566901     BSWAP      EAX
    //         00566903     MOV        dword ptr [EDI + DAT_fffffffb],EAX
    //         00566906     MOV        EAX,dword ptr [ESI]
    //         00566908     MOV        BL,byte ptr [ESI + 0x6]
    //         0056690b     MOV        byte ptr [EDI],AL
    //         0056690d     MOV        byte ptr [EDI + DAT_fffffffa],BL
    //         00566910     MOV        byte ptr [EDI + -0x1],AH
    //         00566913     ADD        ESI,0x7
    //         00566916     SUB        EDI,0x7
    //         00566919     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x0056691F
undefined FUN_0056691f() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056691f()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056691f
    //         0056691f     MOV        EAX,dword ptr [ESI + 0x1]
    //         00566922     MOV        BL,byte ptr [ESI]
    //         00566924     BSWAP      EAX
    //         00566926     MOV        byte ptr [EDI],BL
    //         00566928     MOV        EBX,dword ptr [ESI + 0x5]
    //         0056692b     MOV        dword ptr [EDI + -0x4],EAX
    //         0056692e     ADD        ESI,0x7
    //         00566931     MOV        byte ptr [EDI + DAT_fffffffb],BL
    //         00566934     MOV        byte ptr [EDI + DAT_fffffffa],BH
    //         00566937     SUB        EDI,0x7
    //         0056693a     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00566940
undefined FUN_00566940() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00566940()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00566940                                                 XREF[1]:     00566950(j)  
    //         00566940     MOV        EAX,dword ptr [ESI]
    //         00566942     ADD        ESI,0x4
    //         00566945     BSWAP      EAX
    //         00566947     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff9
    //         0056694a     SUB        EDI,0x4
    //         0056694d     SUB        ECX,0x4
    //         00566950     JA         FUN_00566940
    //         00566952     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00566958
undefined FUN_00566958() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00566958()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00566958
    //         00566958     MOV        AL,byte ptr [ESI]
    //         0056695a     INC        ESI
    //         0056695b     MOV        byte ptr [EDI],AL
    //         0056695d     DEC        EDI
    //         0056695e     DEC        ECX
    //                               LAB_0056695f                                                 XREF[1]:     0056696f(j)  
    //         0056695f     MOV        EAX,dword ptr [ESI]
    //         00566961     ADD        ESI,0x4
    //         00566964     BSWAP      EAX
    //         00566966     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff8
    //         00566969     SUB        EDI,0x4
    //         0056696c     SUB        ECX,0x4
    //         0056696f     JA         LAB_0056695f
    //         00566971     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00566977
undefined FUN_00566977() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00566977()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00566977
    //         00566977     MOV        EAX,dword ptr [ESI]
    //         00566979     ADD        ESI,0x2
    //         0056697c     MOV        byte ptr [EDI],AL
    //         0056697e     MOV        byte ptr [EDI + -0x1],AH
    //         00566981     SUB        EDI,0x2
    //         00566984     SUB        ECX,0x2
    //                               LAB_00566987                                                 XREF[1]:     00566997(j)  
    //         00566987     MOV        EAX,dword ptr [ESI]
    //         00566989     ADD        ESI,0x4
    //         0056698c     BSWAP      EAX
    //         0056698e     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffb
    //         00566991     SUB        EDI,0x4
    //         00566994     SUB        ECX,0x4
    //         00566997     JA         LAB_00566987
    //         00566999     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x0056699F
undefined FUN_0056699f() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056699f()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056699f
    //         0056699f     MOV        EAX,dword ptr [ESI]
    //         005669a1     ADD        ESI,0x3
    //         005669a4     MOV        byte ptr [EDI],AL
    //         005669a6     MOV        byte ptr [EDI + -0x1],AH
    //         005669a9     SHR        EAX,0x10
    //         005669ac     MOV        byte ptr [EDI + -0x2],AL
    //         005669af     SUB        EDI,0x3
    //         005669b2     SUB        ECX,0x3
    //                               LAB_005669b5                                                 XREF[1]:     005669c5(j)  
    //         005669b5     MOV        EAX,dword ptr [ESI]
    //         005669b7     ADD        ESI,0x4
    //         005669ba     BSWAP      EAX
    //         005669bc     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffa
    //         005669bf     SUB        EDI,0x4
    //         005669c2     SUB        ECX,0x4
    //         005669c5     JA         LAB_005669b5
    //         005669c7     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005669CD
undefined FUN_005669cd() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005669cd()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005669cd
    //         005669cd     DEC        ECX
    //                               LAB_005669ce                                                 XREF[1]:     005669de(j)  
    //         005669ce     MOV        EAX,dword ptr [ESI]
    //         005669d0     ADD        ESI,0x4
    //         005669d3     BSWAP      EAX
    //         005669d5     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff9
    //         005669d8     SUB        EDI,0x4
    //         005669db     SUB        ECX,0x4
    //         005669de     JA         LAB_005669ce
    //         005669e0     MOV        AL,byte ptr [ESI]
    //         005669e2     INC        ESI
    //         005669e3     MOV        byte ptr [EDI],AL=>DAT_fffffff8
    //         005669e5     DEC        EDI
    //         005669e6     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005669EC
undefined FUN_005669ec() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005669ec()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005669ec
    //         005669ec     MOV        AL,byte ptr [ESI]
    //         005669ee     INC        ESI
    //         005669ef     MOV        byte ptr [EDI],AL
    //         005669f1     DEC        EDI
    //         005669f2     SUB        ECX,0x2
    //                               LAB_005669f5                                                 XREF[1]:     00566a05(j)  
    //         005669f5     MOV        EAX,dword ptr [ESI]
    //         005669f7     ADD        ESI,0x4
    //         005669fa     BSWAP      EAX
    //         005669fc     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff8
    //         005669ff     SUB        EDI,0x4
    //         00566a02     SUB        ECX,0x4
    //         00566a05     JA         LAB_005669f5
    //         00566a07     MOV        AL,byte ptr [ESI]
    //         00566a09     INC        ESI
    //         00566a0a     MOV        byte ptr [EDI],AL=>DAT_fffffffb
    //         00566a0c     DEC        EDI
    //         00566a0d     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00566A13
undefined FUN_00566a13() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00566a13()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00566a13
    //         00566a13     MOV        EAX,dword ptr [ESI]
    //         00566a15     ADD        ESI,0x2
    //         00566a18     MOV        byte ptr [EDI],AL
    //         00566a1a     MOV        byte ptr [EDI + -0x1],AH
    //         00566a1d     SUB        EDI,0x2
    //         00566a20     SUB        ECX,0x3
    //                               LAB_00566a23                                                 XREF[1]:     00566a33(j)  
    //         00566a23     MOV        EAX,dword ptr [ESI]
    //         00566a25     ADD        ESI,0x4
    //         00566a28     BSWAP      EAX
    //         00566a2a     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffb
    //         00566a2d     SUB        EDI,0x4
    //         00566a30     SUB        ECX,0x4
    //         00566a33     JA         LAB_00566a23
    //         00566a35     MOV        AL,byte ptr [ESI]
    //         00566a37     INC        ESI
    //         00566a38     MOV        byte ptr [EDI],AL=>DAT_fffffffa
    //         00566a3a     DEC        EDI
    //         00566a3b     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00566A41
undefined FUN_00566a41() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00566a41()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00566a41
    //         00566a41     MOV        EAX,dword ptr [ESI]
    //         00566a43     ADD        ESI,0x3
    //         00566a46     MOV        byte ptr [EDI],AL
    //         00566a48     MOV        byte ptr [EDI + -0x1],AH
    //         00566a4b     SHR        EAX,0x10
    //         00566a4e     MOV        byte ptr [EDI + -0x2],AL
    //         00566a51     SUB        EDI,0x3
    //         00566a54     SUB        ECX,0x4
    //                               LAB_00566a57                                                 XREF[1]:     00566a67(j)  
    //         00566a57     MOV        EAX,dword ptr [ESI]
    //         00566a59     ADD        ESI,0x4
    //         00566a5c     BSWAP      EAX
    //         00566a5e     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffa
    //         00566a61     SUB        EDI,0x4
    //         00566a64     SUB        ECX,0x4
    //         00566a67     JA         LAB_00566a57
    //         00566a69     MOV        AL,byte ptr [ESI]
    //         00566a6b     INC        ESI
    //         00566a6c     MOV        byte ptr [EDI],AL=>DAT_fffffff9
    //         00566a6e     DEC        EDI
    //         00566a6f     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00566A75
undefined FUN_00566a75() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00566a75()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00566a75
    //         00566a75     SUB        ECX,0x2
    //                               LAB_00566a78                                                 XREF[1]:     00566a88(j)  
    //         00566a78     MOV        EAX,dword ptr [ESI]
    //         00566a7a     ADD        ESI,0x4
    //         00566a7d     BSWAP      EAX
    //         00566a7f     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff9
    //         00566a82     SUB        EDI,0x4
    //         00566a85     SUB        ECX,0x4
    //         00566a88     JA         LAB_00566a78
    //         00566a8a     MOV        EAX,dword ptr [ESI]
    //         00566a8c     ADD        ESI,0x2
    //         00566a8f     MOV        byte ptr [EDI],AL=>DAT_fffffff8
    //         00566a91     MOV        byte ptr [EDI + -0x1],AH=>DAT_fffffffb
    //         00566a94     SUB        EDI,0x2
    //         00566a97     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00566A9D
undefined FUN_00566a9d() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00566a9d()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00566a9d
    //         00566a9d     MOV        AL,byte ptr [ESI]
    //         00566a9f     INC        ESI
    //         00566aa0     MOV        byte ptr [EDI],AL
    //         00566aa2     DEC        EDI
    //         00566aa3     SUB        ECX,0x3
    //                               LAB_00566aa6                                                 XREF[1]:     00566ab6(j)  
    //         00566aa6     MOV        EAX,dword ptr [ESI]
    //         00566aa8     ADD        ESI,0x4
    //         00566aab     BSWAP      EAX
    //         00566aad     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff8
    //         00566ab0     SUB        EDI,0x4
    //         00566ab3     SUB        ECX,0x4
    //         00566ab6     JA         LAB_00566aa6
    //         00566ab8     MOV        EAX,dword ptr [ESI]
    //         00566aba     ADD        ESI,0x2
    //         00566abd     MOV        byte ptr [EDI],AL=>DAT_fffffffb
    //         00566abf     MOV        byte ptr [EDI + -0x1],AH=>DAT_fffffffa
    //         00566ac2     SUB        EDI,0x2
    //         00566ac5     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00566ACB
undefined FUN_00566acb() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00566acb()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00566acb
    //         00566acb     MOV        EAX,dword ptr [ESI]
    //         00566acd     ADD        ESI,0x2
    //         00566ad0     MOV        byte ptr [EDI],AL
    //         00566ad2     MOV        byte ptr [EDI + -0x1],AH
    //         00566ad5     SUB        EDI,0x2
    //         00566ad8     SUB        ECX,0x4
    //                               LAB_00566adb                                                 XREF[1]:     00566aeb(j)  
    //         00566adb     MOV        EAX,dword ptr [ESI]
    //         00566add     ADD        ESI,0x4
    //         00566ae0     BSWAP      EAX
    //         00566ae2     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffb
    //         00566ae5     SUB        EDI,0x4
    //         00566ae8     SUB        ECX,0x4
    //         00566aeb     JA         LAB_00566adb
    //         00566aed     MOV        EAX,dword ptr [ESI]
    //         00566aef     ADD        ESI,0x2
    //         00566af2     MOV        byte ptr [EDI],AL=>DAT_fffffffa
    //         00566af4     MOV        byte ptr [EDI + -0x1],AH=>DAT_fffffff9
    //         00566af7     SUB        EDI,0x2
    //         00566afa     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00566B00
undefined FUN_00566b00() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00566b00()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00566b00
    //         00566b00     MOV        EAX,dword ptr [ESI]
    //         00566b02     ADD        ESI,0x3
    //         00566b05     MOV        byte ptr [EDI],AL
    //         00566b07     MOV        byte ptr [EDI + -0x1],AH
    //         00566b0a     SHR        EAX,0x10
    //         00566b0d     MOV        byte ptr [EDI + -0x2],AL
    //         00566b10     SUB        EDI,0x3
    //         00566b13     SUB        ECX,0x5
    //                               LAB_00566b16                                                 XREF[1]:     00566b26(j)  
    //         00566b16     MOV        EAX,dword ptr [ESI]
    //         00566b18     ADD        ESI,0x4
    //         00566b1b     BSWAP      EAX
    //         00566b1d     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffa
    //         00566b20     SUB        EDI,0x4
    //         00566b23     SUB        ECX,0x4
    //         00566b26     JA         LAB_00566b16
    //         00566b28     MOV        EAX,dword ptr [ESI]
    //         00566b2a     ADD        ESI,0x2
    //         00566b2d     MOV        byte ptr [EDI],AL=>DAT_fffffff9
    //         00566b2f     MOV        byte ptr [EDI + -0x1],AH=>DAT_fffffff8
    //         00566b32     SUB        EDI,0x2
    //         00566b35     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00566B3B
undefined FUN_00566b3b() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00566b3b()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00566b3b
    //         00566b3b     SUB        ECX,0x3
    //                               LAB_00566b3e                                                 XREF[1]:     00566b4e(j)  
    //         00566b3e     MOV        EAX,dword ptr [ESI]
    //         00566b40     ADD        ESI,0x4
    //         00566b43     BSWAP      EAX
    //         00566b45     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff9
    //         00566b48     SUB        EDI,0x4
    //         00566b4b     SUB        ECX,0x4
    //         00566b4e     JA         LAB_00566b3e
    //         00566b50     MOV        EAX,dword ptr [ESI]
    //         00566b52     ADD        ESI,0x3
    //         00566b55     MOV        byte ptr [EDI],AL=>DAT_fffffff8
    //         00566b57     MOV        byte ptr [EDI + -0x1],AH=>DAT_fffffffb
    //         00566b5a     SHR        EAX,0x10
    //         00566b5d     MOV        byte ptr [EDI + -0x2],AL=>DAT_fffffffa
    //         00566b60     SUB        EDI,0x3
    //         00566b63     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00566B69
undefined FUN_00566b69() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00566b69()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00566b69
    //         00566b69     MOV        AL,byte ptr [ESI]
    //         00566b6b     INC        ESI
    //         00566b6c     MOV        byte ptr [EDI],AL
    //         00566b6e     DEC        EDI
    //         00566b6f     SUB        ECX,0x4
    //                               LAB_00566b72                                                 XREF[1]:     00566b82(j)  
    //         00566b72     MOV        EAX,dword ptr [ESI]
    //         00566b74     ADD        ESI,0x4
    //         00566b77     BSWAP      EAX
    //         00566b79     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff8
    //         00566b7c     SUB        EDI,0x4
    //         00566b7f     SUB        ECX,0x4
    //         00566b82     JA         LAB_00566b72
    //         00566b84     MOV        EAX,dword ptr [ESI]
    //         00566b86     ADD        ESI,0x3
    //         00566b89     MOV        byte ptr [EDI],AL=>DAT_fffffffb
    //         00566b8b     MOV        byte ptr [EDI + -0x1],AH=>DAT_fffffffa
    //         00566b8e     SHR        EAX,0x10
    //         00566b91     MOV        byte ptr [EDI + -0x2],AL=>DAT_fffffff9
    //         00566b94     SUB        EDI,0x3
    //         00566b97     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00566B9D
undefined FUN_00566b9d() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00566b9d()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00566b9d
    //         00566b9d     MOV        EAX,dword ptr [ESI]
    //         00566b9f     ADD        ESI,0x2
    //         00566ba2     MOV        byte ptr [EDI],AL
    //         00566ba4     MOV        byte ptr [EDI + -0x1],AH
    //         00566ba7     SUB        EDI,0x2
    //         00566baa     SUB        ECX,0x5
    //                               LAB_00566bad                                                 XREF[1]:     00566bbd(j)  
    //         00566bad     MOV        EAX,dword ptr [ESI]
    //         00566baf     ADD        ESI,0x4
    //         00566bb2     BSWAP      EAX
    //         00566bb4     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffb
    //         00566bb7     SUB        EDI,0x4
    //         00566bba     SUB        ECX,0x4
    //         00566bbd     JA         LAB_00566bad
    //         00566bbf     MOV        EAX,dword ptr [ESI]
    //         00566bc1     ADD        ESI,0x3
    //         00566bc4     MOV        byte ptr [EDI],AL=>DAT_fffffffa
    //         00566bc6     MOV        byte ptr [EDI + -0x1],AH=>DAT_fffffff9
    //         00566bc9     SHR        EAX,0x10
    //         00566bcc     MOV        byte ptr [EDI + -0x2],AL=>DAT_fffffff8
    //         00566bcf     SUB        EDI,0x3
    //         00566bd2     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00566BD8
undefined FUN_00566bd8() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00566bd8()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00566bd8
    //         00566bd8     MOV        EAX,dword ptr [ESI]
    //         00566bda     ADD        ESI,0x3
    //         00566bdd     MOV        byte ptr [EDI],AL
    //         00566bdf     MOV        byte ptr [EDI + -0x1],AH
    //         00566be2     SHR        EAX,0x10
    //         00566be5     MOV        byte ptr [EDI + -0x2],AL
    //         00566be8     SUB        EDI,0x3
    //         00566beb     SUB        ECX,0x6
    //                               LAB_00566bee                                                 XREF[1]:     00566bfe(j)  
    //         00566bee     MOV        EAX,dword ptr [ESI]
    //         00566bf0     ADD        ESI,0x4
    //         00566bf3     BSWAP      EAX
    //         00566bf5     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffa
    //         00566bf8     SUB        EDI,0x4
    //         00566bfb     SUB        ECX,0x4
    //         00566bfe     JA         LAB_00566bee
    //         00566c00     MOV        EAX,dword ptr [ESI]
    //         00566c02     ADD        ESI,0x3
    //         00566c05     MOV        byte ptr [EDI],AL=>DAT_fffffff9
    //         00566c07     MOV        byte ptr [EDI + -0x1],AH=>DAT_fffffff8
    //         00566c0a     SHR        EAX,0x10
    //         00566c0d     MOV        byte ptr [EDI + -0x2],AL=>DAT_fffffff7
    //         00566c10     SUB        EDI,0x3
    //         00566c13     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00566C19
undefined FUN_00566c19() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00566c19()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00566c19
    //         00566c19     MOV        AL,byte ptr [ESI]
    //         00566c1b     INC        ESI
    //         00566c1c     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00566c22     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00566c28     MOV        byte ptr [EDI],AL
    //         00566c2a     DEC        EDI
    //         00566c2b     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00566C31
undefined FUN_00566c31() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00566c31()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00566c31
    //         00566c31     MOV        AH,byte ptr [ESI]
    //         00566c33     INC        ESI
    //         00566c34     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00566c3a     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00566c40     MOV        byte ptr [EDI],AH
    //         00566c42     DEC        EDI
    //         00566c43     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00566C49
undefined FUN_00566c49() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00566c49()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00566c49
    //         00566c49     MOV        EAX,dword ptr [ESI]
    //         00566c4b     ADD        ESI,0x2
    //         00566c4e     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00566c54     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00566c5a     MOV        byte ptr [EDI],AL
    //         00566c5c     MOV        byte ptr [EDI + -0x1],AH
    //         00566c5f     SUB        EDI,0x2
    //         00566c62     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00566C68
undefined FUN_00566c68() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00566c68()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00566c68
    //         00566c68     MOV        EAX,dword ptr [ESI + -0x1]
    //         00566c6b     ADD        ESI,0x2
    //         00566c6e     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00566c74     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00566c7a     SHR        EAX,0x8
    //         00566c7d     MOV        byte ptr [EDI],AL
    //         00566c7f     MOV        byte ptr [EDI + -0x1],AH
    //         00566c82     SUB        EDI,0x2
    //         00566c85     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00566C8B
undefined FUN_00566c8b() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00566c8b()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00566c8b
    //         00566c8b     MOV        EAX,dword ptr [ESI]
    //         00566c8d     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00566c93     ADD        ESI,0x2
    //         00566c96     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00566c9c     MOV        byte ptr [EDI],AL
    //         00566c9e     MOV        byte ptr [EDI + -0x1],AH
    //         00566ca1     SUB        EDI,0x2
    //         00566ca4     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00566CAA
undefined FUN_00566caa() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00566caa()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00566caa
    //         00566caa     MOV        EAX,dword ptr [ESI]
    //         00566cac     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00566cb2     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00566cb8     MOV        byte ptr [EDI],AL
    //         00566cba     MOV        byte ptr [EDI + -0x1],AH
    //         00566cbd     SHR        EAX,0x10
    //         00566cc0     MOV        byte ptr [EDI + -0x2],AL
    //         00566cc3     ADD        ESI,0x3
    //         00566cc6     SUB        EDI,0x3
    //         00566cc9     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00566CCF
undefined FUN_00566ccf() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00566ccf()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00566ccf
    //         00566ccf     MOV        EAX,dword ptr [ESI + -0x1]
    //         00566cd2     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00566cd8     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00566cde     MOV        byte ptr [EDI],AH
    //         00566ce0     SHR        EAX,0x10
    //         00566ce3     MOV        byte ptr [EDI + -0x1],AL
    //         00566ce6     MOV        byte ptr [EDI + -0x2],AH
    //         00566ce9     ADD        ESI,0x3
    //         00566cec     SUB        EDI,0x3
    //         00566cef     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00566CF5
undefined FUN_00566cf5() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00566cf5()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00566cf5
    //         00566cf5     MOV        EAX,dword ptr [ESI + -0x1]
    //         00566cf8     ADD        ESI,0x2
    //         00566cfb     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00566d01     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00566d07     SHR        EAX,0x8
    //         00566d0a     MOV        byte ptr [EDI],AL
    //         00566d0c     MOV        byte ptr [EDI + -0x1],AH
    //         00566d0f     SUB        EDI,0x2
    //         00566d12     MOV        AH,byte ptr [ESI]
    //         00566d14     INC        ESI
    //         00566d15     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00566d1b     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00566d21     MOV        byte ptr [EDI],AH
    //         00566d23     DEC        EDI
    //         00566d24     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00566D2A
undefined FUN_00566d2a() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00566d2a()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00566d2a
    //         00566d2a     MOV        AL,byte ptr [ESI]
    //         00566d2c     INC        ESI
    //         00566d2d     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00566d33     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00566d39     MOV        byte ptr [EDI],AL
    //         00566d3b     DEC        EDI
    //         00566d3c     MOV        EAX,dword ptr [ESI + -0x1]
    //         00566d3f     ADD        ESI,0x2
    //         00566d42     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00566d48     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00566d4e     SHR        EAX,0x8
    //         00566d51     MOV        byte ptr [EDI],AL
    //         00566d53     MOV        byte ptr [EDI + -0x1],AH
    //         00566d56     SUB        EDI,0x2
    //         00566d59     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00566D5F
undefined FUN_00566d5f() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00566d5f()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00566d5f
    //         00566d5f     MOV        EAX,dword ptr [ESI]
    //         00566d61     SUB        EDI,0x4
    //         00566d64     BSWAP      EAX
    //         00566d66     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00566d6c     ADD        ESI,0x4
    //         00566d6f     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00566d75     MOV        dword ptr [EDI + 0x1],EAX
    //         00566d78     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00566D7E
undefined FUN_00566d7e() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00566d7e()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00566d7e
    //         00566d7e     MOV        EAX,dword ptr [ESI]
    //         00566d80     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00566d86     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00566d8c     MOV        byte ptr [EDI],AL
    //         00566d8e     MOV        byte ptr [EDI + -0x1],AH
    //         00566d91     SHR        EAX,0x10
    //         00566d94     MOV        byte ptr [EDI + -0x2],AL
    //         00566d97     ADD        ESI,0x3
    //         00566d9a     SUB        EDI,0x3
    //         00566d9d     MOV        AH,byte ptr [ESI]
    //         00566d9f     INC        ESI
    //         00566da0     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00566da6     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00566dac     MOV        byte ptr [EDI],AH
    //         00566dae     DEC        EDI
    //         00566daf     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00566DB5
undefined FUN_00566db5() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00566db5()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00566db5
    //         00566db5     MOV        EAX,dword ptr [ESI + -0x1]
    //         00566db8     ADD        ESI,0x2
    //         00566dbb     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00566dc1     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00566dc7     SHR        EAX,0x8
    //         00566dca     MOV        byte ptr [EDI],AL
    //         00566dcc     MOV        byte ptr [EDI + -0x1],AH
    //         00566dcf     SUB        EDI,0x2
    //         00566dd2     MOV        EAX,dword ptr [ESI + -0x1]
    //         00566dd5     ADD        ESI,0x2
    //         00566dd8     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00566dde     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00566de4     SHR        EAX,0x8
    //         00566de7     MOV        byte ptr [EDI],AL
    //         00566de9     MOV        byte ptr [EDI + -0x1],AH
    //         00566dec     SUB        EDI,0x2
    //         00566def     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00566DF5
undefined FUN_00566df5() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00566df5()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00566df5
    //         00566df5     MOV        AL,byte ptr [ESI]
    //         00566df7     INC        ESI
    //         00566df8     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00566dfe     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00566e04     MOV        byte ptr [EDI],AL
    //         00566e06     DEC        EDI
    //         00566e07     MOV        EAX,dword ptr [ESI + -0x1]
    //         00566e0a     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00566e10     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00566e16     MOV        byte ptr [EDI],AH
    //         00566e18     SHR        EAX,0x10
    //         00566e1b     MOV        byte ptr [EDI + -0x1],AL
    //         00566e1e     MOV        byte ptr [EDI + -0x2],AH
    //         00566e21     ADD        ESI,0x3
    //         00566e24     SUB        EDI,0x3
    //         00566e27     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00566E2D
undefined FUN_00566e2d() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00566e2d()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00566e2d
    //         00566e2d     MOV        EAX,dword ptr [ESI]
    //         00566e2f     SUB        EDI,0x4
    //         00566e32     BSWAP      EAX
    //         00566e34     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00566e3a     ADD        ESI,0x4
    //         00566e3d     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00566e43     MOV        dword ptr [EDI + 0x1],EAX
    //         00566e46     MOV        AH,byte ptr [ESI]
    //         00566e48     INC        ESI
    //         00566e49     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00566e4f     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00566e55     MOV        byte ptr [EDI],AH
    //         00566e57     DEC        EDI
    //         00566e58     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00566E5E
undefined FUN_00566e5e() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00566e5e()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00566e5e
    //         00566e5e     MOV        EAX,dword ptr [ESI]
    //         00566e60     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00566e66     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00566e6c     MOV        byte ptr [EDI],AL
    //         00566e6e     MOV        byte ptr [EDI + -0x1],AH
    //         00566e71     SHR        EAX,0x10
    //         00566e74     MOV        byte ptr [EDI + -0x2],AL
    //         00566e77     ADD        ESI,0x3
    //         00566e7a     SUB        EDI,0x3
    //         00566e7d     MOV        EAX,dword ptr [ESI + -0x1]
    //         00566e80     ADD        ESI,0x2
    //         00566e83     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00566e89     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00566e8f     SHR        EAX,0x8
    //         00566e92     MOV        byte ptr [EDI],AL
    //         00566e94     MOV        byte ptr [EDI + -0x1],AH
    //         00566e97     SUB        EDI,0x2
    //         00566e9a     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00566EA0
undefined FUN_00566ea0() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00566ea0()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00566ea0
    //         00566ea0     MOV        EAX,dword ptr [ESI + -0x1]
    //         00566ea3     ADD        ESI,0x2
    //         00566ea6     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00566eac     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00566eb2     SHR        EAX,0x8
    //         00566eb5     MOV        byte ptr [EDI],AL
    //         00566eb7     MOV        byte ptr [EDI + -0x1],AH
    //         00566eba     SUB        EDI,0x2
    //         00566ebd     MOV        EAX,dword ptr [ESI + -0x1]
    //         00566ec0     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00566ec6     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00566ecc     MOV        byte ptr [EDI],AH
    //         00566ece     SHR        EAX,0x10
    //         00566ed1     MOV        byte ptr [EDI + -0x1],AL
    //         00566ed4     MOV        byte ptr [EDI + -0x2],AH
    //         00566ed7     ADD        ESI,0x3
    //         00566eda     SUB        EDI,0x3
    //         00566edd     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00566EE3
undefined FUN_00566ee3() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00566ee3()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00566ee3
    //         00566ee3     MOV        AL,byte ptr [ESI]
    //         00566ee5     INC        ESI
    //         00566ee6     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00566eec     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00566ef2     MOV        byte ptr [EDI],AL
    //         00566ef4     DEC        EDI
    //         00566ef5     MOV        EAX,dword ptr [ESI]
    //         00566ef7     SUB        EDI,0x4
    //         00566efa     BSWAP      EAX
    //         00566efc     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00566f02     ADD        ESI,0x4
    //         00566f05     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00566f0b     MOV        dword ptr [EDI + 0x1],EAX
    //         00566f0e     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00566F14
undefined FUN_00566f14() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00566f14()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00566f14
    //         00566f14     MOV        EAX,dword ptr [ESI]
    //         00566f16     SUB        EDI,0x4
    //         00566f19     BSWAP      EAX
    //         00566f1b     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00566f21     ADD        ESI,0x4
    //         00566f24     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00566f2a     MOV        dword ptr [EDI + 0x1],EAX
    //         00566f2d     MOV        EAX,dword ptr [ESI + -0x1]
    //         00566f30     ADD        ESI,0x2
    //         00566f33     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00566f39     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00566f3f     SHR        EAX,0x8
    //         00566f42     MOV        byte ptr [EDI],AL
    //         00566f44     MOV        byte ptr [EDI + -0x1],AH=>DAT_fffffffb
    //         00566f47     SUB        EDI,0x2
    //         00566f4a     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00566F50
undefined FUN_00566f50() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00566f50()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00566f50
    //         00566f50     MOV        EAX,dword ptr [ESI]
    //         00566f52     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00566f58     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00566f5e     MOV        byte ptr [EDI],AL
    //         00566f60     MOV        byte ptr [EDI + -0x1],AH
    //         00566f63     SHR        EAX,0x10
    //         00566f66     MOV        byte ptr [EDI + -0x2],AL
    //         00566f69     ADD        ESI,0x3
    //         00566f6c     SUB        EDI,0x3
    //         00566f6f     MOV        EAX,dword ptr [ESI + -0x1]
    //         00566f72     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00566f78     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00566f7e     MOV        byte ptr [EDI],AH
    //         00566f80     SHR        EAX,0x10
    //         00566f83     MOV        byte ptr [EDI + -0x1],AL
    //         00566f86     MOV        byte ptr [EDI + -0x2],AH=>DAT_fffffffb
    //         00566f89     ADD        ESI,0x3
    //         00566f8c     SUB        EDI,0x3
    //         00566f8f     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00566F95
undefined FUN_00566f95() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00566f95()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00566f95
    //         00566f95     MOV        EAX,dword ptr [ESI + -0x1]
    //         00566f98     ADD        ESI,0x2
    //         00566f9b     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00566fa1     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00566fa7     SHR        EAX,0x8
    //         00566faa     MOV        byte ptr [EDI],AL
    //         00566fac     MOV        byte ptr [EDI + -0x1],AH
    //         00566faf     SUB        EDI,0x2
    //         00566fb2     MOV        EAX,dword ptr [ESI]
    //         00566fb4     SUB        EDI,0x4
    //         00566fb7     BSWAP      EAX
    //         00566fb9     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00566fbf     ADD        ESI,0x4
    //         00566fc2     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00566fc8     MOV        dword ptr [EDI + 0x1],EAX=>DAT_fffffffb
    //         00566fcb     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00566FD1
undefined FUN_00566fd1() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00566fd1()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00566fd1
    //         00566fd1     MOV        AL,byte ptr [ESI]
    //         00566fd3     INC        ESI
    //         00566fd4     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00566fda     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00566fe0     MOV        byte ptr [EDI],AL
    //         00566fe2     DEC        EDI
    //         00566fe3     MOV        EAX,dword ptr [ESI]
    //         00566fe5     SUB        EDI,0x4
    //         00566fe8     BSWAP      EAX
    //         00566fea     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00566ff0     ADD        ESI,0x4
    //         00566ff3     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00566ff9     MOV        dword ptr [EDI + 0x1],EAX
    //         00566ffc     MOV        AH,byte ptr [ESI]
    //         00566ffe     INC        ESI
    //         00566fff     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567005     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         0056700b     MOV        byte ptr [EDI],AH=>DAT_fffffffb
    //         0056700d     DEC        EDI
    //         0056700e     JMP        dword ptr [DAT_0088c044]
}

