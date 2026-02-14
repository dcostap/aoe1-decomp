// Auto-generated scaffold unit: bucket_0558.asm
#include "../include/common.h"

// Offset: 0x00558050
undefined dtold() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined ___dtold()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               ___dtold                                                     XREF[1]:     __fltout:00557fdd(c)  
    //         00558050     PUSH       EBX
    //         00558051     PUSH       EBP
    //         00558052     PUSH       ESI
    //         00558053     MOV        ESI,dword ptr [ESP + Stack[0x8]]
    //         00558057     PUSH       EDI
    //         00558058     MOV        EBX,0x80000000
    //         0055805d     MOV        CX,word ptr [ESI + 0x6]
    //         00558061     MOV        EDX,dword ptr [ESI + 0x4]
    //         00558064     MOV        EAX,ECX
    //         00558066     MOV        EDI,dword ptr [ESI]
    //         00558068     SHR        EAX,0x4
    //         0055806b     AND        ECX,0x8000
    //         00558071     AND        EAX,0x7ff
    //         00558076     MOV        EBP,ECX
    //         00558078     MOV        ECX,EAX
    //         0055807a     AND        EDX,0xfffff
    //         00558080     AND        ECX,0xffff
    //         00558086     JZ         LAB_0055809f
    //         00558088     CMP        ECX,0x7ff
    //         0055808e     JZ         LAB_00558098
    //         00558090     LEA        ESI,[EAX + 0x3c00]
    //         00558096     JMP        LAB_005580c1
    //                               LAB_00558098                                                 XREF[1]:     0055808e(j)  
    //         00558098     MOV        ESI,0x7fff
    //         0055809d     JMP        LAB_005580c1
    //                               LAB_0055809f                                                 XREF[1]:     00558086(j)  
    //         0055809f     XOR        EBX,EBX
    //         005580a1     CMP        EDX,EBX
    //         005580a3     JNZ        LAB_005580bb
    //         005580a5     CMP        EDI,EBX
    //         005580a7     JNZ        LAB_005580bb
    //         005580a9     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         005580ad     MOV        dword ptr [EAX + 0x4],EBX
    //         005580b0     MOV        dword ptr [EAX],EBX
    //         005580b2     MOV        word ptr [EAX + 0x8],BX
    //         005580b6     POP        EDI
    //         005580b7     POP        ESI
    //         005580b8     POP        EBP
    //         005580b9     POP        EBX
    //         005580ba     RET
    //                               LAB_005580bb                                                 XREF[2]:     005580a3(j), 005580a7(j)  
    //         005580bb     LEA        ESI,[EAX + 0x3c01]
    //                               LAB_005580c1                                                 XREF[2]:     00558096(j), 0055809d(j)  
    //         005580c1     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         005580c5     MOV        ECX,EDI
    //         005580c7     SHR        ECX,0x15
    //         005580ca     SHL        EDX,0xb
    //         005580cd     OR         ECX,EDX
    //         005580cf     OR         ECX,EBX
    //         005580d1     SHL        EDI,0xb
    //         005580d4     TEST       ECX,0x80000000
    //         005580da     MOV        dword ptr [EAX + 0x4],ECX
    //         005580dd     MOV        dword ptr [EAX],EDI
    //         005580df     JNZ        LAB_00558103
    //                               LAB_005580e1                                                 XREF[1]:     00558101(j)  
    //         005580e1     MOV        EDX,dword ptr [EAX]
    //         005580e3     ADD        ECX,ECX
    //         005580e5     MOV        EDI,EDX
    //         005580e7     ADD        EDX,EDX
    //         005580e9     SHR        EDI,0x1f
    //         005580ec     OR         EDI,ECX
    //         005580ee     ADD        ESI,0xffff
    //         005580f4     MOV        ECX,EDI
    //         005580f6     MOV        dword ptr [EAX + 0x4],EDI
    //         005580f9     TEST       ECX,0x80000000
    //         005580ff     MOV        dword ptr [EAX],EDX
    //         00558101     JZ         LAB_005580e1
    //                               LAB_00558103                                                 XREF[1]:     005580df(j)  
    //         00558103     OR         ESI,EBP
    //         00558105     POP        EDI
    //         00558106     MOV        word ptr [EAX + 0x8],SI
    //         0055810a     POP        ESI
    //         0055810b     POP        EBP
    //         0055810c     POP        EBX
    //         0055810d     RET
}

// Offset: 0x00558110
undefined fptrap() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __fptrap()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __fptrap                                                     XREF[10]:    __output:00551c2d(c), 
    //                                                                                                         __output:00551c4b(c), 
    //                                                                                                         __output:00551c62(c), 
    //                                                                                                         __input:00552e04(c), 0058fbc8(*), 
    //                                                                                                         0058fbcc(*), 0058fbd0(*), 
    //                                                                                                         0058fbd4(*), 0058fbd8(*), 
    //                                                                                                         0058fbdc(*)  
    //         00558110     PUSH       0x2
    //         00558112     CALL       __amsg_exit                                      undefined __amsg_exit()
    //         00558117     ADD        ESP,0x4
    //         0055811a     RET
}

// Offset: 0x00558120
undefined isatty() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __isatty()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __isatty                                                     XREF[2]:     __stbuf:0055165a(c), 
    //                                                                                                         __flsbuf:0055348e(c)  
    //         00558120     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00558124     MOV        ECX,dword ptr [__nhandle]
    //         0055812a     CMP        EAX,ECX
    //         0055812c     JC         LAB_00558131
    //         0055812e     XOR        EAX,EAX
    //         00558130     RET
    //                               LAB_00558131                                                 XREF[1]:     0055812c(j)  
    //         00558131     MOV        ECX,EAX
    //         00558133     AND        EAX,0x1f
    //         00558136     SAR        ECX,0x5
    //         00558139     MOV        EDX,dword ptr [ECX*0x4 + ___pioinfo]
    //         00558140     MOV        AL,byte ptr [EDX + EAX*0x8 + 0x4]
    //         00558144     AND        EAX,0x40
    //         00558147     RET
}

// Offset: 0x00558150
undefined wctomb() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * wctomb                                                                                                *
    //                              *********************************************************************************************************
    //                              undefined __cdecl wctomb()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _wctomb                                                      XREF[2]:     __output:00551a1a(c), 
    //                               wctomb                                                                    __output:00551f3b(c)  
    //         00558150     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00558154     TEST       EAX,EAX
    //         00558156     JNZ        LAB_00558159
    //         00558158     RET
    //                               LAB_00558159                                                 XREF[1]:     00558156(j)  
    //         00558159     MOV        ECX,dword ptr [DAT_008882c0]
    //         0055815f     TEST       ECX,ECX
    //         00558161     JNZ        LAB_00558177
    //         00558163     MOV        CX,word ptr [ESP + Stack[0x8]]
    //         00558168     CMP        CX,0xff
    //         0055816d     JA         LAB_005581b3
    //         0055816f     MOV        byte ptr [EAX],CL
    //         00558171     MOV        EAX,0x1
    //         00558176     RET
    //                               LAB_00558177                                                 XREF[1]:     00558161(j)  
    //         00558177     MOV        EDX,dword ptr [___mb_cur_max]                    = 00000001h
    //         0055817d     LEA        ECX=>Stack[0x4],[ESP + 0x4]
    //         00558181     PUSH       ECX
    //         00558182     MOV        ECX,dword ptr [___lc_codepage]
    //         00558188     PUSH       0x0
    //         0055818a     PUSH       EDX
    //         0055818b     PUSH       EAX
    //         0055818c     LEA        EAX=>Stack[0x8],[ESP + 0x18]
    //         00558190     PUSH       0x1
    //         00558192     PUSH       EAX
    //         00558193     PUSH       0x220
    //         00558198     PUSH       ECX
    //         00558199     MOV        dword ptr [ESP + Stack[0x4]],0x0
    //         005581a1     CALL       dword ptr [->KERNEL32.DLL::WideCharToMultiByte]  = 0048b8a0
    //         005581a7     TEST       EAX,EAX
    //         005581a9     JZ         LAB_005581b3
    //         005581ab     MOV        ECX,dword ptr [ESP + 0x4]
    //         005581af     TEST       ECX,ECX
    //         005581b1     JZ         LAB_005581c0
    //                               LAB_005581b3                                                 XREF[2]:     0055816d(j), 005581a9(j)  
    //         005581b3     MOV        dword ptr [_errno],0x2a                          = align(4)
    //         005581bd     OR         EAX,0xffffffff
    //                               LAB_005581c0                                                 XREF[1]:     005581b1(j)  
    //         005581c0     RET
}

// Offset: 0x005581D0
undefined aulldiv() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __aulldiv()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __aulldiv                                                    XREF[2]:     __output:00551e24(c), 
    //                                                                                                         FUN_0055be70:0055beab(c)  
    //         005581d0     PUSH       EBX
    //         005581d1     PUSH       ESI
    //         005581d2     MOV        EAX,dword ptr [ESP + Stack[0x10]]
    //         005581d6     OR         EAX,EAX
    //         005581d8     JNZ        LAB_005581f2
    //         005581da     MOV        ECX,dword ptr [ESP + Stack[0xc]]
    //         005581de     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         005581e2     XOR        EDX,EDX
    //         005581e4     DIV        ECX
    //         005581e6     MOV        EBX,EAX
    //         005581e8     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         005581ec     DIV        ECX
    //         005581ee     MOV        EDX,EBX
    //         005581f0     JMP        LAB_00558233
    //                               LAB_005581f2                                                 XREF[1]:     005581d8(j)  
    //         005581f2     MOV        ECX,EAX
    //         005581f4     MOV        EBX,dword ptr [ESP + Stack[0xc]]
    //         005581f8     MOV        EDX,dword ptr [ESP + Stack[0x8]]
    //         005581fc     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //                               LAB_00558200                                                 XREF[1]:     0055820a(j)  
    //         00558200     SHR        ECX,0x1
    //         00558202     RCR        EBX,0x1
    //         00558204     SHR        EDX,0x1
    //         00558206     RCR        EAX,0x1
    //         00558208     OR         ECX,ECX
    //         0055820a     JNZ        LAB_00558200
    //         0055820c     DIV        EBX
    //         0055820e     MOV        ESI,EAX
    //         00558210     MUL        dword ptr [ESP + Stack[0x10]]
    //         00558214     MOV        ECX,EAX
    //         00558216     MOV        EAX,dword ptr [ESP + Stack[0xc]]
    //         0055821a     MUL        ESI
    //         0055821c     ADD        EDX,ECX
    //         0055821e     JC         LAB_0055822e
    //         00558220     CMP        EDX,dword ptr [ESP + Stack[0x8]]
    //         00558224     JA         LAB_0055822e
    //         00558226     JC         LAB_0055822f
    //         00558228     CMP        EAX,dword ptr [ESP + Stack[0x4]]
    //         0055822c     JBE        LAB_0055822f
    //                               LAB_0055822e                                                 XREF[2]:     0055821e(j), 00558224(j)  
    //         0055822e     DEC        ESI
    //                               LAB_0055822f                                                 XREF[2]:     00558226(j), 0055822c(j)  
    //         0055822f     XOR        EDX,EDX
    //         00558231     MOV        EAX,ESI
    //                               LAB_00558233                                                 XREF[1]:     005581f0(j)  
    //         00558233     POP        ESI
    //         00558234     POP        EBX
    //         00558235     RET        0x10
}

// Offset: 0x00558240
undefined aullrem() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __aullrem()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __aullrem                                                    XREF[2]:     __output:00551e12(c), 
    //                                                                                                         FUN_0055be70:0055be9a(c)  
    //         00558240     PUSH       EBX
    //         00558241     MOV        EAX,dword ptr [ESP + Stack[0x10]]
    //         00558245     OR         EAX,EAX
    //         00558247     JNZ        LAB_00558261
    //         00558249     MOV        ECX,dword ptr [ESP + Stack[0xc]]
    //         0055824d     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         00558251     XOR        EDX,EDX
    //         00558253     DIV        ECX
    //         00558255     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00558259     DIV        ECX
    //         0055825b     MOV        EAX,EDX
    //         0055825d     XOR        EDX,EDX
    //         0055825f     JMP        LAB_005582b1
    //                               LAB_00558261                                                 XREF[1]:     00558247(j)  
    //         00558261     MOV        ECX,EAX
    //         00558263     MOV        EBX,dword ptr [ESP + Stack[0xc]]
    //         00558267     MOV        EDX,dword ptr [ESP + Stack[0x8]]
    //         0055826b     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //                               LAB_0055826f                                                 XREF[1]:     00558279(j)  
    //         0055826f     SHR        ECX,0x1
    //         00558271     RCR        EBX,0x1
    //         00558273     SHR        EDX,0x1
    //         00558275     RCR        EAX,0x1
    //         00558277     OR         ECX,ECX
    //         00558279     JNZ        LAB_0055826f
    //         0055827b     DIV        EBX
    //         0055827d     MOV        ECX,EAX
    //         0055827f     MUL        dword ptr [ESP + Stack[0x10]]
    //         00558283     XCHG       EAX,ECX
    //         00558284     MUL        dword ptr [ESP + Stack[0xc]]
    //         00558288     ADD        EDX,ECX
    //         0055828a     JC         LAB_0055829a
    //         0055828c     CMP        EDX,dword ptr [ESP + Stack[0x8]]
    //         00558290     JA         LAB_0055829a
    //         00558292     JC         LAB_005582a2
    //         00558294     CMP        EAX,dword ptr [ESP + Stack[0x4]]
    //         00558298     JBE        LAB_005582a2
    //                               LAB_0055829a                                                 XREF[2]:     0055828a(j), 00558290(j)  
    //         0055829a     SUB        EAX,dword ptr [ESP + Stack[0xc]]
    //         0055829e     SBB        EDX,dword ptr [ESP + Stack[0x10]]
    //                               LAB_005582a2                                                 XREF[2]:     00558292(j), 00558298(j)  
    //         005582a2     SUB        EAX,dword ptr [ESP + Stack[0x4]]
    //         005582a6     SBB        EDX,dword ptr [ESP + Stack[0x8]]
    //         005582aa     NEG        EDX
    //         005582ac     NEG        EAX
    //         005582ae     SBB        EDX,0x0
    //                               LAB_005582b1                                                 XREF[1]:     0055825f(j)  
    //         005582b1     POP        EBX
    //         005582b2     RET        0x10
}

// Offset: 0x005582C0
undefined mbtowc() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * mbtowc                                                                                                *
    //                              *********************************************************************************************************
    //                              undefined __cdecl mbtowc()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _mbtowc                                                      XREF[1]:     __input:00552769(c)  
    //                               mbtowc
    //         005582c0     PUSH       ESI
    //         005582c1     MOV        ESI,dword ptr [ESP + Stack[0x8]]
    //         005582c5     TEST       ESI,ESI
    //         005582c7     PUSH       EDI
    //         005582c8     JZ         LAB_005583b7
    //         005582ce     MOV        EDI,dword ptr [ESP + Stack[0xc]]
    //         005582d2     TEST       EDI,EDI
    //         005582d4     JZ         LAB_005583b7
    //         005582da     MOV        AL,byte ptr [ESI]
    //         005582dc     TEST       AL,AL
    //         005582de     JNZ        LAB_005582f6
    //         005582e0     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         005582e4     TEST       EAX,EAX
    //         005582e6     JZ         LAB_005583b7
    //         005582ec     MOV        word ptr [EAX],0x0
    //         005582f1     XOR        EAX,EAX
    //         005582f3     POP        EDI
    //         005582f4     POP        ESI
    //         005582f5     RET
    //                               LAB_005582f6                                                 XREF[1]:     005582de(j)  
    //         005582f6     MOV        ECX,dword ptr [DAT_008882c0]
    //         005582fc     TEST       ECX,ECX
    //         005582fe     JNZ        LAB_0055831b
    //         00558300     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         00558304     TEST       ECX,ECX
    //         00558306     JZ         LAB_005583af
    //         0055830c     MOVZX      AX,AL
    //         00558310     MOV        word ptr [ECX],AX
    //         00558313     MOV        EAX,0x1
    //         00558318     POP        EDI
    //         00558319     POP        ESI
    //         0055831a     RET
    //                               LAB_0055831b                                                 XREF[1]:     005582fe(j)  
    //         0055831b     MOV        ECX,dword ptr [__pctype]                         = 005920da
    //         00558321     AND        EAX,0xff
    //         00558326     TEST       byte ptr [ECX + EAX*0x2 + 0x1]=>DAT_005920db,0
    //         0055832b     JZ         LAB_0055837c
    //         0055832d     MOV        EAX,[___mb_cur_max]                              = 00000001h
    //         00558332     CMP        EAX,0x1
    //         00558335     JLE        LAB_00558361
    //         00558337     CMP        EDI,EAX
    //         00558339     JL         LAB_00558363
    //         0055833b     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         0055833f     XOR        EDX,EDX
    //         00558341     TEST       ECX,ECX
    //         00558343     SETNZ      DL
    //         00558346     PUSH       EDX
    //         00558347     PUSH       ECX
    //         00558348     PUSH       EAX
    //         00558349     MOV        EAX,[___lc_codepage]
    //         0055834e     PUSH       ESI
    //         0055834f     PUSH       0x9
    //         00558351     PUSH       EAX
    //         00558352     CALL       dword ptr [->KERNEL32.DLL::MultiByteToWideChar]  = 0048b8da
    //         00558358     TEST       EAX,EAX
    //         0055835a     MOV        EAX,[___mb_cur_max]                              = 00000001h
    //         0055835f     JNZ        LAB_005583b9
    //                               LAB_00558361                                                 XREF[1]:     00558335(j)  
    //         00558361     CMP        EDI,EAX
    //                               LAB_00558363                                                 XREF[1]:     00558339(j)  
    //         00558363     JC         LAB_0055839f
    //         00558365     MOV        CL,byte ptr [ESI + 0x1]
    //         00558368     TEST       CL,CL
    //         0055836a     JNZ        LAB_005583b9
    //         0055836c     MOV        dword ptr [_errno],0x2a                          = align(4)
    //         00558376     OR         EAX,0xffffffff
    //         00558379     POP        EDI
    //         0055837a     POP        ESI
    //         0055837b     RET
    //                               LAB_0055837c                                                 XREF[1]:     0055832b(j)  
    //         0055837c     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00558380     XOR        ECX,ECX
    //         00558382     MOV        EDX,dword ptr [___lc_codepage]
    //         00558388     TEST       EAX,EAX
    //         0055838a     SETNZ      CL
    //         0055838d     PUSH       ECX
    //         0055838e     PUSH       EAX
    //         0055838f     PUSH       0x1
    //         00558391     PUSH       ESI
    //         00558392     PUSH       0x9
    //         00558394     PUSH       EDX
    //         00558395     CALL       dword ptr [->KERNEL32.DLL::MultiByteToWideChar]  = 0048b8da
    //         0055839b     TEST       EAX,EAX
    //         0055839d     JNZ        LAB_005583af
    //                               LAB_0055839f                                                 XREF[1]:     00558363(j)  
    //         0055839f     MOV        dword ptr [_errno],0x2a                          = align(4)
    //         005583a9     OR         EAX,0xffffffff
    //         005583ac     POP        EDI
    //         005583ad     POP        ESI
    //         005583ae     RET
    //                               LAB_005583af                                                 XREF[2]:     00558306(j), 0055839d(j)  
    //         005583af     MOV        EAX,0x1
    //         005583b4     POP        EDI
    //         005583b5     POP        ESI
    //         005583b6     RET
    //                               LAB_005583b7                                                 XREF[3]:     005582c8(j), 005582d4(j), 
    //                                                                                                         005582e6(j)  
    //         005583b7     XOR        EAX,EAX
    //                               LAB_005583b9                                                 XREF[2]:     0055835f(j), 0055836a(j)  
    //         005583b9     POP        EDI
    //         005583ba     POP        ESI
    //         005583bb     RET
}

// Offset: 0x005583C0
undefined allshl() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __allshl()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __allshl                                                     XREF[2]:     __input:00552954(c), 
    //                                                                                                         __input:005529a1(c)  
    //         005583c0     CMP        CL,0x40
    //         005583c3     JNC        LAB_005583da
    //         005583c5     CMP        CL,0x20
    //         005583c8     JNC        LAB_005583d0
    //         005583ca     SHLD       EDX,EAX,CL
    //         005583cd     SHL        EAX,CL
    //         005583cf     RET
    //                               LAB_005583d0                                                 XREF[1]:     005583c8(j)  
    //         005583d0     MOV        EDX,EAX
    //         005583d2     XOR        EAX,EAX
    //         005583d4     AND        CL,0x1f
    //         005583d7     SHL        EDX,CL
    //         005583d9     RET
    //                               LAB_005583da                                                 XREF[1]:     005583c3(j)  
    //         005583da     XOR        EAX,EAX
    //         005583dc     XOR        EDX,EDX
    //         005583de     RET
}

// Offset: 0x005583E0
undefined ungetc() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * ungetc                                                                                                *
    //                              *********************************************************************************************************
    //                              undefined __cdecl ungetc()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _ungetc                                                      XREF[1]:     FUN_00553070:0055307f(c)  
    //                               ungetc
    //         005583e0     PUSH       EBX
    //         005583e1     MOV        EBX,dword ptr [ESP + Stack[0x4]]
    //         005583e5     CMP        EBX,-0x1
    //         005583e8     PUSH       ESI
    //         005583e9     JZ         LAB_0055845d
    //         005583eb     MOV        ESI,dword ptr [ESP + Stack[0x8]]
    //         005583ef     MOV        EAX,dword ptr [ESI + 0xc]
    //         005583f2     TEST       AL,0x1
    //         005583f4     JNZ        LAB_005583fe
    //         005583f6     TEST       AL,0x80
    //         005583f8     JZ         LAB_0055845d
    //         005583fa     TEST       AL,0x2
    //         005583fc     JNZ        LAB_0055845d
    //                               LAB_005583fe                                                 XREF[1]:     005583f4(j)  
    //         005583fe     MOV        EAX,dword ptr [ESI + 0x8]
    //         00558401     TEST       EAX,EAX
    //         00558403     JNZ        LAB_0055840e
    //         00558405     PUSH       ESI
    //         00558406     CALL       __getbuf                                         undefined __getbuf()
    //         0055840b     ADD        ESP,0x4
    //                               LAB_0055840e                                                 XREF[1]:     00558403(j)  
    //         0055840e     MOV        EAX,dword ptr [ESI]
    //         00558410     MOV        ECX,dword ptr [ESI + 0x8]
    //         00558413     CMP        EAX,ECX
    //         00558415     JNZ        LAB_00558421
    //         00558417     MOV        ECX,dword ptr [ESI + 0x4]
    //         0055841a     TEST       ECX,ECX
    //         0055841c     JNZ        LAB_0055845d
    //         0055841e     INC        EAX
    //         0055841f     MOV        dword ptr [ESI],EAX
    //                               LAB_00558421                                                 XREF[1]:     00558415(j)  
    //         00558421     TEST       byte ptr [ESI + 0xc],0x40
    //         00558425     JZ         LAB_0055843b
    //         00558427     MOV        EDX,dword ptr [ESI]
    //         00558429     DEC        EDX
    //         0055842a     MOV        EAX,EDX
    //         0055842c     MOV        dword ptr [ESI],EDX
    //         0055842e     CMP        byte ptr [EAX],BL
    //         00558430     JZ         LAB_00558442
    //         00558432     INC        EAX
    //         00558433     MOV        dword ptr [ESI],EAX
    //         00558435     OR         EAX,0xffffffff
    //         00558438     POP        ESI
    //         00558439     POP        EBX
    //         0055843a     RET
    //                               LAB_0055843b                                                 XREF[1]:     00558425(j)  
    //         0055843b     MOV        EAX,dword ptr [ESI]
    //         0055843d     DEC        EAX
    //         0055843e     MOV        dword ptr [ESI],EAX
    //         00558440     MOV        byte ptr [EAX],BL
    //                               LAB_00558442                                                 XREF[1]:     00558430(j)  
    //         00558442     MOV        EAX,dword ptr [ESI + 0xc]
    //         00558445     MOV        EDX,dword ptr [ESI + 0x4]
    //         00558448     AND        AL,0xef
    //         0055844a     INC        EDX
    //         0055844b     OR         AL,0x1
    //         0055844d     MOV        dword ptr [ESI + 0x4],EDX
    //         00558450     MOV        dword ptr [ESI + 0xc],EAX
    //         00558453     MOV        EAX,EBX
    //         00558455     AND        EAX,0xff
    //         0055845a     POP        ESI
    //         0055845b     POP        EBX
    //         0055845c     RET
    //                               LAB_0055845d                                                 XREF[4]:     005583e9(j), 005583f8(j), 
    //                                                                                                         005583fc(j), 0055841c(j)  
    //         0055845d     POP        ESI
    //         0055845e     OR         EAX,0xffffffff
    //         00558461     POP        EBX
    //         00558462     RET
}

// Offset: 0x00558470
undefined getbuf() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __getbuf()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __getbuf                                                     XREF[3]:     __filbuf:00553115(c), 
    //                                                                                                         __flsbuf:0055349b(c), 
    //                                                                                                         ungetc:00558406(c)  
    //         00558470     MOV        EAX,[__cflush]
    //         00558475     PUSH       0x1000
    //         0055847a     INC        EAX
    //         0055847b     MOV        [__cflush],EAX
    //         00558480     CALL       malloc                                           undefined malloc()
    //         00558485     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         00558489     ADD        ESP,0x4
    //         0055848c     TEST       EAX,EAX
    //         0055848e     MOV        dword ptr [ECX + 0x8],EAX
    //         00558491     MOV        EAX,dword ptr [ECX + 0xc]
    //         00558494     JZ         LAB_005584af
    //         00558496     MOV        EDX,dword ptr [ECX + 0x8]
    //         00558499     OR         AL,0x8
    //         0055849b     MOV        dword ptr [ECX + 0xc],EAX
    //         0055849e     MOV        dword ptr [ECX + 0x18],0x1000
    //         005584a5     MOV        dword ptr [ECX],EDX
    //         005584a7     MOV        dword ptr [ECX + 0x4],0x0
    //         005584ae     RET
    //                               LAB_005584af                                                 XREF[1]:     00558494(j)  
    //         005584af     OR         AL,0x4
    //         005584b1     MOV        dword ptr [ECX + 0x18],0x2
    //         005584b8     MOV        dword ptr [ECX + 0xc],EAX
    //         005584bb     LEA        EAX,[ECX + 0x14]
    //         005584be     MOV        EDX,EAX
    //         005584c0     MOV        dword ptr [ECX + 0x8],EAX
    //         005584c3     MOV        dword ptr [ECX],EDX
    //         005584c5     MOV        dword ptr [ECX + 0x4],0x0
    //         005584cc     RET
}

// Offset: 0x005584D0
undefined wcstombs() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * wcstombs                                                                                              *
    //                              *********************************************************************************************************
    //                              undefined __cdecl wcstombs()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     005584e1(W), 0055855d(*), 005585a4(*), 00558679(*)  
    //                               _wcstombs                                                    XREF[2]:     __tzset:00553651(c), 
    //                               wcstombs                                                                  __tzset:00553666(c)  
    //         005584d0     PUSH       ECX
    //         005584d1     PUSH       EBX
    //         005584d2     PUSH       EBP
    //         005584d3     MOV        EBP,dword ptr [ESP + Stack[0xc]]
    //         005584d7     PUSH       ESI
    //         005584d8     PUSH       EDI
    //         005584d9     MOV        EDI,dword ptr [ESP + Stack[0x4]]
    //         005584dd     XOR        EAX,EAX
    //         005584df     TEST       EDI,EDI
    //         005584e1     MOV        dword ptr [ESP + local_4],EAX
    //         005584e5     JZ         LAB_005584f1
    //         005584e7     TEST       EBP,EBP
    //         005584e9     JNZ        LAB_005584f1
    //         005584eb     POP        EDI
    //         005584ec     POP        ESI
    //         005584ed     POP        EBP
    //         005584ee     POP        EBX
    //         005584ef     POP        ECX
    //         005584f0     RET
    //                               LAB_005584f1                                                 XREF[2]:     005584e5(j), 005584e9(j)  
    //         005584f1     TEST       EDI,EDI
    //         005584f3     JZ         LAB_00558654
    //         005584f9     MOV        ECX,dword ptr [DAT_008882c0]
    //         005584ff     TEST       ECX,ECX
    //         00558501     JNZ        LAB_0055853a
    //         00558503     TEST       EBP,EBP
    //         00558505     JBE        LAB_005586b3
    //         0055850b     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //                               LAB_0055850f                                                 XREF[1]:     00558532(j)  
    //         0055850f     CMP        word ptr [ECX],0xff
    //         00558514     JA         LAB_005586a6
    //         0055851a     MOV        DL,byte ptr [ECX]
    //         0055851c     ADD        ECX,0x2
    //         0055851f     MOV        byte ptr [EAX + EDI*0x1],DL
    //         00558522     MOV        DX,word ptr [ECX + -0x2]
    //         00558526     TEST       DX,DX
    //         00558529     JZ         LAB_005586b3
    //         0055852f     INC        EAX
    //         00558530     CMP        EAX,EBP
    //         00558532     JC         LAB_0055850f
    //         00558534     POP        EDI
    //         00558535     POP        ESI
    //         00558536     POP        EBP
    //         00558537     POP        EBX
    //         00558538     POP        ECX
    //         00558539     RET
    //                               LAB_0055853a                                                 XREF[1]:     00558501(j)  
    //         0055853a     CMP        dword ptr [___mb_cur_max],0x1                    = 00000001h
    //         00558541     JNZ        LAB_0055859b
    //         00558543     MOV        ESI,dword ptr [ESP + Stack[0x8]]
    //         00558547     TEST       EBP,EBP
    //         00558549     JBE        LAB_00558557
    //         0055854b     PUSH       EBP
    //         0055854c     PUSH       ESI
    //         0055854d     CALL       FUN_005586c0                                     undefined FUN_005586c0()
    //         00558552     ADD        ESP,0x8
    //         00558555     MOV        EBP,EAX
    //                               LAB_00558557                                                 XREF[1]:     00558549(j)  
    //         00558557     MOV        ECX,dword ptr [___lc_codepage]
    //         0055855d     LEA        EAX=>local_4,[ESP + 0x10]
    //         00558561     PUSH       EAX
    //         00558562     PUSH       0x0
    //         00558564     PUSH       EBP
    //         00558565     PUSH       EDI
    //         00558566     PUSH       EBP
    //         00558567     PUSH       ESI
    //         00558568     PUSH       0x220
    //         0055856d     PUSH       ECX
    //         0055856e     CALL       dword ptr [->KERNEL32.DLL::WideCharToMultiByte]  = 0048b8a0
    //         00558574     TEST       EAX,EAX
    //         00558576     JZ         LAB_005586a6
    //         0055857c     MOV        ECX,dword ptr [ESP + 0x10]
    //         00558580     TEST       ECX,ECX
    //         00558582     JNZ        LAB_005586a6
    //         00558588     MOV        CL,byte ptr [EAX + EDI*0x1 + -0x1]
    //         0055858c     TEST       CL,CL
    //         0055858e     JNZ        LAB_005586b3
    //         00558594     DEC        EAX
    //         00558595     POP        EDI
    //         00558596     POP        ESI
    //         00558597     POP        EBP
    //         00558598     POP        EBX
    //         00558599     POP        ECX
    //         0055859a     RET
    //                               LAB_0055859b                                                 XREF[1]:     00558541(j)  
    //         0055859b     MOV        EBX,dword ptr [ESP + Stack[0x8]]
    //         0055859f     MOV        EAX,[___lc_codepage]
    //         005585a4     LEA        EDX=>local_4,[ESP + 0x10]
    //         005585a8     PUSH       EDX
    //         005585a9     PUSH       0x0
    //         005585ab     PUSH       EBP
    //         005585ac     PUSH       EDI
    //         005585ad     PUSH       -0x1
    //         005585af     PUSH       EBX
    //         005585b0     PUSH       0x220
    //         005585b5     PUSH       EAX
    //         005585b6     CALL       dword ptr [->KERNEL32.DLL::WideCharToMultiByte]  = 0048b8a0
    //         005585bc     MOV        ESI,EAX
    //         005585be     MOV        EAX,dword ptr [ESP + 0x10]
    //         005585c2     TEST       ESI,ESI
    //         005585c4     JZ         LAB_005585d7
    //         005585c6     TEST       EAX,EAX
    //         005585c8     JNZ        LAB_005586a6
    //         005585ce     LEA        EAX,[ESI + -0x1]
    //         005585d1     POP        EDI
    //         005585d2     POP        ESI
    //         005585d3     POP        EBP
    //         005585d4     POP        EBX
    //         005585d5     POP        ECX
    //         005585d6     RET
    //                               LAB_005585d7                                                 XREF[1]:     005585c4(j)  
    //         005585d7     TEST       EAX,EAX
    //         005585d9     JNZ        LAB_005586a6
    //         005585df     CALL       dword ptr [->KERNEL32.DLL::GetLastError]         = 0048aa76
    //         005585e5     CMP        EAX,0x7a
    //         005585e8     JNZ        LAB_005586a6
    //         005585ee     CMP        ESI,EBP
    //         005585f0     JNC        LAB_0055864c
    //                               LAB_005585f2                                                 XREF[1]:     0055864a(j)  
    //         005585f2     MOV        EDX,dword ptr [___mb_cur_max]                    = 00000001h
    //         005585f8     LEA        ECX,[ESP + 0x10]
    //         005585fc     PUSH       ECX
    //         005585fd     MOV        ECX,dword ptr [___lc_codepage]
    //         00558603     PUSH       0x0=>DAT_fffffff8
    //         00558605     LEA        EAX,[ESP + 0x24]
    //         00558609     PUSH       EDX=>DAT_fffffff4
    //         0055860a     PUSH       EAX=>DAT_fffffff0
    //         0055860b     PUSH       0x1
    //         0055860d     PUSH       EBX
    //         0055860e     PUSH       0x0
    //         00558610     PUSH       ECX
    //         00558611     CALL       dword ptr [->KERNEL32.DLL::WideCharToMultiByte]  = 0048b8a0
    //         00558617     TEST       EAX,EAX
    //         00558619     JZ         LAB_005586a6
    //         0055861f     MOV        ECX,dword ptr [ESP + 0x10]
    //         00558623     TEST       ECX,ECX
    //         00558625     JNZ        LAB_005586a6
    //         00558627     LEA        EDX,[EAX + ESI*0x1]
    //         0055862a     CMP        EDX,EBP
    //         0055862c     JA         LAB_0055864c
    //         0055862e     XOR        EDX,EDX
    //         00558630     TEST       EAX,EAX
    //         00558632     JLE        LAB_00558645
    //                               LAB_00558634                                                 XREF[1]:     00558643(j)  
    //         00558634     MOV        CL,byte ptr [ESP + EDX*0x1 + 0x1c]
    //         00558638     TEST       CL,CL
    //         0055863a     MOV        byte ptr [ESI + EDI*0x1],CL
    //         0055863d     JZ         LAB_0055864c
    //         0055863f     INC        EDX
    //         00558640     INC        ESI
    //         00558641     CMP        EDX,EAX
    //         00558643     JL         LAB_00558634
    //                               LAB_00558645                                                 XREF[1]:     00558632(j)  
    //         00558645     ADD        EBX,0x2
    //         00558648     CMP        ESI,EBP
    //         0055864a     JC         LAB_005585f2
    //                               LAB_0055864c                                                 XREF[3]:     005585f0(j), 0055862c(j), 
    //                                                                                                         0055863d(j)  
    //         0055864c     MOV        EAX,ESI
    //         0055864e     POP        EDI
    //         0055864f     POP        ESI
    //         00558650     POP        EBP
    //         00558651     POP        EBX
    //         00558652     POP        ECX
    //         00558653     RET
    //                               LAB_00558654                                                 XREF[1]:     005584f3(j)  
    //         00558654     MOV        EAX,[DAT_008882c0]
    //         00558659     TEST       EAX,EAX
    //         0055865b     JNZ        LAB_00558670
    //         0055865d     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         00558661     PUSH       EAX
    //         00558662     CALL       wcslen                                           undefined wcslen()
    //         00558667     ADD        ESP,0x4
    //         0055866a     POP        EDI
    //         0055866b     POP        ESI
    //         0055866c     POP        EBP
    //         0055866d     POP        EBX
    //         0055866e     POP        ECX
    //         0055866f     RET
    //                               LAB_00558670                                                 XREF[1]:     0055865b(j)  
    //         00558670     MOV        EDX,dword ptr [ESP + Stack[0x8]]
    //         00558674     MOV        EAX,[___lc_codepage]
    //         00558679     LEA        ECX=>local_4,[ESP + 0x10]
    //         0055867d     PUSH       ECX
    //         0055867e     PUSH       0x0
    //         00558680     PUSH       0x0
    //         00558682     PUSH       0x0
    //         00558684     PUSH       -0x1
    //         00558686     PUSH       EDX
    //         00558687     PUSH       0x220
    //         0055868c     PUSH       EAX
    //         0055868d     CALL       dword ptr [->KERNEL32.DLL::WideCharToMultiByte]  = 0048b8a0
    //         00558693     TEST       EAX,EAX
    //         00558695     JZ         LAB_005586a6
    //         00558697     MOV        ECX,dword ptr [ESP + 0x10]
    //         0055869b     TEST       ECX,ECX
    //         0055869d     JNZ        LAB_005586a6
    //         0055869f     DEC        EAX
    //         005586a0     POP        EDI
    //         005586a1     POP        ESI
    //         005586a2     POP        EBP
    //         005586a3     POP        EBX
    //         005586a4     POP        ECX
    //         005586a5     RET
    //                               LAB_005586a6                                                 XREF[10]:    00558514(j), 00558576(j), 
    //                                                                                                         00558582(j), 005585c8(j), 
    //                                                                                                         005585d9(j), 005585e8(j), 
    //                                                                                                         00558619(j), 00558625(j), 
    //                                                                                                         00558695(j), 0055869d(j)  
    //         005586a6     MOV        dword ptr [_errno],0x2a                          = align(4)
    //         005586b0     OR         EAX,0xffffffff
    //                               LAB_005586b3                                                 XREF[3]:     00558505(j), 00558529(j), 
    //                                                                                                         0055858e(j)  
    //         005586b3     POP        EDI
    //         005586b4     POP        ESI
    //         005586b5     POP        EBP
    //         005586b6     POP        EBX
    //         005586b7     POP        ECX
    //         005586b8     RET
}

// Offset: 0x005586C0
undefined FUN_005586c0() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005586c0()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005586c0                                                 XREF[1]:     wcstombs:0055854d(c)  
    //         005586c0     MOV        EDX,dword ptr [ESP + Stack[0x4]]
    //         005586c4     PUSH       ESI
    //         005586c5     MOV        ESI,dword ptr [ESP + Stack[0x8]]
    //         005586c9     MOV        EAX,EDX
    //         005586cb     MOV        ECX,ESI
    //         005586cd     TEST       ECX,ECX
    //         005586cf     JZ         LAB_005586ee
    //                               LAB_005586d1                                                 XREF[1]:     005586db(j)  
    //         005586d1     CMP        word ptr [EAX],0x0
    //         005586d5     JZ         LAB_005586dd
    //         005586d7     ADD        EAX,0x2
    //         005586da     DEC        ECX
    //         005586db     JNZ        LAB_005586d1
    //                               LAB_005586dd                                                 XREF[1]:     005586d5(j)  
    //         005586dd     TEST       ECX,ECX
    //         005586df     JZ         LAB_005586ee
    //         005586e1     CMP        word ptr [EAX],0x0
    //         005586e5     JNZ        LAB_005586ee
    //         005586e7     SUB        EAX,EDX
    //         005586e9     SAR        EAX,0x1
    //         005586eb     INC        EAX
    //         005586ec     POP        ESI
    //         005586ed     RET
    //                               LAB_005586ee                                                 XREF[3]:     005586cf(j), 005586df(j), 
    //                                                                                                         005586e5(j)  
    //         005586ee     MOV        EAX,ESI
    //         005586f0     POP        ESI
    //         005586f1     RET
}

// Offset: 0x00558700
undefined getenv() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * getenv                                                                                                *
    //                              *********************************************************************************************************
    //                              undefined __cdecl getenv()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _getenv                                                      XREF[1]:     __tzset:005535a9(c)  
    //                               getenv
    //         00558700     PUSH       EBX
    //         00558701     MOV        EBX,dword ptr [__environ]
    //         00558707     PUSH       EBP
    //         00558708     PUSH       ESI
    //         00558709     TEST       EBX,EBX
    //         0055870b     PUSH       EDI
    //         0055870c     JNZ        LAB_0055872a
    //         0055870e     MOV        EAX,[__wenviron]
    //         00558713     TEST       EAX,EAX
    //         00558715     JZ         LAB_00558726
    //         00558717     CALL       ___wtomb_environ                                 undefined ___wtomb_environ()
    //         0055871c     TEST       EAX,EAX
    //         0055871e     JNZ        LAB_00558787
    //         00558720     MOV        EBX,dword ptr [__environ]
    //                               LAB_00558726                                                 XREF[1]:     00558715(j)  
    //         00558726     TEST       EBX,EBX
    //         00558728     JZ         LAB_00558787
    //                               LAB_0055872a                                                 XREF[1]:     0055870c(j)  
    //         0055872a     MOV        EBP,dword ptr [ESP + Stack[0x4]]
    //         0055872e     TEST       EBP,EBP
    //         00558730     JZ         LAB_00558787
    //         00558732     MOV        EDI,EBP
    //         00558734     OR         ECX,0xffffffff
    //         00558737     XOR        EAX,EAX
    //         00558739     MOV        EDX,dword ptr [EBX]
    //         0055873b     SCASB.RE   ES:EDI
    //         0055873d     NOT        ECX
    //         0055873f     DEC        ECX
    //         00558740     TEST       EDX,EDX
    //         00558742     MOV        ESI,ECX
    //         00558744     JZ         LAB_00558787
    //                               LAB_00558746                                                 XREF[1]:     00558773(j)  
    //         00558746     MOV        EDI,EDX
    //         00558748     OR         ECX,0xffffffff
    //         0055874b     XOR        EAX,EAX
    //         0055874d     SCASB.RE   ES:EDI
    //         0055874f     NOT        ECX
    //         00558751     DEC        ECX
    //         00558752     CMP        ECX,ESI
    //         00558754     JBE        LAB_0055876b
    //         00558756     CMP        byte ptr [ESI + EDX*0x1],0x3d
    //         0055875a     JNZ        LAB_0055876b
    //         0055875c     PUSH       ESI
    //         0055875d     PUSH       EBP
    //         0055875e     PUSH       EDX
    //         0055875f     CALL       __mbsnbicoll                                     undefined __mbsnbicoll()
    //         00558764     ADD        ESP,0xc
    //         00558767     TEST       EAX,EAX
    //         00558769     JZ         LAB_0055877c
    //                               LAB_0055876b                                                 XREF[2]:     00558754(j), 0055875a(j)  
    //         0055876b     MOV        EDX,dword ptr [EBX + 0x4]
    //         0055876e     ADD        EBX,0x4
    //         00558771     TEST       EDX,EDX
    //         00558773     JNZ        LAB_00558746
    //         00558775     XOR        EAX,EAX
    //         00558777     POP        EDI
    //         00558778     POP        ESI
    //         00558779     POP        EBP
    //         0055877a     POP        EBX
    //         0055877b     RET
    //                               LAB_0055877c                                                 XREF[1]:     00558769(j)  
    //         0055877c     MOV        EAX,dword ptr [EBX]
    //         0055877e     LEA        EAX,[ESI + EAX*0x1 + 0x1]
    //         00558782     POP        EDI
    //         00558783     POP        ESI
    //         00558784     POP        EBP
    //         00558785     POP        EBX
    //         00558786     RET
    //                               LAB_00558787                                                 XREF[4]:     0055871e(j), 00558728(j), 
    //                                                                                                         00558730(j), 00558744(j)  
    //         00558787     POP        EDI
    //         00558788     POP        ESI
    //         00558789     POP        EBP
    //         0055878a     XOR        EAX,EAX
    //         0055878c     POP        EBX
    //         0055878d     RET
}

// Offset: 0x0055878E
undefined FUN_0055878e() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055878e()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0055878e
    //         0055878e     NOP
    //         0055878f     NOP
    //                               __fcloseall                                                  XREF[1]:     FUN_00553fa9:00553fbe(j)  
    //         00558790     MOV        EAX,[__nstream]
    //         00558795     PUSH       ESI
    //         00558796     PUSH       EDI
    //         00558797     MOV        ESI,0x3
    //         0055879c     XOR        EDI,EDI
    //         0055879e     CMP        EAX,ESI
    //         005587a0     JLE        LAB_005587f3
    //         005587a2     PUSH       EBX
    //                              language.dll match for 0x83: "Arial"
    //         005587a3     MOV        BL,0x83
    //                               LAB_005587a5                                                 XREF[1]:     005587f0(j)  
    //         005587a5     MOV        EAX,[___piob]
    //         005587aa     MOV        EAX,dword ptr [EAX + ESI*0x4]
    //         005587ad     TEST       EAX,EAX
    //         005587af     JZ         LAB_005587e8
    //         005587b1     TEST       byte ptr [EAX + 0xc],BL
    //         005587b4     JZ         LAB_005587c5
    //         005587b6     PUSH       EAX
    //         005587b7     CALL       fclose                                           undefined fclose()
    //         005587bc     ADD        ESP,0x4
    //         005587bf     CMP        EAX,-0x1
    //         005587c2     JZ         LAB_005587c5
    //         005587c4     INC        EDI
    //                               LAB_005587c5                                                 XREF[2]:     005587b4(j), 005587c2(j)  
    //         005587c5     CMP        ESI,0x14
    //         005587c8     JL         LAB_005587e8
    //         005587ca     MOV        ECX,dword ptr [___piob]
    //         005587d0     MOV        EDX,dword ptr [ECX + ESI*0x4]
    //         005587d3     PUSH       EDX
    //         005587d4     CALL       free                                             undefined free()
    //         005587d9     MOV        EAX,[___piob]
    //         005587de     ADD        ESP,0x4
    //         005587e1     MOV        dword ptr [EAX + ESI*0x4],0x0
    //                               LAB_005587e8                                                 XREF[2]:     005587af(j), 005587c8(j)  
    //         005587e8     MOV        EAX,[__nstream]
    //         005587ed     INC        ESI
    //         005587ee     CMP        ESI,EAX
    //         005587f0     JL         LAB_005587a5
    //         005587f2     POP        EBX
    //                               LAB_005587f3                                                 XREF[1]:     005587a0(j)  
    //         005587f3     MOV        EAX,EDI
    //         005587f5     POP        EDI
    //         005587f6     POP        ESI
    //         005587f7     RET
}

// Offset: 0x00558800
undefined mbbtype() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __mbbtype()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __mbbtype                                                    XREF[1]:     __mbsbtype:00554304(c)  
    //         00558800     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         00558804     INC        EAX
    //         00558805     CMP        EAX,0x3
    //         00558808     JA         switchD_0055880a::default
    //                               switchD_0055880a::switchD
    //         0055880a     JMP        dword ptr [EAX*0x4 + switchD_0055880a::switchd   = 0055882c
    //                               switchD_0055880a::caseD_2                                    XREF[2]:     0055880a(j), 00558868(*)  
    //         00558811     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         00558815     AND        ECX,0xff
    //         0055881b     MOV        AL,byte ptr [ECX + __mbctype+1]
    //         00558821     AND        AL,0x8
    //         00558823     NEG        AL
    //         00558825     SBB        EAX,EAX
    //         00558827     AND        EAX,0x3
    //         0055882a     DEC        EAX
    //         0055882b     RET
    //                               switchD_0055880a::caseD_1                                    XREF[4]:     0055880a(j), 00558860(*), 
    //                               switchD_0055880a::caseD_3                                                 00558864(*), 0055886c(*)  
    //                               switchD_0055880a::caseD_0
    //         0055882c     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00558830     AND        EAX,0xff
    //         00558835     MOV        CL,byte ptr [EAX + __mbctype+1]
    //         0055883b     TEST       CL,0x4
    //         0055883e     JZ         LAB_00558846
    //         00558840     MOV        EAX,0x1
    //         00558845     RET
    //                               LAB_00558846                                                 XREF[1]:     0055883e(j)  
    //         00558846     TEST       word ptr [EAX*0x2 + DAT_005920da],0x157          = 20h     
    //         00558850     JNZ        LAB_0055885b
    //         00558852     TEST       CL,0x3
    //         00558855     JNZ        LAB_0055885b
    //         00558857     OR         EAX,0xffffffff
    //         0055885a     RET
    //                               LAB_0055885b                                                 XREF[2]:     00558850(j), 00558855(j)  
    //         0055885b     XOR        EAX,EAX
    //                               switchD_0055880a::default                                    XREF[1]:     00558808(j)  
    //         0055885d     RET
}

// Offset: 0x0055885E
undefined FUN_0055885e() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055885e()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0055885e
    //         0055885e     MOV        EDI,EDI
    //                               switchD_0055880a::switchdataD_00558860                       XREF[1]:     __mbbtype:0055880a(*)  
}

// Offset: 0x00558870
undefined setmode() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __setmode()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __setmode                                                    XREF[2]:     __chsize:00554d06(c), 
    //                                                                                                         __chsize:00554d53(c)  
    //         00558870     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00558874     MOV        ECX,dword ptr [__nhandle]
    //         0055887a     CMP        EAX,ECX
    //         0055887c     PUSH       ESI
    //         0055887d     JNC        LAB_005588df
    //         0055887f     MOV        ECX,EAX
    //         00558881     AND        EAX,0x1f
    //         00558884     SAR        ECX,0x5
    //         00558887     MOV        EDX,dword ptr [ECX*0x4 + ___pioinfo]
    //         0055888e     MOV        CL,byte ptr [EDX + EAX*0x8 + 0x4]
    //         00558892     TEST       CL,0x1
    //         00558895     LEA        EDX,[EDX + EAX*0x8 + 0x4]
    //         00558899     JZ         LAB_005588df
    //         0055889b     MOV        ESI,dword ptr [ESP + Stack[0x8]]
    //         0055889f     MOV        AL,CL
    //         005588a1     AND        EAX,0x80
    //         005588a6     CMP        ESI,0x8000
    //         005588ac     JNZ        LAB_005588b3
    //         005588ae     AND        CL,0x7f
    //         005588b1     JMP        LAB_005588be
    //                               LAB_005588b3                                                 XREF[1]:     005588ac(j)  
    //         005588b3     CMP        ESI,0x4000
    //         005588b9     JNZ        LAB_005588d0
    //         005588bb     OR         CL,0x80
    //                               LAB_005588be                                                 XREF[1]:     005588b1(j)  
    //         005588be     NEG        EAX
    //         005588c0     SBB        EAX,EAX
    //         005588c2     MOV        byte ptr [EDX],CL
    //         005588c4     AND        EAX,0xffffc000
    //         005588c9     ADD        EAX,0x8000
    //         005588ce     POP        ESI
    //         005588cf     RET
    //                               LAB_005588d0                                                 XREF[1]:     005588b9(j)  
    //         005588d0     MOV        dword ptr [_errno],0x16                          = align(4)
    //         005588da     OR         EAX,0xffffffff
    //         005588dd     POP        ESI
    //         005588de     RET
    //                               LAB_005588df                                                 XREF[2]:     0055887d(j), 00558899(j)  
    //         005588df     MOV        dword ptr [_errno],0x9                           = align(4)
    //         005588e9     OR         EAX,0xffffffff
    //         005588ec     POP        ESI
    //         005588ed     RET
}

// Offset: 0x005588F0
undefined strgtold12() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined ___strgtold12()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined1        Stack[-0x5]:1  local_5                   XREF[2]:     00558de3(R), 00558ded(W)  
    //              undefined         Stack[-0x1c]:1 local_1c                  XREF[4]:     005588f8(*), 00558ab8(*), 00558b7d(*), 00558e30(*)  
    //              undefined1        Stack[-0x1d]:1 local_1d                  XREF[1]:     00558e16(R)  
    //              undefined1        Stack[-0x1e]:1 local_1e                  XREF[1]:     00558e1e(R)  
    //              undefined4        Stack[-0x22]:4 local_22                  XREF[1]:     00558f37(R)  
    //              undefined4        Stack[-0x26]:4 local_26                  XREF[1]:     00558f33(R)  
    //              undefined4        Stack[-0x2c]:4 local_2c                  XREF[3,1]:   00558e2c(*), 00558f1f(*), 00558f2b(R), 00558f2f(R)  
    //              undefined4        Stack[-0x30]:4 local_30                  XREF[2]:     00558937(W), 00558edf(R)  
    //              undefined4        Stack[-0x34]:4 local_34                  XREF[3]:     0055892b(W), 00558ec8(R), 00558f0b(W)  
    //              undefined4        Stack[-0x38]:4 local_38                  XREF[3]:     00558927(W), 00558e7c(W), 00558eab(R)  
    //              undefined4        Stack[-0x3c]:4 local_3c                  XREF[4]:     0055890b(W), 005589c6(W), 005589d8(W), 00558eea(R)  
    //              undefined4        Stack[-0x40]:4 local_40                  XREF[4]:     0055891f(W), 00558b17(W), 00558bd3(W), 00558e62(R)  
    //              undefined4        Stack[-0x44]:4 local_44                  XREF[4]:     00558923(W), 00558c64(W), 00558cbe(W), 00558e51(R)  
    //              undefined4        Stack[-0x48]:4 local_48                  XREF[3]:     0055892f(W), 00558d26(W), 00558e45(R)  
    //              undefined4        Stack[-0x4c]:4 local_4c                  XREF[3]:     0055890f(W), 00558dac(W), 00558e3c(R)  
    //              undefined4        Stack[-0x50]:4 local_50                  XREF[4]:     0055893d(W), 00558c32(W), 00558d6e(R), 00558d93(W)  
    //              undefined4        Stack[-0x54]:4 local_54                  XREF[4]:     00558917(W), 00558ae1(W), 00558b9d(W), 00558d6a(R)  
    //              undefined4        Stack[-0x58]:4 local_58                  XREF[6]:     0055891b(W), 005589e8(W), 00558a6b(W), 00558b13(W), 
    //                                                                                     00558dd0(R), 00558e94(R)  
    //              undefined4        Stack[-0x5c]:4 local_5c                  XREF[7]:     005588fe(W), 00558ab0(R), 00558ac2(W), 00558b75(R), 
    //                                                                                     00558b80(W), 00558df1(R), 00558e06(R)  
    //              undefined4        Stack[-0x60]:4 local_60                  XREF[12]:    00558933(W), 00558962(R), 00558ac9(R), 00558ad5(W), 
    //                                                                                     00558b30(W), 00558b84(R), 00558b89(W), 00558df5(R), 
    //                                                                                     00558e00(W), 00558e0a(R), 00558e28(W), 00558e4d(R)  
    //                               ___strgtold12                                                XREF[4]:     __fltin:00554eeb(c), 
    //                                                                                                         __atodbl:00557e8a(c), 
    //                                                                                                         FUN_00557ea8:00557eca(c), 
    //                                                                                                         __atoflt:00557f0a(c)  
    //         005588f0     SUB        ESP,0x60
    //         005588f3     MOV        ECX,dword ptr [ESP + Stack[0xc]]
    //         005588f7     PUSH       EBX
    //         005588f8     LEA        EAX=>local_1c,[ESP + 0x48]
    //         005588fc     PUSH       EBP
    //         005588fd     PUSH       ESI
    //         005588fe     MOV        dword ptr [ESP + local_5c],EAX
    //         00558902     PUSH       EDI
    //         00558903     XOR        EAX,EAX
    //         00558905     XOR        ESI,ESI
    //         00558907     XOR        EDX,EDX
    //         00558909     MOV        EDI,ECX
    //         0055890b     MOV        dword ptr [ESP + local_3c],EAX
    //         0055890f     MOV        dword ptr [ESP + local_4c],0x1
    //         00558917     MOV        dword ptr [ESP + local_54],ESI
    //         0055891b     MOV        dword ptr [ESP + local_58],EAX
    //         0055891f     MOV        dword ptr [ESP + local_40],EAX
    //         00558923     MOV        dword ptr [ESP + local_44],EAX
    //         00558927     MOV        dword ptr [ESP + local_38],EAX
    //         0055892b     MOV        dword ptr [ESP + local_34],EAX
    //         0055892f     MOV        dword ptr [ESP + local_48],EAX
    //         00558933     MOV        dword ptr [ESP + local_60],EDX
    //         00558937     MOV        dword ptr [ESP + local_30],EAX
    //         0055893b     MOV        EBP,ECX
    //         0055893d     MOV        dword ptr [ESP + local_50],EDI
    //                               LAB_00558941                                                 XREF[1]:     00558959(j)  
    //         00558941     MOV        CL,byte ptr [EBP]
    //         00558944     CMP        CL,0x20
    //         00558947     JZ         LAB_00558958
    //         00558949     CMP        CL,0x9
    //         0055894c     JZ         LAB_00558958
    //         0055894e     CMP        CL,0xa
    //         00558951     JZ         LAB_00558958
    //         00558953     CMP        CL,0xd
    //         00558956     JNZ        LAB_0055895b
    //                               LAB_00558958                                                 XREF[3]:     00558947(j), 0055894c(j), 
    //                                                                                                         00558951(j)  
    //         00558958     INC        EBP
    //         00558959     JMP        LAB_00558941
    //                               LAB_0055895b                                                 XREF[1]:     00558956(j)  
    //         0055895b     MOV        ECX,0x1
    //         00558960     JMP        LAB_00558966
    //                               LAB_00558962                                                 XREF[1]:     00558dc6(j)  
    //         00558962     MOV        EDX,dword ptr [ESP + local_60]
    //                               LAB_00558966                                                 XREF[1]:     00558960(j)  
    //         00558966     MOV        BL,byte ptr [EBP]
    //         00558969     INC        EBP
    //         0055896a     CMP        EAX,0xb
    //         0055896d     MOV        byte ptr [ESP + Stack[0xc]],BL
    //         00558971     JA         switchD_00558977::caseD_a
    //                               switchD_00558977::switchD
    //         00558977     JMP        dword ptr [EAX*0x4 + ->switchD_00558977::caseD   = 0055897e
    //                                                                                  = 00558dc3
    //                               switchD_00558977::caseD_0                                    XREF[2]:     00558977(j), 00558f50(*)  
    //         0055897e     CMP        BL,0x31
    //         00558981     JL         LAB_00558992
    //         00558983     CMP        BL,0x39
    //         00558986     JG         LAB_00558992
    //         00558988     MOV        EAX,0x3
    //         0055898d     JMP        LAB_00558dc2
    //                               LAB_00558992                                                 XREF[2]:     00558981(j), 00558986(j)  
    //         00558992     CMP        BL,byte ptr [___decimal_point]                   = 2Eh
    //         00558998     JNZ        LAB_005589a4
    //         0055899a     MOV        EAX,0x5
    //         0055899f     JMP        switchD_00558977::caseD_a
    //                               LAB_005589a4                                                 XREF[1]:     00558998(j)  
    //         005589a4     MOVSX      EAX,BL
    //         005589a7     SUB        EAX,0x2b
    //         005589aa     JZ         LAB_005589d3
    //         005589ac     SUB        EAX,0x2
    //         005589af     JZ         LAB_005589c1
    //         005589b1     SUB        EAX,0x3
    //         005589b4     JNZ        switchD_00558bb2::caseD_2c
    //         005589ba     MOV        EAX,ECX
    //         005589bc     JMP        switchD_00558977::caseD_a
    //                               LAB_005589c1                                                 XREF[1]:     005589af(j)  
    //         005589c1     MOV        EAX,0x2
    //         005589c6     MOV        dword ptr [ESP + local_3c],0x8000
    //         005589ce     JMP        switchD_00558977::caseD_a
    //                               LAB_005589d3                                                 XREF[1]:     005589aa(j)  
    //         005589d3     MOV        EAX,0x2
    //         005589d8     MOV        dword ptr [ESP + local_3c],0x0
    //         005589e0     JMP        switchD_00558977::caseD_a
    //                               switchD_00558977::caseD_1                                    XREF[2]:     00558977(j), 00558f54(*)  
    //         005589e5     CMP        BL,0x31
    //         005589e8     MOV        dword ptr [ESP + local_58],ECX
    //         005589ec     JL         LAB_005589fd
    //         005589ee     CMP        BL,0x39
    //         005589f1     JG         LAB_005589fd
    //         005589f3     MOV        EAX,0x3
    //         005589f8     JMP        LAB_00558dc2
    //                               LAB_005589fd                                                 XREF[2]:     005589ec(j), 005589f1(j)  
    //         005589fd     CMP        BL,byte ptr [___decimal_point]                   = 2Eh
    //         00558a03     JNZ        LAB_00558a0f
    //         00558a05     MOV        EAX,0x4
    //         00558a0a     JMP        switchD_00558977::caseD_a
    //                               LAB_00558a0f                                                 XREF[1]:     00558a03(j)  
    //         00558a0f     MOVSX      EAX,BL
    //         00558a12     ADD        EAX,-0x2b
    //         00558a15     CMP        EAX,0x3a
    //         00558a18     JA         switchD_00558bb2::caseD_2c
    //         00558a1e     XOR        EDX,EDX
    //         00558a20     MOV        DL,byte ptr [EAX + 0x558f98]=>PTR_caseD_7_0055
    //                               switchD_00558a26::switchD
    //         00558a26     JMP        dword ptr [EDX*0x4 + switchD_00558a26::switchd   = 00558bc3
    //                               switchD_00558977::caseD_2                                    XREF[2]:     00558977(j), 00558f58(*)  
    //         00558a2d     CMP        BL,0x31
    //         00558a30     JL         LAB_00558a41
    //         00558a32     CMP        BL,0x39
    //         00558a35     JG         LAB_00558a41
    //         00558a37     MOV        EAX,0x3
    //         00558a3c     JMP        LAB_00558dc2
    //                               LAB_00558a41                                                 XREF[2]:     00558a30(j), 00558a35(j)  
    //         00558a41     CMP        BL,byte ptr [___decimal_point]                   = 2Eh
    //         00558a47     JNZ        LAB_00558a53
    //         00558a49     MOV        EAX,0x5
    //         00558a4e     JMP        switchD_00558977::caseD_a
    //                               LAB_00558a53                                                 XREF[1]:     00558a47(j)  
    //         00558a53     CMP        BL,0x30
    //         00558a56     JZ         switchD_00558a26::caseD_30
    //         00558a58     MOV        EAX,0xa
    //         00558a5d     MOV        EBP,EDI
    //         00558a5f     JMP        switchD_00558977::caseD_a
    //                               switchD_00558a26::caseD_30                                   XREF[3]:     00558a26(j), 00558a56(j), 
    //                                                                                                         00558f88(*)  
    //         00558a64     MOV        EAX,ECX
    //         00558a66     JMP        switchD_00558977::caseD_a
    //                               switchD_00558977::caseD_3                                    XREF[2]:     00558977(j), 00558f5c(*)  
    //         00558a6b     MOV        dword ptr [ESP + local_58],ECX
    //                               LAB_00558a6f                                                 XREF[2]:     00558ac7(j), 00558ada(j)  
    //         00558a6f     CMP        dword ptr [___mb_cur_max],ECX                    = 00000001h
    //         00558a75     JLE        LAB_00558a92
    //         00558a77     MOV        EAX,dword ptr [ESP + Stack[0xc]]
    //         00558a7b     PUSH       0x4
    //         00558a7d     AND        EAX,0xff
    //         00558a82     PUSH       EAX
    //         00558a83     CALL       __isctype                                        undefined __isctype()
    //         00558a88     ADD        ESP,0x8
    //         00558a8b     MOV        ECX,0x1
    //         00558a90     JMP        LAB_00558aa7
    //                               LAB_00558a92                                                 XREF[1]:     00558a75(j)  
    //         00558a92     MOV        EDX,dword ptr [ESP + Stack[0xc]]
    //         00558a96     MOV        EAX,[__pctype]                                   = 005920da
    //         00558a9b     AND        EDX,0xff
    //         00558aa1     MOV        AL,byte ptr [EAX + EDX*0x2]=>DAT_005920da        = 20h     
    //         00558aa4     AND        EAX,0x4
    //                               LAB_00558aa7                                                 XREF[1]:     00558a90(j)  
    //         00558aa7     TEST       EAX,EAX
    //         00558aa9     JZ         LAB_00558adc
    //         00558aab     CMP        ESI,0x19
    //         00558aae     JNC        LAB_00558ac9
    //         00558ab0     MOV        EAX,dword ptr [ESP + local_5c]
    //         00558ab4     SUB        BL,0x30
    //         00558ab7     INC        ESI
    //         00558ab8     MOV        byte ptr [EAX]=>local_1c,BL
    //         00558aba     MOV        BL,byte ptr [EBP]
    //         00558abd     INC        EAX
    //         00558abe     MOV        byte ptr [ESP + Stack[0xc]],BL
    //         00558ac2     MOV        dword ptr [ESP + local_5c],EAX
    //         00558ac6     INC        EBP
    //         00558ac7     JMP        LAB_00558a6f
    //                               LAB_00558ac9                                                 XREF[1]:     00558aae(j)  
    //         00558ac9     MOV        EAX,dword ptr [ESP + local_60]
    //         00558acd     MOV        BL,byte ptr [EBP]
    //         00558ad0     INC        EAX
    //         00558ad1     MOV        byte ptr [ESP + Stack[0xc]],BL
    //         00558ad5     MOV        dword ptr [ESP + local_60],EAX
    //         00558ad9     INC        EBP
    //         00558ada     JMP        LAB_00558a6f
    //                               LAB_00558adc                                                 XREF[1]:     00558aa9(j)  
    //         00558adc     MOV        AL,[___decimal_point]                            = 2Eh
    //         00558ae1     MOV        dword ptr [ESP + local_54],ESI
    //         00558ae5     CMP        BL,AL
    //         00558ae7     JNZ        LAB_00558af3
    //         00558ae9     MOV        EAX,0x4
    //         00558aee     JMP        switchD_00558977::caseD_a
    //                               LAB_00558af3                                                 XREF[1]:     00558ae7(j)  
    //         00558af3     MOVSX      EAX,BL
    //         00558af6     ADD        EAX,-0x2b
    //         00558af9     CMP        EAX,0x3a
    //         00558afc     JA         switchD_00558bb2::caseD_2c
    //         00558b02     XOR        EDX,EDX
    //         00558b04     MOV        DL,byte ptr [EAX + 0x558fe8]=>BYTE_00558fbd      = 5h
    //                               switchD_00558b0a::switchD
    //         00558b0a     JMP        dword ptr [EDX*0x4 + switchD_00558b0a::switchd   = 00558bc3
    //                               switchD_00558977::caseD_4                                    XREF[2]:     00558977(j), 00558f60(*)  
    //         00558b11     TEST       ESI,ESI
    //         00558b13     MOV        dword ptr [ESP + local_58],ECX
    //         00558b17     MOV        dword ptr [ESP + local_40],ECX
    //         00558b1b     JNZ        LAB_00558b34
    //         00558b1d     CMP        BL,0x30
    //         00558b20     JNZ        LAB_00558b34
    //                               LAB_00558b22                                                 XREF[1]:     00558b2e(j)  
    //         00558b22     MOV        BL,byte ptr [EBP]
    //         00558b25     DEC        EDX
    //         00558b26     INC        EBP
    //         00558b27     CMP        BL,0x30
    //         00558b2a     MOV        byte ptr [ESP + Stack[0xc]],BL
    //         00558b2e     JZ         LAB_00558b22
    //         00558b30     MOV        dword ptr [ESP + local_60],EDX
    //                               LAB_00558b34                                                 XREF[3]:     00558b1b(j), 00558b20(j), 
    //                                                                                                         00558b95(j)  
    //         00558b34     CMP        dword ptr [___mb_cur_max],ECX                    = 00000001h
    //         00558b3a     JLE        LAB_00558b57
    //         00558b3c     MOV        EAX,dword ptr [ESP + Stack[0xc]]
    //         00558b40     PUSH       0x4
    //         00558b42     AND        EAX,0xff
    //         00558b47     PUSH       EAX
    //         00558b48     CALL       __isctype                                        undefined __isctype()
    //         00558b4d     ADD        ESP,0x8
    //         00558b50     MOV        ECX,0x1
    //         00558b55     JMP        LAB_00558b6c
    //                               LAB_00558b57                                                 XREF[1]:     00558b3a(j)  
    //         00558b57     MOV        EDX,dword ptr [ESP + Stack[0xc]]
    //         00558b5b     MOV        EAX,[__pctype]                                   = 005920da
    //         00558b60     AND        EDX,0xff
    //         00558b66     MOV        AL,byte ptr [EAX + EDX*0x2]=>DAT_005920da        = 20h     
    //         00558b69     AND        EAX,0x4
    //                               LAB_00558b6c                                                 XREF[1]:     00558b55(j)  
    //         00558b6c     TEST       EAX,EAX
    //         00558b6e     JZ         LAB_00558b97
    //         00558b70     CMP        ESI,0x19
    //         00558b73     JNC        LAB_00558b8d
    //         00558b75     MOV        EAX,dword ptr [ESP + local_5c]
    //         00558b79     SUB        BL,0x30
    //         00558b7c     INC        ESI
    //         00558b7d     MOV        byte ptr [EAX]=>local_1c,BL
    //         00558b7f     INC        EAX
    //         00558b80     MOV        dword ptr [ESP + local_5c],EAX
    //         00558b84     MOV        EAX,dword ptr [ESP + local_60]
    //         00558b88     DEC        EAX
    //         00558b89     MOV        dword ptr [ESP + local_60],EAX
    //                               LAB_00558b8d                                                 XREF[1]:     00558b73(j)  
    //         00558b8d     MOV        BL,byte ptr [EBP]
    //         00558b90     INC        EBP
    //         00558b91     MOV        byte ptr [ESP + Stack[0xc]],BL
    //         00558b95     JMP        LAB_00558b34
    //                               LAB_00558b97                                                 XREF[1]:     00558b6e(j)  
    //         00558b97     MOVSX      EAX,BL
    //         00558b9a     ADD        EAX,-0x2b
    //         00558b9d     MOV        dword ptr [ESP + local_54],ESI
    //         00558ba1     CMP        EAX,0x3a
    //         00558ba4     JA         switchD_00558bb2::caseD_2c
    //         00558baa     XOR        EDX,EDX
    //         00558bac     MOV        DL,byte ptr [EAX + 0x559038]=>BYTE_0055900d      = 4h
    //                               switchD_00558bb2::switchD
    //         00558bb2     JMP        dword ptr [EDX*0x4 + switchD_00558bb2::switchd   = 00558bc3
    //                               switchD_00558bb2::caseD_45                                   XREF[9]:     00558a26(j), 00558b0a(j), 
    //                               switchD_00558bb2::caseD_64                                                00558bb2(j), 00558f8c(*), 
    //                               switchD_00558bb2::caseD_65                                                00558f90(*), 00558fdc(*), 
    //                               switchD_00558b0a::caseD_44                                                00558fe0(*), 0055902c(*), 
    //                               switchD_00558b0a::caseD_45                                                00559030(*)  
    //                               switchD_00558b0a::caseD_64
    //                               switchD_00558b0a::caseD_65
    //                               switchD_00558a26::caseD_44
    //                               switchD_00558a26::caseD_45
    //                               switchD_00558a26::caseD_64
    //                               switchD_00558a26::caseD_65
    //                               switchD_00558bb2::caseD_44
    //         00558bb9     MOV        EAX,0x6
    //         00558bbe     JMP        switchD_00558977::caseD_a
    //                               switchD_00558bb2::caseD_2d                                   XREF[9]:     00558a26(j), 00558b0a(j), 
    //                               switchD_00558b0a::caseD_2b                                                00558bb2(j), 00558f80(*), 
    //                               switchD_00558b0a::caseD_2d                                                00558f84(*), 00558fd4(*), 
    //                               switchD_00558a26::caseD_2b                                                00558fd8(*), 00559024(*), 
    //                               switchD_00558a26::caseD_2d                                                00559028(*)  
    //                               switchD_00558bb2::caseD_2b
    //         00558bc3     DEC        EBP
    //         00558bc4     MOV        EAX,0xb
    //         00558bc9     JMP        switchD_00558977::caseD_a
    //                               switchD_00558977::caseD_5                                    XREF[2]:     00558977(j), 00558f64(*)  
    //         00558bce     MOV        EAX,[___mb_cur_max]                              = 00000001h
    //         00558bd3     MOV        dword ptr [ESP + local_40],ECX
    //         00558bd7     CMP        EAX,ECX
    //         00558bd9     JLE        LAB_00558bf1
    //         00558bdb     MOV        EAX,dword ptr [ESP + Stack[0xc]]
    //         00558bdf     PUSH       0x4
    //         00558be1     AND        EAX,0xff
    //         00558be6     PUSH       EAX
    //         00558be7     CALL       __isctype                                        undefined __isctype()
    //         00558bec     ADD        ESP,0x8
    //         00558bef     JMP        LAB_00558c07
    //                               LAB_00558bf1                                                 XREF[1]:     00558bd9(j)  
    //         00558bf1     MOV        ECX,dword ptr [ESP + Stack[0xc]]
    //         00558bf5     MOV        EDX,dword ptr [__pctype]                         = 005920da
    //         00558bfb     AND        ECX,0xff
    //         00558c01     MOV        AL,byte ptr [EDX + ECX*0x2]=>DAT_005920da        = 20h     
    //         00558c04     AND        EAX,0x4
    //                               LAB_00558c07                                                 XREF[1]:     00558bef(j)  
    //         00558c07     TEST       EAX,EAX
    //         00558c09     JZ         LAB_00558c1b
    //         00558c0b     MOV        EAX,0x4
    //         00558c10     DEC        EBP
    //         00558c11     MOV        ECX,0x1
    //         00558c16     JMP        switchD_00558977::caseD_a
    //                               LAB_00558c1b                                                 XREF[1]:     00558c09(j)  
    //         00558c1b     MOV        EAX,0xa
    //         00558c20     MOV        EBP,EDI
    //         00558c22     MOV        ECX,0x1
    //         00558c27     JMP        switchD_00558977::caseD_a
    //                               switchD_00558977::caseD_6                                    XREF[2]:     00558977(j), 00558f68(*)  
    //         00558c2c     LEA        EDI,[EBP + -0x2]
    //         00558c2f     CMP        BL,0x31
    //         00558c32     MOV        dword ptr [ESP + local_50],EDI
    //         00558c36     JL         LAB_00558c47
    //         00558c38     CMP        BL,0x39
    //         00558c3b     JG         LAB_00558c47
    //         00558c3d     MOV        EAX,0x9
    //         00558c42     JMP        LAB_00558dc2
    //                               LAB_00558c47                                                 XREF[2]:     00558c36(j), 00558c3b(j)  
    //         00558c47     MOVSX      EAX,BL
    //         00558c4a     SUB        EAX,0x2b
    //         00558c4d     JZ         LAB_00558db6
    //         00558c53     SUB        EAX,0x2
    //         00558c56     JZ         LAB_00558da7
    //         00558c5c     SUB        EAX,0x3
    //         00558c5f     JMP        LAB_00558ca6
    //                               switchD_00558977::caseD_8                                    XREF[2]:     00558977(j), 00558f70(*)  
    //         00558c61     CMP        BL,0x30
    //         00558c64     MOV        dword ptr [ESP + local_44],ECX
    //         00558c68     JNZ        LAB_00558c73
    //                               LAB_00558c6a                                                 XREF[1]:     00558c71(j)  
    //         00558c6a     MOV        BL,byte ptr [EBP]
    //         00558c6d     INC        EBP
    //         00558c6e     CMP        BL,0x30
    //         00558c71     JZ         LAB_00558c6a
    //                               LAB_00558c73                                                 XREF[1]:     00558c68(j)  
    //         00558c73     CMP        BL,0x31
    //         00558c76     JL         switchD_00558bb2::caseD_2c
    //         00558c7c     CMP        BL,0x39
    //         00558c7f     JG         switchD_00558bb2::caseD_2c
    //         00558c85     MOV        EAX,0x9
    //         00558c8a     JMP        LAB_00558dc2
    //                               switchD_00558977::caseD_7                                    XREF[2]:     00558977(j), 00558f6c(*)  
    //         00558c8f     CMP        BL,0x31
    //         00558c92     JL         LAB_00558ca3
    //         00558c94     CMP        BL,0x39
    //         00558c97     JG         LAB_00558ca3
    //         00558c99     MOV        EAX,0x9
    //         00558c9e     JMP        LAB_00558dc2
    //                               LAB_00558ca3                                                 XREF[2]:     00558c92(j), 00558c97(j)  
    //         00558ca3     CMP        BL,0x30
    //                               LAB_00558ca6                                                 XREF[1]:     00558c5f(j)  
    //         00558ca6     JZ         LAB_00558cb4
    //         00558ca8     MOV        EAX,0xa
    //         00558cad     MOV        EBP,EDI
    //         00558caf     JMP        switchD_00558977::caseD_a
    //                               LAB_00558cb4                                                 XREF[1]:     00558ca6(j)  
    //         00558cb4     MOV        EAX,0x8
    //         00558cb9     JMP        switchD_00558977::caseD_a
    //                               switchD_00558977::caseD_9                                    XREF[2]:     00558977(j), 00558f74(*)  
    //         00558cbe     MOV        dword ptr [ESP + local_44],ECX
    //         00558cc2     XOR        EDI,EDI
    //                               LAB_00558cc4                                                 XREF[1]:     00558d1f(j)  
    //         00558cc4     CMP        dword ptr [___mb_cur_max],ECX                    = 00000001h
    //         00558cca     JLE        LAB_00558ce4
    //         00558ccc     MOV        ESI,dword ptr [ESP + Stack[0xc]]
    //         00558cd0     PUSH       0x4
    //         00558cd2     MOV        EAX,ESI
    //         00558cd4     AND        EAX,0xff
    //         00558cd9     PUSH       EAX
    //         00558cda     CALL       __isctype                                        undefined __isctype()
    //         00558cdf     ADD        ESP,0x8
    //         00558ce2     JMP        LAB_00558cfc
    //                               LAB_00558ce4                                                 XREF[1]:     00558cca(j)  
    //         00558ce4     MOV        ESI,dword ptr [ESP + Stack[0xc]]
    //         00558ce8     MOV        EDX,dword ptr [__pctype]                         = 005920da
    //         00558cee     MOV        ECX,ESI
    //         00558cf0     AND        ECX,0xff
    //         00558cf6     MOV        AL,byte ptr [EDX + ECX*0x2]=>DAT_005920da        = 20h     
    //         00558cf9     AND        EAX,0x4
    //                               LAB_00558cfc                                                 XREF[1]:     00558ce2(j)  
    //         00558cfc     TEST       EAX,EAX
    //         00558cfe     JZ         LAB_00558d26
    //         00558d00     MOVSX      ECX,BL
    //         00558d03     LEA        EAX,[EDI + EDI*0x4]
    //         00558d06     LEA        EDI,[ECX + EAX*0x2 + -0x30]
    //         00558d0a     CMP        EDI,0x1450
    //         00558d10     JG         LAB_00558d21
    //         00558d12     MOV        BL,byte ptr [EBP]
    //         00558d15     INC        EBP
    //         00558d16     MOV        byte ptr [ESP + Stack[0xc]],BL
    //         00558d1a     MOV        ECX,0x1
    //         00558d1f     JMP        LAB_00558cc4
    //                              language.dll match for 0x1451: "Dead tree"
    //                               LAB_00558d21                                                 XREF[1]:     00558d10(j)  
    //         00558d21     MOV        EDI,0x1451
    //                               LAB_00558d26                                                 XREF[1]:     00558cfe(j)  
    //         00558d26     MOV        dword ptr [ESP + local_48],EDI
    //                               LAB_00558d2a                                                 XREF[1]:     00558d68(j)  
    //         00558d2a     CMP        dword ptr [___mb_cur_max],0x1                    = 00000001h
    //         00558d31     JLE        LAB_00558d46
    //         00558d33     AND        ESI,0xff
    //         00558d39     PUSH       0x4
    //         00558d3b     PUSH       ESI
    //         00558d3c     CALL       __isctype                                        undefined __isctype()
    //         00558d41     ADD        ESP,0x8
    //         00558d44     JMP        LAB_00558d58
    //                               LAB_00558d46                                                 XREF[1]:     00558d31(j)  
    //         00558d46     MOV        EDX,dword ptr [__pctype]                         = 005920da
    //         00558d4c     AND        ESI,0xff
    //         00558d52     MOV        AL,byte ptr [EDX + ESI*0x2]=>DAT_005920da        = 20h     
    //         00558d55     AND        EAX,0x4
    //                               LAB_00558d58                                                 XREF[1]:     00558d44(j)  
    //         00558d58     TEST       EAX,EAX
    //         00558d5a     JZ         LAB_00558d6a
    //         00558d5c     MOV        AL,byte ptr [EBP]
    //         00558d5f     INC        EBP
    //         00558d60     MOV        byte ptr [ESP + Stack[0xc]],AL
    //         00558d64     MOV        ESI,dword ptr [ESP + Stack[0xc]]
    //         00558d68     JMP        LAB_00558d2a
    //                               LAB_00558d6a                                                 XREF[1]:     00558d5a(j)  
    //         00558d6a     MOV        ESI,dword ptr [ESP + local_54]
    //         00558d6e     MOV        EDI,dword ptr [ESP + local_50]
    //         00558d72     MOV        EAX,0xa
    //         00558d77     DEC        EBP
    //         00558d78     MOV        ECX,0x1
    //         00558d7d     JMP        switchD_00558977::caseD_a
    //                               switchD_00558977::caseD_b                                    XREF[2]:     00558977(j), 00558f7c(*)  
    //         00558d7f     MOV        EAX,dword ptr [ESP + Stack[0x1c]]
    //         00558d86     TEST       EAX,EAX
    //         00558d88     JZ         switchD_00558bb2::caseD_2c
    //         00558d8a     MOVSX      EAX,BL
    //         00558d8d     LEA        EDI,[EBP + -0x1]
    //         00558d90     SUB        EAX,0x2b
    //         00558d93     MOV        dword ptr [ESP + local_50],EDI
    //         00558d97     JZ         LAB_00558db6
    //         00558d99     SUB        EAX,0x2
    //         00558d9c     JZ         LAB_00558da7
    //         00558d9e     MOV        EAX,0xa
    //         00558da3     MOV        EBP,EDI
    //         00558da5     JMP        switchD_00558977::caseD_a
    //                               LAB_00558da7                                                 XREF[2]:     00558c56(j), 00558d9c(j)  
    //         00558da7     MOV        EAX,0x7
    //         00558dac     MOV        dword ptr [ESP + local_4c],0xffffffff
    //         00558db4     JMP        switchD_00558977::caseD_a
    //                               LAB_00558db6                                                 XREF[2]:     00558c4d(j), 00558d97(j)  
    //         00558db6     MOV        EAX,0x7
    //         00558dbb     JMP        switchD_00558977::caseD_a
    //                               switchD_00558bb2::caseD_2e                                   XREF[13]:    005589b4(j), 00558a18(j), 
    //                               switchD_00558bb2::caseD_2f                                                00558a26(j), 00558afc(j), 
    //                               switchD_00558bb2::caseD_30                                                00558b0a(j), 00558ba4(j), 
    //                               switchD_00558bb2::caseD_31                                                00558bb2(j), 00558c76(j), 
    //                               switchD_00558bb2::caseD_32                                                00558c7f(j), 00558d88(j), 
    //                               switchD_00558bb2::caseD_33                                                00558f94(*), 00558fe4(*), 
    //                               switchD_00558bb2::caseD_34                                                00559034(*)  
    //                               switchD_00558bb2::caseD_35
    //                               switchD_00558bb2::caseD_36
    //                               switchD_00558bb2::caseD_37
    //                               switchD_00558bb2::caseD_38
    //                               switchD_00558bb2::caseD_39
    //                               switchD_00558bb2::caseD_3a
    //                               switchD_00558bb2::caseD_3b
    //                               switchD_00558bb2::caseD_3c
    //                               switchD_00558bb2::caseD_3d
    //                               switchD_00558bb2::caseD_3e
    //                               switchD_00558bb2::caseD_3f
    //                               switchD_00558bb2::caseD_40
    //                               switchD_00558bb2::caseD_41
    //                               switchD_00558bb2::caseD_42
    //                               switchD_00558bb2::caseD_43
    //                               switchD_00558bb2::caseD_46
    //                               switchD_00558bb2::caseD_47
    //                               switchD_00558bb2::caseD_48
    //                               switchD_00558bb2::caseD_49
    //                               switchD_00558bb2::caseD_4a
    //                               switchD_00558bb2::caseD_4b
    //                               switchD_00558bb2::caseD_4c
    //                               switchD_00558bb2::caseD_4d
    //                               switchD_00558bb2::caseD_4e
    //                               switchD_00558bb2::caseD_4f
    //                               switchD_00558bb2::caseD_50
    //                               switchD_00558bb2::caseD_51
    //                               switchD_00558bb2::caseD_52
    //                               switchD_00558bb2::caseD_53
    //                               switchD_00558bb2::caseD_54
    //                               switchD_00558bb2::caseD_55
    //                               switchD_00558bb2::caseD_56
    //                               switchD_00558bb2::caseD_57
    //                               switchD_00558bb2::caseD_58
    //                               switchD_00558bb2::caseD_59
    //                               switchD_00558bb2::caseD_5a
    //                               switchD_00558bb2::caseD_5b
    //                               switchD_00558bb2::caseD_5c
    //                               switchD_00558bb2::caseD_5d
    //                               switchD_00558bb2::caseD_5e
    //                               switchD_00558bb2::caseD_5f
    //                               switchD_00558bb2::caseD_60
    //                               switchD_00558bb2::caseD_61
    //                               switchD_00558bb2::caseD_62
    //                               switchD_00558bb2::caseD_63
    //                               switchD_00558b0a::caseD_2c
    //                               switchD_00558b0a::caseD_2e
    //                               switchD_00558b0a::caseD_2f
    //                               switchD_00558b0a::caseD_30
    //                               switchD_00558b0a::caseD_31
    //                               switchD_00558b0a::caseD_32
    //                               switchD_00558b0a::caseD_33
    //                               switchD_00558b0a::caseD_34
    //                               switchD_00558b0a::caseD_35
    //                               switchD_00558b0a::caseD_36
    //                               switchD_00558b0a::caseD_37
    //                               switchD_00558b0a::caseD_38
    //                               switchD_00558b0a::caseD_39
    //                               switchD_00558b0a::caseD_3a
    //                               switchD_00558b0a::caseD_3b
    //                               switchD_00558b0a::caseD_3c
    //                               switchD_00558b0a::caseD_3d
    //                               switchD_00558b0a::caseD_3e
    //                               switchD_00558b0a::caseD_3f
    //                               switchD_00558b0a::caseD_40
    //                               switchD_00558b0a::caseD_41
    //                               switchD_00558b0a::caseD_42
    //                               switchD_00558b0a::caseD_43
    //                               switchD_00558b0a::caseD_46
    //                               switchD_00558b0a::caseD_47
    //                               switchD_00558b0a::caseD_48
    //                               switchD_00558b0a::caseD_49
    //                               switchD_00558b0a::caseD_4a
    //                               switchD_00558b0a::caseD_4b
    //                               switchD_00558b0a::caseD_4c
    //                               switchD_00558b0a::caseD_4d
    //                               switchD_00558b0a::caseD_4e
    //                               switchD_00558b0a::caseD_4f
    //                               switchD_00558b0a::caseD_50
    //                               switchD_00558b0a::caseD_51
    //                               switchD_00558b0a::caseD_52
    //                               switchD_00558b0a::caseD_53
    //                               switchD_00558b0a::caseD_54
    //                               switchD_00558b0a::caseD_55
    //                               switchD_00558b0a::caseD_56
    //                               switchD_00558b0a::caseD_57
    //                               switchD_00558b0a::caseD_58
    //                               switchD_00558b0a::caseD_59
    //                               switchD_00558b0a::caseD_5a
    //                               switchD_00558b0a::caseD_5b
    //                               switchD_00558b0a::caseD_5c
    //                               switchD_00558b0a::caseD_5d
    //                               switchD_00558b0a::caseD_5e
    //                               switchD_00558b0a::caseD_5f
    //                               switchD_00558b0a::caseD_60
    //                               switchD_00558b0a::caseD_61
    //                               switchD_00558b0a::caseD_62
    //                               switchD_00558b0a::caseD_63
    //                               switchD_00558a26::caseD_2c
    //                               switchD_00558a26::caseD_2e
    //                               switchD_00558a26::caseD_2f
    //                               switchD_00558a26::caseD_31
    //                               switchD_00558a26::caseD_32
    //                               switchD_00558a26::caseD_33
    //                               switchD_00558a26::caseD_34
    //                               switchD_00558a26::caseD_35
    //                               switchD_00558a26::caseD_36
    //                               switchD_00558a26::caseD_37
    //                               switchD_00558a26::caseD_38
    //                               switchD_00558a26::caseD_39
    //                               switchD_00558a26::caseD_3a
    //                               switchD_00558a26::caseD_3b
    //                               switchD_00558a26::caseD_3c
    //                               switchD_00558a26::caseD_3d
    //                               switchD_00558a26::caseD_3e
    //                               switchD_00558a26::caseD_3f
    //                               switchD_00558a26::caseD_40
    //                               switchD_00558a26::caseD_41
    //                               switchD_00558a26::caseD_42
    //                               switchD_00558a26::caseD_43
    //                               switchD_00558a26::caseD_46
    //                               switchD_00558a26::caseD_47
    //                               switchD_00558a26::caseD_48
    //                               switchD_00558a26::caseD_49
    //                               switchD_00558a26::caseD_4a
    //                               switchD_00558a26::caseD_4b
    //                               switchD_00558a26::caseD_4c
    //                               switchD_00558a26::caseD_4d
    //                               switchD_00558a26::caseD_4e
    //                               switchD_00558a26::caseD_4f
    //                               switchD_00558a26::caseD_50
    //                               switchD_00558a26::caseD_51
    //                               switchD_00558a26::caseD_52
    //                               switchD_00558a26::caseD_53
    //                               switchD_00558a26::caseD_54
    //                               switchD_00558a26::caseD_55
    //                               switchD_00558a26::caseD_56
    //                               switchD_00558a26::caseD_57
    //                               switchD_00558a26::caseD_58
    //                               switchD_00558a26::caseD_59
    //                               switchD_00558a26::caseD_5a
    //                               switchD_00558a26::caseD_5b
    //                               switchD_00558a26::caseD_5c
    //                               switchD_00558a26::caseD_5d
    //                               switchD_00558a26::caseD_5e
    //                               switchD_00558a26::caseD_5f
    //                               switchD_00558a26::caseD_60
    //                               switchD_00558a26::caseD_61
    //                               switchD_00558a26::caseD_62
    //                               switchD_00558a26::caseD_63
    //                               switchD_00558bb2::caseD_2c
    //         00558dbd     MOV        EAX,0xa
    //                               LAB_00558dc2                                                 XREF[6]:     0055898d(j), 005589f8(j), 
    //                                                                                                         00558a3c(j), 00558c42(j), 
    //                                                                                                         00558c8a(j), 00558c9e(j)  
    //         00558dc2     DEC        EBP
    //                               switchD_00558977::caseD_a                                    XREF[22]:    00558971(j), 00558977(j), 
    //                                                                                                         0055899f(j), 005589bc(j), 
    //                                                                                                         005589ce(j), 005589e0(j), 
    //                                                                                                         00558a0a(j), 00558a4e(j), 
    //                                                                                                         00558a5f(j), 00558a66(j), 
    //                                                                                                         00558aee(j), 00558bbe(j), 
    //                                                                                                         00558c16(j), 00558c27(j), 
    //                                                                                                         00558caf(j), 00558cb9(j), 
    //                                                                                                         00558d7d(j), 00558da5(j), 
    //                                                                                                         00558db4(j), 00558dbb(j), [more]
    //         00558dc3     CMP        EAX,0xa
    //         00558dc6     JNZ        LAB_00558962
    //         00558dcc     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //         00558dd0     MOV        EAX,dword ptr [ESP + local_58]
    //         00558dd4     TEST       EAX,EAX
    //         00558dd6     MOV        dword ptr [ECX],EBP
    //         00558dd8     JZ         LAB_00558e84
    //         00558dde     CMP        ESI,0x18
    //         00558de1     JBE        LAB_00558e06
    //         00558de3     MOV        AL,byte ptr [ESP + local_5]
    //         00558de7     CMP        AL,0x5
    //         00558de9     JL         LAB_00558df1
    //         00558deb     INC        AL
    //         00558ded     MOV        byte ptr [ESP + local_5],AL
    //                               LAB_00558df1                                                 XREF[1]:     00558de9(j)  
    //         00558df1     MOV        EAX,dword ptr [ESP + local_5c]
    //         00558df5     MOV        ECX,dword ptr [ESP + local_60]
    //         00558df9     DEC        EAX
    //         00558dfa     INC        ECX
    //         00558dfb     MOV        ESI,0x18
    //         00558e00     MOV        dword ptr [ESP + local_60],ECX
    //         00558e04     JMP        LAB_00558e0e
    //                               LAB_00558e06                                                 XREF[1]:     00558de1(j)  
    //         00558e06     MOV        EAX,dword ptr [ESP + local_5c]
    //         00558e0a     MOV        ECX,dword ptr [ESP + local_60]
    //                               LAB_00558e0e                                                 XREF[1]:     00558e04(j)  
    //         00558e0e     TEST       ESI,ESI
    //         00558e10     JBE        LAB_00558f43
    //         00558e16     MOV        DL,byte ptr [EAX + local_1d]
    //         00558e19     DEC        EAX
    //         00558e1a     TEST       DL,DL
    //         00558e1c     JNZ        LAB_00558e2c
    //                               LAB_00558e1e                                                 XREF[1]:     00558e26(j)  
    //         00558e1e     MOV        DL,byte ptr [EAX + local_1e]
    //         00558e21     DEC        ESI
    //         00558e22     INC        ECX
    //         00558e23     DEC        EAX
    //         00558e24     TEST       DL,DL
    //         00558e26     JZ         LAB_00558e1e
    //         00558e28     MOV        dword ptr [ESP + local_60],ECX
    //                               LAB_00558e2c                                                 XREF[1]:     00558e1c(j)  
    //         00558e2c     LEA        EDX=>local_2c,[ESP + 0x44]
    //         00558e30     LEA        EAX=>local_1c,[ESP + 0x54]
    //         00558e34     PUSH       EDX
    //         00558e35     PUSH       ESI
    //         00558e36     PUSH       EAX
    //         00558e37     CALL       ___mtold12                                       undefined ___mtold12()
    //         00558e3c     MOV        EAX,dword ptr [ESP + local_4c]
    //         00558e40     ADD        ESP,0xc
    //         00558e43     TEST       EAX,EAX
    //         00558e45     MOV        EAX,dword ptr [ESP + local_48]
    //         00558e49     JGE        LAB_00558e4d
    //         00558e4b     NEG        EAX
    //                               LAB_00558e4d                                                 XREF[1]:     00558e49(j)  
    //         00558e4d     MOV        EDX,dword ptr [ESP + local_60]
    //         00558e51     MOV        ECX,dword ptr [ESP + local_44]
    //         00558e55     ADD        EAX,EDX
    //         00558e57     TEST       ECX,ECX
    //         00558e59     JNZ        LAB_00558e62
    //         00558e5b     ADD        EAX,dword ptr [ESP + Stack[0x14]]
    //                               LAB_00558e62                                                 XREF[1]:     00558e59(j)  
    //         00558e62     MOV        ECX,dword ptr [ESP + local_40]
    //         00558e66     TEST       ECX,ECX
    //         00558e68     JNZ        LAB_00558e71
    //         00558e6a     SUB        EAX,dword ptr [ESP + Stack[0x18]]
    //                               LAB_00558e71                                                 XREF[1]:     00558e68(j)  
    //         00558e71     CMP        EAX,0x1450
    //         00558e76     JLE        LAB_00558f04
    //         00558e7c     MOV        dword ptr [ESP + local_38],0x1
    //                               LAB_00558e84                                                 XREF[2]:     00558dd8(j), 00558f13(j)  
    //         00558e84     MOV        ESI,dword ptr [ESP + Stack[0xc]]
    //         00558e88     MOV        EDX,dword ptr [ESP + Stack[0xc]]
    //         00558e8c     MOV        EAX,dword ptr [ESP + Stack[0xc]]
    //         00558e90     MOV        ECX,dword ptr [ESP + Stack[0xc]]
    //                               LAB_00558e94                                                 XREF[2]:     00558f3e(j), 00558f4b(j)  
    //         00558e94     MOV        EDI,dword ptr [ESP + local_58]
    //         00558e98     TEST       EDI,EDI
    //         00558e9a     JNZ        LAB_00558eab
    //         00558e9c     XOR        ECX,ECX
    //         00558e9e     XOR        EAX,EAX
    //         00558ea0     XOR        EDX,EDX
    //         00558ea2     XOR        ESI,ESI
    //         00558ea4     MOV        EBX,0x4
    //         00558ea9     JMP        LAB_00558ee3
    //                               LAB_00558eab                                                 XREF[1]:     00558e9a(j)  
    //         00558eab     MOV        EDI,dword ptr [ESP + local_38]
    //         00558eaf     TEST       EDI,EDI
    //         00558eb1     JZ         LAB_00558ec8
    //         00558eb3     XOR        ESI,ESI
    //         00558eb5     MOV        EAX,0x7fff
    //         00558eba     MOV        EDX,0x80000000
    //         00558ebf     XOR        ECX,ECX
    //         00558ec1     MOV        EBX,0x2
    //         00558ec6     JMP        LAB_00558ee3
    //                               LAB_00558ec8                                                 XREF[1]:     00558eb1(j)  
    //         00558ec8     MOV        EDI,dword ptr [ESP + local_34]
    //         00558ecc     TEST       EDI,EDI
    //         00558ece     JZ         LAB_00558edf
    //         00558ed0     XOR        ECX,ECX
    //         00558ed2     XOR        EAX,EAX
    //         00558ed4     XOR        EDX,EDX
    //         00558ed6     XOR        ESI,ESI
    //         00558ed8     MOV        EBX,0x1
    //         00558edd     JMP        LAB_00558ee3
    //                               LAB_00558edf                                                 XREF[1]:     00558ece(j)  
    //         00558edf     MOV        EBX,dword ptr [ESP + local_30]
    //                               LAB_00558ee3                                                 XREF[3]:     00558ea9(j), 00558ec6(j), 
    //                                                                                                         00558edd(j)  
    //         00558ee3     MOV        EDI,dword ptr [ESP + Stack[0x4]]
    //         00558ee7     MOV        word ptr [EDI],CX
    //         00558eea     MOV        ECX,dword ptr [ESP + local_3c]
    //         00558eee     OR         EAX,ECX
    //         00558ef0     MOV        dword ptr [EDI + 0x2],ESI
    //         00558ef3     MOV        dword ptr [EDI + 0x6],EDX
    //         00558ef6     MOV        word ptr [EDI + 0xa],AX
    //         00558efa     POP        EDI
    //         00558efb     POP        ESI
    //         00558efc     MOV        EAX,EBX
    //         00558efe     POP        EBP
    //         00558eff     POP        EBX
    //         00558f00     ADD        ESP,0x60
    //         00558f03     RET
    //                               LAB_00558f04                                                 XREF[1]:     00558e76(j)  
    //         00558f04     CMP        EAX,0xffffebb0
    //         00558f09     JGE        LAB_00558f18
    //         00558f0b     MOV        dword ptr [ESP + local_34],0x1
    //         00558f13     JMP        LAB_00558e84
    //                               LAB_00558f18                                                 XREF[1]:     00558f09(j)  
    //         00558f18     MOV        ECX,dword ptr [ESP + Stack[0x10]]
    //         00558f1f     LEA        EDX=>local_2c,[ESP + 0x44]
    //         00558f23     PUSH       ECX
    //         00558f24     PUSH       EAX
    //         00558f25     PUSH       EDX
    //         00558f26     CALL       ___multtenpow12                                  undefined ___multtenpow12()
    //         00558f2b     MOV        ECX,dword ptr [ESP + local_2c]
    //         00558f2f     MOV        ESI,dword ptr [ESP + local_2c+0x2]
    //         00558f33     MOV        EDX,dword ptr [ESP + local_26]
    //         00558f37     MOV        EAX,dword ptr [ESP + local_22]
    //         00558f3b     ADD        ESP,0xc
    //         00558f3e     JMP        LAB_00558e94
    //                               LAB_00558f43                                                 XREF[1]:     00558e10(j)  
    //         00558f43     XOR        ECX,ECX
    //         00558f45     XOR        EAX,EAX
    //         00558f47     XOR        EDX,EDX
    //         00558f49     XOR        ESI,ESI
    //         00558f4b     JMP        LAB_00558e94
    //                               switchD_00558977::switchdataD_00558f50                       XREF[1]:     ___strgtold12:00558977(R)  
}

