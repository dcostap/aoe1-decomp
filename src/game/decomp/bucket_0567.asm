// Auto-generated scaffold unit: bucket_0567.asm
#include "../include/common.h"

// Offset: 0x00567014
undefined FUN_00567014() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00567014()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00567014
    //         00567014     MOV        EAX,dword ptr [ESI]
    //         00567016     SUB        EDI,0x4
    //         00567019     BSWAP      EAX
    //         0056701b     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567021     ADD        ESI,0x4
    //         00567024     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         0056702a     MOV        dword ptr [EDI + 0x1],EAX
    //         0056702d     MOV        EAX,dword ptr [ESI + -0x1]
    //         00567030     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567036     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         0056703c     MOV        byte ptr [EDI],AH
    //         0056703e     SHR        EAX,0x10
    //         00567041     MOV        byte ptr [EDI + -0x1],AL=>DAT_fffffffb
    //         00567044     MOV        byte ptr [EDI + -0x2],AH=>DAT_fffffffa
    //         00567047     ADD        ESI,0x3
    //         0056704a     SUB        EDI,0x3
    //         0056704d     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00567053
undefined FUN_00567053() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00567053()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00567053
    //         00567053     MOV        EAX,dword ptr [ESI]
    //         00567055     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056705b     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00567061     MOV        byte ptr [EDI],AL
    //         00567063     MOV        byte ptr [EDI + -0x1],AH
    //         00567066     SHR        EAX,0x10
    //         00567069     MOV        byte ptr [EDI + -0x2],AL
    //         0056706c     ADD        ESI,0x3
    //         0056706f     SUB        EDI,0x3
    //         00567072     MOV        EAX,dword ptr [ESI]
    //         00567074     SUB        EDI,0x4
    //         00567077     BSWAP      EAX
    //         00567079     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056707f     ADD        ESI,0x4
    //         00567082     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00567088     MOV        dword ptr [EDI + 0x1],EAX=>DAT_fffffffa
    //         0056708b     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00567091
undefined FUN_00567091() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00567091()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00567091
    //         00567091     MOV        EAX,dword ptr [ESI + -0x1]
    //         00567094     ADD        ESI,0x2
    //         00567097     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056709d     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         005670a3     SHR        EAX,0x8
    //         005670a6     MOV        byte ptr [EDI],AL
    //         005670a8     MOV        byte ptr [EDI + -0x1],AH
    //         005670ab     SUB        EDI,0x2
    //         005670ae     MOV        EAX,dword ptr [ESI]
    //         005670b0     SUB        EDI,0x4
    //         005670b3     BSWAP      EAX
    //         005670b5     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005670bb     ADD        ESI,0x4
    //         005670be     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         005670c4     MOV        dword ptr [EDI + 0x1],EAX=>DAT_fffffffb
    //         005670c7     MOV        AH,byte ptr [ESI]
    //         005670c9     INC        ESI
    //         005670ca     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005670d0     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         005670d6     MOV        byte ptr [EDI],AH=>DAT_fffffffa
    //         005670d8     DEC        EDI
    //         005670d9     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005670DF
undefined FUN_005670df() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005670df()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005670df
    //         005670df     MOV        AL,byte ptr [ESI]
    //         005670e1     INC        ESI
    //         005670e2     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005670e8     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         005670ee     MOV        byte ptr [EDI],AL
    //         005670f0     DEC        EDI
    //         005670f1     MOV        EAX,dword ptr [ESI]
    //         005670f3     SUB        EDI,0x4
    //         005670f6     BSWAP      EAX
    //         005670f8     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005670fe     ADD        ESI,0x4
    //         00567101     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00567107     MOV        dword ptr [EDI + 0x1],EAX
    //         0056710a     MOV        EAX,dword ptr [ESI + -0x1]
    //         0056710d     ADD        ESI,0x2
    //         00567110     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567116     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         0056711c     SHR        EAX,0x8
    //         0056711f     MOV        byte ptr [EDI],AL=>DAT_fffffffb
    //         00567121     MOV        byte ptr [EDI + -0x1],AH=>DAT_fffffffa
    //         00567124     SUB        EDI,0x2
    //         00567127     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x0056712D
undefined FUN_0056712d() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056712d()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056712d                                                 XREF[1]:     00567149(j)  
    //         0056712d     MOV        EAX,dword ptr [ESI]
    //         0056712f     BSWAP      EAX
    //         00567131     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567137     ADD        ESI,0x4
    //         0056713a     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00567140     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff9
    //         00567143     SUB        EDI,0x4
    //         00567146     SUB        ECX,0x4
    //         00567149     JA         FUN_0056712d
    //         0056714b     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00567151
undefined FUN_00567151() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00567151()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00567151
    //         00567151     MOV        AL,byte ptr [ESI]
    //         00567153     INC        ESI
    //         00567154     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056715a     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00567160     MOV        byte ptr [EDI],AL
    //         00567162     DEC        EDI
    //         00567163     DEC        ECX
    //                               LAB_00567164                                                 XREF[1]:     00567180(j)  
    //         00567164     MOV        EAX,dword ptr [ESI]
    //         00567166     BSWAP      EAX
    //         00567168     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056716e     ADD        ESI,0x4
    //         00567171     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00567177     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff8
    //         0056717a     SUB        EDI,0x4
    //         0056717d     SUB        ECX,0x4
    //         00567180     JA         LAB_00567164
    //         00567182     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00567188
undefined FUN_00567188() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00567188()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00567188
    //         00567188     MOV        EAX,dword ptr [ESI + -0x1]
    //         0056718b     ADD        ESI,0x2
    //         0056718e     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567194     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         0056719a     SHR        EAX,0x8
    //         0056719d     MOV        byte ptr [EDI],AL
    //         0056719f     MOV        byte ptr [EDI + -0x1],AH
    //         005671a2     SUB        EDI,0x2
    //         005671a5     SUB        ECX,0x2
    //                               LAB_005671a8                                                 XREF[1]:     005671c4(j)  
    //         005671a8     MOV        EAX,dword ptr [ESI]
    //         005671aa     BSWAP      EAX
    //         005671ac     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005671b2     ADD        ESI,0x4
    //         005671b5     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         005671bb     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffb
    //         005671be     SUB        EDI,0x4
    //         005671c1     SUB        ECX,0x4
    //         005671c4     JA         LAB_005671a8
    //         005671c6     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005671CC
undefined FUN_005671cc() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005671cc()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005671cc
    //         005671cc     MOV        EAX,dword ptr [ESI]
    //         005671ce     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005671d4     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         005671da     MOV        byte ptr [EDI],AL
    //         005671dc     MOV        byte ptr [EDI + -0x1],AH
    //         005671df     SHR        EAX,0x10
    //         005671e2     MOV        byte ptr [EDI + -0x2],AL
    //         005671e5     ADD        ESI,0x3
    //         005671e8     SUB        EDI,0x3
    //         005671eb     SUB        ECX,0x3
    //                               LAB_005671ee                                                 XREF[1]:     0056720a(j)  
    //         005671ee     MOV        EAX,dword ptr [ESI]
    //         005671f0     BSWAP      EAX
    //         005671f2     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005671f8     ADD        ESI,0x4
    //         005671fb     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00567201     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffa
    //         00567204     SUB        EDI,0x4
    //         00567207     SUB        ECX,0x4
    //         0056720a     JA         LAB_005671ee
    //         0056720c     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00567212
undefined FUN_00567212() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00567212()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00567212
    //         00567212     DEC        ECX
    //                               LAB_00567213                                                 XREF[1]:     0056722f(j)  
    //         00567213     MOV        EAX,dword ptr [ESI]
    //         00567215     BSWAP      EAX
    //         00567217     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056721d     ADD        ESI,0x4
    //         00567220     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00567226     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff9
    //         00567229     SUB        EDI,0x4
    //         0056722c     SUB        ECX,0x4
    //         0056722f     JA         LAB_00567213
    //         00567231     MOV        AH,byte ptr [ESI]
    //         00567233     INC        ESI
    //         00567234     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056723a     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00567240     MOV        byte ptr [EDI],AH=>DAT_fffffff8
    //         00567242     DEC        EDI
    //         00567243     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00567249
undefined FUN_00567249() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00567249()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00567249
    //         00567249     MOV        AL,byte ptr [ESI]
    //         0056724b     INC        ESI
    //         0056724c     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567252     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00567258     MOV        byte ptr [EDI],AL
    //         0056725a     DEC        EDI
    //         0056725b     SUB        ECX,0x2
    //                               LAB_0056725e                                                 XREF[1]:     0056727a(j)  
    //         0056725e     MOV        EAX,dword ptr [ESI]
    //         00567260     BSWAP      EAX
    //         00567262     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567268     ADD        ESI,0x4
    //         0056726b     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00567271     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff8
    //         00567274     SUB        EDI,0x4
    //         00567277     SUB        ECX,0x4
    //         0056727a     JA         LAB_0056725e
    //         0056727c     MOV        AH,byte ptr [ESI]
    //         0056727e     INC        ESI
    //         0056727f     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567285     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         0056728b     MOV        byte ptr [EDI],AH=>DAT_fffffffb
    //         0056728d     DEC        EDI
    //         0056728e     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00567294
undefined FUN_00567294() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00567294()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00567294
    //         00567294     MOV        EAX,dword ptr [ESI + -0x1]
    //         00567297     ADD        ESI,0x2
    //         0056729a     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005672a0     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         005672a6     SHR        EAX,0x8
    //         005672a9     MOV        byte ptr [EDI],AL
    //         005672ab     MOV        byte ptr [EDI + -0x1],AH
    //         005672ae     SUB        EDI,0x2
    //         005672b1     SUB        ECX,0x3
    //                               LAB_005672b4                                                 XREF[1]:     005672d0(j)  
    //         005672b4     MOV        EAX,dword ptr [ESI]
    //         005672b6     BSWAP      EAX
    //         005672b8     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005672be     ADD        ESI,0x4
    //         005672c1     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         005672c7     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffb
    //         005672ca     SUB        EDI,0x4
    //         005672cd     SUB        ECX,0x4
    //         005672d0     JA         LAB_005672b4
    //         005672d2     MOV        AH,byte ptr [ESI]
    //         005672d4     INC        ESI
    //         005672d5     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005672db     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         005672e1     MOV        byte ptr [EDI],AH=>DAT_fffffffa
    //         005672e3     DEC        EDI
    //         005672e4     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005672EA
undefined FUN_005672ea() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005672ea()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005672ea
    //         005672ea     MOV        EAX,dword ptr [ESI]
    //         005672ec     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005672f2     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         005672f8     MOV        byte ptr [EDI],AL
    //         005672fa     MOV        byte ptr [EDI + -0x1],AH
    //         005672fd     SHR        EAX,0x10
    //         00567300     MOV        byte ptr [EDI + -0x2],AL
    //         00567303     ADD        ESI,0x3
    //         00567306     SUB        EDI,0x3
    //         00567309     SUB        ECX,0x4
    //                               LAB_0056730c                                                 XREF[1]:     00567328(j)  
    //         0056730c     MOV        EAX,dword ptr [ESI]
    //         0056730e     BSWAP      EAX
    //         00567310     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567316     ADD        ESI,0x4
    //         00567319     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         0056731f     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffa
    //         00567322     SUB        EDI,0x4
    //         00567325     SUB        ECX,0x4
    //         00567328     JA         LAB_0056730c
    //         0056732a     MOV        AH,byte ptr [ESI]
    //         0056732c     INC        ESI
    //         0056732d     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567333     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00567339     MOV        byte ptr [EDI],AH=>DAT_fffffff9
    //         0056733b     DEC        EDI
    //         0056733c     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00567342
undefined FUN_00567342() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00567342()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00567342
    //         00567342     SUB        ECX,0x2
    //                               LAB_00567345                                                 XREF[1]:     00567361(j)  
    //         00567345     MOV        EAX,dword ptr [ESI]
    //         00567347     BSWAP      EAX
    //         00567349     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056734f     ADD        ESI,0x4
    //         00567352     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00567358     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff9
    //         0056735b     SUB        EDI,0x4
    //         0056735e     SUB        ECX,0x4
    //         00567361     JA         LAB_00567345
    //         00567363     MOV        EAX,dword ptr [ESI + -0x1]
    //         00567366     ADD        ESI,0x2
    //         00567369     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056736f     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00567375     SHR        EAX,0x8
    //         00567378     MOV        byte ptr [EDI],AL=>DAT_fffffff8
    //         0056737a     MOV        byte ptr [EDI + -0x1],AH=>DAT_fffffffb
    //         0056737d     SUB        EDI,0x2
    //         00567380     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00567386
undefined FUN_00567386() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00567386()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00567386
    //         00567386     MOV        AL,byte ptr [ESI]
    //         00567388     INC        ESI
    //         00567389     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056738f     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00567395     MOV        byte ptr [EDI],AL
    //         00567397     DEC        EDI
    //         00567398     SUB        ECX,0x3
    //                               LAB_0056739b                                                 XREF[1]:     005673b7(j)  
    //         0056739b     MOV        EAX,dword ptr [ESI]
    //         0056739d     BSWAP      EAX
    //         0056739f     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005673a5     ADD        ESI,0x4
    //         005673a8     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         005673ae     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff8
    //         005673b1     SUB        EDI,0x4
    //         005673b4     SUB        ECX,0x4
    //         005673b7     JA         LAB_0056739b
    //         005673b9     MOV        EAX,dword ptr [ESI + -0x1]
    //         005673bc     ADD        ESI,0x2
    //         005673bf     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005673c5     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         005673cb     SHR        EAX,0x8
    //         005673ce     MOV        byte ptr [EDI],AL=>DAT_fffffffb
    //         005673d0     MOV        byte ptr [EDI + -0x1],AH=>DAT_fffffffa
    //         005673d3     SUB        EDI,0x2
    //         005673d6     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005673DC
undefined FUN_005673dc() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005673dc()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005673dc
    //         005673dc     MOV        EAX,dword ptr [ESI + -0x1]
    //         005673df     ADD        ESI,0x2
    //         005673e2     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005673e8     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         005673ee     SHR        EAX,0x8
    //         005673f1     MOV        byte ptr [EDI],AL
    //         005673f3     MOV        byte ptr [EDI + -0x1],AH
    //         005673f6     SUB        EDI,0x2
    //         005673f9     SUB        ECX,0x4
    //                               LAB_005673fc                                                 XREF[1]:     00567418(j)  
    //         005673fc     MOV        EAX,dword ptr [ESI]
    //         005673fe     BSWAP      EAX
    //         00567400     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567406     ADD        ESI,0x4
    //         00567409     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         0056740f     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffb
    //         00567412     SUB        EDI,0x4
    //         00567415     SUB        ECX,0x4
    //         00567418     JA         LAB_005673fc
    //         0056741a     MOV        EAX,dword ptr [ESI + -0x1]
    //         0056741d     ADD        ESI,0x2
    //         00567420     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567426     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         0056742c     SHR        EAX,0x8
    //         0056742f     MOV        byte ptr [EDI],AL=>DAT_fffffffa
    //         00567431     MOV        byte ptr [EDI + -0x1],AH=>DAT_fffffff9
    //         00567434     SUB        EDI,0x2
    //         00567437     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x0056743D
undefined FUN_0056743d() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056743d()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056743d
    //         0056743d     MOV        EAX,dword ptr [ESI]
    //         0056743f     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567445     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         0056744b     MOV        byte ptr [EDI],AL
    //         0056744d     MOV        byte ptr [EDI + -0x1],AH
    //         00567450     SHR        EAX,0x10
    //         00567453     MOV        byte ptr [EDI + -0x2],AL
    //         00567456     ADD        ESI,0x3
    //         00567459     SUB        EDI,0x3
    //         0056745c     SUB        ECX,0x5
    //                               LAB_0056745f                                                 XREF[1]:     0056747b(j)  
    //         0056745f     MOV        EAX,dword ptr [ESI]
    //         00567461     BSWAP      EAX
    //         00567463     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567469     ADD        ESI,0x4
    //         0056746c     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00567472     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffa
    //         00567475     SUB        EDI,0x4
    //         00567478     SUB        ECX,0x4
    //         0056747b     JA         LAB_0056745f
    //         0056747d     MOV        EAX,dword ptr [ESI + -0x1]
    //         00567480     ADD        ESI,0x2
    //         00567483     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567489     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         0056748f     SHR        EAX,0x8
    //         00567492     MOV        byte ptr [EDI],AL=>DAT_fffffff9
    //         00567494     MOV        byte ptr [EDI + -0x1],AH=>DAT_fffffff8
    //         00567497     SUB        EDI,0x2
    //         0056749a     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005674A0
undefined FUN_005674a0() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005674a0()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005674a0
    //         005674a0     SUB        ECX,0x3
    //                               LAB_005674a3                                                 XREF[1]:     005674bf(j)  
    //         005674a3     MOV        EAX,dword ptr [ESI]
    //         005674a5     BSWAP      EAX
    //         005674a7     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005674ad     ADD        ESI,0x4
    //         005674b0     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         005674b6     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff9
    //         005674b9     SUB        EDI,0x4
    //         005674bc     SUB        ECX,0x4
    //         005674bf     JA         LAB_005674a3
    //         005674c1     MOV        EAX,dword ptr [ESI + -0x1]
    //         005674c4     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005674ca     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         005674d0     MOV        byte ptr [EDI],AH=>DAT_fffffff8
    //         005674d2     SHR        EAX,0x10
    //         005674d5     MOV        byte ptr [EDI + -0x1],AL=>DAT_fffffffb
    //         005674d8     MOV        byte ptr [EDI + -0x2],AH=>DAT_fffffffa
    //         005674db     ADD        ESI,0x3
    //         005674de     SUB        EDI,0x3
    //         005674e1     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005674E7
undefined FUN_005674e7() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005674e7()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005674e7
    //         005674e7     MOV        AL,byte ptr [ESI]
    //         005674e9     INC        ESI
    //         005674ea     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005674f0     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         005674f6     MOV        byte ptr [EDI],AL
    //         005674f8     DEC        EDI
    //         005674f9     SUB        ECX,0x4
    //                               LAB_005674fc                                                 XREF[1]:     00567518(j)  
    //         005674fc     MOV        EAX,dword ptr [ESI]
    //         005674fe     BSWAP      EAX
    //         00567500     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567506     ADD        ESI,0x4
    //         00567509     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         0056750f     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff8
    //         00567512     SUB        EDI,0x4
    //         00567515     SUB        ECX,0x4
    //         00567518     JA         LAB_005674fc
    //         0056751a     MOV        EAX,dword ptr [ESI + -0x1]
    //         0056751d     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567523     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00567529     MOV        byte ptr [EDI],AH=>DAT_fffffffb
    //         0056752b     SHR        EAX,0x10
    //         0056752e     MOV        byte ptr [EDI + -0x1],AL=>DAT_fffffffa
    //         00567531     MOV        byte ptr [EDI + -0x2],AH=>DAT_fffffff9
    //         00567534     ADD        ESI,0x3
    //         00567537     SUB        EDI,0x3
    //         0056753a     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00567540
undefined FUN_00567540() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00567540()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00567540
    //         00567540     MOV        EAX,dword ptr [ESI + -0x1]
    //         00567543     ADD        ESI,0x2
    //         00567546     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056754c     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00567552     SHR        EAX,0x8
    //         00567555     MOV        byte ptr [EDI],AL
    //         00567557     MOV        byte ptr [EDI + -0x1],AH
    //         0056755a     SUB        EDI,0x2
    //         0056755d     SUB        ECX,0x5
    //                               LAB_00567560                                                 XREF[1]:     0056757c(j)  
    //         00567560     MOV        EAX,dword ptr [ESI]
    //         00567562     BSWAP      EAX
    //         00567564     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056756a     ADD        ESI,0x4
    //         0056756d     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00567573     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffb
    //         00567576     SUB        EDI,0x4
    //         00567579     SUB        ECX,0x4
    //         0056757c     JA         LAB_00567560
    //         0056757e     MOV        EAX,dword ptr [ESI + -0x1]
    //         00567581     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567587     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         0056758d     MOV        byte ptr [EDI],AH=>DAT_fffffffa
    //         0056758f     SHR        EAX,0x10
    //         00567592     MOV        byte ptr [EDI + -0x1],AL=>DAT_fffffff9
    //         00567595     MOV        byte ptr [EDI + -0x2],AH=>DAT_fffffff8
    //         00567598     ADD        ESI,0x3
    //         0056759b     SUB        EDI,0x3
    //         0056759e     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005675A4
undefined FUN_005675a4() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005675a4()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005675a4
    //         005675a4     MOV        EAX,dword ptr [ESI]
    //         005675a6     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005675ac     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         005675b2     MOV        byte ptr [EDI],AL
    //         005675b4     MOV        byte ptr [EDI + -0x1],AH
    //         005675b7     SHR        EAX,0x10
    //         005675ba     MOV        byte ptr [EDI + -0x2],AL
    //         005675bd     ADD        ESI,0x3
    //         005675c0     SUB        EDI,0x3
    //         005675c3     SUB        ECX,0x6
    //                               LAB_005675c6                                                 XREF[1]:     005675e2(j)  
    //         005675c6     MOV        EAX,dword ptr [ESI]
    //         005675c8     BSWAP      EAX
    //         005675ca     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005675d0     ADD        ESI,0x4
    //         005675d3     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         005675d9     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffa
    //         005675dc     SUB        EDI,0x4
    //         005675df     SUB        ECX,0x4
    //         005675e2     JA         LAB_005675c6
    //         005675e4     MOV        EAX,dword ptr [ESI + -0x1]
    //         005675e7     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005675ed     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         005675f3     MOV        byte ptr [EDI],AH=>DAT_fffffff9
    //         005675f5     SHR        EAX,0x10
    //         005675f8     MOV        byte ptr [EDI + -0x1],AL=>DAT_fffffff8
    //         005675fb     MOV        byte ptr [EDI + -0x2],AH=>DAT_fffffff7
    //         005675fe     ADD        ESI,0x3
    //         00567601     SUB        EDI,0x3
    //         00567604     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x0056760A
undefined FUN_0056760a() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056760a()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056760a
    //         0056760a     MOV        AL,byte ptr [ESI]
    //         0056760c     INC        ESI
    //         0056760d     OR         EAX,EBX
    //         0056760f     MOV        byte ptr [EDI],AL
    //         00567611     DEC        EDI
    //         00567612     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00567618
undefined FUN_00567618() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00567618()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00567618
    //         00567618     MOV        AX,word ptr [ESI]
    //         0056761b     OR         EAX,EBX
    //         0056761d     ADD        ESI,0x2
    //         00567620     MOV        byte ptr [EDI],AL
    //         00567622     MOV        byte ptr [EDI + -0x1],AH
    //         00567625     SUB        EDI,0x2
    //         00567628     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x0056762E
undefined FUN_0056762e() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056762e()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056762e
    //         0056762e     MOV        EAX,dword ptr [ESI]
    //         00567630     OR         EAX,EBX
    //         00567632     ADD        ESI,0x3
    //         00567635     MOV        byte ptr [EDI],AL
    //         00567637     MOV        byte ptr [EDI + -0x1],AH
    //         0056763a     SHR        EAX,0x8
    //         0056763d     MOV        byte ptr [EDI + -0x2],AH
    //         00567640     SUB        EDI,0x3
    //         00567643     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00567649
undefined FUN_00567649() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00567649()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00567649
    //         00567649     MOV        EAX,dword ptr [ESI]
    //         0056764b     BSWAP      EAX
    //         0056764d     OR         EAX,EBX
    //         0056764f     ADD        ESI,0x4
    //         00567652     MOV        dword ptr [EDI + -0x3],EAX
    //         00567655     SUB        EDI,0x4
    //         00567658     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x0056765E
undefined FUN_0056765e() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056765e()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056765e
    //         0056765e     MOV        EAX,dword ptr [ESI]
    //         00567660     OR         EAX,EBX
    //         00567662     ADD        ESI,0x4
    //         00567665     MOV        byte ptr [EDI],AL
    //         00567667     MOV        byte ptr [EDI + -0x1],AH
    //         0056766a     SHR        EAX,0x10
    //         0056766d     MOV        byte ptr [EDI + -0x2],AL
    //         00567670     MOV        byte ptr [EDI + -0x3],AH
    //         00567673     SUB        EDI,0x4
    //         00567676     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x0056767C
undefined FUN_0056767c() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056767c()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056767c
    //         0056767c     MOV        EAX,dword ptr [ESI]
    //         0056767e     MOV        DL,byte ptr [ESI + 0x4]
    //         00567681     OR         EAX,EBX
    //         00567683     OR         EDX,EBX
    //         00567685     BSWAP      EAX
    //         00567687     MOV        byte ptr [EDI + -0x4],DL
    //         0056768a     MOV        dword ptr [EDI + -0x3],EAX
    //         0056768d     ADD        ESI,0x5
    //         00567690     SUB        EDI,0x5
    //         00567693     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00567699
undefined FUN_00567699() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00567699()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00567699
    //         00567699     MOV        EAX,dword ptr [ESI]
    //         0056769b     OR         EAX,EBX
    //         0056769d     MOV        byte ptr [EDI],AL
    //         0056769f     MOV        byte ptr [EDI + -0x1],AH
    //         005676a2     SHR        EAX,0x10
    //         005676a5     MOV        byte ptr [EDI + -0x2],AL
    //         005676a8     ADD        ESI,0x3
    //         005676ab     SUB        EDI,0x3
    //         005676ae     MOV        EAX,dword ptr [ESI]
    //         005676b0     OR         EAX,EBX
    //         005676b2     MOV        byte ptr [EDI],AL
    //         005676b4     MOV        byte ptr [EDI + -0x1],AH
    //         005676b7     ADD        ESI,0x2
    //         005676ba     SUB        EDI,0x2
    //         005676bd     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005676C3
undefined FUN_005676c3() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005676c3()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005676c3
    //         005676c3     MOV        DL,byte ptr [ESI]
    //         005676c5     MOV        EAX,dword ptr [ESI + 0x1]
    //         005676c8     OR         EAX,EBX
    //         005676ca     OR         EDX,EBX
    //         005676cc     BSWAP      EAX
    //         005676ce     MOV        byte ptr [EDI],DL
    //         005676d0     MOV        dword ptr [EDI + -0x4],EAX
    //         005676d3     ADD        ESI,0x5
    //         005676d6     SUB        EDI,0x5
    //         005676d9     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005676DF
undefined FUN_005676df() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005676df()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005676df
    //         005676df     MOV        EAX,dword ptr [ESI]
    //         005676e1     MOV        EDX,dword ptr [ESI + 0x4]
    //         005676e4     OR         EAX,EBX
    //         005676e6     OR         EDX,EBX
    //         005676e8     BSWAP      EAX
    //         005676ea     MOV        dword ptr [EDI + -0x3],EAX
    //         005676ed     ADD        ESI,0x6
    //         005676f0     MOV        byte ptr [EDI + -0x4],DL
    //         005676f3     MOV        byte ptr [EDI + DAT_fffffffb],DH
    //         005676f6     SUB        EDI,0x6
    //         005676f9     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005676FF
undefined FUN_005676ff() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005676ff()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005676ff
    //         005676ff     MOV        EAX,dword ptr [ESI]
    //         00567701     OR         EAX,EBX
    //         00567703     MOV        byte ptr [EDI],AL
    //         00567705     MOV        byte ptr [EDI + -0x1],AH
    //         00567708     SHR        EAX,0x10
    //         0056770b     MOV        byte ptr [EDI + -0x2],AL
    //         0056770e     ADD        ESI,0x3
    //         00567711     SUB        EDI,0x3
    //         00567714     MOV        EAX,dword ptr [ESI]
    //         00567716     OR         EAX,EBX
    //         00567718     MOV        byte ptr [EDI],AL
    //         0056771a     MOV        byte ptr [EDI + -0x1],AH
    //         0056771d     SHR        EAX,0x10
    //         00567720     MOV        byte ptr [EDI + -0x2],AL=>DAT_fffffffb
    //         00567723     ADD        ESI,0x3
    //         00567726     SUB        EDI,0x3
    //         00567729     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x0056772F
undefined FUN_0056772f() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056772f()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056772f
    //         0056772f     MOV        EAX,dword ptr [ESI]
    //         00567731     MOV        EDX,dword ptr [ESI + 0x2]
    //         00567734     OR         EAX,EBX
    //         00567736     OR         EDX,EBX
    //         00567738     BSWAP      EDX
    //         0056773a     MOV        byte ptr [EDI],AL
    //         0056773c     MOV        byte ptr [EDI + -0x1],AH
    //         0056773f     ADD        ESI,0x6
    //         00567742     MOV        dword ptr [EDI + DAT_fffffffb],EDX
    //         00567745     SUB        EDI,0x6
    //         00567748     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x0056774E
undefined FUN_0056774e() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056774e()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056774e
    //         0056774e     MOV        DL,byte ptr [ESI]
    //         00567750     MOV        DH,byte ptr [ESI + 0x5]
    //         00567753     MOV        EAX,dword ptr [ESI + 0x1]
    //         00567756     OR         EAX,EBX
    //         00567758     OR         EDX,EBX
    //         0056775a     BSWAP      EAX
    //         0056775c     MOV        byte ptr [EDI],DL
    //         0056775e     MOV        dword ptr [EDI + -0x4],EAX
    //         00567761     ADD        ESI,0x6
    //         00567764     MOV        byte ptr [EDI + DAT_fffffffb],DH
    //         00567767     SUB        EDI,0x6
    //         0056776a     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00567770
undefined FUN_00567770() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00567770()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00567770
    //         00567770     MOV        EAX,dword ptr [ESI]
    //         00567772     MOV        EDX,dword ptr [ESI + 0x4]
    //         00567775     OR         EAX,EBX
    //         00567777     OR         EDX,EBX
    //         00567779     BSWAP      EAX
    //         0056777b     MOV        dword ptr [EDI + -0x3],EAX
    //         0056777e     MOV        byte ptr [EDI + -0x4],DL
    //         00567781     MOV        byte ptr [EDI + DAT_fffffffb],DH
    //         00567784     SHR        EBX,0x10
    //         00567787     ADD        ESI,0x7
    //         0056778a     MOV        byte ptr [EDI + DAT_fffffffa],DL
    //         0056778d     SUB        EDI,0x7
    //         00567790     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00567796
undefined FUN_00567796() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00567796()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00567796
    //         00567796     MOV        EAX,dword ptr [ESI]
    //         00567798     MOV        EDX,dword ptr [ESI + 0x3]
    //         0056779b     OR         EAX,EBX
    //         0056779d     OR         EDX,EBX
    //         0056779f     MOV        byte ptr [EDI],AL
    //         005677a1     MOV        byte ptr [EDI + -0x1],AH
    //         005677a4     SHR        EAX,0x10
    //         005677a7     ADD        ESI,0x7
    //         005677aa     MOV        byte ptr [EDI + -0x2],AL
    //         005677ad     BSWAP      EDX
    //         005677af     MOV        dword ptr [EDI + DAT_fffffffa],EDX
    //         005677b2     SUB        EDI,0x7
    //         005677b5     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005677BB
undefined FUN_005677bb() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005677bb()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005677bb
    //         005677bb     MOV        EDX,dword ptr [ESI]
    //         005677bd     MOV        EAX,dword ptr [ESI + 0x2]
    //         005677c0     OR         EDX,EBX
    //         005677c2     OR         EAX,EBX
    //         005677c4     BSWAP      EAX
    //         005677c6     MOV        byte ptr [EDI],DL
    //         005677c8     MOV        byte ptr [EDI + -0x1],DH
    //         005677cb     MOV        dword ptr [EDI + DAT_fffffffb],EAX
    //         005677ce     MOV        AL,byte ptr [ESI + 0x6]
    //         005677d1     ADD        ESI,0x7
    //         005677d4     OR         EAX,EBX
    //         005677d6     MOV        byte ptr [EDI + DAT_fffffffa],AL
    //         005677d9     SUB        EDI,0x7
    //         005677dc     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005677E2
undefined FUN_005677e2() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005677e2()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005677e2
    //         005677e2     MOV        DL,byte ptr [ESI]
    //         005677e4     MOV        EAX,dword ptr [ESI + 0x1]
    //         005677e7     OR         EAX,EBX
    //         005677e9     OR         EDX,EBX
    //         005677eb     BSWAP      EAX
    //         005677ed     MOV        byte ptr [EDI],DL
    //         005677ef     MOV        dword ptr [EDI + -0x4],EAX
    //         005677f2     MOV        EAX,dword ptr [ESI + 0x5]
    //         005677f5     ADD        ESI,0x7
    //         005677f8     OR         EAX,EBX
    //         005677fa     MOV        byte ptr [EDI + DAT_fffffffb],AL
    //         005677fd     MOV        byte ptr [EDI + DAT_fffffffa],AH
    //         00567800     SUB        EDI,0x7
    //         00567803     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00567809
undefined FUN_00567809() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00567809()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00567809                                                 XREF[1]:     0056781b(j)  
    //         00567809     MOV        EAX,dword ptr [ESI]
    //         0056780b     BSWAP      EAX
    //         0056780d     OR         EAX,EBX
    //         0056780f     ADD        ESI,0x4
    //         00567812     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff9
    //         00567815     SUB        EDI,0x4
    //         00567818     SUB        ECX,0x4
    //         0056781b     JA         FUN_00567809
    //         0056781d     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00567823
undefined FUN_00567823() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00567823()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00567823
    //         00567823     MOV        AL,byte ptr [ESI]
    //         00567825     OR         EAX,EBX
    //         00567827     MOV        byte ptr [EDI],AL
    //         00567829     INC        ESI
    //         0056782a     DEC        EDI
    //         0056782b     DEC        ECX
    //                               LAB_0056782c                                                 XREF[1]:     0056783e(j)  
    //         0056782c     MOV        EAX,dword ptr [ESI]
    //         0056782e     BSWAP      EAX
    //         00567830     OR         EAX,EBX
    //         00567832     ADD        ESI,0x4
    //         00567835     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff8
    //         00567838     SUB        EDI,0x4
    //         0056783b     SUB        ECX,0x4
    //         0056783e     JA         LAB_0056782c
    //         00567840     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00567846
undefined FUN_00567846() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00567846()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00567846
    //         00567846     MOV        EAX,dword ptr [ESI]
    //         00567848     OR         EAX,EBX
    //         0056784a     MOV        byte ptr [EDI],AL
    //         0056784c     MOV        byte ptr [EDI + -0x1],AH
    //         0056784f     ADD        ESI,0x2
    //         00567852     SUB        EDI,0x2
    //         00567855     SUB        ECX,0x2
    //                               LAB_00567858                                                 XREF[1]:     0056786a(j)  
    //         00567858     MOV        EAX,dword ptr [ESI]
    //         0056785a     BSWAP      EAX
    //         0056785c     OR         EAX,EBX
    //         0056785e     ADD        ESI,0x4
    //         00567861     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffb
    //         00567864     SUB        EDI,0x4
    //         00567867     SUB        ECX,0x4
    //         0056786a     JA         LAB_00567858
    //         0056786c     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00567872
undefined FUN_00567872() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00567872()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00567872
    //         00567872     MOV        EAX,dword ptr [ESI]
    //         00567874     OR         EAX,EBX
    //         00567876     MOV        byte ptr [EDI],AL
    //         00567878     MOV        byte ptr [EDI + -0x1],AH
    //         0056787b     SHR        EAX,0x10
    //         0056787e     MOV        byte ptr [EDI + -0x2],AL
    //         00567881     ADD        ESI,0x3
    //         00567884     SUB        EDI,0x3
    //         00567887     SUB        ECX,0x3
    //                               LAB_0056788a                                                 XREF[1]:     0056789c(j)  
    //         0056788a     MOV        EAX,dword ptr [ESI]
    //         0056788c     BSWAP      EAX
    //         0056788e     OR         EAX,EBX
    //         00567890     ADD        ESI,0x4
    //         00567893     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffa
    //         00567896     SUB        EDI,0x4
    //         00567899     SUB        ECX,0x4
    //         0056789c     JA         LAB_0056788a
    //         0056789e     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005678A4
undefined FUN_005678a4() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005678a4()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005678a4
    //         005678a4     DEC        ECX
    //                               LAB_005678a5                                                 XREF[1]:     005678b7(j)  
    //         005678a5     MOV        EAX,dword ptr [ESI]
    //         005678a7     BSWAP      EAX
    //         005678a9     OR         EAX,EBX
    //         005678ab     ADD        ESI,0x4
    //         005678ae     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff9
    //         005678b1     SUB        EDI,0x4
    //         005678b4     SUB        ECX,0x4
    //         005678b7     JA         LAB_005678a5
    //         005678b9     MOV        AL,byte ptr [ESI]
    //         005678bb     OR         EAX,EBX
    //         005678bd     MOV        byte ptr [EDI],AL=>DAT_fffffff8
    //         005678bf     INC        ESI
    //         005678c0     DEC        EDI
    //         005678c1     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005678C7
undefined FUN_005678c7() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005678c7()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005678c7
    //         005678c7     MOV        AL,byte ptr [ESI]
    //         005678c9     OR         EAX,EBX
    //         005678cb     MOV        byte ptr [EDI],AL
    //         005678cd     INC        ESI
    //         005678ce     DEC        EDI
    //         005678cf     SUB        ECX,0x2
    //                               LAB_005678d2                                                 XREF[1]:     005678e4(j)  
    //         005678d2     MOV        EAX,dword ptr [ESI]
    //         005678d4     BSWAP      EAX
    //         005678d6     OR         EAX,EBX
    //         005678d8     ADD        ESI,0x4
    //         005678db     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff8
    //         005678de     SUB        EDI,0x4
    //         005678e1     SUB        ECX,0x4
    //         005678e4     JA         LAB_005678d2
    //         005678e6     MOV        AL,byte ptr [ESI]
    //         005678e8     OR         EAX,EBX
    //         005678ea     MOV        byte ptr [EDI],AL=>DAT_fffffffb
    //         005678ec     INC        ESI
    //         005678ed     DEC        EDI
    //         005678ee     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005678F4
undefined FUN_005678f4() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005678f4()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005678f4
    //         005678f4     MOV        EAX,dword ptr [ESI]
    //         005678f6     OR         EAX,EBX
    //         005678f8     MOV        byte ptr [EDI],AL
    //         005678fa     MOV        byte ptr [EDI + -0x1],AH
    //         005678fd     ADD        ESI,0x2
    //         00567900     SUB        EDI,0x2
    //         00567903     SUB        ECX,0x3
    //                               LAB_00567906                                                 XREF[1]:     00567918(j)  
    //         00567906     MOV        EAX,dword ptr [ESI]
    //         00567908     BSWAP      EAX
    //         0056790a     OR         EAX,EBX
    //         0056790c     ADD        ESI,0x4
    //         0056790f     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffb
    //         00567912     SUB        EDI,0x4
    //         00567915     SUB        ECX,0x4
    //         00567918     JA         LAB_00567906
    //         0056791a     MOV        AL,byte ptr [ESI]
    //         0056791c     OR         EAX,EBX
    //         0056791e     MOV        byte ptr [EDI],AL=>DAT_fffffffa
    //         00567920     INC        ESI
    //         00567921     DEC        EDI
    //         00567922     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00567928
undefined FUN_00567928() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00567928()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00567928
    //         00567928     MOV        EAX,dword ptr [ESI]
    //         0056792a     OR         EAX,EBX
    //         0056792c     MOV        byte ptr [EDI],AL
    //         0056792e     MOV        byte ptr [EDI + -0x1],AH
    //         00567931     SHR        EAX,0x10
    //         00567934     MOV        byte ptr [EDI + -0x2],AL
    //         00567937     ADD        ESI,0x3
    //         0056793a     SUB        EDI,0x3
    //         0056793d     SUB        ECX,0x4
    //                               LAB_00567940                                                 XREF[1]:     00567952(j)  
    //         00567940     MOV        EAX,dword ptr [ESI]
    //         00567942     BSWAP      EAX
    //         00567944     OR         EAX,EBX
    //         00567946     ADD        ESI,0x4
    //         00567949     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffa
    //         0056794c     SUB        EDI,0x4
    //         0056794f     SUB        ECX,0x4
    //         00567952     JA         LAB_00567940
    //         00567954     MOV        AL,byte ptr [ESI]
    //         00567956     OR         EAX,EBX
    //         00567958     MOV        byte ptr [EDI],AL=>DAT_fffffff9
    //         0056795a     INC        ESI
    //         0056795b     DEC        EDI
    //         0056795c     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00567962
undefined FUN_00567962() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00567962()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00567962
    //         00567962     SUB        ECX,0x2
    //                               LAB_00567965                                                 XREF[1]:     00567977(j)  
    //         00567965     MOV        EAX,dword ptr [ESI]
    //         00567967     BSWAP      EAX
    //         00567969     OR         EAX,EBX
    //         0056796b     ADD        ESI,0x4
    //         0056796e     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff9
    //         00567971     SUB        EDI,0x4
    //         00567974     SUB        ECX,0x4
    //         00567977     JA         LAB_00567965
    //         00567979     MOV        EAX,dword ptr [ESI]
    //         0056797b     OR         EAX,EBX
    //         0056797d     MOV        byte ptr [EDI],AL=>DAT_fffffff8
    //         0056797f     MOV        byte ptr [EDI + -0x1],AH=>DAT_fffffffb
    //         00567982     ADD        ESI,0x2
    //         00567985     SUB        EDI,0x2
    //         00567988     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x0056798E
undefined FUN_0056798e() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056798e()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056798e
    //         0056798e     MOV        AL,byte ptr [ESI]
    //         00567990     OR         EAX,EBX
    //         00567992     MOV        byte ptr [EDI],AL
    //         00567994     INC        ESI
    //         00567995     DEC        EDI
    //         00567996     SUB        ECX,0x3
    //                               LAB_00567999                                                 XREF[1]:     005679ab(j)  
    //         00567999     MOV        EAX,dword ptr [ESI]
    //         0056799b     BSWAP      EAX
    //         0056799d     OR         EAX,EBX
    //         0056799f     ADD        ESI,0x4
    //         005679a2     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff8
    //         005679a5     SUB        EDI,0x4
    //         005679a8     SUB        ECX,0x4
    //         005679ab     JA         LAB_00567999
    //         005679ad     MOV        EAX,dword ptr [ESI]
    //         005679af     OR         EAX,EBX
    //         005679b1     MOV        byte ptr [EDI],AL=>DAT_fffffffb
    //         005679b3     MOV        byte ptr [EDI + -0x1],AH=>DAT_fffffffa
    //         005679b6     ADD        ESI,0x2
    //         005679b9     SUB        EDI,0x2
    //         005679bc     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005679C2
undefined FUN_005679c2() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005679c2()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005679c2
    //         005679c2     MOV        EAX,dword ptr [ESI]
    //         005679c4     OR         EAX,EBX
    //         005679c6     MOV        byte ptr [EDI],AL
    //         005679c8     MOV        byte ptr [EDI + -0x1],AH
    //         005679cb     ADD        ESI,0x2
    //         005679ce     SUB        EDI,0x2
    //         005679d1     SUB        ECX,0x4
    //                               LAB_005679d4                                                 XREF[1]:     005679e6(j)  
    //         005679d4     MOV        EAX,dword ptr [ESI]
    //         005679d6     BSWAP      EAX
    //         005679d8     OR         EAX,EBX
    //         005679da     ADD        ESI,0x4
    //         005679dd     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffb
    //         005679e0     SUB        EDI,0x4
    //         005679e3     SUB        ECX,0x4
    //         005679e6     JA         LAB_005679d4
    //         005679e8     MOV        EAX,dword ptr [ESI]
    //         005679ea     OR         EAX,EBX
    //         005679ec     MOV        byte ptr [EDI],AL=>DAT_fffffffa
    //         005679ee     MOV        byte ptr [EDI + -0x1],AH=>DAT_fffffff9
    //         005679f1     ADD        ESI,0x2
    //         005679f4     SUB        EDI,0x2
    //         005679f7     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005679FD
undefined FUN_005679fd() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005679fd()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005679fd
    //         005679fd     MOV        EAX,dword ptr [ESI]
    //         005679ff     OR         EAX,EBX
    //         00567a01     MOV        byte ptr [EDI],AL
    //         00567a03     MOV        byte ptr [EDI + -0x1],AH
    //         00567a06     SHR        EAX,0x10
    //         00567a09     MOV        byte ptr [EDI + -0x2],AL
    //         00567a0c     ADD        ESI,0x3
    //         00567a0f     SUB        EDI,0x3
    //         00567a12     SUB        ECX,0x5
    //                               LAB_00567a15                                                 XREF[1]:     00567a27(j)  
    //         00567a15     MOV        EAX,dword ptr [ESI]
    //         00567a17     BSWAP      EAX
    //         00567a19     OR         EAX,EBX
    //         00567a1b     ADD        ESI,0x4
    //         00567a1e     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffa
    //         00567a21     SUB        EDI,0x4
    //         00567a24     SUB        ECX,0x4
    //         00567a27     JA         LAB_00567a15
    //         00567a29     MOV        EAX,dword ptr [ESI]
    //         00567a2b     OR         EAX,EBX
    //         00567a2d     MOV        byte ptr [EDI],AL=>DAT_fffffff9
    //         00567a2f     MOV        byte ptr [EDI + -0x1],AH=>DAT_fffffff8
    //         00567a32     ADD        ESI,0x2
    //         00567a35     SUB        EDI,0x2
    //         00567a38     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00567A3E
undefined FUN_00567a3e() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00567a3e()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00567a3e
    //         00567a3e     SUB        ECX,0x3
    //                               LAB_00567a41                                                 XREF[1]:     00567a53(j)  
    //         00567a41     MOV        EAX,dword ptr [ESI]
    //         00567a43     BSWAP      EAX
    //         00567a45     OR         EAX,EBX
    //         00567a47     ADD        ESI,0x4
    //         00567a4a     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff9
    //         00567a4d     SUB        EDI,0x4
    //         00567a50     SUB        ECX,0x4
    //         00567a53     JA         LAB_00567a41
    //         00567a55     MOV        EAX,dword ptr [ESI]
    //         00567a57     OR         EAX,EBX
    //         00567a59     MOV        byte ptr [EDI],AL=>DAT_fffffff8
    //         00567a5b     MOV        byte ptr [EDI + -0x1],AH=>DAT_fffffffb
    //         00567a5e     SHR        EAX,0x10
    //         00567a61     MOV        byte ptr [EDI + -0x2],AL=>DAT_fffffffa
    //         00567a64     ADD        ESI,0x3
    //         00567a67     SUB        EDI,0x3
    //         00567a6a     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00567A70
undefined FUN_00567a70() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00567a70()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00567a70
    //         00567a70     MOV        AL,byte ptr [ESI]
    //         00567a72     OR         EAX,EBX
    //         00567a74     MOV        byte ptr [EDI],AL
    //         00567a76     INC        ESI
    //         00567a77     DEC        EDI
    //         00567a78     SUB        ECX,0x4
    //                               LAB_00567a7b                                                 XREF[1]:     00567a8d(j)  
    //         00567a7b     MOV        EAX,dword ptr [ESI]
    //         00567a7d     BSWAP      EAX
    //         00567a7f     OR         EAX,EBX
    //         00567a81     ADD        ESI,0x4
    //         00567a84     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff8
    //         00567a87     SUB        EDI,0x4
    //         00567a8a     SUB        ECX,0x4
    //         00567a8d     JA         LAB_00567a7b
    //         00567a8f     MOV        EAX,dword ptr [ESI]
    //         00567a91     OR         EAX,EBX
    //         00567a93     MOV        byte ptr [EDI],AL=>DAT_fffffffb
    //         00567a95     MOV        byte ptr [EDI + -0x1],AH=>DAT_fffffffa
    //         00567a98     SHR        EAX,0x10
    //         00567a9b     MOV        byte ptr [EDI + -0x2],AL=>DAT_fffffff9
    //         00567a9e     ADD        ESI,0x3
    //         00567aa1     SUB        EDI,0x3
    //         00567aa4     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00567AAA
undefined FUN_00567aaa() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00567aaa()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00567aaa
    //         00567aaa     MOV        EAX,dword ptr [ESI]
    //         00567aac     OR         EAX,EBX
    //         00567aae     MOV        byte ptr [EDI],AL
    //         00567ab0     MOV        byte ptr [EDI + -0x1],AH
    //         00567ab3     ADD        ESI,0x2
    //         00567ab6     SUB        EDI,0x2
    //         00567ab9     SUB        ECX,0x5
    //                               LAB_00567abc                                                 XREF[1]:     00567ace(j)  
    //         00567abc     MOV        EAX,dword ptr [ESI]
    //         00567abe     BSWAP      EAX
    //         00567ac0     OR         EAX,EBX
    //         00567ac2     ADD        ESI,0x4
    //         00567ac5     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffb
    //         00567ac8     SUB        EDI,0x4
    //         00567acb     SUB        ECX,0x4
    //         00567ace     JA         LAB_00567abc
    //         00567ad0     MOV        EAX,dword ptr [ESI]
    //         00567ad2     OR         EAX,EBX
    //         00567ad4     MOV        byte ptr [EDI],AL=>DAT_fffffffa
    //         00567ad6     MOV        byte ptr [EDI + -0x1],AH=>DAT_fffffff9
    //         00567ad9     SHR        EAX,0x10
    //         00567adc     MOV        byte ptr [EDI + -0x2],AL=>DAT_fffffff8
    //         00567adf     ADD        ESI,0x3
    //         00567ae2     SUB        EDI,0x3
    //         00567ae5     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00567AEB
undefined FUN_00567aeb() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00567aeb()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00567aeb
    //         00567aeb     MOV        EAX,dword ptr [ESI]
    //         00567aed     OR         EAX,EBX
    //         00567aef     MOV        byte ptr [EDI],AL
    //         00567af1     MOV        byte ptr [EDI + -0x1],AH
    //         00567af4     SHR        EAX,0x10
    //         00567af7     MOV        byte ptr [EDI + -0x2],AL
    //         00567afa     ADD        ESI,0x3
    //         00567afd     SUB        EDI,0x3
    //         00567b00     SUB        ECX,0x6
    //                               LAB_00567b03                                                 XREF[1]:     00567b15(j)  
    //         00567b03     MOV        EAX,dword ptr [ESI]
    //         00567b05     BSWAP      EAX
    //         00567b07     OR         EAX,EBX
    //         00567b09     ADD        ESI,0x4
    //         00567b0c     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffa
    //         00567b0f     SUB        EDI,0x4
    //         00567b12     SUB        ECX,0x4
    //         00567b15     JA         LAB_00567b03
    //         00567b17     MOV        EAX,dword ptr [ESI]
    //         00567b19     OR         EAX,EBX
    //         00567b1b     MOV        byte ptr [EDI],AL=>DAT_fffffff9
    //         00567b1d     MOV        byte ptr [EDI + -0x1],AH=>DAT_fffffff8
    //         00567b20     SHR        EAX,0x10
    //         00567b23     MOV        byte ptr [EDI + -0x2],AL=>DAT_fffffff7
    //         00567b26     ADD        ESI,0x3
    //         00567b29     SUB        EDI,0x3
    //         00567b2c     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00567B32
undefined FUN_00567b32() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00567b32()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00567b32
    //         00567b32     MOV        AL,byte ptr [ESI]
    //         00567b34     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567b3a     INC        ESI
    //         00567b3b     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         00567b41     MOV        byte ptr [EDI],AL
    //         00567b43     DEC        EDI
    //         00567b44     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00567B4A
undefined FUN_00567b4a() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00567b4a()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00567b4a
    //         00567b4a     MOV        AH,byte ptr [ESI]
    //         00567b4c     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567b52     INC        ESI
    //         00567b53     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         00567b59     MOV        byte ptr [EDI],AH
    //         00567b5b     DEC        EDI
    //         00567b5c     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00567B62
undefined FUN_00567b62() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00567b62()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00567b62
    //         00567b62     MOV        EAX,dword ptr [ESI]
    //         00567b64     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567b6a     ADD        ESI,0x2
    //         00567b6d     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         00567b73     XCHG       AH,AL
    //         00567b75     MOV        word ptr [EDI + -0x1],AX
    //         00567b79     SUB        EDI,0x2
    //         00567b7c     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00567B82
undefined FUN_00567b82() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00567b82()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00567b82
    //         00567b82     MOV        EAX,dword ptr [ESI + -0x1]
    //         00567b85     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567b8b     ADD        ESI,0x2
    //         00567b8e     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         00567b94     SHR        EAX,0x8
    //         00567b97     XCHG       AH,AL
    //         00567b99     MOV        word ptr [EDI + -0x1],AX
    //         00567b9d     SUB        EDI,0x2
    //         00567ba0     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00567BA6
undefined FUN_00567ba6() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00567ba6()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00567ba6
    //         00567ba6     MOV        AL,byte ptr [ESI]
    //         00567ba8     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567bae     INC        ESI
    //         00567baf     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         00567bb5     MOV        byte ptr [EDI],AL
    //         00567bb7     DEC        EDI
    //         00567bb8     MOV        AH,byte ptr [ESI]
    //         00567bba     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567bc0     INC        ESI
    //         00567bc1     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         00567bc7     MOV        byte ptr [EDI],AH
    //         00567bc9     DEC        EDI
    //         00567bca     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00567BD0
undefined FUN_00567bd0() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00567bd0()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00567bd0
    //         00567bd0     MOV        EAX,dword ptr [ESI]
    //         00567bd2     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567bd8     ADD        ESI,0x2
    //         00567bdb     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         00567be1     MOV        byte ptr [EDI],AL
    //         00567be3     MOV        byte ptr [EDI + -0x1],AH
    //         00567be6     SUB        EDI,0x2
    //         00567be9     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00567BEF
undefined FUN_00567bef() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00567bef()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00567bef
    //         00567bef     MOV        EAX,dword ptr [ESI]
    //         00567bf1     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567bf7     ADD        ESI,0x3
    //         00567bfa     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         00567c00     MOV        byte ptr [EDI],AL
    //         00567c02     MOV        byte ptr [EDI + -0x1],AH
    //         00567c05     SHR        EAX,0x10
    //         00567c08     MOV        byte ptr [EDI + -0x2],AL
    //         00567c0b     SUB        EDI,0x3
    //         00567c0e     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00567C14
undefined FUN_00567c14() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00567c14()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00567c14
    //         00567c14     MOV        EAX,dword ptr [ESI + -0x1]
    //         00567c17     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567c1d     ADD        ESI,0x3
    //         00567c20     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         00567c26     MOV        byte ptr [EDI],AH
    //         00567c28     SHR        EAX,0x10
    //         00567c2b     MOV        byte ptr [EDI + -0x1],AL
    //         00567c2e     MOV        byte ptr [EDI + -0x2],AH
    //         00567c31     SUB        EDI,0x3
    //         00567c34     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00567C3A
undefined FUN_00567c3a() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00567c3a()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00567c3a
    //         00567c3a     MOV        EAX,dword ptr [ESI + -0x1]
    //         00567c3d     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567c43     ADD        ESI,0x2
    //         00567c46     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         00567c4c     SHR        EAX,0x8
    //         00567c4f     XCHG       AH,AL
    //         00567c51     MOV        word ptr [EDI + -0x1],AX
    //         00567c55     SUB        EDI,0x2
    //         00567c58     MOV        AH,byte ptr [ESI]
    //         00567c5a     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567c60     INC        ESI
    //         00567c61     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         00567c67     MOV        byte ptr [EDI],AH
    //         00567c69     DEC        EDI
    //         00567c6a     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00567C70
undefined FUN_00567c70() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00567c70()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00567c70
    //         00567c70     MOV        AL,byte ptr [ESI]
    //         00567c72     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567c78     INC        ESI
    //         00567c79     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         00567c7f     MOV        byte ptr [EDI],AL
    //         00567c81     DEC        EDI
    //         00567c82     MOV        EAX,dword ptr [ESI + -0x1]
    //         00567c85     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567c8b     ADD        ESI,0x2
    //         00567c8e     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         00567c94     SHR        EAX,0x8
    //         00567c97     XCHG       AH,AL
    //         00567c99     MOV        word ptr [EDI + -0x1],AX
    //         00567c9d     SUB        EDI,0x2
    //         00567ca0     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00567CA6
undefined FUN_00567ca6() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00567ca6()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00567ca6
    //         00567ca6     MOV        EAX,dword ptr [ESI]
    //         00567ca8     BSWAP      EAX
    //         00567caa     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567cb0     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         00567cb6     ADD        ESI,0x4
    //         00567cb9     MOV        dword ptr [EDI + -0x3],EAX
    //         00567cbc     SUB        EDI,0x4
    //         00567cbf     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00567CC5
undefined FUN_00567cc5() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00567cc5()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00567cc5
    //         00567cc5     MOV        EAX,dword ptr [ESI]
    //         00567cc7     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567ccd     ADD        ESI,0x3
    //         00567cd0     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         00567cd6     MOV        byte ptr [EDI],AL
    //         00567cd8     MOV        byte ptr [EDI + -0x1],AH
    //         00567cdb     SHR        EAX,0x10
    //         00567cde     MOV        byte ptr [EDI + -0x2],AL
    //         00567ce1     SUB        EDI,0x3
    //         00567ce4     MOV        AH,byte ptr [ESI]
    //         00567ce6     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567cec     INC        ESI
    //         00567ced     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         00567cf3     MOV        byte ptr [EDI],AH
    //         00567cf5     DEC        EDI
    //         00567cf6     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00567CFC
undefined FUN_00567cfc() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00567cfc()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00567cfc
    //         00567cfc     MOV        EAX,dword ptr [ESI + -0x1]
    //         00567cff     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567d05     ADD        ESI,0x2
    //         00567d08     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         00567d0e     SHR        EAX,0x8
    //         00567d11     XCHG       AH,AL
    //         00567d13     MOV        word ptr [EDI + -0x1],AX
    //         00567d17     SUB        EDI,0x2
    //         00567d1a     MOV        EAX,dword ptr [ESI + -0x1]
    //         00567d1d     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567d23     ADD        ESI,0x2
    //         00567d26     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         00567d2c     SHR        EAX,0x8
    //         00567d2f     XCHG       AH,AL
    //         00567d31     MOV        word ptr [EDI + -0x1],AX
    //         00567d35     SUB        EDI,0x2
    //         00567d38     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00567D3E
undefined FUN_00567d3e() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00567d3e()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00567d3e
    //         00567d3e     MOV        AL,byte ptr [ESI]
    //         00567d40     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567d46     INC        ESI
    //         00567d47     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         00567d4d     MOV        byte ptr [EDI],AL
    //         00567d4f     DEC        EDI
    //         00567d50     MOV        EAX,dword ptr [ESI + -0x1]
    //         00567d53     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567d59     ADD        ESI,0x3
    //         00567d5c     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         00567d62     MOV        byte ptr [EDI],AH
    //         00567d64     SHR        EAX,0x10
    //         00567d67     MOV        byte ptr [EDI + -0x1],AL
    //         00567d6a     MOV        byte ptr [EDI + -0x2],AH
    //         00567d6d     SUB        EDI,0x3
    //         00567d70     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00567D76
undefined FUN_00567d76() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00567d76()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00567d76
    //         00567d76     MOV        EAX,dword ptr [ESI]
    //         00567d78     BSWAP      EAX
    //         00567d7a     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567d80     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         00567d86     ADD        ESI,0x4
    //         00567d89     MOV        dword ptr [EDI + -0x3],EAX
    //         00567d8c     SUB        EDI,0x4
    //         00567d8f     MOV        AH,byte ptr [ESI]
    //         00567d91     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567d97     INC        ESI
    //         00567d98     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         00567d9e     MOV        byte ptr [EDI],AH
    //         00567da0     DEC        EDI
    //         00567da1     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00567DA7
undefined FUN_00567da7() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00567da7()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00567da7
    //         00567da7     MOV        EAX,dword ptr [ESI]
    //         00567da9     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567daf     ADD        ESI,0x3
    //         00567db2     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         00567db8     MOV        byte ptr [EDI],AL
    //         00567dba     MOV        byte ptr [EDI + -0x1],AH
    //         00567dbd     SHR        EAX,0x10
    //         00567dc0     MOV        byte ptr [EDI + -0x2],AL
    //         00567dc3     SUB        EDI,0x3
    //         00567dc6     MOV        EAX,dword ptr [ESI + -0x1]
    //         00567dc9     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567dcf     ADD        ESI,0x2
    //         00567dd2     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         00567dd8     SHR        EAX,0x8
    //         00567ddb     XCHG       AH,AL
    //         00567ddd     MOV        word ptr [EDI + -0x1],AX
    //         00567de1     SUB        EDI,0x2
    //         00567de4     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00567DEA
undefined FUN_00567dea() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00567dea()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00567dea
    //         00567dea     MOV        EAX,dword ptr [ESI + -0x1]
    //         00567ded     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567df3     ADD        ESI,0x2
    //         00567df6     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         00567dfc     SHR        EAX,0x8
    //         00567dff     XCHG       AH,AL
    //         00567e01     MOV        word ptr [EDI + -0x1],AX
    //         00567e05     SUB        EDI,0x2
    //         00567e08     MOV        EAX,dword ptr [ESI + -0x1]
    //         00567e0b     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567e11     ADD        ESI,0x3
    //         00567e14     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         00567e1a     MOV        byte ptr [EDI],AH
    //         00567e1c     SHR        EAX,0x10
    //         00567e1f     MOV        byte ptr [EDI + -0x1],AL
    //         00567e22     MOV        byte ptr [EDI + -0x2],AH
    //         00567e25     SUB        EDI,0x3
    //         00567e28     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00567E2E
undefined FUN_00567e2e() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00567e2e()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00567e2e
    //         00567e2e     MOV        AL,byte ptr [ESI]
    //         00567e30     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567e36     INC        ESI
    //         00567e37     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         00567e3d     MOV        byte ptr [EDI],AL
    //         00567e3f     DEC        EDI
    //         00567e40     MOV        EAX,dword ptr [ESI]
    //         00567e42     BSWAP      EAX
    //         00567e44     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567e4a     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         00567e50     ADD        ESI,0x4
    //         00567e53     MOV        dword ptr [EDI + -0x3],EAX
    //         00567e56     SUB        EDI,0x4
    //         00567e59     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00567E5F
undefined FUN_00567e5f() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00567e5f()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00567e5f
    //         00567e5f     MOV        EAX,dword ptr [ESI]
    //         00567e61     BSWAP      EAX
    //         00567e63     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567e69     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         00567e6f     ADD        ESI,0x4
    //         00567e72     MOV        dword ptr [EDI + -0x3],EAX
    //         00567e75     SUB        EDI,0x4
    //         00567e78     MOV        EAX,dword ptr [ESI + -0x1]
    //         00567e7b     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567e81     ADD        ESI,0x2
    //         00567e84     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         00567e8a     SHR        EAX,0x8
    //         00567e8d     XCHG       AH,AL
    //         00567e8f     MOV        word ptr [EDI + -0x1],AX=>DAT_fffffffb
    //         00567e93     SUB        EDI,0x2
    //         00567e96     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00567E9C
undefined FUN_00567e9c() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00567e9c()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00567e9c
    //         00567e9c     MOV        EAX,dword ptr [ESI]
    //         00567e9e     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567ea4     ADD        ESI,0x3
    //         00567ea7     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         00567ead     MOV        byte ptr [EDI],AL
    //         00567eaf     MOV        byte ptr [EDI + -0x1],AH
    //         00567eb2     SHR        EAX,0x10
    //         00567eb5     MOV        byte ptr [EDI + -0x2],AL
    //         00567eb8     SUB        EDI,0x3
    //         00567ebb     MOV        EAX,dword ptr [ESI + -0x1]
    //         00567ebe     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567ec4     ADD        ESI,0x3
    //         00567ec7     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         00567ecd     MOV        byte ptr [EDI],AH
    //         00567ecf     SHR        EAX,0x10
    //         00567ed2     MOV        byte ptr [EDI + -0x1],AL
    //         00567ed5     MOV        byte ptr [EDI + -0x2],AH=>DAT_fffffffb
    //         00567ed8     SUB        EDI,0x3
    //         00567edb     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00567EE1
undefined FUN_00567ee1() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00567ee1()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00567ee1
    //         00567ee1     MOV        EAX,dword ptr [ESI + -0x1]
    //         00567ee4     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567eea     ADD        ESI,0x2
    //         00567eed     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         00567ef3     SHR        EAX,0x8
    //         00567ef6     XCHG       AH,AL
    //         00567ef8     MOV        word ptr [EDI + -0x1],AX
    //         00567efc     SUB        EDI,0x2
    //         00567eff     MOV        EAX,dword ptr [ESI]
    //         00567f01     BSWAP      EAX
    //         00567f03     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567f09     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         00567f0f     ADD        ESI,0x4
    //         00567f12     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffb
    //         00567f15     SUB        EDI,0x4
    //         00567f18     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00567F1E
undefined FUN_00567f1e() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00567f1e()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00567f1e
    //         00567f1e     MOV        AL,byte ptr [ESI]
    //         00567f20     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567f26     INC        ESI
    //         00567f27     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         00567f2d     MOV        byte ptr [EDI],AL
    //         00567f2f     DEC        EDI
    //         00567f30     MOV        EAX,dword ptr [ESI]
    //         00567f32     BSWAP      EAX
    //         00567f34     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567f3a     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         00567f40     ADD        ESI,0x4
    //         00567f43     MOV        dword ptr [EDI + -0x3],EAX
    //         00567f46     SUB        EDI,0x4
    //         00567f49     MOV        AH,byte ptr [ESI]
    //         00567f4b     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567f51     INC        ESI
    //         00567f52     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         00567f58     MOV        byte ptr [EDI],AH=>DAT_fffffffb
    //         00567f5a     DEC        EDI
    //         00567f5b     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00567F61
undefined FUN_00567f61() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00567f61()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00567f61
    //         00567f61     MOV        EAX,dword ptr [ESI]
    //         00567f63     BSWAP      EAX
    //         00567f65     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567f6b     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         00567f71     ADD        ESI,0x4
    //         00567f74     MOV        dword ptr [EDI + -0x3],EAX
    //         00567f77     SUB        EDI,0x4
    //         00567f7a     MOV        EAX,dword ptr [ESI + -0x1]
    //         00567f7d     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567f83     ADD        ESI,0x3
    //         00567f86     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         00567f8c     MOV        byte ptr [EDI],AH
    //         00567f8e     SHR        EAX,0x10
    //         00567f91     MOV        byte ptr [EDI + -0x1],AL=>DAT_fffffffb
    //         00567f94     MOV        byte ptr [EDI + -0x2],AH=>DAT_fffffffa
    //         00567f97     SUB        EDI,0x3
    //         00567f9a     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00567FA0
undefined FUN_00567fa0() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00567fa0()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00567fa0
    //         00567fa0     MOV        EAX,dword ptr [ESI]
    //         00567fa2     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567fa8     ADD        ESI,0x3
    //         00567fab     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         00567fb1     MOV        byte ptr [EDI],AL
    //         00567fb3     MOV        byte ptr [EDI + -0x1],AH
    //         00567fb6     SHR        EAX,0x10
    //         00567fb9     MOV        byte ptr [EDI + -0x2],AL
    //         00567fbc     SUB        EDI,0x3
    //         00567fbf     MOV        EAX,dword ptr [ESI]
    //         00567fc1     BSWAP      EAX
    //         00567fc3     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567fc9     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         00567fcf     ADD        ESI,0x4
    //         00567fd2     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffa
    //         00567fd5     SUB        EDI,0x4
    //         00567fd8     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00567FDE
undefined FUN_00567fde() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00567fde()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00567fde
    //         00567fde     MOV        EAX,dword ptr [ESI + -0x1]
    //         00567fe1     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00567fe7     ADD        ESI,0x2
    //         00567fea     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         00567ff0     SHR        EAX,0x8
    //         00567ff3     XCHG       AH,AL
    //         00567ff5     MOV        word ptr [EDI + -0x1],AX
    //         00567ff9     SUB        EDI,0x2
    //         00567ffc     MOV        EAX,dword ptr [ESI]
    //         00567ffe     BSWAP      EAX
    //         00568000     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00568006     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         0056800c     ADD        ESI,0x4
    //         0056800f     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffb
    //         00568012     SUB        EDI,0x4
    //         00568015     MOV        AH,byte ptr [ESI]
    //         00568017     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056801d     INC        ESI
    //         0056801e     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         00568024     MOV        byte ptr [EDI],AH=>DAT_fffffffa
    //         00568026     DEC        EDI
    //         00568027     JMP        dword ptr [DAT_0088c044]
}

