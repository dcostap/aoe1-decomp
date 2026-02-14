// Auto-generated scaffold unit: bucket_054C.asm
#include "../include/common.h"

// Offset: 0x0054C080
undefined fflush() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * fflush                                                                                                *
    //                              *********************************************************************************************************
    //                              undefined __cdecl fflush()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _fflush                                                      XREF[9]:     logCommonHistory:0040e8c4(c), 
    //                               fflush                                                                    write_draw_log:0041b643(c), 
    //                                                                                                         calc_timings:00421f4e(c), 
    //                                                                                                         FlushLog:004365ad(c), 
    //                                                                                                         Log:004367f1(c), 
    //                                                                                                         FUN_0054c150:0054c181(c), 
    //                                                                                                         FUN_0054c150:0054c19b(c), 
    //                                                                                                         osfx:0055a7dc(c), 
    //                                                                                                         osfx:0055a800(c)  
    //         0054c080     PUSH       ESI
    //         0054c081     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         0054c085     TEST       ESI,ESI
    //         0054c087     JNZ        LAB_0054c094
    //         0054c089     PUSH       ESI
    //         0054c08a     CALL       FUN_0054c150                                     undefined FUN_0054c150()
    //         0054c08f     ADD        ESP,0x4
    //         0054c092     POP        ESI
    //         0054c093     RET
    //                               LAB_0054c094                                                 XREF[1]:     0054c087(j)  
    //         0054c094     PUSH       ESI
    //         0054c095     CALL       __flush                                          undefined __flush()
    //         0054c09a     ADD        ESP,0x4
    //         0054c09d     TEST       EAX,EAX
    //         0054c09f     JZ         LAB_0054c0a6
    //         0054c0a1     OR         EAX,0xffffffff
    //         0054c0a4     POP        ESI
    //         0054c0a5     RET
    //                               LAB_0054c0a6                                                 XREF[1]:     0054c09f(j)  
    //         0054c0a6     MOV        EAX,dword ptr [ESI + 0xc]
    //         0054c0a9     TEST       AH,0x40
    //         0054c0ac     JZ         LAB_0054c0c0
    //         0054c0ae     MOV        EAX,dword ptr [ESI + 0x10]
    //         0054c0b1     PUSH       EAX
    //         0054c0b2     CALL       __commit                                         undefined __commit()
    //         0054c0b7     ADD        ESP,0x4
    //         0054c0ba     NEG        EAX
    //         0054c0bc     SBB        EAX,EAX
    //         0054c0be     POP        ESI
    //         0054c0bf     RET
    //                               LAB_0054c0c0                                                 XREF[1]:     0054c0ac(j)  
    //         0054c0c0     XOR        EAX,EAX
    //         0054c0c2     POP        ESI
    //         0054c0c3     RET
}

// Offset: 0x0054C0D0
undefined flush() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __flush()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __flush                                                      XREF[7]:     fclose:0054ba42(c), 
    //                                                                                                         fflush:0054c095(c), 
    //                                                                                                         rewind:0054c24a(c), 
    //                                                                                                         fseek:0054f29f(c), 
    //                                                                                                         fwrite:0054f399(c), 
    //                                                                                                         __ftbuf:00551706(c), 
    //                                                                                                         __ftbuf:0055173a(c)  
    //         0054c0d0     PUSH       EBX
    //         0054c0d1     PUSH       ESI
    //         0054c0d2     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         0054c0d6     XOR        EBX,EBX
    //         0054c0d8     PUSH       EDI
    //         0054c0d9     MOV        EAX,dword ptr [ESI + 0xc]
    //         0054c0dc     MOV        ECX,EAX
    //         0054c0de     AND        ECX,0x3
    //         0054c0e1     CMP        CL,0x2
    //         0054c0e4     JNZ        LAB_0054c12c
    //         0054c0e6     TEST       EAX,0x108
    //         0054c0eb     JZ         LAB_0054c12c
    //         0054c0ed     MOV        EAX,dword ptr [ESI + 0x8]
    //         0054c0f0     MOV        EDI,dword ptr [ESI]
    //         0054c0f2     SUB        EDI,EAX
    //         0054c0f4     TEST       EDI,EDI
    //         0054c0f6     JLE        LAB_0054c12c
    //         0054c0f8     MOV        EDX,dword ptr [ESI + 0x10]
    //         0054c0fb     PUSH       EDI
    //         0054c0fc     PUSH       EAX
    //         0054c0fd     PUSH       EDX
    //         0054c0fe     CALL       write                                            undefined write()
    //         0054c103     ADD        ESP,0xc
    //         0054c106     CMP        EAX,EDI
    //         0054c108     MOV        EAX,dword ptr [ESI + 0xc]
    //         0054c10b     JNZ        LAB_0054c124
    //         0054c10d     TEST       AL,0x80
    //         0054c10f     JZ         LAB_0054c12c
    //         0054c111     AND        AL,0xfd
    //         0054c113     MOV        dword ptr [ESI + 0x4],EBX
    //         0054c116     MOV        dword ptr [ESI + 0xc],EAX
    //         0054c119     MOV        EAX,dword ptr [ESI + 0x8]
    //         0054c11c     MOV        dword ptr [ESI],EAX
    //         0054c11e     MOV        EAX,EBX
    //         0054c120     POP        EDI
    //         0054c121     POP        ESI
    //         0054c122     POP        EBX
    //         0054c123     RET
    //                               LAB_0054c124                                                 XREF[1]:     0054c10b(j)  
    //         0054c124     OR         AL,0x20
    //         0054c126     OR         EBX,0xffffffff
    //         0054c129     MOV        dword ptr [ESI + 0xc],EAX
    //                               LAB_0054c12c                                                 XREF[4]:     0054c0e4(j), 0054c0eb(j), 
    //                                                                                                         0054c0f6(j), 0054c10f(j)  
    //         0054c12c     MOV        EAX,dword ptr [ESI + 0x8]
    //         0054c12f     MOV        dword ptr [ESI + 0x4],0x0
    //         0054c136     MOV        dword ptr [ESI],EAX
    //         0054c138     POP        EDI
    //         0054c139     MOV        EAX,EBX
    //         0054c13b     POP        ESI
    //         0054c13c     POP        EBX
    //         0054c13d     RET
}

// Offset: 0x0054C140
undefined flushall() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __flushall()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __flushall                                                   XREF[1]:     FUN_00553fa9:00553fb0(c)  
    //         0054c140     PUSH       0x1
    //         0054c142     CALL       FUN_0054c150                                     undefined FUN_0054c150()
    //         0054c147     ADD        ESP,0x4
    //         0054c14a     RET
}

// Offset: 0x0054C150
undefined FUN_0054c150() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054c150()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054c150                                                 XREF[2]:     fflush:0054c08a(c), 
    //                                                                                                         __flushall:0054c142(c)  
    //         0054c150     MOV        EAX,[__nstream]
    //         0054c155     PUSH       EBX
    //         0054c156     MOV        EBX,dword ptr [ESP + Stack[0x4]]
    //         0054c15a     PUSH       EBP
    //         0054c15b     PUSH       ESI
    //         0054c15c     PUSH       EDI
    //         0054c15d     XOR        EBP,EBP
    //         0054c15f     XOR        EDI,EDI
    //         0054c161     XOR        ESI,ESI
    //         0054c163     TEST       EAX,EAX
    //         0054c165     JLE        LAB_0054c1b4
    //                               LAB_0054c167                                                 XREF[1]:     0054c1b2(j)  
    //         0054c167     MOV        EAX,[___piob]
    //         0054c16c     MOV        EAX,dword ptr [EAX + ESI*0x4]
    //         0054c16f     TEST       EAX,EAX
    //         0054c171     JZ         LAB_0054c1aa
    //         0054c173     MOV        ECX,dword ptr [EAX + 0xc]
    //         0054c176     TEST       CL,0x83
    //         0054c179     JZ         LAB_0054c1aa
    //         0054c17b     CMP        EBX,0x1
    //         0054c17e     JNZ        LAB_0054c191
    //         0054c180     PUSH       EAX
    //         0054c181     CALL       fflush                                           undefined fflush()
    //         0054c186     ADD        ESP,0x4
    //         0054c189     CMP        EAX,-0x1
    //         0054c18c     JZ         LAB_0054c1aa
    //         0054c18e     INC        EBP
    //         0054c18f     JMP        LAB_0054c1aa
    //                               LAB_0054c191                                                 XREF[1]:     0054c17e(j)  
    //         0054c191     TEST       EBX,EBX
    //         0054c193     JNZ        LAB_0054c1aa
    //         0054c195     TEST       CL,0x2
    //         0054c198     JZ         LAB_0054c1aa
    //         0054c19a     PUSH       EAX
    //         0054c19b     CALL       fflush                                           undefined fflush()
    //         0054c1a0     ADD        ESP,0x4
    //         0054c1a3     CMP        EAX,-0x1
    //         0054c1a6     JNZ        LAB_0054c1aa
    //         0054c1a8     OR         EDI,EAX
    //                               LAB_0054c1aa                                                 XREF[7]:     0054c171(j), 0054c179(j), 
    //                                                                                                         0054c18c(j), 0054c18f(j), 
    //                                                                                                         0054c193(j), 0054c198(j), 
    //                                                                                                         0054c1a6(j)  
    //         0054c1aa     MOV        EAX,[__nstream]
    //         0054c1af     INC        ESI
    //         0054c1b0     CMP        ESI,EAX
    //         0054c1b2     JL         LAB_0054c167
    //                               LAB_0054c1b4                                                 XREF[1]:     0054c165(j)  
    //         0054c1b4     CMP        EBX,0x1
    //         0054c1b7     MOV        EAX,EBP
    //         0054c1b9     JZ         LAB_0054c1bd
    //         0054c1bb     MOV        EAX,EDI
    //                               LAB_0054c1bd                                                 XREF[1]:     0054c1b9(j)  
    //         0054c1bd     POP        EDI
    //         0054c1be     POP        ESI
    //         0054c1bf     POP        EBP
    //         0054c1c0     POP        EBX
    //         0054c1c1     RET
}

// Offset: 0x0054C1D0
undefined vsprintf() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * vsprintf                                                                                              *
    //                              *********************************************************************************************************
    //                              undefined __cdecl vsprintf()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[1]:     0054c1ef(W)  
    //              undefined4        Stack[-0x18]:4 local_18                  XREF[1]:     0054c1db(W)  
    //              undefined4        Stack[-0x1c]:4 local_1c                  XREF[3]:     0054c1f7(W), 0054c206(R), 0054c20e(W)  
    //              undefined4        Stack[-0x20]:4 local_20                  XREF[4]:     0054c1df(*), 0054c1e9(*), 0054c214(R), 0054c222(*)  
    //                               _vsprintf                                                    XREF[6]:     logCommonHistory:0040e86c(c), 
    //                               vsprintf                                                                  logDebug:0041a12a(c), 
    //                                                                                                         Log:00436683(c), 
    //                                                                                                         sendChatMessage:0046f2bb(c), 
    //                                                                                                         logDebug:004c73b7(c), 
    //                                                                                                         logMessage:0051500d(c)  
    //         0054c1d0     SUB        ESP,0x20
    //         0054c1d3     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054c1d7     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //         0054c1db     MOV        dword ptr [ESP + local_18],EAX
    //         0054c1df     MOV        dword ptr [ESP]=>local_20,EAX
    //         0054c1e3     MOV        EAX,dword ptr [ESP + Stack[0xc]]
    //         0054c1e7     PUSH       ESI
    //         0054c1e8     PUSH       EAX
    //         0054c1e9     LEA        EDX=>local_20,[ESP + 0x8]
    //         0054c1ed     PUSH       ECX
    //         0054c1ee     PUSH       EDX
    //         0054c1ef     MOV        dword ptr [ESP + local_14],0x42
    //         0054c1f7     MOV        dword ptr [ESP + local_1c],0x7fffffff
    //         0054c1ff     CALL       __output                                         undefined __output()
    //         0054c204     MOV        ESI,EAX
    //         0054c206     MOV        EAX,dword ptr [ESP + local_1c]
    //         0054c20a     ADD        ESP,0xc
    //         0054c20d     DEC        EAX
    //         0054c20e     MOV        dword ptr [ESP + local_1c],EAX
    //         0054c212     JS         LAB_0054c222
    //         0054c214     MOV        EAX,dword ptr [ESP + local_20]
    //         0054c218     MOV        byte ptr [EAX],0x0
    //         0054c21b     MOV        EAX,ESI
    //         0054c21d     POP        ESI
    //         0054c21e     ADD        ESP,0x20
    //         0054c221     RET
    //                               LAB_0054c222                                                 XREF[1]:     0054c212(j)  
    //         0054c222     LEA        ECX=>local_20,[ESP + 0x4]
    //         0054c226     PUSH       ECX
    //         0054c227     PUSH       0x0
    //         0054c229     CALL       __flsbuf                                         undefined __flsbuf()
    //         0054c22e     ADD        ESP,0x8
    //         0054c231     MOV        EAX,ESI
    //         0054c233     POP        ESI
    //         0054c234     ADD        ESP,0x20
    //         0054c237     RET
}

// Offset: 0x0054C240
undefined rewind() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * rewind                                                                                                *
    //                              *********************************************************************************************************
    //                              undefined __cdecl rewind()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _rewind                                                      XREF[1]:     loadPlays:00410405(c)  
    //                               rewind
    //         0054c240     PUSH       ESI
    //         0054c241     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         0054c245     PUSH       EDI
    //         0054c246     PUSH       ESI
    //         0054c247     MOV        EDI,dword ptr [ESI + 0x10]
    //         0054c24a     CALL       __flush                                          undefined __flush()
    //         0054c24f     MOV        ECX,dword ptr [ESI + 0xc]
    //         0054c252     ADD        ESP,0x4
    //         0054c255     AND        ECX,0xffffffcf
    //         0054c258     CMP        EDI,-0x1
    //         0054c25b     MOV        dword ptr [ESI + 0xc],ECX
    //         0054c25e     JZ         LAB_0054c276
    //         0054c260     MOV        EAX,EDI
    //         0054c262     MOV        ECX,EDI
    //         0054c264     SAR        EAX,0x5
    //         0054c267     AND        ECX,0x1f
    //         0054c26a     MOV        EDX,dword ptr [EAX*0x4 + ___pioinfo]
    //         0054c271     LEA        EAX,[EDX + ECX*0x8]
    //         0054c274     JMP        LAB_0054c27b
    //                               LAB_0054c276                                                 XREF[1]:     0054c25e(j)  
    //         0054c276     MOV        EAX,___badioinfo                                 = FFh
    //                               LAB_0054c27b                                                 XREF[1]:     0054c274(j)  
    //         0054c27b     MOV        DL,byte ptr [EAX + 0x4]=>DAT_005920cc
    //         0054c27e     AND        DL,0xfd
    //         0054c281     MOV        byte ptr [EAX + 0x4]=>DAT_005920cc,DL
    //         0054c284     MOV        EAX,dword ptr [ESI + 0xc]
    //         0054c287     TEST       AL,0x80
    //         0054c289     JZ         LAB_0054c290
    //         0054c28b     AND        AL,0xfc
    //         0054c28d     MOV        dword ptr [ESI + 0xc],EAX
    //                               LAB_0054c290                                                 XREF[1]:     0054c289(j)  
    //         0054c290     PUSH       0x0
    //         0054c292     PUSH       0x0
    //         0054c294     PUSH       EDI
    //         0054c295     CALL       lseek                                            undefined lseek()
    //         0054c29a     ADD        ESP,0xc
    //         0054c29d     POP        EDI
    //         0054c29e     POP        ESI
    //         0054c29f     RET
}

// Offset: 0x0054C2A0
undefined findfirst() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __findfirst()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined         Stack[-0x140   local_140                 XREF[1]:     0054c2aa(*)  
    //                               __findfirst                                                  XREF[37]:    setup:0041bca8(c), 
    //                                                                                                         setup:0041c07d(c), 
    //                                                                                                         find_campaigns:0044d503(c), 
    //                                                                                                         find_campaigns:0044d561(c), 
    //                                                                                                         find_campaigns:0044d5d4(c), 
    //                                                                                                         find_campaigns:0044d664(c), 
    //                                                                                                         reload_scenarios:0048d125(c), 
    //                                                                                                         reload_scenarios:0048d17d(c), 
    //                                                                                                         fill_campaign_drop:0048fc12(c), 
    //                                                                                                         fill_campaign_drop:0048fca8(c), 
    //                                                                                                         fillList:0049e1a6(c), 
    //                                                                                                         fillList:0049e23d(c), 
    //                                                                                                         fillList:004a7700(c), 
    //                                                                                                         fillList:004a77d0(c), 
    //                                                                                                         MakeFileList:004b2b24(c), 
    //                                                                                                         fillList:004b3796(c), 
    //                                                                                                         fillList:004b382d(c), 
    //                                                                                                         quit_game:005242a2(c), 
    //                                                                                                         restart_game:00524451(c), 
    //                                                                                                         start_scenario:00525fe6(c), [more]
    //         0054c2a0     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         0054c2a4     SUB        ESP,0x140
    //         0054c2aa     LEA        EAX=>local_140,[ESP]
    //         0054c2ae     PUSH       EBX
    //         0054c2af     PUSH       EAX
    //         0054c2b0     PUSH       ECX
    //         0054c2b1     CALL       dword ptr [->KERNEL32.DLL::FindFirstFileA]       = 0048ac9c
    //         0054c2b7     MOV        EBX,EAX
    //         0054c2b9     CMP        EBX,-0x1
    //         0054c2bc     JNZ        LAB_0054c31a
    //         0054c2be     CALL       dword ptr [->KERNEL32.DLL::GetLastError]         = 0048aa76
    //         0054c2c4     ADD        EAX,-0x2
    //         0054c2c7     CMP        EAX,0x10
    //         0054c2ca     JA         switchD_0054c2d4::caseD_4
    //         0054c2cc     XOR        EDX,EDX
    //         0054c2ce     MOV        DL,byte ptr [EAX + 0x54c3b0]=>PTR_caseD_4_0054
    //                               switchD_0054c2d4::switchD
    //         0054c2d4     JMP        dword ptr [EDX*0x4 + switchD_0054c2d4::switchd   = 0054c2db
    //                               switchD_0054c2d4::caseD_3                                    XREF[3]:     0054c2d4(j), 0054c3a0(*), 
    //                               switchD_0054c2d4::caseD_12                                                0054c3a8(*)  
    //                               switchD_0054c2d4::caseD_2
    //         0054c2db     MOV        dword ptr [_errno],0x2                           = align(4)
    //         0054c2e5     OR         EAX,0xffffffff
    //         0054c2e8     POP        EBX
    //         0054c2e9     ADD        ESP,0x140
    //         0054c2ef     RET
    //                               switchD_0054c2d4::caseD_8                                    XREF[2]:     0054c2d4(j), 0054c3a4(*)  
    //         0054c2f0     MOV        dword ptr [_errno],0xc                           = align(4)
    //         0054c2fa     OR         EAX,0xffffffff
    //         0054c2fd     POP        EBX
    //         0054c2fe     ADD        ESP,0x140
    //         0054c304     RET
    //                               switchD_0054c2d4::caseD_5                                    XREF[3]:     0054c2ca(j), 0054c2d4(j), 
    //                               switchD_0054c2d4::caseD_6                                                 0054c3ac(*)  
    //                               switchD_0054c2d4::caseD_7
    //                               switchD_0054c2d4::caseD_9
    //                               switchD_0054c2d4::caseD_a
    //                               switchD_0054c2d4::caseD_b
    //                               switchD_0054c2d4::caseD_c
    //                               switchD_0054c2d4::caseD_d
    //                               switchD_0054c2d4::caseD_e
    //                               switchD_0054c2d4::caseD_f
    //                               switchD_0054c2d4::caseD_10
    //                               switchD_0054c2d4::caseD_11
    //                               switchD_0054c2d4::caseD_4
    //         0054c305     MOV        dword ptr [_errno],0x16                          = align(4)
    //         0054c30f     OR         EAX,0xffffffff
    //         0054c312     POP        EBX
    //         0054c313     ADD        ESP,0x140
    //         0054c319     RET
    //                               LAB_0054c31a                                                 XREF[1]:     0054c2bc(j)  
    //         0054c31a     MOV        EAX,dword ptr [ESP + 0x4]
    //         0054c31e     PUSH       EDI
    //         0054c31f     MOV        ECX,EAX
    //         0054c321     PUSH       ESI
    //         0054c322     MOV        ESI,dword ptr [ESP + 0x154]
    //         0054c329     SUB        ECX,0x80
    //         0054c32f     NEG        ECX
    //         0054c331     SBB        ECX,ECX
    //         0054c333     LEA        EDX,[ESP + 0x10]
    //         0054c337     AND        ECX,EAX
    //         0054c339     PUSH       EDX
    //         0054c33a     MOV        dword ptr [ESI],ECX
    //         0054c33c     CALL       ___timet_from_ft                                 undefined ___timet_from_ft()
    //         0054c341     ADD        ESP,0x4
    //         0054c344     MOV        dword ptr [ESI + 0x4],EAX
    //         0054c347     LEA        EAX,[ESP + 0x18]
    //         0054c34b     PUSH       EAX
    //         0054c34c     CALL       ___timet_from_ft                                 undefined ___timet_from_ft()
    //         0054c351     ADD        ESP,0x4
    //         0054c354     LEA        ECX,[ESP + 0x20]
    //         0054c358     MOV        dword ptr [ESI + 0x8],EAX
    //         0054c35b     PUSH       ECX
    //         0054c35c     CALL       ___timet_from_ft                                 undefined ___timet_from_ft()
    //         0054c361     MOV        dword ptr [ESI + 0xc],EAX
    //         0054c364     LEA        EDI,[ESP + 0x3c]
    //         0054c368     OR         ECX,0xffffffff
    //         0054c36b     XOR        EAX,EAX
    //         0054c36d     ADD        ESP,0x4
    //         0054c370     MOV        EDX,dword ptr [ESP + 0x2c]
    //         0054c374     SCASB.RE   ES:EDI
    //         0054c376     NOT        ECX
    //         0054c378     SUB        EDI,ECX
    //         0054c37a     MOV        dword ptr [ESI + 0x10],EDX
    //         0054c37d     LEA        EDX,[ESI + 0x14]
    //         0054c380     MOV        EAX,ECX
    //         0054c382     MOV        ESI,EDI
    //         0054c384     MOV        EDI,EDX
    //         0054c386     SHR        ECX,0x2
    //         0054c389     MOVSD.REP  ES:EDI,ESI
    //         0054c38b     MOV        ECX,EAX
    //         0054c38d     MOV        EAX,EBX
    //         0054c38f     AND        ECX,0x3
    //         0054c392     MOVSB.REP  ES:EDI,ESI
    //         0054c394     POP        ESI
    //         0054c395     POP        EDI
    //         0054c396     POP        EBX
    //         0054c397     ADD        ESP,0x140
    //         0054c39d     RET
}

// Offset: 0x0054C39E
undefined FUN_0054c39e() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054c39e()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054c39e
    //         0054c39e     MOV        EDI,EDI
    //                               switchD_0054c2d4::switchdataD_0054c3a0                       XREF[1]:     __findfirst:0054c2d4(*)  
}

// Offset: 0x0054C3D0
undefined findnext() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __findnext()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined         Stack[-0x140   local_140                 XREF[1]:     0054c3da(*)  
    //                               __findnext                                                   XREF[24]:    numberOfFilesWithFilename:004498d8
    //                                                                                                         numberOfFilesWithFilename:004498ec
    //                                                                                                         numberOfFilesWithAttribute:0044994
    //                                                                                                         find_campaigns:0044d524(c), 
    //                                                                                                         find_campaigns:0044d57c(c), 
    //                                                                                                         find_campaigns:0044d626(c), 
    //                                                                                                         find_campaigns:0044d6bd(c), 
    //                                                                                                         reload_scenarios:0048d13e(c), 
    //                                                                                                         reload_scenarios:0048d196(c), 
    //                                                                                                         reload_scenarios:0048d3ec(c), 
    //                                                                                                         fill_campaign_drop:0048fc6d(c), 
    //                                                                                                         fill_campaign_drop:0048fd03(c), 
    //                                                                                                         fill_scenario_list:0048fdd1(c), 
    //                                                                                                         fill_scenario_list:0048fe68(c), 
    //                                                                                                         fillList:0049e201(c), 
    //                                                                                                         fillList:0049e298(c), 
    //                                                                                                         fillList:004a775b(c), 
    //                                                                                                         fillList:004a782b(c), 
    //                                                                                                         MakeFileList:004b2b95(c), 
    //                                                                                                         fillList:004b37f1(c), [more]
    //         0054c3d0     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         0054c3d4     SUB        ESP,0x140
    //         0054c3da     LEA        EAX=>local_140,[ESP]
    //         0054c3de     PUSH       EAX
    //         0054c3df     PUSH       ECX
    //         0054c3e0     CALL       dword ptr [->KERNEL32.DLL::FindNextFileA]        = 0048b70c
    //         0054c3e6     TEST       EAX,EAX
    //         0054c3e8     JNZ        LAB_0054c443
    //         0054c3ea     CALL       dword ptr [->KERNEL32.DLL::GetLastError]         = 0048aa76
    //         0054c3f0     ADD        EAX,-0x2
    //         0054c3f3     CMP        EAX,0x10
    //         0054c3f6     JA         switchD_0054c400::caseD_4
    //         0054c3f8     XOR        EDX,EDX
    //         0054c3fa     MOV        DL,byte ptr [EAX + 0x54c4d8]=>PTR_caseD_4_0054
    //                               switchD_0054c400::switchD
    //         0054c400     JMP        dword ptr [EDX*0x4 + switchD_0054c400::switchd   = 0054c407
    //                               switchD_0054c400::caseD_3                                    XREF[3]:     0054c400(j), 0054c4c8(*), 
    //                               switchD_0054c400::caseD_12                                                0054c4d0(*)  
    //                               switchD_0054c400::caseD_2
    //         0054c407     MOV        dword ptr [_errno],0x2                           = align(4)
    //         0054c411     OR         EAX,0xffffffff
    //         0054c414     ADD        ESP,0x140
    //         0054c41a     RET
    //                               switchD_0054c400::caseD_8                                    XREF[2]:     0054c400(j), 0054c4cc(*)  
    //         0054c41b     MOV        dword ptr [_errno],0xc                           = align(4)
    //         0054c425     OR         EAX,0xffffffff
    //         0054c428     ADD        ESP,0x140
    //         0054c42e     RET
    //                               switchD_0054c400::caseD_5                                    XREF[3]:     0054c3f6(j), 0054c400(j), 
    //                               switchD_0054c400::caseD_6                                                 0054c4d4(*)  
    //                               switchD_0054c400::caseD_7
    //                               switchD_0054c400::caseD_9
    //                               switchD_0054c400::caseD_a
    //                               switchD_0054c400::caseD_b
    //                               switchD_0054c400::caseD_c
    //                               switchD_0054c400::caseD_d
    //                               switchD_0054c400::caseD_e
    //                               switchD_0054c400::caseD_f
    //                               switchD_0054c400::caseD_10
    //                               switchD_0054c400::caseD_11
    //                               switchD_0054c400::caseD_4
    //         0054c42f     MOV        dword ptr [_errno],0x16                          = align(4)
    //         0054c439     OR         EAX,0xffffffff
    //         0054c43c     ADD        ESP,0x140
    //         0054c442     RET
    //                               LAB_0054c443                                                 XREF[1]:     0054c3e8(j)  
    //         0054c443     MOV        EAX,dword ptr [ESP]
    //         0054c447     PUSH       EDI
    //         0054c448     MOV        ECX,EAX
    //         0054c44a     PUSH       ESI
    //         0054c44b     MOV        ESI,dword ptr [ESP + 0x150]
    //         0054c452     SUB        ECX,0x80
    //         0054c458     NEG        ECX
    //         0054c45a     SBB        ECX,ECX
    //         0054c45c     LEA        EDX,[ESP + 0xc]
    //         0054c460     AND        ECX,EAX
    //         0054c462     PUSH       EDX
    //         0054c463     MOV        dword ptr [ESI],ECX
    //         0054c465     CALL       ___timet_from_ft                                 undefined ___timet_from_ft()
    //         0054c46a     ADD        ESP,0x4
    //         0054c46d     MOV        dword ptr [ESI + 0x4],EAX
    //         0054c470     LEA        EAX,[ESP + 0x14]
    //         0054c474     PUSH       EAX
    //         0054c475     CALL       ___timet_from_ft                                 undefined ___timet_from_ft()
    //         0054c47a     ADD        ESP,0x4
    //         0054c47d     LEA        ECX,[ESP + 0x1c]
    //         0054c481     MOV        dword ptr [ESI + 0x8],EAX
    //         0054c484     PUSH       ECX
    //         0054c485     CALL       ___timet_from_ft                                 undefined ___timet_from_ft()
    //         0054c48a     MOV        dword ptr [ESI + 0xc],EAX
    //         0054c48d     LEA        EDI,[ESP + 0x38]
    //         0054c491     OR         ECX,0xffffffff
    //         0054c494     XOR        EAX,EAX
    //         0054c496     ADD        ESP,0x4
    //         0054c499     MOV        EDX,dword ptr [ESP + 0x28]
    //         0054c49d     SCASB.RE   ES:EDI
    //         0054c49f     NOT        ECX
    //         0054c4a1     SUB        EDI,ECX
    //         0054c4a3     MOV        dword ptr [ESI + 0x10],EDX
    //         0054c4a6     LEA        EDX,[ESI + 0x14]
    //         0054c4a9     MOV        EAX,ECX
    //         0054c4ab     MOV        ESI,EDI
    //         0054c4ad     MOV        EDI,EDX
    //         0054c4af     SHR        ECX,0x2
    //         0054c4b2     MOVSD.REP  ES:EDI,ESI
    //         0054c4b4     MOV        ECX,EAX
    //         0054c4b6     AND        ECX,0x3
    //         0054c4b9     XOR        EAX,EAX
    //         0054c4bb     MOVSB.REP  ES:EDI,ESI
    //         0054c4bd     POP        ESI
    //         0054c4be     POP        EDI
    //         0054c4bf     ADD        ESP,0x140
    //         0054c4c5     RET
}

// Offset: 0x0054C4C6
undefined FUN_0054c4c6() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054c4c6()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054c4c6
    //         0054c4c6     MOV        EDI,EDI
    //                               switchD_0054c400::switchdataD_0054c4c8                       XREF[1]:     __findnext:0054c400(*)  
}

// Offset: 0x0054C510
undefined timet_from_ft() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined ___timet_from_ft()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined         Stack[-0x18]:1 local_18                  XREF[1]:     0054c523(*)  
    //                               ___timet_from_ft                                             XREF[6]:     __findfirst:0054c33c(c), 
    //                                                                                                         __findfirst:0054c34c(c), 
    //                                                                                                         __findfirst:0054c35c(c), 
    //                                                                                                         __findnext:0054c465(c), 
    //                                                                                                         __findnext:0054c475(c), 
    //                                                                                                         __findnext:0054c485(c)  
    //         0054c510     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054c514     SUB        ESP,0x18
    //         0054c517     CMP        dword ptr [EAX],0x0
    //         0054c51a     JNZ        LAB_0054c523
    //         0054c51c     MOV        ECX,dword ptr [EAX + 0x4]
    //         0054c51f     TEST       ECX,ECX
    //         0054c521     JZ         LAB_0054c595
    //                               LAB_0054c523                                                 XREF[1]:     0054c51a(j)  
    //         0054c523     LEA        ECX=>local_18,[ESP]
    //         0054c527     PUSH       ECX
    //         0054c528     PUSH       EAX
    //         0054c529     CALL       dword ptr [->KERNEL32.DLL::FileTimeToLocalFile   = 0048b71c
    //         0054c52f     TEST       EAX,EAX
    //         0054c531     JZ         LAB_0054c595
    //         0054c533     LEA        EDX,[ESP + 0x8]
    //         0054c537     LEA        EAX,[ESP]
    //         0054c53b     PUSH       EDX
    //         0054c53c     PUSH       EAX
    //         0054c53d     CALL       dword ptr [->KERNEL32.DLL::FileTimeToSystemTime] = 0048ac84
    //         0054c543     TEST       EAX,EAX
    //         0054c545     JZ         LAB_0054c595
    //         0054c547     MOV        ECX,dword ptr [ESP + 0x14]
    //         0054c54b     MOV        EDX,dword ptr [ESP + 0x12]
    //         0054c54f     MOV        EAX,dword ptr [ESP + 0x10]
    //         0054c553     AND        ECX,0xffff
    //         0054c559     PUSH       -0x1
    //         0054c55b     AND        EDX,0xffff
    //         0054c561     PUSH       ECX
    //         0054c562     MOV        ECX,dword ptr [ESP + 0x16]
    //         0054c566     AND        EAX,0xffff
    //         0054c56b     PUSH       EDX
    //         0054c56c     MOV        EDX,dword ptr [ESP + 0x16]
    //         0054c570     PUSH       EAX
    //         0054c571     MOV        EAX,dword ptr [ESP + 0x18]
    //         0054c575     AND        ECX,0xffff
    //         0054c57b     AND        EDX,0xffff
    //         0054c581     PUSH       ECX
    //         0054c582     AND        EAX,0xffff
    //         0054c587     PUSH       EDX
    //         0054c588     PUSH       EAX
    //         0054c589     CALL       ___loctotime_t                                   undefined ___loctotime_t()
    //         0054c58e     ADD        ESP,0x1c
    //         0054c591     ADD        ESP,0x18
    //         0054c594     RET
    //                               LAB_0054c595                                                 XREF[3]:     0054c521(j), 0054c531(j), 
    //                                                                                                         0054c545(j)  
    //         0054c595     OR         EAX,0xffffffff
    //         0054c598     ADD        ESP,0x18
    //         0054c59b     RET
}

// Offset: 0x0054C5A0
undefined malloc() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * malloc                                                                                                *
    //                              *********************************************************************************************************
    //                              undefined __cdecl malloc()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _malloc                                                      XREF[83]:    RESFILE_load:0047f3e3(c), 
    //                               malloc                                                                    TShape:004b8c33(c), 
    //                                                                                                         TShape:004b8ce2(c), 
    //                                                                                                         load:004bce84(c), 
    //                                                                                                         load:004bcee3(c), 
    //                                                                                                         load:004bd0de(c), 
    //                                                                                                         load:004bd13a(c), 
    //                                                                                                         InitNewZone:004bd754(c), 
    //                                                                                                         __stbuf:005516aa(c), 
    //                                                                                                         __getstream:005533e4(c), 
    //                                                                                                         __tzset:005536e5(c), 
    //                                                                                                         realloc:005562b4(c), 
    //                                                                                                         __getbuf:00558480(c), 
    //                                                                                                         ___wtomb_environ:00559b1e(c), 
    //                                                                                                         ___crtCompareStringA:0055a320(c), 
    //                                                                                                         ___crtCompareStringA:0055a368(c), 
    //                                                                                                         ___crtsetenv:0055a49c(c), 
    //                                                                                                         ___crtsetenv:0055a4c2(c), 
    //                                                                                                         ___crtsetenv:0055a56a(c), 
    //                                                                                                         FUN_0055a6a0:0055a6cc(c), [more]
    //         0054c5a0     MOV        EAX,[__newmode]
    //         0054c5a5     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         0054c5a9     PUSH       EAX
    //         0054c5aa     PUSH       ECX
    //         0054c5ab     CALL       __nh_malloc                                      undefined __nh_malloc()
    //         0054c5b0     ADD        ESP,0x8
    //         0054c5b3     RET
}

// Offset: 0x0054C5C0
undefined nh_malloc() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __nh_malloc()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __nh_malloc                                                  XREF[2]:     operator_new:0054b6f7(c), 
    //                                                                                                         malloc:0054c5ab(c)  
    //         0054c5c0     PUSH       ESI
    //         0054c5c1     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         0054c5c5     CMP        ESI,-0x20
    //         0054c5c8     PUSH       EDI
    //         0054c5c9     JA         LAB_0054c5ff
    //         0054c5cb     TEST       ESI,ESI
    //         0054c5cd     JNZ        LAB_0054c5d4
    //         0054c5cf     MOV        ESI,0x1
    //                               LAB_0054c5d4                                                 XREF[1]:     0054c5cd(j)  
    //         0054c5d4     MOV        EDI,dword ptr [ESP + Stack[0x8]]
    //                               LAB_0054c5d8                                                 XREF[1]:     0054c5fd(j)  
    //         0054c5d8     CMP        ESI,-0x20
    //         0054c5db     JA         LAB_0054c5e8
    //         0054c5dd     PUSH       ESI
    //         0054c5de     CALL       __heap_alloc                                     undefined __heap_alloc()
    //         0054c5e3     ADD        ESP,0x4
    //         0054c5e6     JMP        LAB_0054c5ea
    //                               LAB_0054c5e8                                                 XREF[1]:     0054c5db(j)  
    //         0054c5e8     XOR        EAX,EAX
    //                               LAB_0054c5ea                                                 XREF[1]:     0054c5e6(j)  
    //         0054c5ea     TEST       EAX,EAX
    //         0054c5ec     JNZ        LAB_0054c601
    //         0054c5ee     TEST       EDI,EDI
    //         0054c5f0     JZ         LAB_0054c601
    //         0054c5f2     PUSH       ESI
    //         0054c5f3     CALL       __callnewh                                       undefined __callnewh()
    //         0054c5f8     ADD        ESP,0x4
    //         0054c5fb     TEST       EAX,EAX
    //         0054c5fd     JNZ        LAB_0054c5d8
    //                               LAB_0054c5ff                                                 XREF[1]:     0054c5c9(j)  
    //         0054c5ff     XOR        EAX,EAX
    //                               LAB_0054c601                                                 XREF[2]:     0054c5ec(j), 0054c5f0(j)  
    //         0054c601     POP        EDI
    //         0054c602     POP        ESI
    //         0054c603     RET
}

// Offset: 0x0054C610
undefined heap_alloc() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __heap_alloc()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __heap_alloc                                                 XREF[1]:     __nh_malloc:0054c5de(c)  
    //         0054c610     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054c614     PUSH       ESI
    //         0054c615     LEA        ESI,[EAX + 0xf]
    //         0054c618     MOV        EAX,[___sbh_threshold]                           = 000001E0h
    //         0054c61d     AND        ESI,0xfffffff0
    //         0054c620     CMP        ESI,EAX
    //         0054c622     JA         LAB_0054c636
    //         0054c624     MOV        ECX,ESI
    //         0054c626     SHR        ECX,0x4
    //         0054c629     PUSH       ECX
    //         0054c62a     CALL       ___sbh_alloc_block                               undefined ___sbh_alloc_block()
    //         0054c62f     ADD        ESP,0x4
    //         0054c632     TEST       EAX,EAX
    //         0054c634     JNZ        LAB_0054c646
    //                               LAB_0054c636                                                 XREF[1]:     0054c622(j)  
    //         0054c636     MOV        EDX,dword ptr [__crtheap]
    //         0054c63c     PUSH       ESI
    //         0054c63d     PUSH       0x0
    //         0054c63f     PUSH       EDX
    //         0054c640     CALL       dword ptr [->KERNEL32.DLL::HeapAlloc]            = 0048b6ac
    //                               LAB_0054c646                                                 XREF[1]:     0054c634(j)  
    //         0054c646     POP        ESI
    //         0054c647     RET
}

// Offset: 0x0054C650
undefined atol() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * atol                                                                                                  *
    //                              *********************************************************************************************************
    //                              undefined __cdecl atol()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _atol                                                        XREF[17]:    setup_cmd_options:0041d3d1(c), 
    //                               atol                                                                      setup_cmd_options:0041d46f(c), 
    //                                                                                                         setup_cmd_options:0041dbdf(c), 
    //                                                                                                         setup_cmd_options:0041dc7f(c), 
    //                                                                                                         setup_cmd_options:0041e01c(c), 
    //                                                                                                         setup_cmd_options:0041e0c6(c), 
    //                                                                                                         setup_cmd_options:0041e164(c), 
    //                                                                                                         setup_cmd_options:0041e200(c), 
    //                                                                                                         setup_cmd_options:0041e595(c), 
    //                                                                                                         setup_cmd_options:0041e633(c), 
    //                                                                                                         ReadPalette:004398b0(c), 
    //                                                                                                         setup_cmd_options:0052206c(c), 
    //                                                                                                         setup_cmd_options:0052214e(c), 
    //                                                                                                         atoi:0054c6f5(c), 
    //                                                                                                         __tzset:0055374f(c), 
    //                                                                                                         __tzset:00553783(c), 
    //                                                                                                         __tzset:005537bb(c)  
    //         0054c650     PUSH       EBX
    //         0054c651     PUSH       EBP
    //         0054c652     PUSH       ESI
    //         0054c653     PUSH       EDI
    //         0054c654     MOV        EDI,dword ptr [ESP + Stack[0x4]]
    //                               LAB_0054c658                                                 XREF[1]:     0054c687(j)  
    //         0054c658     CMP        dword ptr [___mb_cur_max],0x1                    = 00000001h
    //         0054c65f     JLE        LAB_0054c672
    //         0054c661     XOR        EAX,EAX
    //         0054c663     PUSH       0x8
    //         0054c665     MOV        AL,byte ptr [EDI]
    //         0054c667     PUSH       EAX
    //         0054c668     CALL       __isctype                                        undefined __isctype()
    //         0054c66d     ADD        ESP,0x8
    //         0054c670     JMP        LAB_0054c682
    //                               LAB_0054c672                                                 XREF[1]:     0054c65f(j)  
    //         0054c672     MOV        EDX,dword ptr [__pctype]                         = 005920da
    //         0054c678     XOR        ECX,ECX
    //         0054c67a     MOV        CL,byte ptr [EDI]
    //         0054c67c     MOV        AL,byte ptr [EDX + ECX*0x2]=>DAT_005920da        = 20h     
    //         0054c67f     AND        EAX,0x8
    //                               LAB_0054c682                                                 XREF[1]:     0054c670(j)  
    //         0054c682     TEST       EAX,EAX
    //         0054c684     JZ         LAB_0054c689
    //         0054c686     INC        EDI
    //         0054c687     JMP        LAB_0054c658
    //                               LAB_0054c689                                                 XREF[1]:     0054c684(j)  
    //         0054c689     XOR        EAX,EAX
    //         0054c68b     MOV        AL,byte ptr [EDI]
    //         0054c68d     INC        EDI
    //         0054c68e     MOV        ESI,EAX
    //         0054c690     CMP        ESI,0x2d
    //         0054c693     MOV        EBP,ESI
    //         0054c695     JZ         LAB_0054c69c
    //         0054c697     CMP        ESI,0x2b
    //         0054c69a     JNZ        LAB_0054c6a3
    //                               LAB_0054c69c                                                 XREF[1]:     0054c695(j)  
    //         0054c69c     XOR        ECX,ECX
    //         0054c69e     MOV        CL,byte ptr [EDI]
    //         0054c6a0     INC        EDI
    //         0054c6a1     MOV        ESI,ECX
    //                               LAB_0054c6a3                                                 XREF[1]:     0054c69a(j)  
    //         0054c6a3     XOR        EBX,EBX
    //                               LAB_0054c6a5                                                 XREF[1]:     0054c6d9(j)  
    //         0054c6a5     CMP        dword ptr [___mb_cur_max],0x1                    = 00000001h
    //         0054c6ac     JLE        LAB_0054c6bb
    //         0054c6ae     PUSH       0x4
    //         0054c6b0     PUSH       ESI
    //         0054c6b1     CALL       __isctype                                        undefined __isctype()
    //         0054c6b6     ADD        ESP,0x8
    //         0054c6b9     JMP        LAB_0054c6c7
    //                               LAB_0054c6bb                                                 XREF[1]:     0054c6ac(j)  
    //         0054c6bb     MOV        EDX,dword ptr [__pctype]                         = 005920da
    //         0054c6c1     MOV        AL,byte ptr [EDX + ESI*0x2]=>DAT_005920da        = 20h     
    //         0054c6c4     AND        EAX,0x4
    //                               LAB_0054c6c7                                                 XREF[1]:     0054c6b9(j)  
    //         0054c6c7     TEST       EAX,EAX
    //         0054c6c9     JZ         LAB_0054c6db
    //         0054c6cb     LEA        EAX,[EBX + EBX*0x4]
    //         0054c6ce     XOR        ECX,ECX
    //         0054c6d0     MOV        CL,byte ptr [EDI]
    //         0054c6d2     INC        EDI
    //         0054c6d3     LEA        EBX,[ESI + EAX*0x2 + -0x30]
    //         0054c6d7     MOV        ESI,ECX
    //         0054c6d9     JMP        LAB_0054c6a5
    //                               LAB_0054c6db                                                 XREF[1]:     0054c6c9(j)  
    //         0054c6db     CMP        EBP,0x2d
    //         0054c6de     MOV        EAX,EBX
    //         0054c6e0     JNZ        LAB_0054c6e4
    //         0054c6e2     NEG        EAX
    //                               LAB_0054c6e4                                                 XREF[1]:     0054c6e0(j)  
    //         0054c6e4     POP        EDI
    //         0054c6e5     POP        ESI
    //         0054c6e6     POP        EBP
    //         0054c6e7     POP        EBX
    //         0054c6e8     RET
}

// Offset: 0x0054C6F0
undefined atoi() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * atoi                                                                                                  *
    //                              *********************************************************************************************************
    //                              undefined __cdecl atoi()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _atoi                                                        XREF[19]:    make_font:0041fb41(c), 
    //                               atoi                                                                      make_font:0041fbdf(c), 
    //                                                                                                         ReadPalette:004398fe(c), 
    //                                                                                                         ReadPalette:0043991d(c), 
    //                                                                                                         ReadPalette:0043993b(c), 
    //                                                                                                         asInt:00447403(c), 
    //                                                                                                         set_player:004aae5e(c), 
    //                                                                                                         set_player:004aaea2(c), 
    //                                                                                                         set_player:004aaee7(c), 
    //                                                                                                         set_player:004aaf2c(c), 
    //                                                                                                         action:004ac6f8(c), 
    //                                                                                                         save_multi_victory_cond_in_scenari
    //                                                                                                         save_multi_victory_cond_in_scenari
    //                                                                                                         save_multi_victory_cond_in_scenari
    //                                                                                                         save_multi_victory_cond_in_scenari
    //                                                                                                         save_multi_victory_cond_in_scenari
    //                                                                                                         save_victory_cond_in_scenario:004a
    //                                                                                                         GetTauntNo:0050961b(c), 
    //                                                                                                         randomComputerName:0052a0dd(c)  
    //         0054c6f0     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054c6f4     PUSH       EAX
    //         0054c6f5     CALL       atol                                             undefined atol()
    //         0054c6fa     ADD        ESP,0x4
    //         0054c6fd     RET
}

// Offset: 0x0054C700
undefined atoi64() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __atoi64()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __atoi64
    //         0054c700     PUSH       EBX
    //         0054c701     PUSH       EBP
    //         0054c702     PUSH       ESI
    //         0054c703     PUSH       EDI
    //         0054c704     MOV        EDI,dword ptr [ESP + Stack[0x4]]
    //                               LAB_0054c708                                                 XREF[1]:     0054c737(j)  
    //         0054c708     CMP        dword ptr [___mb_cur_max],0x1                    = 00000001h
    //         0054c70f     JLE        LAB_0054c722
    //         0054c711     XOR        EAX,EAX
    //         0054c713     PUSH       0x8
    //         0054c715     MOV        AL,byte ptr [EDI]
    //         0054c717     PUSH       EAX
    //         0054c718     CALL       __isctype                                        undefined __isctype()
    //         0054c71d     ADD        ESP,0x8
    //         0054c720     JMP        LAB_0054c732
    //                               LAB_0054c722                                                 XREF[1]:     0054c70f(j)  
    //         0054c722     MOV        EDX,dword ptr [__pctype]                         = 005920da
    //         0054c728     XOR        ECX,ECX
    //         0054c72a     MOV        CL,byte ptr [EDI]
    //         0054c72c     MOV        AL,byte ptr [EDX + ECX*0x2]=>DAT_005920da        = 20h     
    //         0054c72f     AND        EAX,0x8
    //                               LAB_0054c732                                                 XREF[1]:     0054c720(j)  
    //         0054c732     TEST       EAX,EAX
    //         0054c734     JZ         LAB_0054c739
    //         0054c736     INC        EDI
    //         0054c737     JMP        LAB_0054c708
    //                               LAB_0054c739                                                 XREF[1]:     0054c734(j)  
    //         0054c739     XOR        EAX,EAX
    //         0054c73b     MOV        AL,byte ptr [EDI]
    //         0054c73d     INC        EDI
    //         0054c73e     MOV        ESI,EAX
    //         0054c740     CMP        ESI,0x2d
    //         0054c743     MOV        dword ptr [ESP + Stack[0x4]],ESI
    //         0054c747     JZ         LAB_0054c74e
    //         0054c749     CMP        ESI,0x2b
    //         0054c74c     JNZ        LAB_0054c755
    //                               LAB_0054c74e                                                 XREF[1]:     0054c747(j)  
    //         0054c74e     XOR        ECX,ECX
    //         0054c750     MOV        CL,byte ptr [EDI]
    //         0054c752     INC        EDI
    //         0054c753     MOV        ESI,ECX
    //                               LAB_0054c755                                                 XREF[1]:     0054c74c(j)  
    //         0054c755     XOR        EBX,EBX
    //         0054c757     XOR        EBP,EBP
    //                               LAB_0054c759                                                 XREF[1]:     0054c79f(j)  
    //         0054c759     CMP        dword ptr [___mb_cur_max],0x1                    = 00000001h
    //         0054c760     JLE        LAB_0054c76f
    //         0054c762     PUSH       0x4
    //         0054c764     PUSH       ESI
    //         0054c765     CALL       __isctype                                        undefined __isctype()
    //         0054c76a     ADD        ESP,0x8
    //         0054c76d     JMP        LAB_0054c77b
    //                               LAB_0054c76f                                                 XREF[1]:     0054c760(j)  
    //         0054c76f     MOV        EDX,dword ptr [__pctype]                         = 005920da
    //         0054c775     MOV        AL,byte ptr [EDX + ESI*0x2]=>DAT_005920da        = 20h     
    //         0054c778     AND        EAX,0x4
    //                               LAB_0054c77b                                                 XREF[1]:     0054c76d(j)  
    //         0054c77b     TEST       EAX,EAX
    //         0054c77d     JZ         LAB_0054c7a1
    //         0054c77f     PUSH       0x0
    //         0054c781     PUSH       0xa
    //         0054c783     PUSH       EBP
    //         0054c784     PUSH       EBX
    //         0054c785     CALL       __allmul                                         undefined __allmul()
    //         0054c78a     MOV        ECX,EAX
    //         0054c78c     LEA        EAX,[ESI + -0x30]
    //         0054c78f     MOV        EBP,EDX
    //         0054c791     CDQ
    //         0054c792     ADD        ECX,EAX
    //         0054c794     ADC        EBP,EDX
    //         0054c796     XOR        EDX,EDX
    //         0054c798     MOV        DL,byte ptr [EDI]
    //         0054c79a     MOV        EBX,ECX
    //         0054c79c     MOV        ESI,EDX
    //         0054c79e     INC        EDI
    //         0054c79f     JMP        LAB_0054c759
    //                               LAB_0054c7a1                                                 XREF[1]:     0054c77d(j)  
    //         0054c7a1     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054c7a5     CMP        EAX,0x2d
    //         0054c7a8     MOV        EAX,EBX
    //         0054c7aa     JNZ        LAB_0054c7ba
    //         0054c7ac     NEG        EAX
    //         0054c7ae     MOV        EDX,EBP
    //         0054c7b0     ADC        EDX,0x0
    //         0054c7b3     NEG        EDX
    //         0054c7b5     POP        EDI
    //         0054c7b6     POP        ESI
    //         0054c7b7     POP        EBP
    //         0054c7b8     POP        EBX
    //         0054c7b9     RET
    //                               LAB_0054c7ba                                                 XREF[1]:     0054c7aa(j)  
    //         0054c7ba     POP        EDI
    //         0054c7bb     MOV        EDX,EBP
    //         0054c7bd     POP        ESI
    //         0054c7be     POP        EBP
    //         0054c7bf     POP        EBX
    //         0054c7c0     RET
}

// Offset: 0x0054C7D0
undefined mbsncat() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __mbsncat()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __mbsncat                                                    XREF[16]:    setup_cmd_options:0041d3a4(c), 
    //                                                                                                         setup_cmd_options:0041d442(c), 
    //                                                                                                         setup_cmd_options:0041dbb2(c), 
    //                                                                                                         setup_cmd_options:0041dc52(c), 
    //                                                                                                         setup_cmd_options:0041deb6(c), 
    //                                                                                                         setup_cmd_options:0041deeb(c), 
    //                                                                                                         setup_cmd_options:0041df58(c), 
    //                                                                                                         setup_cmd_options:0041dfef(c), 
    //                                                                                                         setup_cmd_options:0041e099(c), 
    //                                                                                                         setup_cmd_options:0041e137(c), 
    //                                                                                                         setup_cmd_options:0041e1d3(c), 
    //                                                                                                         setup_cmd_options:0041e267(c), 
    //                                                                                                         setup_cmd_options:0041e327(c), 
    //                                                                                                         setup_cmd_options:0041e568(c), 
    //                                                                                                         setup_cmd_options:0041e606(c), 
    //                                                                                                         setup:00521a14(c)  
    //         0054c7d0     PUSH       EBP
    //         0054c7d1     PUSH       ESI
    //         0054c7d2     PUSH       EDI
    //         0054c7d3     MOV        EDI,dword ptr [ESP + Stack[0xc]]
    //         0054c7d7     TEST       EDI,EDI
    //         0054c7d9     JNZ        LAB_0054c7e3
    //         0054c7db     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054c7df     POP        EDI
    //         0054c7e0     POP        ESI
    //         0054c7e1     POP        EBP
    //         0054c7e2     RET
    //                               LAB_0054c7e3                                                 XREF[1]:     0054c7d9(j)  
    //         0054c7e3     MOV        EAX,[___mbcodepage]
    //         0054c7e8     TEST       EAX,EAX
    //         0054c7ea     JNZ        LAB_0054c803
    //         0054c7ec     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         0054c7f0     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         0054c7f4     PUSH       EDI
    //         0054c7f5     PUSH       EAX
    //         0054c7f6     PUSH       ECX
    //         0054c7f7     CALL       strncat                                          undefined strncat()
    //         0054c7fc     ADD        ESP,0xc
    //         0054c7ff     POP        EDI
    //         0054c800     POP        ESI
    //         0054c801     POP        EBP
    //         0054c802     RET
    //                               LAB_0054c803                                                 XREF[1]:     0054c7ea(j)  
    //         0054c803     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         0054c807     MOV        EAX,ESI
    //         0054c809     MOV        DL,byte ptr [ESI]
    //         0054c80b     INC        ESI
    //         0054c80c     TEST       DL,DL
    //         0054c80e     MOV        dword ptr [ESP + Stack[0x4]],EAX
    //         0054c812     JZ         LAB_0054c81b
    //                               LAB_0054c814                                                 XREF[1]:     0054c819(j)  
    //         0054c814     MOV        CL,byte ptr [ESI]
    //         0054c816     INC        ESI
    //         0054c817     TEST       CL,CL
    //         0054c819     JNZ        LAB_0054c814
    //                               LAB_0054c81b                                                 XREF[1]:     0054c812(j)  
    //         0054c81b     DEC        ESI
    //         0054c81c     PUSH       ESI
    //         0054c81d     PUSH       EAX
    //         0054c81e     CALL       __ismbslead                                      undefined __ismbslead()
    //         0054c823     ADD        ESP,0x8
    //         0054c826     TEST       EAX,EAX
    //         0054c828     JZ         LAB_0054c82b
    //         0054c82a     DEC        ESI
    //                               LAB_0054c82b                                                 XREF[1]:     0054c828(j)  
    //         0054c82b     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         0054c82f     DEC        EDI
    //         0054c830     MOV        DL,0x4
    //                               LAB_0054c832                                                 XREF[1]:     0054c860(j)  
    //         0054c832     MOV        CL,byte ptr [EAX]
    //         0054c834     MOV        EBP,ECX
    //         0054c836     AND        EBP,0xff
    //         0054c83c     TEST       byte ptr [EBP + __mbctype+1],DL
    //         0054c842     MOV        byte ptr [ESI],CL
    //         0054c844     JZ         LAB_0054c855
    //         0054c846     MOV        CL,byte ptr [EAX + 0x1]
    //         0054c849     INC        ESI
    //         0054c84a     INC        EAX
    //         0054c84b     MOV        byte ptr [ESI],CL
    //         0054c84d     INC        ESI
    //         0054c84e     INC        EAX
    //         0054c84f     TEST       CL,CL
    //         0054c851     JZ         LAB_0054c864
    //         0054c853     JMP        LAB_0054c85b
    //                               LAB_0054c855                                                 XREF[1]:     0054c844(j)  
    //         0054c855     INC        ESI
    //         0054c856     INC        EAX
    //         0054c857     TEST       CL,CL
    //         0054c859     JZ         LAB_0054c868
    //                               LAB_0054c85b                                                 XREF[1]:     0054c853(j)  
    //         0054c85b     MOV        ECX,EDI
    //         0054c85d     DEC        EDI
    //         0054c85e     TEST       ECX,ECX
    //         0054c860     JNZ        LAB_0054c832
    //         0054c862     JMP        LAB_0054c868
    //                               LAB_0054c864                                                 XREF[1]:     0054c851(j)  
    //         0054c864     MOV        byte ptr [ESI + -0x2],0x0
    //                               LAB_0054c868                                                 XREF[2]:     0054c859(j), 0054c862(j)  
    //         0054c868     MOV        EDI,dword ptr [ESP + Stack[0x4]]
    //         0054c86c     MOV        EDX,ESI
    //         0054c86e     SUB        EDX,EDI
    //         0054c870     DEC        EDX
    //         0054c871     PUSH       EDX
    //         0054c872     PUSH       EDI
    //         0054c873     CALL       __mbsbtype                                       undefined __mbsbtype()
    //         0054c878     ADD        ESP,0x8
    //         0054c87b     CMP        EAX,0x1
    //         0054c87e     JNZ        LAB_0054c88a
    //         0054c880     MOV        byte ptr [ESI + -0x1],0x0
    //         0054c884     MOV        EAX,EDI
    //         0054c886     POP        EDI
    //         0054c887     POP        ESI
    //         0054c888     POP        EBP
    //         0054c889     RET
    //                               LAB_0054c88a                                                 XREF[1]:     0054c87e(j)  
    //         0054c88a     MOV        EAX,EDI
    //         0054c88c     MOV        byte ptr [ESI],0x0
    //         0054c88f     POP        EDI
    //         0054c890     POP        ESI
    //         0054c891     POP        EBP
    //         0054c892     RET
}

// Offset: 0x0054C8A0
undefined ismbcspace() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __ismbcspace()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined2        Stack[-0x2]:2  local_2                   XREF[2]:     0054c8c3(W), 0054c8f6(R)  
    //              undefined2        Stack[-0x4]:2  local_4                   XREF[3]:     0054c8b7(*), 0054c8de(*), 0054c8fe(*)  
    //                               __ismbcspace                                                 XREF[40]:    setup_cmd_options:0041d389(c), 
    //                                                                                                         setup_cmd_options:0041d3bd(c), 
    //                                                                                                         setup_cmd_options:0041d427(c), 
    //                                                                                                         setup_cmd_options:0041d45b(c), 
    //                                                                                                         setup_cmd_options:0041db97(c), 
    //                                                                                                         setup_cmd_options:0041dbcb(c), 
    //                                                                                                         setup_cmd_options:0041dc37(c), 
    //                                                                                                         setup_cmd_options:0041dc6b(c), 
    //                                                                                                         setup_cmd_options:0041de9a(c), 
    //                                                                                                         setup_cmd_options:0041decf(c), 
    //                                                                                                         setup_cmd_options:0041df3c(c), 
    //                                                                                                         setup_cmd_options:0041df71(c), 
    //                                                                                                         setup_cmd_options:0041dfd4(c), 
    //                                                                                                         is_blank:00476a83(c), 
    //                                                                                                         get_trimmed_str:00476b22(c), 
    //                                                                                                         get_trimmed_str:00476b3e(c), 
    //                                                                                                         get_trimmed_str:00476b8e(c), 
    //                                                                                                         word_wrap_append:0047c8a6(c), 
    //                                                                                                         word_wrap_append:0047c8f3(c), 
    //                                                                                                         setup:005219fc(c), [more]
    //         0054c8a0     PUSH       ECX
    //         0054c8a1     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054c8a5     CMP        EAX,0xff
    //         0054c8aa     JBE        LAB_0054c910
    //         0054c8ac     MOV        ECX,EAX
    //         0054c8ae     MOV        byte ptr [ESP + Stack[0x5]],AL
    //         0054c8b2     MOV        EAX,[___mbcodepage]
    //         0054c8b7     MOV        word ptr [ESP]=>local_4,0x0
    //         0054c8be     SHR        ECX,0x8
    //         0054c8c1     TEST       EAX,EAX
    //         0054c8c3     MOV        word ptr [ESP + local_2],0x0
    //         0054c8ca     MOV        byte ptr [ESP + Stack[0x4]],CL
    //         0054c8ce     JNZ        LAB_0054c8d2
    //         0054c8d0     POP        ECX
    //         0054c8d1     RET
    //                               LAB_0054c8d2                                                 XREF[1]:     0054c8ce(j)  
    //         0054c8d2     MOV        EDX,dword ptr [___mblcid]
    //         0054c8d8     LEA        ECX=>Stack[0x4],[ESP + 0x8]
    //         0054c8dc     PUSH       EDX
    //         0054c8dd     PUSH       EAX
    //         0054c8de     LEA        EAX=>local_4,[ESP + 0x8]
    //         0054c8e2     PUSH       EAX
    //         0054c8e3     PUSH       0x2
    //         0054c8e5     PUSH       ECX
    //         0054c8e6     PUSH       0x1
    //         0054c8e8     CALL       ___crtGetStringTypeA                             undefined ___crtGetStringTypeA()
    //         0054c8ed     ADD        ESP,0x18
    //         0054c8f0     TEST       EAX,EAX
    //         0054c8f2     JNZ        LAB_0054c8f6
    //         0054c8f4     POP        ECX
    //         0054c8f5     RET
    //                               LAB_0054c8f6                                                 XREF[1]:     0054c8f2(j)  
    //         0054c8f6     CMP        word ptr [ESP + local_2],0x0
    //         0054c8fc     JNZ        LAB_0054c90c
    //         0054c8fe     TEST       byte ptr [ESP]=>local_4,0x8
    //         0054c903     JZ         LAB_0054c90c
    //         0054c905     MOV        EAX,0x1
    //         0054c90a     POP        ECX
    //         0054c90b     RET
    //                               LAB_0054c90c                                                 XREF[2]:     0054c8fc(j), 0054c903(j)  
    //         0054c90c     XOR        EAX,EAX
    //         0054c90e     POP        ECX
    //         0054c90f     RET
    //                               LAB_0054c910                                                 XREF[1]:     0054c8aa(j)  
    //         0054c910     CMP        dword ptr [___mb_cur_max],0x1                    = 00000001h
    //         0054c917     JLE        LAB_0054c926
    //         0054c919     PUSH       0x8
    //         0054c91b     PUSH       EAX
    //         0054c91c     CALL       __isctype                                        undefined __isctype()
    //         0054c921     ADD        ESP,0x8
    //         0054c924     POP        ECX
    //         0054c925     RET
    //                               LAB_0054c926                                                 XREF[1]:     0054c917(j)  
    //         0054c926     MOV        EDX,dword ptr [__pctype]                         = 005920da
    //         0054c92c     MOV        AL,byte ptr [EDX + EAX*0x2]=>DAT_005920da        = 20h     
    //         0054c92f     AND        EAX,0x8
    //         0054c932     POP        ECX
    //         0054c933     RET
}

// Offset: 0x0054C940
undefined mbsninc() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __mbsninc()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __mbsninc                                                    XREF[55]:    setup_cmd_options:0041d361(c), 
    //                                                                                                         setup_cmd_options:0041d372(c), 
    //                                                                                                         setup_cmd_options:0041d3ae(c), 
    //                                                                                                         setup_cmd_options:0041d3ff(c), 
    //                                                                                                         setup_cmd_options:0041d410(c), 
    //                                                                                                         setup_cmd_options:0041d44c(c), 
    //                                                                                                         setup_cmd_options:0041db6f(c), 
    //                                                                                                         setup_cmd_options:0041db80(c), 
    //                                                                                                         insert_character:00477a54(c), 
    //                                                                                                         insert_character:00477a67(c), 
    //                                                                                                         delete_character:00477b6a(c), 
    //                                                                                                         delete_character:00477b7d(c), 
    //                                                                                                         delete_character:00477be3(c), 
    //                                                                                                         delete_character:00477bfd(c), 
    //                                                                                                         paste:00477de8(c), 
    //                                                                                                         paste:00477dfb(c), 
    //                                                                                                         paste:00477e16(c), 
    //                                                                                                         word_wrap_append:0047c9fa(c), 
    //                                                                                                         setup:005219d7(c), 
    //                                                                                                         setup:005219e8(c), [more]
    //         0054c940     PUSH       ESI
    //         0054c941     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         0054c945     TEST       ESI,ESI
    //         0054c947     JNZ        LAB_0054c94d
    //         0054c949     XOR        EAX,EAX
    //         0054c94b     POP        ESI
    //         0054c94c     RET
    //                               LAB_0054c94d                                                 XREF[1]:     0054c947(j)  
    //         0054c94d     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         0054c951     PUSH       EAX
    //         0054c952     PUSH       ESI
    //         0054c953     CALL       __mbsnbcnt                                       undefined __mbsnbcnt()
    //         0054c958     ADD        ESP,0x8
    //         0054c95b     ADD        EAX,ESI
    //         0054c95d     POP        ESI
    //         0054c95e     RET
}

// Offset: 0x0054C960
undefined mbsstr() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __mbsstr()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __mbsstr                                                     XREF[15]:    setup_cmd_options:0041d34a(c), 
    //                                                                                                         setup_cmd_options:0041d3e8(c), 
    //                                                                                                         setup_cmd_options:0041db58(c), 
    //                                                                                                         setup_cmd_options:0041dbf8(c), 
    //                                                                                                         setup_cmd_options:0041de59(c), 
    //                                                                                                         setup_cmd_options:0041deff(c), 
    //                                                                                                         setup_cmd_options:0041df87(c), 
    //                                                                                                         setup_cmd_options:0041e033(c), 
    //                                                                                                         setup_cmd_options:0041e0dd(c), 
    //                                                                                                         setup_cmd_options:0041e179(c), 
    //                                                                                                         setup_cmd_options:0041e215(c), 
    //                                                                                                         setup_cmd_options:0041e2ce(c), 
    //                                                                                                         setup_cmd_options:0041e50e(c), 
    //                                                                                                         setup_cmd_options:0041e5ac(c), 
    //                                                                                                         setup:0052198b(c)  
    //         0054c960     MOV        EAX,[___mbcodepage]
    //         0054c965     PUSH       EBX
    //         0054c966     PUSH       EBP
    //         0054c967     PUSH       ESI
    //         0054c968     TEST       EAX,EAX
    //         0054c96a     PUSH       EDI
    //         0054c96b     JNZ        LAB_0054c984
    //         0054c96d     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         0054c971     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         0054c975     PUSH       EAX
    //         0054c976     PUSH       ECX
    //         0054c977     CALL       strstr                                           undefined strstr()
    //         0054c97c     ADD        ESP,0x8
    //         0054c97f     POP        EDI
    //         0054c980     POP        ESI
    //         0054c981     POP        EBP
    //         0054c982     POP        EBX
    //         0054c983     RET
    //                               LAB_0054c984                                                 XREF[1]:     0054c96b(j)  
    //         0054c984     MOV        EBX,dword ptr [ESP + Stack[0x8]]
    //         0054c988     OR         ECX,0xffffffff
    //         0054c98b     MOV        EDI,EBX
    //         0054c98d     XOR        EAX,EAX
    //         0054c98f     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         0054c993     SCASB.RE   ES:EDI
    //         0054c995     NOT        ECX
    //         0054c997     DEC        ECX
    //         0054c998     MOV        EBP,ESI
    //         0054c99a     SUB        EBP,ECX
    //         0054c99c     MOV        EDI,ESI
    //         0054c99e     OR         ECX,0xffffffff
    //         0054c9a1     SCASB.RE   ES:EDI
    //         0054c9a3     MOV        AL,byte ptr [ESI]
    //         0054c9a5     NOT        ECX
    //         0054c9a7     DEC        ECX
    //         0054c9a8     ADD        EBP,ECX
    //         0054c9aa     TEST       AL,AL
    //         0054c9ac     JZ         LAB_0054c9f5
    //                               LAB_0054c9ae                                                 XREF[1]:     0054c9e5(j)  
    //         0054c9ae     CMP        ESI,EBP
    //         0054c9b0     JA         LAB_0054c9f5
    //         0054c9b2     MOV        CL,byte ptr [ESI]
    //         0054c9b4     MOV        EAX,EBX
    //         0054c9b6     TEST       CL,CL
    //         0054c9b8     JZ         LAB_0054c9d2
    //         0054c9ba     MOV        EDX,ESI
    //         0054c9bc     SUB        EDX,EBX
    //                               LAB_0054c9be                                                 XREF[1]:     0054c9d0(j)  
    //         0054c9be     MOV        CL,byte ptr [EAX]
    //         0054c9c0     TEST       CL,CL
    //         0054c9c2     JZ         LAB_0054c9d2
    //         0054c9c4     CMP        byte ptr [EAX + EDX*0x1],CL
    //         0054c9c7     JNZ        LAB_0054c9d2
    //         0054c9c9     MOV        CL,byte ptr [EAX + EDX*0x1 + 0x1]
    //         0054c9cd     INC        EAX
    //         0054c9ce     TEST       CL,CL
    //         0054c9d0     JNZ        LAB_0054c9be
    //                               LAB_0054c9d2                                                 XREF[3]:     0054c9b8(j), 0054c9c2(j), 
    //                                                                                                         0054c9c7(j)  
    //         0054c9d2     CMP        byte ptr [EAX],0x0
    //         0054c9d5     JZ         LAB_0054c9ee
    //         0054c9d7     PUSH       ESI
    //         0054c9d8     CALL       __mbsinc                                         undefined __mbsinc()
    //         0054c9dd     MOV        ESI,EAX
    //         0054c9df     ADD        ESP,0x4
    //         0054c9e2     CMP        byte ptr [ESI],0x0
    //         0054c9e5     JNZ        LAB_0054c9ae
    //         0054c9e7     XOR        EAX,EAX
    //         0054c9e9     POP        EDI
    //         0054c9ea     POP        ESI
    //         0054c9eb     POP        EBP
    //         0054c9ec     POP        EBX
    //         0054c9ed     RET
    //                               LAB_0054c9ee                                                 XREF[1]:     0054c9d5(j)  
    //         0054c9ee     MOV        EAX,ESI
    //         0054c9f0     POP        EDI
    //         0054c9f1     POP        ESI
    //         0054c9f2     POP        EBP
    //         0054c9f3     POP        EBX
    //         0054c9f4     RET
    //                               LAB_0054c9f5                                                 XREF[2]:     0054c9ac(j), 0054c9b0(j)  
    //         0054c9f5     POP        EDI
    //         0054c9f6     POP        ESI
    //         0054c9f7     POP        EBP
    //         0054c9f8     XOR        EAX,EAX
    //         0054c9fa     POP        EBX
    //         0054c9fb     RET
}

// Offset: 0x0054CA00
undefined mktime() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * mktime                                                                                                *
    //                              *********************************************************************************************************
    //                              undefined __cdecl mktime()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _mktime                                                      XREF[1]:     check_expiration:0041fe1e(c)  
    //                               mktime
    //         0054ca00     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054ca04     PUSH       0x1
    //         0054ca06     PUSH       EAX
    //         0054ca07     CALL       FUN_0054ca20                                     undefined FUN_0054ca20()
    //         0054ca0c     ADD        ESP,0x8
    //         0054ca0f     RET
}

// Offset: 0x0054CA10
undefined mkgmtime() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __mkgmtime()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __mkgmtime
    //         0054ca10     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054ca14     PUSH       0x0
    //         0054ca16     PUSH       EAX
    //         0054ca17     CALL       FUN_0054ca20                                     undefined FUN_0054ca20()
    //         0054ca1c     ADD        ESP,0x8
    //         0054ca1f     RET
}

// Offset: 0x0054CA20
undefined FUN_0054ca20() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054ca20()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054ca20                                                 XREF[2]:     mktime:0054ca07(c), 
    //                                                                                                         __mkgmtime:0054ca17(c)  
    //         0054ca20     PUSH       EBX
    //         0054ca21     PUSH       ESI
    //         0054ca22     PUSH       EDI
    //         0054ca23     MOV        EDI,dword ptr [ESP + Stack[0x4]]
    //         0054ca27     MOV        ECX,dword ptr [EDI + 0x14]
    //         0054ca2a     CMP        ECX,0x45
    //         0054ca2d     JL         LAB_0054cc55
    //         0054ca33     CMP        ECX,0x8b
    //         0054ca39     JG         LAB_0054cc55
    //         0054ca3f     MOV        ESI,dword ptr [EDI + 0x10]
    //         0054ca42     TEST       ESI,ESI
    //         0054ca44     JL         LAB_0054ca4b
    //         0054ca46     CMP        ESI,0xb
    //         0054ca49     JLE        LAB_0054ca89
    //                               LAB_0054ca4b                                                 XREF[1]:     0054ca44(j)  
    //         0054ca4b     MOV        EAX,0x2aaaaaab
    //         0054ca50     IMUL       ESI
    //         0054ca52     SAR        EDX,0x1
    //         0054ca54     MOV        EAX,EDX
    //         0054ca56     SHR        EAX,0x1f
    //         0054ca59     ADD        EDX,EAX
    //         0054ca5b     MOV        EAX,ESI
    //         0054ca5d     ADD        ECX,EDX
    //         0054ca5f     MOV        ESI,0xc
    //         0054ca64     CDQ
    //         0054ca65     IDIV       ESI
    //         0054ca67     TEST       EDX,EDX
    //         0054ca69     MOV        dword ptr [EDI + 0x10],EDX
    //         0054ca6c     JGE        LAB_0054ca74
    //         0054ca6e     ADD        EDX,ESI
    //         0054ca70     DEC        ECX
    //         0054ca71     MOV        dword ptr [EDI + 0x10],EDX
    //                               LAB_0054ca74                                                 XREF[1]:     0054ca6c(j)  
    //         0054ca74     CMP        ECX,0x45
    //         0054ca77     JL         LAB_0054cc55
    //         0054ca7d     CMP        ECX,0x8b
    //         0054ca83     JG         LAB_0054cc55
    //                               LAB_0054ca89                                                 XREF[1]:     0054ca49(j)  
    //         0054ca89     MOV        EDX,dword ptr [EDI + 0x10]
    //         0054ca8c     TEST       CL,0x3
    //         0054ca8f     MOV        EAX,dword ptr [EDX*0x4 + __days]                 = FFFFFFFFh
    //         0054ca96     JNZ        LAB_0054ca9e
    //         0054ca98     CMP        EDX,0x1
    //         0054ca9b     JLE        LAB_0054ca9e
    //         0054ca9d     INC        EAX
    //                               LAB_0054ca9e                                                 XREF[2]:     0054ca96(j), 0054ca9b(j)  
    //         0054ca9e     LEA        ESI,[ECX + ECX*0x8]
    //         0054caa1     LEA        EDX,[ECX + -0x1]
    //         0054caa4     SAR        EDX,0x2
    //         0054caa7     LEA        ECX,[ECX + ESI*0x8]
    //         0054caaa     ADD        EAX,EDX
    //         0054caac     MOV        EDX,dword ptr [EDI + 0xc]
    //         0054caaf     LEA        ECX,[ECX + ECX*0x4]
    //         0054cab2     LEA        EAX,[ECX + EAX*0x1 + 0xffff9c21]
    //         0054cab9     TEST       EAX,EAX
    //         0054cabb     LEA        ECX,[EAX + EDX*0x1]
    //         0054cabe     JL         LAB_0054cad0
    //         0054cac0     TEST       EDX,EDX
    //         0054cac2     JL         LAB_0054cacc
    //         0054cac4     TEST       ECX,ECX
    //         0054cac6     JL         LAB_0054cc55
    //                               LAB_0054cacc                                                 XREF[1]:     0054cac2(j)  
    //         0054cacc     TEST       EAX,EAX
    //         0054cace     JGE        LAB_0054cadc
    //                               LAB_0054cad0                                                 XREF[1]:     0054cabe(j)  
    //         0054cad0     TEST       EDX,EDX
    //         0054cad2     JGE        LAB_0054cadc
    //         0054cad4     TEST       ECX,ECX
    //         0054cad6     JGE        LAB_0054cc55
    //                               LAB_0054cadc                                                 XREF[2]:     0054cace(j), 0054cad2(j)  
    //         0054cadc     LEA        EBX,[ECX + ECX*0x2]
    //         0054cadf     SHL        EBX,0x3
    //         0054cae2     TEST       ECX,ECX
    //         0054cae4     JZ         LAB_0054caf7
    //         0054cae6     MOV        EAX,EBX
    //         0054cae8     CDQ
    //         0054cae9     IDIV       ECX
    //         0054caeb     XOR        EDX,EDX
    //         0054caed     CMP        EAX,0x18
    //         0054caf0     SETNZ      DL
    //         0054caf3     MOV        EAX,EDX
    //         0054caf5     JMP        LAB_0054caf9
    //                               LAB_0054caf7                                                 XREF[1]:     0054cae4(j)  
    //         0054caf7     XOR        EAX,EAX
    //                               LAB_0054caf9                                                 XREF[1]:     0054caf5(j)  
    //         0054caf9     TEST       EAX,EAX
    //         0054cafb     JNZ        LAB_0054cc55
    //         0054cb01     MOV        EAX,dword ptr [EDI + 0x8]
    //         0054cb04     TEST       EBX,EBX
    //         0054cb06     LEA        ESI,[EAX + EBX*0x1]
    //         0054cb09     JL         LAB_0054cb1b
    //         0054cb0b     TEST       EAX,EAX
    //         0054cb0d     JL         LAB_0054cb17
    //         0054cb0f     TEST       ESI,ESI
    //         0054cb11     JL         LAB_0054cc55
    //                               LAB_0054cb17                                                 XREF[1]:     0054cb0d(j)  
    //         0054cb17     TEST       EBX,EBX
    //         0054cb19     JGE        LAB_0054cb27
    //                               LAB_0054cb1b                                                 XREF[1]:     0054cb09(j)  
    //         0054cb1b     TEST       EAX,EAX
    //         0054cb1d     JGE        LAB_0054cb27
    //         0054cb1f     TEST       ESI,ESI
    //         0054cb21     JGE        LAB_0054cc55
    //                               LAB_0054cb27                                                 XREF[2]:     0054cb19(j), 0054cb1d(j)  
    //         0054cb27     MOV        ECX,ESI
    //         0054cb29     SHL        ECX,0x4
    //         0054cb2c     SUB        ECX,ESI
    //         0054cb2e     SHL        ECX,0x2
    //         0054cb31     TEST       ESI,ESI
    //         0054cb33     JZ         LAB_0054cb46
    //         0054cb35     MOV        EAX,ECX
    //         0054cb37     CDQ
    //         0054cb38     IDIV       ESI
    //         0054cb3a     XOR        EDX,EDX
    //         0054cb3c     CMP        EAX,0x3c
    //         0054cb3f     SETNZ      DL
    //         0054cb42     MOV        EAX,EDX
    //         0054cb44     JMP        LAB_0054cb48
    //                               LAB_0054cb46                                                 XREF[1]:     0054cb33(j)  
    //         0054cb46     XOR        EAX,EAX
    //                               LAB_0054cb48                                                 XREF[1]:     0054cb44(j)  
    //         0054cb48     TEST       EAX,EAX
    //         0054cb4a     JNZ        LAB_0054cc55
    //         0054cb50     MOV        EAX,dword ptr [EDI + 0x4]
    //         0054cb53     TEST       ECX,ECX
    //         0054cb55     LEA        ESI,[EAX + ECX*0x1]
    //         0054cb58     JL         LAB_0054cb6a
    //         0054cb5a     TEST       EAX,EAX
    //         0054cb5c     JL         LAB_0054cb66
    //         0054cb5e     TEST       ESI,ESI
    //         0054cb60     JL         LAB_0054cc55
    //                               LAB_0054cb66                                                 XREF[1]:     0054cb5c(j)  
    //         0054cb66     TEST       ECX,ECX
    //         0054cb68     JGE        LAB_0054cb76
    //                               LAB_0054cb6a                                                 XREF[1]:     0054cb58(j)  
    //         0054cb6a     TEST       EAX,EAX
    //         0054cb6c     JGE        LAB_0054cb76
    //         0054cb6e     TEST       ESI,ESI
    //         0054cb70     JGE        LAB_0054cc55
    //                               LAB_0054cb76                                                 XREF[2]:     0054cb68(j), 0054cb6c(j)  
    //         0054cb76     MOV        ECX,ESI
    //         0054cb78     SHL        ECX,0x4
    //         0054cb7b     SUB        ECX,ESI
    //         0054cb7d     SHL        ECX,0x2
    //         0054cb80     TEST       ESI,ESI
    //         0054cb82     JZ         LAB_0054cb95
    //         0054cb84     MOV        EAX,ECX
    //         0054cb86     CDQ
    //         0054cb87     IDIV       ESI
    //         0054cb89     XOR        EDX,EDX
    //         0054cb8b     CMP        EAX,0x3c
    //         0054cb8e     SETNZ      DL
    //         0054cb91     MOV        EAX,EDX
    //         0054cb93     JMP        LAB_0054cb97
    //                               LAB_0054cb95                                                 XREF[1]:     0054cb82(j)  
    //         0054cb95     XOR        EAX,EAX
    //                               LAB_0054cb97                                                 XREF[1]:     0054cb93(j)  
    //         0054cb97     TEST       EAX,EAX
    //         0054cb99     JNZ        LAB_0054cc55
    //         0054cb9f     MOV        EAX,dword ptr [EDI]
    //         0054cba1     TEST       ECX,ECX
    //         0054cba3     LEA        EDX,[EAX + ECX*0x1]
    //         0054cba6     MOV        dword ptr [ESP + Stack[0x4]],EDX
    //         0054cbaa     JL         LAB_0054cbbc
    //         0054cbac     TEST       EAX,EAX
    //         0054cbae     JL         LAB_0054cbb8
    //         0054cbb0     TEST       EDX,EDX
    //         0054cbb2     JL         LAB_0054cc55
    //                               LAB_0054cbb8                                                 XREF[1]:     0054cbae(j)  
    //         0054cbb8     TEST       ECX,ECX
    //         0054cbba     JGE        LAB_0054cbc8
    //                               LAB_0054cbbc                                                 XREF[1]:     0054cbaa(j)  
    //         0054cbbc     TEST       EAX,EAX
    //         0054cbbe     JGE        LAB_0054cbc8
    //         0054cbc0     TEST       EDX,EDX
    //         0054cbc2     JGE        LAB_0054cc55
    //                               LAB_0054cbc8                                                 XREF[2]:     0054cbba(j), 0054cbbe(j)  
    //         0054cbc8     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         0054cbcc     TEST       EAX,EAX
    //         0054cbce     JZ         LAB_0054cc33
    //         0054cbd0     CALL       ___tzset                                         undefined ___tzset()
    //         0054cbd5     MOV        EAX,[__timezone]                                 = 00007080h
    //         0054cbda     MOV        EBX,dword ptr [ESP + Stack[0x4]]
    //         0054cbde     LEA        ECX=>Stack[0x4],[ESP + 0x10]
    //         0054cbe2     ADD        EBX,EAX
    //         0054cbe4     PUSH       ECX
    //         0054cbe5     MOV        dword ptr [ESP + Stack[0x4]],EBX
    //         0054cbe9     CALL       localtime                                        undefined localtime()
    //         0054cbee     ADD        ESP,0x4
    //         0054cbf1     TEST       EAX,EAX
    //         0054cbf3     JZ         LAB_0054cc55
    //         0054cbf5     MOV        ECX,dword ptr [EDI + 0x20]
    //         0054cbf8     TEST       ECX,ECX
    //         0054cbfa     JG         LAB_0054cc05
    //         0054cbfc     JGE        LAB_0054cc44
    //         0054cbfe     MOV        ECX,dword ptr [EAX + 0x20]
    //         0054cc01     TEST       ECX,ECX
    //         0054cc03     JLE        LAB_0054cc44
    //                               LAB_0054cc05                                                 XREF[1]:     0054cbfa(j)  
    //         0054cc05     MOV        EDX,dword ptr [__dstbias]                        = FFFFF1F0h
    //         0054cc0b     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         0054cc0f     LEA        EAX=>Stack[0x4],[ESP + 0x10]
    //         0054cc13     ADD        ESI,EDX
    //         0054cc15     PUSH       EAX
    //         0054cc16     MOV        dword ptr [ESP + Stack[0x4]],ESI
    //         0054cc1a     CALL       localtime                                        undefined localtime()
    //         0054cc1f     MOV        ECX,0x9
    //         0054cc24     MOV        ESI,EAX
    //         0054cc26     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054cc2a     ADD        ESP,0x4
    //         0054cc2d     MOVSD.REP  ES:EDI,ESI
    //         0054cc2f     POP        EDI
    //         0054cc30     POP        ESI
    //         0054cc31     POP        EBX
    //         0054cc32     RET
    //                               LAB_0054cc33                                                 XREF[1]:     0054cbce(j)  
    //         0054cc33     LEA        ECX=>Stack[0x4],[ESP + 0x10]
    //         0054cc37     PUSH       ECX
    //         0054cc38     CALL       gmtime                                           undefined gmtime()
    //         0054cc3d     ADD        ESP,0x4
    //         0054cc40     TEST       EAX,EAX
    //         0054cc42     JZ         LAB_0054cc55
    //                               LAB_0054cc44                                                 XREF[2]:     0054cbfc(j), 0054cc03(j)  
    //         0054cc44     MOV        ECX,0x9
    //         0054cc49     MOV        ESI,EAX
    //         0054cc4b     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054cc4f     MOVSD.REP  ES:EDI,ESI
    //         0054cc51     POP        EDI
    //         0054cc52     POP        ESI
    //         0054cc53     POP        EBX
    //         0054cc54     RET
    //                               LAB_0054cc55                                                 XREF[17]:    0054ca2d(j), 0054ca39(j), 
    //                                                                                                         0054ca77(j), 0054ca83(j), 
    //                                                                                                         0054cac6(j), 0054cad6(j), 
    //                                                                                                         0054cafb(j), 0054cb11(j), 
    //                                                                                                         0054cb21(j), 0054cb4a(j), 
    //                                                                                                         0054cb60(j), 0054cb70(j), 
    //                                                                                                         0054cb99(j), 0054cbb2(j), 
    //                                                                                                         0054cbc2(j), 0054cbf3(j), 
    //                                                                                                         0054cc42(j)  
    //         0054cc55     POP        EDI
    //         0054cc56     POP        ESI
    //         0054cc57     OR         EAX,0xffffffff
    //         0054cc5a     POP        EBX
    //         0054cc5b     RET
}

// Offset: 0x0054CC60
undefined srand() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * srand                                                                                                 *
    //                              *********************************************************************************************************
    //                              undefined __cdecl srand()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _srand                                                       XREF[1]:     debug_srand:004231d1(c)  
    //                               srand
    //         0054cc60     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054cc64     MOV        [DAT_0058fb80],EAX                               = 00000001h
    //         0054cc69     RET
}

// Offset: 0x0054CC70
undefined rand() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * rand                                                                                                  *
    //                              *********************************************************************************************************
    //                              undefined __cdecl rand()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _rand                                                        XREF[1]:     debug_rand:004230a4(c)  
    //                               rand
    //         0054cc70     MOV        EAX,[DAT_0058fb80]                               = 00000001h
    //         0054cc75     LEA        ECX,[EAX + EAX*0x2]
    //         0054cc78     LEA        EDX,[EAX + ECX*0x4]
    //         0054cc7b     SHL        EDX,0x4
    //         0054cc7e     ADD        EDX,EAX
    //         0054cc80     SHL        EDX,0x8
    //         0054cc83     SUB        EDX,EAX
    //         0054cc85     LEA        EAX,[EAX + EDX*0x4 + 0x269ec3]
    //         0054cc8c     MOV        [DAT_0058fb80],EAX                               = 00000001h
    //         0054cc91     SAR        EAX,0x10
    //         0054cc94     AND        EAX,0x7fff
    //         0054cc99     RET
}

// Offset: 0x0054CCA0
undefined close() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * close                                                                                                 *
    //                              *********************************************************************************************************
    //                              undefined __cdecl close()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __close                                                      XREF[36]:    RGE_Campaign:004232ba(c), 
    //                               _close                                                                    RGE_Campaign:004232d4(c), 
    //                               close                                                                     ReadPalette:004397de(c), 
    //                                                                                                         play:00462396(c), 
    //                                                                                                         setup:00466c88(c), 
    //                                                                                                         RESFILE_build_res_file:0047f88e(c)
    //                                                                                                         RESFILE_build_res_file:0047fbe2(c)
    //                                                                                                         rge_close:0047ffe6(c), 
    //                                                                                                         Get_BuildList:0048bdb5(c), 
    //                                                                                                         Get_CityPlan:0048bfb5(c), 
    //                                                                                                         Get_player_AI:0048c1d5(c), 
    //                                                                                                         TShape:004b8c5a(c), 
    //                                                                                                         TShape:004b8d09(c), 
    //                                                                                                         load:004bce47(c), 
    //                                                                                                         load:004bce98(c), 
    //                                                                                                         load:004bcecb(c), 
    //                                                                                                         load:004bced9(c), 
    //                                                                                                         load:004bd091(c), 
    //                                                                                                         Init_Tile_Edge_Tables:00533b5e(c), 
    //                                                                                                         Init_Tile_Edge_Tables:00533c1d(c), 
    //                                                                                                         [more]
    //         0054cca0     MOV        EAX,[__nhandle]
    //         0054cca5     PUSH       EBX
    //         0054cca6     PUSH       EBP
    //         0054cca7     PUSH       ESI
    //         0054cca8     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         0054ccac     PUSH       EDI
    //         0054ccad     CMP        ESI,EAX
    //         0054ccaf     JNC        LAB_0054cd56
    //         0054ccb5     MOV        EAX,ESI
    //         0054ccb7     MOV        EDI,ESI
    //         0054ccb9     SAR        EAX,0x5
    //         0054ccbc     AND        EDI,0x1f
    //         0054ccbf     MOV        ECX,dword ptr [EAX*0x4 + ___pioinfo]
    //         0054ccc6     LEA        EBP,[EAX*0x4 + ___pioinfo]
    //         0054cccd     SHL        EDI,0x3
    //         0054ccd0     TEST       byte ptr [ECX + EDI*0x1 + 0x4],0x1
    //         0054ccd5     JZ         LAB_0054cd56
    //         0054ccd7     PUSH       ESI
    //         0054ccd8     CALL       __get_osfhandle                                  undefined __get_osfhandle()
    //         0054ccdd     ADD        ESP,0x4
    //         0054cce0     CMP        EAX,-0x1
    //         0054cce3     JZ         LAB_0054cd27
    //         0054cce5     CMP        ESI,0x1
    //         0054cce8     JZ         LAB_0054ccef
    //         0054ccea     CMP        ESI,0x2
    //         0054cced     JNZ        LAB_0054cd09
    //                               LAB_0054ccef                                                 XREF[1]:     0054cce8(j)  
    //         0054ccef     PUSH       0x2
    //         0054ccf1     CALL       __get_osfhandle                                  undefined __get_osfhandle()
    //         0054ccf6     ADD        ESP,0x4
    //         0054ccf9     MOV        EBX,EAX
    //         0054ccfb     PUSH       0x1
    //         0054ccfd     CALL       __get_osfhandle                                  undefined __get_osfhandle()
    //         0054cd02     ADD        ESP,0x4
    //         0054cd05     CMP        EAX,EBX
    //         0054cd07     JZ         LAB_0054cd27
    //                               LAB_0054cd09                                                 XREF[1]:     0054cced(j)  
    //         0054cd09     PUSH       ESI
    //         0054cd0a     CALL       __get_osfhandle                                  undefined __get_osfhandle()
    //         0054cd0f     ADD        ESP,0x4
    //         0054cd12     PUSH       EAX
    //         0054cd13     CALL       dword ptr [->KERNEL32.DLL::CloseHandle]          = 0048aa26
    //         0054cd19     TEST       EAX,EAX
    //         0054cd1b     JNZ        LAB_0054cd27
    //         0054cd1d     CALL       dword ptr [->KERNEL32.DLL::GetLastError]         = 0048aa76
    //         0054cd23     MOV        EBX,EAX
    //         0054cd25     JMP        LAB_0054cd29
    //                               LAB_0054cd27                                                 XREF[3]:     0054cce3(j), 0054cd07(j), 
    //                                                                                                         0054cd1b(j)  
    //         0054cd27     XOR        EBX,EBX
    //                               LAB_0054cd29                                                 XREF[1]:     0054cd25(j)  
    //         0054cd29     PUSH       ESI
    //         0054cd2a     CALL       __free_osfhnd                                    undefined __free_osfhnd()
    //         0054cd2f     MOV        EDX,dword ptr [EBP]=>___pioinfo
    //         0054cd32     ADD        ESP,0x4
    //         0054cd35     TEST       EBX,EBX
    //         0054cd37     MOV        byte ptr [EDX + EDI*0x1 + 0x4],0x0
    //         0054cd3c     JZ         LAB_0054cd4f
    //         0054cd3e     PUSH       EBX
    //         0054cd3f     CALL       __dosmaperr                                      undefined __dosmaperr()
    //         0054cd44     ADD        ESP,0x4
    //         0054cd47     OR         EAX,0xffffffff
    //         0054cd4a     POP        EDI
    //         0054cd4b     POP        ESI
    //         0054cd4c     POP        EBP
    //         0054cd4d     POP        EBX
    //         0054cd4e     RET
    //                               LAB_0054cd4f                                                 XREF[1]:     0054cd3c(j)  
    //         0054cd4f     XOR        EAX,EAX
    //         0054cd51     POP        EDI
    //         0054cd52     POP        ESI
    //         0054cd53     POP        EBP
    //         0054cd54     POP        EBX
    //         0054cd55     RET
    //                               LAB_0054cd56                                                 XREF[2]:     0054ccaf(j), 0054ccd5(j)  
    //         0054cd56     POP        EDI
    //         0054cd57     POP        ESI
    //         0054cd58     POP        EBP
    //         0054cd59     MOV        dword ptr [_errno],0x9                           = align(4)
    //         0054cd63     MOV        dword ptr [__doserrno],0x0
    //         0054cd6d     OR         EAX,0xffffffff
    //         0054cd70     POP        EBX
    //         0054cd71     RET
}

// Offset: 0x0054CD80
undefined read() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * read                                                                                                  *
    //                              *********************************************************************************************************
    //                              undefined __cdecl read()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[1]:     0054cdb1(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[3]:     0054cdb8(W), 0054cdea(R), 0054ce08(*)  
    //                               _read                                                        XREF[30]:    RGE_Campaign:00423278(c), 
    //                               __read                                                                    RGE_Campaign:004232b1(c), 
    //                               read                                                                      ReadPalette:004397cd(c), 
    //                                                                                                         palette:00449c93(c), 
    //                                                                                                         palette:00449cb6(c), 
    //                                                                                                         draw:00449ecc(c), 
    //                                                                                                         draw:00449ef1(c), 
    //                                                                                                         setup:00466c77(c), 
    //                                                                                                         RESFILE_open_new_resource_file:004
    //                                                                                                         RESFILE_open_new_resource_file:004
    //                                                                                                         RESFILE_load:0047f43f(c), 
    //                                                                                                         rge_read_uncompressed:0048001c(c), 
    //                                                                                                         rge_read:004800b5(c), 
    //                                                                                                         rge_read:00480135(c), 
    //                                                                                                         TShape:004b8c51(c), 
    //                                                                                                         TShape:004b8d00(c), 
    //                                                                                                         load:004bce36(c), 
    //                                                                                                         load:004bceab(c), 
    //                                                                                                         Init_Tile_Edge_Tables:00533b55(c), 
    //                                                                                                         Init_Tile_Edge_Tables:00533c14(c), 
    //                                                                                                         [more]
    //         0054cd80     MOV        EAX,[__nhandle]
    //         0054cd85     SUB        ESP,0xc
    //         0054cd88     PUSH       EBX
    //         0054cd89     MOV        EBX,dword ptr [ESP + Stack[0x4]]
    //         0054cd8d     PUSH       EBP
    //         0054cd8e     PUSH       ESI
    //         0054cd8f     CMP        EBX,EAX
    //         0054cd91     PUSH       EDI
    //         0054cd92     JNC        LAB_0054cfb5
    //         0054cd98     MOV        EAX,EBX
    //         0054cd9a     AND        EBX,0x1f
    //         0054cd9d     SAR        EAX,0x5
    //         0054cda0     SHL        EBX,0x3
    //         0054cda3     MOV        ECX,dword ptr [EAX*0x4 + ___pioinfo]
    //         0054cdaa     LEA        ESI,[EAX*0x4 + ___pioinfo]
    //         0054cdb1     MOV        dword ptr [ESP + local_8],ESI
    //         0054cdb5     LEA        EAX,[EBX + ECX*0x1]
    //         0054cdb8     MOV        dword ptr [ESP + local_c],EAX
    //         0054cdbc     MOV        DL,byte ptr [EAX + 0x4]
    //         0054cdbf     TEST       DL,0x1
    //         0054cdc2     JZ         LAB_0054cfb5
    //         0054cdc8     MOV        ECX,dword ptr [ESP + Stack[0xc]]
    //         0054cdcc     MOV        EDI,dword ptr [ESP + Stack[0x8]]
    //         0054cdd0     XOR        EBP,EBP
    //         0054cdd2     MOV        EAX,EDI
    //         0054cdd4     TEST       ECX,ECX
    //         0054cdd6     JZ         LAB_0054cfab
    //         0054cddc     TEST       DL,0x2
    //         0054cddf     JNZ        LAB_0054cfab
    //         0054cde5     TEST       DL,0x48
    //         0054cde8     JZ         LAB_0054ce08
    //         0054cdea     MOV        EDX,dword ptr [ESP + local_c]
    //         0054cdee     MOV        DL,byte ptr [EDX + 0x5]
    //         0054cdf1     CMP        DL,0xa
    //         0054cdf4     JZ         LAB_0054ce08
    //         0054cdf6     MOV        byte ptr [EDI],DL
    //         0054cdf8     MOV        EDX,dword ptr [ESI]=>___pioinfo
    //         0054cdfa     LEA        EAX,[EDI + 0x1]
    //         0054cdfd     MOV        EBP,0x1
    //         0054ce02     DEC        ECX
    //         0054ce03     MOV        byte ptr [EBX + EDX*0x1 + 0x5],0xa
    //                               LAB_0054ce08                                                 XREF[2]:     0054cde8(j), 0054cdf4(j)  
    //         0054ce08     LEA        EDX=>local_c,[ESP + 0x10]
    //         0054ce0c     PUSH       0x0
    //         0054ce0e     PUSH       EDX
    //         0054ce0f     PUSH       ECX
    //         0054ce10     PUSH       EAX
    //         0054ce11     MOV        EAX,dword ptr [ESI]=>___pioinfo
    //         0054ce13     MOV        ECX,dword ptr [EBX + EAX*0x1]
    //         0054ce16     PUSH       ECX
    //         0054ce17     CALL       dword ptr [->KERNEL32.DLL::ReadFile]             = 0048b736
    //         0054ce1d     TEST       EAX,EAX
    //         0054ce1f     JNZ        LAB_0054ce69
    //         0054ce21     CALL       dword ptr [->KERNEL32.DLL::GetLastError]         = 0048aa76
    //         0054ce27     CMP        EAX,0x5
    //         0054ce2a     JNZ        LAB_0054ce46
    //         0054ce2c     MOV        [__doserrno],EAX
    //         0054ce31     MOV        dword ptr [_errno],0x9                           = align(4)
    //         0054ce3b     OR         EAX,0xffffffff
    //         0054ce3e     POP        EDI
    //         0054ce3f     POP        ESI
    //         0054ce40     POP        EBP
    //         0054ce41     POP        EBX
    //         0054ce42     ADD        ESP,0xc
    //         0054ce45     RET
    //                               LAB_0054ce46                                                 XREF[1]:     0054ce2a(j)  
    //         0054ce46     CMP        EAX,0x6d
    //         0054ce49     JNZ        LAB_0054ce55
    //         0054ce4b     XOR        EAX,EAX
    //         0054ce4d     POP        EDI
    //         0054ce4e     POP        ESI
    //         0054ce4f     POP        EBP
    //         0054ce50     POP        EBX
    //         0054ce51     ADD        ESP,0xc
    //         0054ce54     RET
    //                               LAB_0054ce55                                                 XREF[1]:     0054ce49(j)  
    //         0054ce55     PUSH       EAX
    //         0054ce56     CALL       __dosmaperr                                      undefined __dosmaperr()
    //         0054ce5b     ADD        ESP,0x4
    //         0054ce5e     OR         EAX,0xffffffff
    //         0054ce61     POP        EDI
    //         0054ce62     POP        ESI
    //         0054ce63     POP        EBP
    //         0054ce64     POP        EBX
    //         0054ce65     ADD        ESP,0xc
    //         0054ce68     RET
    //                               LAB_0054ce69                                                 XREF[1]:     0054ce1f(j)  
    //         0054ce69     MOV        EAX,dword ptr [ESI]=>___pioinfo
    //         0054ce6b     MOV        EDX,dword ptr [ESP + 0x10]
    //         0054ce6f     ADD        EBP,EDX
    //         0054ce71     LEA        ECX,[EBX + EAX*0x1 + 0x4]
    //         0054ce75     MOV        AL,byte ptr [EBX + EAX*0x1 + 0x4]
    //         0054ce79     TEST       AL,0x80
    //         0054ce7b     JZ         LAB_0054cfa1
    //         0054ce81     TEST       EDX,EDX
    //         0054ce83     JZ         LAB_0054ce8e
    //         0054ce85     CMP        byte ptr [EDI],0xa
    //         0054ce88     JNZ        LAB_0054ce8e
    //         0054ce8a     OR         AL,0x4
    //         0054ce8c     JMP        LAB_0054ce90
    //                               LAB_0054ce8e                                                 XREF[2]:     0054ce83(j), 0054ce88(j)  
    //         0054ce8e     AND        AL,0xfb
    //                               LAB_0054ce90                                                 XREF[1]:     0054ce8c(j)  
    //         0054ce90     MOV        byte ptr [ECX],AL
    //         0054ce92     MOV        EAX,dword ptr [ESP + 0x24]
    //         0054ce96     ADD        EBP,EAX
    //         0054ce98     MOV        ESI,EDI
    //         0054ce9a     CMP        EAX,EBP
    //         0054ce9c     MOV        dword ptr [ESP + 0x18],EBP
    //         0054cea0     JNC        LAB_0054cf9b
    //                               LAB_0054cea6                                                 XREF[1]:     0054cf6f(j)  
    //         0054cea6     MOV        AL,byte ptr [EDI]
    //         0054cea8     CMP        AL,0x1a
    //         0054ceaa     JZ         LAB_0054cf85
    //         0054ceb0     CMP        AL,0xd
    //         0054ceb2     JZ         LAB_0054cebd
    //         0054ceb4     MOV        byte ptr [ESI],AL
    //         0054ceb6     INC        ESI
    //         0054ceb7     INC        EDI
    //         0054ceb8     JMP        LAB_0054cf69
    //                               LAB_0054cebd                                                 XREF[1]:     0054ceb2(j)  
    //         0054cebd     DEC        EBP
    //         0054cebe     CMP        EDI,EBP
    //         0054cec0     JNC        LAB_0054cedd
    //         0054cec2     CMP        byte ptr [EDI + 0x1],0xa
    //         0054cec6     JNZ        LAB_0054ced3
    //         0054cec8     ADD        EDI,0x2
    //         0054cecb     MOV        byte ptr [ESI],0xa
    //         0054cece     JMP        LAB_0054cf68
    //                               LAB_0054ced3                                                 XREF[1]:     0054cec6(j)  
    //         0054ced3     MOV        byte ptr [ESI],0xd
    //         0054ced6     INC        ESI
    //         0054ced7     INC        EDI
    //         0054ced8     JMP        LAB_0054cf69
    //                               LAB_0054cedd                                                 XREF[1]:     0054cec0(j)  
    //         0054cedd     MOV        EAX,dword ptr [ESP + 0x14]
    //         0054cee1     XOR        EBP,EBP
    //         0054cee3     LEA        ECX,[ESP + 0x10]
    //         0054cee7     PUSH       EBP
    //         0054cee8     PUSH       ECX=>DAT_fffffff8
    //         0054cee9     MOV        ECX,dword ptr [EAX]
    //         0054ceeb     LEA        EDX,[ESP + 0x30]
    //         0054ceef     PUSH       offset DAT_fffffff4
    //         0054cef1     PUSH       EDX=>DAT_fffffff0
    //         0054cef2     MOV        EDX,dword ptr [EBX + ECX*0x1]
    //         0054cef5     PUSH       EDX
    //         0054cef6     INC        EDI
    //         0054cef7     CALL       dword ptr [->KERNEL32.DLL::ReadFile]             = 0048b736
    //         0054cefd     TEST       EAX,EAX
    //         0054ceff     JNZ        LAB_0054cf09
    //         0054cf01     CALL       dword ptr [->KERNEL32.DLL::GetLastError]         = 0048aa76
    //         0054cf07     MOV        EBP,EAX
    //                               LAB_0054cf09                                                 XREF[1]:     0054ceff(j)  
    //         0054cf09     TEST       EBP,EBP
    //         0054cf0b     JNZ        LAB_0054cf65
    //         0054cf0d     MOV        EAX,dword ptr [ESP + 0x10]
    //         0054cf11     TEST       EAX,EAX
    //         0054cf13     JZ         LAB_0054cf65
    //         0054cf15     MOV        ECX,dword ptr [ESP + 0x14]
    //         0054cf19     MOV        EAX,dword ptr [ECX]
    //         0054cf1b     TEST       byte ptr [EBX + EAX*0x1 + 0x4],0x48
    //         0054cf20     JZ         LAB_0054cf3a
    //         0054cf22     MOV        AL,byte ptr [ESP + 0x28]
    //         0054cf26     CMP        AL,0xa
    //         0054cf28     JNZ        LAB_0054cf2e
    //         0054cf2a     MOV        byte ptr [ESI],AL
    //         0054cf2c     JMP        LAB_0054cf68
    //                               LAB_0054cf2e                                                 XREF[1]:     0054cf28(j)  
    //         0054cf2e     MOV        byte ptr [ESI],0xd
    //         0054cf31     MOV        ECX,dword ptr [ECX]
    //         0054cf33     INC        ESI
    //         0054cf34     MOV        byte ptr [EBX + ECX*0x1 + 0x5],AL
    //         0054cf38     JMP        LAB_0054cf69
    //                               LAB_0054cf3a                                                 XREF[1]:     0054cf20(j)  
    //         0054cf3a     CMP        ESI,dword ptr [ESP + 0x24]
    //         0054cf3e     JNZ        LAB_0054cf4c
    //         0054cf40     CMP        byte ptr [ESP + 0x28],0xa
    //         0054cf45     JNZ        LAB_0054cf4c
    //         0054cf47     MOV        byte ptr [ESI],0xa
    //         0054cf4a     JMP        LAB_0054cf68
    //                               LAB_0054cf4c                                                 XREF[2]:     0054cf3e(j), 0054cf45(j)  
    //         0054cf4c     MOV        EDX,dword ptr [ESP + 0x20]
    //         0054cf50     PUSH       0x1
    //         0054cf52     PUSH       offset DAT_fffffff8
    //         0054cf54     PUSH       EDX=>DAT_fffffff4
    //         0054cf55     CALL       lseek                                            undefined lseek()
    //         0054cf5a     MOV        AL,byte ptr [ESP + 0x34]
    //         0054cf5e     ADD        ESP,0xc
    //         0054cf61     CMP        AL,0xa
    //         0054cf63     JZ         LAB_0054cf69
    //                               LAB_0054cf65                                                 XREF[2]:     0054cf0b(j), 0054cf13(j)  
    //         0054cf65     MOV        byte ptr [ESI],0xd
    //                               LAB_0054cf68                                                 XREF[3]:     0054cece(j), 0054cf2c(j), 
    //                                                                                                         0054cf4a(j)  
    //         0054cf68     INC        ESI
    //                               LAB_0054cf69                                                 XREF[4]:     0054ceb8(j), 0054ced8(j), 
    //                                                                                                         0054cf38(j), 0054cf63(j)  
    //         0054cf69     MOV        EBP,dword ptr [ESP + 0x18]
    //         0054cf6d     CMP        EDI,EBP
    //         0054cf6f     JC         LAB_0054cea6
    //         0054cf75     SUB        ESI,dword ptr [ESP + 0x24]
    //         0054cf79     MOV        EBP,ESI
    //         0054cf7b     MOV        EAX,EBP
    //         0054cf7d     POP        EDI
    //         0054cf7e     POP        ESI
    //         0054cf7f     POP        EBP
    //         0054cf80     POP        EBX
    //         0054cf81     ADD        ESP,0xc
    //         0054cf84     RET
    //                               LAB_0054cf85                                                 XREF[1]:     0054ceaa(j)  
    //         0054cf85     MOV        EAX,dword ptr [ESP + 0x14]
    //         0054cf89     MOV        ECX,dword ptr [EAX]
    //         0054cf8b     MOV        AL,byte ptr [EBX + ECX*0x1 + 0x4]
    //         0054cf8f     TEST       AL,0x40
    //         0054cf91     LEA        EBX,[EBX + ECX*0x1 + 0x4]
    //         0054cf95     JNZ        LAB_0054cf9b
    //         0054cf97     OR         AL,0x2
    //         0054cf99     MOV        byte ptr [EBX],AL
    //                               LAB_0054cf9b                                                 XREF[2]:     0054cea0(j), 0054cf95(j)  
    //         0054cf9b     SUB        ESI,dword ptr [ESP + 0x24]
    //         0054cf9f     MOV        EBP,ESI
    //                               LAB_0054cfa1                                                 XREF[1]:     0054ce7b(j)  
    //         0054cfa1     MOV        EAX,EBP
    //         0054cfa3     POP        EDI
    //         0054cfa4     POP        ESI
    //         0054cfa5     POP        EBP
    //         0054cfa6     POP        EBX
    //         0054cfa7     ADD        ESP,0xc
    //         0054cfaa     RET
    //                               LAB_0054cfab                                                 XREF[2]:     0054cdd6(j), 0054cddf(j)  
    //         0054cfab     XOR        EAX,EAX
    //         0054cfad     POP        EDI
    //         0054cfae     POP        ESI
    //         0054cfaf     POP        EBP
    //         0054cfb0     POP        EBX
    //         0054cfb1     ADD        ESP,0xc
    //         0054cfb4     RET
    //                               LAB_0054cfb5                                                 XREF[2]:     0054cd92(j), 0054cdc2(j)  
    //         0054cfb5     POP        EDI
    //         0054cfb6     POP        ESI
    //         0054cfb7     POP        EBP
    //         0054cfb8     MOV        dword ptr [_errno],0x9                           = align(4)
    //         0054cfc2     MOV        dword ptr [__doserrno],0x0
    //         0054cfcc     OR         EAX,0xffffffff
    //         0054cfcf     POP        EBX
    //         0054cfd0     ADD        ESP,0xc
    //         0054cfd3     RET
}

// Offset: 0x0054CFE0
undefined open() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __open()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __open                                                       XREF[31]:    RGE_Campaign:00423263(c), 
    //                                                                                                         open_scenario:004236b2(c), 
    //                                                                                                         ReadPalette:00439786(c), 
    //                                                                                                         play:00462384(c), 
    //                                                                                                         setup:00466c31(c), 
    //                                                                                                         RESFILE_open_new_resource_file:004
    //                                                                                                         RESFILE_build_res_file:0047f7e0(c)
    //                                                                                                         RESFILE_build_res_file:0047f94c(c)
    //                                                                                                         rge_open:0047fd9c(c), 
    //                                                                                                         rge_open:0047fe31(c), 
    //                                                                                                         Get_BuildList:0048bd85(c), 
    //                                                                                                         Get_CityPlan:0048bf85(c), 
    //                                                                                                         Get_player_AI:0048c1a5(c), 
    //                                                                                                         save:0048c950(c), 
    //                                                                                                         TShape:004b8c0b(c), 
    //                                                                                                         TShape:004b8cba(c), 
    //                                                                                                         load:004bce1b(c), 
    //                                                                                                         start_video:005238af(c), 
    //                                                                                                         start_video:005238fa(c), 
    //                                                                                                         Init_Tile_Edge_Tables:00533b03(c), 
    //                                                                                                         [more]
    //         0054cfe0     MOV        EAX,dword ptr [ESP + Stack[0xc]]
    //         0054cfe4     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //         0054cfe8     MOV        EDX,dword ptr [ESP + Stack[0x4]]
    //         0054cfec     PUSH       EAX
    //         0054cfed     PUSH       0x40
    //         0054cfef     PUSH       ECX
    //         0054cff0     PUSH       EDX
    //         0054cff1     CALL       __sopen                                          undefined __sopen()
    //         0054cff6     ADD        ESP,0x10
    //         0054cff9     RET
}

