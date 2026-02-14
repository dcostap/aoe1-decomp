// Auto-generated scaffold unit: bucket_056D.asm
#include "../include/common.h"

// Offset: 0x0056D078
undefined FUN_0056d078() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056d078()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056d078
    //         0056d078     MOV        EAX,EAX
    //         0056d07b     MOV        EAX,EAX
    //         0056d07e     MOV        EAX,EAX
    //         0056d080     MOV        AL,byte ptr [ESI]
    //         0056d082     CALL       FUN_0056db60                                     undefined FUN_0056db60()
    //         0056d087     ADD        EDI,ECX
    //         0056d089     JMP        LAB_0056cc20
}

// Offset: 0x0056D08E
undefined FUN_0056d08e() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056d08e()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056d08e
    //         0056d08e     MOV        EAX,EAX
    //         0056d091     MOV        EAX,EAX
    //         0056d094     MOV        EAX,EAX
    //         0056d097     MOV        EAX,EAX
    //         0056d09a     MOV        EAX,EAX
    //         0056d09d     MOV        EAX,EAX
    //                               LAB_0056d0a0                                                 XREF[4]:     _ASMDraw_Sprite:0056cb86(j), 
    //                                                                                                         FUN_0056d127:0056d145(j), 
    //                                                                                                         FUN_0056d127:0056d153(j), 
    //                                                                                                         FUN_0056d2a4:0056d2c9(j)  
    //         0056d0a0     XOR        EAX,EAX
    //         0056d0a2     MOV        AL,byte ptr [ESI]
    //         0056d0a4     MOV        ECX,EAX
    //         0056d0a6     AND        EAX,0xf
    //         0056d0a9     INC        ESI
    //                               switchD_0056d0aa::switchD
    //         0056d0aa     JMP        dword ptr [EAX*0x4 + switchD_0056d0aa::switchd   = 0056d0e0
}

// Offset: 0x0056D0B1
undefined FUN_0056d0b1() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056d0b1()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056d0b1
    //         0056d0b1     MOV        EAX,EAX
    //         0056d0b4     MOV        EAX,EAX
    //         0056d0b7     MOV        EAX,EAX
    //         0056d0ba     MOV        EAX,EAX
    //         0056d0bd     MOV        EAX,EAX
    //                               switchD_0056d0aa::caseD_e                                    XREF[2]:     0056b478(*), 
    //                                                                                                         FUN_0056d08e:0056d0aa(j)  
    //         0056d0c0     MOV        EAX,ECX
    //         0056d0c2     SHR        EAX,0x4
    //         0056d0c5     JMP        dword ptr [EAX*0x4 + DAT_0056b4c0]               = CEh
}

// Offset: 0x0056D0CC
undefined FUN_0056d0cc() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056d0cc()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056d0cc
    //         0056d0cc     MOV        EAX,EAX
    //         0056d0cf     MOV        EAX,EAX
    //         0056d0d2     MOV        EAX,EAX
    //         0056d0d5     MOV        EAX,EAX
    //         0056d0d8     MOV        EAX,EAX
    //         0056d0db     MOV        EAX,EAX
    //         0056d0de     MOV        EAX,EAX
    //                               switchD_0056d0aa::caseD_4                                    XREF[5]:     0056b440(*), 0056b450(*), 
    //                               switchD_0056d0aa::caseD_8                                                 0056b460(*), 0056b470(*), 
    //                               switchD_0056d0aa::caseD_c                                                 FUN_0056d08e:0056d0aa(j)  
    //                               switchD_0056d0aa::caseD_0
    //         0056d0e0     SHR        ECX,0x2
    //         0056d0e3     MOV        EAX,EDI
    //         0056d0e5     AND        EAX,0x3
    //         0056d0e8     OR         AL,byte ptr [ECX + LAB_0056b2ff+1]
    //         0056d0ee     OR         AL,byte ptr [null_0088c048]                      = align(12)
    //         0056d0f4     JMP        dword ptr [EAX*0x4 + LAB_0056a300]
}

// Offset: 0x0056D0FB
undefined FUN_0056d0fb() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056d0fb()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056d0fb
    //         0056d0fb     MOV        EAX,EAX
    //         0056d0fe     MOV        EAX,EAX
    //                               switchD_0056d0aa::caseD_2                                    XREF[2]:     0056b448(*), 
    //                                                                                                         FUN_0056d08e:0056d0aa(j)  
    //         0056d100     SHL        ECX,0x4
    //         0056d103     XOR        EBX,EBX
    //         0056d105     MOV        CL,byte ptr [ESI]
    //         0056d107     SUB        BL,CH
    //         0056d109     MOV        EAX,EDI
    //         0056d10b     AND        BL,0x80
    //         0056d10e     AND        EAX,0x3
    //         0056d111     OR         BL,CL
    //         0056d113     OR         AL,byte ptr [null_0088c048]                      = align(12)
    //         0056d119     OR         AL,byte ptr [EBX + LAB_0056b2ff+1]
    //         0056d11f     INC        ESI
    //         0056d120     JMP        dword ptr [EAX*0x4 + LAB_0056a300]
}

// Offset: 0x0056D127
undefined FUN_0056d127() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056d127()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056d127
    //         0056d127     MOV        EAX,EAX
    //         0056d12a     MOV        EAX,EAX
    //         0056d12d     MOV        EAX,EAX
    //         0056d130     MOV        EAX,EAX
    //         0056d133     MOV        EAX,EAX
    //         0056d136     MOV        EAX,EAX
    //         0056d139     MOV        EAX,EAX
    //         0056d13c     MOV        EAX,EAX
    //         0056d13f     NOP
    //                               switchD_0056d0aa::caseD_5                                    XREF[5]:     0056b444(*), 0056b454(*), 
    //                               switchD_0056d0aa::caseD_9                                                 0056b464(*), 0056b474(*), 
    //                               switchD_0056d0aa::caseD_d                                                 FUN_0056d08e:0056d0aa(j)  
    //                               switchD_0056d0aa::caseD_1
    //         0056d140     SHR        ECX,0x2
    //         0056d143     ADD        EDI,ECX
    //         0056d145     JMP        dword ptr [DAT_0088c044]
    //                               switchD_0056d0aa::caseD_3                                    XREF[2]:     0056b44c(*), 
    //                                                                                                         FUN_0056d08e:0056d0aa(j)  
    //         0056d14b     SHL        ECX,0x4
    //         0056d14e     MOV        CL,byte ptr [ESI]
    //         0056d150     INC        ESI
    //         0056d151     ADD        EDI,ECX
    //         0056d153     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x0056D159
undefined FUN_0056d159() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056d159()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056d159
    //         0056d159     MOV        EAX,EAX
    //         0056d15c     MOV        EAX,EAX
    //         0056d15f     NOP
    //                               switchD_0056d0aa::caseD_6                                    XREF[2]:     0056b458(*), 
    //                                                                                                         FUN_0056d08e:0056d0aa(j)  
    //         0056d160     SHR        ECX,0x4
    //         0056d163     JNZ        LAB_0056d168
    //         0056d165     MOV        CL,byte ptr [ESI]
    //         0056d167     INC        ESI
    //                               LAB_0056d168                                                 XREF[1]:     0056d163(j)  
    //         0056d168     MOV        EAX,EDI
    //         0056d16a     AND        EAX,0x3
    //         0056d16d     OR         AL,byte ptr [ECX + LAB_0056b2ff+1]
    //         0056d173     MOV        EBX,dword ptr [DAT_0088c040]
    //         0056d179     OR         AL,byte ptr [null_0088c048]                      = align(12)
    //         0056d17f     JMP        dword ptr [EAX*0x4 + LAB_0056aaff+1]
}

// Offset: 0x0056D186
undefined FUN_0056d186() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056d186()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056d186
    //         0056d186     MOV        EAX,EAX
    //         0056d189     MOV        EAX,EAX
    //         0056d18c     MOV        EAX,EAX
    //         0056d18f     MOV        EAX,EAX
    //         0056d192     MOV        EAX,EAX
    //         0056d195     MOV        EAX,EAX
    //         0056d198     MOV        EAX,EAX
    //         0056d19b     MOV        EAX,EAX
    //         0056d19e     MOV        EAX,EAX
    //                               switchD_0056d0aa::caseD_7                                    XREF[2]:     0056b45c(*), 
    //                                                                                                         FUN_0056d08e:0056d0aa(j)  
    //         0056d1a0     SHR        ECX,0x4
    //         0056d1a3     JNZ        LAB_0056d1a8
    //         0056d1a5     MOV        CL,byte ptr [ESI]
    //         0056d1a7     INC        ESI
    //                               LAB_0056d1a8                                                 XREF[1]:     0056d1a3(j)  
    //         0056d1a8     MOV        AL,byte ptr [ESI]
    //         0056d1aa     MOV        EBX,EDI
    //         0056d1ac     MOV        AH,AL
    //         0056d1ae     AND        EBX,0x3
    //         0056d1b1     SHL        EAX,0x10
    //         0056d1b4     OR         BL,byte ptr [ECX + LAB_0056b2ff+1]
    //         0056d1ba     MOV        AL,byte ptr [ESI]
    //         0056d1bc     OR         BL,byte ptr [null_0088c048]                      = align(12)
    //         0056d1c2     INC        ESI
    //         0056d1c3     MOV        AH,AL
    //         0056d1c5     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056d1cb     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         0056d1d1     JMP        dword ptr [EBX*0x4 + LAB_0056a6ff+1]
}

// Offset: 0x0056D1D8
undefined FUN_0056d1d8() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056d1d8()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056d1d8
    //         0056d1d8     MOV        EAX,EAX
    //         0056d1db     MOV        EAX,EAX
    //         0056d1de     MOV        EAX,EAX
    //                               switchD_0056d0aa::caseD_a                                    XREF[2]:     0056b468(*), 
    //                                                                                                         FUN_0056d08e:0056d0aa(j)  
    //         0056d1e0     SHR        ECX,0x4
    //         0056d1e3     JNZ        LAB_0056d1e8
    //         0056d1e5     MOV        CL,byte ptr [ESI]
    //         0056d1e7     INC        ESI
    //                               LAB_0056d1e8                                                 XREF[1]:     0056d1e3(j)  
    //         0056d1e8     MOV        AL,byte ptr [ESI]
    //         0056d1ea     MOV        EBX,EDI
    //         0056d1ec     MOV        AH,AL
    //         0056d1ee     AND        EBX,0x3
    //         0056d1f1     SHL        EAX,0x10
    //         0056d1f4     OR         BL,byte ptr [ECX + LAB_0056b2ff+1]
    //         0056d1fa     MOV        AL,byte ptr [ESI]
    //         0056d1fc     OR         BL,byte ptr [null_0088c048]                      = align(12)
    //         0056d202     INC        ESI
    //         0056d203     MOV        AH,AL
    //         0056d205     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056d20b     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         0056d211     JMP        dword ptr [EBX*0x4 + LAB_0056a6ff+1]
}

// Offset: 0x0056D218
undefined FUN_0056d218() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056d218()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056d218
    //         0056d218     MOV        EAX,EAX
    //         0056d21b     MOV        EAX,EAX
    //         0056d21e     MOV        EAX,EAX
    //                               switchD_0056d0aa::caseD_b                                    XREF[2]:     0056b46c(*), 
    //                                                                                                         FUN_0056d08e:0056d0aa(j)  
    //         0056d220     SHR        ECX,0x4
    //         0056d223     JNZ        LAB_0056d228
    //         0056d225     MOV        CL,byte ptr [ESI]
    //         0056d227     INC        ESI
    //                               LAB_0056d228                                                 XREF[1]:     0056d223(j)  
    //         0056d228     MOV        EAX,EDI
    //         0056d22a     AND        EAX,0x3
    //         0056d22d     OR         AL,byte ptr [ECX + LAB_0056b2ff+1]
    //         0056d233     MOV        EBX,dword ptr [DAT_0088c01c]
    //         0056d239     OR         AL,byte ptr [null_0088c048]                      = align(12)
    //         0056d23f     XOR        EDX,EDX
    //         0056d241     JMP        dword ptr [EAX*0x4 + LAB_0056aeff+1]
}

// Offset: 0x0056D248
undefined FUN_0056d248() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056d248()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056d248
    //         0056d248     MOV        EAX,EAX
    //         0056d24b     MOV        EAX,EAX
    //         0056d24e     MOV        EAX,EAX
    //         0056d251     MOV        EAX,EAX
    //         0056d254     MOV        EAX,EAX
    //         0056d257     MOV        EAX,EAX
    //         0056d25a     MOV        EAX,EAX
    //         0056d25d     MOV        EAX,EAX
    //         0056d260     MOV        CL,byte ptr [ESI]
    //         0056d262     INC        ESI
    //         0056d263     JMP        LAB_0056d26a
}

// Offset: 0x0056D265
undefined FUN_0056d265() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056d265()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056d265
    //         0056d265     MOV        ECX,0x1
    //                               LAB_0056d26a                                                 XREF[1]:     FUN_0056d248:0056d263(j)  
    //         0056d26a     CMP        dword ptr [DAT_0088c058],0x0                     = align(40)
    //         0056d271     JZ         LAB_0056d29c
    //         0056d273     MOV        EAX,[null_0088c05c]                              = align(36)
    //         0056d278     MOV        EBX,EDI
    //         0056d27a     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056d280     AND        EBX,0x3
    //         0056d283     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         0056d289     OR         BL,byte ptr [ECX + 0x56b300]
    //         0056d28f     OR         BL,byte ptr [null_0088c048]                      = align(12)
    //         0056d295     JMP        dword ptr [EBX*0x4 + 0x56a700]
    //                               LAB_0056d29c                                                 XREF[1]:     0056d271(j)  
    //         0056d29c     ADD        EDI,ECX
    //         0056d29e     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x0056D2A4
undefined FUN_0056d2a4() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056d2a4()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056d2a4
    //         0056d2a4     MOV        EAX,EAX
    //         0056d2a7     MOV        EAX,EAX
    //         0056d2aa     MOV        EAX,EAX
    //         0056d2ad     MOV        EAX,EAX
    //         0056d2b0     MOV        EAX,EAX
    //         0056d2b3     MOV        EAX,EAX
    //         0056d2b6     MOV        EAX,EAX
    //         0056d2b9     MOV        EAX,EAX
    //         0056d2bc     MOV        EAX,EAX
    //         0056d2bf     NOP
    //         0056d2c0     MOV        AL,byte ptr [ESI]
    //         0056d2c2     CALL       FUN_0056db60                                     undefined FUN_0056db60()
    //         0056d2c7     ADD        EDI,ECX
    //         0056d2c9     JMP        LAB_0056d0a0
}

// Offset: 0x0056D2E0
undefined caseD_f() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined caseD_f()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               switchD_0056cbfc::caseD_f                                    XREF[16]:    0056b43c(*), 0056b47c(*), 
    //                               switchD_0056cc42::caseD_f                                                 _ASMDraw_Sprite:0056cab6(j), 
    //                               switchD_0056d0aa::caseD_f                                                 _ASMDraw_Sprite:0056cb0d(j), 
    //                                                                                                         _ASMDraw_Sprite:0056cb50(j), 
    //                                                                                                         _ASMDraw_Sprite:0056cb61(c), 
    //                                                                                                         FUN_0056cbac:0056cbd6(j), 
    //                                                                                                         FUN_0056cbac:0056cbfc(j), 
    //                                                                                                         FUN_0056cc03:0056cc42(j), 
    //                                                                                                         FUN_0056cc6c:0056cd07(c), 
    //                                                                                                         FUN_0056cd45:0056cde1(c), 
    //                                                                                                         FUN_0056cde6:0056ce94(c), 
    //                                                                                                         FUN_0056ce99:0056cf34(c), 
    //                                                                                                         FUN_0056cf39:0056cfbf(c), 
    //                                                                                                         FUN_0056cfc4:0056d073(c), 
    //                                                                                                         FUN_0056d08e:0056d0aa(j)  
    //         0056d2e0     MOV        EAX,[DAT_0088c038]
    //         0056d2e5     INC        EAX
    //         0056d2e6     MOV        [DAT_0088c038],EAX
    //         0056d2eb     CMP        EAX,dword ptr [EBP + 0x18]
    //         0056d2ee     JL         LAB_0056caa0
    //                               LAB_0056d2f4                                                 XREF[4]:     _ASMDraw_Sprite:0056c9b8(j), 
    //                                                                                                         _ASMDraw_Sprite:0056c9c4(j), 
    //                                                                                                         _ASMDraw_Sprite:0056ca0d(j), 
    //                                                                                                         _ASMDraw_Sprite:0056ca22(j)  
    //         0056d2f4     POP        EDI
    //         0056d2f5     POP        ESI
    //         0056d2f6     POP        EBX
    //         0056d2f7     POP        EBP
    //         0056d2f8     RET
}

// Offset: 0x0056D2F9
undefined FUN_0056d2f9() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056d2f9()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056d2f9
    //         0056d2f9     MOV        EAX,EAX
    //         0056d2fc     MOV        EAX,EAX
    //         0056d2ff     NOP
    //                               LAB_0056d300                                                 XREF[2]:     _ASMDraw_Sprite:0056ca7c(j), 
    //                                                                                                         FUN_0056db2e:0056db4e(j)  
    //         0056d300     MOV        EAX,dword ptr [EBP + 0x10]
    //         0056d303     MOV        EBX,dword ptr [DAT_0088c038]
    //         0056d309     ADD        EAX,EBX
    //         0056d30b     MOV        ESI,dword ptr [DAT_0088c008]
    //         0056d311     MOV        EDI,dword ptr [ESI + EAX*0x4]
    //         0056d314     OR         EDI,EDI
    //         0056d316     JZ         switchD_0056d42a::caseD_f
    //         0056d31c     MOV        dword ptr [DAT_0088c03c],EDI
    //         0056d322     TEST       byte ptr [null_0088c048],0x80                    = align(12)
    //         0056d329     JZ         LAB_0056d356
    //         0056d32b     AND        EAX,0x3
    //         0056d32e     MOV        EDX,dword ptr [EAX*0x4 + null_0088c070]          = align(16)
    //         0056d335     MOV        ECX,dword ptr [EAX*0x4 + null_0088c060]          = align(32)
    //         0056d33c     MOV        EAX,[DAT_0088c040]
    //         0056d341     MOV        dword ptr [null_0088c030],EDX                    = align(8)
    //         0056d347     MOV        dword ptr [DAT_0088c02c],ECX                     = align(12)
    //         0056d34d     AND        EAX,ECX
    //         0056d34f     OR         EAX,EDX
    //         0056d351     MOV        [null_0088c034],EAX                              = align(4)
    //                               LAB_0056d356                                                 XREF[1]:     0056d329(j)  
    //         0056d356     MOV        ESI,dword ptr [DAT_0088c010]
    //         0056d35c     XOR        EAX,EAX
    //         0056d35e     MOV        AX,word ptr [ESI + EBX*0x4 + 0x2]
    //         0056d363     MOV        EDX,dword ptr [DAT_0088c024]
    //         0056d369     TEST       EAX,0x8000
    //         0056d36e     JNZ        switchD_0056d42a::caseD_f
    //         0056d374     ADD        EDX,EAX
    //         0056d376     MOV        AX,word ptr [ESI + EBX*0x4]
    //         0056d37a     MOV        ECX,dword ptr [DAT_0088c028]
    //         0056d380     SUB        ECX,EAX
    //         0056d382     MOV        ESI,dword ptr [DAT_0088c000]
    //         0056d388     MOV        EAX,dword ptr [EBP + 0x10]
    //         0056d38b     ADD        EAX,EBX
    //         0056d38d     MOV        EAX,dword ptr [ESI + EAX*0x4]
    //         0056d390     MOV        [DAT_0088c020],EAX                               = align(4)
    //         0056d395     ADD        EAX,ECX
    //         0056d397     MOV        [DAT_0088c014],EAX
    //         0056d39c     MOV        ESI,dword ptr [DAT_0088c00c]
    //         0056d3a2     MOV        EAX,dword ptr [ESI + EBX*0x4]
    //         0056d3a5     ADD        EAX,dword ptr [EBP + 0x8]
    //         0056d3a8     MOV        [DAT_0088c018],EAX
    //                               LAB_0056d3ad                                                 XREF[1]:     0056d3c0(j)  
    //         0056d3ad     CMP        EDX,dword ptr [EDI + 0xc]
    //         0056d3b0     JG         switchD_0056d42a::caseD_f
    //         0056d3b6     CMP        ECX,dword ptr [EDI + 0x8]
    //         0056d3b9     JGE        LAB_0056d3c7
    //         0056d3bb     MOV        EDI,dword ptr [EDI + 0x4]
    //         0056d3be     OR         EDI,EDI
    //         0056d3c0     JNZ        LAB_0056d3ad
    //         0056d3c2     JMP        switchD_0056d42a::caseD_f
    //                               LAB_0056d3c7                                                 XREF[1]:     0056d3b9(j)  
    //         0056d3c7     CMP        EDX,dword ptr [EDI + 0x8]
    //         0056d3ca     JL         LAB_0056d3e9
    //         0056d3cc     CMP        ECX,dword ptr [EDI + 0xc]
    //         0056d3cf     JG         LAB_0056d3e9
    //         0056d3d1     MOV        EAX,0x56d420
    //         0056d3d6     MOV        [DAT_0088c044],EAX                               = align(16)
    //         0056d3db     MOV        EDI,dword ptr [DAT_0088c014]
    //         0056d3e1     MOV        ESI,dword ptr [DAT_0088c018]
    //         0056d3e7     JMP        LAB_0056d420
    //                               LAB_0056d3e9                                                 XREF[2]:     0056d3ca(j), 0056d3cf(j)  
    //         0056d3e9     MOV        EAX,0x56d6c0
    //         0056d3ee     MOV        [DAT_0088c044],EAX                               = align(16)
    //         0056d3f3     MOV        dword ptr [DAT_0088c03c],EDI
    //         0056d3f9     MOV        EDI,dword ptr [DAT_0088c014]
    //         0056d3ff     MOV        ESI,dword ptr [DAT_0088c018]
    //         0056d405     JMP        LAB_0056d6c0
}

// Offset: 0x0056D40A
undefined FUN_0056d40a() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056d40a()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056d40a
    //         0056d40a     MOV        EAX,EAX
    //         0056d40d     MOV        EAX,EAX
    //         0056d410     MOV        EAX,EAX
    //         0056d413     MOV        EAX,EAX
    //         0056d416     MOV        EAX,EAX
    //         0056d419     MOV        EAX,EAX
    //         0056d41c     MOV        EAX,EAX
    //         0056d41f     NOP
    //                               LAB_0056d420                                                 XREF[4]:     FUN_0056d2f9:0056d3e7(j), 
    //                                                                                                         FUN_0056d4a7:0056d4c5(j), 
    //                                                                                                         FUN_0056d4a7:0056d4d3(j), 
    //                                                                                                         FUN_0056d624:0056d649(j)  
    //         0056d420     XOR        EAX,EAX
    //         0056d422     MOV        AL,byte ptr [ESI]
    //         0056d424     MOV        ECX,EAX
    //         0056d426     AND        EAX,0xf
    //         0056d429     INC        ESI
    //                               switchD_0056d42a::switchD
    //         0056d42a     JMP        dword ptr [EAX*0x4 + switchD_0056d42a::switchd   = 0056d460
}

// Offset: 0x0056D431
undefined FUN_0056d431() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056d431()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056d431
    //         0056d431     MOV        EAX,EAX
    //         0056d434     MOV        EAX,EAX
    //         0056d437     MOV        EAX,EAX
    //         0056d43a     MOV        EAX,EAX
    //         0056d43d     MOV        EAX,EAX
    //                               switchD_0056d42a::caseD_e                                    XREF[2]:     0056b578(*), 
    //                                                                                                         FUN_0056d40a:0056d42a(j)  
    //         0056d440     MOV        EAX,ECX
    //         0056d442     SHR        EAX,0x4
    //         0056d445     JMP        dword ptr [EAX*0x4 + DAT_0056b5c0]               = CEh
}

// Offset: 0x0056D44C
undefined FUN_0056d44c() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056d44c()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056d44c
    //         0056d44c     MOV        EAX,EAX
    //         0056d44f     MOV        EAX,EAX
    //         0056d452     MOV        EAX,EAX
    //         0056d455     MOV        EAX,EAX
    //         0056d458     MOV        EAX,EAX
    //         0056d45b     MOV        EAX,EAX
    //         0056d45e     MOV        EAX,EAX
    //                               switchD_0056d42a::caseD_4                                    XREF[5]:     0056b540(*), 0056b550(*), 
    //                               switchD_0056d42a::caseD_8                                                 0056b560(*), 0056b570(*), 
    //                               switchD_0056d42a::caseD_c                                                 FUN_0056d40a:0056d42a(j)  
    //                               switchD_0056d42a::caseD_0
    //         0056d460     SHR        ECX,0x2
    //         0056d463     MOV        EAX,EDI
    //         0056d465     AND        EAX,0x3
    //         0056d468     OR         AL,byte ptr [ECX + LAB_0056b2ff+1]
    //         0056d46e     OR         AL,byte ptr [null_0088c048]                      = align(12)
    //         0056d474     JMP        dword ptr [EAX*0x4 + DAT_0056b600]
}

// Offset: 0x0056D47B
undefined FUN_0056d47b() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056d47b()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056d47b
    //         0056d47b     MOV        EAX,EAX
    //         0056d47e     MOV        EAX,EAX
    //                               switchD_0056d42a::caseD_2                                    XREF[2]:     0056b548(*), 
    //                                                                                                         FUN_0056d40a:0056d42a(j)  
    //         0056d480     SHL        ECX,0x4
    //         0056d483     XOR        EBX,EBX
    //         0056d485     MOV        CL,byte ptr [ESI]
    //         0056d487     SUB        BL,CH
    //         0056d489     MOV        EAX,EDI
    //         0056d48b     AND        BL,0x80
    //         0056d48e     AND        EAX,0x3
    //         0056d491     OR         BL,CL
    //         0056d493     OR         AL,byte ptr [null_0088c048]                      = align(12)
    //         0056d499     OR         AL,byte ptr [EBX + LAB_0056b2ff+1]
    //         0056d49f     INC        ESI
    //         0056d4a0     JMP        dword ptr [EAX*0x4 + DAT_0056b600]
}

// Offset: 0x0056D4A7
undefined FUN_0056d4a7() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056d4a7()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056d4a7
    //         0056d4a7     MOV        EAX,EAX
    //         0056d4aa     MOV        EAX,EAX
    //         0056d4ad     MOV        EAX,EAX
    //         0056d4b0     MOV        EAX,EAX
    //         0056d4b3     MOV        EAX,EAX
    //         0056d4b6     MOV        EAX,EAX
    //         0056d4b9     MOV        EAX,EAX
    //         0056d4bc     MOV        EAX,EAX
    //         0056d4bf     NOP
    //                               switchD_0056d42a::caseD_5                                    XREF[5]:     0056b544(*), 0056b554(*), 
    //                               switchD_0056d42a::caseD_9                                                 0056b564(*), 0056b574(*), 
    //                               switchD_0056d42a::caseD_d                                                 FUN_0056d40a:0056d42a(j)  
    //                               switchD_0056d42a::caseD_1
    //         0056d4c0     SHR        ECX,0x2
    //         0056d4c3     SUB        EDI,ECX
    //         0056d4c5     JMP        dword ptr [DAT_0088c044]
    //                               switchD_0056d42a::caseD_3                                    XREF[2]:     0056b54c(*), 
    //                                                                                                         FUN_0056d40a:0056d42a(j)  
    //         0056d4cb     SHL        ECX,0x4
    //         0056d4ce     MOV        CL,byte ptr [ESI]
    //         0056d4d0     INC        ESI
    //         0056d4d1     SUB        EDI,ECX
    //         0056d4d3     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x0056D4D9
undefined FUN_0056d4d9() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056d4d9()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056d4d9
    //         0056d4d9     MOV        EAX,EAX
    //         0056d4dc     MOV        EAX,EAX
    //         0056d4df     NOP
    //                               switchD_0056d42a::caseD_6                                    XREF[2]:     0056b558(*), 
    //                                                                                                         FUN_0056d40a:0056d42a(j)  
    //         0056d4e0     SHR        ECX,0x4
    //         0056d4e3     JNZ        LAB_0056d4e8
    //         0056d4e5     MOV        CL,byte ptr [ESI]
    //         0056d4e7     INC        ESI
    //                               LAB_0056d4e8                                                 XREF[1]:     0056d4e3(j)  
    //         0056d4e8     MOV        EAX,EDI
    //         0056d4ea     AND        EAX,0x3
    //         0056d4ed     OR         AL,byte ptr [ECX + LAB_0056b2ff+1]
    //         0056d4f3     MOV        EBX,dword ptr [DAT_0088c040]
    //         0056d4f9     OR         AL,byte ptr [null_0088c048]                      = align(12)
    //         0056d4ff     JMP        dword ptr [EAX*0x4 + DAT_0056be00]
}

// Offset: 0x0056D506
undefined FUN_0056d506() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056d506()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056d506
    //         0056d506     MOV        EAX,EAX
    //         0056d509     MOV        EAX,EAX
    //         0056d50c     MOV        EAX,EAX
    //         0056d50f     MOV        EAX,EAX
    //         0056d512     MOV        EAX,EAX
    //         0056d515     MOV        EAX,EAX
    //         0056d518     MOV        EAX,EAX
    //         0056d51b     MOV        EAX,EAX
    //         0056d51e     MOV        EAX,EAX
    //                               switchD_0056d42a::caseD_7                                    XREF[2]:     0056b55c(*), 
    //                                                                                                         FUN_0056d40a:0056d42a(j)  
    //         0056d520     SHR        ECX,0x4
    //         0056d523     JNZ        LAB_0056d528
    //         0056d525     MOV        CL,byte ptr [ESI]
    //         0056d527     INC        ESI
    //                               LAB_0056d528                                                 XREF[1]:     0056d523(j)  
    //         0056d528     MOV        AL,byte ptr [ESI]
    //         0056d52a     MOV        EBX,EDI
    //         0056d52c     MOV        AH,AL
    //         0056d52e     AND        EBX,0x3
    //         0056d531     SHL        EAX,0x10
    //         0056d534     OR         BL,byte ptr [ECX + LAB_0056b2ff+1]
    //         0056d53a     MOV        AL,byte ptr [ESI]
    //         0056d53c     OR         BL,byte ptr [null_0088c048]                      = align(12)
    //         0056d542     INC        ESI
    //         0056d543     MOV        AH,AL
    //         0056d545     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056d54b     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         0056d551     JMP        dword ptr [EBX*0x4 + DAT_0056ba00]
}

// Offset: 0x0056D558
undefined FUN_0056d558() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056d558()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056d558
    //         0056d558     MOV        EAX,EAX
    //         0056d55b     MOV        EAX,EAX
    //         0056d55e     MOV        EAX,EAX
    //                               switchD_0056d42a::caseD_a                                    XREF[2]:     0056b568(*), 
    //                                                                                                         FUN_0056d40a:0056d42a(j)  
    //         0056d560     SHR        ECX,0x4
    //         0056d563     JNZ        LAB_0056d568
    //         0056d565     MOV        CL,byte ptr [ESI]
    //         0056d567     INC        ESI
    //                               LAB_0056d568                                                 XREF[1]:     0056d563(j)  
    //         0056d568     MOV        AL,byte ptr [ESI]
    //         0056d56a     MOV        EBX,EDI
    //         0056d56c     MOV        AH,AL
    //         0056d56e     AND        EBX,0x3
    //         0056d571     SHL        EAX,0x10
    //         0056d574     OR         BL,byte ptr [ECX + LAB_0056b2ff+1]
    //         0056d57a     MOV        AL,byte ptr [ESI]
    //         0056d57c     OR         BL,byte ptr [null_0088c048]                      = align(12)
    //         0056d582     INC        ESI
    //         0056d583     MOV        AH,AL
    //         0056d585     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056d58b     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         0056d591     JMP        dword ptr [EBX*0x4 + DAT_0056ba00]
}

// Offset: 0x0056D598
undefined FUN_0056d598() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056d598()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056d598
    //         0056d598     MOV        EAX,EAX
    //         0056d59b     MOV        EAX,EAX
    //         0056d59e     MOV        EAX,EAX
    //                               switchD_0056d42a::caseD_b                                    XREF[2]:     0056b56c(*), 
    //                                                                                                         FUN_0056d40a:0056d42a(j)  
    //         0056d5a0     SHR        ECX,0x4
    //         0056d5a3     JNZ        LAB_0056d5a8
    //         0056d5a5     MOV        CL,byte ptr [ESI]
    //         0056d5a7     INC        ESI
    //                               LAB_0056d5a8                                                 XREF[1]:     0056d5a3(j)  
    //         0056d5a8     MOV        EAX,EDI
    //         0056d5aa     AND        EAX,0x3
    //         0056d5ad     OR         AL,byte ptr [ECX + LAB_0056b2ff+1]
    //         0056d5b3     MOV        EBX,dword ptr [DAT_0088c01c]
    //         0056d5b9     OR         AL,byte ptr [null_0088c048]                      = align(12)
    //         0056d5bf     XOR        EDX,EDX
    //         0056d5c1     JMP        dword ptr [EAX*0x4 + DAT_0056c200]
}

// Offset: 0x0056D5C8
undefined FUN_0056d5c8() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056d5c8()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056d5c8
    //         0056d5c8     MOV        EAX,EAX
    //         0056d5cb     MOV        EAX,EAX
    //         0056d5ce     MOV        EAX,EAX
    //         0056d5d1     MOV        EAX,EAX
    //         0056d5d4     MOV        EAX,EAX
    //         0056d5d7     MOV        EAX,EAX
    //         0056d5da     MOV        EAX,EAX
    //         0056d5dd     MOV        EAX,EAX
    //         0056d5e0     MOV        CL,byte ptr [ESI]
    //         0056d5e2     INC        ESI
    //         0056d5e3     JMP        LAB_0056d5ea
}

// Offset: 0x0056D5E5
undefined FUN_0056d5e5() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056d5e5()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056d5e5
    //         0056d5e5     MOV        ECX,0x1
    //                               LAB_0056d5ea                                                 XREF[1]:     FUN_0056d5c8:0056d5e3(j)  
    //         0056d5ea     CMP        dword ptr [DAT_0088c058],0x0                     = align(40)
    //         0056d5f1     JZ         LAB_0056d61c
    //         0056d5f3     MOV        EAX,[null_0088c05c]                              = align(36)
    //         0056d5f8     MOV        EBX,EDI
    //         0056d5fa     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056d600     AND        EBX,0x3
    //         0056d603     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         0056d609     OR         BL,byte ptr [ECX + 0x56b300]
    //         0056d60f     OR         BL,byte ptr [null_0088c048]                      = align(12)
    //         0056d615     JMP        dword ptr [EBX*0x4 + DAT_0056ba00]
    //                               LAB_0056d61c                                                 XREF[1]:     0056d5f1(j)  
    //         0056d61c     SUB        EDI,ECX
    //         0056d61e     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x0056D624
undefined FUN_0056d624() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056d624()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056d624
    //         0056d624     MOV        EAX,EAX
    //         0056d627     MOV        EAX,EAX
    //         0056d62a     MOV        EAX,EAX
    //         0056d62d     MOV        EAX,EAX
    //         0056d630     MOV        EAX,EAX
    //         0056d633     MOV        EAX,EAX
    //         0056d636     MOV        EAX,EAX
    //         0056d639     MOV        EAX,EAX
    //         0056d63c     MOV        EAX,EAX
    //         0056d63f     NOP
    //         0056d640     MOV        AL,byte ptr [ESI]
    //         0056d642     CALL       FUN_0056db60                                     undefined FUN_0056db60()
    //         0056d647     ADD        EDI,ECX
    //         0056d649     JMP        LAB_0056d420
}

// Offset: 0x0056D64E
undefined FUN_0056d64e() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056d64e()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056d64e
    //         0056d64e     MOV        EAX,EAX
    //         0056d651     MOV        EAX,EAX
    //         0056d654     MOV        EAX,EAX
    //         0056d657     MOV        EAX,EAX
    //         0056d65a     MOV        EAX,EAX
    //         0056d65d     MOV        EAX,EAX
    //                               LAB_0056d660                                                 XREF[6]:     FUN_0056d70c:0056d75b(*), 
    //                                                                                                         FUN_0056d7e5:0056d838(*), 
    //                                                                                                         FUN_0056d887:0056d8d6(*), 
    //                                                                                                         FUN_0056d93a:0056d976(*), 
    //                                                                                                         FUN_0056d9da:0056da16(*), 
    //                                                                                                         FUN_0056da65:0056dac1(*)  
    //         0056d660     MOV        ESI,dword ptr [null_0088c050]                    = align(4)
    //         0056d666     MOV        EDI,dword ptr [DAT_0088c054]
    //         0056d66c     MOV        EBX,dword ptr [DAT_0088c03c]
    //         0056d672     MOV        EBX,dword ptr [EBX + 0x4]
    //         0056d675     OR         EBX,EBX
    //         0056d677     JZ         switchD_0056d42a::caseD_f
    //         0056d67d     MOV        dword ptr [DAT_0088c044],0x56d6c0                = align(16)
    //         0056d687     XOR        EAX,EAX
    //         0056d689     MOV        AL,byte ptr [ESI]
    //         0056d68b     SUB        EDI,dword ptr [DAT_0088c020]                     = align(4)
    //         0056d691     MOV        ECX,EAX
    //         0056d693     INC        ESI
    //         0056d694     AND        EAX,0xf
    //         0056d697     MOV        dword ptr [DAT_0088c03c],EBX
    //                               switchD_0056d69d::switchD
    //         0056d69d     JMP        dword ptr [EAX*0x4 + switchD_0056d6e2::switchd   = 0056d720
}

// Offset: 0x0056D6A4
undefined FUN_0056d6a4() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056d6a4()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056d6a4
    //         0056d6a4     MOV        EAX,EAX
    //         0056d6a7     MOV        EAX,EAX
    //         0056d6aa     MOV        EAX,EAX
    //         0056d6ad     MOV        EAX,EAX
    //         0056d6b0     MOV        EAX,EAX
    //         0056d6b3     MOV        EAX,EAX
    //         0056d6b6     MOV        EAX,EAX
    //         0056d6b9     MOV        EAX,EAX
    //         0056d6bc     MOV        EAX,EAX
    //         0056d6bf     NOP
    //                               LAB_0056d6c0                                                 XREF[10]:    FUN_0056d2f9:0056d405(j), 
    //                                                                                                         FUN_0056d70c:0056d79c(j), 
    //                                                                                                         FUN_0056d7ad:0056d7cb(j), 
    //                                                                                                         FUN_0056d7ad:0056d7df(j), 
    //                                                                                                         FUN_0056d7e5:0056d876(j), 
    //                                                                                                         FUN_0056d887:0056d925(j), 
    //                                                                                                         FUN_0056d93a:0056d9c5(j), 
    //                                                                                                         FUN_0056d9da:0056da54(j), 
    //                                                                                                         FUN_0056da65:0056db08(j), 
    //                                                                                                         FUN_0056db16:0056db29(j)  
    //         0056d6c0     MOV        dword ptr [null_0088c050],ESI                    = align(4)
    //         0056d6c6     XOR        EAX,EAX
    //         0056d6c8     MOV        dword ptr [DAT_0088c054],EDI
    //         0056d6ce     MOV        AL,byte ptr [ESI]
    //         0056d6d0     SUB        EDI,dword ptr [DAT_0088c020]                     = align(4)
    //         0056d6d6     MOV        ECX,EAX
    //         0056d6d8     INC        ESI
    //         0056d6d9     AND        EAX,0xf
    //         0056d6dc     MOV        EBX,dword ptr [DAT_0088c03c]
    //                               switchD_0056d6e2::switchD
    //         0056d6e2     JMP        dword ptr [EAX*0x4 + switchD_0056d6e2::switchd   = 0056d720
}

// Offset: 0x0056D6E9
undefined FUN_0056d6e9() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056d6e9()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056d6e9
    //         0056d6e9     MOV        EAX,EAX
    //         0056d6ec     MOV        EAX,EAX
    //         0056d6ef     MOV        EAX,EAX
    //         0056d6f2     MOV        EAX,EAX
    //         0056d6f5     MOV        EAX,EAX
    //         0056d6f8     MOV        EAX,EAX
    //         0056d6fb     MOV        EAX,EAX
    //         0056d6fe     MOV        EAX,EAX
    //                               switchD_0056d69d::caseD_e                                    XREF[3]:     0056b538(*), 
    //                               switchD_0056d6e2::caseD_e                                                 FUN_0056d64e:0056d69d(j), 
    //                                                                                                         FUN_0056d6a4:0056d6e2(j)  
    //         0056d700     MOV        EAX,ECX
    //         0056d702     SHR        EAX,0x4
    //         0056d705     JMP        dword ptr [EAX*0x4 + DAT_0056b580]               = CEh
}

// Offset: 0x0056D70C
undefined FUN_0056d70c() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056d70c()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056d70c
    //         0056d70c     MOV        EAX,EAX
    //         0056d70f     MOV        EAX,EAX
    //         0056d712     MOV        EAX,EAX
    //         0056d715     MOV        EAX,EAX
    //         0056d718     MOV        EAX,EAX
    //         0056d71b     MOV        EAX,EAX
    //         0056d71e     MOV        EAX,EAX
    //                               switchD_0056d6e2::caseD_4                                    XREF[6]:     0056b500(*), 0056b510(*), 
    //                               switchD_0056d6e2::caseD_8                                                 0056b520(*), 0056b530(*), 
    //                               switchD_0056d6e2::caseD_c                                                 FUN_0056d64e:0056d69d(j), 
    //                               switchD_0056d69d::caseD_0                                                 FUN_0056d6a4:0056d6e2(j)  
    //                               switchD_0056d69d::caseD_4
    //                               switchD_0056d69d::caseD_8
    //                               switchD_0056d69d::caseD_c
    //                               switchD_0056d6e2::caseD_0
    //         0056d720     SHR        ECX,0x2
    //         0056d723     JMP        LAB_0056d72b
    //                               switchD_0056d69d::caseD_2                                    XREF[3]:     0056b508(*), 
    //                               switchD_0056d6e2::caseD_2                                                 FUN_0056d64e:0056d69d(j), 
    //                                                                                                         FUN_0056d6a4:0056d6e2(j)  
    //         0056d725     SHL        ECX,0x4
    //         0056d728     MOV        CL,byte ptr [ESI]
    //         0056d72a     INC        ESI
    //                               LAB_0056d72b                                                 XREF[1]:     0056d723(j)  
    //         0056d72b     MOV        EDX,EDI
    //         0056d72d     SUB        EDX,ECX
    //         0056d72f     INC        EDX
    //                               LAB_0056d730                                                 XREF[1]:     0056d7a6(j)  
    //         0056d730     CMP        EDX,dword ptr [EBX + 0xc]
    //         0056d733     JG         LAB_0056d792
    //         0056d735     CMP        EDI,dword ptr [EBX + 0x8]
    //         0056d738     JL         LAB_0056d7a1
    //         0056d73a     XOR        EAX,EAX
    //         0056d73c     CMP        EDI,dword ptr [EBX + 0xc]
    //         0056d73f     JLE        LAB_0056d74a
    //         0056d741     MOV        EAX,EDI
    //         0056d743     SUB        EAX,dword ptr [EBX + 0xc]
    //         0056d746     ADD        ESI,EAX
    //         0056d748     SUB        ECX,EAX
    //                               LAB_0056d74a                                                 XREF[1]:     0056d73f(j)  
    //         0056d74a     MOV        [null_0088c04c],EAX                              = align(8)
    //         0056d74f     CMP        EDX,dword ptr [EBX + 0x8]
    //         0056d752     JGE        LAB_0056d765
    //         0056d754     MOV        EAX,dword ptr [EBX + 0x8]
    //         0056d757     SUB        EAX,EDX
    //         0056d759     SUB        ECX,EAX
    //         0056d75b     MOV        dword ptr [DAT_0088c044],LAB_0056d660            = align(16)
    //                               LAB_0056d765                                                 XREF[1]:     0056d752(j)  
    //         0056d765     MOV        EDI,dword ptr [DAT_0088c054]
    //         0056d76b     XOR        EBX,EBX
    //         0056d76d     SUB        EDI,dword ptr [null_0088c04c]                    = align(8)
    //         0056d773     SUB        BL,CH
    //         0056d775     MOV        EAX,EDI
    //         0056d777     AND        BL,0x80
    //         0056d77a     AND        EAX,0x3
    //         0056d77d     OR         BL,CL
    //         0056d77f     OR         AL,byte ptr [null_0088c048]                      = align(12)
    //         0056d785     OR         AL,byte ptr [EBX + LAB_0056b2ff+1]
    //         0056d78b     JMP        dword ptr [EAX*0x4 + DAT_0056b600]
    //                               LAB_0056d792                                                 XREF[1]:     0056d733(j)  
    //         0056d792     MOV        EDI,dword ptr [DAT_0088c054]
    //         0056d798     ADD        ESI,ECX
    //         0056d79a     SUB        EDI,ECX
    //         0056d79c     JMP        LAB_0056d6c0
    //                               LAB_0056d7a1                                                 XREF[1]:     0056d738(j)  
    //         0056d7a1     MOV        EBX,dword ptr [EBX + 0x4]
    //         0056d7a4     OR         EBX,EBX
    //         0056d7a6     JNZ        LAB_0056d730
    //         0056d7a8     JMP        switchD_0056d42a::caseD_f
}

// Offset: 0x0056D7AD
undefined FUN_0056d7ad() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056d7ad()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056d7ad
    //         0056d7ad     MOV        EAX,EAX
    //         0056d7b0     MOV        EAX,EAX
    //         0056d7b3     MOV        EAX,EAX
    //         0056d7b6     MOV        EAX,EAX
    //         0056d7b9     MOV        EAX,EAX
    //         0056d7bc     MOV        EAX,EAX
    //         0056d7bf     NOP
    //                               switchD_0056d6e2::caseD_5                                    XREF[6]:     0056b504(*), 0056b514(*), 
    //                               switchD_0056d6e2::caseD_9                                                 0056b524(*), 0056b534(*), 
    //                               switchD_0056d6e2::caseD_d                                                 FUN_0056d64e:0056d69d(j), 
    //                               switchD_0056d69d::caseD_1                                                 FUN_0056d6a4:0056d6e2(j)  
    //                               switchD_0056d69d::caseD_5
    //                               switchD_0056d69d::caseD_9
    //                               switchD_0056d69d::caseD_d
    //                               switchD_0056d6e2::caseD_1
    //         0056d7c0     SHR        ECX,0x2
    //         0056d7c3     MOV        EDI,dword ptr [DAT_0088c054]
    //         0056d7c9     SUB        EDI,ECX
    //         0056d7cb     JMP        dword ptr [DAT_0088c044]
    //                               switchD_0056d69d::caseD_3                                    XREF[3]:     0056b50c(*), 
    //                               switchD_0056d6e2::caseD_3                                                 FUN_0056d64e:0056d69d(j), 
    //                                                                                                         FUN_0056d6a4:0056d6e2(j)  
    //         0056d7d1     SHL        ECX,0x4
    //         0056d7d4     MOV        EDI,dword ptr [DAT_0088c054]
    //         0056d7da     MOV        CL,byte ptr [ESI]
    //         0056d7dc     INC        ESI
    //         0056d7dd     SUB        EDI,ECX
    //         0056d7df     JMP        dword ptr [DAT_0088c044]
}

// Offset: 0x0056D7E5
undefined FUN_0056d7e5() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056d7e5()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056d7e5
    //         0056d7e5     MOV        EAX,EAX
    //         0056d7e8     MOV        EAX,EAX
    //         0056d7eb     MOV        EAX,EAX
    //         0056d7ee     MOV        EAX,EAX
    //         0056d7f1     MOV        EAX,EAX
    //         0056d7f4     MOV        EAX,EAX
    //         0056d7f7     MOV        EAX,EAX
    //         0056d7fa     MOV        EAX,EAX
    //         0056d7fd     MOV        EAX,EAX
    //                               switchD_0056d69d::caseD_6                                    XREF[3]:     0056b518(*), 
    //                               switchD_0056d6e2::caseD_6                                                 FUN_0056d64e:0056d69d(j), 
    //                                                                                                         FUN_0056d6a4:0056d6e2(j)  
    //         0056d800     SHR        ECX,0x4
    //         0056d803     JNZ        LAB_0056d808
    //         0056d805     MOV        CL,byte ptr [ESI]
    //         0056d807     INC        ESI
    //                               LAB_0056d808                                                 XREF[1]:     0056d803(j)  
    //         0056d808     MOV        EDX,EDI
    //         0056d80a     SUB        EDX,ECX
    //         0056d80c     INC        EDX
    //                               LAB_0056d80d                                                 XREF[1]:     0056d880(j)  
    //         0056d80d     CMP        EDX,dword ptr [EBX + 0xc]
    //         0056d810     JG         LAB_0056d86c
    //         0056d812     CMP        EDI,dword ptr [EBX + 0x8]
    //         0056d815     JL         LAB_0056d87b
    //         0056d817     XOR        EAX,EAX
    //         0056d819     CMP        EDI,dword ptr [EBX + 0xc]
    //         0056d81c     JLE        LAB_0056d827
    //         0056d81e     MOV        EAX,EDI
    //         0056d820     SUB        EAX,dword ptr [EBX + 0xc]
    //         0056d823     ADD        ESI,EAX
    //         0056d825     SUB        ECX,EAX
    //                               LAB_0056d827                                                 XREF[1]:     0056d81c(j)  
    //         0056d827     MOV        [null_0088c04c],EAX                              = align(8)
    //         0056d82c     CMP        EDX,dword ptr [EBX + 0x8]
    //         0056d82f     JGE        LAB_0056d842
    //         0056d831     MOV        EAX,dword ptr [EBX + 0x8]
    //         0056d834     SUB        EAX,EDX
    //         0056d836     SUB        ECX,EAX
    //         0056d838     MOV        dword ptr [DAT_0088c044],LAB_0056d660            = align(16)
    //                               LAB_0056d842                                                 XREF[1]:     0056d82f(j)  
    //         0056d842     MOV        EDI,dword ptr [DAT_0088c054]
    //         0056d848     SUB        EDI,dword ptr [null_0088c04c]                    = align(8)
    //         0056d84e     MOV        EAX,EDI
    //         0056d850     AND        EAX,0x3
    //         0056d853     OR         AL,byte ptr [ECX + LAB_0056b2ff+1]
    //         0056d859     MOV        EBX,dword ptr [DAT_0088c040]
    //         0056d85f     OR         AL,byte ptr [null_0088c048]                      = align(12)
    //         0056d865     JMP        dword ptr [EAX*0x4 + DAT_0056be00]
    //                               LAB_0056d86c                                                 XREF[1]:     0056d810(j)  
    //         0056d86c     MOV        EDI,dword ptr [DAT_0088c054]
    //         0056d872     ADD        ESI,ECX
    //         0056d874     SUB        EDI,ECX
    //         0056d876     JMP        LAB_0056d6c0
    //                               LAB_0056d87b                                                 XREF[1]:     0056d815(j)  
    //         0056d87b     MOV        EBX,dword ptr [EBX + 0x4]
    //         0056d87e     OR         EBX,EBX
    //         0056d880     JNZ        LAB_0056d80d
    //         0056d882     JMP        switchD_0056d42a::caseD_f
}

// Offset: 0x0056D887
undefined FUN_0056d887() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056d887()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056d887
    //         0056d887     MOV        EAX,EAX
    //         0056d88a     MOV        EAX,EAX
    //         0056d88d     MOV        EAX,EAX
    //         0056d890     MOV        EAX,EAX
    //         0056d893     MOV        EAX,EAX
    //         0056d896     MOV        EAX,EAX
    //         0056d899     MOV        EAX,EAX
    //         0056d89c     MOV        EAX,EAX
    //         0056d89f     NOP
    //                               switchD_0056d69d::caseD_7                                    XREF[3]:     0056b51c(*), 
    //                               switchD_0056d6e2::caseD_7                                                 FUN_0056d64e:0056d69d(j), 
    //                                                                                                         FUN_0056d6a4:0056d6e2(j)  
    //         0056d8a0     SHR        ECX,0x4
    //         0056d8a3     JNZ        LAB_0056d8a8
    //         0056d8a5     MOV        CL,byte ptr [ESI]
    //         0056d8a7     INC        ESI
    //                               LAB_0056d8a8                                                 XREF[1]:     0056d8a3(j)  
    //         0056d8a8     MOV        EDX,EDI
    //         0056d8aa     SUB        EDX,ECX
    //         0056d8ac     INC        EDX
    //                               LAB_0056d8ad                                                 XREF[1]:     0056d92f(j)  
    //         0056d8ad     CMP        EDX,dword ptr [EBX + 0xc]
    //         0056d8b0     JG         LAB_0056d91c
    //         0056d8b2     CMP        EDI,dword ptr [EBX + 0x8]
    //         0056d8b5     JL         LAB_0056d92a
    //         0056d8b7     XOR        EAX,EAX
    //         0056d8b9     CMP        EDI,dword ptr [EBX + 0xc]
    //         0056d8bc     JLE        LAB_0056d8c5
    //         0056d8be     MOV        EAX,EDI
    //         0056d8c0     SUB        EAX,dword ptr [EBX + 0xc]
    //         0056d8c3     SUB        ECX,EAX
    //                               LAB_0056d8c5                                                 XREF[1]:     0056d8bc(j)  
    //         0056d8c5     MOV        [null_0088c04c],EAX                              = align(8)
    //         0056d8ca     CMP        EDX,dword ptr [EBX + 0x8]
    //         0056d8cd     JGE        LAB_0056d8e0
    //         0056d8cf     MOV        EAX,dword ptr [EBX + 0x8]
    //         0056d8d2     SUB        EAX,EDX
    //         0056d8d4     SUB        ECX,EAX
    //         0056d8d6     MOV        dword ptr [DAT_0088c044],LAB_0056d660            = align(16)
    //                               LAB_0056d8e0                                                 XREF[1]:     0056d8cd(j)  
    //         0056d8e0     MOV        EDI,dword ptr [DAT_0088c054]
    //         0056d8e6     MOV        AL,byte ptr [ESI]
    //         0056d8e8     SUB        EDI,dword ptr [null_0088c04c]                    = align(8)
    //         0056d8ee     MOV        AH,AL
    //         0056d8f0     MOV        EBX,EDI
    //         0056d8f2     SHL        EAX,0x10
    //         0056d8f5     AND        EBX,0x3
    //         0056d8f8     MOV        AL,byte ptr [ESI]
    //         0056d8fa     OR         BL,byte ptr [ECX + LAB_0056b2ff+1]
    //         0056d900     MOV        AH,AL
    //         0056d902     OR         BL,byte ptr [null_0088c048]                      = align(12)
    //         0056d908     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056d90e     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         0056d914     INC        ESI
    //         0056d915     JMP        dword ptr [EBX*0x4 + DAT_0056ba00]
    //                               LAB_0056d91c                                                 XREF[1]:     0056d8b0(j)  
    //         0056d91c     MOV        EDI,dword ptr [DAT_0088c054]
    //         0056d922     INC        ESI
    //         0056d923     SUB        EDI,ECX
    //         0056d925     JMP        LAB_0056d6c0
    //                               LAB_0056d92a                                                 XREF[1]:     0056d8b5(j)  
    //         0056d92a     MOV        EBX,dword ptr [EBX + 0x4]
    //         0056d92d     OR         EBX,EBX
    //         0056d92f     JNZ        LAB_0056d8ad
    //         0056d935     JMP        switchD_0056d42a::caseD_f
}

// Offset: 0x0056D93A
undefined FUN_0056d93a() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056d93a()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056d93a
    //         0056d93a     MOV        EAX,EAX
    //         0056d93d     MOV        EAX,EAX
    //                               switchD_0056d69d::caseD_a                                    XREF[3]:     0056b528(*), 
    //                               switchD_0056d6e2::caseD_a                                                 FUN_0056d64e:0056d69d(j), 
    //                                                                                                         FUN_0056d6a4:0056d6e2(j)  
    //         0056d940     SHR        ECX,0x4
    //         0056d943     JNZ        LAB_0056d948
    //         0056d945     MOV        CL,byte ptr [ESI]
    //         0056d947     INC        ESI
    //                               LAB_0056d948                                                 XREF[1]:     0056d943(j)  
    //         0056d948     MOV        EDX,EDI
    //         0056d94a     SUB        EDX,ECX
    //         0056d94c     INC        EDX
    //                               LAB_0056d94d                                                 XREF[1]:     0056d9cf(j)  
    //         0056d94d     CMP        EDX,dword ptr [EBX + 0xc]
    //         0056d950     JG         LAB_0056d9bc
    //         0056d952     CMP        EDI,dword ptr [EBX + 0x8]
    //         0056d955     JL         LAB_0056d9ca
    //         0056d957     XOR        EAX,EAX
    //         0056d959     CMP        EDI,dword ptr [EBX + 0xc]
    //         0056d95c     JLE        LAB_0056d965
    //         0056d95e     MOV        EAX,EDI
    //         0056d960     SUB        EAX,dword ptr [EBX + 0xc]
    //         0056d963     SUB        ECX,EAX
    //                               LAB_0056d965                                                 XREF[1]:     0056d95c(j)  
    //         0056d965     MOV        [null_0088c04c],EAX                              = align(8)
    //         0056d96a     CMP        EDX,dword ptr [EBX + 0x8]
    //         0056d96d     JGE        LAB_0056d980
    //         0056d96f     MOV        EAX,dword ptr [EBX + 0x8]
    //         0056d972     SUB        EAX,EDX
    //         0056d974     SUB        ECX,EAX
    //         0056d976     MOV        dword ptr [DAT_0088c044],LAB_0056d660            = align(16)
    //                               LAB_0056d980                                                 XREF[1]:     0056d96d(j)  
    //         0056d980     MOV        EDI,dword ptr [DAT_0088c054]
    //         0056d986     MOV        AL,byte ptr [ESI]
    //         0056d988     SUB        EDI,dword ptr [null_0088c04c]                    = align(8)
    //         0056d98e     MOV        AH,AL
    //         0056d990     MOV        EBX,EDI
    //         0056d992     SHL        EAX,0x10
    //         0056d995     AND        EBX,0x3
    //         0056d998     MOV        AL,byte ptr [ESI]
    //         0056d99a     OR         BL,byte ptr [ECX + LAB_0056b2ff+1]
    //         0056d9a0     MOV        AH,AL
    //         0056d9a2     OR         BL,byte ptr [null_0088c048]                      = align(12)
    //         0056d9a8     INC        ESI
    //         0056d9a9     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056d9af     OR         EAX,dword ptr [null_0088c034]                    = align(4)
    //         0056d9b5     JMP        dword ptr [EBX*0x4 + DAT_0056ba00]
    //                               LAB_0056d9bc                                                 XREF[1]:     0056d950(j)  
    //         0056d9bc     MOV        EDI,dword ptr [DAT_0088c054]
    //         0056d9c2     INC        ESI
    //         0056d9c3     SUB        EDI,ECX
    //         0056d9c5     JMP        LAB_0056d6c0
    //                               LAB_0056d9ca                                                 XREF[1]:     0056d955(j)  
    //         0056d9ca     MOV        EBX,dword ptr [EBX + 0x4]
    //         0056d9cd     OR         EBX,EBX
    //         0056d9cf     JNZ        LAB_0056d94d
    //         0056d9d5     JMP        switchD_0056d42a::caseD_f
}

// Offset: 0x0056D9DA
undefined FUN_0056d9da() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056d9da()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056d9da
    //         0056d9da     MOV        EAX,EAX
    //         0056d9dd     MOV        EAX,EAX
    //                               switchD_0056d69d::caseD_b                                    XREF[3]:     0056b52c(*), 
    //                               switchD_0056d6e2::caseD_b                                                 FUN_0056d64e:0056d69d(j), 
    //                                                                                                         FUN_0056d6a4:0056d6e2(j)  
    //         0056d9e0     SHR        ECX,0x4
    //         0056d9e3     JNZ        LAB_0056d9e8
    //         0056d9e5     MOV        CL,byte ptr [ESI]
    //         0056d9e7     INC        ESI
    //                               LAB_0056d9e8                                                 XREF[1]:     0056d9e3(j)  
    //         0056d9e8     MOV        EDX,EDI
    //         0056d9ea     SUB        EDX,ECX
    //         0056d9ec     INC        EDX
    //                               LAB_0056d9ed                                                 XREF[1]:     0056da5e(j)  
    //         0056d9ed     CMP        EDX,dword ptr [EBX + 0xc]
    //         0056d9f0     JG         LAB_0056da4c
    //         0056d9f2     CMP        EDI,dword ptr [EBX + 0x8]
    //         0056d9f5     JL         LAB_0056da59
    //         0056d9f7     XOR        EAX,EAX
    //         0056d9f9     CMP        EDI,dword ptr [EBX + 0xc]
    //         0056d9fc     JLE        LAB_0056da05
    //         0056d9fe     MOV        EAX,EDI
    //         0056da00     SUB        EAX,dword ptr [EBX + 0xc]
    //         0056da03     SUB        ECX,EAX
    //                               LAB_0056da05                                                 XREF[1]:     0056d9fc(j)  
    //         0056da05     MOV        [null_0088c04c],EAX                              = align(8)
    //         0056da0a     CMP        EDX,dword ptr [EBX + 0x8]
    //         0056da0d     JGE        LAB_0056da20
    //         0056da0f     MOV        EAX,dword ptr [EBX + 0x8]
    //         0056da12     SUB        EAX,EDX
    //         0056da14     SUB        ECX,EAX
    //         0056da16     MOV        dword ptr [DAT_0088c044],LAB_0056d660            = align(16)
    //                               LAB_0056da20                                                 XREF[1]:     0056da0d(j)  
    //         0056da20     MOV        EDI,dword ptr [DAT_0088c054]
    //         0056da26     SUB        EDI,dword ptr [null_0088c04c]                    = align(8)
    //         0056da2c     MOV        EAX,EDI
    //         0056da2e     AND        EAX,0x3
    //         0056da31     OR         AL,byte ptr [ECX + LAB_0056b2ff+1]
    //         0056da37     MOV        EBX,dword ptr [DAT_0088c01c]
    //         0056da3d     OR         AL,byte ptr [null_0088c048]                      = align(12)
    //         0056da43     XOR        EDX,EDX
    //         0056da45     JMP        dword ptr [EAX*0x4 + DAT_0056c200]
    //                               LAB_0056da4c                                                 XREF[1]:     0056d9f0(j)  
    //         0056da4c     MOV        EDI,dword ptr [DAT_0088c054]
    //         0056da52     SUB        EDI,ECX
    //         0056da54     JMP        LAB_0056d6c0
    //                               LAB_0056da59                                                 XREF[1]:     0056d9f5(j)  
    //         0056da59     MOV        EBX,dword ptr [EBX + 0x4]
    //         0056da5c     OR         EBX,EBX
    //         0056da5e     JNZ        LAB_0056d9ed
    //         0056da60     JMP        switchD_0056d42a::caseD_f
}

// Offset: 0x0056DA65
undefined FUN_0056da65() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056da65()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056da65
    //         0056da65     MOV        EAX,EAX
    //         0056da68     MOV        EAX,EAX
    //         0056da6b     MOV        EAX,EAX
    //         0056da6e     MOV        EAX,EAX
    //         0056da71     MOV        EAX,EAX
    //         0056da74     MOV        EAX,EAX
    //         0056da77     MOV        EAX,EAX
    //         0056da7a     MOV        EAX,EAX
    //         0056da7d     MOV        EAX,EAX
    //         0056da80     MOV        CL,byte ptr [ESI]
    //         0056da82     INC        ESI
    //         0056da83     JNZ        LAB_0056da8a
    //         0056da85     MOV        ECX,0x1
    //                               LAB_0056da8a                                                 XREF[1]:     0056da83(j)  
    //         0056da8a     CMP        dword ptr [DAT_0088c058],0x0                     = align(40)
    //         0056da91     JZ         LAB_0056db00
    //         0056da93     MOV        EDX,EDI
    //         0056da95     SUB        EDX,ECX
    //         0056da97     INC        EDX
    //                               LAB_0056da98                                                 XREF[1]:     0056db12(j)  
    //         0056da98     CMP        EDX,dword ptr [EBX + 0xc]
    //         0056da9b     JG         LAB_0056db00
    //         0056da9d     CMP        EDI,dword ptr [EBX + 0x8]
    //         0056daa0     JL         LAB_0056db0d
    //         0056daa2     XOR        EAX,EAX
    //         0056daa4     CMP        EDI,dword ptr [EBX + 0xc]
    //         0056daa7     JLE        LAB_0056dab0
    //         0056daa9     MOV        EAX,EDI
    //         0056daab     SUB        EAX,dword ptr [EBX + 0xc]
    //         0056daae     SUB        ECX,EAX
    //                               LAB_0056dab0                                                 XREF[1]:     0056daa7(j)  
    //         0056dab0     MOV        [null_0088c04c],EAX                              = align(8)
    //         0056dab5     CMP        EDX,dword ptr [EBX + 0x8]
    //         0056dab8     JGE        LAB_0056dacb
    //         0056daba     MOV        EAX,dword ptr [EBX + 0x8]
    //         0056dabd     SUB        EAX,EDX
    //         0056dabf     SUB        ECX,EAX
    //         0056dac1     MOV        dword ptr [DAT_0088c044],LAB_0056d660            = align(16)
    //                               LAB_0056dacb                                                 XREF[1]:     0056dab8(j)  
    //         0056dacb     MOV        EDI,dword ptr [DAT_0088c054]
    //         0056dad1     MOV        EAX,[null_0088c05c]                              = align(36)
    //         0056dad6     SUB        EDI,dword ptr [null_0088c04c]                    = align(8)
    //         0056dadc     AND        EAX,dword ptr [DAT_0088c02c]                     = align(12)
    //         0056dae2     MOV        EBX,EDI
    //         0056dae4     OR         EAX,dword ptr [null_0088c030]                    = align(8)
    //         0056daea     AND        EBX,0x3
    //         0056daed     OR         BL,byte ptr [ECX + 0x56b300]
    //         0056daf3     OR         BL,byte ptr [null_0088c048]                      = align(12)
    //         0056daf9     JMP        dword ptr [EBX*0x4 + DAT_0056ba00]
    //                               LAB_0056db00                                                 XREF[2]:     0056da91(j), 0056da9b(j)  
    //         0056db00     MOV        EDI,dword ptr [DAT_0088c054]
    //         0056db06     SUB        EDI,ECX
    //         0056db08     JMP        LAB_0056d6c0
    //                               LAB_0056db0d                                                 XREF[1]:     0056daa0(j)  
    //         0056db0d     MOV        EBX,dword ptr [EBX + 0x4]
    //         0056db10     OR         EBX,EBX
    //         0056db12     JNZ        LAB_0056da98
    //         0056db14     JMP        switchD_0056d42a::caseD_f
}

// Offset: 0x0056DB16
undefined FUN_0056db16() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056db16()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056db16
    //         0056db16     MOV        EAX,EAX
    //         0056db19     MOV        EAX,EAX
    //         0056db1c     MOV        EAX,EAX
    //         0056db1f     NOP
    //         0056db20     MOV        AL,byte ptr [ESI]
    //         0056db22     CALL       FUN_0056db60                                     undefined FUN_0056db60()
    //         0056db27     ADD        EDI,ECX
    //         0056db29     JMP        LAB_0056d6c0
}

// Offset: 0x0056DB2E
undefined FUN_0056db2e() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056db2e()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056db2e
    //         0056db2e     MOV        EAX,EAX
    //         0056db31     MOV        EAX,EAX
    //         0056db34     MOV        EAX,EAX
    //         0056db37     MOV        EAX,EAX
    //         0056db3a     MOV        EAX,EAX
    //         0056db3d     MOV        EAX,EAX
    //                               switchD_0056d6e2::caseD_f                                    XREF[16]:    0056b53c(*), 0056b57c(*), 
    //                               switchD_0056d69d::caseD_f                                                 FUN_0056d2f9:0056d316(j), 
    //                               switchD_0056d42a::caseD_f                                                 FUN_0056d2f9:0056d36e(j), 
    //                                                                                                         FUN_0056d2f9:0056d3b0(j), 
    //                                                                                                         FUN_0056d2f9:0056d3c2(j), 
    //                                                                                                         FUN_0056d40a:0056d42a(j), 
    //                                                                                                         FUN_0056d64e:0056d677(j), 
    //                                                                                                         FUN_0056d64e:0056d69d(j), 
    //                                                                                                         FUN_0056d6a4:0056d6e2(j), 
    //                                                                                                         FUN_0056d70c:0056d7a8(j), 
    //                                                                                                         FUN_0056d7e5:0056d882(j), 
    //                                                                                                         FUN_0056d887:0056d935(j), 
    //                                                                                                         FUN_0056d93a:0056d9d5(j), 
    //                                                                                                         FUN_0056d9da:0056da60(j), 
    //                                                                                                         FUN_0056da65:0056db14(j)  
    //         0056db40     MOV        EAX,[DAT_0088c038]
    //         0056db45     INC        EAX
    //         0056db46     MOV        [DAT_0088c038],EAX
    //         0056db4b     CMP        EAX,dword ptr [EBP + 0x18]
    //         0056db4e     JL         LAB_0056d300
    //         0056db54     POP        EDI
    //         0056db55     POP        ESI
    //         0056db56     POP        EBX
    //         0056db57     POP        EBP
    //         0056db58     RET
}

// Offset: 0x0056DB59
undefined FUN_0056db59() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056db59()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056db59
    //         0056db59     MOV        EAX,EAX
    //         0056db5c     MOV        EAX,EAX
    //         0056db5f     NOP
}

// Offset: 0x0056DB60
undefined FUN_0056db60() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0056db60()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0056db60                                                 XREF[4]:     FUN_0056d078:0056d082(c), 
    //                                                                                                         FUN_0056d2a4:0056d2c2(c), 
    //                                                                                                         FUN_0056d624:0056d642(c), 
    //                                                                                                         FUN_0056db16:0056db22(c)  
    //         0056db60     XOR        EAX,EAX
    //         0056db62     MOV        AL,byte ptr [ESI]
    //         0056db64     MOV        ECX,EAX
    //         0056db66     INC        ESI
    //         0056db67     AND        EAX,0xf
    //                               switchD_0056db6a::switchD
    //         0056db6a     JMP        dword ptr [EAX*0x4 + switchD_0056db6a::switchd   = 0056db71
    //                               switchD_0056db6a::caseD_4                                    XREF[5]:     0056c600(*), 0056c610(*), 
    //                               switchD_0056db6a::caseD_8                                                 0056c620(*), 0056c630(*), 
    //                               switchD_0056db6a::caseD_c                                                 0056db6a(j)  
    //                               switchD_0056db6a::caseD_0
    //         0056db71     SHR        ECX,0x2
    //         0056db74     ADD        ESI,ECX
    //         0056db76     RET
    //                               switchD_0056db6a::caseD_5                                    XREF[5]:     0056c604(*), 0056c614(*), 
    //                               switchD_0056db6a::caseD_9                                                 0056c624(*), 0056c634(*), 
    //                               switchD_0056db6a::caseD_d                                                 0056db6a(j)  
    //                               switchD_0056db6a::caseD_1
    //         0056db77     SHR        ECX,0x2
    //         0056db7a     RET
    //                               switchD_0056db6a::caseD_2                                    XREF[2]:     0056c608(*), 0056db6a(j)  
    //         0056db7b     SHL        ECX,0x4
    //         0056db7e     MOV        CL,byte ptr [ESI]
    //         0056db80     INC        ESI
    //         0056db81     ADD        ESI,ECX
    //         0056db83     RET
    //                               switchD_0056db6a::caseD_3                                    XREF[2]:     0056c60c(*), 0056db6a(j)  
    //         0056db84     SHL        ECX,0x4
    //         0056db87     MOV        CL,byte ptr [ESI]
    //         0056db89     INC        ESI
    //         0056db8a     RET
    //                               switchD_0056db6a::caseD_6                                    XREF[2]:     0056c618(*), 0056db6a(j)  
    //         0056db8b     SHR        ECX,0x4
    //         0056db8e     JNZ        LAB_0056db93
    //         0056db90     MOV        CL,byte ptr [ESI]
    //         0056db92     INC        ESI
    //                               LAB_0056db93                                                 XREF[1]:     0056db8e(j)  
    //         0056db93     ADD        ESI,ECX
    //         0056db95     RET
    //                               switchD_0056db6a::caseD_a                                    XREF[3]:     0056c61c(*), 0056c628(*), 
    //                               switchD_0056db6a::caseD_7                                                 0056db6a(j)  
    //         0056db96     SHR        ECX,0x4
    //         0056db99     JNZ        LAB_0056db9e
    //         0056db9b     MOV        CL,byte ptr [ESI]
    //         0056db9d     INC        ESI
    //                               LAB_0056db9e                                                 XREF[1]:     0056db99(j)  
    //         0056db9e     INC        ESI
    //         0056db9f     RET
    //                               switchD_0056db6a::caseD_b                                    XREF[2]:     0056c62c(*), 0056db6a(j)  
    //         0056dba0     SHR        ECX,0x4
    //         0056dba3     JNZ        LAB_0056dba8
    //         0056dba5     MOV        CL,byte ptr [ESI]
    //         0056dba7     INC        ESI
    //                               LAB_0056dba8                                                 XREF[1]:     0056dba3(j)  
    //         0056dba8     RET
    //                               switchD_0056db6a::caseD_e                                    XREF[2]:     0056c638(*), 0056db6a(j)  
    //         0056dba9     MOV        EAX,ECX
    //         0056dbab     SHR        EAX,0x4
    //         0056dbae     JMP        dword ptr [EAX*0x4 + DAT_0056c640]               = BBh
    //                               switchD_0056db6a::caseD_f                                    XREF[2]:     0056c63c(*), 0056db6a(j)  
    //         0056dbb5     MOV        ECX,0x0
    //         0056dbba     RET
}

