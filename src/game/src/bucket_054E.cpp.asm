// Auto-generated scaffold unit: bucket_054E.cpp.asm
#include "../include/common.h"

// Offset: 0x0054E000
undefined isspace() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * isspace                                                                                               *
    //                              *********************************************************************************************************
    //                              undefined __cdecl isspace()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _isspace                                                     XREF[20]:    numWords:00446e47(c), 
    //                               isspace                                                                   numWords:00446e68(c), 
    //                                                                                                         word:00446f04(c), 
    //                                                                                                         word:00446f1f(c), 
    //                                                                                                         word:00446f46(c), 
    //                                                                                                         word:00446f5f(c), 
    //                                                                                                         nextWord:00446fff(c), 
    //                                                                                                         nextWord:00447018(c), 
    //                                                                                                         nextWord:0044702d(c), 
    //                                                                                                         nextWord:00447046(c), 
    //                                                                                                         moveToNextWord:004470cd(c), 
    //                                                                                                         moveToNextWord:004470ee(c), 
    //                                                                                                         moveToNextWord:00447104(c), 
    //                                                                                                         moveToNextWord:00447125(c), 
    //                                                                                                         __input:0055235b(c), 
    //                                                                                                         __input:00552374(c), 
    //                                                                                                         FUN_00553090:005530a9(c), 
    //                                                                                                         FUN_00553090:005530c6(c), 
    //                                                                                                         operator>>:0055b7f8(c), 
    //                                                                                                         eatwhite:0055b957(c)  
    //         0054e000     CMP        dword ptr [___mb_cur_max],0x1                    = 00000001h
    //         0054e007     JLE        LAB_0054e019
    //         0054e009     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054e00d     PUSH       0x8
    //         0054e00f     PUSH       EAX
    //         0054e010     CALL       __isctype                                        undefined __isctype()
    //         0054e015     ADD        ESP,0x8
    //         0054e018     RET
    //                               LAB_0054e019                                                 XREF[1]:     0054e007(j)  
    //         0054e019     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         0054e01d     MOV        EDX,dword ptr [__pctype]                         = 005920da
    //         0054e023     MOV        AL,byte ptr [EDX + ECX*0x2]=>DAT_005920da        = 20h     
    //         0054e026     AND        EAX,0x8
    //         0054e029     RET
}

// Offset: 0x0054E02A
undefined FUN_0054e02a() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054e02a()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054e02a
    //         0054e02a     NOP
    //         0054e02b     NOP
    //         0054e02c     NOP
    //         0054e02d     NOP
    //         0054e02e     NOP
    //         0054e02f     NOP
    //                               _ispunct
    //         0054e030     CMP        dword ptr [___mb_cur_max],0x1                    = 00000001h
    //         0054e037     JLE        LAB_0054e049
    //         0054e039     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054e03d     PUSH       0x10
    //         0054e03f     PUSH       EAX
    //         0054e040     CALL       __isctype                                        undefined __isctype()
    //         0054e045     ADD        ESP,0x8
    //         0054e048     RET
    //                               LAB_0054e049                                                 XREF[1]:     0054e037(j)  
    //         0054e049     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         0054e04d     MOV        EDX,dword ptr [__pctype]                         = 005920da
    //         0054e053     MOV        AL,byte ptr [EDX + ECX*0x2]=>DAT_005920da        = 20h     
    //         0054e056     AND        EAX,0x10
    //         0054e059     RET
}

// Offset: 0x0054E05A
undefined FUN_0054e05a() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054e05a()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054e05a
    //         0054e05a     NOP
    //         0054e05b     NOP
    //         0054e05c     NOP
    //         0054e05d     NOP
    //         0054e05e     NOP
    //         0054e05f     NOP
    //                               _isalnum
    //         0054e060     CMP        dword ptr [___mb_cur_max],0x1                    = 00000001h
    //         0054e067     JLE        LAB_0054e07c
    //         0054e069     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054e06d     PUSH       0x107
    //         0054e072     PUSH       EAX
    //         0054e073     CALL       __isctype                                        undefined __isctype()
    //         0054e078     ADD        ESP,0x8
    //         0054e07b     RET
    //                               LAB_0054e07c                                                 XREF[1]:     0054e067(j)  
    //         0054e07c     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         0054e080     MOV        EDX,dword ptr [__pctype]                         = 005920da
    //         0054e086     MOV        AX,word ptr [EDX + ECX*0x2]=>DAT_005920da        = 20h     
    //         0054e08a     AND        EAX,0x107
    //         0054e08f     RET
}

// Offset: 0x0054E090
undefined isprint() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined _isprint()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _isprint
    //         0054e090     CMP        dword ptr [___mb_cur_max],0x1                    = 00000001h
    //         0054e097     JLE        LAB_0054e0ac
    //         0054e099     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054e09d     PUSH       0x157
    //         0054e0a2     PUSH       EAX
    //         0054e0a3     CALL       __isctype                                        undefined __isctype()
    //         0054e0a8     ADD        ESP,0x8
    //         0054e0ab     RET
    //                               LAB_0054e0ac                                                 XREF[1]:     0054e097(j)  
    //         0054e0ac     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         0054e0b0     MOV        EDX,dword ptr [__pctype]                         = 005920da
    //         0054e0b6     MOV        AX,word ptr [EDX + ECX*0x2]=>DAT_005920da        = 20h     
    //         0054e0ba     AND        EAX,0x157
    //         0054e0bf     RET
}

// Offset: 0x0054E0C0
undefined isgraph() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined _isgraph()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _isgraph
    //         0054e0c0     CMP        dword ptr [___mb_cur_max],0x1                    = 00000001h
    //         0054e0c7     JLE        LAB_0054e0dc
    //         0054e0c9     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054e0cd     PUSH       0x117
    //         0054e0d2     PUSH       EAX
    //         0054e0d3     CALL       __isctype                                        undefined __isctype()
    //         0054e0d8     ADD        ESP,0x8
    //         0054e0db     RET
    //                               LAB_0054e0dc                                                 XREF[1]:     0054e0c7(j)  
    //         0054e0dc     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         0054e0e0     MOV        EDX,dword ptr [__pctype]                         = 005920da
    //         0054e0e6     MOV        AX,word ptr [EDX + ECX*0x2]=>DAT_005920da        = 20h     
    //         0054e0ea     AND        EAX,0x117
    //         0054e0ef     RET
}

// Offset: 0x0054E0F0
undefined iscntrl() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined _iscntrl()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _iscntrl
    //         0054e0f0     CMP        dword ptr [___mb_cur_max],0x1                    = 00000001h
    //         0054e0f7     JLE        LAB_0054e109
    //         0054e0f9     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054e0fd     PUSH       0x20
    //         0054e0ff     PUSH       EAX
    //         0054e100     CALL       __isctype                                        undefined __isctype()
    //         0054e105     ADD        ESP,0x8
    //         0054e108     RET
    //                               LAB_0054e109                                                 XREF[1]:     0054e0f7(j)  
    //         0054e109     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         0054e10d     MOV        EDX,dword ptr [__pctype]                         = 005920da
    //         0054e113     MOV        AL,byte ptr [EDX + ECX*0x2]=>DAT_005920da        = 20h     
    //         0054e116     AND        EAX,0x20
    //         0054e119     RET
}

// Offset: 0x0054E11A
undefined FUN_0054e11a() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054e11a()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054e11a
    //         0054e11a     NOP
    //         0054e11b     NOP
    //         0054e11c     NOP
    //         0054e11d     NOP
    //         0054e11e     NOP
    //         0054e11f     NOP
    //                               ___isascii
    //         0054e120     CMP        dword ptr [ESP + Stack[0x4]],0x80
    //         0054e128     SBB        EAX,EAX
    //         0054e12a     NEG        EAX
    //         0054e12c     RET
}

// Offset: 0x0054E12D
undefined FUN_0054e12d() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054e12d()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054e12d
    //         0054e12d     NOP
    //         0054e12e     NOP
    //         0054e12f     NOP
    //                               ___toascii
    //         0054e130     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054e134     AND        EAX,0x7f
    //         0054e137     RET
}

// Offset: 0x0054E138
undefined FUN_0054e138() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054e138()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054e138
    //         0054e138     NOP
    //         0054e139     NOP
    //         0054e13a     NOP
    //         0054e13b     NOP
    //         0054e13c     NOP
    //         0054e13d     NOP
    //         0054e13e     NOP
    //         0054e13f     NOP
    //                               ___iscsymf
    //         0054e140     MOV        EAX,[___mb_cur_max]                              = 00000001h
    //         0054e145     PUSH       ESI
    //         0054e146     CMP        EAX,0x1
    //         0054e149     JLE        LAB_0054e15f
    //         0054e14b     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         0054e14f     PUSH       0x103
    //         0054e154     PUSH       ESI
    //         0054e155     CALL       __isctype                                        undefined __isctype()
    //         0054e15a     ADD        ESP,0x8
    //         0054e15d     JMP        LAB_0054e171
    //                               LAB_0054e15f                                                 XREF[1]:     0054e149(j)  
    //         0054e15f     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         0054e163     MOV        EAX,[__pctype]                                   = 005920da
    //         0054e168     MOV        AX=>DAT_005920da,word ptr [EAX + ESI*0x2]        = 20h     
    //         0054e16c     AND        EAX,0x103
    //                               LAB_0054e171                                                 XREF[1]:     0054e15d(j)  
    //         0054e171     TEST       EAX,EAX
    //         0054e173     JNZ        LAB_0054e17c
    //         0054e175     CMP        ESI,0x5f
    //         0054e178     JZ         LAB_0054e17c
    //         0054e17a     POP        ESI
    //         0054e17b     RET
    //                               LAB_0054e17c                                                 XREF[2]:     0054e173(j), 0054e178(j)  
    //         0054e17c     MOV        EAX,0x1
    //         0054e181     POP        ESI
    //         0054e182     RET
}

// Offset: 0x0054E183
undefined FUN_0054e183() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054e183()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054e183
    //         0054e183     NOP
    //         0054e184     NOP
    //         0054e185     NOP
    //         0054e186     NOP
    //         0054e187     NOP
    //         0054e188     NOP
    //         0054e189     NOP
    //         0054e18a     NOP
    //         0054e18b     NOP
    //         0054e18c     NOP
    //         0054e18d     NOP
    //         0054e18e     NOP
    //         0054e18f     NOP
    //                               ___iscsym
    //         0054e190     MOV        EAX,[___mb_cur_max]                              = 00000001h
    //         0054e195     PUSH       ESI
    //         0054e196     CMP        EAX,0x1
    //         0054e199     JLE        LAB_0054e1af
    //         0054e19b     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         0054e19f     PUSH       0x107
    //         0054e1a4     PUSH       ESI
    //         0054e1a5     CALL       __isctype                                        undefined __isctype()
    //         0054e1aa     ADD        ESP,0x8
    //         0054e1ad     JMP        LAB_0054e1c1
    //                               LAB_0054e1af                                                 XREF[1]:     0054e199(j)  
    //         0054e1af     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         0054e1b3     MOV        EAX,[__pctype]                                   = 005920da
    //         0054e1b8     MOV        AX=>DAT_005920da,word ptr [EAX + ESI*0x2]        = 20h     
    //         0054e1bc     AND        EAX,0x107
    //                               LAB_0054e1c1                                                 XREF[1]:     0054e1ad(j)  
    //         0054e1c1     TEST       EAX,EAX
    //         0054e1c3     JNZ        LAB_0054e1cc
    //         0054e1c5     CMP        ESI,0x5f
    //         0054e1c8     JZ         LAB_0054e1cc
    //         0054e1ca     POP        ESI
    //         0054e1cb     RET
    //                               LAB_0054e1cc                                                 XREF[2]:     0054e1c3(j), 0054e1c8(j)  
    //         0054e1cc     MOV        EAX,0x1
    //         0054e1d1     POP        ESI
    //         0054e1d2     RET
}

// Offset: 0x0054E1E0
undefined atof() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * atof                                                                                                  *
    //                              *********************************************************************************************************
    //                              undefined __cdecl atof()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _atof                                                        XREF[1]:     asDouble:00447413(c)  
    //                               atof
    //         0054e1e0     PUSH       ESI
    //         0054e1e1     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         0054e1e5     PUSH       EDI
    //                               LAB_0054e1e6                                                 XREF[1]:     0054e215(j)  
    //         0054e1e6     CMP        dword ptr [___mb_cur_max],0x1                    = 00000001h
    //         0054e1ed     JLE        LAB_0054e200
    //         0054e1ef     XOR        EAX,EAX
    //         0054e1f1     PUSH       0x8
    //         0054e1f3     MOV        AL,byte ptr [ESI]
    //         0054e1f5     PUSH       EAX
    //         0054e1f6     CALL       __isctype                                        undefined __isctype()
    //         0054e1fb     ADD        ESP,0x8
    //         0054e1fe     JMP        LAB_0054e210
    //                               LAB_0054e200                                                 XREF[1]:     0054e1ed(j)  
    //         0054e200     MOV        EDX,dword ptr [__pctype]                         = 005920da
    //         0054e206     XOR        ECX,ECX
    //         0054e208     MOV        CL,byte ptr [ESI]
    //         0054e20a     MOV        AL,byte ptr [EDX + ECX*0x2]=>DAT_005920da        = 20h     
    //         0054e20d     AND        EAX,0x8
    //                               LAB_0054e210                                                 XREF[1]:     0054e1fe(j)  
    //         0054e210     TEST       EAX,EAX
    //         0054e212     JZ         LAB_0054e217
    //         0054e214     INC        ESI
    //         0054e215     JMP        LAB_0054e1e6
    //                               LAB_0054e217                                                 XREF[1]:     0054e212(j)  
    //         0054e217     MOV        EDI,ESI
    //         0054e219     OR         ECX,0xffffffff
    //         0054e21c     XOR        EAX,EAX
    //         0054e21e     PUSH       0x0
    //         0054e220     SCASB.RE   ES:EDI
    //         0054e222     NOT        ECX
    //         0054e224     DEC        ECX
    //         0054e225     PUSH       0x0
    //         0054e227     PUSH       ECX
    //         0054e228     PUSH       ESI
    //         0054e229     CALL       __fltin                                          undefined __fltin()
    //         0054e22e     FLD        double ptr [EAX + 0x10]
    //         0054e231     ADD        ESP,0x10
    //         0054e234     POP        EDI
    //         0054e235     POP        ESI
    //         0054e236     RET
}

// Offset: 0x0054E237
undefined FUN_0054e237() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054e237()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054e237
    //         0054e237     NOP
    //         0054e238     NOP
    //         0054e239     NOP
    //         0054e23a     NOP
    //         0054e23b     NOP
    //         0054e23c     NOP
    //         0054e23d     NOP
    //         0054e23e     NOP
    //         0054e23f     NOP
    //                               __toupper
    //         0054e240     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054e244     ADD        EAX,-0x20
    //         0054e247     RET
}

// Offset: 0x0054E250
undefined toupper() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * toupper                                                                                               *
    //                              *********************************************************************************************************
    //                              undefined __cdecl toupper()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[3,1]:   0054e2f1(*), 0054e321(R), 0054e333(R), 0054e32f(R)  
    //                               _toupper                                                     XREF[6]:     uppercase:00447436(c), 
    //                               toupper                                                                   char_action:0047885b(c), 
    //                                                                                                         char_action:00478882(c), 
    //                                                                                                         char_action:004788b2(c), 
    //                                                                                                         __getdrive:0054e48c(c), 
    //                                                                                                         operator<<:0055b09f(c)  
    //         0054e250     MOV        EAX,[DAT_008882c0]
    //         0054e255     SUB        ESP,0x8
    //         0054e258     TEST       EAX,EAX
    //         0054e25a     PUSH       EBX
    //         0054e25b     JNZ        LAB_0054e27b
    //         0054e25d     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054e261     CMP        EAX,0x61
    //         0054e264     JL         LAB_0054e347
    //         0054e26a     CMP        EAX,0x7a
    //         0054e26d     JG         LAB_0054e347
    //         0054e273     SUB        EAX,0x20
    //         0054e276     POP        EBX
    //         0054e277     ADD        ESP,0x8
    //         0054e27a     RET
    //                               LAB_0054e27b                                                 XREF[1]:     0054e25b(j)  
    //         0054e27b     MOV        EBX,dword ptr [ESP + Stack[0x4]]
    //         0054e27f     CMP        EBX,0x100
    //         0054e285     JGE        LAB_0054e2b3
    //         0054e287     CMP        dword ptr [___mb_cur_max],0x1                    = 00000001h
    //         0054e28e     JLE        LAB_0054e29d
    //         0054e290     PUSH       0x2
    //         0054e292     PUSH       EBX
    //         0054e293     CALL       __isctype                                        undefined __isctype()
    //         0054e298     ADD        ESP,0x8
    //         0054e29b     JMP        LAB_0054e2a8
    //                               LAB_0054e29d                                                 XREF[1]:     0054e28e(j)  
    //         0054e29d     MOV        EAX,[__pctype]                                   = 005920da
    //         0054e2a2     MOV        AL,byte ptr [EAX + EBX*0x2]=>DAT_005920da        = 20h     
    //         0054e2a5     AND        EAX,0x2
    //                               LAB_0054e2a8                                                 XREF[1]:     0054e29b(j)  
    //         0054e2a8     TEST       EAX,EAX
    //         0054e2aa     JNZ        LAB_0054e2b3
    //         0054e2ac     MOV        EAX,EBX
    //         0054e2ae     POP        EBX
    //         0054e2af     ADD        ESP,0x8
    //         0054e2b2     RET
    //                               LAB_0054e2b3                                                 XREF[2]:     0054e285(j), 0054e2aa(j)  
    //         0054e2b3     MOV        EDX,dword ptr [__pctype]                         = 005920da
    //         0054e2b9     MOV        EAX,EBX
    //         0054e2bb     SAR        EAX,0x8
    //         0054e2be     MOV        ECX,EAX
    //         0054e2c0     AND        ECX,0xff
    //         0054e2c6     TEST       byte ptr [EDX + ECX*0x2 + 0x1]=>DAT_005920db,0
    //         0054e2cb     JZ         LAB_0054e2e1
    //         0054e2cd     MOV        byte ptr [ESP + Stack[0x4]],AL
    //         0054e2d1     MOV        byte ptr [ESP + Stack[0x5]],BL
    //         0054e2d5     MOV        byte ptr [ESP + Stack[0x6]],0x0
    //         0054e2da     MOV        EAX,0x2
    //         0054e2df     JMP        LAB_0054e2ef
    //                               LAB_0054e2e1                                                 XREF[1]:     0054e2cb(j)  
    //         0054e2e1     MOV        byte ptr [ESP + Stack[0x4]],BL
    //         0054e2e5     MOV        byte ptr [ESP + Stack[0x5]],0x0
    //         0054e2ea     MOV        EAX,0x1
    //                               LAB_0054e2ef                                                 XREF[1]:     0054e2df(j)  
    //         0054e2ef     PUSH       0x0
    //         0054e2f1     LEA        ECX=>local_8,[ESP + 0x8]
    //         0054e2f5     PUSH       0x3
    //         0054e2f7     PUSH       ECX
    //         0054e2f8     LEA        EDX=>Stack[0x4],[ESP + 0x1c]
    //         0054e2fc     PUSH       EAX
    //         0054e2fd     MOV        EAX,[DAT_008882c0]
    //         0054e302     PUSH       EDX
    //         0054e303     PUSH       0x200
    //         0054e308     PUSH       EAX
    //         0054e309     CALL       ___crtLCMapStringA                               undefined ___crtLCMapStringA()
    //         0054e30e     ADD        ESP,0x1c
    //         0054e311     TEST       EAX,EAX
    //         0054e313     JNZ        LAB_0054e31c
    //         0054e315     MOV        EAX,EBX
    //         0054e317     POP        EBX
    //         0054e318     ADD        ESP,0x8
    //         0054e31b     RET
    //                               LAB_0054e31c                                                 XREF[1]:     0054e313(j)  
    //         0054e31c     CMP        EAX,0x1
    //         0054e31f     JNZ        LAB_0054e32f
    //         0054e321     MOV        EAX,dword ptr [ESP + local_8]
    //         0054e325     AND        EAX,0xff
    //         0054e32a     POP        EBX
    //         0054e32b     ADD        ESP,0x8
    //         0054e32e     RET
    //                               LAB_0054e32f                                                 XREF[1]:     0054e31f(j)  
    //         0054e32f     MOV        EAX,dword ptr [ESP + local_8+0x1]
    //         0054e333     MOV        ECX,dword ptr [ESP + local_8]
    //         0054e337     AND        EAX,0xff
    //         0054e33c     AND        ECX,0xff
    //         0054e342     SHL        EAX,0x8
    //         0054e345     OR         EAX,ECX
    //                               LAB_0054e347                                                 XREF[2]:     0054e264(j), 0054e26d(j)  
    //         0054e347     POP        EBX
    //         0054e348     ADD        ESP,0x8
    //         0054e34b     RET
}

// Offset: 0x0054E34C
undefined FUN_0054e34c() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054e34c()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054e34c
    //         0054e34c     NOP
    //         0054e34d     NOP
    //         0054e34e     NOP
    //         0054e34f     NOP
    //                               __tolower
    //         0054e350     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054e354     ADD        EAX,0x20
    //         0054e357     RET
}

// Offset: 0x0054E360
undefined tolower() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * tolower                                                                                               *
    //                              *********************************************************************************************************
    //                              undefined __cdecl tolower()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[3,1]:   0054e401(*), 0054e431(R), 0054e443(R), 0054e43f(R)  
    //                               _tolower                                                     XREF[7]:     lowercase:004474f6(c), 
    //                               tolower                                                                   BUILDRES_get_files_resource_type:0
    //                                                                                                         stricmp:0054ebdc(c), 
    //                                                                                                         stricmp:0054ebe6(c), 
    //                                                                                                         __strnicmp:0054f5cd(c), 
    //                                                                                                         __strnicmp:0054f5d7(c), 
    //                                                                                                         __forcdecpt:00550669(c)  
    //         0054e360     MOV        EAX,[DAT_008882c0]
    //         0054e365     SUB        ESP,0x8
    //         0054e368     TEST       EAX,EAX
    //         0054e36a     PUSH       EBX
    //         0054e36b     JNZ        LAB_0054e38b
    //         0054e36d     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054e371     CMP        EAX,0x41
    //         0054e374     JL         LAB_0054e457
    //         0054e37a     CMP        EAX,0x5a
    //         0054e37d     JG         LAB_0054e457
    //         0054e383     ADD        EAX,0x20
    //         0054e386     POP        EBX
    //         0054e387     ADD        ESP,0x8
    //         0054e38a     RET
    //                               LAB_0054e38b                                                 XREF[1]:     0054e36b(j)  
    //         0054e38b     MOV        EBX,dword ptr [ESP + Stack[0x4]]
    //         0054e38f     CMP        EBX,0x100
    //         0054e395     JGE        LAB_0054e3c3
    //         0054e397     CMP        dword ptr [___mb_cur_max],0x1                    = 00000001h
    //         0054e39e     JLE        LAB_0054e3ad
    //         0054e3a0     PUSH       0x1
    //         0054e3a2     PUSH       EBX
    //         0054e3a3     CALL       __isctype                                        undefined __isctype()
    //         0054e3a8     ADD        ESP,0x8
    //         0054e3ab     JMP        LAB_0054e3b8
    //                               LAB_0054e3ad                                                 XREF[1]:     0054e39e(j)  
    //         0054e3ad     MOV        EAX,[__pctype]                                   = 005920da
    //         0054e3b2     MOV        AL,byte ptr [EAX + EBX*0x2]=>DAT_005920da        = 20h     
    //         0054e3b5     AND        EAX,0x1
    //                               LAB_0054e3b8                                                 XREF[1]:     0054e3ab(j)  
    //         0054e3b8     TEST       EAX,EAX
    //         0054e3ba     JNZ        LAB_0054e3c3
    //         0054e3bc     MOV        EAX,EBX
    //         0054e3be     POP        EBX
    //         0054e3bf     ADD        ESP,0x8
    //         0054e3c2     RET
    //                               LAB_0054e3c3                                                 XREF[2]:     0054e395(j), 0054e3ba(j)  
    //         0054e3c3     MOV        EDX,dword ptr [__pctype]                         = 005920da
    //         0054e3c9     MOV        EAX,EBX
    //         0054e3cb     SAR        EAX,0x8
    //         0054e3ce     MOV        ECX,EAX
    //         0054e3d0     AND        ECX,0xff
    //         0054e3d6     TEST       byte ptr [EDX + ECX*0x2 + 0x1]=>DAT_005920db,0
    //         0054e3db     JZ         LAB_0054e3f1
    //         0054e3dd     MOV        byte ptr [ESP + Stack[0x4]],AL
    //         0054e3e1     MOV        byte ptr [ESP + Stack[0x5]],BL
    //         0054e3e5     MOV        byte ptr [ESP + Stack[0x6]],0x0
    //         0054e3ea     MOV        EAX,0x2
    //         0054e3ef     JMP        LAB_0054e3ff
    //                               LAB_0054e3f1                                                 XREF[1]:     0054e3db(j)  
    //         0054e3f1     MOV        byte ptr [ESP + Stack[0x4]],BL
    //         0054e3f5     MOV        byte ptr [ESP + Stack[0x5]],0x0
    //         0054e3fa     MOV        EAX,0x1
    //                               LAB_0054e3ff                                                 XREF[1]:     0054e3ef(j)  
    //         0054e3ff     PUSH       0x0
    //         0054e401     LEA        ECX=>local_8,[ESP + 0x8]
    //         0054e405     PUSH       0x3
    //         0054e407     PUSH       ECX
    //         0054e408     LEA        EDX=>Stack[0x4],[ESP + 0x1c]
    //         0054e40c     PUSH       EAX
    //         0054e40d     MOV        EAX,[DAT_008882c0]
    //         0054e412     PUSH       EDX
    //         0054e413     PUSH       0x100
    //         0054e418     PUSH       EAX
    //         0054e419     CALL       ___crtLCMapStringA                               undefined ___crtLCMapStringA()
    //         0054e41e     ADD        ESP,0x1c
    //         0054e421     TEST       EAX,EAX
    //         0054e423     JNZ        LAB_0054e42c
    //         0054e425     MOV        EAX,EBX
    //         0054e427     POP        EBX
    //         0054e428     ADD        ESP,0x8
    //         0054e42b     RET
    //                               LAB_0054e42c                                                 XREF[1]:     0054e423(j)  
    //         0054e42c     CMP        EAX,0x1
    //         0054e42f     JNZ        LAB_0054e43f
    //         0054e431     MOV        EAX,dword ptr [ESP + local_8]
    //         0054e435     AND        EAX,0xff
    //         0054e43a     POP        EBX
    //         0054e43b     ADD        ESP,0x8
    //         0054e43e     RET
    //                               LAB_0054e43f                                                 XREF[1]:     0054e42f(j)  
    //         0054e43f     MOV        EAX,dword ptr [ESP + local_8+0x1]
    //         0054e443     MOV        ECX,dword ptr [ESP + local_8]
    //         0054e447     AND        EAX,0xff
    //         0054e44c     AND        ECX,0xff
    //         0054e452     SHL        EAX,0x8
    //         0054e455     OR         EAX,ECX
    //                               LAB_0054e457                                                 XREF[2]:     0054e374(j), 0054e37d(j)  
    //         0054e457     POP        EBX
    //         0054e458     ADD        ESP,0x8
    //         0054e45b     RET
}

// Offset: 0x0054E460
undefined getdrive() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __getdrive()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined         Stack[-0x104   local_104                 XREF[1]:     0054e466(*)  
    //                               __getdrive                                                   XREF[1]:     DriveInformation:00449775(c)  
    //         0054e460     SUB        ESP,0x104
    //         0054e466     LEA        EAX=>local_104,[ESP]
    //         0054e46a     PUSH       ESI
    //         0054e46b     PUSH       EAX
    //         0054e46c     PUSH       0x104
    //         0054e471     XOR        ESI,ESI
    //         0054e473     CALL       dword ptr [->KERNEL32.DLL::GetCurrentDirectoryA] = 0048a9ce
    //         0054e479     TEST       EAX,EAX
    //         0054e47b     JZ         LAB_0054e499
    //         0054e47d     MOV        EAX,dword ptr [ESP + 0x4]
    //         0054e481     CMP        AH,0x3a
    //         0054e484     JNZ        LAB_0054e499
    //         0054e486     AND        EAX,0xff
    //         0054e48b     PUSH       EAX
    //         0054e48c     CALL       toupper                                          undefined toupper()
    //         0054e491     MOV        ESI,EAX
    //         0054e493     ADD        ESP,0x4
    //         0054e496     SUB        ESI,0x40
    //                               LAB_0054e499                                                 XREF[2]:     0054e47b(j), 0054e484(j)  
    //         0054e499     MOV        EAX,ESI
    //         0054e49b     POP        ESI
    //         0054e49c     ADD        ESP,0x104
    //         0054e4a2     RET
}

// Offset: 0x0054E4B0
undefined chdrive() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __chdrive()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __chdrive                                                    XREF[3]:     checkDrives:0044985b(c), 
    //                                                                                                         checkDrives:00449892(c), 
    //                                                                                                         changeDrive:00449a69(c)  
    //         0054e4b0     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054e4b4     CMP        EAX,0x1
    //         0054e4b7     JL         LAB_0054e4f3
    //         0054e4b9     CMP        EAX,0x1f
    //         0054e4bc     JG         LAB_0054e4f3
    //         0054e4be     ADD        AL,0x40
    //         0054e4c0     MOV        byte ptr [ESP + Stack[0x5]],0x3a
    //         0054e4c5     MOV        byte ptr [ESP + Stack[0x4]],AL
    //         0054e4c9     LEA        EAX=>Stack[0x4],[ESP + 0x4]
    //         0054e4cd     PUSH       EAX
    //         0054e4ce     MOV        byte ptr [ESP + Stack[0x6]],0x0
    //         0054e4d3     CALL       dword ptr [->KERNEL32.DLL::SetCurrentDirectoryA] = 0048b76e
    //         0054e4d9     TEST       EAX,EAX
    //         0054e4db     JZ         LAB_0054e4e0
    //         0054e4dd     XOR        EAX,EAX
    //         0054e4df     RET
    //                               LAB_0054e4e0                                                 XREF[1]:     0054e4db(j)  
    //         0054e4e0     CALL       dword ptr [->KERNEL32.DLL::GetLastError]         = 0048aa76
    //         0054e4e6     PUSH       EAX
    //         0054e4e7     CALL       __dosmaperr                                      undefined __dosmaperr()
    //         0054e4ec     ADD        ESP,0x4
    //         0054e4ef     OR         EAX,0xffffffff
    //         0054e4f2     RET
    //                               LAB_0054e4f3                                                 XREF[2]:     0054e4b7(j), 0054e4bc(j)  
    //         0054e4f3     MOV        dword ptr [_errno],0xd                           = align(4)
    //         0054e4fd     MOV        dword ptr [__doserrno],0xf
    //         0054e507     OR         EAX,0xffffffff
    //         0054e50a     RET
}

// Offset: 0x0054E510
undefined chdir() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __chdir()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __chdir                                                      XREF[1]:     changeDirectory:00449a98(c)  
    //         0054e510     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054e514     SUB        ESP,0x10c
    //         0054e51a     PUSH       EAX
    //         0054e51b     CALL       dword ptr [->KERNEL32.DLL::SetCurrentDirectoryA] = 0048b76e
    //         0054e521     TEST       EAX,EAX
    //         0054e523     JZ         LAB_0054e590
    //         0054e525     LEA        ECX,[ESP + 0x4]
    //         0054e529     PUSH       ECX
    //         0054e52a     PUSH       offset DAT_fffffff8
    //         0054e52f     CALL       dword ptr [->KERNEL32.DLL::GetCurrentDirectoryA] = 0048a9ce
    //         0054e535     TEST       EAX,EAX
    //         0054e537     JZ         LAB_0054e590
    //         0054e539     MOV        EAX,dword ptr [ESP + 0x4]
    //         0054e53d     CMP        AL,0x5c
    //         0054e53f     JZ         LAB_0054e545
    //         0054e541     CMP        AL,0x2f
    //         0054e543     JNZ        LAB_0054e552
    //                               LAB_0054e545                                                 XREF[1]:     0054e53f(j)  
    //         0054e545     CMP        AL,AH
    //         0054e547     JNZ        LAB_0054e552
    //         0054e549     XOR        EAX,EAX
    //         0054e54b     ADD        ESP,0x10c
    //         0054e551     RET
    //                               LAB_0054e552                                                 XREF[2]:     0054e543(j), 0054e547(j)  
    //         0054e552     AND        EAX,0xff
    //         0054e557     MOV        byte ptr [ESP],0x3d
    //         0054e55c     PUSH       EAX
    //         0054e55d     CALL       __mbctoupper                                     undefined __mbctoupper()
    //         0054e562     ADD        ESP,0x4
    //         0054e565     MOV        byte ptr [ESP + 0x1],AL
    //         0054e569     LEA        EDX,[ESP + 0x4]
    //         0054e56d     LEA        EAX,[ESP]
    //         0054e571     PUSH       EDX
    //         0054e572     PUSH       EAX=>DAT_fffffff8
    //         0054e573     MOV        byte ptr [ESP + 0xa],0x3a
    //         0054e578     MOV        byte ptr [ESP + 0xb],0x0
    //         0054e57d     CALL       dword ptr [->KERNEL32.DLL::SetEnvironmentVaria   = 0048b786
    //         0054e583     TEST       EAX,EAX
    //         0054e585     JZ         LAB_0054e590
    //         0054e587     XOR        EAX,EAX
    //         0054e589     ADD        ESP,0x10c
    //         0054e58f     RET
    //                               LAB_0054e590                                                 XREF[3]:     0054e523(j), 0054e537(j), 
    //                                                                                                         0054e585(j)  
    //         0054e590     CALL       dword ptr [->KERNEL32.DLL::GetLastError]         = 0048aa76
    //         0054e596     PUSH       EAX
    //         0054e597     CALL       __dosmaperr                                      undefined __dosmaperr()
    //         0054e59c     ADD        ESP,0x4
    //         0054e59f     OR         EAX,0xffffffff
    //         0054e5a2     ADD        ESP,0x10c
    //         0054e5a8     RET
}

// Offset: 0x0054E5B0
undefined splitpath() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __splitpath()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     0054e5c5(W), 0054e632(W), 0054e687(R), 0054e6c2(R)  
    //                               __splitpath                                                  XREF[1]:     updateDirectory:00449aff(c)  
    //         0054e5b0     PUSH       ECX
    //         0054e5b1     PUSH       EBX
    //         0054e5b2     PUSH       EBP
    //         0054e5b3     MOV        EBP,dword ptr [ESP + Stack[0x4]]
    //         0054e5b7     PUSH       ESI
    //         0054e5b8     PUSH       EDI
    //         0054e5b9     MOV        EDI,EBP
    //         0054e5bb     OR         ECX,0xffffffff
    //         0054e5be     XOR        EAX,EAX
    //         0054e5c0     SCASB.RE   ES:EDI
    //         0054e5c2     NOT        ECX
    //         0054e5c4     DEC        ECX
    //         0054e5c5     MOV        dword ptr [ESP + local_4],0x0
    //         0054e5cd     CMP        ECX,0x1
    //         0054e5d0     JC         LAB_0054e5f5
    //         0054e5d2     CMP        byte ptr [EBP + 0x1],0x3a
    //         0054e5d6     JNZ        LAB_0054e5f5
    //         0054e5d8     MOV        ESI,dword ptr [ESP + Stack[0x8]]
    //         0054e5dc     TEST       ESI,ESI
    //         0054e5de     JZ         LAB_0054e5f0
    //         0054e5e0     PUSH       0x2
    //         0054e5e2     PUSH       EBP
    //         0054e5e3     PUSH       ESI
    //         0054e5e4     CALL       __mbsnbcpy                                       undefined __mbsnbcpy()
    //         0054e5e9     ADD        ESP,0xc
    //         0054e5ec     MOV        byte ptr [ESI + 0x2],0x0
    //                               LAB_0054e5f0                                                 XREF[1]:     0054e5de(j)  
    //         0054e5f0     ADD        EBP,0x2
    //         0054e5f3     JMP        LAB_0054e600
    //                               LAB_0054e5f5                                                 XREF[2]:     0054e5d0(j), 0054e5d6(j)  
    //         0054e5f5     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         0054e5f9     TEST       EAX,EAX
    //         0054e5fb     JZ         LAB_0054e600
    //         0054e5fd     MOV        byte ptr [EAX],0x0
    //                               LAB_0054e600                                                 XREF[2]:     0054e5f3(j), 0054e5fb(j)  
    //         0054e600     MOV        CL,byte ptr [EBP]
    //         0054e603     XOR        EAX,EAX
    //         0054e605     TEST       CL,CL
    //         0054e607     MOV        dword ptr [ESP + Stack[0x8]],EAX
    //         0054e60b     MOV        ESI,EBP
    //         0054e60d     JZ         LAB_0054e64b
    //         0054e60f     MOV        CL,0x4
    //                               LAB_0054e611                                                 XREF[1]:     0054e645(j)  
    //         0054e611     MOV        AL,byte ptr [ESI]
    //         0054e613     MOV        EDX,EAX
    //         0054e615     AND        EDX,0xff
    //         0054e61b     TEST       byte ptr [EDX + __mbctype+1],CL
    //         0054e621     JZ         LAB_0054e626
    //         0054e623     INC        ESI
    //         0054e624     JMP        LAB_0054e63f
    //                               LAB_0054e626                                                 XREF[1]:     0054e621(j)  
    //         0054e626     CMP        AL,0x2f
    //         0054e628     JZ         LAB_0054e638
    //         0054e62a     CMP        AL,0x5c
    //         0054e62c     JZ         LAB_0054e638
    //         0054e62e     CMP        AL,0x2e
    //         0054e630     JNZ        LAB_0054e63f
    //         0054e632     MOV        dword ptr [ESP + local_4],ESI
    //         0054e636     JMP        LAB_0054e63f
    //                               LAB_0054e638                                                 XREF[2]:     0054e628(j), 0054e62c(j)  
    //         0054e638     LEA        EAX,[ESI + 0x1]
    //         0054e63b     MOV        dword ptr [ESP + Stack[0x8]],EAX
    //                               LAB_0054e63f                                                 XREF[3]:     0054e624(j), 0054e630(j), 
    //                                                                                                         0054e636(j)  
    //         0054e63f     MOV        AL,byte ptr [ESI + 0x1]
    //         0054e642     INC        ESI
    //         0054e643     TEST       AL,AL
    //         0054e645     JNZ        LAB_0054e611
    //         0054e647     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //                               LAB_0054e64b                                                 XREF[1]:     0054e60d(j)  
    //         0054e64b     TEST       EAX,EAX
    //         0054e64d     JZ         LAB_0054e67c
    //         0054e64f     MOV        EBX,dword ptr [ESP + Stack[0xc]]
    //         0054e653     TEST       EBX,EBX
    //         0054e655     JZ         LAB_0054e676
    //         0054e657     SUB        EAX,EBP
    //         0054e659     CMP        EAX,0xff
    //         0054e65e     MOV        EDI,EAX
    //         0054e660     JC         LAB_0054e667
    //         0054e662     MOV        EDI,0xff
    //                               LAB_0054e667                                                 XREF[1]:     0054e660(j)  
    //         0054e667     PUSH       EDI
    //         0054e668     PUSH       EBP
    //         0054e669     PUSH       EBX
    //         0054e66a     CALL       __mbsnbcpy                                       undefined __mbsnbcpy()
    //         0054e66f     ADD        ESP,0xc
    //         0054e672     MOV        byte ptr [EDI + EBX*0x1],0x0
    //                               LAB_0054e676                                                 XREF[1]:     0054e655(j)  
    //         0054e676     MOV        EBP,dword ptr [ESP + Stack[0x8]]
    //         0054e67a     JMP        LAB_0054e687
    //                               LAB_0054e67c                                                 XREF[1]:     0054e64d(j)  
    //         0054e67c     MOV        EAX,dword ptr [ESP + Stack[0xc]]
    //         0054e680     TEST       EAX,EAX
    //         0054e682     JZ         LAB_0054e687
    //         0054e684     MOV        byte ptr [EAX],0x0
    //                               LAB_0054e687                                                 XREF[2]:     0054e67a(j), 0054e682(j)  
    //         0054e687     MOV        EAX,dword ptr [ESP + local_4]
    //         0054e68b     TEST       EAX,EAX
    //         0054e68d     JZ         LAB_0054e6ea
    //         0054e68f     CMP        EAX,EBP
    //         0054e691     JC         LAB_0054e6ea
    //         0054e693     MOV        EBX,dword ptr [ESP + Stack[0x10]]
    //         0054e697     TEST       EBX,EBX
    //         0054e699     JZ         LAB_0054e6ba
    //         0054e69b     SUB        EAX,EBP
    //         0054e69d     CMP        EAX,0xff
    //         0054e6a2     MOV        EDI,EAX
    //         0054e6a4     JC         LAB_0054e6ab
    //         0054e6a6     MOV        EDI,0xff
    //                               LAB_0054e6ab                                                 XREF[1]:     0054e6a4(j)  
    //         0054e6ab     PUSH       EDI
    //         0054e6ac     PUSH       EBP
    //         0054e6ad     PUSH       EBX
    //         0054e6ae     CALL       __mbsnbcpy                                       undefined __mbsnbcpy()
    //         0054e6b3     ADD        ESP,0xc
    //         0054e6b6     MOV        byte ptr [EDI + EBX*0x1],0x0
    //                               LAB_0054e6ba                                                 XREF[1]:     0054e699(j)  
    //         0054e6ba     MOV        EDI,dword ptr [ESP + Stack[0x14]]
    //         0054e6be     TEST       EDI,EDI
    //         0054e6c0     JZ         LAB_0054e71b
    //         0054e6c2     MOV        EAX,dword ptr [ESP + local_4]
    //         0054e6c6     SUB        ESI,EAX
    //         0054e6c8     CMP        ESI,0xff
    //         0054e6ce     JC         LAB_0054e6d5
    //         0054e6d0     MOV        ESI,0xff
    //                               LAB_0054e6d5                                                 XREF[1]:     0054e6ce(j)  
    //         0054e6d5     PUSH       ESI
    //         0054e6d6     PUSH       EAX
    //         0054e6d7     PUSH       EDI
    //         0054e6d8     CALL       __mbsnbcpy                                       undefined __mbsnbcpy()
    //         0054e6dd     ADD        ESP,0xc
    //         0054e6e0     MOV        byte ptr [ESI + EDI*0x1],0x0
    //         0054e6e4     POP        EDI
    //         0054e6e5     POP        ESI
    //         0054e6e6     POP        EBP
    //         0054e6e7     POP        EBX
    //         0054e6e8     POP        ECX
    //         0054e6e9     RET
    //                               LAB_0054e6ea                                                 XREF[2]:     0054e68d(j), 0054e691(j)  
    //         0054e6ea     MOV        EDI,dword ptr [ESP + Stack[0x10]]
    //         0054e6ee     TEST       EDI,EDI
    //         0054e6f0     JZ         LAB_0054e710
    //         0054e6f2     SUB        ESI,EBP
    //         0054e6f4     CMP        ESI,0xff
    //         0054e6fa     JC         LAB_0054e701
    //         0054e6fc     MOV        ESI,0xff
    //                               LAB_0054e701                                                 XREF[1]:     0054e6fa(j)  
    //         0054e701     PUSH       ESI
    //         0054e702     PUSH       EBP
    //         0054e703     PUSH       EDI
    //         0054e704     CALL       __mbsnbcpy                                       undefined __mbsnbcpy()
    //         0054e709     ADD        ESP,0xc
    //         0054e70c     MOV        byte ptr [ESI + EDI*0x1],0x0
    //                               LAB_0054e710                                                 XREF[1]:     0054e6f0(j)  
    //         0054e710     MOV        EAX,dword ptr [ESP + Stack[0x14]]
    //         0054e714     TEST       EAX,EAX
    //         0054e716     JZ         LAB_0054e71b
    //         0054e718     MOV        byte ptr [EAX],0x0
    //                               LAB_0054e71b                                                 XREF[2]:     0054e6c0(j), 0054e716(j)  
    //         0054e71b     POP        EDI
    //         0054e71c     POP        ESI
    //         0054e71d     POP        EBP
    //         0054e71e     POP        EBX
    //         0054e71f     POP        ECX
    //         0054e720     RET
}

// Offset: 0x0054E730
undefined getcwd() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __getcwd()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __getcwd                                                     XREF[1]:     updateDirectory:00449ad6(c)  
    //         0054e730     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         0054e734     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         0054e738     PUSH       EAX
    //         0054e739     PUSH       ECX
    //         0054e73a     PUSH       0x0
    //         0054e73c     CALL       __getdcwd                                        undefined __getdcwd()
    //         0054e741     ADD        ESP,0xc
    //         0054e744     RET
}

// Offset: 0x0054E750
undefined getdcwd() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __getdcwd()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined         Stack[-0x104   local_104                 XREF[2]:     0054e793(*), 0054e7c1(*)  
    //              undefined         Stack[-0x108   local_108                 XREF[1]:     0054e78f(*)  
    //              undefined1        Stack[-0x109   local_109                 XREF[1]:     0054e7b4(W)  
    //              undefined1        Stack[-0x10a   local_10a                 XREF[1]:     0054e7af(W)  
    //              undefined1        Stack[-0x10b   local_10b                 XREF[1]:     0054e7aa(W)  
    //              undefined         Stack[-0x10c   local_10c                 XREF[2]:     0054e799(*), 0054e7a6(W)  
    //                               __getdcwd                                                    XREF[1]:     __getcwd:0054e73c(c)  
    //         0054e750     SUB        ESP,0x10c
    //         0054e756     PUSH       EBX
    //         0054e757     MOV        EBX,dword ptr [ESP + Stack[0x4]]
    //         0054e75e     PUSH       ESI
    //         0054e75f     PUSH       EDI
    //         0054e760     TEST       EBX,EBX
    //         0054e762     JZ         LAB_0054e7c1
    //         0054e764     PUSH       EBX
    //         0054e765     CALL       __validdrive                                     undefined __validdrive()
    //         0054e76a     ADD        ESP,0x4
    //         0054e76d     TEST       EAX,EAX
    //         0054e76f     JNZ        LAB_0054e78f
    //         0054e771     MOV        dword ptr [__doserrno],0xf
    //         0054e77b     MOV        dword ptr [_errno],0xd                           = align(4)
    //         0054e785     POP        EDI
    //         0054e786     POP        ESI
    //         0054e787     POP        EBX
    //         0054e788     ADD        ESP,0x10c
    //         0054e78e     RET
    //                               LAB_0054e78f                                                 XREF[1]:     0054e76f(j)  
    //         0054e78f     LEA        EAX=>local_108,[ESP + 0x10]
    //         0054e793     LEA        ECX=>local_104,[ESP + 0x14]
    //         0054e797     PUSH       EAX
    //         0054e798     PUSH       ECX
    //         0054e799     LEA        EDX=>local_10c,[ESP + 0x14]
    //         0054e79d     ADD        BL,0x40
    //         0054e7a0     PUSH       0x104
    //         0054e7a5     PUSH       EDX
    //         0054e7a6     MOV        byte ptr [ESP + local_10c],BL
    //         0054e7aa     MOV        byte ptr [ESP + local_10b],0x3a
    //         0054e7af     MOV        byte ptr [ESP + local_10a],0x2e
    //         0054e7b4     MOV        byte ptr [ESP + local_109],0x0
    //         0054e7b9     CALL       dword ptr [->KERNEL32.DLL::GetFullPathNameA]     = 0048b7a0
    //         0054e7bf     JMP        LAB_0054e7d1
    //                               LAB_0054e7c1                                                 XREF[1]:     0054e762(j)  
    //         0054e7c1     LEA        EAX=>local_104,[ESP + 0x14]
    //         0054e7c5     PUSH       EAX
    //         0054e7c6     PUSH       0x104
    //         0054e7cb     CALL       dword ptr [->KERNEL32.DLL::GetCurrentDirectoryA] = 0048a9ce
    //                               LAB_0054e7d1                                                 XREF[1]:     0054e7bf(j)  
    //         0054e7d1     TEST       EAX,EAX
    //         0054e7d3     JZ         LAB_0054e867
    //         0054e7d9     INC        EAX
    //         0054e7da     CMP        EAX,0x104
    //         0054e7df     JA         LAB_0054e867
    //         0054e7e5     MOV        EDX,dword ptr [ESP + 0x120]
    //         0054e7ec     MOV        ECX,dword ptr [ESP + 0x124]
    //         0054e7f3     TEST       EDX,EDX
    //         0054e7f5     JNZ        LAB_0054e820
    //         0054e7f7     CMP        EAX,ECX
    //         0054e7f9     JG         LAB_0054e7fd
    //         0054e7fb     MOV        EAX,ECX
    //                               LAB_0054e7fd                                                 XREF[1]:     0054e7f9(j)  
    //         0054e7fd     PUSH       EAX
    //         0054e7fe     CALL       malloc                                           undefined malloc()
    //         0054e803     MOV        EDX,EAX
    //         0054e805     ADD        ESP,0x4
    //         0054e808     TEST       EDX,EDX
    //         0054e80a     JNZ        LAB_0054e83a
    //         0054e80c     MOV        dword ptr [_errno],0xc                           = align(4)
    //         0054e816     POP        EDI
    //         0054e817     POP        ESI
    //         0054e818     POP        EBX
    //         0054e819     ADD        ESP,0x10c
    //         0054e81f     RET
    //                               LAB_0054e820                                                 XREF[1]:     0054e7f5(j)  
    //         0054e820     CMP        EAX,ECX
    //         0054e822     JLE        LAB_0054e83a
    //         0054e824     MOV        dword ptr [_errno],0x22                          = align(4)
    //         0054e82e     XOR        EAX,EAX
    //         0054e830     POP        EDI
    //         0054e831     POP        ESI
    //         0054e832     POP        EBX
    //         0054e833     ADD        ESP,0x10c
    //         0054e839     RET
    //                               LAB_0054e83a                                                 XREF[2]:     0054e80a(j), 0054e822(j)  
    //         0054e83a     LEA        EDI,[ESP + 0x14]
    //         0054e83e     OR         ECX,0xffffffff
    //         0054e841     XOR        EAX,EAX
    //         0054e843     SCASB.RE   ES:EDI
    //         0054e845     NOT        ECX
    //         0054e847     SUB        EDI,ECX
    //         0054e849     MOV        ESI,EDI
    //         0054e84b     MOV        EBX,ECX
    //         0054e84d     MOV        EDI,EDX
    //         0054e84f     MOV        EAX,EDI
    //         0054e851     SHR        ECX,0x2
    //         0054e854     MOVSD.REP  ES:EDI,ESI
    //         0054e856     MOV        ECX,EBX
    //         0054e858     AND        ECX,0x3
    //         0054e85b     MOVSB.REP  ES:EDI,ESI
    //         0054e85d     POP        EDI
    //         0054e85e     POP        ESI
    //         0054e85f     POP        EBX
    //         0054e860     ADD        ESP,0x10c
    //         0054e866     RET
    //                               LAB_0054e867                                                 XREF[2]:     0054e7d3(j), 0054e7df(j)  
    //         0054e867     POP        EDI
    //         0054e868     POP        ESI
    //         0054e869     XOR        EAX,EAX
    //         0054e86b     POP        EBX
    //         0054e86c     ADD        ESP,0x10c
    //         0054e872     RET
}

// Offset: 0x0054E880
undefined validdrive() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __validdrive()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __validdrive                                                 XREF[1]:     __getdcwd:0054e765(c)  
    //         0054e880     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054e884     TEST       EAX,EAX
    //         0054e886     JNZ        LAB_0054e88e
    //         0054e888     MOV        EAX,0x1
    //         0054e88d     RET
    //                               LAB_0054e88e                                                 XREF[1]:     0054e886(j)  
    //         0054e88e     ADD        AL,0x40
    //         0054e890     MOV        byte ptr [ESP + Stack[0x5]],0x3a
    //         0054e895     MOV        byte ptr [ESP + Stack[0x4]],AL
    //         0054e899     LEA        EAX=>Stack[0x4],[ESP + 0x4]
    //         0054e89d     PUSH       EAX
    //         0054e89e     MOV        byte ptr [ESP + Stack[0x6]],0x5c
    //         0054e8a3     MOV        byte ptr [ESP + Stack[0x7]],0x0
    //         0054e8a8     CALL       dword ptr [->KERNEL32.DLL::GetDriveTypeA]        = 0048aa56
    //         0054e8ae     TEST       EAX,EAX
    //         0054e8b0     JZ         LAB_0054e8bd
    //         0054e8b2     CMP        EAX,0x1
    //         0054e8b5     JZ         LAB_0054e8bd
    //         0054e8b7     MOV        EAX,0x1
    //         0054e8bc     RET
    //                               LAB_0054e8bd                                                 XREF[2]:     0054e8b0(j), 0054e8b5(j)  
    //         0054e8bd     XOR        EAX,EAX
    //         0054e8bf     RET
}

// Offset: 0x0054E8C0
undefined floor() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * floor                                                                                                 *
    //                              *********************************************************************************************************
    //                              undefined __cdecl floor()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined8        Stack[-0x8]:8  local_8                   XREF[4,1]:   0054e965(W), 0054e969(R), 0054e98b(R), 0054e99d(R), 
    //                                                                                     0054e999(R)  
    //              undefined8        Stack[-0x20]:8 local_20                  XREF[1]:     0054e948(*)  
    //                               _floor                                                       XREF[46]:    doMove:0045e1de(c), 
    //                               floor                                                                     doMove:0045e1fa(c), 
    //                                                                                                         doMove:0045e230(c), 
    //                                                                                                         doMove:0045e25a(c), 
    //                                                                                                         doMove:0045e284(c), 
    //                                                                                                         doMove:0045e2a0(c), 
    //                                                                                                         doMove:0045e6ef(c), 
    //                                                                                                         doMove:0045e70b(c), 
    //                                                                                                         doMove:0045e741(c), 
    //                                                                                                         doMove:0045e76b(c), 
    //                                                                                                         doMove:0045e7cc(c), 
    //                                                                                                         doMove:0045e7e8(c), 
    //                                                                                                         doTrivialMove:0045eabd(c), 
    //                                                                                                         doTrivialMove:0045eadd(c), 
    //                                                                                                         doTrivialMove:0045ed86(c), 
    //                                                                                                         findTilePath:0046b9ee(c), 
    //                                                                                                         findTilePath:0046ba0f(c), 
    //                                                                                                         findTilePath:0046ba4f(c), 
    //                                                                                                         findTilePath:0046ba69(c), 
    //                                                                                                         passable:0046d2dd(c), [more]
    //         0054e8c0     MOV        EAX,[DAT_0058fb90]                               = 0000173Fh
    //         0054e8c5     SUB        ESP,0x8
    //         0054e8c8     PUSH       EBX
    //         0054e8c9     PUSH       ESI
    //         0054e8ca     PUSH       EDI
    //         0054e8cb     PUSH       0xffff
    //         0054e8d0     PUSH       EAX
    //         0054e8d1     CALL       __ctrlfp                                         undefined __ctrlfp()
    //         0054e8d6     MOV        ECX,dword ptr [ESP + Stack[0xa]]
    //         0054e8da     MOV        ESI,dword ptr [ESP + Stack[0x8]]
    //         0054e8de     MOV        EDI,dword ptr [ESP + Stack[0x4]]
    //         0054e8e2     ADD        ESP,0x8
    //         0054e8e5     AND        ECX,0x7ff0
    //         0054e8eb     MOV        EBX,EAX
    //         0054e8ed     CMP        ECX,0x7ff0
    //         0054e8f3     PUSH       ESI
    //         0054e8f4     PUSH       EDI
    //         0054e8f5     JNZ        LAB_0054e960
    //         0054e8f7     CALL       __sptype                                         undefined __sptype()
    //         0054e8fc     ADD        ESP,0x8
    //         0054e8ff     TEST       EAX,EAX
    //         0054e901     JLE        LAB_0054e93a
    //         0054e903     CMP        EAX,0x2
    //         0054e906     JLE        LAB_0054e921
    //         0054e908     CMP        EAX,0x3
    //         0054e90b     JNZ        LAB_0054e93a
    //         0054e90d     PUSH       EBX
    //         0054e90e     PUSH       ESI
    //         0054e90f     PUSH       EDI
    //         0054e910     PUSH       0xb
    //         0054e912     CALL       __handle_qnan1                                   undefined __handle_qnan1()
    //         0054e917     ADD        ESP,0x10
    //         0054e91a     POP        EDI
    //         0054e91b     POP        ESI
    //         0054e91c     POP        EBX
    //         0054e91d     ADD        ESP,0x8
    //         0054e920     RET
    //                               LAB_0054e921                                                 XREF[1]:     0054e906(j)  
    //         0054e921     PUSH       0xffff
    //         0054e926     PUSH       EBX
    //         0054e927     CALL       __ctrlfp                                         undefined __ctrlfp()
    //         0054e92c     FLD        double ptr [ESP + Stack[0x4]]
    //         0054e930     ADD        ESP,0x8
    //         0054e933     POP        EDI
    //         0054e934     POP        ESI
    //         0054e935     POP        EBX
    //         0054e936     ADD        ESP,0x8
    //         0054e939     RET
    //                               LAB_0054e93a                                                 XREF[2]:     0054e901(j), 0054e90b(j)  
    //         0054e93a     FLD        double ptr [ESP + Stack[0x4]]
    //         0054e93e     FSUB       double ptr [DAT_00577a88]
    //         0054e944     PUSH       EBX
    //         0054e945     SUB        ESP,0x8
    //         0054e948     FSTP       double ptr [ESP]=>local_20
    //         0054e94b     PUSH       ESI
    //         0054e94c     PUSH       EDI
    //         0054e94d     PUSH       0xb
    //         0054e94f     PUSH       0x8
    //         0054e951     CALL       __except1                                        undefined __except1()
    //         0054e956     ADD        ESP,0x1c
    //         0054e959     POP        EDI
    //         0054e95a     POP        ESI
    //         0054e95b     POP        EBX
    //         0054e95c     ADD        ESP,0x8
    //         0054e95f     RET
    //                               LAB_0054e960                                                 XREF[1]:     0054e8f5(j)  
    //         0054e960     CALL       __frnd                                           undefined __frnd()
    //         0054e965     FSTP       double ptr [ESP + local_8]
    //         0054e969     FLD        double ptr [ESP + local_8]
    //         0054e96d     FCOMP      double ptr [ESP + Stack[0x4]]
    //         0054e971     ADD        ESP,0x8
    //         0054e974     FNSTSW     AX
    //         0054e976     TEST       AH,0x40
    //         0054e979     JNZ        LAB_0054e980
    //         0054e97b     TEST       BL,0x20
    //         0054e97e     JZ         LAB_0054e999
    //                               LAB_0054e980                                                 XREF[1]:     0054e979(j)  
    //         0054e980     PUSH       0xffff
    //         0054e985     PUSH       EBX
    //         0054e986     CALL       __ctrlfp                                         undefined __ctrlfp()
    //         0054e98b     FLD        double ptr [ESP + local_8]
    //         0054e98f     ADD        ESP,0x8
    //         0054e992     POP        EDI
    //         0054e993     POP        ESI
    //         0054e994     POP        EBX
    //         0054e995     ADD        ESP,0x8
    //         0054e998     RET
    //                               LAB_0054e999                                                 XREF[1]:     0054e97e(j)  
    //         0054e999     MOV        EDX,dword ptr [ESP + local_8+0x4]
    //         0054e99d     MOV        EAX,dword ptr [ESP + local_8]
    //         0054e9a1     PUSH       EBX
    //         0054e9a2     PUSH       EDX
    //         0054e9a3     PUSH       EAX
    //         0054e9a4     PUSH       ESI
    //         0054e9a5     PUSH       EDI
    //         0054e9a6     PUSH       0xb
    //         0054e9a8     PUSH       0x10
    //         0054e9aa     CALL       __except1                                        undefined __except1()
    //         0054e9af     ADD        ESP,0x1c
    //         0054e9b2     POP        EDI
    //         0054e9b3     POP        ESI
    //         0054e9b4     POP        EBX
    //         0054e9b5     ADD        ESP,0x8
    //         0054e9b8     RET
}

// Offset: 0x0054E9B9
undefined FUN_0054e9b9() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054e9b9()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054e9b9
    //         0054e9b9     NOP
    //         0054e9ba     NOP
    //         0054e9bb     NOP
    //         0054e9bc     NOP
    //         0054e9bd     NOP
    //         0054e9be     NOP
    //         0054e9bf     NOP
    //                               LAB_0054e9c0                                                 XREF[1]:     strchr:0054e9ed(j)  
    //         0054e9c0     LEA        EAX,[EDX + -0x1]
    //         0054e9c3     POP        EBX
    //         0054e9c4     RET
}

// Offset: 0x0054E9C5
undefined FUN_0054e9c5() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054e9c5()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054e9c5
    //         0054e9c5     MOV        EAX,EAX
    //         0054e9c8     MOV        EAX,EAX
    //         0054e9cb     MOV        EAX,EAX
    //         0054e9ce     MOV        EAX,EAX
}

// Offset: 0x0054E9D0
undefined strchr() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * strchr                                                                                                *
    //                              *********************************************************************************************************
    //                              undefined __cdecl strchr()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _strchr                                                      XREF[13]:    play:00462329(c), 
    //                               strchr                                                                    get_palette:004642de(c), 
    //                                                                                                         setup:00466bf3(c), 
    //                                                                                                         set_background:00467ad8(c), 
    //                                                                                                         set_background2:00467c48(c), 
    //                                                                                                         set_button_pics:004680c8(c), 
    //                                                                                                         set_text:0047238b(c), 
    //                                                                                                         TribeMPStartupScreen:0049f769(c), 
    //                                                                                                         set_background:0051ec84(c), 
    //                                                                                                         set_special_events:0051ef54(c), 
    //                                                                                                         setup_cmd_options:005221b0(c), 
    //                                                                                                         save_game:00524713(c), 
    //                                                                                                         __mbschr:0054ec15(c)  
    //         0054e9d0     XOR        EAX,EAX
    //         0054e9d2     MOV        AL,byte ptr [ESP + Stack[0x8]]
    //                               ___from_strstr_to_strchr                                     XREF[1]:     strstr:0054ba0e(j)  
    //         0054e9d6     PUSH       EBX
    //         0054e9d7     MOV        EBX,EAX
    //         0054e9d9     SHL        EAX,0x8
    //         0054e9dc     MOV        EDX,dword ptr [ESP + Stack[0x4]]
    //         0054e9e0     TEST       EDX,0x3
    //         0054e9e6     JZ         LAB_0054e9fb
    //                               LAB_0054e9e8                                                 XREF[1]:     0054e9f9(j)  
    //         0054e9e8     MOV        CL,byte ptr [EDX]
    //         0054e9ea     INC        EDX
    //         0054e9eb     CMP        CL,BL
    //         0054e9ed     JZ         LAB_0054e9c0
    //         0054e9ef     TEST       CL,CL
    //         0054e9f1     JZ         LAB_0054ea44
    //         0054e9f3     TEST       EDX,0x3
    //         0054e9f9     JNZ        LAB_0054e9e8
    //                               LAB_0054e9fb                                                 XREF[1]:     0054e9e6(j)  
    //         0054e9fb     OR         EBX,EAX
    //         0054e9fd     PUSH       EDI
    //         0054e9fe     MOV        EAX,EBX
    //         0054ea00     SHL        EBX,0x10
    //         0054ea03     PUSH       ESI
    //         0054ea04     OR         EBX,EAX
    //                               LAB_0054ea06                                                 XREF[3]:     0054ea31(j), 0054ea40(j), 
    //                                                                                                         0054ea6e(j)  
    //         0054ea06     MOV        ECX,dword ptr [EDX]
    //         0054ea08     MOV        EDI,0x7efefeff
    //         0054ea0d     MOV        EAX,ECX
    //         0054ea0f     MOV        ESI,EDI
    //         0054ea11     XOR        ECX,EBX
    //         0054ea13     ADD        ESI,EAX
    //         0054ea15     ADD        EDI,ECX
    //         0054ea17     XOR        ECX,0xffffffff
    //         0054ea1a     XOR        EAX,0xffffffff
    //         0054ea1d     XOR        ECX,EDI
    //         0054ea1f     XOR        EAX,ESI
    //         0054ea21     ADD        EDX,0x4
    //         0054ea24     AND        ECX,0x81010100
    //         0054ea2a     JNZ        LAB_0054ea48
    //         0054ea2c     AND        EAX,0x81010100
    //         0054ea31     JZ         LAB_0054ea06
    //         0054ea33     AND        EAX,0x1010100
    //         0054ea38     JNZ        LAB_0054ea42
    //         0054ea3a     AND        ESI,0x80000000
    //         0054ea40     JNZ        LAB_0054ea06
    //                               LAB_0054ea42                                                 XREF[5]:     0054ea38(j), 0054ea51(j), 
    //                                                                                                         0054ea59(j), 0054ea64(j), 
    //                                                                                                         0054ea6c(j)  
    //         0054ea42     POP        ESI
    //         0054ea43     POP        EDI
    //                               LAB_0054ea44                                                 XREF[1]:     0054e9f1(j)  
    //         0054ea44     POP        EBX
    //         0054ea45     XOR        EAX,EAX
    //         0054ea47     RET
    //                               LAB_0054ea48                                                 XREF[1]:     0054ea2a(j)  
    //         0054ea48     MOV        EAX,dword ptr [EDX + -0x4]
    //         0054ea4b     CMP        AL,BL
    //         0054ea4d     JZ         LAB_0054ea85
    //         0054ea4f     TEST       AL,AL
    //         0054ea51     JZ         LAB_0054ea42
    //         0054ea53     CMP        AH,BL
    //         0054ea55     JZ         LAB_0054ea7e
    //         0054ea57     TEST       AH,AH
    //         0054ea59     JZ         LAB_0054ea42
    //         0054ea5b     SHR        EAX,0x10
    //         0054ea5e     CMP        AL,BL
    //         0054ea60     JZ         LAB_0054ea77
    //         0054ea62     TEST       AL,AL
    //         0054ea64     JZ         LAB_0054ea42
    //         0054ea66     CMP        AH,BL
    //         0054ea68     JZ         LAB_0054ea70
    //         0054ea6a     TEST       AH,AH
    //         0054ea6c     JZ         LAB_0054ea42
    //         0054ea6e     JMP        LAB_0054ea06
    //                               LAB_0054ea70                                                 XREF[1]:     0054ea68(j)  
    //         0054ea70     POP        ESI
    //         0054ea71     POP        EDI
    //         0054ea72     LEA        EAX,[EDX + -0x1]
    //         0054ea75     POP        EBX
    //         0054ea76     RET
    //                               LAB_0054ea77                                                 XREF[1]:     0054ea60(j)  
    //         0054ea77     LEA        EAX,[EDX + -0x2]
    //         0054ea7a     POP        ESI
    //         0054ea7b     POP        EDI
    //         0054ea7c     POP        EBX
    //         0054ea7d     RET
    //                               LAB_0054ea7e                                                 XREF[1]:     0054ea55(j)  
    //         0054ea7e     LEA        EAX,[EDX + -0x3]
    //         0054ea81     POP        ESI
    //         0054ea82     POP        EDI
    //         0054ea83     POP        EBX
    //         0054ea84     RET
    //                               LAB_0054ea85                                                 XREF[1]:     0054ea4d(j)  
    //         0054ea85     LEA        EAX,[EDX + -0x4]
    //         0054ea88     POP        ESI
    //         0054ea89     POP        EDI
    //         0054ea8a     POP        EBX
    //         0054ea8b     RET
}

// Offset: 0x0054EA90
undefined onexit() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __onexit()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __onexit                                                     XREF[1]:     atexit:0054eb15(c)  
    //         0054ea90     MOV        EAX,[___onexitbegin]
    //         0054ea95     PUSH       ESI
    //         0054ea96     PUSH       EAX
    //         0054ea97     CALL       __msize                                          undefined __msize()
    //         0054ea9c     MOV        ECX,dword ptr [___onexitend]
    //         0054eaa2     MOV        EDX,dword ptr [___onexitbegin]
    //         0054eaa8     MOV        ESI,ECX
    //         0054eaaa     ADD        ESP,0x4
    //         0054eaad     SUB        ESI,EDX
    //         0054eaaf     ADD        ESI,0x4
    //         0054eab2     CMP        EAX,ESI
    //         0054eab4     JNC        LAB_0054eaf7
    //         0054eab6     PUSH       EDX
    //         0054eab7     CALL       __msize                                          undefined __msize()
    //         0054eabc     MOV        ECX,dword ptr [___onexitbegin]
    //         0054eac2     ADD        ESP,0x4
    //         0054eac5     ADD        EAX,0x10
    //         0054eac8     PUSH       EAX
    //         0054eac9     PUSH       ECX
    //         0054eaca     CALL       realloc                                          undefined realloc()
    //         0054eacf     ADD        ESP,0x8
    //         0054ead2     TEST       EAX,EAX
    //         0054ead4     JNZ        LAB_0054ead8
    //         0054ead6     POP        ESI
    //         0054ead7     RET
    //                               LAB_0054ead8                                                 XREF[1]:     0054ead4(j)  
    //         0054ead8     MOV        EDX,dword ptr [___onexitend]
    //         0054eade     MOV        ESI,dword ptr [___onexitbegin]
    //         0054eae4     SUB        EDX,ESI
    //         0054eae6     MOV        [___onexitbegin],EAX
    //         0054eaeb     SAR        EDX,0x2
    //         0054eaee     LEA        ECX,[EAX + EDX*0x4]
    //         0054eaf1     MOV        dword ptr [___onexitend],ECX
    //                               LAB_0054eaf7                                                 XREF[1]:     0054eab4(j)  
    //         0054eaf7     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054eafb     POP        ESI
    //         0054eafc     MOV        dword ptr [ECX],EAX
    //         0054eafe     MOV        ECX,dword ptr [___onexitend]
    //         0054eb04     ADD        ECX,0x4
    //         0054eb07     MOV        dword ptr [___onexitend],ECX
    //         0054eb0d     RET
}

// Offset: 0x0054EB10
undefined atexit() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * atexit                                                                                                *
    //                              *********************************************************************************************************
    //                              undefined __cdecl atexit()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _atexit                                                      XREF[6]:     $E3:00463bc5(c), $E11:0046b085(c), 
    //                               atexit                                                                    $E16:0046b0d5(c), 
    //                                                                                                         $E11:004d6af5(c), 
    //                                                                                                         $E16:004d6b45(c), 
    //                                                                                                         $E21:004d6b95(c)  
    //         0054eb10     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054eb14     PUSH       EAX
    //         0054eb15     CALL       __onexit                                         undefined __onexit()
    //         0054eb1a     ADD        ESP,0x4
    //         0054eb1d     NEG        EAX
    //         0054eb1f     SBB        EAX,EAX
    //         0054eb21     NEG        EAX
    //         0054eb23     DEC        EAX
    //         0054eb24     RET
}

// Offset: 0x0054EB25
undefined FUN_0054eb25() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054eb25()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054eb25
    //         0054eb25     NOP
    //         0054eb26     NOP
    //         0054eb27     NOP
    //         0054eb28     NOP
    //         0054eb29     NOP
    //         0054eb2a     NOP
    //         0054eb2b     NOP
    //         0054eb2c     NOP
    //         0054eb2d     NOP
    //         0054eb2e     NOP
    //         0054eb2f     NOP
    //                              language.dll match for 0x80: "Arial"
    //                               ___onexitinit
    //         0054eb30     PUSH       0x80
    //         0054eb35     CALL       malloc                                           undefined malloc()
    //         0054eb3a     ADD        ESP,0x4
    //         0054eb3d     MOV        [___onexitbegin],EAX
    //         0054eb42     TEST       EAX,EAX
    //         0054eb44     JNZ        LAB_0054eb55
    //         0054eb46     PUSH       0x18
    //         0054eb48     CALL       __amsg_exit                                      undefined __amsg_exit()
    //         0054eb4d     MOV        EAX,[___onexitbegin]
    //         0054eb52     ADD        ESP,0x4
    //                               LAB_0054eb55                                                 XREF[1]:     0054eb44(j)  
    //         0054eb55     MOV        dword ptr [EAX],0x0
    //         0054eb5b     MOV        EAX,[___onexitbegin]
    //         0054eb60     MOV        [___onexitend],EAX
    //         0054eb65     RET
}

// Offset: 0x0054EB70
undefined stricmp() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * stricmp                                                                                               *
    //                              *********************************************************************************************************
    //                              undefined __cdecl stricmp()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __strcmpi                                                    XREF[8]:     check_for_cd:0041fdc1(c), 
    //                               __stricmp                                                                 setup:00466ee7(c), 
    //                               _stricmp                                                                  set_background:00467ac9(c), 
    //                               stricmp                                                                   set_background2:00467c39(c), 
    //                                                                                                         set_palette:00467e23(c), 
    //                                                                                                         set_button_pics:004680b9(c), 
    //                                                                                                         set_background:0051ec75(c), 
    //                                                                                                         set_special_events:0051ef45(c)  
    //         0054eb70     PUSH       EBP
    //         0054eb71     MOV        EBP,ESP
    //         0054eb73     PUSH       EDI
    //         0054eb74     PUSH       ESI
    //         0054eb75     PUSH       EBX
    //         0054eb76     MOV        ESI,dword ptr [EBP + Stack[0x8]]
    //         0054eb79     MOV        EDI,dword ptr [EBP + Stack[0x4]]
    //         0054eb7c     LEA        EAX,[___lc_handle]                               = align(8)
    //         0054eb82     CMP        dword ptr [EAX + 0x8]=>DAT_008882c0,0x0
    //         0054eb86     JNZ        LAB_0054ebc3
    //         0054eb88     MOV        AL,0xff
    //         0054eb8a     MOV        EAX,EAX
    //                               LAB_0054eb8c                                                 XREF[2]:     0054eb98(j), 0054ebb8(j)  
    //         0054eb8c     OR         AL,AL
    //         0054eb8e     JZ         LAB_0054ebbe
    //         0054eb90     MOV        AL,byte ptr [ESI]
    //         0054eb92     INC        ESI
    //         0054eb93     MOV        AH,byte ptr [EDI]
    //         0054eb95     INC        EDI
    //         0054eb96     CMP        AH,AL
    //         0054eb98     JZ         LAB_0054eb8c
    //         0054eb9a     SUB        AL,0x41
    //         0054eb9c     CMP        AL,0x1a
    //         0054eb9e     SBB        CL,CL
    //         0054eba0     AND        CL,0x20
    //         0054eba3     ADD        AL,CL
    //         0054eba5     ADD        AL,0x41
    //         0054eba7     XCHG       AL,AH
    //         0054eba9     SUB        AL,0x41
    //         0054ebab     CMP        AL,0x1a
    //         0054ebad     SBB        CL,CL
    //         0054ebaf     AND        CL,0x20
    //         0054ebb2     ADD        AL,CL
    //         0054ebb4     ADD        AL,0x41
    //         0054ebb6     CMP        AL,AH
    //         0054ebb8     JZ         LAB_0054eb8c
    //         0054ebba     SBB        AL,AL
    //         0054ebbc     SBB        AL,0xff
    //                               LAB_0054ebbe                                                 XREF[1]:     0054eb8e(j)  
    //         0054ebbe     MOVSX      EAX,AL
    //         0054ebc1     JMP        LAB_0054ebf7
    //                               LAB_0054ebc3                                                 XREF[1]:     0054eb86(j)  
    //         0054ebc3     MOV        EAX,0xff
    //         0054ebc8     XOR        EBX,EBX
    //         0054ebca     MOV        EAX,EAX
    //                               LAB_0054ebcc                                                 XREF[2]:     0054ebd8(j), 0054ebf0(j)  
    //         0054ebcc     OR         AL,AL
    //         0054ebce     JZ         LAB_0054ebf7
    //         0054ebd0     MOV        AL,byte ptr [ESI]
    //         0054ebd2     INC        ESI
    //         0054ebd3     MOV        BL,byte ptr [EDI]
    //         0054ebd5     INC        EDI
    //         0054ebd6     CMP        AL,BL
    //         0054ebd8     JZ         LAB_0054ebcc
    //         0054ebda     PUSH       EAX
    //         0054ebdb     PUSH       EBX
    //         0054ebdc     CALL       tolower                                          undefined tolower()
    //         0054ebe1     MOV        EBX,EAX
    //         0054ebe3     ADD        ESP,0x4
    //         0054ebe6     CALL       tolower                                          undefined tolower()
    //         0054ebeb     ADD        ESP,0x4
    //         0054ebee     CMP        BL,AL
    //         0054ebf0     JZ         LAB_0054ebcc
    //         0054ebf2     SBB        EAX,EAX
    //         0054ebf4     SBB        EAX,-0x1
    //                               LAB_0054ebf7                                                 XREF[2]:     0054ebc1(j), 0054ebce(j)  
    //         0054ebf7     POP        EBX
    //         0054ebf8     POP        ESI
    //         0054ebf9     POP        EDI
    //         0054ebfa     LEAVE
    //         0054ebfb     RET
}

// Offset: 0x0054EC00
undefined mbschr() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __mbschr()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __mbschr                                                     XREF[7]:     verify_char:00476596(c), 
    //                                                                                                         verify_char:004765df(c), 
    //                                                                                                         char_action:004770ab(c), 
    //                                                                                                         char_action:004770df(c), 
    //                                                                                                         set_text:0047c5d9(c), 
    //                                                                                                         load_game:0052643d(c), 
    //                                                                                                         ___crtsetenv:0055a424(c)  
    //         0054ec00     MOV        EAX,[___mbcodepage]
    //         0054ec05     PUSH       EBX
    //         0054ec06     TEST       EAX,EAX
    //         0054ec08     PUSH       ESI
    //         0054ec09     JNZ        LAB_0054ec20
    //         0054ec0b     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         0054ec0f     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         0054ec13     PUSH       EAX
    //         0054ec14     PUSH       ECX
    //         0054ec15     CALL       strchr                                           undefined strchr()
    //         0054ec1a     ADD        ESP,0x8
    //         0054ec1d     POP        ESI
    //         0054ec1e     POP        EBX
    //         0054ec1f     RET
    //                               LAB_0054ec20                                                 XREF[1]:     0054ec09(j)  
    //         0054ec20     MOV        EDX,dword ptr [ESP + Stack[0x4]]
    //         0054ec24     MOV        ESI,dword ptr [ESP + Stack[0x8]]
    //         0054ec28     MOVZX      AX,byte ptr [EDX]
    //         0054ec2c     TEST       AX,AX
    //         0054ec2f     JZ         LAB_0054ec97
    //         0054ec31     MOV        BL,0x4
    //                               LAB_0054ec33                                                 XREF[1]:     0054ec76(j)  
    //         0054ec33     MOV        ECX,EAX
    //         0054ec35     AND        ECX,0xff
    //         0054ec3b     TEST       byte ptr [ECX + __mbctype+1],BL
    //         0054ec41     JZ         LAB_0054ec61
    //         0054ec43     MOV        CL,byte ptr [EDX + 0x1]
    //         0054ec46     INC        EDX
    //         0054ec47     TEST       CL,CL
    //         0054ec49     JZ         LAB_0054ec8c
    //         0054ec4b     AND        EAX,0xffff
    //         0054ec50     AND        ECX,0xff
    //         0054ec56     SHL        EAX,0x8
    //         0054ec59     OR         EAX,ECX
    //         0054ec5b     CMP        ESI,EAX
    //         0054ec5d     JZ         LAB_0054ec91
    //         0054ec5f     JMP        LAB_0054ec6d
    //                               LAB_0054ec61                                                 XREF[1]:     0054ec41(j)  
    //         0054ec61     MOV        ECX,EAX
    //         0054ec63     AND        ECX,0xffff
    //         0054ec69     CMP        ESI,ECX
    //         0054ec6b     JZ         LAB_0054ec97
    //                               LAB_0054ec6d                                                 XREF[1]:     0054ec5f(j)  
    //         0054ec6d     MOVZX      AX,byte ptr [EDX + 0x1]
    //         0054ec72     INC        EDX
    //         0054ec73     TEST       AX,AX
    //         0054ec76     JNZ        LAB_0054ec33
    //         0054ec78     AND        EAX,0xffff
    //         0054ec7d     XOR        ECX,ECX
    //         0054ec7f     CMP        ESI,EAX
    //         0054ec81     SETNZ      CL
    //         0054ec84     DEC        ECX
    //         0054ec85     AND        ECX,EDX
    //         0054ec87     MOV        EAX,ECX
    //         0054ec89     POP        ESI
    //         0054ec8a     POP        EBX
    //         0054ec8b     RET
    //                               LAB_0054ec8c                                                 XREF[1]:     0054ec49(j)  
    //         0054ec8c     XOR        EAX,EAX
    //         0054ec8e     POP        ESI
    //         0054ec8f     POP        EBX
    //         0054ec90     RET
    //                               LAB_0054ec91                                                 XREF[1]:     0054ec5d(j)  
    //         0054ec91     LEA        EAX,[EDX + -0x1]
    //         0054ec94     POP        ESI
    //         0054ec95     POP        EBX
    //         0054ec96     RET
    //                               LAB_0054ec97                                                 XREF[2]:     0054ec2f(j), 0054ec6b(j)  
    //         0054ec97     AND        EAX,0xffff
    //         0054ec9c     XOR        ECX,ECX
    //         0054ec9e     CMP        ESI,EAX
    //         0054eca0     POP        ESI
    //         0054eca1     SETNZ      CL
    //         0054eca4     DEC        ECX
    //         0054eca5     POP        EBX
    //         0054eca6     AND        ECX,EDX
    //         0054eca8     MOV        EAX,ECX
    //         0054ecaa     RET
}

// Offset: 0x0054ECB0
undefined mbscmp() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __mbscmp()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __mbscmp                                                     XREF[2]:     verify_char:00476547(c), 
    //                                                                                                         char_action:0047705e(c)  
    //         0054ecb0     MOV        EAX,[___mbcodepage]
    //         0054ecb5     PUSH       EBX
    //         0054ecb6     PUSH       ESI
    //         0054ecb7     PUSH       EDI
    //         0054ecb8     TEST       EAX,EAX
    //         0054ecba     JNZ        LAB_0054ecfb
    //         0054ecbc     MOV        ESI,dword ptr [ESP + Stack[0x8]]
    //         0054ecc0     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //                               LAB_0054ecc4                                                 XREF[1]:     0054ecea(j)  
    //         0054ecc4     MOV        DL,byte ptr [EAX]
    //         0054ecc6     MOV        BL,byte ptr [ESI]
    //         0054ecc8     MOV        CL,DL
    //         0054ecca     CMP        DL,BL
    //         0054eccc     JNZ        LAB_0054ecf2
    //         0054ecce     TEST       CL,CL
    //         0054ecd0     JZ         LAB_0054ed6c
    //         0054ecd6     MOV        DL,byte ptr [EAX + 0x1]
    //         0054ecd9     MOV        BL,byte ptr [ESI + 0x1]
    //         0054ecdc     MOV        CL,DL
    //         0054ecde     CMP        DL,BL
    //         0054ece0     JNZ        LAB_0054ecf2
    //         0054ece2     ADD        EAX,0x2
    //         0054ece5     ADD        ESI,0x2
    //         0054ece8     TEST       CL,CL
    //         0054ecea     JNZ        LAB_0054ecc4
    //         0054ecec     XOR        EAX,EAX
    //         0054ecee     POP        EDI
    //         0054ecef     POP        ESI
    //         0054ecf0     POP        EBX
    //         0054ecf1     RET
    //                               LAB_0054ecf2                                                 XREF[2]:     0054eccc(j), 0054ece0(j)  
    //         0054ecf2     SBB        EAX,EAX
    //         0054ecf4     SBB        EAX,-0x1
    //         0054ecf7     POP        EDI
    //         0054ecf8     POP        ESI
    //         0054ecf9     POP        EBX
    //         0054ecfa     RET
    //                               LAB_0054ecfb                                                 XREF[1]:     0054ecba(j)  
    //         0054ecfb     MOV        ESI,dword ptr [ESP + Stack[0x8]]
    //         0054ecff     MOV        EDI,dword ptr [ESP + Stack[0x4]]
    //         0054ed03     MOV        BL,0x4
    //                               LAB_0054ed05                                                 XREF[1]:     0054ed60(j)  
    //         0054ed05     MOVZX      CX,byte ptr [EDI]
    //         0054ed09     MOV        EAX,ECX
    //         0054ed0b     INC        EDI
    //         0054ed0c     AND        EAX,0xff
    //         0054ed11     TEST       byte ptr [EAX + __mbctype+1],BL
    //         0054ed17     JZ         LAB_0054ed2c
    //         0054ed19     MOV        AL,byte ptr [EDI]
    //         0054ed1b     TEST       AL,AL
    //         0054ed1d     JNZ        LAB_0054ed23
    //         0054ed1f     XOR        ECX,ECX
    //         0054ed21     JMP        LAB_0054ed2c
    //                               LAB_0054ed23                                                 XREF[1]:     0054ed1d(j)  
    //         0054ed23     XOR        EDX,EDX
    //         0054ed25     INC        EDI
    //         0054ed26     MOV        DH,CL
    //         0054ed28     MOV        DL,AL
    //         0054ed2a     MOV        ECX,EDX
    //                               LAB_0054ed2c                                                 XREF[2]:     0054ed17(j), 0054ed21(j)  
    //         0054ed2c     MOVZX      AX,byte ptr [ESI]
    //         0054ed30     MOV        EDX,EAX
    //         0054ed32     INC        ESI
    //         0054ed33     AND        EDX,0xff
    //         0054ed39     TEST       byte ptr [EDX + __mbctype+1],BL
    //         0054ed3f     JZ         LAB_0054ed56
    //         0054ed41     MOV        DL,byte ptr [ESI]
    //         0054ed43     TEST       DL,DL
    //         0054ed45     JNZ        LAB_0054ed4b
    //         0054ed47     XOR        EAX,EAX
    //         0054ed49     JMP        LAB_0054ed56
    //                               LAB_0054ed4b                                                 XREF[1]:     0054ed45(j)  
    //         0054ed4b     XOR        EBX,EBX
    //         0054ed4d     INC        ESI
    //         0054ed4e     MOV        BH,AL
    //         0054ed50     MOV        BL,DL
    //         0054ed52     MOV        EAX,EBX
    //         0054ed54     MOV        BL,0x4
    //                               LAB_0054ed56                                                 XREF[2]:     0054ed3f(j), 0054ed49(j)  
    //         0054ed56     CMP        AX,CX
    //         0054ed59     JNZ        LAB_0054ed62
    //         0054ed5b     TEST       CX,CX
    //         0054ed5e     JZ         LAB_0054ed6c
    //         0054ed60     JMP        LAB_0054ed05
    //                               LAB_0054ed62                                                 XREF[1]:     0054ed59(j)  
    //         0054ed62     SBB        EAX,EAX
    //         0054ed64     AND        EAX,0x2
    //         0054ed67     DEC        EAX
    //         0054ed68     POP        EDI
    //         0054ed69     POP        ESI
    //         0054ed6a     POP        EBX
    //         0054ed6b     RET
    //                               LAB_0054ed6c                                                 XREF[2]:     0054ecd0(j), 0054ed5e(j)  
    //         0054ed6c     POP        EDI
    //         0054ed6d     POP        ESI
    //         0054ed6e     XOR        EAX,EAX
    //         0054ed70     POP        EBX
    //         0054ed71     RET
}

// Offset: 0x0054ED80
undefined mbsinc() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __mbsinc()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __mbsinc                                                     XREF[21]:    is_blank:00476a90(c), 
    //                                                                                                         get_trimmed_str:00476b2f(c), 
    //                                                                                                         get_trimmed_str:00476b5c(c), 
    //                                                                                                         get_trimmed_str:00476b67(c), 
    //                                                                                                         insert_character:00477a82(c), 
    //                                                                                                         delete_character:00477b91(c), 
    //                                                                                                         delete_character:00477ba6(c), 
    //                                                                                                         delete_character:00477c08(c), 
    //                                                                                                         is_blank:0047817a(c), 
    //                                                                                                         get_trimmed_str:0047821f(c), 
    //                                                                                                         get_trimmed_str:0047824c(c), 
    //                                                                                                         get_trimmed_str:00478257(c), 
    //                                                                                                         word_wrap_append:0047c71d(c), 
    //                                                                                                         word_wrap_append:0047c76c(c), 
    //                                                                                                         word_wrap_append:0047c778(c), 
    //                                                                                                         word_wrap_append:0047c815(c), 
    //                                                                                                         word_wrap_append:0047c848(c), 
    //                                                                                                         word_wrap_append:0047c9d7(c), 
    //                                                                                                         word_wrap_append:0047ca09(c), 
    //                                                                                                         word_wrap_append:0047ca1c(c), 
    //                                                                                                         [more]
    //         0054ed80     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054ed84     XOR        ECX,ECX
    //         0054ed86     MOV        CL,byte ptr [EAX]
    //         0054ed88     MOV        DL,byte ptr [ECX + __mbctype+1]
    //         0054ed8e     AND        DL,0x4
    //         0054ed91     INC        EAX
    //         0054ed92     TEST       DL,DL
    //         0054ed94     JZ         LAB_0054ed97
    //         0054ed96     INC        EAX
    //                               LAB_0054ed97                                                 XREF[1]:     0054ed94(j)  
    //         0054ed97     RET
}

// Offset: 0x0054EDA0
undefined mbsdec() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __mbsdec()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __mbsdec                                                     XREF[5]:     get_trimmed_str:00476b7f(c), 
    //                                                                                                         delete_character:00477bbf(c), 
    //                                                                                                         delete_character:00477bd4(c), 
    //                                                                                                         get_trimmed_str:0047826f(c), 
    //                                                                                                         word_wrap_append:0047c868(c)  
    //         0054eda0     MOV        EDX,dword ptr [ESP + Stack[0x4]]
    //         0054eda4     PUSH       EBX
    //         0054eda5     PUSH       ESI
    //         0054eda6     MOV        ESI,dword ptr [ESP + Stack[0x8]]
    //         0054edaa     CMP        EDX,ESI
    //         0054edac     PUSH       EDI
    //         0054edad     JC         LAB_0054edb5
    //         0054edaf     XOR        EAX,EAX
    //         0054edb1     POP        EDI
    //         0054edb2     POP        ESI
    //         0054edb3     POP        EBX
    //         0054edb4     RET
    //                               LAB_0054edb5                                                 XREF[1]:     0054edad(j)  
    //         0054edb5     MOV        EAX,[___mbcodepage]
    //         0054edba     TEST       EAX,EAX
    //         0054edbc     JNZ        LAB_0054edc5
    //         0054edbe     LEA        EAX,[ESI + -0x1]
    //         0054edc1     POP        EDI
    //         0054edc2     POP        ESI
    //         0054edc3     POP        EBX
    //         0054edc4     RET
    //                               LAB_0054edc5                                                 XREF[1]:     0054edbc(j)  
    //         0054edc5     LEA        ECX,[ESI + -0x1]
    //         0054edc8     XOR        EAX,EAX
    //         0054edca     MOV        AL,byte ptr [ECX]
    //         0054edcc     MOV        EDI,EAX
    //         0054edce     MOV        AL,0x4
    //         0054edd0     TEST       byte ptr [EDI + __mbctype+1],AL
    //         0054edd6     JZ         LAB_0054eddf
    //         0054edd8     LEA        EAX,[ECX + -0x1]
    //         0054eddb     POP        EDI
    //         0054eddc     POP        ESI
    //         0054eddd     POP        EBX
    //         0054edde     RET
    //                               LAB_0054eddf                                                 XREF[1]:     0054edd6(j)  
    //         0054eddf     DEC        ECX
    //         0054ede0     CMP        EDX,ECX
    //         0054ede2     JA         LAB_0054edf5
    //                               LAB_0054ede4                                                 XREF[1]:     0054edf3(j)  
    //         0054ede4     XOR        EBX,EBX
    //         0054ede6     MOV        BL,byte ptr [ECX]
    //         0054ede8     TEST       byte ptr [EBX + __mbctype+1],AL
    //         0054edee     JZ         LAB_0054edf5
    //         0054edf0     DEC        ECX
    //         0054edf1     CMP        EDX,ECX
    //         0054edf3     JBE        LAB_0054ede4
    //                               LAB_0054edf5                                                 XREF[2]:     0054ede2(j), 0054edee(j)  
    //         0054edf5     MOV        EDX,ESI
    //         0054edf7     MOV        EAX,ESI
    //         0054edf9     SUB        EDX,ECX
    //         0054edfb     POP        EDI
    //         0054edfc     AND        EDX,0x1
    //         0054edff     POP        ESI
    //         0054ee00     SUB        EAX,EDX
    //         0054ee02     POP        EBX
    //         0054ee03     DEC        EAX
    //         0054ee04     RET
}

// Offset: 0x0054EE10
undefined mbsncpy() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __mbsncpy()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __mbsncpy                                                    XREF[13]:    get_trimmed_str:00476b53(c), 
    //                                                                                                         insert_character:00477a43(c), 
    //                                                                                                         insert_character:00477a79(c), 
    //                                                                                                         insert_character:00477a9e(c), 
    //                                                                                                         delete_character:00477b59(c), 
    //                                                                                                         delete_character:00477c2d(c), 
    //                                                                                                         paste:00477d42(c), 
    //                                                                                                         paste:00477dd7(c), 
    //                                                                                                         paste:00477e0c(c), 
    //                                                                                                         paste:00477e32(c), 
    //                                                                                                         get_trimmed_str:00478243(c), 
    //                                                                                                         word_wrap_append:0047c972(c), 
    //                                                                                                         calc_line_pos:0047da5c(c)  
    //         0054ee10     MOV        EAX,[___mbcodepage]
    //         0054ee15     PUSH       ESI
    //         0054ee16     PUSH       EDI
    //         0054ee17     MOV        EDI,dword ptr [ESP + Stack[0x4]]
    //         0054ee1b     TEST       EAX,EAX
    //         0054ee1d     MOV        ESI,EDI
    //         0054ee1f     JNZ        LAB_0054ee37
    //         0054ee21     MOV        EAX,dword ptr [ESP + Stack[0xc]]
    //         0054ee25     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //         0054ee29     PUSH       EAX
    //         0054ee2a     PUSH       ECX
    //         0054ee2b     PUSH       EDI
    //         0054ee2c     CALL       strncpy                                          undefined strncpy()
    //         0054ee31     ADD        ESP,0xc
    //         0054ee34     POP        EDI
    //         0054ee35     POP        ESI
    //         0054ee36     RET
    //                               LAB_0054ee37                                                 XREF[1]:     0054ee1f(j)  
    //         0054ee37     MOV        EDX,dword ptr [ESP + Stack[0xc]]
    //         0054ee3b     PUSH       EBP
    //         0054ee3c     TEST       EDX,EDX
    //         0054ee3e     PUSH       EBX
    //         0054ee3f     JZ         LAB_0054ee7b
    //         0054ee41     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         0054ee45     MOV        BL,0x4
    //                               LAB_0054ee47                                                 XREF[1]:     0054ee73(j)  
    //         0054ee47     MOV        CL,byte ptr [EAX]
    //         0054ee49     DEC        EDX
    //         0054ee4a     MOV        EBP,ECX
    //         0054ee4c     AND        EBP,0xff
    //         0054ee52     TEST       byte ptr [EBP + __mbctype+1],BL
    //         0054ee58     MOV        byte ptr [EDI],CL
    //         0054ee5a     JZ         LAB_0054ee6b
    //         0054ee5c     MOV        CL,byte ptr [EAX + 0x1]
    //         0054ee5f     INC        EDI
    //         0054ee60     INC        EAX
    //         0054ee61     MOV        byte ptr [EDI],CL
    //         0054ee63     INC        EDI
    //         0054ee64     INC        EAX
    //         0054ee65     TEST       CL,CL
    //         0054ee67     JZ         LAB_0054ee77
    //         0054ee69     JMP        LAB_0054ee71
    //                               LAB_0054ee6b                                                 XREF[1]:     0054ee5a(j)  
    //         0054ee6b     INC        EDI
    //         0054ee6c     INC        EAX
    //         0054ee6d     TEST       CL,CL
    //         0054ee6f     JZ         LAB_0054ee7b
    //                               LAB_0054ee71                                                 XREF[1]:     0054ee69(j)  
    //         0054ee71     TEST       EDX,EDX
    //         0054ee73     JNZ        LAB_0054ee47
    //         0054ee75     JMP        LAB_0054ee7b
    //                               LAB_0054ee77                                                 XREF[1]:     0054ee67(j)  
    //         0054ee77     MOV        byte ptr [EDI + -0x2],0x0
    //                               LAB_0054ee7b                                                 XREF[3]:     0054ee3f(j), 0054ee6f(j), 
    //                                                                                                         0054ee75(j)  
    //         0054ee7b     MOV        EAX,EDX
    //         0054ee7d     DEC        EDX
    //         0054ee7e     TEST       EAX,EAX
    //         0054ee80     JZ         LAB_0054ee95
    //         0054ee82     LEA        ECX,[EDX + 0x1]
    //         0054ee85     XOR        EAX,EAX
    //         0054ee87     MOV        EDX,ECX
    //         0054ee89     SHR        ECX,0x2
    //         0054ee8c     STOSD.REP  ES:EDI
    //         0054ee8e     MOV        ECX,EDX
    //         0054ee90     AND        ECX,0x3
    //         0054ee93     STOSB.REP  ES:EDI
    //                               LAB_0054ee95                                                 XREF[1]:     0054ee80(j)  
    //         0054ee95     POP        EBX
    //         0054ee96     POP        EBP
    //         0054ee97     MOV        EAX,ESI
    //         0054ee99     POP        EDI
    //         0054ee9a     POP        ESI
    //         0054ee9b     RET
}

// Offset: 0x0054EEA0
undefined mbslen() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __mbslen()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __mbslen                                                     XREF[18]:    char_action:00477014(c), 
    //                                                                                                         char_action:00477037(c), 
    //                                                                                                         key_down_action:004772b5(c), 
    //                                                                                                         key_down_action:00477349(c), 
    //                                                                                                         key_down_action:0047736a(c), 
    //                                                                                                         key_down_action:004773d4(c), 
    //                                                                                                         key_down_action:004774a1(c), 
    //                                                                                                         key_down_action:004774db(c), 
    //                                                                                                         key_down_action:00477500(c), 
    //                                                                                                         key_down_action:0047760c(c), 
    //                                                                                                         key_down_action:0047762d(c), 
    //                                                                                                         set_text:0047793a(c), 
    //                                                                                                         paste:00477d17(c), 
    //                                                                                                         calc_input_pos:00477f16(c), 
    //                                                                                                         calc_cur_line_col:00478049(c), 
    //                                                                                                         word_wrap_append:0047c6e4(c), 
    //                                                                                                         calc_line_pos:0047da1a(c), 
    //                                                                                                         calc_line_pos:0047da8c(c)  
    //         0054eea0     MOV        EAX,[___mbcodepage]
    //         0054eea5     TEST       EAX,EAX
    //         0054eea7     JNZ        LAB_0054eebc
    //         0054eea9     PUSH       EDI
    //         0054eeaa     MOV        EDI,dword ptr [ESP + Stack[0x4]]
    //         0054eeae     OR         ECX,0xffffffff
    //         0054eeb1     XOR        EAX,EAX
    //         0054eeb3     SCASB.RE   ES:EDI
    //         0054eeb5     NOT        ECX
    //         0054eeb7     DEC        ECX
    //         0054eeb8     POP        EDI
    //         0054eeb9     MOV        EAX,ECX
    //         0054eebb     RET
    //                               LAB_0054eebc                                                 XREF[1]:     0054eea7(j)  
    //         0054eebc     MOV        EDX,dword ptr [ESP + Stack[0x4]]
    //         0054eec0     XOR        EAX,EAX
    //         0054eec2     PUSH       EBX
    //         0054eec3     MOV        CL,byte ptr [EDX]
    //         0054eec5     TEST       CL,CL
    //         0054eec7     JZ         LAB_0054eeea
    //         0054eec9     MOV        BL,0x4
    //                               LAB_0054eecb                                                 XREF[1]:     0054eee8(j)  
    //         0054eecb     AND        ECX,0xff
    //         0054eed1     TEST       byte ptr [ECX + __mbctype+1],BL
    //         0054eed7     JZ         LAB_0054eee1
    //         0054eed9     MOV        CL,byte ptr [EDX + 0x1]
    //         0054eedc     INC        EDX
    //         0054eedd     TEST       CL,CL
    //         0054eedf     JZ         LAB_0054eeea
    //                               LAB_0054eee1                                                 XREF[1]:     0054eed7(j)  
    //         0054eee1     MOV        CL,byte ptr [EDX + 0x1]
    //         0054eee4     INC        EAX
    //         0054eee5     INC        EDX
    //         0054eee6     TEST       CL,CL
    //         0054eee8     JNZ        LAB_0054eecb
    //                               LAB_0054eeea                                                 XREF[2]:     0054eec7(j), 0054eedf(j)  
    //         0054eeea     POP        EBX
    //         0054eeeb     RET
}

// Offset: 0x0054EEF0
undefined mbscpy() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __mbscpy()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __mbscpy                                                     XREF[1]:     set_text:0047792b(c)  
    //         0054eef0     PUSH       EDI
    //         0054eef1     MOV        EDI,dword ptr [ESP + Stack[0x4]]
    //         0054eef5     JMP        LAB_0054ef61
}

// Offset: 0x0054EEF7
undefined FUN_0054eef7() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054eef7()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054eef7
    //         0054eef7     MOV        EAX,EAX
    //         0054eefa     MOV        EAX,EAX
    //         0054eefd     MOV        EAX,EAX
}

// Offset: 0x0054EF00
undefined mbscat() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __mbscat()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __mbscat                                                     XREF[2]:     word_wrap_append:0047c98f(c), 
    //                                                                                                         word_wrap_append:0047c9ac(c)  
    //         0054ef00     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         0054ef04     PUSH       EDI
    //         0054ef05     TEST       ECX,0x3
    //         0054ef0b     JZ         LAB_0054ef1c
    //                               LAB_0054ef0d                                                 XREF[1]:     0054ef1a(j)  
    //         0054ef0d     MOV        AL,byte ptr [ECX]
    //         0054ef0f     INC        ECX
    //         0054ef10     TEST       AL,AL
    //         0054ef12     JZ         LAB_0054ef4f
    //         0054ef14     TEST       ECX,0x3
    //         0054ef1a     JNZ        LAB_0054ef0d
    //                               LAB_0054ef1c                                                 XREF[3]:     0054ef0b(j), 0054ef32(j), 
    //                                                                                                         0054ef4d(j)  
    //         0054ef1c     MOV        EAX,dword ptr [ECX]
    //         0054ef1e     MOV        EDX,0x7efefeff
    //         0054ef23     ADD        EDX,EAX
    //         0054ef25     XOR        EAX,0xffffffff
    //         0054ef28     XOR        EAX,EDX
    //         0054ef2a     ADD        ECX,0x4
    //         0054ef2d     TEST       EAX,0x81010100
    //         0054ef32     JZ         LAB_0054ef1c
    //         0054ef34     MOV        EAX,dword ptr [ECX + -0x4]
    //         0054ef37     TEST       AL,AL
    //         0054ef39     JZ         LAB_0054ef5e
    //         0054ef3b     TEST       AH,AH
    //         0054ef3d     JZ         LAB_0054ef59
    //         0054ef3f     TEST       EAX,0xff0000
    //         0054ef44     JZ         LAB_0054ef54
    //         0054ef46     TEST       EAX,0xff000000
    //         0054ef4b     JZ         LAB_0054ef4f
    //         0054ef4d     JMP        LAB_0054ef1c
    //                               LAB_0054ef4f                                                 XREF[2]:     0054ef12(j), 0054ef4b(j)  
    //         0054ef4f     LEA        EDI,[ECX + -0x1]
    //         0054ef52     JMP        LAB_0054ef61
    //                               LAB_0054ef54                                                 XREF[1]:     0054ef44(j)  
    //         0054ef54     LEA        EDI,[ECX + -0x2]
    //         0054ef57     JMP        LAB_0054ef61
    //                               LAB_0054ef59                                                 XREF[1]:     0054ef3d(j)  
    //         0054ef59     LEA        EDI,[ECX + -0x3]
    //         0054ef5c     JMP        LAB_0054ef61
    //                               LAB_0054ef5e                                                 XREF[1]:     0054ef39(j)  
    //         0054ef5e     LEA        EDI,[ECX + -0x4]
    //                               LAB_0054ef61                                                 XREF[4]:     __mbscpy:0054eef5(j), 0054ef52(j), 
    //                                                                                                         0054ef57(j), 0054ef5c(j)  
    //         0054ef61     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //         0054ef65     TEST       ECX,0x3
    //         0054ef6b     JZ         LAB_0054ef86
    //                               LAB_0054ef6d                                                 XREF[1]:     0054ef7d(j)  
    //         0054ef6d     MOV        DL,byte ptr [ECX]
    //         0054ef6f     INC        ECX
    //         0054ef70     TEST       DL,DL
    //         0054ef72     JZ         LAB_0054efd8
    //         0054ef74     MOV        byte ptr [EDI],DL
    //         0054ef76     INC        EDI
    //         0054ef77     TEST       ECX,0x3
    //         0054ef7d     JNZ        LAB_0054ef6d
    //         0054ef7f     JMP        LAB_0054ef86
    //                               LAB_0054ef81                                                 XREF[2]:     0054ef9e(j), 0054efb8(j)  
    //         0054ef81     MOV        dword ptr [EDI],EDX
    //         0054ef83     ADD        EDI,0x4
    //                               LAB_0054ef86                                                 XREF[2]:     0054ef6b(j), 0054ef7f(j)  
    //         0054ef86     MOV        EDX,0x7efefeff
    //         0054ef8b     MOV        EAX,dword ptr [ECX]
    //         0054ef8d     ADD        EDX,EAX
    //         0054ef8f     XOR        EAX,0xffffffff
    //         0054ef92     XOR        EAX,EDX
    //         0054ef94     MOV        EDX,dword ptr [ECX]
    //         0054ef96     ADD        ECX,0x4
    //         0054ef99     TEST       EAX,0x81010100
    //         0054ef9e     JZ         LAB_0054ef81
    //         0054efa0     TEST       DL,DL
    //         0054efa2     JZ         LAB_0054efd8
    //         0054efa4     TEST       DH,DH
    //         0054efa6     JZ         LAB_0054efcf
    //         0054efa8     TEST       EDX,0xff0000
    //         0054efae     JZ         LAB_0054efc2
    //         0054efb0     TEST       EDX,0xff000000
    //         0054efb6     JZ         LAB_0054efba
    //         0054efb8     JMP        LAB_0054ef81
    //                               LAB_0054efba                                                 XREF[1]:     0054efb6(j)  
    //         0054efba     MOV        dword ptr [EDI],EDX
    //         0054efbc     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054efc0     POP        EDI
    //         0054efc1     RET
    //                               LAB_0054efc2                                                 XREF[1]:     0054efae(j)  
    //         0054efc2     MOV        word ptr [EDI],DX
    //         0054efc5     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054efc9     MOV        byte ptr [EDI + 0x2],0x0
    //         0054efcd     POP        EDI
    //         0054efce     RET
    //                               LAB_0054efcf                                                 XREF[1]:     0054efa6(j)  
    //         0054efcf     MOV        word ptr [EDI],DX
    //         0054efd2     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054efd6     POP        EDI
    //         0054efd7     RET
    //                               LAB_0054efd8                                                 XREF[2]:     0054ef72(j), 0054efa2(j)  
    //         0054efd8     MOV        byte ptr [EDI],DL
    //         0054efda     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054efde     POP        EDI
    //         0054efdf     RET
}

// Offset: 0x0054EFE0
undefined strncmp() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * strncmp                                                                                               *
    //                              *********************************************************************************************************
    //                              undefined __cdecl strncmp()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _strncmp                                                     XREF[5]:     show_message:004792d1(c), 
    //                               strncmp                                                                   show_message2:004793f7(c), 
    //                                                                                                         FUN_0047f076:0047f0fb(c), 
    //                                                                                                         BUILDRES_get_files_resource_type:0
    //                                                                                                         load:004bce60(c)  
    //         0054efe0     PUSH       EBP
    //         0054efe1     MOV        EBP,ESP
    //         0054efe3     PUSH       EDI
    //         0054efe4     PUSH       ESI
    //         0054efe5     PUSH       EBX
    //         0054efe6     MOV        ECX,dword ptr [EBP + Stack[0xc]]
    //         0054efe9     JECXZ      LAB_0054f011
    //         0054efeb     MOV        EBX,ECX
    //         0054efed     MOV        EDI,dword ptr [EBP + Stack[0x4]]
    //         0054eff0     MOV        ESI,EDI
    //         0054eff2     XOR        EAX,EAX
    //         0054eff4     SCASB.RE   ES:EDI
    //         0054eff6     NEG        ECX
    //         0054eff8     ADD        ECX,EBX
    //         0054effa     MOV        EDI,ESI
    //         0054effc     MOV        ESI,dword ptr [EBP + Stack[0x8]]
    //         0054efff     CMPSB.REPE ES:EDI,ESI
    //         0054f001     MOV        AL,byte ptr [ESI + -0x1]
    //         0054f004     XOR        ECX,ECX
    //         0054f006     CMP        AL,byte ptr [EDI + -0x1]
    //         0054f009     JA         LAB_0054f00f
    //         0054f00b     JZ         LAB_0054f011
    //         0054f00d     DEC        ECX
    //         0054f00e     DEC        ECX
    //                               LAB_0054f00f                                                 XREF[1]:     0054f009(j)  
    //         0054f00f     NOT        ECX
    //                               LAB_0054f011                                                 XREF[2]:     0054efe9(j), 0054f00b(j)  
    //         0054f011     MOV        EAX,ECX
    //         0054f013     POP        EBX
    //         0054f014     POP        ESI
    //         0054f015     POP        EDI
    //         0054f016     LEAVE
    //         0054f017     RET
}

