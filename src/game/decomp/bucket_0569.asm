// Auto-generated scaffold unit: bucket_0569.asm
#include "../include/common.h"

// Offset: 0x00569023
undefined FUN_00569023() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00569023()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00569023
    //         00569023     MOV        DL,byte ptr [EDI]
    //         00569025     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569028     MOV        byte ptr [EDI],AL
    //         0056902a     DEC        EDI
    //         0056902b     MOV        EAX,dword ptr [EDI + -0x3]
    //         0056902e     MOV        DL,AL
    //         00569030     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569033     MOV        DL,AH
    //         00569035     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569038     BSWAP      EAX
    //         0056903a     MOV        DL,AL
    //         0056903c     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056903f     MOV        DL,AH
    //         00569041     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569044     BSWAP      EAX
    //         00569046     MOV        dword ptr [EDI + -0x3],EAX
    //         00569049     SUB        EDI,0x4
    //         0056904c     MOV        AX,word ptr [EDI + -0x1]=>DAT_fffffffa
    //         00569050     MOV        DL,AL
    //         00569052     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569055     MOV        DL,AH
    //         00569057     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056905a     MOV        word ptr [EDI + -0x1],AX=>DAT_fffffffa
    //         0056905e     SUB        EDI,0x2
    //         00569061     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00569067
undefined FUN_00569067() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00569067()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00569067                                                 XREF[1]:     0056908b(j)  
    //         00569067     MOV        EAX,dword ptr [EDI + -0x3]=>DAT_fffffff9
    //         0056906a     MOV        DL,AL
    //         0056906c     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056906f     MOV        DL,AH
    //         00569071     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569074     BSWAP      EAX
    //         00569076     MOV        DL,AL
    //         00569078     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056907b     MOV        DL,AH
    //         0056907d     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569080     BSWAP      EAX
    //         00569082     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff9
    //         00569085     SUB        EDI,0x4
    //         00569088     SUB        ECX,0x4
    //         0056908b     JA         FUN_00569067
    //         0056908d     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00569093
undefined FUN_00569093() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00569093()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00569093
    //         00569093     MOV        DL,byte ptr [EDI]
    //         00569095     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569098     MOV        byte ptr [EDI],AL
    //         0056909a     DEC        EDI
    //         0056909b     DEC        ECX
    //                               LAB_0056909c                                                 XREF[1]:     005690c0(j)  
    //         0056909c     MOV        EAX,dword ptr [EDI + -0x3]=>DAT_fffffff8
    //         0056909f     MOV        DL,AL
    //         005690a1     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005690a4     MOV        DL,AH
    //         005690a6     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005690a9     BSWAP      EAX
    //         005690ab     MOV        DL,AL
    //         005690ad     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005690b0     MOV        DL,AH
    //         005690b2     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005690b5     BSWAP      EAX
    //         005690b7     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff8
    //         005690ba     SUB        EDI,0x4
    //         005690bd     SUB        ECX,0x4
    //         005690c0     JA         LAB_0056909c
    //         005690c2     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005690C8
undefined FUN_005690c8() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005690c8()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005690c8
    //         005690c8     MOV        AX,word ptr [EDI + -0x1]
    //         005690cc     MOV        DL,AL
    //         005690ce     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005690d1     MOV        DL,AH
    //         005690d3     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005690d6     MOV        word ptr [EDI + -0x1],AX
    //         005690da     SUB        EDI,0x2
    //         005690dd     SUB        ECX,0x2
    //                               LAB_005690e0                                                 XREF[1]:     00569104(j)  
    //         005690e0     MOV        EAX,dword ptr [EDI + -0x3]=>DAT_fffffffb
    //         005690e3     MOV        DL,AL
    //         005690e5     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005690e8     MOV        DL,AH
    //         005690ea     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005690ed     BSWAP      EAX
    //         005690ef     MOV        DL,AL
    //         005690f1     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005690f4     MOV        DL,AH
    //         005690f6     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005690f9     BSWAP      EAX
    //         005690fb     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffb
    //         005690fe     SUB        EDI,0x4
    //         00569101     SUB        ECX,0x4
    //         00569104     JA         LAB_005690e0
    //         00569106     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x0056910C
undefined FUN_0056910c() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056910c()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056910c
    //         0056910c     MOV        EAX,dword ptr [EDI + -0x2]
    //         0056910f     MOV        DL,AL
    //         00569111     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569114     MOV        DL,AH
    //         00569116     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569119     BSWAP      EAX
    //         0056911b     MOV        DL,AH
    //         0056911d     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569120     BSWAP      EAX
    //         00569122     MOV        dword ptr [EDI + -0x2],EAX
    //         00569125     SUB        EDI,0x3
    //         00569128     SUB        ECX,0x3
    //                               LAB_0056912b                                                 XREF[1]:     0056914f(j)  
    //         0056912b     MOV        EAX,dword ptr [EDI + -0x3]=>DAT_fffffffa
    //         0056912e     MOV        DL,AL
    //         00569130     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569133     MOV        DL,AH
    //         00569135     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569138     BSWAP      EAX
    //         0056913a     MOV        DL,AL
    //         0056913c     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056913f     MOV        DL,AH
    //         00569141     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569144     BSWAP      EAX
    //         00569146     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffa
    //         00569149     SUB        EDI,0x4
    //         0056914c     SUB        ECX,0x4
    //         0056914f     JA         LAB_0056912b
    //         00569151     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00569157
undefined FUN_00569157() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00569157()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00569157
    //         00569157     DEC        ECX
    //                               LAB_00569158                                                 XREF[1]:     0056917c(j)  
    //         00569158     MOV        EAX,dword ptr [EDI + -0x3]=>DAT_fffffff9
    //         0056915b     MOV        DL,AL
    //         0056915d     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569160     MOV        DL,AH
    //         00569162     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569165     BSWAP      EAX
    //         00569167     MOV        DL,AL
    //         00569169     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056916c     MOV        DL,AH
    //         0056916e     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569171     BSWAP      EAX
    //         00569173     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff9
    //         00569176     SUB        EDI,0x4
    //         00569179     SUB        ECX,0x4
    //         0056917c     JA         LAB_00569158
    //         0056917e     MOV        DL,byte ptr [EDI]=>DAT_fffffff8
    //         00569180     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569183     MOV        byte ptr [EDI],AL
    //         00569185     DEC        EDI
    //         00569186     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x0056918C
undefined FUN_0056918c() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056918c()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056918c
    //         0056918c     MOV        DL,byte ptr [EDI]
    //         0056918e     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569191     MOV        byte ptr [EDI],AL
    //         00569193     DEC        EDI
    //         00569194     SUB        ECX,0x2
    //                               LAB_00569197                                                 XREF[1]:     005691bb(j)  
    //         00569197     MOV        EAX,dword ptr [EDI + -0x3]=>DAT_fffffff8
    //         0056919a     MOV        DL,AL
    //         0056919c     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056919f     MOV        DL,AH
    //         005691a1     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005691a4     BSWAP      EAX
    //         005691a6     MOV        DL,AL
    //         005691a8     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005691ab     MOV        DL,AH
    //         005691ad     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005691b0     BSWAP      EAX
    //         005691b2     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff8
    //         005691b5     SUB        EDI,0x4
    //         005691b8     SUB        ECX,0x4
    //         005691bb     JA         LAB_00569197
    //         005691bd     MOV        DL,byte ptr [EDI]=>DAT_fffffffb
    //         005691bf     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005691c2     MOV        byte ptr [EDI],AL=>DAT_fffffffb
    //         005691c4     DEC        EDI
    //         005691c5     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005691CB
undefined FUN_005691cb() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005691cb()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005691cb
    //         005691cb     MOV        AX,word ptr [EDI + -0x1]
    //         005691cf     MOV        DL,AL
    //         005691d1     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005691d4     MOV        DL,AH
    //         005691d6     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005691d9     MOV        word ptr [EDI + -0x1],AX
    //         005691dd     SUB        EDI,0x2
    //         005691e0     SUB        ECX,0x3
    //                               LAB_005691e3                                                 XREF[1]:     00569207(j)  
    //         005691e3     MOV        EAX,dword ptr [EDI + -0x3]=>DAT_fffffffb
    //         005691e6     MOV        DL,AL
    //         005691e8     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005691eb     MOV        DL,AH
    //         005691ed     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005691f0     BSWAP      EAX
    //         005691f2     MOV        DL,AL
    //         005691f4     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005691f7     MOV        DL,AH
    //         005691f9     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005691fc     BSWAP      EAX
    //         005691fe     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffb
    //         00569201     SUB        EDI,0x4
    //         00569204     SUB        ECX,0x4
    //         00569207     JA         LAB_005691e3
    //         00569209     MOV        DL,byte ptr [EDI]=>DAT_fffffffa
    //         0056920b     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056920e     MOV        byte ptr [EDI],AL=>DAT_fffffffa
    //         00569210     DEC        EDI
    //         00569211     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00569217
undefined FUN_00569217() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00569217()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00569217
    //         00569217     MOV        EAX,dword ptr [EDI + -0x2]
    //         0056921a     MOV        DL,AL
    //         0056921c     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056921f     MOV        DL,AH
    //         00569221     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569224     BSWAP      EAX
    //         00569226     MOV        DL,AH
    //         00569228     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056922b     BSWAP      EAX
    //         0056922d     MOV        dword ptr [EDI + -0x2],EAX
    //         00569230     SUB        EDI,0x3
    //         00569233     SUB        ECX,0x4
    //                               LAB_00569236                                                 XREF[1]:     0056925a(j)  
    //         00569236     MOV        EAX,dword ptr [EDI + -0x3]=>DAT_fffffffa
    //         00569239     MOV        DL,AL
    //         0056923b     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056923e     MOV        DL,AH
    //         00569240     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569243     BSWAP      EAX
    //         00569245     MOV        DL,AL
    //         00569247     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056924a     MOV        DL,AH
    //         0056924c     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056924f     BSWAP      EAX
    //         00569251     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffa
    //         00569254     SUB        EDI,0x4
    //         00569257     SUB        ECX,0x4
    //         0056925a     JA         LAB_00569236
    //         0056925c     MOV        DL,byte ptr [EDI]=>DAT_fffffff9
    //         0056925e     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569261     MOV        byte ptr [EDI],AL=>DAT_fffffff9
    //         00569263     DEC        EDI
    //         00569264     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x0056926A
undefined FUN_0056926a() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056926a()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056926a
    //         0056926a     SUB        ECX,0x2
    //                               LAB_0056926d                                                 XREF[1]:     00569291(j)  
    //         0056926d     MOV        EAX,dword ptr [EDI + -0x3]=>DAT_fffffff9
    //         00569270     MOV        DL,AL
    //         00569272     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569275     MOV        DL,AH
    //         00569277     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056927a     BSWAP      EAX
    //         0056927c     MOV        DL,AL
    //         0056927e     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569281     MOV        DL,AH
    //         00569283     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569286     BSWAP      EAX
    //         00569288     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff9
    //         0056928b     SUB        EDI,0x4
    //         0056928e     SUB        ECX,0x4
    //         00569291     JA         LAB_0056926d
    //         00569293     MOV        AX,word ptr [EDI + -0x1]=>DAT_fffffffb
    //         00569297     MOV        DL,AL
    //         00569299     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056929c     MOV        DL,AH
    //         0056929e     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005692a1     MOV        word ptr [EDI + -0x1],AX=>DAT_fffffffb
    //         005692a5     SUB        EDI,0x2
    //         005692a8     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005692AE
undefined FUN_005692ae() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005692ae()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005692ae
    //         005692ae     MOV        DL,byte ptr [EDI]
    //         005692b0     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005692b3     MOV        byte ptr [EDI],AL
    //         005692b5     DEC        EDI
    //         005692b6     SUB        ECX,0x3
    //                               LAB_005692b9                                                 XREF[1]:     005692dd(j)  
    //         005692b9     MOV        EAX,dword ptr [EDI + -0x3]=>DAT_fffffff8
    //         005692bc     MOV        DL,AL
    //         005692be     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005692c1     MOV        DL,AH
    //         005692c3     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005692c6     BSWAP      EAX
    //         005692c8     MOV        DL,AL
    //         005692ca     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005692cd     MOV        DL,AH
    //         005692cf     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005692d2     BSWAP      EAX
    //         005692d4     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff8
    //         005692d7     SUB        EDI,0x4
    //         005692da     SUB        ECX,0x4
    //         005692dd     JA         LAB_005692b9
    //         005692df     MOV        AX,word ptr [EDI + -0x1]=>DAT_fffffffa
    //         005692e3     MOV        DL,AL
    //         005692e5     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005692e8     MOV        DL,AH
    //         005692ea     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005692ed     MOV        word ptr [EDI + -0x1],AX=>DAT_fffffffa
    //         005692f1     SUB        EDI,0x2
    //         005692f4     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005692FA
undefined FUN_005692fa() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005692fa()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005692fa
    //         005692fa     MOV        AX,word ptr [EDI + -0x1]
    //         005692fe     MOV        DL,AL
    //         00569300     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569303     MOV        DL,AH
    //         00569305     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569308     MOV        word ptr [EDI + -0x1],AX
    //         0056930c     SUB        EDI,0x2
    //         0056930f     SUB        ECX,0x4
    //                               LAB_00569312                                                 XREF[1]:     00569336(j)  
    //         00569312     MOV        EAX,dword ptr [EDI + -0x3]=>DAT_fffffffb
    //         00569315     MOV        DL,AL
    //         00569317     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056931a     MOV        DL,AH
    //         0056931c     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056931f     BSWAP      EAX
    //         00569321     MOV        DL,AL
    //         00569323     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569326     MOV        DL,AH
    //         00569328     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056932b     BSWAP      EAX
    //         0056932d     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffb
    //         00569330     SUB        EDI,0x4
    //         00569333     SUB        ECX,0x4
    //         00569336     JA         LAB_00569312
    //         00569338     MOV        AX,word ptr [EDI + -0x1]=>DAT_fffffff9
    //         0056933c     MOV        DL,AL
    //         0056933e     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569341     MOV        DL,AH
    //         00569343     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569346     MOV        word ptr [EDI + -0x1],AX=>DAT_fffffff9
    //         0056934a     SUB        EDI,0x2
    //         0056934d     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00569353
undefined FUN_00569353() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00569353()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00569353
    //         00569353     MOV        EAX,dword ptr [EDI + -0x2]
    //         00569356     MOV        DL,AL
    //         00569358     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056935b     MOV        DL,AH
    //         0056935d     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569360     BSWAP      EAX
    //         00569362     MOV        DL,AH
    //         00569364     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569367     BSWAP      EAX
    //         00569369     MOV        dword ptr [EDI + -0x2],EAX
    //         0056936c     SUB        EDI,0x3
    //         0056936f     SUB        ECX,0x5
    //                               LAB_00569372                                                 XREF[1]:     00569396(j)  
    //         00569372     MOV        EAX,dword ptr [EDI + -0x3]=>DAT_fffffffa
    //         00569375     MOV        DL,AL
    //         00569377     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056937a     MOV        DL,AH
    //         0056937c     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056937f     BSWAP      EAX
    //         00569381     MOV        DL,AL
    //         00569383     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569386     MOV        DL,AH
    //         00569388     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056938b     BSWAP      EAX
    //         0056938d     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffa
    //         00569390     SUB        EDI,0x4
    //         00569393     SUB        ECX,0x4
    //         00569396     JA         LAB_00569372
    //         00569398     MOV        AX,word ptr [EDI + -0x1]=>DAT_fffffff8
    //         0056939c     MOV        DL,AL
    //         0056939e     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005693a1     MOV        DL,AH
    //         005693a3     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005693a6     MOV        word ptr [EDI + -0x1],AX=>DAT_fffffff8
    //         005693aa     SUB        EDI,0x2
    //         005693ad     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005693B3
undefined FUN_005693b3() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005693b3()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005693b3
    //         005693b3     SUB        ECX,0x3
    //                               LAB_005693b6                                                 XREF[1]:     005693da(j)  
    //         005693b6     MOV        EAX,dword ptr [EDI + -0x3]=>DAT_fffffff9
    //         005693b9     MOV        DL,AL
    //         005693bb     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005693be     MOV        DL,AH
    //         005693c0     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005693c3     BSWAP      EAX
    //         005693c5     MOV        DL,AL
    //         005693c7     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005693ca     MOV        DL,AH
    //         005693cc     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005693cf     BSWAP      EAX
    //         005693d1     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff9
    //         005693d4     SUB        EDI,0x4
    //         005693d7     SUB        ECX,0x4
    //         005693da     JA         LAB_005693b6
    //         005693dc     MOV        EAX,dword ptr [EDI + -0x3]=>DAT_fffffff9
    //         005693df     MOV        DL,AH
    //         005693e1     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005693e4     BSWAP      EAX
    //         005693e6     MOV        DL,AH
    //         005693e8     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005693eb     MOV        DL,AL
    //         005693ed     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005693f0     BSWAP      EAX
    //         005693f2     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff9
    //         005693f5     SUB        EDI,0x3
    //         005693f8     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005693FE
undefined FUN_005693fe() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005693fe()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005693fe
    //         005693fe     MOV        DL,byte ptr [EDI]
    //         00569400     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569403     MOV        byte ptr [EDI],AL
    //         00569405     DEC        EDI
    //         00569406     SUB        ECX,0x4
    //                               LAB_00569409                                                 XREF[1]:     0056942d(j)  
    //         00569409     MOV        EAX,dword ptr [EDI + -0x3]=>DAT_fffffff8
    //         0056940c     MOV        DL,AL
    //         0056940e     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569411     MOV        DL,AH
    //         00569413     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569416     BSWAP      EAX
    //         00569418     MOV        DL,AL
    //         0056941a     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056941d     MOV        DL,AH
    //         0056941f     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569422     BSWAP      EAX
    //         00569424     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff8
    //         00569427     SUB        EDI,0x4
    //         0056942a     SUB        ECX,0x4
    //         0056942d     JA         LAB_00569409
    //         0056942f     MOV        EAX,dword ptr [EDI + -0x3]=>DAT_fffffff8
    //         00569432     MOV        DL,AH
    //         00569434     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569437     BSWAP      EAX
    //         00569439     MOV        DL,AH
    //         0056943b     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056943e     MOV        DL,AL
    //         00569440     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569443     BSWAP      EAX
    //         00569445     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff8
    //         00569448     SUB        EDI,0x3
    //         0056944b     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00569451
undefined FUN_00569451() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00569451()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00569451
    //         00569451     MOV        AX,word ptr [EDI + -0x1]
    //         00569455     MOV        DL,AL
    //         00569457     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056945a     MOV        DL,AH
    //         0056945c     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056945f     MOV        word ptr [EDI + -0x1],AX
    //         00569463     SUB        EDI,0x2
    //         00569466     SUB        ECX,0x5
    //                               LAB_00569469                                                 XREF[1]:     0056948d(j)  
    //         00569469     MOV        EAX,dword ptr [EDI + -0x3]=>DAT_fffffffb
    //         0056946c     MOV        DL,AL
    //         0056946e     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569471     MOV        DL,AH
    //         00569473     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569476     BSWAP      EAX
    //         00569478     MOV        DL,AL
    //         0056947a     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056947d     MOV        DL,AH
    //         0056947f     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569482     BSWAP      EAX
    //         00569484     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffb
    //         00569487     SUB        EDI,0x4
    //         0056948a     SUB        ECX,0x4
    //         0056948d     JA         LAB_00569469
    //         0056948f     MOV        EAX,dword ptr [EDI + -0x3]=>DAT_fffffff7
    //         00569492     MOV        DL,AH
    //         00569494     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569497     BSWAP      EAX
    //         00569499     MOV        DL,AH
    //         0056949b     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056949e     MOV        DL,AL
    //         005694a0     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005694a3     BSWAP      EAX
    //         005694a5     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff7
    //         005694a8     SUB        EDI,0x3
    //         005694ab     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005694B1
undefined FUN_005694b1() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005694b1()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005694b1
    //         005694b1     MOV        EAX,dword ptr [EDI + -0x2]
    //         005694b4     MOV        DL,AL
    //         005694b6     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005694b9     MOV        DL,AH
    //         005694bb     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005694be     BSWAP      EAX
    //         005694c0     MOV        DL,AH
    //         005694c2     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005694c5     BSWAP      EAX
    //         005694c7     MOV        dword ptr [EDI + -0x2],EAX
    //         005694ca     SUB        EDI,0x3
    //         005694cd     SUB        ECX,0x6
    //                               LAB_005694d0                                                 XREF[1]:     005694f4(j)  
    //         005694d0     MOV        EAX,dword ptr [EDI + -0x3]=>DAT_fffffffa
    //         005694d3     MOV        DL,AL
    //         005694d5     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005694d8     MOV        DL,AH
    //         005694da     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005694dd     BSWAP      EAX
    //         005694df     MOV        DL,AL
    //         005694e1     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005694e4     MOV        DL,AH
    //         005694e6     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005694e9     BSWAP      EAX
    //         005694eb     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffa
    //         005694ee     SUB        EDI,0x4
    //         005694f1     SUB        ECX,0x4
    //         005694f4     JA         LAB_005694d0
    //         005694f6     MOV        EAX,dword ptr [EDI + -0x3]=>DAT_fffffff6
    //         005694f9     MOV        DL,AH
    //         005694fb     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005694fe     BSWAP      EAX
    //         00569500     MOV        DL,AH
    //         00569502     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569505     MOV        DL,AL
    //         00569507     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056950a     BSWAP      EAX
    //         0056950c     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff6
    //         0056950f     SUB        EDI,0x3
    //         00569512     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00569518
undefined FUN_00569518() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00569518()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00569518
    //         00569518     MOV        DL,byte ptr [EDI]
    //         0056951a     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056951d     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00569523     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569529     MOV        byte ptr [EDI],AL
    //         0056952b     DEC        EDI
    //         0056952c     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00569532
undefined FUN_00569532() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00569532()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00569532
    //         00569532     MOV        DL,byte ptr [EDI]
    //         00569534     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569537     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056953d     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569543     MOV        byte ptr [EDI],AH
    //         00569545     DEC        EDI
    //         00569546     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x0056954C
undefined FUN_0056954c() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056954c()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056954c
    //         0056954c     MOV        AX,word ptr [EDI + -0x1]
    //         00569550     MOV        DL,AL
    //         00569552     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569555     MOV        DL,AH
    //         00569557     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056955a     SHL        EAX,0x8
    //         0056955d     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00569563     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569569     SHR        EAX,0x8
    //         0056956c     MOV        word ptr [EDI + -0x1],AX
    //         00569570     SUB        EDI,0x2
    //         00569573     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00569579
undefined FUN_00569579() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00569579()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00569579
    //         00569579     MOV        AX,word ptr [EDI + -0x1]
    //         0056957d     MOV        DL,AL
    //         0056957f     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569582     MOV        DL,AH
    //         00569584     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569587     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056958d     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569593     MOV        word ptr [EDI + -0x1],AX
    //         00569597     SUB        EDI,0x2
    //         0056959a     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005695A0
undefined FUN_005695a0() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005695a0()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005695a0
    //         005695a0     MOV        DL,byte ptr [EDI]
    //         005695a2     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005695a5     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005695ab     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         005695b1     MOV        byte ptr [EDI],AL
    //         005695b3     DEC        EDI
    //         005695b4     MOV        DL,byte ptr [EDI]
    //         005695b6     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005695b9     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005695bf     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         005695c5     MOV        byte ptr [EDI],AH
    //         005695c7     DEC        EDI
    //         005695c8     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005695CE
undefined FUN_005695ce() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005695ce()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005695ce
    //         005695ce     MOV        EAX,dword ptr [EDI + -0x2]
    //         005695d1     MOV        DL,AL
    //         005695d3     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005695d6     MOV        DL,AH
    //         005695d8     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005695db     BSWAP      EAX
    //         005695dd     MOV        DL,AH
    //         005695df     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005695e2     MOV        DL,AL
    //         005695e4     BSWAP      EAX
    //         005695e6     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005695ec     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         005695f2     BSWAP      EAX
    //         005695f4     MOV        AL,DL
    //         005695f6     BSWAP      EAX
    //         005695f8     MOV        dword ptr [EDI + -0x2],EAX
    //         005695fb     SUB        EDI,0x3
    //         005695fe     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00569604
undefined FUN_00569604() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00569604()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00569604
    //         00569604     MOV        EAX,dword ptr [EDI + -0x3]
    //         00569607     MOV        DL,AH
    //         00569609     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056960c     BSWAP      EAX
    //         0056960e     MOV        DL,AH
    //         00569610     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569613     MOV        DL,AL
    //         00569615     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569618     BSWAP      EAX
    //         0056961a     MOV        DL,AL
    //         0056961c     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00569622     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569628     MOV        AL,DL
    //         0056962a     MOV        dword ptr [EDI + -0x3],EAX
    //         0056962d     SUB        EDI,0x3
    //         00569630     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00569636
undefined FUN_00569636() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00569636()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00569636
    //         00569636     MOV        AX,word ptr [EDI + -0x1]
    //         0056963a     MOV        DL,AL
    //         0056963c     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056963f     MOV        DL,AH
    //         00569641     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569644     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056964a     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569650     MOV        word ptr [EDI + -0x1],AX
    //         00569654     SUB        EDI,0x2
    //         00569657     MOV        DL,byte ptr [EDI]
    //         00569659     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056965c     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00569662     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569668     MOV        byte ptr [EDI],AH
    //         0056966a     DEC        EDI
    //         0056966b     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00569671
undefined FUN_00569671() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00569671()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00569671
    //         00569671     MOV        DL,byte ptr [EDI]
    //         00569673     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569676     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056967c     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569682     MOV        byte ptr [EDI],AL
    //         00569684     DEC        EDI
    //         00569685     MOV        AX,word ptr [EDI + -0x1]
    //         00569689     MOV        DL,AL
    //         0056968b     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056968e     MOV        DL,AH
    //         00569690     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569693     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00569699     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         0056969f     MOV        word ptr [EDI + -0x1],AX
    //         005696a3     SUB        EDI,0x2
    //         005696a6     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005696AC
undefined FUN_005696ac() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005696ac()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005696ac
    //         005696ac     MOV        EAX,dword ptr [EDI + -0x3]
    //         005696af     MOV        DL,AL
    //         005696b1     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005696b4     MOV        DL,AH
    //         005696b6     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005696b9     BSWAP      EAX
    //         005696bb     MOV        DL,AL
    //         005696bd     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005696c0     MOV        DL,AH
    //         005696c2     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005696c5     BSWAP      EAX
    //         005696c7     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005696cd     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         005696d3     MOV        dword ptr [EDI + -0x3],EAX
    //         005696d6     SUB        EDI,0x4
    //         005696d9     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005696DF
undefined FUN_005696df() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005696df()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005696df
    //         005696df     MOV        EAX,dword ptr [EDI + -0x2]
    //         005696e2     MOV        DL,AL
    //         005696e4     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005696e7     MOV        DL,AH
    //         005696e9     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005696ec     BSWAP      EAX
    //         005696ee     MOV        DL,AH
    //         005696f0     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005696f3     MOV        DL,AL
    //         005696f5     BSWAP      EAX
    //         005696f7     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005696fd     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569703     BSWAP      EAX
    //         00569705     MOV        AL,DL
    //         00569707     BSWAP      EAX
    //         00569709     MOV        dword ptr [EDI + -0x2],EAX
    //         0056970c     SUB        EDI,0x3
    //         0056970f     MOV        DL,byte ptr [EDI]
    //         00569711     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569714     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056971a     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569720     MOV        byte ptr [EDI],AH
    //         00569722     DEC        EDI
    //         00569723     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00569729
undefined FUN_00569729() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00569729()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00569729
    //         00569729     MOV        AX,word ptr [EDI + -0x1]
    //         0056972d     MOV        DL,AL
    //         0056972f     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569732     MOV        DL,AH
    //         00569734     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569737     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056973d     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569743     MOV        word ptr [EDI + -0x1],AX
    //         00569747     SUB        EDI,0x2
    //         0056974a     MOV        AX,word ptr [EDI + -0x1]
    //         0056974e     MOV        DL,AL
    //         00569750     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569753     MOV        DL,AH
    //         00569755     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569758     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056975e     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569764     MOV        word ptr [EDI + -0x1],AX
    //         00569768     SUB        EDI,0x2
    //         0056976b     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00569771
undefined FUN_00569771() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00569771()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00569771
    //         00569771     MOV        DL,byte ptr [EDI]
    //         00569773     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569776     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056977c     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569782     MOV        byte ptr [EDI],AL
    //         00569784     DEC        EDI
    //         00569785     MOV        EAX,dword ptr [EDI + -0x3]
    //         00569788     MOV        DL,AH
    //         0056978a     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056978d     BSWAP      EAX
    //         0056978f     MOV        DL,AH
    //         00569791     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569794     MOV        DL,AL
    //         00569796     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569799     BSWAP      EAX
    //         0056979b     MOV        DL,AL
    //         0056979d     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005697a3     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         005697a9     MOV        AL,DL
    //         005697ab     MOV        dword ptr [EDI + -0x3],EAX
    //         005697ae     SUB        EDI,0x3
    //         005697b1     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005697B7
undefined FUN_005697b7() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005697b7()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005697b7
    //         005697b7     MOV        EAX,dword ptr [EDI + -0x3]
    //         005697ba     MOV        DL,AL
    //         005697bc     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005697bf     MOV        DL,AH
    //         005697c1     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005697c4     BSWAP      EAX
    //         005697c6     MOV        DL,AL
    //         005697c8     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005697cb     MOV        DL,AH
    //         005697cd     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005697d0     BSWAP      EAX
    //         005697d2     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005697d8     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         005697de     MOV        dword ptr [EDI + -0x3],EAX
    //         005697e1     SUB        EDI,0x4
    //         005697e4     MOV        DL,byte ptr [EDI]
    //         005697e6     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005697e9     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005697ef     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         005697f5     MOV        byte ptr [EDI],AH
    //         005697f7     DEC        EDI
    //         005697f8     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005697FE
undefined FUN_005697fe() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005697fe()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005697fe
    //         005697fe     MOV        EAX,dword ptr [EDI + -0x2]
    //         00569801     MOV        DL,AL
    //         00569803     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569806     MOV        DL,AH
    //         00569808     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056980b     BSWAP      EAX
    //         0056980d     MOV        DL,AH
    //         0056980f     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569812     MOV        DL,AL
    //         00569814     BSWAP      EAX
    //         00569816     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056981c     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569822     BSWAP      EAX
    //         00569824     MOV        AL,DL
    //         00569826     BSWAP      EAX
    //         00569828     MOV        dword ptr [EDI + -0x2],EAX
    //         0056982b     SUB        EDI,0x3
    //         0056982e     MOV        AX,word ptr [EDI + -0x1]
    //         00569832     MOV        DL,AL
    //         00569834     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569837     MOV        DL,AH
    //         00569839     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056983c     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00569842     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569848     MOV        word ptr [EDI + -0x1],AX
    //         0056984c     SUB        EDI,0x2
    //         0056984f     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00569855
undefined FUN_00569855() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00569855()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00569855
    //         00569855     MOV        AX,word ptr [EDI + -0x1]
    //         00569859     MOV        DL,AL
    //         0056985b     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056985e     MOV        DL,AH
    //         00569860     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569863     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00569869     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         0056986f     MOV        word ptr [EDI + -0x1],AX
    //         00569873     SUB        EDI,0x2
    //         00569876     MOV        EAX,dword ptr [EDI + -0x3]=>DAT_fffffffb
    //         00569879     MOV        DL,AH
    //         0056987b     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056987e     BSWAP      EAX
    //         00569880     MOV        DL,AH
    //         00569882     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569885     MOV        DL,AL
    //         00569887     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056988a     BSWAP      EAX
    //         0056988c     MOV        DL,AL
    //         0056988e     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00569894     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         0056989a     MOV        AL,DL
    //         0056989c     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffb
    //         0056989f     SUB        EDI,0x3
    //         005698a2     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005698A8
undefined FUN_005698a8() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005698a8()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005698a8
    //         005698a8     MOV        DL,byte ptr [EDI]
    //         005698aa     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005698ad     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005698b3     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         005698b9     MOV        byte ptr [EDI],AL
    //         005698bb     DEC        EDI
    //         005698bc     MOV        EAX,dword ptr [EDI + -0x3]
    //         005698bf     MOV        DL,AL
    //         005698c1     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005698c4     MOV        DL,AH
    //         005698c6     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005698c9     BSWAP      EAX
    //         005698cb     MOV        DL,AL
    //         005698cd     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005698d0     MOV        DL,AH
    //         005698d2     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005698d5     BSWAP      EAX
    //         005698d7     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005698dd     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         005698e3     MOV        dword ptr [EDI + -0x3],EAX
    //         005698e6     SUB        EDI,0x4
    //         005698e9     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005698EF
undefined FUN_005698ef() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005698ef()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005698ef
    //         005698ef     MOV        EAX,dword ptr [EDI + -0x3]
    //         005698f2     MOV        DL,AL
    //         005698f4     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005698f7     MOV        DL,AH
    //         005698f9     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005698fc     BSWAP      EAX
    //         005698fe     MOV        DL,AL
    //         00569900     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569903     MOV        DL,AH
    //         00569905     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569908     BSWAP      EAX
    //         0056990a     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00569910     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569916     MOV        dword ptr [EDI + -0x3],EAX
    //         00569919     SUB        EDI,0x4
    //         0056991c     MOV        AX,word ptr [EDI + -0x1]=>DAT_fffffffb
    //         00569920     MOV        DL,AL
    //         00569922     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569925     MOV        DL,AH
    //         00569927     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056992a     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00569930     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569936     MOV        word ptr [EDI + -0x1],AX=>DAT_fffffffb
    //         0056993a     SUB        EDI,0x2
    //         0056993d     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00569943
undefined FUN_00569943() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00569943()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00569943
    //         00569943     MOV        EAX,dword ptr [EDI + -0x2]
    //         00569946     MOV        DL,AL
    //         00569948     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         0056994b     MOV        DL,AH
    //         0056994d     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569950     BSWAP      EAX
    //         00569952     MOV        DL,AH
    //         00569954     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569957     MOV        DL,AL
    //         00569959     BSWAP      EAX
    //         0056995b     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00569961     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569967     BSWAP      EAX
    //         00569969     MOV        AL,DL
    //         0056996b     BSWAP      EAX
    //         0056996d     MOV        dword ptr [EDI + -0x2],EAX
    //         00569970     SUB        EDI,0x3
    //         00569973     MOV        EAX,dword ptr [EDI + -0x3]=>DAT_fffffffa
    //         00569976     MOV        DL,AH
    //         00569978     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056997b     BSWAP      EAX
    //         0056997d     MOV        DL,AH
    //         0056997f     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569982     MOV        DL,AL
    //         00569984     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569987     BSWAP      EAX
    //         00569989     MOV        DL,AL
    //         0056998b     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00569991     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569997     MOV        AL,DL
    //         00569999     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffa
    //         0056999c     SUB        EDI,0x3
    //         0056999f     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005699A5
undefined FUN_005699a5() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005699a5()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005699a5
    //         005699a5     MOV        AX,word ptr [EDI + -0x1]
    //         005699a9     MOV        DL,AL
    //         005699ab     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005699ae     MOV        DL,AH
    //         005699b0     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005699b3     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005699b9     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         005699bf     MOV        word ptr [EDI + -0x1],AX
    //         005699c3     SUB        EDI,0x2
    //         005699c6     MOV        EAX,dword ptr [EDI + -0x3]=>DAT_fffffffb
    //         005699c9     MOV        DL,AL
    //         005699cb     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005699ce     MOV        DL,AH
    //         005699d0     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005699d3     BSWAP      EAX
    //         005699d5     MOV        DL,AL
    //         005699d7     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005699da     MOV        DL,AH
    //         005699dc     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         005699df     BSWAP      EAX
    //         005699e1     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         005699e7     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         005699ed     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffb
    //         005699f0     SUB        EDI,0x4
    //         005699f3     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x005699F9
undefined FUN_005699f9() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005699f9()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005699f9
    //         005699f9     MOV        DL,byte ptr [EDI]
    //         005699fb     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         005699fe     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00569a04     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569a0a     MOV        byte ptr [EDI],AL
    //         00569a0c     DEC        EDI
    //         00569a0d     MOV        EAX,dword ptr [EDI + -0x3]
    //         00569a10     MOV        DL,AL
    //         00569a12     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569a15     MOV        DL,AH
    //         00569a17     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569a1a     BSWAP      EAX
    //         00569a1c     MOV        DL,AL
    //         00569a1e     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569a21     MOV        DL,AH
    //         00569a23     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569a26     BSWAP      EAX
    //         00569a28     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00569a2e     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569a34     MOV        dword ptr [EDI + -0x3],EAX
    //         00569a37     SUB        EDI,0x4
    //         00569a3a     MOV        DL,byte ptr [EDI]=>DAT_fffffffb
    //         00569a3c     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569a3f     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00569a45     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569a4b     MOV        byte ptr [EDI],AH=>DAT_fffffffb
    //         00569a4d     DEC        EDI
    //         00569a4e     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00569A54
undefined FUN_00569a54() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00569a54()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00569a54
    //         00569a54     MOV        EAX,dword ptr [EDI + -0x3]
    //         00569a57     MOV        DL,AL
    //         00569a59     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569a5c     MOV        DL,AH
    //         00569a5e     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569a61     BSWAP      EAX
    //         00569a63     MOV        DL,AL
    //         00569a65     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569a68     MOV        DL,AH
    //         00569a6a     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569a6d     BSWAP      EAX
    //         00569a6f     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00569a75     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569a7b     MOV        dword ptr [EDI + -0x3],EAX
    //         00569a7e     SUB        EDI,0x4
    //         00569a81     MOV        EAX,dword ptr [EDI + -0x3]=>DAT_fffffff9
    //         00569a84     MOV        DL,AH
    //         00569a86     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569a89     BSWAP      EAX
    //         00569a8b     MOV        DL,AH
    //         00569a8d     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569a90     MOV        DL,AL
    //         00569a92     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569a95     BSWAP      EAX
    //         00569a97     MOV        DL,AL
    //         00569a99     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00569a9f     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569aa5     MOV        AL,DL
    //         00569aa7     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff9
    //         00569aaa     SUB        EDI,0x3
    //         00569aad     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00569AB3
undefined FUN_00569ab3() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00569ab3()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00569ab3
    //         00569ab3     MOV        EAX,dword ptr [EDI + -0x2]
    //         00569ab6     MOV        DL,AL
    //         00569ab8     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569abb     MOV        DL,AH
    //         00569abd     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569ac0     BSWAP      EAX
    //         00569ac2     MOV        DL,AH
    //         00569ac4     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569ac7     MOV        DL,AL
    //         00569ac9     BSWAP      EAX
    //         00569acb     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00569ad1     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569ad7     BSWAP      EAX
    //         00569ad9     MOV        AL,DL
    //         00569adb     BSWAP      EAX
    //         00569add     MOV        dword ptr [EDI + -0x2],EAX
    //         00569ae0     SUB        EDI,0x3
    //         00569ae3     MOV        EAX,dword ptr [EDI + -0x3]=>DAT_fffffffa
    //         00569ae6     MOV        DL,AL
    //         00569ae8     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569aeb     MOV        DL,AH
    //         00569aed     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569af0     BSWAP      EAX
    //         00569af2     MOV        DL,AL
    //         00569af4     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569af7     MOV        DL,AH
    //         00569af9     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569afc     BSWAP      EAX
    //         00569afe     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00569b04     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569b0a     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffa
    //         00569b0d     SUB        EDI,0x4
    //         00569b10     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00569B16
undefined FUN_00569b16() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00569b16()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00569b16
    //         00569b16     MOV        AX,word ptr [EDI + -0x1]
    //         00569b1a     MOV        DL,AL
    //         00569b1c     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569b1f     MOV        DL,AH
    //         00569b21     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569b24     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00569b2a     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569b30     MOV        word ptr [EDI + -0x1],AX
    //         00569b34     SUB        EDI,0x2
    //         00569b37     MOV        EAX,dword ptr [EDI + -0x3]=>DAT_fffffffb
    //         00569b3a     MOV        DL,AL
    //         00569b3c     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569b3f     MOV        DL,AH
    //         00569b41     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569b44     BSWAP      EAX
    //         00569b46     MOV        DL,AL
    //         00569b48     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569b4b     MOV        DL,AH
    //         00569b4d     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569b50     BSWAP      EAX
    //         00569b52     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00569b58     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569b5e     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffb
    //         00569b61     SUB        EDI,0x4
    //         00569b64     MOV        DL,byte ptr [EDI]=>DAT_fffffffa
    //         00569b66     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569b69     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00569b6f     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569b75     MOV        byte ptr [EDI],AH=>DAT_fffffffa
    //         00569b77     DEC        EDI
    //         00569b78     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00569B7E
undefined FUN_00569b7e() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00569b7e()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00569b7e
    //         00569b7e     MOV        DL,byte ptr [EDI]
    //         00569b80     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569b83     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00569b89     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569b8f     MOV        byte ptr [EDI],AL
    //         00569b91     DEC        EDI
    //         00569b92     MOV        EAX,dword ptr [EDI + -0x3]
    //         00569b95     MOV        DL,AL
    //         00569b97     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569b9a     MOV        DL,AH
    //         00569b9c     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569b9f     BSWAP      EAX
    //         00569ba1     MOV        DL,AL
    //         00569ba3     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569ba6     MOV        DL,AH
    //         00569ba8     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569bab     BSWAP      EAX
    //         00569bad     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00569bb3     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569bb9     MOV        dword ptr [EDI + -0x3],EAX
    //         00569bbc     SUB        EDI,0x4
    //         00569bbf     MOV        AX,word ptr [EDI + -0x1]=>DAT_fffffffa
    //         00569bc3     MOV        DL,AL
    //         00569bc5     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569bc8     MOV        DL,AH
    //         00569bca     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569bcd     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00569bd3     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569bd9     MOV        word ptr [EDI + -0x1],AX=>DAT_fffffffa
    //         00569bdd     SUB        EDI,0x2
    //         00569be0     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00569BE6
undefined FUN_00569be6() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00569be6()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00569be6                                                 XREF[1]:     00569c16(j)  
    //         00569be6     MOV        EAX,dword ptr [EDI + -0x3]=>DAT_fffffff9
    //         00569be9     MOV        DL,AL
    //         00569beb     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569bee     MOV        DL,AH
    //         00569bf0     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569bf3     BSWAP      EAX
    //         00569bf5     MOV        DL,AL
    //         00569bf7     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569bfa     MOV        DL,AH
    //         00569bfc     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569bff     BSWAP      EAX
    //         00569c01     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00569c07     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569c0d     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff9
    //         00569c10     SUB        EDI,0x4
    //         00569c13     SUB        ECX,0x4
    //         00569c16     JA         FUN_00569be6
    //         00569c18     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00569C1E
undefined FUN_00569c1e() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00569c1e()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00569c1e
    //         00569c1e     MOV        DL,byte ptr [EDI]
    //         00569c20     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569c23     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00569c29     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569c2f     MOV        byte ptr [EDI],AL
    //         00569c31     DEC        EDI
    //         00569c32     DEC        ECX
    //                               LAB_00569c33                                                 XREF[1]:     00569c63(j)  
    //         00569c33     MOV        EAX,dword ptr [EDI + -0x3]=>DAT_fffffff8
    //         00569c36     MOV        DL,AL
    //         00569c38     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569c3b     MOV        DL,AH
    //         00569c3d     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569c40     BSWAP      EAX
    //         00569c42     MOV        DL,AL
    //         00569c44     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569c47     MOV        DL,AH
    //         00569c49     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569c4c     BSWAP      EAX
    //         00569c4e     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00569c54     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569c5a     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff8
    //         00569c5d     SUB        EDI,0x4
    //         00569c60     SUB        ECX,0x4
    //         00569c63     JA         LAB_00569c33
    //         00569c65     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00569C6B
undefined FUN_00569c6b() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00569c6b()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00569c6b
    //         00569c6b     MOV        AX,word ptr [EDI + -0x1]
    //         00569c6f     MOV        DL,AL
    //         00569c71     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569c74     MOV        DL,AH
    //         00569c76     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569c79     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00569c7f     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569c85     MOV        word ptr [EDI + -0x1],AX
    //         00569c89     SUB        EDI,0x2
    //         00569c8c     SUB        ECX,0x2
    //                               LAB_00569c8f                                                 XREF[1]:     00569cbf(j)  
    //         00569c8f     MOV        EAX,dword ptr [EDI + -0x3]=>DAT_fffffffb
    //         00569c92     MOV        DL,AL
    //         00569c94     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569c97     MOV        DL,AH
    //         00569c99     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569c9c     BSWAP      EAX
    //         00569c9e     MOV        DL,AL
    //         00569ca0     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569ca3     MOV        DL,AH
    //         00569ca5     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569ca8     BSWAP      EAX
    //         00569caa     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00569cb0     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569cb6     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffb
    //         00569cb9     SUB        EDI,0x4
    //         00569cbc     SUB        ECX,0x4
    //         00569cbf     JA         LAB_00569c8f
    //         00569cc1     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00569CC7
undefined FUN_00569cc7() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00569cc7()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00569cc7
    //         00569cc7     MOV        EAX,dword ptr [EDI + -0x2]
    //         00569cca     MOV        DL,AL
    //         00569ccc     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569ccf     MOV        DL,AH
    //         00569cd1     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569cd4     BSWAP      EAX
    //         00569cd6     MOV        DL,AH
    //         00569cd8     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569cdb     MOV        DL,AL
    //         00569cdd     BSWAP      EAX
    //         00569cdf     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00569ce5     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569ceb     BSWAP      EAX
    //         00569ced     MOV        AL,DL
    //         00569cef     BSWAP      EAX
    //         00569cf1     MOV        dword ptr [EDI + -0x2],EAX
    //         00569cf4     SUB        EDI,0x3
    //         00569cf7     SUB        ECX,0x3
    //                               LAB_00569cfa                                                 XREF[1]:     00569d2a(j)  
    //         00569cfa     MOV        EAX,dword ptr [EDI + -0x3]=>DAT_fffffffa
    //         00569cfd     MOV        DL,AL
    //         00569cff     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569d02     MOV        DL,AH
    //         00569d04     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569d07     BSWAP      EAX
    //         00569d09     MOV        DL,AL
    //         00569d0b     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569d0e     MOV        DL,AH
    //         00569d10     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569d13     BSWAP      EAX
    //         00569d15     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00569d1b     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569d21     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffa
    //         00569d24     SUB        EDI,0x4
    //         00569d27     SUB        ECX,0x4
    //         00569d2a     JA         LAB_00569cfa
    //         00569d2c     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00569D32
undefined FUN_00569d32() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00569d32()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00569d32
    //         00569d32     DEC        ECX
    //                               LAB_00569d33                                                 XREF[1]:     00569d63(j)  
    //         00569d33     MOV        EAX,dword ptr [EDI + -0x3]=>DAT_fffffff9
    //         00569d36     MOV        DL,AL
    //         00569d38     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569d3b     MOV        DL,AH
    //         00569d3d     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569d40     BSWAP      EAX
    //         00569d42     MOV        DL,AL
    //         00569d44     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569d47     MOV        DL,AH
    //         00569d49     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569d4c     BSWAP      EAX
    //         00569d4e     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00569d54     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569d5a     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff9
    //         00569d5d     SUB        EDI,0x4
    //         00569d60     SUB        ECX,0x4
    //         00569d63     JA         LAB_00569d33
    //         00569d65     MOV        DL,byte ptr [EDI]
    //         00569d67     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569d6a     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00569d70     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569d76     MOV        byte ptr [EDI],AH
    //         00569d78     DEC        EDI
    //         00569d79     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00569D7F
undefined FUN_00569d7f() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00569d7f()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00569d7f
    //         00569d7f     MOV        DL,byte ptr [EDI]
    //         00569d81     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569d84     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00569d8a     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569d90     MOV        byte ptr [EDI],AL
    //         00569d92     DEC        EDI
    //         00569d93     SUB        ECX,0x2
    //                               LAB_00569d96                                                 XREF[1]:     00569dc6(j)  
    //         00569d96     MOV        EAX,dword ptr [EDI + -0x3]=>DAT_fffffff8
    //         00569d99     MOV        DL,AL
    //         00569d9b     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569d9e     MOV        DL,AH
    //         00569da0     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569da3     BSWAP      EAX
    //         00569da5     MOV        DL,AL
    //         00569da7     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569daa     MOV        DL,AH
    //         00569dac     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569daf     BSWAP      EAX
    //         00569db1     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00569db7     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569dbd     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff8
    //         00569dc0     SUB        EDI,0x4
    //         00569dc3     SUB        ECX,0x4
    //         00569dc6     JA         LAB_00569d96
    //         00569dc8     MOV        DL,byte ptr [EDI]=>DAT_fffffffb
    //         00569dca     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569dcd     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00569dd3     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569dd9     MOV        byte ptr [EDI],AH=>DAT_fffffffb
    //         00569ddb     DEC        EDI
    //         00569ddc     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00569DE2
undefined FUN_00569de2() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00569de2()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00569de2
    //         00569de2     MOV        AX,word ptr [EDI + -0x1]
    //         00569de6     MOV        DL,AL
    //         00569de8     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569deb     MOV        DL,AH
    //         00569ded     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569df0     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00569df6     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569dfc     MOV        word ptr [EDI + -0x1],AX
    //         00569e00     SUB        EDI,0x2
    //         00569e03     SUB        ECX,0x3
    //                               LAB_00569e06                                                 XREF[1]:     00569e36(j)  
    //         00569e06     MOV        EAX,dword ptr [EDI + -0x3]=>DAT_fffffffb
    //         00569e09     MOV        DL,AL
    //         00569e0b     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569e0e     MOV        DL,AH
    //         00569e10     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569e13     BSWAP      EAX
    //         00569e15     MOV        DL,AL
    //         00569e17     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569e1a     MOV        DL,AH
    //         00569e1c     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569e1f     BSWAP      EAX
    //         00569e21     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00569e27     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569e2d     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffb
    //         00569e30     SUB        EDI,0x4
    //         00569e33     SUB        ECX,0x4
    //         00569e36     JA         LAB_00569e06
    //         00569e38     MOV        DL,byte ptr [EDI]=>DAT_fffffffa
    //         00569e3a     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569e3d     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00569e43     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569e49     MOV        byte ptr [EDI],AH=>DAT_fffffffa
    //         00569e4b     DEC        EDI
    //         00569e4c     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00569E52
undefined FUN_00569e52() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00569e52()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00569e52
    //         00569e52     MOV        EAX,dword ptr [EDI + -0x2]
    //         00569e55     MOV        DL,AL
    //         00569e57     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569e5a     MOV        DL,AH
    //         00569e5c     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569e5f     BSWAP      EAX
    //         00569e61     MOV        DL,AH
    //         00569e63     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569e66     MOV        DL,AL
    //         00569e68     BSWAP      EAX
    //         00569e6a     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00569e70     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569e76     BSWAP      EAX
    //         00569e78     MOV        AL,DL
    //         00569e7a     BSWAP      EAX
    //         00569e7c     MOV        dword ptr [EDI + -0x2],EAX
    //         00569e7f     SUB        EDI,0x3
    //         00569e82     SUB        ECX,0x4
    //                               LAB_00569e85                                                 XREF[1]:     00569eb5(j)  
    //         00569e85     MOV        EAX,dword ptr [EDI + -0x3]=>DAT_fffffffa
    //         00569e88     MOV        DL,AL
    //         00569e8a     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569e8d     MOV        DL,AH
    //         00569e8f     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569e92     BSWAP      EAX
    //         00569e94     MOV        DL,AL
    //         00569e96     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569e99     MOV        DL,AH
    //         00569e9b     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569e9e     BSWAP      EAX
    //         00569ea0     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00569ea6     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569eac     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffa
    //         00569eaf     SUB        EDI,0x4
    //         00569eb2     SUB        ECX,0x4
    //         00569eb5     JA         LAB_00569e85
    //         00569eb7     MOV        DL,byte ptr [EDI]=>DAT_fffffff9
    //         00569eb9     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569ebc     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00569ec2     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569ec8     MOV        byte ptr [EDI],AH=>DAT_fffffff9
    //         00569eca     DEC        EDI
    //         00569ecb     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00569ED1
undefined FUN_00569ed1() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00569ed1()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00569ed1
    //         00569ed1     SUB        ECX,0x2
    //                               LAB_00569ed4                                                 XREF[1]:     00569f04(j)  
    //         00569ed4     MOV        EAX,dword ptr [EDI + -0x3]=>DAT_fffffff9
    //         00569ed7     MOV        DL,AL
    //         00569ed9     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569edc     MOV        DL,AH
    //         00569ede     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569ee1     BSWAP      EAX
    //         00569ee3     MOV        DL,AL
    //         00569ee5     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569ee8     MOV        DL,AH
    //         00569eea     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569eed     BSWAP      EAX
    //         00569eef     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00569ef5     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569efb     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff9
    //         00569efe     SUB        EDI,0x4
    //         00569f01     SUB        ECX,0x4
    //         00569f04     JA         LAB_00569ed4
    //         00569f06     MOV        AX,word ptr [EDI + -0x1]=>DAT_fffffffb
    //         00569f0a     MOV        DL,AL
    //         00569f0c     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569f0f     MOV        DL,AH
    //         00569f11     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569f14     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00569f1a     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569f20     MOV        word ptr [EDI + -0x1],AX=>DAT_fffffffb
    //         00569f24     SUB        EDI,0x2
    //         00569f27     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00569F2D
undefined FUN_00569f2d() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00569f2d()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00569f2d
    //         00569f2d     MOV        DL,byte ptr [EDI]
    //         00569f2f     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569f32     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00569f38     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569f3e     MOV        byte ptr [EDI],AL
    //         00569f40     DEC        EDI
    //         00569f41     SUB        ECX,0x3
    //                               LAB_00569f44                                                 XREF[1]:     00569f74(j)  
    //         00569f44     MOV        EAX,dword ptr [EDI + -0x3]=>DAT_fffffff8
    //         00569f47     MOV        DL,AL
    //         00569f49     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569f4c     MOV        DL,AH
    //         00569f4e     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569f51     BSWAP      EAX
    //         00569f53     MOV        DL,AL
    //         00569f55     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569f58     MOV        DL,AH
    //         00569f5a     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569f5d     BSWAP      EAX
    //         00569f5f     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00569f65     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569f6b     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffff8
    //         00569f6e     SUB        EDI,0x4
    //         00569f71     SUB        ECX,0x4
    //         00569f74     JA         LAB_00569f44
    //         00569f76     MOV        AX,word ptr [EDI + -0x1]=>DAT_fffffffa
    //         00569f7a     MOV        DL,AL
    //         00569f7c     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569f7f     MOV        DL,AH
    //         00569f81     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569f84     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00569f8a     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569f90     MOV        word ptr [EDI + -0x1],AX=>DAT_fffffffa
    //         00569f94     SUB        EDI,0x2
    //         00569f97     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x00569F9D
undefined FUN_00569f9d() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00569f9d()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00569f9d
    //         00569f9d     MOV        AX,word ptr [EDI + -0x1]
    //         00569fa1     MOV        DL,AL
    //         00569fa3     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569fa6     MOV        DL,AH
    //         00569fa8     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569fab     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00569fb1     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569fb7     MOV        word ptr [EDI + -0x1],AX
    //         00569fbb     SUB        EDI,0x2
    //         00569fbe     SUB        ECX,0x4
    //                               LAB_00569fc1                                                 XREF[1]:     00569ff1(j)  
    //         00569fc1     MOV        EAX,dword ptr [EDI + -0x3]=>DAT_fffffffb
    //         00569fc4     MOV        DL,AL
    //         00569fc6     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569fc9     MOV        DL,AH
    //         00569fcb     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569fce     BSWAP      EAX
    //         00569fd0     MOV        DL,AL
    //         00569fd2     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569fd5     MOV        DL,AH
    //         00569fd7     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         00569fda     BSWAP      EAX
    //         00569fdc     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         00569fe2     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         00569fe8     MOV        dword ptr [EDI + -0x3],EAX=>DAT_fffffffb
    //         00569feb     SUB        EDI,0x4
    //         00569fee     SUB        ECX,0x4
    //         00569ff1     JA         LAB_00569fc1
    //         00569ff3     MOV        AX,word ptr [EDI + -0x1]=>DAT_fffffff9
    //         00569ff7     MOV        DL,AL
    //         00569ff9     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         00569ffc     MOV        DL,AH
    //         00569ffe     MOV        AH,byte ptr [EDX + EBX*0x1]
    //         0056a001     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056a007     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         0056a00d     MOV        word ptr [EDI + -0x1],AX=>DAT_fffffff9
    //         0056a011     SUB        EDI,0x2
    //         0056a014     JMP        dword ptr [DAT_0088c044]
}

