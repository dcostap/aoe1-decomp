// Auto-generated scaffold unit: bucket_0553.asm
#include "../include/common.h"

// Offset: 0x00553000
undefined FUN_00553000() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00553000()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00553000                                                 XREF[2]:     __input:0055295e(c), 
    //                                                                                                         __input:00552ada(c)  
    //         00553000     MOV        EAX,[___mb_cur_max]                              = 00000001h
    //         00553005     PUSH       ESI
    //         00553006     CMP        EAX,0x1
    //         00553009     JLE        LAB_0055301c
    //         0055300b     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         0055300f     PUSH       0x4
    //         00553011     PUSH       ESI
    //         00553012     CALL       __isctype                                        undefined __isctype()
    //         00553017     ADD        ESP,0x8
    //         0055301a     JMP        LAB_0055302b
    //                               LAB_0055301c                                                 XREF[1]:     00553009(j)  
    //         0055301c     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         00553020     MOV        EAX,[__pctype]                                   = 005920da
    //         00553025     MOV        AL,byte ptr [EAX + ESI*0x2]=>DAT_005920da        = 20h     
    //         00553028     AND        EAX,0x4
    //                               LAB_0055302b                                                 XREF[1]:     0055301a(j)  
    //         0055302b     TEST       EAX,EAX
    //         0055302d     JNZ        LAB_00553035
    //         0055302f     AND        ESI,0xffffffdf
    //         00553032     SUB        ESI,0x7
    //                               LAB_00553035                                                 XREF[1]:     0055302d(j)  
    //         00553035     MOV        EAX,ESI
    //         00553037     POP        ESI
    //         00553038     RET
}

// Offset: 0x00553040
undefined FUN_00553040() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00553040()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00553040                                                 XREF[19]:    __input:00552522(c), 
    //                                                                                                         __input:005526e8(c), 
    //                                                                                                         __input:0055274d(c), 
    //                                                                                                         __input:00552832(c), 
    //                                                                                                         __input:0055284f(c), 
    //                                                                                                         __input:0055289f(c), 
    //                                                                                                         __input:005528ea(c), 
    //                                                                                                         __input:005529fe(c), 
    //                                                                                                         __input:00552b23(c), 
    //                                                                                                         __input:00552c16(c), 
    //                                                                                                         __input:00552c80(c), 
    //                                                                                                         __input:00552cad(c), 
    //                                                                                                         __input:00552d02(c), 
    //                                                                                                         __input:00552d45(c), 
    //                                                                                                         __input:00552d7d(c), 
    //                                                                                                         __input:00552e71(c), 
    //                                                                                                         __input:00552ea7(c), 
    //                                                                                                         FUN_00553090:0055309e(c), 
    //                                                                                                         FUN_00553090:005530bb(c)  
    //         00553040     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         00553044     MOV        EAX,dword ptr [ECX + 0x4]
    //         00553047     DEC        EAX
    //         00553048     MOV        dword ptr [ECX + 0x4],EAX
    //         0055304b     JS         LAB_00553057
    //         0055304d     MOV        EDX,dword ptr [ECX]
    //         0055304f     XOR        EAX,EAX
    //         00553051     MOV        AL,byte ptr [EDX]
    //         00553053     INC        EDX
    //         00553054     MOV        dword ptr [ECX],EDX
    //         00553056     RET
    //                               LAB_00553057                                                 XREF[1]:     0055304b(j)  
    //         00553057     PUSH       ECX
    //         00553058     CALL       __filbuf                                         undefined __filbuf()
    //         0055305d     ADD        ESP,0x4
    //         00553060     RET
}

// Offset: 0x00553070
undefined FUN_00553070() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00553070()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00553070                                                 XREF[9]:     __input:00552346(c), 
    //                                                                                                         __input:005526bb(c), 
    //                                                                                                         __input:0055279e(c), 
    //                                                                                                         __input:00552886(c), 
    //                                                                                                         __input:00552a15(c), 
    //                                                                                                         __input:00552b3a(c), 
    //                                                                                                         __input:00552dcc(c), 
    //                                                                                                         __input:00552ef5(c), 
    //                                                                                                         __input:00552f08(c)  
    //         00553070     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00553074     CMP        EAX,-0x1
    //         00553077     JZ         LAB_00553087
    //         00553079     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //         0055307d     PUSH       ECX
    //         0055307e     PUSH       EAX
    //         0055307f     CALL       ungetc                                           undefined ungetc()
    //         00553084     ADD        ESP,0x8
    //                               LAB_00553087                                                 XREF[1]:     00553077(j)  
    //         00553087     RET
}

// Offset: 0x00553090
undefined FUN_00553090() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00553090()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00553090                                                 XREF[2]:     __input:0055233d(c), 
    //                                                                                                         __input:0055250e(c)  
    //         00553090     PUSH       EBX
    //         00553091     MOV        EBX,dword ptr [ESP + Stack[0x8]]
    //         00553095     PUSH       ESI
    //         00553096     PUSH       EDI
    //         00553097     MOV        EDI,dword ptr [ESP + Stack[0x4]]
    //         0055309b     PUSH       EBX
    //         0055309c     INC        dword ptr [EDI]
    //         0055309e     CALL       FUN_00553040                                     undefined FUN_00553040()
    //         005530a3     ADD        ESP,0x4
    //         005530a6     MOV        ESI,EAX
    //         005530a8     PUSH       ESI
    //         005530a9     CALL       isspace                                          undefined isspace()
    //         005530ae     ADD        ESP,0x4
    //         005530b1     TEST       EAX,EAX
    //         005530b3     JZ         LAB_005530d2
    //                               LAB_005530b5                                                 XREF[1]:     005530d0(j)  
    //         005530b5     MOV        ESI,dword ptr [EDI]
    //         005530b7     PUSH       EBX
    //         005530b8     INC        ESI
    //         005530b9     MOV        dword ptr [EDI],ESI
    //         005530bb     CALL       FUN_00553040                                     undefined FUN_00553040()
    //         005530c0     ADD        ESP,0x4
    //         005530c3     MOV        ESI,EAX
    //         005530c5     PUSH       ESI
    //         005530c6     CALL       isspace                                          undefined isspace()
    //         005530cb     ADD        ESP,0x4
    //         005530ce     TEST       EAX,EAX
    //         005530d0     JNZ        LAB_005530b5
    //                               LAB_005530d2                                                 XREF[1]:     005530b3(j)  
    //         005530d2     MOV        EAX,ESI
    //         005530d4     POP        EDI
    //         005530d5     POP        ESI
    //         005530d6     POP        EBX
    //         005530d7     RET
}

// Offset: 0x005530E0
undefined filbuf() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __filbuf()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __filbuf                                                     XREF[2]:     fgets:0054bb28(c), 
    //                                                                                                         FUN_00553040:00553058(c)  
    //         005530e0     PUSH       ESI
    //         005530e1     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         005530e5     PUSH       EDI
    //         005530e6     MOV        EAX,dword ptr [ESI + 0xc]
    //         005530e9     TEST       AL,0x83
    //         005530eb     JZ         LAB_005531c6
    //         005530f1     TEST       AL,0x40
    //         005530f3     JNZ        LAB_005531c6
    //         005530f9     TEST       AL,0x2
    //         005530fb     JZ         LAB_00553108
    //         005530fd     OR         AL,0x20
    //         005530ff     MOV        dword ptr [ESI + 0xc],EAX
    //         00553102     OR         EAX,0xffffffff
    //         00553105     POP        EDI
    //         00553106     POP        ESI
    //         00553107     RET
    //                               LAB_00553108                                                 XREF[1]:     005530fb(j)  
    //         00553108     OR         AL,0x1
    //         0055310a     TEST       EAX,0x10c
    //         0055310f     MOV        dword ptr [ESI + 0xc],EAX
    //         00553112     JNZ        LAB_0055311f
    //         00553114     PUSH       ESI
    //         00553115     CALL       __getbuf                                         undefined __getbuf()
    //         0055311a     ADD        ESP,0x4
    //         0055311d     JMP        LAB_00553124
    //                               LAB_0055311f                                                 XREF[1]:     00553112(j)  
    //         0055311f     MOV        EAX,dword ptr [ESI + 0x8]
    //         00553122     MOV        dword ptr [ESI],EAX
    //                               LAB_00553124                                                 XREF[1]:     0055311d(j)  
    //         00553124     MOV        ECX,dword ptr [ESI + 0x18]
    //         00553127     MOV        EDX,dword ptr [ESI + 0x8]
    //         0055312a     MOV        EAX,dword ptr [ESI + 0x10]
    //         0055312d     PUSH       ECX
    //         0055312e     PUSH       EDX
    //         0055312f     PUSH       EAX
    //         00553130     CALL       read                                             undefined read()
    //         00553135     ADD        ESP,0xc
    //         00553138     MOV        dword ptr [ESI + 0x4],EAX
    //         0055313b     TEST       EAX,EAX
    //         0055313d     JZ         LAB_005531ad
    //         0055313f     CMP        EAX,-0x1
    //         00553142     JZ         LAB_005531ad
    //         00553144     MOV        EDX,dword ptr [ESI + 0xc]
    //         00553147     TEST       DL,0x82
    //         0055314a     JNZ        LAB_0055317e
    //         0055314c     MOV        ECX,dword ptr [ESI + 0x10]
    //         0055314f     CMP        ECX,-0x1
    //         00553152     JZ         LAB_00553168
    //         00553154     MOV        EDI,ECX
    //         00553156     SAR        EDI,0x5
    //         00553159     AND        ECX,0x1f
    //         0055315c     MOV        EDI,dword ptr [EDI*0x4 + ___pioinfo]
    //         00553163     LEA        EDI,[EDI + ECX*0x8]
    //         00553166     JMP        LAB_0055316d
    //                               LAB_00553168                                                 XREF[1]:     00553152(j)  
    //         00553168     MOV        EDI,___badioinfo                                 = FFh
    //                               LAB_0055316d                                                 XREF[1]:     00553166(j)  
    //         0055316d     MOV        CL,byte ptr [EDI + 0x4]=>DAT_005920cc
    //         00553170     AND        CL,0x82
    //         00553173     CMP        CL,0x82
    //         00553176     JNZ        LAB_0055317e
    //         00553178     OR         DH,0x20
    //         0055317b     MOV        dword ptr [ESI + 0xc],EDX
    //                               LAB_0055317e                                                 XREF[2]:     0055314a(j), 00553176(j)  
    //         0055317e     CMP        dword ptr [ESI + 0x18],0x200
    //         00553185     JNZ        LAB_0055319b
    //         00553187     MOV        ECX,dword ptr [ESI + 0xc]
    //         0055318a     TEST       CL,0x8
    //         0055318d     JZ         LAB_0055319b
    //         0055318f     TEST       CH,0x4
    //         00553192     JNZ        LAB_0055319b
    //         00553194     MOV        dword ptr [ESI + 0x18],0x1000
    //                               LAB_0055319b                                                 XREF[3]:     00553185(j), 0055318d(j), 
    //                                                                                                         00553192(j)  
    //         0055319b     DEC        EAX
    //         0055319c     XOR        EDX,EDX
    //         0055319e     MOV        dword ptr [ESI + 0x4],EAX
    //         005531a1     MOV        EAX,dword ptr [ESI]
    //         005531a3     MOV        DL,byte ptr [EAX]
    //         005531a5     INC        EAX
    //         005531a6     MOV        dword ptr [ESI],EAX
    //         005531a8     MOV        EAX,EDX
    //         005531aa     POP        EDI
    //         005531ab     POP        ESI
    //         005531ac     RET
    //                               LAB_005531ad                                                 XREF[2]:     0055313d(j), 00553142(j)  
    //         005531ad     MOV        ECX,dword ptr [ESI + 0xc]
    //         005531b0     MOV        dword ptr [ESI + 0x4],0x0
    //         005531b7     NEG        EAX
    //         005531b9     SBB        EAX,EAX
    //         005531bb     AND        EAX,0x10
    //         005531be     ADD        EAX,0x10
    //         005531c1     OR         ECX,EAX
    //         005531c3     MOV        dword ptr [ESI + 0xc],ECX
    //                               LAB_005531c6                                                 XREF[2]:     005530eb(j), 005530f3(j)  
    //         005531c6     POP        EDI
    //         005531c7     OR         EAX,0xffffffff
    //         005531ca     POP        ESI
    //         005531cb     RET
}

// Offset: 0x005531D0
undefined openfile() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __openfile()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __openfile                                                   XREF[1]:     __fsopen:0054bb8a(c)  
    //         005531d0     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //         005531d4     PUSH       EBX
    //         005531d5     PUSH       EBP
    //         005531d6     PUSH       ESI
    //         005531d7     MOV        AL,byte ptr [ECX]
    //         005531d9     XOR        EDX,EDX
    //         005531db     XOR        EBP,EBP
    //         005531dd     PUSH       EDI
    //         005531de     MOV        EDI,dword ptr [__commode]
    //         005531e4     CMP        AL,0x61
    //         005531e6     JZ         LAB_00553205
    //         005531e8     CMP        AL,0x72
    //         005531ea     JZ         LAB_005531fe
    //         005531ec     CMP        AL,0x77
    //         005531ee     JZ         LAB_005531f7
    //         005531f0     XOR        EAX,EAX
    //         005531f2     POP        EDI
    //         005531f3     POP        ESI
    //         005531f4     POP        EBP
    //         005531f5     POP        EBX
    //         005531f6     RET
    //                               LAB_005531f7                                                 XREF[1]:     005531ee(j)  
    //         005531f7     MOV        EAX,0x301
    //         005531fc     JMP        LAB_0055320a
    //                               LAB_005531fe                                                 XREF[1]:     005531ea(j)  
    //         005531fe     XOR        EAX,EAX
    //         00553200     OR         EDI,0x1
    //         00553203     JMP        LAB_0055320d
    //                               LAB_00553205                                                 XREF[1]:     005531e6(j)  
    //         00553205     MOV        EAX,0x109
    //                               LAB_0055320a                                                 XREF[1]:     005531fc(j)  
    //         0055320a     OR         EDI,0x2
    //                               LAB_0055320d                                                 XREF[1]:     00553203(j)  
    //         0055320d     INC        ECX
    //         0055320e     MOV        ESI,0x1
    //         00553213     MOV        dword ptr [ESP + Stack[0x8]],ECX
    //         00553217     MOV        CL,byte ptr [ECX]
    //         00553219     TEST       CL,CL
    //         0055321b     JZ         LAB_005532d1
    //                               LAB_00553221                                                 XREF[1]:     005532cb(j)  
    //         00553221     TEST       ESI,ESI
    //         00553223     JZ         LAB_005532d1
    //         00553229     MOVSX      ECX,CL
    //         0055322c     ADD        ECX,-0x2b
    //         0055322f     CMP        ECX,0x49
    //         00553232     JA         switchD_00553240::caseD_2c
    //         00553238     XOR        EBX,EBX
    //         0055323a     MOV        BL,byte ptr [ECX + switchD_00553240::switchdat
    //                               switchD_00553240::switchD
    //         00553240     JMP        dword ptr [EBX*0x4 + switchD_00553240::switchd   = 00553247
    //                               switchD_00553240::caseD_2b                                   XREF[2]:     00553240(j), 0055332c(*)  
    //         00553247     TEST       AL,0x2
    //         00553249     JNZ        switchD_00553240::caseD_2c
    //         0055324b     AND        AL,0xfe
    //         0055324d     AND        EDI,0xfffffffc
    //         00553250     OR         AL,0x2
    //         00553252     OR         EDI,0x80
    //         00553258     JMP        LAB_005532be
    //                               switchD_00553240::caseD_62                                   XREF[2]:     00553240(j), 00553340(*)  
    //         0055325a     TEST       AH,0xc0
    //         0055325d     JNZ        switchD_00553240::caseD_2c
    //         0055325f     OR         AH,0x80
    //         00553262     JMP        LAB_005532be
    //                               switchD_00553240::caseD_74                                   XREF[2]:     00553240(j), 0055334c(*)  
    //         00553264     TEST       AH,0xc0
    //         00553267     JNZ        switchD_00553240::caseD_2c
    //         00553269     OR         AH,0x40
    //         0055326c     JMP        LAB_005532be
    //                               switchD_00553240::caseD_63                                   XREF[2]:     00553240(j), 00553344(*)  
    //         0055326e     TEST       EDX,EDX
    //         00553270     JNZ        switchD_00553240::caseD_2c
    //         00553272     MOV        EDX,0x1
    //         00553277     OR         EDI,0x4000
    //         0055327d     JMP        LAB_005532be
    //                               switchD_00553240::caseD_6e                                   XREF[2]:     00553240(j), 00553348(*)  
    //         0055327f     TEST       EDX,EDX
    //         00553281     JNZ        switchD_00553240::caseD_2c
    //         00553283     MOV        EDX,0x1
    //         00553288     AND        EDI,0xffffbfff
    //         0055328e     JMP        LAB_005532be
    //                               switchD_00553240::caseD_53                                   XREF[2]:     00553240(j), 00553338(*)  
    //         00553290     TEST       EBP,EBP
    //         00553292     JNZ        switchD_00553240::caseD_2c
    //         00553294     MOV        EBP,0x1
    //         00553299     OR         AL,0x20
    //         0055329b     JMP        LAB_005532be
    //                               switchD_00553240::caseD_52                                   XREF[2]:     00553240(j), 00553334(*)  
    //         0055329d     TEST       EBP,EBP
    //         0055329f     JNZ        switchD_00553240::caseD_2c
    //         005532a1     MOV        EBP,0x1
    //         005532a6     OR         AL,0x10
    //         005532a8     JMP        LAB_005532be
    //                               switchD_00553240::caseD_54                                   XREF[2]:     00553240(j), 0055333c(*)  
    //         005532aa     TEST       AH,0x10
    //         005532ad     JNZ        switchD_00553240::caseD_2c
    //         005532af     OR         AH,0x10
    //         005532b2     JMP        LAB_005532be
    //                               switchD_00553240::caseD_44                                   XREF[2]:     00553240(j), 00553330(*)  
    //         005532b4     TEST       AL,0x40
    //         005532b6     JNZ        switchD_00553240::caseD_2c
    //         005532b8     OR         AL,0x40
    //         005532ba     JMP        LAB_005532be
    //                               switchD_00553240::caseD_2d                                   XREF[12]:    00553232(j), 00553240(j), 
    //                               switchD_00553240::caseD_2e                                                00553249(j), 0055325d(j), 
    //                               switchD_00553240::caseD_2f                                                00553267(j), 00553270(j), 
    //                               switchD_00553240::caseD_30                                                00553281(j), 00553292(j), 
    //                               switchD_00553240::caseD_31                                                0055329f(j), 005532ad(j), 
    //                               switchD_00553240::caseD_32                                                005532b6(j), 00553350(*)  
    //                               switchD_00553240::caseD_33
    //                               switchD_00553240::caseD_34
    //                               switchD_00553240::caseD_35
    //                               switchD_00553240::caseD_36
    //                               switchD_00553240::caseD_37
    //                               switchD_00553240::caseD_38
    //                               switchD_00553240::caseD_39
    //                               switchD_00553240::caseD_3a
    //                               switchD_00553240::caseD_3b
    //                               switchD_00553240::caseD_3c
    //                               switchD_00553240::caseD_3d
    //                               switchD_00553240::caseD_3e
    //                               switchD_00553240::caseD_3f
    //                               switchD_00553240::caseD_40
    //                               switchD_00553240::caseD_41
    //                               switchD_00553240::caseD_42
    //                               switchD_00553240::caseD_43
    //                               switchD_00553240::caseD_45
    //                               switchD_00553240::caseD_46
    //                               switchD_00553240::caseD_47
    //                               switchD_00553240::caseD_48
    //                               switchD_00553240::caseD_49
    //                               switchD_00553240::caseD_4a
    //                               switchD_00553240::caseD_4b
    //                               switchD_00553240::caseD_4c
    //                               switchD_00553240::caseD_4d
    //                               switchD_00553240::caseD_4e
    //                               switchD_00553240::caseD_4f
    //                               switchD_00553240::caseD_50
    //                               switchD_00553240::caseD_51
    //                               switchD_00553240::caseD_55
    //                               switchD_00553240::caseD_56
    //                               switchD_00553240::caseD_57
    //                               switchD_00553240::caseD_58
    //                               switchD_00553240::caseD_59
    //                               switchD_00553240::caseD_5a
    //                               switchD_00553240::caseD_5b
    //                               switchD_00553240::caseD_5c
    //                               switchD_00553240::caseD_5d
    //                               switchD_00553240::caseD_5e
    //                               switchD_00553240::caseD_5f
    //                               switchD_00553240::caseD_60
    //                               switchD_00553240::caseD_61
    //                               switchD_00553240::caseD_64
    //                               switchD_00553240::caseD_65
    //                               switchD_00553240::caseD_66
    //                               switchD_00553240::caseD_67
    //                               switchD_00553240::caseD_68
    //                               switchD_00553240::caseD_69
    //                               switchD_00553240::caseD_6a
    //                               switchD_00553240::caseD_6b
    //                               switchD_00553240::caseD_6c
    //                               switchD_00553240::caseD_6d
    //                               switchD_00553240::caseD_6f
    //                               switchD_00553240::caseD_70
    //                               switchD_00553240::caseD_71
    //                               switchD_00553240::caseD_72
    //                               switchD_00553240::caseD_73
    //                               switchD_00553240::caseD_2c
    //         005532bc     XOR        ESI,ESI
    //                               LAB_005532be                                                 XREF[9]:     00553258(j), 00553262(j), 
    //                                                                                                         0055326c(j), 0055327d(j), 
    //                                                                                                         0055328e(j), 0055329b(j), 
    //                                                                                                         005532a8(j), 005532b2(j), 
    //                                                                                                         005532ba(j)  
    //         005532be     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //         005532c2     INC        ECX
    //         005532c3     MOV        dword ptr [ESP + Stack[0x8]],ECX
    //         005532c7     MOV        CL,byte ptr [ECX]
    //         005532c9     TEST       CL,CL
    //         005532cb     JNZ        LAB_00553221
    //                               LAB_005532d1                                                 XREF[2]:     0055321b(j), 00553223(j)  
    //         005532d1     MOV        ECX,dword ptr [ESP + Stack[0xc]]
    //         005532d5     MOV        EDX,dword ptr [ESP + Stack[0x4]]
    //         005532d9     PUSH       0x1a4
    //         005532de     PUSH       ECX
    //         005532df     PUSH       EAX
    //         005532e0     PUSH       EDX
    //         005532e1     CALL       __sopen                                          undefined __sopen()
    //         005532e6     MOV        ECX,EAX
    //         005532e8     ADD        ESP,0x10
    //         005532eb     TEST       ECX,ECX
    //         005532ed     JGE        LAB_005532f6
    //         005532ef     XOR        EAX,EAX
    //         005532f1     POP        EDI
    //         005532f2     POP        ESI
    //         005532f3     POP        EBP
    //         005532f4     POP        EBX
    //         005532f5     RET
    //                               LAB_005532f6                                                 XREF[1]:     005532ed(j)  
    //         005532f6     MOV        EAX,[__cflush]
    //         005532fb     INC        EAX
    //         005532fc     MOV        [__cflush],EAX
    //         00553301     MOV        EAX,dword ptr [ESP + Stack[0x10]]
    //         00553305     MOV        dword ptr [EAX + 0xc],EDI
    //         00553308     POP        EDI
    //         00553309     POP        ESI
    //         0055330a     POP        EBP
    //         0055330b     MOV        dword ptr [EAX + 0x4],0x0
    //         00553312     MOV        dword ptr [EAX],0x0
    //         00553318     MOV        dword ptr [EAX + 0x8],0x0
    //         0055331f     MOV        dword ptr [EAX + 0x1c],0x0
    //         00553326     MOV        dword ptr [EAX + 0x10],ECX
    //         00553329     POP        EBX
    //         0055332a     RET
}

// Offset: 0x005533A0
undefined getstream() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __getstream()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __getstream                                                  XREF[1]:     __fsopen:0054bb70(c)  
    //         005533a0     PUSH       EBX
    //         005533a1     PUSH       EBP
    //         005533a2     PUSH       ESI
    //         005533a3     MOV        ESI,dword ptr [__nstream]
    //         005533a9     PUSH       EDI
    //         005533aa     XOR        EBP,EBP
    //         005533ac     XOR        EDI,EDI
    //         005533ae     XOR        ECX,ECX
    //         005533b0     CMP        ESI,EBP
    //         005533b2     JLE        LAB_00553404
    //         005533b4     MOV        EDX,dword ptr [___piob]
    //         005533ba     MOV        BL,0x83
    //                               LAB_005533bc                                                 XREF[1]:     005533cd(j)  
    //         005533bc     MOV        EAX,dword ptr [EDX]
    //         005533be     CMP        EAX,EBP
    //         005533c0     JZ         LAB_005533db
    //         005533c2     TEST       byte ptr [EAX + 0xc],BL
    //         005533c5     JZ         LAB_005533d1
    //         005533c7     INC        ECX
    //         005533c8     ADD        EDX,0x4
    //         005533cb     CMP        ECX,ESI
    //         005533cd     JL         LAB_005533bc
    //         005533cf     JMP        LAB_00553404
    //                               LAB_005533d1                                                 XREF[1]:     005533c5(j)  
    //         005533d1     MOV        EAX,[___piob]
    //         005533d6     MOV        EDI,dword ptr [EAX + ECX*0x4]
    //         005533d9     JMP        LAB_00553404
    //                               LAB_005533db                                                 XREF[1]:     005533c0(j)  
    //         005533db     PUSH       0x20
    //         005533dd     LEA        ESI,[ECX*0x4 + 0x0]
    //         005533e4     CALL       malloc                                           undefined malloc()
    //         005533e9     MOV        ECX,dword ptr [___piob]
    //         005533ef     ADD        ESP,0x4
    //         005533f2     MOV        dword ptr [ECX + ESI*0x1],EAX
    //         005533f5     MOV        EDX,dword ptr [___piob]
    //         005533fb     MOV        ESI,dword ptr [EDX + ESI*0x1]
    //         005533fe     CMP        ESI,EBP
    //         00553400     JZ         LAB_00553404
    //         00553402     MOV        EDI,ESI
    //                               LAB_00553404                                                 XREF[4]:     005533b2(j), 005533cf(j), 
    //                                                                                                         005533d9(j), 00553400(j)  
    //         00553404     CMP        EDI,EBP
    //         00553406     JZ         LAB_0055341d
    //         00553408     MOV        dword ptr [EDI + 0x4],EBP
    //         0055340b     MOV        dword ptr [EDI + 0xc],EBP
    //         0055340e     MOV        dword ptr [EDI + 0x8],EBP
    //         00553411     MOV        dword ptr [EDI],EBP
    //         00553413     MOV        dword ptr [EDI + 0x1c],EBP
    //         00553416     MOV        dword ptr [EDI + 0x10],0xffffffff
    //                               LAB_0055341d                                                 XREF[1]:     00553406(j)  
    //         0055341d     MOV        EAX,EDI
    //         0055341f     POP        EDI
    //         00553420     POP        ESI
    //         00553421     POP        EBP
    //         00553422     POP        EBX
    //         00553423     RET
}

// Offset: 0x00553430
undefined flsbuf() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __flsbuf()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __flsbuf                                                     XREF[4]:     sprintf:0054bc19(c), 
    //                                                                                                         vsprintf:0054c229(c), 
    //                                                                                                         fwrite:0054f3e1(c), 
    //                                                                                                         FUN_005520e0:00552107(c)  
    //         00553430     PUSH       EBX
    //         00553431     PUSH       EBP
    //         00553432     PUSH       ESI
    //         00553433     MOV        ESI,dword ptr [ESP + Stack[0x8]]
    //         00553437     PUSH       EDI
    //         00553438     MOV        EAX,dword ptr [ESI + 0xc]
    //         0055343b     MOV        EBP,dword ptr [ESI + 0x10]
    //         0055343e     TEST       AL,0x82
    //         00553440     JZ         LAB_00553550
    //         00553446     TEST       AL,0x40
    //         00553448     JNZ        LAB_00553550
    //         0055344e     XOR        EBX,EBX
    //         00553450     TEST       AL,0x1
    //         00553452     JZ         LAB_00553469
    //         00553454     TEST       AL,0x10
    //         00553456     MOV        dword ptr [ESI + 0x4],EBX
    //         00553459     JZ         LAB_00553550
    //         0055345f     MOV        ECX,dword ptr [ESI + 0x8]
    //         00553462     AND        AL,0xfe
    //         00553464     MOV        dword ptr [ESI],ECX
    //         00553466     MOV        dword ptr [ESI + 0xc],EAX
    //                               LAB_00553469                                                 XREF[1]:     00553452(j)  
    //         00553469     MOV        EAX,dword ptr [ESI + 0xc]
    //         0055346c     MOV        dword ptr [ESI + 0x4],EBX
    //         0055346f     AND        AL,0xef
    //         00553471     OR         AL,0x2
    //         00553473     TEST       EAX,0x10c
    //         00553478     MOV        dword ptr [ESI + 0xc],EAX
    //         0055347b     JNZ        LAB_005534a3
    //         0055347d     CMP        ESI,DAT_00591e68
    //         00553483     JZ         LAB_0055348d
    //         00553485     CMP        ESI,DAT_00591e88
    //         0055348b     JNZ        LAB_0055349a
    //                               LAB_0055348d                                                 XREF[1]:     00553483(j)  
    //         0055348d     PUSH       EBP
    //         0055348e     CALL       __isatty                                         undefined __isatty()
    //         00553493     ADD        ESP,0x4
    //         00553496     TEST       EAX,EAX
    //         00553498     JNZ        LAB_005534a3
    //                               LAB_0055349a                                                 XREF[1]:     0055348b(j)  
    //         0055349a     PUSH       ESI
    //         0055349b     CALL       __getbuf                                         undefined __getbuf()
    //         005534a0     ADD        ESP,0x4
    //                               LAB_005534a3                                                 XREF[2]:     0055347b(j), 00553498(j)  
    //         005534a3     TEST       dword ptr [ESI + 0xc],0x108
    //         005534aa     JZ         LAB_00553518
    //         005534ac     MOV        EAX,dword ptr [ESI + 0x8]
    //         005534af     MOV        EDI,dword ptr [ESI]
    //         005534b1     MOV        ECX,dword ptr [ESI + 0x18]
    //         005534b4     SUB        EDI,EAX
    //         005534b6     LEA        EDX,[EAX + 0x1]
    //         005534b9     DEC        ECX
    //         005534ba     CMP        EDI,EBX
    //         005534bc     MOV        dword ptr [ESI],EDX
    //         005534be     MOV        dword ptr [ESI + 0x4],ECX
    //         005534c1     JLE        LAB_005534db
    //         005534c3     PUSH       EDI
    //         005534c4     PUSH       EAX
    //         005534c5     PUSH       EBP
    //         005534c6     CALL       write                                            undefined write()
    //         005534cb     MOV        EDX,dword ptr [ESI + 0x8]
    //         005534ce     MOV        EBX,EAX
    //         005534d0     MOV        AL,byte ptr [ESP + Stack[0x4]]
    //         005534d4     ADD        ESP,0xc
    //         005534d7     MOV        byte ptr [EDX],AL
    //         005534d9     JMP        LAB_0055352e
    //                               LAB_005534db                                                 XREF[1]:     005534c1(j)  
    //         005534db     CMP        EBP,-0x1
    //         005534de     JZ         LAB_005534f6
    //         005534e0     MOV        EDX,EBP
    //         005534e2     MOV        EAX,EBP
    //         005534e4     SAR        EDX,0x5
    //         005534e7     AND        EAX,0x1f
    //         005534ea     MOV        ECX,dword ptr [EDX*0x4 + ___pioinfo]
    //         005534f1     LEA        EAX,[ECX + EAX*0x8]
    //         005534f4     JMP        LAB_005534fb
    //                               LAB_005534f6                                                 XREF[1]:     005534de(j)  
    //         005534f6     MOV        EAX,___badioinfo                                 = FFh
    //                               LAB_005534fb                                                 XREF[1]:     005534f4(j)  
    //         005534fb     TEST       byte ptr [EAX + 0x4]=>DAT_005920cc,0x20
    //         005534ff     JZ         LAB_0055350d
    //         00553501     PUSH       0x2
    //         00553503     PUSH       EBX
    //         00553504     PUSH       EBP
    //         00553505     CALL       lseek                                            undefined lseek()
    //         0055350a     ADD        ESP,0xc
    //                               LAB_0055350d                                                 XREF[1]:     005534ff(j)  
    //         0055350d     MOV        EDX,dword ptr [ESI + 0x8]
    //         00553510     MOV        AL,byte ptr [ESP + Stack[0x4]]
    //         00553514     MOV        byte ptr [EDX],AL
    //         00553516     JMP        LAB_0055352e
    //                               LAB_00553518                                                 XREF[1]:     005534aa(j)  
    //         00553518     MOV        EDI,0x1
    //         0055351d     LEA        ECX=>Stack[0x4],[ESP + 0x14]
    //         00553521     PUSH       EDI
    //         00553522     PUSH       ECX
    //         00553523     PUSH       EBP
    //         00553524     CALL       write                                            undefined write()
    //         00553529     ADD        ESP,0xc
    //         0055352c     MOV        EBX,EAX
    //                               LAB_0055352e                                                 XREF[2]:     005534d9(j), 00553516(j)  
    //         0055352e     CMP        EBX,EDI
    //         00553530     JZ         LAB_00553542
    //         00553532     MOV        EAX,dword ptr [ESI + 0xc]
    //         00553535     OR         AL,0x20
    //         00553537     MOV        dword ptr [ESI + 0xc],EAX
    //         0055353a     OR         EAX,0xffffffff
    //         0055353d     POP        EDI
    //         0055353e     POP        ESI
    //         0055353f     POP        EBP
    //         00553540     POP        EBX
    //         00553541     RET
    //                               LAB_00553542                                                 XREF[1]:     00553530(j)  
    //         00553542     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00553546     AND        EAX,0xff
    //         0055354b     POP        EDI
    //         0055354c     POP        ESI
    //         0055354d     POP        EBP
    //         0055354e     POP        EBX
    //         0055354f     RET
    //                               LAB_00553550                                                 XREF[3]:     00553440(j), 00553448(j), 
    //                                                                                                         00553459(j)  
    //         00553550     OR         AL,0x20
    //         00553552     POP        EDI
    //         00553553     MOV        dword ptr [ESI + 0xc],EAX
    //         00553556     POP        ESI
    //         00553557     POP        EBP
    //         00553558     OR         EAX,0xffffffff
    //         0055355b     POP        EBX
    //         0055355c     RET
}

// Offset: 0x00553560
undefined tzset() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined ___tzset()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               ___tzset                                                     XREF[3]:     localtime:0054bd6e(c), 
    //                                                                                                         FUN_0054ca20:0054cbd0(c), 
    //                                                                                                         ___loctotime_t:00553de2(c)  
    //         00553560     MOV        EAX,[DAT_00888138]
    //         00553565     TEST       EAX,EAX
    //         00553567     JNZ        LAB_00553574
    //         00553569     CALL       __tzset                                          undefined __tzset()
    //         0055356e     INC        dword ptr [DAT_00888138]
    //                               LAB_00553574                                                 XREF[1]:     00553567(j)  
    //         00553574     RET
}

// Offset: 0x00553580
undefined tzset() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __tzset()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0055358b(W), 0055374a(R)  
    //                               __tzset                                                      XREF[1]:     ___tzset:00553569(c)  
    //         00553580     PUSH       ECX
    //         00553581     PUSH       EBP
    //         00553582     PUSH       ESI
    //         00553583     PUSH       EDI
    //         00553584     XOR        ESI,ESI
    //         00553586     PUSH       s_TZ                                             = "TZ"
    //         0055358b     MOV        dword ptr [ESP + local_4],ESI
    //         0055358f     MOV        dword ptr [DAT_00888080],ESI
    //         00553595     MOV        dword ptr [DAT_00591e38],0xffffffff              = FFFFFFFFh
    //         0055359f     MOV        dword ptr [DAT_00591e28],0xffffffff              = FFFFFFFFh
    //         005535a9     CALL       getenv                                           undefined getenv()
    //         005535ae     MOV        EBP,EAX
    //         005535b0     ADD        ESP,0x4
    //         005535b3     CMP        EBP,ESI
    //         005535b5     JNZ        LAB_00553687
    //         005535bb     PUSH       DAT_00888088
    //         005535c0     CALL       dword ptr [->KERNEL32.DLL::GetTimeZoneInformat   = 0048b6d2
    //         005535c6     CMP        EAX,-0x1
    //         005535c9     JZ         LAB_00553826
    //         005535cf     MOV        EAX,[DAT_00888088]
    //         005535d4     MOV        ECX,dword ptr [DAT_008880dc]
    //         005535da     XOR        EDI,EDI
    //         005535dc     MOV        ESI,0x1
    //         005535e1     LEA        EAX,[EAX + EAX*0x2]
    //         005535e4     MOV        dword ptr [DAT_00888080],ESI
    //         005535ea     LEA        EAX,[EAX + EAX*0x4]
    //         005535ed     SHL        EAX,0x2
    //         005535f0     CMP        word ptr [DAT_008880ce],DI
    //         005535f7     MOV        [__timezone],EAX                                 = 00007080h
    //         005535fc     JZ         LAB_0055360c
    //         005535fe     LEA        EDX,[ECX + ECX*0x2]
    //         00553601     LEA        EDX,[EDX + EDX*0x4]
    //         00553604     LEA        EAX,[EAX + EDX*0x4]
    //         00553607     MOV        [__timezone],EAX                                 = 00007080h
    //                               LAB_0055360c                                                 XREF[1]:     005535fc(j)  
    //         0055360c     CMP        word ptr [DAT_00888122],DI
    //         00553613     JZ         LAB_00553637
    //         00553615     MOV        EAX,[DAT_00888130]
    //         0055361a     CMP        EAX,EDI
    //         0055361c     JZ         LAB_00553637
    //         0055361e     SUB        EAX,ECX
    //         00553620     MOV        dword ptr [__daylight],ESI                       = 00000001h
    //         00553626     LEA        EAX,[EAX + EAX*0x2]
    //         00553629     LEA        ECX,[EAX + EAX*0x4]
    //         0055362c     SHL        ECX,0x2
    //         0055362f     MOV        dword ptr [__dstbias],ECX                        = FFFFF1F0h
    //         00553635     JMP        LAB_00553643
    //                               LAB_00553637                                                 XREF[2]:     00553613(j), 0055361c(j)  
    //         00553637     MOV        dword ptr [__daylight],EDI                       = 00000001h
    //         0055363d     MOV        dword ptr [__dstbias],EDI                        = FFFFF1F0h
    //                               LAB_00553643                                                 XREF[1]:     00553635(j)  
    //         00553643     MOV        EDX,dword ptr [__tzname]                         = 00591da0
    //         00553649     PUSH       0x40
    //         0055364b     PUSH       DAT_0088808c                                     = align(64)
    //         00553650     PUSH       EDX=>DAT_00591da0                                = 50h    P
    //         00553651     CALL       wcstombs                                         undefined wcstombs()
    //         00553656     MOV        EAX,[PTR_DAT_00591e24]                           = 00591de0
    //         0055365b     ADD        ESP,0xc
    //         0055365e     PUSH       0x40
    //         00553660     PUSH       DAT_008880e0                                     = align(64)
    //         00553665     PUSH       EAX=>DAT_00591de0                                = 50h
    //         00553666     CALL       wcstombs                                         undefined wcstombs()
    //         0055366b     MOV        ECX,dword ptr [PTR_DAT_00591e24]                 = 00591de0
    //         00553671     ADD        ESP,0xc
    //         00553674     MOV        byte ptr [ECX + 0x3f]=>DAT_00591e1f,0x0
    //         00553678     MOV        EDX,dword ptr [__tzname]                         = 00591da0
    //         0055367e     MOV        byte ptr [EDX + 0x3f]=>DAT_00591ddf,0x0
    //         00553682     POP        EDI
    //         00553683     POP        ESI
    //         00553684     POP        EBP
    //         00553685     POP        ECX
    //         00553686     RET
    //                               LAB_00553687                                                 XREF[1]:     005535b5(j)  
    //         00553687     CMP        byte ptr [EBP],0x0
    //         0055368b     JZ         LAB_00553826
    //         00553691     MOV        EDI,dword ptr [DAT_00888134]
    //         00553697     CMP        EDI,ESI
    //         00553699     JZ         LAB_005536d0
    //         0055369b     MOV        ESI,EDI
    //         0055369d     MOV        EAX,EBP
    //                               LAB_0055369f                                                 XREF[1]:     005536bd(j)  
    //         0055369f     MOV        DL,byte ptr [EAX]
    //         005536a1     MOV        CL,DL
    //         005536a3     CMP        DL,byte ptr [ESI]
    //         005536a5     JNZ        LAB_005536c3
    //         005536a7     TEST       CL,CL
    //         005536a9     JZ         LAB_005536bf
    //         005536ab     MOV        DL,byte ptr [EAX + 0x1]
    //         005536ae     MOV        CL,DL
    //         005536b0     CMP        DL,byte ptr [ESI + 0x1]
    //         005536b3     JNZ        LAB_005536c3
    //         005536b5     ADD        EAX,0x2
    //         005536b8     ADD        ESI,0x2
    //         005536bb     TEST       CL,CL
    //         005536bd     JNZ        LAB_0055369f
    //                               LAB_005536bf                                                 XREF[1]:     005536a9(j)  
    //         005536bf     XOR        EAX,EAX
    //         005536c1     JMP        LAB_005536c8
    //                               LAB_005536c3                                                 XREF[2]:     005536a5(j), 005536b3(j)  
    //         005536c3     SBB        EAX,EAX
    //         005536c5     SBB        EAX,-0x1
    //                               LAB_005536c8                                                 XREF[1]:     005536c1(j)  
    //         005536c8     TEST       EAX,EAX
    //         005536ca     JZ         LAB_00553826
    //                               LAB_005536d0                                                 XREF[1]:     00553699(j)  
    //         005536d0     PUSH       EDI
    //         005536d1     CALL       free                                             undefined free()
    //         005536d6     MOV        EDI,EBP
    //         005536d8     OR         ECX,0xffffffff
    //         005536db     XOR        EAX,EAX
    //         005536dd     ADD        ESP,0x4
    //         005536e0     SCASB.RE   ES:EDI
    //         005536e2     NOT        ECX
    //         005536e4     PUSH       ECX
    //         005536e5     CALL       malloc                                           undefined malloc()
    //         005536ea     MOV        EDX,EAX
    //         005536ec     ADD        ESP,0x4
    //         005536ef     TEST       EDX,EDX
    //         005536f1     MOV        dword ptr [DAT_00888134],EDX
    //         005536f7     JZ         LAB_00553826
    //         005536fd     MOV        EDI,EBP
    //         005536ff     OR         ECX,0xffffffff
    //         00553702     XOR        EAX,EAX
    //         00553704     PUSH       0x3
    //         00553706     SCASB.RE   ES:EDI
    //         00553708     NOT        ECX
    //         0055370a     SUB        EDI,ECX
    //         0055370c     PUSH       EBP
    //         0055370d     MOV        EAX,ECX
    //         0055370f     MOV        ESI,EDI
    //         00553711     MOV        EDI,EDX
    //         00553713     SHR        ECX,0x2
    //         00553716     MOVSD.REP  ES:EDI,ESI
    //         00553718     MOV        ECX,EAX
    //         0055371a     AND        ECX,0x3
    //         0055371d     MOVSB.REP  ES:EDI,ESI
    //         0055371f     MOV        ECX,dword ptr [__tzname]                         = 00591da0
    //         00553725     PUSH       ECX=>DAT_00591da0                                = 50h    P
    //         00553726     CALL       strncpy                                          undefined strncpy()
    //         0055372b     MOV        EDX,dword ptr [__tzname]                         = 00591da0
    //         00553731     ADD        EBP,0x3
    //         00553734     ADD        ESP,0xc
    //         00553737     MOV        byte ptr [EDX + 0x3]=>DAT_00591da3,0x0
    //         0055373b     MOV        AL,byte ptr [EBP]
    //         0055373e     CMP        AL,0x2d
    //         00553740     JNZ        LAB_0055374a
    //         00553742     MOV        ESI,0x1
    //         00553747     INC        EBP
    //         00553748     JMP        LAB_0055374e
    //                               LAB_0055374a                                                 XREF[1]:     00553740(j)  
    //         0055374a     MOV        ESI,dword ptr [ESP + local_4]
    //                               LAB_0055374e                                                 XREF[1]:     00553748(j)  
    //         0055374e     PUSH       EBP
    //         0055374f     CALL       atol                                             undefined atol()
    //         00553754     LEA        EAX,[EAX + EAX*0x4]
    //         00553757     ADD        ESP,0x4
    //         0055375a     LEA        EAX,[EAX + EAX*0x4]
    //         0055375d     LEA        ECX,[EAX + EAX*0x8]
    //         00553760     SHL        ECX,0x4
    //         00553763     MOV        dword ptr [__timezone],ECX                       = 00007080h
    //                               LAB_00553769                                                 XREF[1]:     00553779(j)  
    //         00553769     MOV        AL,byte ptr [EBP]
    //         0055376c     CMP        AL,0x2b
    //         0055376e     JZ         LAB_00553778
    //         00553770     CMP        AL,0x30
    //         00553772     JL         LAB_0055377b
    //         00553774     CMP        AL,0x39
    //         00553776     JG         LAB_0055377b
    //                               LAB_00553778                                                 XREF[1]:     0055376e(j)  
    //         00553778     INC        EBP
    //         00553779     JMP        LAB_00553769
    //                               LAB_0055377b                                                 XREF[2]:     00553772(j), 00553776(j)  
    //         0055377b     CMP        byte ptr [EBP],0x3a
    //         0055377f     JNZ        LAB_005537e4
    //         00553781     INC        EBP
    //         00553782     PUSH       EBP
    //         00553783     CALL       atol                                             undefined atol()
    //         00553788     MOV        ECX,dword ptr [__timezone]                       = 00007080h
    //         0055378e     LEA        EAX,[EAX + EAX*0x2]
    //         00553791     ADD        ESP,0x4
    //         00553794     LEA        EAX,[EAX + EAX*0x4]
    //         00553797     LEA        ECX,[ECX + EAX*0x4]
    //         0055379a     MOV        dword ptr [__timezone],ECX                       = 00007080h
    //         005537a0     MOV        AL,byte ptr [EBP]
    //         005537a3     CMP        AL,0x30
    //         005537a5     JL         LAB_005537b3
    //                               LAB_005537a7                                                 XREF[1]:     005537b1(j)  
    //         005537a7     CMP        AL,0x39
    //         005537a9     JG         LAB_005537b3
    //         005537ab     MOV        AL,byte ptr [EBP + 0x1]
    //         005537ae     INC        EBP
    //         005537af     CMP        AL,0x30
    //         005537b1     JGE        LAB_005537a7
    //                               LAB_005537b3                                                 XREF[2]:     005537a5(j), 005537a9(j)  
    //         005537b3     CMP        byte ptr [EBP],0x3a
    //         005537b7     JNZ        LAB_005537e4
    //         005537b9     INC        EBP
    //         005537ba     PUSH       EBP
    //         005537bb     CALL       atol                                             undefined atol()
    //         005537c0     MOV        ECX,dword ptr [__timezone]                       = 00007080h
    //         005537c6     ADD        ESP,0x4
    //         005537c9     ADD        ECX,EAX
    //         005537cb     MOV        dword ptr [__timezone],ECX                       = 00007080h
    //         005537d1     MOV        AL,byte ptr [EBP]
    //         005537d4     CMP        AL,0x30
    //         005537d6     JL         LAB_005537e4
    //                               LAB_005537d8                                                 XREF[1]:     005537e2(j)  
    //         005537d8     CMP        AL,0x39
    //         005537da     JG         LAB_005537e4
    //         005537dc     MOV        AL,byte ptr [EBP + 0x1]
    //         005537df     INC        EBP
    //         005537e0     CMP        AL,0x30
    //         005537e2     JGE        LAB_005537d8
    //                               LAB_005537e4                                                 XREF[4]:     0055377f(j), 005537b7(j), 
    //                                                                                                         005537d6(j), 005537da(j)  
    //         005537e4     TEST       ESI,ESI
    //         005537e6     JZ         LAB_005537f0
    //         005537e8     NEG        ECX
    //         005537ea     MOV        dword ptr [__timezone],ECX                       = 00007080h
    //                               LAB_005537f0                                                 XREF[1]:     005537e6(j)  
    //         005537f0     MOVSX      EAX,byte ptr [EBP]
    //         005537f4     TEST       EAX,EAX
    //         005537f6     MOV        [__daylight],EAX                                 = 00000001h
    //         005537fb     JZ         LAB_0055381d
    //         005537fd     MOV        EDX,dword ptr [PTR_DAT_00591e24]                 = 00591de0
    //         00553803     PUSH       0x3
    //         00553805     PUSH       EBP
    //         00553806     PUSH       EDX=>DAT_00591de0                                = 50h
    //         00553807     CALL       strncpy                                          undefined strncpy()
    //         0055380c     MOV        EAX=>DAT_00591de0,[PTR_DAT_00591e24]             = 50h
    //                                                                                  = 00591de0
    //         00553811     ADD        ESP,0xc
    //         00553814     MOV        byte ptr [EAX + 0x3]=>DAT_00591de3,0x0
    //         00553818     POP        EDI
    //         00553819     POP        ESI
    //         0055381a     POP        EBP
    //         0055381b     POP        ECX
    //         0055381c     RET
    //                               LAB_0055381d                                                 XREF[1]:     005537fb(j)  
    //         0055381d     MOV        ECX,dword ptr [PTR_DAT_00591e24]                 = 00591de0
    //         00553823     MOV        byte ptr [ECX]=>DAT_00591de0,0x0                 = 50h
    //                               LAB_00553826                                                 XREF[4]:     005535c9(j), 0055368b(j), 
    //                                                                                                         005536ca(j), 005536f7(j)  
    //         00553826     POP        EDI
    //         00553827     POP        ESI
    //         00553828     POP        EBP
    //         00553829     POP        ECX
    //         0055382a     RET
}

// Offset: 0x00553830
undefined isindst() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __isindst()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __isindst                                                    XREF[3]:     localtime:0054bdaa(c), 
    //                                                                                                         localtime:0054bdee(c), 
    //                                                                                                         ___loctotime_t:00553e5b(c)  
    //         00553830     MOV        EAX,[__daylight]                                 = 00000001h
    //         00553835     PUSH       ESI
    //         00553836     TEST       EAX,EAX
    //         00553838     PUSH       EDI
    //         00553839     JNZ        LAB_00553840
    //         0055383b     XOR        EAX,EAX
    //         0055383d     POP        EDI
    //         0055383e     POP        ESI
    //         0055383f     RET
    //                               LAB_00553840                                                 XREF[1]:     00553839(j)  
    //         00553840     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         00553844     MOV        ECX,dword ptr [DAT_00591e28]                     = FFFFFFFFh
    //         0055384a     MOV        EAX,dword ptr [ESI + 0x14]
    //         0055384d     CMP        EAX,ECX
    //         0055384f     JNZ        LAB_0055385d
    //         00553851     CMP        EAX,dword ptr [DAT_00591e38]                     = FFFFFFFFh
    //         00553857     JZ         LAB_00553a04
    //                               LAB_0055385d                                                 XREF[1]:     0055384f(j)  
    //         0055385d     MOV        ECX,dword ptr [DAT_00888080]
    //         00553863     TEST       ECX,ECX
    //         00553865     JZ         LAB_005539c7
    //         0055386b     CMP        word ptr [DAT_00888120],0x0
    //         00553873     JNZ        LAB_005538cb
    //         00553875     MOV        EDX,dword ptr [DAT_0088812c]
    //         0055387b     XOR        ECX,ECX
    //         0055387d     MOV        CX,word ptr [DAT_0088812c+2]
    //         00553884     AND        EDX,0xffff
    //         0055388a     PUSH       ECX
    //         0055388b     XOR        ECX,ECX
    //         0055388d     MOV        CX,word ptr [DAT_00888128+2]
    //         00553894     PUSH       EDX
    //         00553895     MOV        EDX,dword ptr [DAT_00888128]
    //         0055389b     PUSH       ECX
    //         0055389c     MOV        ECX,dword ptr [DAT_00888124]
    //         005538a2     AND        EDX,0xffff
    //         005538a8     PUSH       EDX
    //         005538a9     AND        ECX,0xffff
    //         005538af     PUSH       0x0
    //         005538b1     PUSH       ECX
    //         005538b2     XOR        EDX,EDX
    //         005538b4     XOR        ECX,ECX
    //         005538b6     MOV        DX,word ptr [DAT_00888124+2]
    //         005538bd     MOV        CX,word ptr [DAT_00888122]
    //         005538c4     PUSH       EDX
    //         005538c5     PUSH       ECX
    //         005538c6     PUSH       EAX
    //         005538c7     PUSH       0x1
    //         005538c9     JMP        LAB_00553914
    //                               LAB_005538cb                                                 XREF[1]:     00553873(j)  
    //         005538cb     MOV        ECX,dword ptr [DAT_0088812c]
    //         005538d1     XOR        EDX,EDX
    //         005538d3     MOV        DX,word ptr [DAT_0088812c+2]
    //         005538da     AND        ECX,0xffff
    //         005538e0     PUSH       EDX
    //         005538e1     XOR        EDX,EDX
    //         005538e3     MOV        DX,word ptr [DAT_00888128+2]
    //         005538ea     PUSH       ECX
    //         005538eb     MOV        ECX,dword ptr [DAT_00888128]
    //         005538f1     PUSH       EDX
    //         005538f2     AND        ECX,0xffff
    //         005538f8     XOR        EDX,EDX
    //         005538fa     MOV        DX,word ptr [DAT_00888124+2]
    //         00553901     PUSH       ECX
    //         00553902     XOR        ECX,ECX
    //         00553904     PUSH       EDX
    //         00553905     MOV        CX,word ptr [DAT_00888122]
    //         0055390c     PUSH       0x0
    //         0055390e     PUSH       0x0
    //         00553910     PUSH       ECX
    //         00553911     PUSH       EAX
    //         00553912     PUSH       0x0
    //                               LAB_00553914                                                 XREF[1]:     005538c9(j)  
    //         00553914     PUSH       0x1
    //         00553916     CALL       FUN_00553aa0                                     undefined FUN_00553aa0()
    //         0055391b     ADD        ESP,0x2c
    //         0055391e     CMP        word ptr [DAT_008880cc],0x0
    //         00553926     JNZ        LAB_0055397b
    //         00553928     MOV        EAX,[DAT_008880d8]
    //         0055392d     XOR        EDX,EDX
    //         0055392f     MOV        DX,word ptr [DAT_008880d8+2]
    //         00553936     AND        EAX,0xffff
    //         0055393b     PUSH       EDX
    //         0055393c     MOV        EDX,dword ptr [DAT_008880d4]
    //         00553942     XOR        ECX,ECX
    //         00553944     PUSH       EAX
    //         00553945     MOV        CX,word ptr [DAT_008880d4+2]
    //         0055394c     MOV        EAX,[DAT_008880d0]
    //         00553951     AND        EDX,0xffff
    //         00553957     PUSH       ECX
    //         00553958     PUSH       EDX
    //         00553959     AND        EAX,0xffff
    //         0055395e     XOR        ECX,ECX
    //         00553960     XOR        EDX,EDX
    //         00553962     MOV        CX,word ptr [DAT_008880d0+2]
    //         00553969     MOV        DX,word ptr [DAT_008880ce]
    //         00553970     PUSH       0x0
    //         00553972     PUSH       EAX
    //         00553973     MOV        EAX,dword ptr [ESI + 0x14]
    //         00553976     PUSH       ECX
    //         00553977     PUSH       EDX
    //         00553978     PUSH       EAX
    //         00553979     JMP        LAB_005539f8
    //                               LAB_0055397b                                                 XREF[1]:     00553926(j)  
    //         0055397b     MOV        EDX,dword ptr [DAT_008880d8]
    //         00553981     XOR        ECX,ECX
    //         00553983     MOV        CX,word ptr [DAT_008880d8+2]
    //         0055398a     AND        EDX,0xffff
    //         00553990     PUSH       ECX
    //         00553991     MOV        ECX,dword ptr [DAT_008880d4]
    //         00553997     XOR        EAX,EAX
    //         00553999     PUSH       EDX
    //         0055399a     MOV        AX,[DAT_008880d4+2]
    //         005539a0     XOR        EDX,EDX
    //         005539a2     MOV        DX,word ptr [DAT_008880d0+2]
    //         005539a9     AND        ECX,0xffff
    //         005539af     PUSH       EAX
    //         005539b0     PUSH       ECX
    //         005539b1     MOV        ECX,dword ptr [ESI + 0x14]
    //         005539b4     XOR        EAX,EAX
    //         005539b6     MOV        AX,[DAT_008880ce]
    //         005539bc     PUSH       EDX
    //         005539bd     PUSH       0x0
    //         005539bf     PUSH       0x0
    //         005539c1     PUSH       EAX
    //         005539c2     PUSH       ECX
    //         005539c3     PUSH       0x0
    //         005539c5     JMP        LAB_005539fa
    //                               LAB_005539c7                                                 XREF[1]:     00553865(j)  
    //         005539c7     PUSH       0x0
    //         005539c9     PUSH       0x0
    //         005539cb     PUSH       0x0
    //         005539cd     PUSH       0x2
    //         005539cf     PUSH       0x0
    //         005539d1     PUSH       0x0
    //         005539d3     PUSH       0x1
    //         005539d5     PUSH       0x4
    //         005539d7     PUSH       EAX
    //         005539d8     PUSH       0x1
    //         005539da     PUSH       0x1
    //         005539dc     CALL       FUN_00553aa0                                     undefined FUN_00553aa0()
    //         005539e1     ADD        ESP,0x2c
    //         005539e4     MOV        EDX,dword ptr [ESI + 0x14]
    //         005539e7     PUSH       0x0
    //         005539e9     PUSH       0x0
    //         005539eb     PUSH       0x0
    //         005539ed     PUSH       0x2
    //         005539ef     PUSH       0x0
    //         005539f1     PUSH       0x0
    //         005539f3     PUSH       0x5
    //         005539f5     PUSH       0xa
    //         005539f7     PUSH       EDX
    //                               LAB_005539f8                                                 XREF[1]:     00553979(j)  
    //         005539f8     PUSH       0x1
    //                               LAB_005539fa                                                 XREF[1]:     005539c5(j)  
    //         005539fa     PUSH       0x0
    //         005539fc     CALL       FUN_00553aa0                                     undefined FUN_00553aa0()
    //         00553a01     ADD        ESP,0x2c
    //                               LAB_00553a04                                                 XREF[1]:     00553857(j)  
    //         00553a04     MOV        EDX,dword ptr [DAT_00591e2c]
    //         00553a0a     MOV        EAX,[DAT_00591e3c]
    //         00553a0f     MOV        ECX,dword ptr [ESI + 0x1c]
    //         00553a12     CMP        EDX,EAX
    //         00553a14     JGE        LAB_00553a2e
    //         00553a16     CMP        ECX,EDX
    //         00553a18     JL         LAB_00553a3e
    //         00553a1a     CMP        ECX,EAX
    //         00553a1c     JG         LAB_00553a3e
    //         00553a1e     CMP        ECX,EDX
    //         00553a20     JLE        LAB_00553a43
    //         00553a22     CMP        ECX,EAX
    //         00553a24     JGE        LAB_00553a43
    //         00553a26     MOV        EAX,0x1
    //         00553a2b     POP        EDI
    //         00553a2c     POP        ESI
    //         00553a2d     RET
    //                               LAB_00553a2e                                                 XREF[1]:     00553a14(j)  
    //         00553a2e     CMP        ECX,EAX
    //         00553a30     JL         LAB_00553a91
    //         00553a32     CMP        ECX,EDX
    //         00553a34     JG         LAB_00553a91
    //         00553a36     CMP        ECX,EAX
    //         00553a38     JLE        LAB_00553a43
    //         00553a3a     CMP        ECX,EDX
    //         00553a3c     JGE        LAB_00553a43
    //                               LAB_00553a3e                                                 XREF[2]:     00553a18(j), 00553a1c(j)  
    //         00553a3e     XOR        EAX,EAX
    //         00553a40     POP        EDI
    //         00553a41     POP        ESI
    //         00553a42     RET
    //                               LAB_00553a43                                                 XREF[4]:     00553a20(j), 00553a24(j), 
    //                                                                                                         00553a38(j), 00553a3c(j)  
    //         00553a43     MOV        EAX,dword ptr [ESI + 0x8]
    //         00553a46     MOV        EDI,dword ptr [ESI + 0x4]
    //         00553a49     MOV        ESI,dword ptr [ESI]
    //         00553a4b     LEA        EAX,[EAX + EAX*0x2]
    //         00553a4e     LEA        EAX,[EAX + EAX*0x4]
    //         00553a51     LEA        EAX,[EDI + EAX*0x4]
    //         00553a54     LEA        EAX,[EAX + EAX*0x2]
    //         00553a57     LEA        EAX,[EAX + EAX*0x4]
    //         00553a5a     LEA        EAX,[ESI + EAX*0x4]
    //         00553a5d     LEA        EAX,[EAX + EAX*0x4]
    //         00553a60     LEA        EAX,[EAX + EAX*0x4]
    //         00553a63     LEA        EAX,[EAX + EAX*0x4]
    //         00553a66     SHL        EAX,0x3
    //         00553a69     CMP        ECX,EDX
    //         00553a6b     JNZ        LAB_00553a7f
    //         00553a6d     MOV        EDX,dword ptr [DAT_00591e30]
    //         00553a73     XOR        ECX,ECX
    //         00553a75     CMP        EAX,EDX
    //         00553a77     SETGE      CL
    //         00553a7a     MOV        EAX,ECX
    //         00553a7c     POP        EDI
    //         00553a7d     POP        ESI
    //         00553a7e     RET
    //                               LAB_00553a7f                                                 XREF[1]:     00553a6b(j)  
    //         00553a7f     MOV        ECX,dword ptr [DAT_00591e40]
    //         00553a85     XOR        EDX,EDX
    //         00553a87     CMP        EAX,ECX
    //         00553a89     SETL       DL
    //         00553a8c     MOV        EAX,EDX
    //         00553a8e     POP        EDI
    //         00553a8f     POP        ESI
    //         00553a90     RET
    //                               LAB_00553a91                                                 XREF[2]:     00553a30(j), 00553a34(j)  
    //         00553a91     POP        EDI
    //         00553a92     MOV        EAX,0x1
    //         00553a97     POP        ESI
    //         00553a98     RET
}

// Offset: 0x00553AA0
undefined FUN_00553aa0() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00553aa0()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00553aa0                                                 XREF[3]:     __isindst:00553916(c), 
    //                                                                                                         __isindst:005539dc(c), 
    //                                                                                                         __isindst:005539fc(c)  
    //         00553aa0     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         00553aa4     PUSH       EBX
    //         00553aa5     MOV        EBX,dword ptr [ESP + Stack[0xc]]
    //         00553aa9     PUSH       EBP
    //         00553aaa     PUSH       ESI
    //         00553aab     CMP        EAX,0x1
    //         00553aae     PUSH       EDI
    //         00553aaf     JNZ        LAB_00553b55
    //         00553ab5     MOV        EAX,EBX
    //         00553ab7     AND        EAX,0x3
    //         00553aba     MOV        dword ptr [ESP + Stack[0xc]],EAX
    //         00553abe     JNZ        LAB_00553ad3
    //         00553ac0     MOV        EAX,dword ptr [ESP + Stack[0x10]]
    //         00553ac4     LEA        EDI,[EAX*0x4 + 0x0]
    //         00553acb     MOV        EAX,dword ptr [EDI + DAT_005923e4]
    //         00553ad1     JMP        LAB_00553ae4
    //                               LAB_00553ad3                                                 XREF[1]:     00553abe(j)  
    //         00553ad3     MOV        ECX,dword ptr [ESP + Stack[0x10]]
    //         00553ad7     LEA        EDI,[ECX*0x4 + 0x0]
    //         00553ade     MOV        EAX,dword ptr [EDI + DAT_0059241c]
    //                               LAB_00553ae4                                                 XREF[1]:     00553ad1(j)  
    //         00553ae4     LEA        EDX,[EBX + EBX*0x8]
    //         00553ae7     LEA        ECX,[EAX + 0x1]
    //         00553aea     LEA        ESI,[EBX + -0x1]
    //         00553aed     LEA        EAX,[EBX + EDX*0x8]
    //         00553af0     MOV        EDX,EAX
    //         00553af2     ADD        EDX,ECX
    //         00553af4     SAR        ESI,0x2
    //         00553af7     LEA        EAX,[EDX + EAX*0x4]
    //         00553afa     LEA        EAX,[ESI + EAX*0x1 + 0xffff9c25]
    //         00553b01     MOV        ESI,0x7
    //         00553b06     CDQ
    //         00553b07     IDIV       ESI
    //         00553b09     MOV        ESI,dword ptr [ESP + Stack[0x18]]
    //         00553b0d     MOV        EAX,dword ptr [ESP + Stack[0x14]]
    //         00553b11     MOV        EBP,EAX
    //         00553b13     CMP        EDX,ESI
    //         00553b15     JGE        LAB_00553b26
    //         00553b17     SHL        EBP,0x3
    //         00553b1a     SUB        EBP,EAX
    //         00553b1c     SUB        EBP,EDX
    //         00553b1e     ADD        EBP,ESI
    //         00553b20     LEA        ECX,[ECX + EBP*0x1 + -0x7]
    //         00553b24     JMP        LAB_00553b31
    //                               LAB_00553b26                                                 XREF[1]:     00553b15(j)  
    //         00553b26     SHL        EBP,0x3
    //         00553b29     SUB        EBP,EAX
    //         00553b2b     SUB        EBP,EDX
    //         00553b2d     ADD        EBP,ESI
    //         00553b2f     ADD        ECX,EBP
    //                               LAB_00553b31                                                 XREF[1]:     00553b24(j)  
    //         00553b31     CMP        EAX,0x5
    //         00553b34     JNZ        LAB_00553b76
    //         00553b36     MOV        EAX,dword ptr [ESP + Stack[0xc]]
    //         00553b3a     TEST       EAX,EAX
    //         00553b3c     JNZ        LAB_00553b46
    //         00553b3e     MOV        EDI,dword ptr [EDI + __lpdays]                   = FFh
    //         00553b44     JMP        LAB_00553b4c
    //                               LAB_00553b46                                                 XREF[1]:     00553b3c(j)  
    //         00553b46     MOV        EDI,dword ptr [EDI + __days]                     = FFFFFFFFh
    //                               LAB_00553b4c                                                 XREF[1]:     00553b44(j)  
    //         00553b4c     CMP        ECX,EDI
    //         00553b4e     JLE        LAB_00553b76
    //         00553b50     SUB        ECX,0x7
    //         00553b53     JMP        LAB_00553b76
    //                               LAB_00553b55                                                 XREF[1]:     00553aaf(j)  
    //         00553b55     TEST       BL,0x3
    //         00553b58     JNZ        LAB_00553b67
    //         00553b5a     MOV        ECX,dword ptr [ESP + Stack[0x10]]
    //         00553b5e     MOV        ECX,dword ptr [ECX*0x4 + DAT_005923e4]
    //         00553b65     JMP        LAB_00553b72
    //                               LAB_00553b67                                                 XREF[1]:     00553b58(j)  
    //         00553b67     MOV        EDX,dword ptr [ESP + Stack[0x10]]
    //         00553b6b     MOV        ECX,dword ptr [EDX*0x4 + DAT_0059241c]
    //                               LAB_00553b72                                                 XREF[1]:     00553b65(j)  
    //         00553b72     ADD        ECX,dword ptr [ESP + Stack[0x1c]]
    //                               LAB_00553b76                                                 XREF[3]:     00553b34(j), 00553b4e(j), 
    //                                                                                                         00553b53(j)  
    //         00553b76     CMP        dword ptr [ESP + Stack[0x4]],0x1
    //         00553b7b     JNZ        LAB_00553bc4
    //         00553b7d     MOV        EAX,dword ptr [ESP + Stack[0x20]]
    //         00553b81     MOV        EDX,dword ptr [ESP + Stack[0x24]]
    //         00553b85     MOV        dword ptr [DAT_00591e2c],ECX
    //         00553b8b     MOV        ECX,EAX
    //         00553b8d     SHL        ECX,0x4
    //         00553b90     SUB        ECX,EAX
    //         00553b92     MOV        dword ptr [DAT_00591e28],EBX                     = FFFFFFFFh
    //         00553b98     LEA        EAX,[EDX + ECX*0x4]
    //         00553b9b     MOV        EDX,dword ptr [ESP + Stack[0x28]]
    //         00553b9f     MOV        ECX,EAX
    //         00553ba1     SHL        ECX,0x4
    //         00553ba4     SUB        ECX,EAX
    //         00553ba6     LEA        EAX,[EDX + ECX*0x4]
    //         00553ba9     MOV        ECX,dword ptr [ESP + Stack[0x2c]]
    //         00553bad     LEA        EAX,[EAX + EAX*0x4]
    //         00553bb0     LEA        EAX,[EAX + EAX*0x4]
    //         00553bb3     LEA        EAX,[EAX + EAX*0x4]
    //         00553bb6     LEA        EDX,[ECX + EAX*0x8]
    //         00553bb9     MOV        dword ptr [DAT_00591e30],EDX
    //         00553bbf     POP        EDI
    //         00553bc0     POP        ESI
    //         00553bc1     POP        EBP
    //         00553bc2     POP        EBX
    //         00553bc3     RET
    //                               LAB_00553bc4                                                 XREF[1]:     00553b7b(j)  
    //         00553bc4     MOV        EAX,dword ptr [ESP + Stack[0x20]]
    //         00553bc8     MOV        EDX,dword ptr [ESP + Stack[0x24]]
    //         00553bcc     MOV        dword ptr [DAT_00591e3c],ECX
    //         00553bd2     MOV        ECX,EAX
    //         00553bd4     SHL        ECX,0x4
    //         00553bd7     SUB        ECX,EAX
    //         00553bd9     LEA        EAX,[EDX + ECX*0x4]
    //         00553bdc     MOV        EDX,dword ptr [ESP + Stack[0x28]]
    //         00553be0     MOV        ECX,EAX
    //         00553be2     SHL        ECX,0x4
    //         00553be5     SUB        ECX,EAX
    //         00553be7     LEA        EAX,[EDX + ECX*0x4]
    //         00553bea     MOV        EDX,dword ptr [__dstbias]                        = FFFFF1F0h
    //         00553bf0     ADD        EAX,EDX
    //         00553bf2     MOV        ECX,dword ptr [ESP + Stack[0x2c]]
    //         00553bf6     LEA        EAX,[EAX + EAX*0x4]
    //         00553bf9     LEA        EAX,[EAX + EAX*0x4]
    //         00553bfc     LEA        EAX,[EAX + EAX*0x4]
    //         00553bff     LEA        EAX,[ECX + EAX*0x8]
    //         00553c02     TEST       EAX,EAX
    //         00553c04     MOV        [DAT_00591e40],EAX
    //         00553c09     JGE        LAB_00553c20
    //         00553c0b     ADD        EAX,0x5265bff
    //         00553c10     MOV        dword ptr [DAT_00591e38],EBX                     = FFFFFFFFh
    //         00553c16     MOV        [DAT_00591e40],EAX
    //         00553c1b     POP        EDI
    //         00553c1c     POP        ESI
    //         00553c1d     POP        EBP
    //         00553c1e     POP        EBX
    //         00553c1f     RET
    //                               LAB_00553c20                                                 XREF[1]:     00553c09(j)  
    //         00553c20     CMP        EAX,0x5265c00
    //         00553c25     JL         LAB_00553c31
    //         00553c27     SUB        EAX,0x5265bff
    //         00553c2c     MOV        [DAT_00591e40],EAX
    //                               LAB_00553c31                                                 XREF[1]:     00553c25(j)  
    //         00553c31     POP        EDI
    //         00553c32     POP        ESI
    //         00553c33     MOV        dword ptr [DAT_00591e38],EBX                     = FFFFFFFFh
    //         00553c39     POP        EBP
    //         00553c3a     POP        EBX
    //         00553c3b     RET
}

// Offset: 0x00553C40
undefined gmtime() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * gmtime                                                                                                *
    //                              *********************************************************************************************************
    //                              undefined __cdecl gmtime()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _gmtime                                                      XREF[4]:     localtime:0054bd92(c), 
    //                               gmtime                                                                    localtime:0054bdcf(c), 
    //                                                                                                         localtime:0054bde3(c), 
    //                                                                                                         FUN_0054ca20:0054cc38(c)  
    //         00553c40     PUSH       EBX
    //         00553c41     MOV        EBX,dword ptr [ESP + Stack[0x4]]
    //         00553c45     PUSH       ESI
    //         00553c46     XOR        ESI,ESI
    //         00553c48     MOV        ECX,dword ptr [EBX]
    //         00553c4a     TEST       ECX,ECX
    //         00553c4c     JGE        LAB_00553c53
    //         00553c4e     XOR        EAX,EAX
    //         00553c50     POP        ESI
    //         00553c51     POP        EBX
    //         00553c52     RET
    //                               LAB_00553c53                                                 XREF[1]:     00553c4c(j)  
    //         00553c53     MOV        EAX,0x11032d79
    //         00553c58     PUSH       EDI
    //         00553c59     IMUL       ECX
    //         00553c5b     SAR        EDX,0x17
    //         00553c5e     MOV        EAX,EDX
    //         00553c60     PUSH       EBP
    //         00553c61     SHR        EAX,0x1f
    //         00553c64     ADD        EDX,EAX
    //         00553c66     MOV        EAX,EDX
    //         00553c68     IMUL       EAX,EAX,-0x7861f80
    //         00553c6e     ADD        ECX,EAX
    //         00553c70     LEA        EAX,[EDX*0x4 + 0x46]
    //         00553c77     CMP        ECX,0x1e13380
    //         00553c7d     JL         LAB_00553cab
    //         00553c7f     SUB        ECX,0x1e13380
    //         00553c85     INC        EAX
    //         00553c86     CMP        ECX,0x1e13380
    //         00553c8c     JL         LAB_00553cab
    //         00553c8e     SUB        ECX,0x1e13380
    //         00553c94     INC        EAX
    //         00553c95     CMP        ECX,0x1e28500
    //         00553c9b     JL         LAB_00553ca6
    //         00553c9d     INC        EAX
    //         00553c9e     SUB        ECX,0x1e28500
    //         00553ca4     JMP        LAB_00553cab
    //                               LAB_00553ca6                                                 XREF[1]:     00553c9b(j)  
    //         00553ca6     MOV        ESI,0x1
    //                               LAB_00553cab                                                 XREF[3]:     00553c7d(j), 00553c8c(j), 
    //                                                                                                         00553ca4(j)  
    //         00553cab     MOV        [null_00888154],EAX                              = align(16)
    //         00553cb0     MOV        EAX,0xc22e4507
    //         00553cb5     IMUL       ECX
    //         00553cb7     MOV        EAX,EDX
    //         00553cb9     MOV        EDI,__lpdays                                     = FFh
    //         00553cbe     ADD        EAX,ECX
    //         00553cc0     SAR        EAX,0x10
    //         00553cc3     MOV        EDX,EAX
    //         00553cc5     SHR        EDX,0x1f
    //         00553cc8     ADD        EAX,EDX
    //         00553cca     MOV        EDX,EAX
    //         00553ccc     MOV        [null_0088815c],EAX                              = align(8)
    //         00553cd1     SHL        EDX,0x4
    //         00553cd4     SUB        EDX,EAX
    //         00553cd6     NEG        EDX
    //         00553cd8     LEA        EDX,[EDX + EDX*0x4]
    //         00553cdb     LEA        EDX,[EDX + EDX*0x8]
    //         00553cde     SHL        EDX,0x7
    //         00553ce1     ADD        ECX,EDX
    //         00553ce3     TEST       ESI,ESI
    //         00553ce5     JNZ        LAB_00553cec
    //         00553ce7     MOV        EDI,__days                                       = FFFFFFFFh
    //                               LAB_00553cec                                                 XREF[1]:     00553ce5(j)  
    //         00553cec     MOV        EBP,dword ptr [EDI + 0x4]=>DAT_00592424          = 0000001Eh
    //         00553cef     LEA        ESI,[EDI + 0x4]=>DAT_00592424                    = 0000001Eh
    //         00553cf2     CMP        EBP,EAX
    //         00553cf4     MOV        EDX,0x1
    //         00553cf9     JGE        LAB_00553d06
    //                               LAB_00553cfb                                                 XREF[1]:     00553d04(j)  
    //         00553cfb     MOV        EBP,dword ptr [ESI + 0x4]=>DAT_00592428          = 0000003Bh
    //                                                                                  = 0000003Ah
    //                                                                                  = 00000059h
    //         00553cfe     ADD        ESI,0x4
    //         00553d01     INC        EDX
    //         00553d02     CMP        EBP,EAX
    //         00553d04     JL         LAB_00553cfb
    //                               LAB_00553d06                                                 XREF[1]:     00553cf9(j)  
    //         00553d06     MOV        EBP,dword ptr [EDI + EDX*0x4 + -0x4]=>DAT_0059   = 0000001Eh
    //                                                                                  = FFFFFFFFh
    //                                                                                  = 0000003Ah
    //         00553d0a     DEC        EDX
    //         00553d0b     SUB        EAX,EBP
    //         00553d0d     MOV        dword ptr [null_00888150],EDX                    = align(20)
    //         00553d13     MOV        [null_0088814c],EAX                              = align(24)
    //         00553d18     MOV        ESI,dword ptr [EBX]
    //         00553d1a     MOV        EAX,0xc22e4507
    //         00553d1f     POP        EBP
    //         00553d20     IMUL       ESI
    //         00553d22     ADD        EDX,ESI
    //         00553d24     MOV        ESI,0x7
    //         00553d29     SAR        EDX,0x10
    //         00553d2c     MOV        EAX,EDX
    //         00553d2e     POP        EDI
    //         00553d2f     SHR        EAX,0x1f
    //         00553d32     MOV        dword ptr [null_00888160],0x0                    = align(4)
    //         00553d3c     LEA        EAX,[EDX + EAX*0x1 + 0x4]
    //         00553d40     CDQ
    //         00553d41     IDIV       ESI
    //         00553d43     MOV        EAX,0x91a2b3c5
    //         00553d48     POP        ESI
    //         00553d49     POP        EBX
    //         00553d4a     MOV        dword ptr [null_00888158],EDX                    = align(12)
    //         00553d50     IMUL       ECX
    //         00553d52     ADD        EDX,ECX
    //         00553d54     SAR        EDX,0xb
    //         00553d57     MOV        EAX,EDX
    //         00553d59     SHR        EAX,0x1f
    //         00553d5c     ADD        EDX,EAX
    //         00553d5e     MOV        EAX,0x88888889
    //         00553d63     MOV        dword ptr [null_00888148],EDX                    = align(28)
    //         00553d69     IMUL       EDX,EDX,-0xe10
    //         00553d6f     ADD        ECX,EDX
    //         00553d71     IMUL       ECX
    //         00553d73     ADD        EDX,ECX
    //         00553d75     SAR        EDX,0x5
    //         00553d78     MOV        EAX,EDX
    //         00553d7a     SHR        EAX,0x1f
    //         00553d7d     ADD        EDX,EAX
    //         00553d7f     MOV        dword ptr [null_00888144],EDX                    = align(32)
    //         00553d85     LEA        EAX,[EDX + EDX*0x2]
    //         00553d88     LEA        EDX,[EAX + EAX*0x4]
    //         00553d8b     MOV        EAX,null_00888140                                = align(36)
    //         00553d90     SHL        EDX,0x2
    //         00553d93     SUB        ECX,EDX
    //         00553d95     MOV        dword ptr [null_00888140],ECX                    = align(36)
    //         00553d9b     RET
}

// Offset: 0x00553DA0
undefined loctotime_t() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined ___loctotime_t()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[1]:     00553dea(W)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00553dee(W)  
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[1]:     00553e34(W)  
    //              undefined4        Stack[-0x1c]:4 local_1c                  XREF[1]:     00553e08(W)  
    //              undefined         Stack[-0x24]:1 local_24                  XREF[1]:     00553e56(*)  
    //                               ___loctotime_t                                               XREF[2]:     time:0054c060(c), 
    //                                                                                                         ___timet_from_ft:0054c589(c)  
    //         00553da0     SUB        ESP,0x24
    //         00553da3     PUSH       EBX
    //         00553da4     MOV        EBX,dword ptr [ESP + Stack[0x4]]
    //         00553da8     SUB        EBX,0x76c
    //         00553dae     PUSH       EBP
    //         00553daf     PUSH       ESI
    //         00553db0     CMP        EBX,0x46
    //         00553db3     PUSH       EDI
    //         00553db4     JL         LAB_00553e77
    //         00553dba     CMP        EBX,0x8a
    //         00553dc0     JG         LAB_00553e77
    //         00553dc6     MOV        EDI,dword ptr [ESP + Stack[0x8]]
    //         00553dca     MOV        ECX,dword ptr [ESP + Stack[0xc]]
    //         00553dce     MOV        ESI,dword ptr [EDI*0x4 + DAT_0059241c]
    //         00553dd5     ADD        ESI,ECX
    //         00553dd7     TEST       BL,0x3
    //         00553dda     JNZ        LAB_00553de2
    //         00553ddc     CMP        EDI,0x2
    //         00553ddf     JLE        LAB_00553de2
    //         00553de1     INC        ESI
    //                               LAB_00553de2                                                 XREF[2]:     00553dda(j), 00553ddf(j)  
    //         00553de2     CALL       ___tzset                                         undefined ___tzset()
    //         00553de7     LEA        EAX,[EBX + EBX*0x8]
    //         00553dea     MOV        dword ptr [ESP + local_8],ESI
    //         00553dee     MOV        dword ptr [ESP + local_10],EBX
    //         00553df2     LEA        ECX,[EBX + EAX*0x8]
    //         00553df5     LEA        EAX,[EBX + -0x1]
    //         00553df8     MOV        EDX,ECX
    //         00553dfa     ADD        EDX,ESI
    //         00553dfc     SAR        EAX,0x2
    //         00553dff     LEA        ECX,[EDX + ECX*0x4]
    //         00553e02     ADD        EAX,ECX
    //         00553e04     MOV        ECX,dword ptr [ESP + Stack[0x10]]
    //         00553e08     MOV        dword ptr [ESP + local_1c],ECX
    //         00553e0c     LEA        EDX,[EAX + EAX*0x2]
    //         00553e0f     LEA        EAX,[ECX + EDX*0x8]
    //         00553e12     MOV        EDX,EAX
    //         00553e14     SHL        EDX,0x4
    //         00553e17     SUB        EDX,EAX
    //         00553e19     MOV        EAX,dword ptr [ESP + Stack[0x14]]
    //         00553e1d     LEA        EAX,[EAX + EDX*0x4]
    //         00553e20     MOV        EDX,EAX
    //         00553e22     SHL        EDX,0x4
    //         00553e25     SUB        EDX,EAX
    //         00553e27     MOV        EAX,dword ptr [ESP + Stack[0x18]]
    //         00553e2b     DEC        EDI
    //         00553e2c     LEA        EDX,[EAX + EDX*0x4]
    //         00553e2f     MOV        EAX,[__timezone]                                 = 00007080h
    //         00553e34     MOV        dword ptr [ESP + local_14],EDI
    //         00553e38     LEA        EBP,[EDX + EAX*0x1 + 0x7c558180]
    //         00553e3f     MOV        EAX,dword ptr [ESP + Stack[0x1c]]
    //         00553e43     CMP        EAX,0x1
    //         00553e46     JZ         LAB_00553e67
    //         00553e48     CMP        EAX,-0x1
    //         00553e4b     JNZ        LAB_00553e6d
    //         00553e4d     MOV        EAX,[__daylight]                                 = 00000001h
    //         00553e52     TEST       EAX,EAX
    //         00553e54     JZ         LAB_00553e6d
    //         00553e56     LEA        ECX=>local_24,[ESP + 0x10]
    //         00553e5a     PUSH       ECX
    //         00553e5b     CALL       __isindst                                        undefined __isindst()
    //         00553e60     ADD        ESP,0x4
    //         00553e63     TEST       EAX,EAX
    //         00553e65     JZ         LAB_00553e6d
    //                               LAB_00553e67                                                 XREF[1]:     00553e46(j)  
    //         00553e67     ADD        EBP,dword ptr [__dstbias]                        = FFFFF1F0h
    //                               LAB_00553e6d                                                 XREF[3]:     00553e4b(j), 00553e54(j), 
    //                                                                                                         00553e65(j)  
    //         00553e6d     MOV        EAX,EBP
    //         00553e6f     POP        EDI
    //         00553e70     POP        ESI
    //         00553e71     POP        EBP
    //         00553e72     POP        EBX
    //         00553e73     ADD        ESP,0x24
    //         00553e76     RET
    //                               LAB_00553e77                                                 XREF[2]:     00553db4(j), 00553dc0(j)  
    //         00553e77     POP        EDI
    //         00553e78     POP        ESI
    //         00553e79     POP        EBP
    //         00553e7a     OR         EAX,0xffffffff
    //         00553e7d     POP        EBX
    //         00553e7e     ADD        ESP,0x24
    //         00553e81     RET
}

// Offset: 0x00553E90
undefined commit() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __commit()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __commit                                                     XREF[1]:     fflush:0054c0b2(c)  
    //         00553e90     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00553e94     MOV        ECX,dword ptr [__nhandle]
    //         00553e9a     CMP        EAX,ECX
    //         00553e9c     JNC        LAB_00553edd
    //         00553e9e     MOV        ECX,EAX
    //         00553ea0     MOV        EDX,EAX
    //         00553ea2     SAR        ECX,0x5
    //         00553ea5     AND        EDX,0x1f
    //         00553ea8     MOV        ECX,dword ptr [ECX*0x4 + ___pioinfo]
    //         00553eaf     TEST       byte ptr [ECX + EDX*0x8 + 0x4],0x1
    //         00553eb4     JZ         LAB_00553edd
    //         00553eb6     PUSH       EAX
    //         00553eb7     CALL       __get_osfhandle                                  undefined __get_osfhandle()
    //         00553ebc     ADD        ESP,0x4
    //         00553ebf     PUSH       EAX
    //         00553ec0     CALL       dword ptr [->KERNEL32.DLL::FlushFileBuffers]     = 0048b848
    //         00553ec6     TEST       EAX,EAX
    //         00553ec8     JNZ        LAB_00553ed2
    //         00553eca     CALL       dword ptr [->KERNEL32.DLL::GetLastError]         = 0048aa76
    //         00553ed0     JMP        LAB_00553ed4
    //                               LAB_00553ed2                                                 XREF[1]:     00553ec8(j)  
    //         00553ed2     XOR        EAX,EAX
    //                               LAB_00553ed4                                                 XREF[1]:     00553ed0(j)  
    //         00553ed4     TEST       EAX,EAX
    //         00553ed6     JZ         LAB_00553eea
    //         00553ed8     MOV        [__doserrno],EAX
    //                               LAB_00553edd                                                 XREF[2]:     00553e9c(j), 00553eb4(j)  
    //         00553edd     MOV        dword ptr [_errno],0x9                           = align(4)
    //         00553ee7     OR         EAX,0xffffffff
    //                               LAB_00553eea                                                 XREF[1]:     00553ed6(j)  
    //         00553eea     RET
}

// Offset: 0x00553EEB
undefined FUN_00553eeb() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00553eeb()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00553eeb
    //         00553eeb     NOP
    //         00553eec     NOP
    //         00553eed     NOP
    //         00553eee     NOP
    //         00553eef     NOP
    //                               ___initstdio
    //         00553ef0     MOV        EAX,[__nstream]
    //         00553ef5     PUSH       ESI
    //         00553ef6     TEST       EAX,EAX
    //         00553ef8     JNZ        LAB_00553f01
    //         00553efa     MOV        EAX,0x200
    //         00553eff     JMP        LAB_00553f0b
    //                               LAB_00553f01                                                 XREF[1]:     00553ef8(j)  
    //         00553f01     CMP        EAX,0x14
    //         00553f04     JGE        LAB_00553f10
    //         00553f06     MOV        EAX,0x14
    //                               LAB_00553f0b                                                 XREF[1]:     00553eff(j)  
    //         00553f0b     MOV        [__nstream],EAX
    //                               LAB_00553f10                                                 XREF[1]:     00553f04(j)  
    //         00553f10     PUSH       0x4
    //         00553f12     PUSH       EAX
    //         00553f13     CALL       calloc                                           undefined calloc()
    //         00553f18     ADD        ESP,0x8
    //         00553f1b     MOV        [___piob],EAX
    //         00553f20     TEST       EAX,EAX
    //         00553f22     JNZ        LAB_00553f52
    //         00553f24     PUSH       0x4
    //         00553f26     PUSH       0x14
    //         00553f28     MOV        dword ptr [__nstream],0x14
    //         00553f32     CALL       calloc                                           undefined calloc()
    //         00553f37     ADD        ESP,0x8
    //         00553f3a     MOV        [___piob],EAX
    //         00553f3f     TEST       EAX,EAX
    //         00553f41     JNZ        LAB_00553f52
    //         00553f43     PUSH       0x1a
    //         00553f45     CALL       __amsg_exit                                      undefined __amsg_exit()
    //         00553f4a     MOV        EAX,[___piob]
    //         00553f4f     ADD        ESP,0x4
    //                               LAB_00553f52                                                 XREF[2]:     00553f22(j), 00553f41(j)  
    //         00553f52     XOR        EDX,EDX
    //         00553f54     MOV        ECX,__iob                                        = align(1)
    //         00553f59     JMP        LAB_00553f60
    //                               LAB_00553f5b                                                 XREF[1]:     00553f6f(j)  
    //         00553f5b     MOV        EAX,[___piob]
    //                               LAB_00553f60                                                 XREF[1]:     00553f59(j)  
    //         00553f60     MOV        dword ptr [EAX + EDX*0x1],ECX=>__iob             = align(1)
    //         00553f63     ADD        ECX,0x20
    //         00553f66     ADD        EDX,0x4
    //         00553f69     CMP        ECX,___badioinfo                                 = FFh
    //         00553f6f     JL         LAB_00553f5b
    //         00553f71     XOR        EAX,EAX
    //         00553f73     MOV        EDX,DAT_00591e58
    //                               LAB_00553f78                                                 XREF[1]:     00553fa5(j)  
    //         00553f78     MOV        ECX,EAX
    //         00553f7a     MOV        ESI,EAX
    //         00553f7c     SAR        ECX,0x5
    //         00553f7f     AND        ESI,0x1f
    //         00553f82     MOV        ECX,dword ptr [ECX*0x4 + ___pioinfo]
    //         00553f89     MOV        ECX,dword ptr [ECX + ESI*0x8]
    //         00553f8c     CMP        ECX,-0x1
    //         00553f8f     JZ         LAB_00553f95
    //         00553f91     TEST       ECX,ECX
    //         00553f93     JNZ        LAB_00553f9b
    //                               LAB_00553f95                                                 XREF[1]:     00553f8f(j)  
    //         00553f95     MOV        dword ptr [EDX]=>DAT_00591e58,0xffffffff         = 00000001h
    //                               LAB_00553f9b                                                 XREF[1]:     00553f93(j)  
    //         00553f9b     ADD        EDX,0x20
    //         00553f9e     INC        EAX
    //         00553f9f     CMP        EDX,DAT_00591eb8
    //         00553fa5     JL         LAB_00553f78
    //         00553fa7     POP        ESI
    //         00553fa8     RET
}

// Offset: 0x00553FA9
undefined FUN_00553fa9() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00553fa9()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00553fa9
    //         00553fa9     NOP
    //         00553faa     NOP
    //         00553fab     NOP
    //         00553fac     NOP
    //         00553fad     NOP
    //         00553fae     NOP
    //         00553faf     NOP
    //                               ___endstdio
    //         00553fb0     CALL       __flushall                                       undefined __flushall()
    //         00553fb5     MOV        AL,[__exitflag]                                  = align(8)
    //         00553fba     TEST       AL,AL
    //         00553fbc     JZ         LAB_00553fc3
    //         00553fbe     JMP        __fcloseall
    //                               LAB_00553fc3                                                 XREF[1]:     00553fbc(j)  
    //         00553fc3     RET
}

// Offset: 0x00553FD0
undefined ioinit() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __ioinit()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined         Stack[-0x44]:1 local_44                  XREF[1]:     00554030(*)  
    //                               __ioinit                                                     XREF[1]:     entry:0054f8e1(c)  
    //         00553fd0     SUB        ESP,0x48
    //         00553fd3     PUSH       EBX
    //         00553fd4     PUSH       EBP
    //         00553fd5     PUSH       ESI
    //         00553fd6     PUSH       EDI
    //         00553fd7     PUSH       0x100
    //         00553fdc     CALL       malloc                                           undefined malloc()
    //         00553fe1     MOV        ESI,EAX
    //         00553fe3     ADD        ESP,0x4
    //         00553fe6     TEST       ESI,ESI
    //         00553fe8     JNZ        LAB_00553ff4
    //         00553fea     PUSH       0x1b
    //         00553fec     CALL       __amsg_exit                                      undefined __amsg_exit()
    //         00553ff1     ADD        ESP,0x4
    //                               LAB_00553ff4                                                 XREF[1]:     00553fe8(j)  
    //         00553ff4     LEA        EAX,[ESI + 0x100]
    //         00553ffa     MOV        dword ptr [___pioinfo],ESI
    //         00554000     CMP        ESI,EAX
    //         00554002     MOV        dword ptr [__nhandle],0x20
    //         0055400c     MOV        BL,0xa
    //         0055400e     JNC        LAB_00554030
    //                               LAB_00554010                                                 XREF[1]:     0055402e(j)  
    //         00554010     MOV        byte ptr [ESI + 0x4],0x0
    //         00554014     MOV        dword ptr [ESI],0xffffffff
    //         0055401a     MOV        byte ptr [ESI + 0x5],BL
    //         0055401d     MOV        ECX,dword ptr [___pioinfo]
    //         00554023     ADD        ESI,0x8
    //         00554026     ADD        ECX,0x100
    //         0055402c     CMP        ESI,ECX
    //         0055402e     JC         LAB_00554010
    //                               LAB_00554030                                                 XREF[1]:     0055400e(j)  
    //         00554030     LEA        EDX=>local_44,[ESP + 0x14]
    //         00554034     PUSH       EDX
    //         00554035     CALL       dword ptr [->KERNEL32.DLL::GetStartupInfoA]      = 0048b7ea
    //         0055403b     CMP        word ptr [ESP + 0x46],0x0
    //         00554041     JZ         LAB_00554139
    //         00554047     MOV        EAX,dword ptr [ESP + 0x48]
    //         0055404b     TEST       EAX,EAX
    //         0055404d     JZ         LAB_00554139
    //         00554053     MOV        ECX,dword ptr [EAX]
    //         00554055     LEA        EDI,[EAX + 0x4]
    //         00554058     CMP        ECX,0x800
    //         0055405e     MOV        dword ptr [ESP + 0x10],ECX
    //         00554062     LEA        EBP,[EDI + ECX*0x1]
    //         00554065     JL         LAB_0055406f
    //         00554067     MOV        dword ptr [ESP + 0x10],0x800
    //                               LAB_0055406f                                                 XREF[1]:     00554065(j)  
    //         0055406f     MOV        EAX,dword ptr [ESP + 0x10]
    //         00554073     MOV        ECX,dword ptr [__nhandle]
    //         00554079     CMP        ECX,EAX
    //         0055407b     JGE        LAB_005540e6
    //         0055407d     MOV        ESI,DAT_008884e4
    //                               LAB_00554082                                                 XREF[1]:     005540d8(j)  
    //         00554082     PUSH       0x100
    //         00554087     CALL       malloc                                           undefined malloc()
    //         0055408c     ADD        ESP,0x4
    //         0055408f     TEST       EAX,EAX
    //         00554091     JZ         LAB_005540dc
    //         00554093     MOV        ECX,dword ptr [__nhandle]
    //         00554099     MOV        dword ptr [ESI]=>DAT_008884e4,EAX
    //         0055409b     ADD        ECX,0x20
    //         0055409e     MOV        dword ptr [__nhandle],ECX
    //         005540a4     LEA        ECX,[EAX + 0x100]
    //         005540aa     CMP        EAX,ECX
    //         005540ac     JNC        LAB_005540ca
    //                               LAB_005540ae                                                 XREF[1]:     005540c8(j)  
    //         005540ae     MOV        byte ptr [EAX + 0x4],0x0
    //         005540b2     MOV        dword ptr [EAX],0xffffffff
    //         005540b8     MOV        byte ptr [EAX + 0x5],BL
    //         005540bb     MOV        EDX,dword ptr [ESI]=>DAT_008884e4
    //         005540bd     ADD        EAX,0x8
    //         005540c0     ADD        EDX,0x100
    //         005540c6     CMP        EAX,EDX
    //         005540c8     JC         LAB_005540ae
    //                               LAB_005540ca                                                 XREF[1]:     005540ac(j)  
    //         005540ca     MOV        EAX,[__nhandle]
    //         005540cf     MOV        ECX,dword ptr [ESP + 0x10]
    //         005540d3     ADD        ESI,0x4
    //         005540d6     CMP        EAX,ECX
    //         005540d8     JL         LAB_00554082
    //         005540da     JMP        LAB_005540e6
    //                               LAB_005540dc                                                 XREF[1]:     00554091(j)  
    //         005540dc     MOV        ECX,dword ptr [__nhandle]
    //         005540e2     MOV        dword ptr [ESP + 0x10],ECX
    //                               LAB_005540e6                                                 XREF[2]:     0055407b(j), 005540da(j)  
    //         005540e6     MOV        EAX,dword ptr [ESP + 0x10]
    //         005540ea     XOR        ESI,ESI
    //         005540ec     TEST       EAX,EAX
    //         005540ee     JLE        LAB_00554139
    //                               LAB_005540f0                                                 XREF[1]:     00554137(j)  
    //         005540f0     MOV        ECX,dword ptr [EBP]
    //         005540f3     CMP        ECX,-0x1
    //         005540f6     JZ         LAB_0055412c
    //         005540f8     MOV        AL,byte ptr [EDI]
    //         005540fa     TEST       AL,0x1
    //         005540fc     JZ         LAB_0055412c
    //         005540fe     TEST       AL,0x8
    //         00554100     JNZ        LAB_0055410d
    //         00554102     PUSH       ECX
    //         00554103     CALL       dword ptr [->KERNEL32.DLL::GetFileType]          = 0048b742
    //         00554109     TEST       EAX,EAX
    //         0055410b     JZ         LAB_0055412c
    //                               LAB_0055410d                                                 XREF[1]:     00554100(j)  
    //         0055410d     MOV        EDX,ESI
    //         0055410f     MOV        EAX,ESI
    //         00554111     SAR        EDX,0x5
    //         00554114     AND        EAX,0x1f
    //         00554117     MOV        ECX,dword ptr [EDX*0x4 + ___pioinfo]
    //         0055411e     MOV        EDX,dword ptr [EBP]
    //         00554121     MOV        dword ptr [ECX + EAX*0x8],EDX
    //         00554124     LEA        EAX,[ECX + EAX*0x8]
    //         00554127     MOV        CL,byte ptr [EDI]
    //         00554129     MOV        byte ptr [EAX + 0x4],CL
    //                               LAB_0055412c                                                 XREF[3]:     005540f6(j), 005540fc(j), 
    //                                                                                                         0055410b(j)  
    //         0055412c     MOV        EAX,dword ptr [ESP + 0x10]
    //         00554130     INC        ESI
    //         00554131     INC        EDI
    //         00554132     ADD        EBP,0x4
    //         00554135     CMP        ESI,EAX
    //         00554137     JL         LAB_005540f0
    //                               LAB_00554139                                                 XREF[3]:     00554041(j), 0055404d(j), 
    //                                                                                                         005540ee(j)  
    //         00554139     MOV        EBP,dword ptr [->KERNEL32.DLL::GetStdHandle]     = 0048b86e
    //         0055413f     XOR        EBX,EBX
    //                               LAB_00554141                                                 XREF[1]:     005541b2(j)  
    //         00554141     MOV        EDX,dword ptr [___pioinfo]
    //         00554147     MOV        EAX,dword ptr [EDX + EBX*0x8]
    //         0055414a     LEA        ESI,[EDX + EBX*0x8]
    //         0055414d     CMP        EAX,-0x1
    //         00554150     JNZ        LAB_005541a6
    //         00554152     TEST       EBX,EBX
    //                              language.dll match for 0x81: "10"
    //         00554154     MOV        byte ptr [ESI + 0x4],0x81
    //         00554158     JNZ        LAB_00554161
    //         0055415a     MOV        EAX,0xfffffff6
    //         0055415f     JMP        LAB_0055416b
    //                               LAB_00554161                                                 XREF[1]:     00554158(j)  
    //         00554161     MOV        EAX,EBX
    //         00554163     DEC        EAX
    //         00554164     NEG        EAX
    //         00554166     SBB        EAX,EAX
    //         00554168     ADD        EAX,-0xb
    //                               LAB_0055416b                                                 XREF[1]:     0055415f(j)  
    //         0055416b     PUSH       EAX=>DAT_fffffff6
    //         0055416c     CALL       EBP=>KERNEL32.DLL::GetStdHandle
    //         0055416e     MOV        EDI,EAX
    //         00554170     CMP        EDI,-0x1
    //         00554173     JZ         LAB_0055419f
    //         00554175     PUSH       EDI
    //         00554176     CALL       dword ptr [->KERNEL32.DLL::GetFileType]          = 0048b742
    //         0055417c     TEST       EAX,EAX
    //         0055417e     JZ         LAB_0055419f
    //         00554180     AND        EAX,0xff
    //         00554185     MOV        dword ptr [ESI],EDI
    //         00554187     CMP        EAX,0x2
    //         0055418a     JNZ        LAB_00554193
    //         0055418c     MOV        AL,byte ptr [ESI + 0x4]
    //         0055418f     OR         AL,0x40
    //         00554191     JMP        LAB_005541ab
    //                               LAB_00554193                                                 XREF[1]:     0055418a(j)  
    //         00554193     CMP        EAX,0x3
    //         00554196     JNZ        LAB_005541ae
    //         00554198     MOV        AL,byte ptr [ESI + 0x4]
    //         0055419b     OR         AL,0x8
    //         0055419d     JMP        LAB_005541ab
    //                               LAB_0055419f                                                 XREF[2]:     00554173(j), 0055417e(j)  
    //         0055419f     MOV        AL,byte ptr [ESI + 0x4]
    //         005541a2     OR         AL,0x40
    //         005541a4     JMP        LAB_005541ab
    //                               LAB_005541a6                                                 XREF[1]:     00554150(j)  
    //         005541a6     MOV        AL,byte ptr [ESI + 0x4]
    //         005541a9     OR         AL,0x80
    //                               LAB_005541ab                                                 XREF[3]:     00554191(j), 0055419d(j), 
    //                                                                                                         005541a4(j)  
    //         005541ab     MOV        byte ptr [ESI + 0x4],AL
    //                               LAB_005541ae                                                 XREF[1]:     00554196(j)  
    //         005541ae     INC        EBX
    //         005541af     CMP        EBX,0x3
    //         005541b2     JL         LAB_00554141
    //         005541b4     MOV        EAX,[__nhandle]
    //         005541b9     PUSH       EAX
    //         005541ba     CALL       dword ptr [->KERNEL32.DLL::SetHandleCount]       = 0048b85c
    //         005541c0     POP        EDI
    //         005541c1     POP        ESI
    //         005541c2     POP        EBP
    //         005541c3     POP        EBX
    //         005541c4     ADD        ESP,0x48
    //         005541c7     RET
}

