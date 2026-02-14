// Auto-generated scaffold unit: bucket_0552.asm
#include "../include/common.h"

// Offset: 0x005520E0
undefined FUN_005520e0() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005520e0()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005520e0                                                 XREF[4]:     __output:0055197b(c), 
    //                                                                                                         __output:0055199e(c), 
    //                                                                                                         FUN_00552130:0055214e(c), 
    //                                                                                                         FUN_00552170:00552192(c)  
    //         005520e0     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //         005520e4     MOV        EAX,dword ptr [ECX + 0x4]
    //         005520e7     DEC        EAX
    //         005520e8     MOV        dword ptr [ECX + 0x4],EAX
    //         005520eb     JS         LAB_00552101
    //         005520ed     MOV        EDX,dword ptr [ECX]
    //         005520ef     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         005520f3     MOV        byte ptr [EDX],AL
    //         005520f5     MOV        EDX,dword ptr [ECX]
    //         005520f7     AND        EAX,0xff
    //         005520fc     INC        EDX
    //         005520fd     MOV        dword ptr [ECX],EDX
    //         005520ff     JMP        LAB_0055210f
    //                               LAB_00552101                                                 XREF[1]:     005520eb(j)  
    //         00552101     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00552105     PUSH       ECX
    //         00552106     PUSH       EAX
    //         00552107     CALL       __flsbuf                                         undefined __flsbuf()
    //         0055210c     ADD        ESP,0x8
    //                               LAB_0055210f                                                 XREF[1]:     005520ff(j)  
    //         0055210f     CMP        EAX,-0x1
    //         00552112     JNZ        LAB_0055211b
    //         00552114     MOV        ECX,dword ptr [ESP + Stack[0xc]]
    //         00552118     MOV        dword ptr [ECX],EAX
    //         0055211a     RET
    //                               LAB_0055211b                                                 XREF[1]:     00552112(j)  
    //         0055211b     MOV        EAX,dword ptr [ESP + Stack[0xc]]
    //         0055211f     INC        dword ptr [EAX]
    //         00552121     RET
}

// Offset: 0x00552130
undefined FUN_00552130() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00552130()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00552130                                                 XREF[3]:     __output:00551ed0(c), 
    //                                                                                                         __output:00551f0c(c), 
    //                                                                                                         __output:00551f82(c)  
    //         00552130     PUSH       EBX
    //         00552131     PUSH       EBP
    //         00552132     MOV        EBP,dword ptr [ESP + Stack[0x8]]
    //         00552136     PUSH       ESI
    //         00552137     MOV        EAX,EBP
    //         00552139     DEC        EBP
    //         0055213a     TEST       EAX,EAX
    //         0055213c     PUSH       EDI
    //         0055213d     JLE        LAB_00552164
    //         0055213f     MOV        ESI,dword ptr [ESP + Stack[0x10]]
    //         00552143     MOV        EDI,dword ptr [ESP + Stack[0xc]]
    //         00552147     MOV        EBX,dword ptr [ESP + Stack[0x4]]
    //                               LAB_0055214b                                                 XREF[1]:     00552162(j)  
    //         0055214b     PUSH       ESI
    //         0055214c     PUSH       EDI
    //         0055214d     PUSH       EBX
    //         0055214e     CALL       FUN_005520e0                                     undefined FUN_005520e0()
    //         00552153     MOV        EAX,dword ptr [ESI]
    //         00552155     ADD        ESP,0xc
    //         00552158     CMP        EAX,-0x1
    //         0055215b     JZ         LAB_00552164
    //         0055215d     MOV        ECX,EBP
    //         0055215f     DEC        EBP
    //         00552160     TEST       ECX,ECX
    //         00552162     JG         LAB_0055214b
    //                               LAB_00552164                                                 XREF[2]:     0055213d(j), 0055215b(j)  
    //         00552164     POP        EDI
    //         00552165     POP        ESI
    //         00552166     POP        EBP
    //         00552167     POP        EBX
    //         00552168     RET
}

// Offset: 0x00552170
undefined FUN_00552170() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00552170()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00552170                                                 XREF[3]:     __output:00551ef1(c), 
    //                                                                                                         __output:00551f5a(c), 
    //                                                                                                         __output:00551fc2(c)  
    //         00552170     PUSH       EBX
    //         00552171     PUSH       EBP
    //         00552172     MOV        EBP,dword ptr [ESP + Stack[0x8]]
    //         00552176     PUSH       ESI
    //         00552177     MOV        EAX,EBP
    //         00552179     DEC        EBP
    //         0055217a     TEST       EAX,EAX
    //         0055217c     PUSH       EDI
    //         0055217d     JLE        LAB_005521a8
    //         0055217f     MOV        EDI,dword ptr [ESP + Stack[0x10]]
    //         00552183     MOV        EBX,dword ptr [ESP + Stack[0xc]]
    //         00552187     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //                               LAB_0055218b                                                 XREF[1]:     005521a6(j)  
    //         0055218b     MOVSX      EAX,byte ptr [ESI]
    //         0055218e     PUSH       EDI
    //         0055218f     PUSH       EBX
    //         00552190     PUSH       EAX
    //         00552191     INC        ESI
    //         00552192     CALL       FUN_005520e0                                     undefined FUN_005520e0()
    //         00552197     MOV        EAX,dword ptr [EDI]
    //         00552199     ADD        ESP,0xc
    //         0055219c     CMP        EAX,-0x1
    //         0055219f     JZ         LAB_005521a8
    //         005521a1     MOV        ECX,EBP
    //         005521a3     DEC        EBP
    //         005521a4     TEST       ECX,ECX
    //         005521a6     JG         LAB_0055218b
    //                               LAB_005521a8                                                 XREF[2]:     0055217d(j), 0055219f(j)  
    //         005521a8     POP        EDI
    //         005521a9     POP        ESI
    //         005521aa     POP        EBP
    //         005521ab     POP        EBX
    //         005521ac     RET
}

// Offset: 0x005521B0
undefined FUN_005521b0() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005521b0()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005521b0                                                 XREF[10]:    __output:0055186f(c), 
    //                                                                                                         __output:005518c2(c), 
    //                                                                                                         __output:00551a45(c), 
    //                                                                                                         __output:00551a6b(c), 
    //                                                                                                         __output:00551af6(c), 
    //                                                                                                         __output:00551b7e(c), 
    //                                                                                                         __output:00551d44(c), 
    //                                                                                                         __output:00551d5a(c), 
    //                                                                                                         __output:00551d77(c), 
    //                                                                                                         __output:00551d8a(c)  
    //         005521b0     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         005521b4     MOV        ECX,dword ptr [EAX]
    //         005521b6     ADD        ECX,0x4
    //         005521b9     MOV        dword ptr [EAX],ECX
    //         005521bb     MOV        EAX,ECX
    //         005521bd     MOV        EAX,dword ptr [EAX + -0x4]
    //         005521c0     RET
}

// Offset: 0x005521D0
undefined FUN_005521d0() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005521d0()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005521d0                                                 XREF[1]:     __output:00551d28(c)  
    //         005521d0     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         005521d4     MOV        ECX,dword ptr [EAX]
    //         005521d6     ADD        ECX,0x8
    //         005521d9     MOV        dword ptr [EAX],ECX
    //         005521db     MOV        EAX,dword ptr [ECX + -0x8]
    //         005521de     MOV        EDX,dword ptr [ECX + -0x4]
    //         005521e1     RET
}

// Offset: 0x005521F0
undefined FUN_005521f0() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005521f0()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005521f0                                                 XREF[1]:     __output:00551a0c(c)  
    //         005521f0     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         005521f4     MOV        ECX,dword ptr [EAX]
    //         005521f6     ADD        ECX,0x4
    //         005521f9     MOV        dword ptr [EAX],ECX
    //         005521fb     MOV        EAX,ECX
    //         005521fd     MOV        AX,word ptr [EAX + -0x4]
    //         00552201     RET
}

// Offset: 0x00552210
undefined dosmaperr() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __dosmaperr()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __dosmaperr                                                  XREF[10]:    remove:0054b97e(c), 
    //                                                                                                         close:0054cd3f(c), 
    //                                                                                                         read:0054ce56(c), 
    //                                                                                                         __sopen:0054d1d9(c), 
    //                                                                                                         __sopen:0054d204(c), 
    //                                                                                                         lseek:0054d45e(c), 
    //                                                                                                         write:0054d5fc(c), 
    //                                                                                                         __chdrive:0054e4e7(c), 
    //                                                                                                         __chdir:0054e597(c), 
    //                                                                                                         FUN_00554bc4:00554bfd(c)  
    //         00552210     MOV        EDX,dword ptr [ESP + Stack[0x4]]
    //         00552214     MOV        dword ptr [__doserrno],EDX
    //         0055221a     XOR        ECX,ECX
    //         0055221c     MOV        EAX,DAT_00591c18                                 = 00000001h
    //                               LAB_00552221                                                 XREF[1]:     0055222e(j)  
    //         00552221     CMP        EDX,dword ptr [EAX]=>DAT_00591c18                = 00000001h
    //                                                                                  = 00000002h
    //         00552223     JZ         LAB_0055226a
    //         00552225     ADD        EAX=>DAT_00591c28,0x8                            = 03h
    //         00552228     INC        ECX
    //         00552229     CMP        EAX,s_-_]_00591d80                               = " \t-\r]"
    //         0055222e     JC         LAB_00552221
    //         00552230     CMP        EDX,0x13
    //         00552233     JC         LAB_00552245
    //         00552235     CMP        EDX,0x24
    //         00552238     JA         LAB_00552245
    //         0055223a     MOV        dword ptr [_errno],0xd                           = align(4)
    //         00552244     RET
    //                               LAB_00552245                                                 XREF[2]:     00552233(j), 00552238(j)  
    //         00552245     CMP        EDX,0xbc
    //         0055224b     JC         LAB_0055225f
    //         0055224d     CMP        EDX,0xca
    //         00552253     MOV        dword ptr [_errno],0x8                           = align(4)
    //         0055225d     JBE        LAB_00552269
    //                               LAB_0055225f                                                 XREF[1]:     0055224b(j)  
    //         0055225f     MOV        dword ptr [_errno],0x16                          = align(4)
    //                               LAB_00552269                                                 XREF[1]:     0055225d(j)  
    //         00552269     RET
    //                               LAB_0055226a                                                 XREF[1]:     00552223(j)  
    //         0055226a     MOV        EAX,dword ptr [ECX*0x8 + 0x591c1c]=>DAT_00591c24 = 00000002h
    //         00552271     MOV        [_errno],EAX                                     = align(4)
    //         00552276     RET
}

// Offset: 0x00552280
undefined freebuf() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __freebuf()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __freebuf                                                    XREF[1]:     fclose:0054ba4d(c)  
    //         00552280     PUSH       ESI
    //         00552281     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         00552285     MOV        EAX,dword ptr [ESI + 0xc]
    //         00552288     TEST       AL,0x83
    //         0055228a     JZ         LAB_005522b1
    //         0055228c     TEST       AL,0x8
    //         0055228e     JZ         LAB_005522b1
    //         00552290     MOV        EAX,dword ptr [ESI + 0x8]
    //         00552293     PUSH       EAX
    //         00552294     CALL       free                                             undefined free()
    //         00552299     MOV        EAX,dword ptr [ESI + 0xc]
    //         0055229c     ADD        ESP,0x4
    //         0055229f     AND        EAX,0xfffffbf7
    //         005522a4     MOV        dword ptr [ESI + 0xc],EAX
    //         005522a7     XOR        EAX,EAX
    //         005522a9     MOV        dword ptr [ESI],EAX
    //         005522ab     MOV        dword ptr [ESI + 0x8],EAX
    //         005522ae     MOV        dword ptr [ESI + 0x4],EAX
    //                               LAB_005522b1                                                 XREF[2]:     0055228a(j), 0055228e(j)  
    //         005522b1     POP        ESI
    //         005522b2     RET
}

// Offset: 0x005522C0
undefined input() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __input()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined1        Stack[-0x15a   local_15a                 XREF[2]:     00552dbc(*), 00552e01(*)  
    //              undefined1        Stack[-0x15b   local_15b                 XREF[1]:     00552d54(*)  
    //              undefined1        Stack[-0x15c   local_15c                 XREF[1]:     00552d3b(*)  
    //              undefined1        Stack[-0x15d   local_15d                 XREF[1]:     00552cf4(*)  
    //              undefined1        Stack[-0x15e   local_15e                 XREF[1]:     00552cbc(*)  
    //              undefined         Stack[-0x15f   local_15f                 XREF[2]:     00552bf5(*), 00552c72(*)  
    //              undefined         Stack[-0x160   local_160                 XREF[3]:     00552be5(*), 00552bee(W), 00552ded(*)  
    //              undefined1        Stack[-0x175   local_175                 XREF[1]:     005525e0(W)  
    //              undefined         Stack[-0x180   local_180                 XREF[1]:     005525ca(*)  
    //              undefined4        Stack[-0x184   local_184                 XREF[2]:     005525f5(W), 0055266d(R)  
    //              undefined4        Stack[-0x188   local_188                 XREF[3]:     005523c8(W), 005524aa(W), 00552b92(R)  
    //              undefined4        Stack[-0x18c   local_18c                 XREF[4]:     005522f0(R), 005524b9(W), 00552e34(R), 00552f12(R)  
    //              undefined2        Stack[-0x18e   local_18e                 XREF[2]:     00552763(*), 0055276e(R)  
    //              undefined4        Stack[-0x194   local_194                 XREF[4]:     00552612(W), 00552618(W), 00552622(R), 0055262c(R)  
    //              undefined4        Stack[-0x198   local_198                 XREF[6]:     0055247a(W), 00552913(R), 00552a29(W), 00552a41(R), 
    //                                                                                     00552a50(W), 00552bbd(R)  
    //              undefined4        Stack[-0x19c   local_19c                 XREF[6]:     00552476(W), 0055290f(R), 00552a2d(W), 00552a3d(R), 
    //                                                                                     00552a4a(W), 00552bb9(R)  
    //              undefined1        Stack[-0x19d   local_19d                 XREF[1]:     00552755(W)  
    //              undefined1        Stack[-0x19e   local_19e                 XREF[2]:     00552738(W), 0055275e(*)  
    //              undefined4        Stack[-0x1a4   local_1a4                 XREF[5]:     00552390(W), 00552a59(R), 00552b4e(W), 00552b5c(W), 
    //                                                                                     00552b9b(R)  
    //              undefined4        Stack[-0x1a8   local_1a8                 XREF[8]:     00552399(W), 00552866(W), 005529c9(R), 005529d1(W), 
    //                                                                                     00552af2(R), 00552b01(W), 00552b6b(R), 00552c3a(R)  
    //              undefined4        Stack[-0x1ac   local_1ac                 XREF[8]:     005522d1(W), 005527c0(R), 005527cc(W), 00552b83(R), 
    //                                                                                     00552b97(W), 00552de4(R), 00552df4(W), 00552f16(R)  
    //              undefined4        Stack[-0x1b0   local_1b0                 XREF[9]:     0055239d(W), 00552416(R), 0055241b(W), 0055252c(R), 
    //                                                                                     00552567(W), 005526c3(R), 005529d8(R), 00552af6(R), 
    //                                                                                     00552c20(R)  
    //              undefined4        Stack[-0x1b4   local_1b4                 XREF[8]:     00552394(W), 005525da(W), 005525fb(R), 00552609(R), 
    //                                                                                     0055261c(W), 00552628(R), 00552662(W), 00552669(W)  
    //              undefined4        Stack[-0x1b8   local_1b8                 XREF[9]:     005524ca(W), 005526ae(R), 00552796(W), 005527a8(W), 
    //                                                                                     005527de(R), 005527ec(R), 00552b8e(R), 00552bb1(R), 
    //                                                                                     00552de8(R)  
    //              undefined4        Stack[-0x1bc   local_1bc                 XREF[10]:    005524f8(W), 00552540(R), 0055269c(R), 005527c4(R), 
    //                                                                                     005527fd(W), 00552875(W), 005528ae(W), 00552917(R), 
    //                                                                                     0055298c(R), 00552b60(R)  
    //              undefined1        Stack[-0x1bd   local_1bd                 XREF[3]:     005523a5(W), 005525be(W), 0055270f(R)  
    //              undefined1        Stack[-0x1be   local_1be                 XREF[5]:     005523aa(W), 00552806(W), 005528be(W), 00552a31(R), 
    //                                                                                     00552b52(R)  
    //              undefined1        Stack[-0x1bf   local_1bf                 XREF[6]:     005522c9(W), 00552e22(R), 00552e2e(W), 00552e48(R), 
    //                                                                                     00552e56(W), 00552f23(R)  
    //              undefined1        Stack[-0x1c0   local_1c0                 XREF[6]:     005523b9(W), 0055257c(W), 00552590(W), 005525a4(W), 
    //                                                                                     00552722(R), 005527d6(R)  
    //              undefined4        Stack[-0x1c4   local_1c4                 XREF[33]:    005523a1(W), 0055241f(R), 0055242a(W), 00552534(R), 
    //                                                                                     00552563(R), 00552570(W), 005526cb(R), 005526d4(W), 
    //                                                                                     00552812(R), 00552817(W), 005528ca(R), 005528cf(W), 
    //                                                                                     005529e2(R), 005529e7(W), 00552b07(R), 00552b0c(W), 
    //                                                                                     00552c03(R), 00552c0e(W), 00552c28(R), 00552c32(W)  
    //              undefined1        Stack[-0x1c5   local_1c5                 XREF[9]:     005523af(W), 00552490(RW), 005524a6(R), 0055271a(R), 
    //                                                                                     005527b4(R), 00552b77(R), 00552ba1(R), 00552ddc(R), 
    //                                                                                     00552e26(R)  
    //              undefined1        Stack[-0x1c6   local_1c6                 XREF[8]:     005523c3(W), 00552447(R), 00552453(W), 00552480(RW), 
    //                                                                                     00552486(RW), 005528b4(W), 00552bcb(R), 00552df9(R)  
    //              undefined1        Stack[-0x1c7   local_1c7                 XREF[10]:    005523be(W), 0055244b(R), 00552457(W), 0055248a(RW), 
    //                                                                                     005524ce(R), 005524e3(W), 005524ea(W), 00552574(R), 
    //                                                                                     00552588(R), 0055259c(R)  
    //              undefined4        Stack[-0x1cc   local_1cc                 XREF[57]:    005522cd(W), 0055232d(R), 00552332(*), 00552339(W), 
    //                                                                                     00552508(*), 00552518(R), 0055251e(W), 005526aa(R), 
    //                                                                                     005526b7(W), 005526de(R), 005526e4(W), 00552743(R), 
    //                                                                                     00552749(W), 0055278f(R), 0055279a(W), 00552828(R), 
    //                                                                                     0055282e(W), 00552845(R), 0055284b(W), 0055287b(R)  
    //              undefined1        Stack[-0x1cd   local_1cd                 XREF[15]:    005523b4(W), 00552496(RW), 0055249a(R), 005524d2(W), 
    //                                                                                     00552821(W), 005528d9(W), 005528f4(R), 005529bd(RW), 
    //                                                                                     005529c1(R), 005529ed(W), 00552a1d(R), 00552ae6(RW), 
    //                                                                                     00552aea(R), 00552b12(W), 00552b42(R)  
    //                               __input                                                      XREF[2]:     sscanf:0054bad5(c), 
    //                                                                                                         fscanf:0054d6cf(c)  
    //         005522c0     SUB        ESP,0x1d0
    //         005522c6     XOR        EAX,EAX
    //         005522c8     PUSH       EBX
    //         005522c9     MOV        byte ptr [ESP + local_1bf],AL
    //         005522cd     MOV        dword ptr [ESP + local_1cc],EAX
    //         005522d1     MOV        dword ptr [ESP + local_1ac],EAX
    //         005522d5     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         005522dc     PUSH       EBP
    //         005522dd     PUSH       ESI
    //         005522de     MOV        AL,byte ptr [EAX]
    //         005522e0     PUSH       EDI
    //         005522e1     TEST       AL,AL
    //         005522e3     JZ         LAB_00552f12
    //         005522e9     MOV        EBP,dword ptr [ESP + Stack[0x4]]
    //         005522f0     MOV        EBX,dword ptr [ESP + local_18c]
    //         005522f4     MOV        ESI,dword ptr [ESP + Stack[0x8]]
    //         005522fb     XOR        EDI,EDI
    //                               LAB_005522fd                                                 XREF[1]:     00552ee2(j)  
    //         005522fd     CMP        dword ptr [___mb_cur_max],0x1                    = 00000001h
    //         00552304     JLE        LAB_00552318
    //         00552306     AND        EAX,0xff
    //         0055230b     PUSH       0x8
    //         0055230d     PUSH       EAX
    //         0055230e     CALL       __isctype                                        undefined __isctype()
    //         00552313     ADD        ESP,0x8
    //         00552316     JMP        LAB_00552329
    //                               LAB_00552318                                                 XREF[1]:     00552304(j)  
    //         00552318     MOV        ECX,dword ptr [__pctype]                         = 005920da
    //         0055231e     AND        EAX,0xff
    //         00552323     MOV        AL,byte ptr [ECX + EAX*0x2]=>DAT_005920da        = 20h     
    //         00552326     AND        EAX,0x8
    //                               LAB_00552329                                                 XREF[1]:     00552316(j)  
    //         00552329     CMP        EAX,EDI
    //         0055232b     JZ         LAB_00552380
    //         0055232d     MOV        EAX,dword ptr [ESP + local_1cc]
    //         00552331     PUSH       EBP
    //         00552332     LEA        EDX=>local_1cc,[ESP + 0x18]
    //         00552336     DEC        EAX
    //         00552337     PUSH       EBP
    //         00552338     PUSH       EDX
    //         00552339     MOV        dword ptr [ESP + local_1cc],EAX
    //         0055233d     CALL       FUN_00553090                                     undefined FUN_00553090()
    //         00552342     ADD        ESP,0x8
    //         00552345     PUSH       EAX
    //         00552346     CALL       FUN_00553070                                     undefined FUN_00553070()
    //         0055234b     ADD        ESP,0x8
    //         0055234e     INC        ESI
    //         0055234f     XOR        EAX,EAX
    //         00552351     MOV        dword ptr [ESP + Stack[0x8]],ESI
    //         00552358     MOV        AL,byte ptr [ESI]
    //         0055235a     PUSH       EAX
    //         0055235b     CALL       isspace                                          undefined isspace()
    //         00552360     ADD        ESP,0x4
    //         00552363     TEST       EAX,EAX
    //         00552365     JZ         LAB_00552380
    //                               LAB_00552367                                                 XREF[1]:     0055237e(j)  
    //         00552367     INC        ESI
    //         00552368     XOR        ECX,ECX
    //         0055236a     MOV        dword ptr [ESP + Stack[0x8]],ESI
    //         00552371     MOV        CL,byte ptr [ESI]
    //         00552373     PUSH       ECX
    //         00552374     CALL       isspace                                          undefined isspace()
    //         00552379     ADD        ESP,0x4
    //         0055237c     TEST       EAX,EAX
    //         0055237e     JNZ        LAB_00552367
    //                               LAB_00552380                                                 XREF[2]:     0055232b(j), 00552365(j)  
    //         00552380     CMP        byte ptr [ESI],0x25
    //         00552383     JNZ        LAB_00552e67
    //         00552389     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //         00552390     MOV        dword ptr [ESP + local_1a4],EDI
    //         00552394     MOV        byte ptr [ESP + local_1b4],0x0
    //         00552399     MOV        dword ptr [ESP + local_1a8],EDI
    //         0055239d     MOV        dword ptr [ESP + local_1b0],EDI
    //         005523a1     MOV        dword ptr [ESP + local_1c4],EDI
    //         005523a5     MOV        byte ptr [ESP + local_1bd],0x0
    //         005523aa     MOV        byte ptr [ESP + local_1be],0x0
    //         005523af     MOV        byte ptr [ESP + local_1c5],0x0
    //         005523b4     MOV        byte ptr [ESP + local_1cd],0x0
    //         005523b9     MOV        byte ptr [ESP + local_1c0],0x0
    //         005523be     MOV        byte ptr [ESP + local_1c7],0x0
    //         005523c3     MOV        byte ptr [ESP + local_1c6],0x1
    //         005523c8     MOV        dword ptr [ESP + local_188],EDI
    //                               LAB_005523cc                                                 XREF[1]:     005524a0(j)  
    //         005523cc     MOV        EAX,[___mb_cur_max]                              = 00000001h
    //         005523d1     INC        ECX
    //         005523d2     XOR        EDX,EDX
    //         005523d4     CMP        EAX,0x1
    //         005523d7     MOV        DL,byte ptr [ECX]
    //         005523d9     MOV        dword ptr [ESP + Stack[0x8]],ECX
    //         005523e0     MOV        ESI,EDX
    //         005523e2     JLE        LAB_005523ff
    //         005523e4     MOV        EAX,ESI
    //         005523e6     PUSH       0x4
    //         005523e8     AND        EAX,0xff
    //         005523ed     PUSH       EAX
    //         005523ee     CALL       __isctype                                        undefined __isctype()
    //         005523f3     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //         005523fa     ADD        ESP,0x8
    //         005523fd     JMP        LAB_00552412
    //                               LAB_005523ff                                                 XREF[1]:     005523e2(j)  
    //         005523ff     MOV        EAX,[__pctype]                                   = 005920da
    //         00552404     MOV        EDX,ESI
    //         00552406     AND        EDX,0xff
    //         0055240c     MOV        AL,byte ptr [EAX + EDX*0x2]=>DAT_005920da        = 20h     
    //         0055240f     AND        EAX,0x4
    //                               LAB_00552412                                                 XREF[1]:     005523fd(j)  
    //         00552412     TEST       EAX,EAX
    //         00552414     JZ         LAB_00552430
    //         00552416     MOV        EAX,dword ptr [ESP + local_1b0]
    //         0055241a     INC        EAX
    //         0055241b     MOV        dword ptr [ESP + local_1b0],EAX
    //         0055241f     MOV        EAX,dword ptr [ESP + local_1c4]
    //         00552423     LEA        EDX,[EAX + EAX*0x4]
    //         00552426     LEA        EAX,[ESI + EDX*0x2 + -0x30]
    //         0055242a     MOV        dword ptr [ESP + local_1c4],EAX
    //         0055242e     JMP        switchD_00552440::caseD_46
    //                               LAB_00552430                                                 XREF[1]:     00552414(j)  
    //         00552430     LEA        EAX,[ESI + -0x2a]
    //         00552433     CMP        EAX,0x4d
    //         00552436     JA         switchD_00552440::caseD_2b
    //         00552438     XOR        EDX,EDX
    //         0055243a     MOV        DL,byte ptr [EAX + switchD_00552440::switchdat
    //                               switchD_00552440::switchD
    //         00552440     JMP        dword ptr [EDX*0x4 + switchD_00552440::switchd   = 00552490
    //                               switchD_00552440::caseD_68                                   XREF[2]:     00552440(j), 00552f50(*)  
    //         00552447     MOV        DL,byte ptr [ESP + local_1c6]
    //         0055244b     MOV        AL,byte ptr [ESP + local_1c7]
    //         0055244f     DEC        DL
    //         00552451     DEC        AL
    //         00552453     MOV        byte ptr [ESP + local_1c6],DL
    //         00552457     MOV        byte ptr [ESP + local_1c7],AL
    //         0055245b     JMP        switchD_00552440::caseD_46
    //                               switchD_00552440::caseD_49                                   XREF[2]:     00552440(j), 00552f44(*)  
    //         0055245d     CMP        byte ptr [ECX + 0x1],0x36
    //         00552461     JNZ        switchD_00552440::caseD_2b
    //         00552463     CMP        byte ptr [ECX + 0x2],0x34
    //         00552467     JNZ        switchD_00552440::caseD_2b
    //         00552469     ADD        ECX,0x2
    //         0055246c     INC        EDI
    //         0055246d     XOR        EAX,EAX
    //         0055246f     MOV        dword ptr [ESP + Stack[0x8]],ECX
    //         00552476     MOV        dword ptr [ESP + local_19c],EAX
    //         0055247a     MOV        dword ptr [ESP + local_198],EAX
    //         0055247e     JMP        switchD_00552440::caseD_46
    //                               switchD_00552440::caseD_4c                                   XREF[2]:     00552440(j), 00552f48(*)  
    //         00552480     INC        byte ptr [ESP + local_1c6]
    //         00552484     JMP        switchD_00552440::caseD_46
    //                               switchD_00552440::caseD_6c                                   XREF[2]:     00552440(j), 00552f54(*)  
    //         00552486     INC        byte ptr [ESP + local_1c6]
    //                               switchD_00552440::caseD_77                                   XREF[2]:     00552440(j), 00552f58(*)  
    //         0055248a     INC        byte ptr [ESP + local_1c7]
    //         0055248e     JMP        switchD_00552440::caseD_46
    //                               switchD_00552440::caseD_2a                                   XREF[2]:     00552440(j), 00552f3c(*)  
    //         00552490     INC        byte ptr [ESP + local_1c5]
    //         00552494     JMP        switchD_00552440::caseD_46
    //                               switchD_00552440::caseD_2c                                   XREF[5]:     00552436(j), 00552440(j), 
    //                               switchD_00552440::caseD_2d                                                00552461(j), 00552467(j), 
    //                               switchD_00552440::caseD_2e                                                00552f5c(*)  
    //                               switchD_00552440::caseD_2f
    //                               switchD_00552440::caseD_30
    //                               switchD_00552440::caseD_31
    //                               switchD_00552440::caseD_32
    //                               switchD_00552440::caseD_33
    //                               switchD_00552440::caseD_34
    //                               switchD_00552440::caseD_35
    //                               switchD_00552440::caseD_36
    //                               switchD_00552440::caseD_37
    //                               switchD_00552440::caseD_38
    //                               switchD_00552440::caseD_39
    //                               switchD_00552440::caseD_3a
    //                               switchD_00552440::caseD_3b
    //                               switchD_00552440::caseD_3c
    //                               switchD_00552440::caseD_3d
    //                               switchD_00552440::caseD_3e
    //                               switchD_00552440::caseD_3f
    //                               switchD_00552440::caseD_40
    //                               switchD_00552440::caseD_41
    //                               switchD_00552440::caseD_42
    //                               switchD_00552440::caseD_43
    //                               switchD_00552440::caseD_44
    //                               switchD_00552440::caseD_45
    //                               switchD_00552440::caseD_47
    //                               switchD_00552440::caseD_48
    //                               switchD_00552440::caseD_4a
    //                               switchD_00552440::caseD_4b
    //                               switchD_00552440::caseD_4d
    //                               switchD_00552440::caseD_4f
    //                               switchD_00552440::caseD_50
    //                               switchD_00552440::caseD_51
    //                               switchD_00552440::caseD_52
    //                               switchD_00552440::caseD_53
    //                               switchD_00552440::caseD_54
    //                               switchD_00552440::caseD_55
    //                               switchD_00552440::caseD_56
    //                               switchD_00552440::caseD_57
    //                               switchD_00552440::caseD_58
    //                               switchD_00552440::caseD_59
    //                               switchD_00552440::caseD_5a
    //                               switchD_00552440::caseD_5b
    //                               switchD_00552440::caseD_5c
    //                               switchD_00552440::caseD_5d
    //                               switchD_00552440::caseD_5e
    //                               switchD_00552440::caseD_5f
    //                               switchD_00552440::caseD_60
    //                               switchD_00552440::caseD_61
    //                               switchD_00552440::caseD_62
    //                               switchD_00552440::caseD_63
    //                               switchD_00552440::caseD_64
    //                               switchD_00552440::caseD_65
    //                               switchD_00552440::caseD_66
    //                               switchD_00552440::caseD_67
    //                               switchD_00552440::caseD_69
    //                               switchD_00552440::caseD_6a
    //                               switchD_00552440::caseD_6b
    //                               switchD_00552440::caseD_6d
    //                               switchD_00552440::caseD_6e
    //                               switchD_00552440::caseD_6f
    //                               switchD_00552440::caseD_70
    //                               switchD_00552440::caseD_71
    //                               switchD_00552440::caseD_72
    //                               switchD_00552440::caseD_73
    //                               switchD_00552440::caseD_74
    //                               switchD_00552440::caseD_75
    //                               switchD_00552440::caseD_76
    //                               switchD_00552440::caseD_2b
    //         00552496     INC        byte ptr [ESP + local_1cd]
    //                               switchD_00552440::caseD_4e                                   XREF[9]:     0055242e(j), 00552440(j), 
    //                               switchD_00552440::caseD_46                                                0055245b(j), 0055247e(j), 
    //                                                                                                         00552484(j), 0055248e(j), 
    //                                                                                                         00552494(j), 00552f40(*), 
    //                                                                                                         00552f4c(*)  
    //         0055249a     MOV        AL,byte ptr [ESP + local_1cd]
    //         0055249e     TEST       AL,AL
    //         005524a0     JZ         LAB_005523cc
    //         005524a6     MOV        AL,byte ptr [ESP + local_1c5]
    //         005524aa     MOV        dword ptr [ESP + local_188],EDI
    //         005524ae     TEST       AL,AL
    //         005524b0     JNZ        LAB_005524ce
    //         005524b2     MOV        EAX,dword ptr [ESP + Stack[0xc]]
    //         005524b9     MOV        dword ptr [ESP + local_18c],EAX
    //         005524bd     ADD        EAX,0x4
    //         005524c0     MOV        dword ptr [ESP + Stack[0xc]],EAX
    //         005524c7     MOV        EAX,dword ptr [EAX + -0x4]
    //         005524ca     MOV        dword ptr [ESP + local_1b8],EAX
    //                               LAB_005524ce                                                 XREF[1]:     005524b0(j)  
    //         005524ce     MOV        AL,byte ptr [ESP + local_1c7]
    //         005524d2     MOV        byte ptr [ESP + local_1cd],0x0
    //         005524d7     TEST       AL,AL
    //         005524d9     JNZ        LAB_005524ef
    //         005524db     MOV        AL,byte ptr [ECX]
    //         005524dd     CMP        AL,0x53
    //         005524df     JZ         LAB_005524ea
    //         005524e1     CMP        AL,0x43
    //         005524e3     MOV        byte ptr [ESP + local_1c7],0xff
    //         005524e8     JNZ        LAB_005524ef
    //                               LAB_005524ea                                                 XREF[1]:     005524df(j)  
    //         005524ea     MOV        byte ptr [ESP + local_1c7],0x1
    //                               LAB_005524ef                                                 XREF[2]:     005524d9(j), 005524e8(j)  
    //         005524ef     XOR        EAX,EAX
    //         005524f1     MOV        AL,byte ptr [ECX]
    //         005524f3     OR         AL,0x20
    //         005524f5     CMP        EAX,0x6e
    //         005524f8     MOV        dword ptr [ESP + local_1bc],EAX
    //         005524fc     JZ         LAB_0055252c
    //         005524fe     CMP        EAX,0x63
    //         00552501     JZ         LAB_00552518
    //         00552503     CMP        EAX,0x7b
    //         00552506     JZ         LAB_00552518
    //         00552508     LEA        ECX=>local_1cc,[ESP + 0x14]
    //         0055250c     PUSH       EBP
    //         0055250d     PUSH       ECX
    //         0055250e     CALL       FUN_00553090                                     undefined FUN_00553090()
    //         00552513     ADD        ESP,0x8
    //         00552516     JMP        LAB_0055252a
    //                               LAB_00552518                                                 XREF[2]:     00552501(j), 00552506(j)  
    //         00552518     MOV        ESI,dword ptr [ESP + local_1cc]
    //         0055251c     PUSH       EBP
    //         0055251d     INC        ESI
    //         0055251e     MOV        dword ptr [ESP + local_1cc],ESI
    //         00552522     CALL       FUN_00553040                                     undefined FUN_00553040()
    //         00552527     ADD        ESP,0x4
    //                               LAB_0055252a                                                 XREF[1]:     00552516(j)  
    //         0055252a     MOV        EBX,EAX
    //                               LAB_0055252c                                                 XREF[1]:     005524fc(j)  
    //         0055252c     MOV        ECX,dword ptr [ESP + local_1b0]
    //         00552530     TEST       ECX,ECX
    //         00552532     JZ         LAB_00552540
    //         00552534     MOV        EAX,dword ptr [ESP + local_1c4]
    //         00552538     TEST       EAX,EAX
    //         0055253a     JZ         LAB_00552efd
    //                               LAB_00552540                                                 XREF[1]:     00552532(j)  
    //         00552540     MOV        ESI,dword ptr [ESP + local_1bc]
    //         00552544     LEA        EAX,[ESI + -0x63]
    //         00552547     CMP        EAX,0x18
    //         0055254a     JA         switchD_00552558::caseD_68
    //         00552550     XOR        EDX,EDX
    //         00552552     MOV        DL,byte ptr [EAX + 0x552fe0]=>BYTE_00552f7d      = 8h
    //                               switchD_00552558::switchD
    //         00552558     JMP        dword ptr [EDX*0x4 + switchD_00552558::switchd   = 0055255f
    //                               switchD_00552558::caseD_63                                   XREF[2]:     00552558(j), 00552fb0(*)  
    //         0055255f     TEST       ECX,ECX
    //         00552561     JNZ        LAB_00552574
    //         00552563     MOV        EAX,dword ptr [ESP + local_1c4]
    //         00552567     MOV        dword ptr [ESP + local_1b0],0x1
    //         0055256f     INC        EAX
    //         00552570     MOV        dword ptr [ESP + local_1c4],EAX
    //                               LAB_00552574                                                 XREF[1]:     00552561(j)  
    //         00552574     MOV        AL,byte ptr [ESP + local_1c7]
    //         00552578     TEST       AL,AL
    //         0055257a     JLE        LAB_00552581
    //         0055257c     MOV        byte ptr [ESP + local_1c0],0x1
    //                               LAB_00552581                                                 XREF[1]:     0055257a(j)  
    //         00552581     MOV        EDX,DAT_00591d88                                 = 5Dh    ]
    //         00552586     JMP        LAB_005525be
    //                               switchD_00552558::caseD_73                                   XREF[2]:     00552558(j), 00552fcc(*)  
    //         00552588     MOV        AL,byte ptr [ESP + local_1c7]
    //         0055258c     TEST       AL,AL
    //         0055258e     JLE        LAB_00552595
    //         00552590     MOV        byte ptr [ESP + local_1c0],0x1
    //                               LAB_00552595                                                 XREF[1]:     0055258e(j)  
    //         00552595     MOV        EDX,s_-_]_00591d80                               = " \t-\r]"
    //         0055259a     JMP        LAB_005525be
    //                               switchD_00552558::caseD_7b                                   XREF[2]:     00552558(j), 00552fd8(*)  
    //         0055259c     MOV        AL,byte ptr [ESP + local_1c7]
    //         005525a0     TEST       AL,AL
    //         005525a2     JLE        LAB_005525a9
    //         005525a4     MOV        byte ptr [ESP + local_1c0],0x1
    //                               LAB_005525a9                                                 XREF[1]:     005525a2(j)  
    //         005525a9     MOV        EDX,dword ptr [ESP + Stack[0x8]]
    //         005525b0     INC        EDX
    //         005525b1     MOV        dword ptr [ESP + Stack[0x8]],EDX
    //         005525b8     CMP        byte ptr [EDX],0x5e
    //         005525bb     JNZ        LAB_005525c3
    //         005525bd     INC        EDX
    //                               LAB_005525be                                                 XREF[2]:     00552586(j), 0055259a(j)  
    //         005525be     MOV        byte ptr [ESP + local_1bd],0xff
    //                               LAB_005525c3                                                 XREF[1]:     005525bb(j)  
    //         005525c3     MOV        ECX,0x8
    //         005525c8     XOR        EAX,EAX
    //         005525ca     LEA        EDI=>local_180,[ESP + 0x60]
    //         005525ce     CMP        ESI,0x7b
    //         005525d1     STOSD.REP  ES:EDI
    //         005525d3     JNZ        LAB_005525e5
    //         005525d5     CMP        byte ptr [EDX],0x5d
    //         005525d8     JNZ        LAB_005525e5
    //         005525da     MOV        byte ptr [ESP + local_1b4],0x5d
    //         005525df     INC        EDX
    //         005525e0     MOV        byte ptr [ESP + local_175],0x20
    //                               LAB_005525e5                                                 XREF[2]:     005525d3(j), 005525d8(j)  
    //         005525e5     MOV        AL,byte ptr [EDX]
    //         005525e7     CMP        AL,0x5d
    //         005525e9     JZ         LAB_00552693
    //                               LAB_005525ef                                                 XREF[1]:     0055268d(j)  
    //         005525ef     MOV        CL,AL
    //         005525f1     INC        EDX
    //         005525f2     CMP        CL,0x2d
    //         005525f5     MOV        byte ptr [ESP + local_184],CL
    //         005525f9     JNZ        LAB_00552669
    //         005525fb     MOV        AL,byte ptr [ESP + local_1b4]
    //         005525ff     TEST       AL,AL
    //         00552601     JZ         LAB_00552669
    //         00552603     MOV        AL,byte ptr [EDX]
    //         00552605     CMP        AL,0x5d
    //         00552607     JZ         LAB_00552669
    //         00552609     MOV        CL,byte ptr [ESP + local_1b4]
    //         0055260d     INC        EDX
    //         0055260e     CMP        CL,AL
    //         00552610     JNC        LAB_00552618
    //         00552612     MOV        byte ptr [ESP + local_194],AL
    //         00552616     JMP        LAB_00552622
    //                               LAB_00552618                                                 XREF[1]:     00552610(j)  
    //         00552618     MOV        byte ptr [ESP + local_194],CL
    //         0055261c     MOV        byte ptr [ESP + local_1b4],AL
    //         00552620     MOV        CL,AL
    //                               LAB_00552622                                                 XREF[1]:     00552616(j)  
    //         00552622     CMP        CL,byte ptr [ESP + local_194]
    //         00552626     JA         LAB_0055265b
    //         00552628     MOV        ESI,dword ptr [ESP + local_1b4]
    //         0055262c     MOV        EBP,dword ptr [ESP + local_194]
    //         00552630     AND        ESI,0xff
    //         00552636     AND        EBP,0xff
    //         0055263c     SUB        EBP,ESI
    //         0055263e     INC        EBP
    //                               LAB_0055263f                                                 XREF[1]:     00552659(j)  
    //         0055263f     MOV        EAX,ESI
    //         00552641     MOV        ECX,ESI
    //         00552643     SHR        EAX,0x3
    //         00552646     AND        ECX,0x7
    //         00552649     LEA        EDI,[ESP + EAX*0x1 + 0x60]
    //         0055264d     MOV        AL,0x1
    //         0055264f     SHL        AL,CL
    //         00552651     MOV        CL,byte ptr [EDI]
    //         00552653     OR         CL,AL
    //         00552655     INC        ESI
    //         00552656     DEC        EBP
    //         00552657     MOV        byte ptr [EDI],CL
    //         00552659     JNZ        LAB_0055263f
    //                               LAB_0055265b                                                 XREF[1]:     00552626(j)  
    //         0055265b     MOV        EBP,dword ptr [ESP + Stack[0x4]]
    //         00552662     MOV        byte ptr [ESP + local_1b4],0x0
    //         00552667     JMP        LAB_00552689
    //                               LAB_00552669                                                 XREF[3]:     005525f9(j), 00552601(j), 
    //                                                                                                         00552607(j)  
    //         00552669     MOV        byte ptr [ESP + local_1b4],CL
    //         0055266d     MOV        ECX,dword ptr [ESP + local_184]
    //         00552671     AND        ECX,0xff
    //         00552677     MOV        EAX,ECX
    //         00552679     AND        ECX,0x7
    //         0055267c     SHR        EAX,0x3
    //         0055267f     LEA        ESI,[ESP + EAX*0x1 + 0x60]
    //         00552683     MOV        AL,0x1
    //         00552685     SHL        AL,CL
    //         00552687     OR         byte ptr [ESI],AL
    //                               LAB_00552689                                                 XREF[1]:     00552667(j)  
    //         00552689     MOV        AL,byte ptr [EDX]
    //         0055268b     CMP        AL,0x5d
    //         0055268d     JNZ        LAB_005525ef
    //                               LAB_00552693                                                 XREF[1]:     005525e9(j)  
    //         00552693     CMP        byte ptr [EDX],0x0
    //         00552696     JZ         LAB_00552f16
    //         0055269c     CMP        dword ptr [ESP + local_1bc],0x7b
    //         005526a1     JNZ        LAB_005526aa
    //         005526a3     MOV        dword ptr [ESP + Stack[0x8]],EDX
    //                               LAB_005526aa                                                 XREF[1]:     005526a1(j)  
    //         005526aa     MOV        EAX,dword ptr [ESP + local_1cc]
    //         005526ae     MOV        EDI,dword ptr [ESP + local_1b8]
    //         005526b2     DEC        EAX
    //         005526b3     PUSH       EBP
    //         005526b4     PUSH       EBX
    //         005526b5     MOV        ESI,EDI
    //         005526b7     MOV        dword ptr [ESP + local_1cc],EAX
    //         005526bb     CALL       FUN_00553070                                     undefined FUN_00553070()
    //         005526c0     ADD        ESP,0x8
    //                               LAB_005526c3                                                 XREF[3]:     0055277c(j), 00552784(j), 
    //                                                                                                         0055278a(j)  
    //         005526c3     MOV        EAX,dword ptr [ESP + local_1b0]
    //         005526c7     TEST       EAX,EAX
    //         005526c9     JZ         LAB_005526de
    //         005526cb     MOV        EAX,dword ptr [ESP + local_1c4]
    //         005526cf     MOV        ECX,EAX
    //         005526d1     DEC        EAX
    //         005526d2     TEST       ECX,ECX
    //         005526d4     MOV        dword ptr [ESP + local_1c4],EAX
    //         005526d8     JZ         LAB_005527a8
    //                               LAB_005526de                                                 XREF[1]:     005526c9(j)  
    //         005526de     MOV        EBX,dword ptr [ESP + local_1cc]
    //         005526e2     PUSH       EBP
    //         005526e3     INC        EBX
    //         005526e4     MOV        dword ptr [ESP + local_1cc],EBX
    //         005526e8     CALL       FUN_00553040                                     undefined FUN_00553040()
    //         005526ed     MOV        EBX,EAX
    //         005526ef     ADD        ESP,0x4
    //         005526f2     CMP        EBX,-0x1
    //         005526f5     JZ         LAB_0055278f
    //         005526fb     MOV        ECX,EBX
    //         005526fd     MOV        EDX,0x1
    //         00552702     AND        ECX,0x7
    //         00552705     SAR        EAX,0x3
    //         00552708     SHL        EDX,CL
    //         0055270a     MOVSX      ECX,byte ptr [ESP + EAX*0x1 + 0x60]
    //         0055270f     MOVSX      EAX,byte ptr [ESP + local_1bd]
    //         00552714     XOR        ECX,EAX
    //         00552716     TEST       ECX,EDX
    //         00552718     JZ         LAB_0055278f
    //         0055271a     MOV        AL,byte ptr [ESP + local_1c5]
    //         0055271e     TEST       AL,AL
    //         00552720     JNZ        LAB_00552789
    //         00552722     MOV        AL,byte ptr [ESP + local_1c0]
    //         00552726     TEST       AL,AL
    //         00552728     JZ         LAB_00552781
    //         0055272a     MOV        EDX,dword ptr [__pctype]                         = 005920da
    //         00552730     MOV        ECX,EBX
    //         00552732     AND        ECX,0xff
    //         00552738     MOV        byte ptr [ESP + local_19e],BL
    //         0055273c     TEST       byte ptr [EDX + ECX*0x2 + 0x1]=>DAT_005920db,0
    //         00552741     JZ         LAB_00552759
    //         00552743     MOV        EAX,dword ptr [ESP + local_1cc]
    //         00552747     PUSH       EBP
    //         00552748     INC        EAX
    //         00552749     MOV        dword ptr [ESP + local_1cc],EAX
    //         0055274d     CALL       FUN_00553040                                     undefined FUN_00553040()
    //         00552752     ADD        ESP,0x4
    //         00552755     MOV        byte ptr [ESP + local_19d],AL
    //                               LAB_00552759                                                 XREF[1]:     00552741(j)  
    //         00552759     MOV        EAX,[___mb_cur_max]                              = 00000001h
    //         0055275e     LEA        ECX=>local_19e,[ESP + 0x42]
    //         00552762     PUSH       EAX
    //         00552763     LEA        EDX=>local_18e,[ESP + 0x56]
    //         00552767     PUSH       ECX
    //         00552768     PUSH       EDX
    //         00552769     CALL       mbtowc                                           undefined mbtowc()
    //         0055276e     MOV        AX,word ptr [ESP + local_18e]
    //         00552773     ADD        ESP,0xc
    //         00552776     MOV        word ptr [EDI],AX
    //         00552779     ADD        EDI,0x2
    //         0055277c     JMP        LAB_005526c3
    //                               LAB_00552781                                                 XREF[1]:     00552728(j)  
    //         00552781     MOV        byte ptr [EDI],BL
    //         00552783     INC        EDI
    //         00552784     JMP        LAB_005526c3
    //                               LAB_00552789                                                 XREF[1]:     00552720(j)  
    //         00552789     INC        ESI
    //         0055278a     JMP        LAB_005526c3
    //                               LAB_0055278f                                                 XREF[2]:     005526f5(j), 00552718(j)  
    //         0055278f     MOV        EAX,dword ptr [ESP + local_1cc]
    //         00552793     PUSH       EBP
    //         00552794     DEC        EAX
    //         00552795     PUSH       EBX
    //         00552796     MOV        dword ptr [ESP + local_1b8],EDI
    //         0055279a     MOV        dword ptr [ESP + local_1cc],EAX
    //         0055279e     CALL       FUN_00553070                                     undefined FUN_00553070()
    //         005527a3     ADD        ESP,0x8
    //         005527a6     JMP        LAB_005527ac
    //                               LAB_005527a8                                                 XREF[1]:     005526d8(j)  
    //         005527a8     MOV        dword ptr [ESP + local_1b8],EDI
    //                               LAB_005527ac                                                 XREF[1]:     005527a6(j)  
    //         005527ac     CMP        ESI,EDI
    //         005527ae     JZ         LAB_00552f16
    //         005527b4     MOV        AL,byte ptr [ESP + local_1c5]
    //         005527b8     TEST       AL,AL
    //         005527ba     JNZ        LAB_00552e48
    //         005527c0     MOV        ECX,dword ptr [ESP + local_1ac]
    //         005527c4     MOV        EAX,dword ptr [ESP + local_1bc]
    //         005527c8     INC        ECX
    //         005527c9     CMP        EAX,0x63
    //         005527cc     MOV        dword ptr [ESP + local_1ac],ECX
    //         005527d0     JZ         LAB_00552e48
    //         005527d6     MOV        AL,byte ptr [ESP + local_1c0]
    //         005527da     TEST       AL,AL
    //         005527dc     JZ         LAB_005527ec
    //         005527de     MOV        ECX,dword ptr [ESP + local_1b8]
    //         005527e2     MOV        word ptr [ECX],0x0
    //         005527e7     JMP        LAB_00552e48
    //                               LAB_005527ec                                                 XREF[1]:     005527dc(j)  
    //         005527ec     MOV        EDX,dword ptr [ESP + local_1b8]
    //         005527f0     MOV        byte ptr [EDX],0x0
    //         005527f3     JMP        LAB_00552e48
    //                               switchD_00552558::caseD_69                                   XREF[2]:     00552558(j), 00552fbc(*)  
    //         005527f8     MOV        ESI,0x64
    //         005527fd     MOV        dword ptr [ESP + local_1bc],ESI
    //                               switchD_00552558::caseD_78                                   XREF[2]:     00552558(j), 00552fd4(*)  
    //         00552801     CMP        EBX,0x2d
    //         00552804     JNZ        LAB_0055280d
    //         00552806     MOV        byte ptr [ESP + local_1be],0x1
    //         0055280b     JMP        LAB_00552812
    //                               LAB_0055280d                                                 XREF[1]:     00552804(j)  
    //         0055280d     CMP        EBX,0x2b
    //         00552810     JNZ        LAB_0055283c
    //                               LAB_00552812                                                 XREF[1]:     0055280b(j)  
    //         00552812     MOV        EAX,dword ptr [ESP + local_1c4]
    //         00552816     DEC        EAX
    //         00552817     MOV        dword ptr [ESP + local_1c4],EAX
    //         0055281b     JNZ        LAB_00552828
    //         0055281d     TEST       ECX,ECX
    //         0055281f     JZ         LAB_00552828
    //         00552821     MOV        byte ptr [ESP + local_1cd],0x1
    //         00552826     JMP        LAB_0055283c
    //                               LAB_00552828                                                 XREF[2]:     0055281b(j), 0055281f(j)  
    //         00552828     MOV        EBX,dword ptr [ESP + local_1cc]
    //         0055282c     PUSH       EBP
    //         0055282d     INC        EBX
    //         0055282e     MOV        dword ptr [ESP + local_1cc],EBX
    //         00552832     CALL       FUN_00553040                                     undefined FUN_00553040()
    //         00552837     ADD        ESP,0x4
    //         0055283a     MOV        EBX,EAX
    //                               LAB_0055283c                                                 XREF[2]:     00552810(j), 00552826(j)  
    //         0055283c     CMP        EBX,0x30
    //         0055283f     JNZ        LAB_005528f4
    //         00552845     MOV        EBX,dword ptr [ESP + local_1cc]
    //         00552849     PUSH       EBP
    //         0055284a     INC        EBX
    //         0055284b     MOV        dword ptr [ESP + local_1cc],EBX
    //         0055284f     CALL       FUN_00553040                                     undefined FUN_00553040()
    //         00552854     MOV        EBX,EAX
    //         00552856     ADD        ESP,0x4
    //         00552859     CMP        BL,0x78
    //         0055285c     JZ         LAB_00552895
    //         0055285e     CMP        BL,0x58
    //         00552861     JZ         LAB_00552895
    //         00552863     CMP        ESI,0x78
    //         00552866     MOV        dword ptr [ESP + local_1a8],0x1
    //         0055286e     JZ         LAB_0055287b
    //                              language.dll match for 0x6f: "12"
    //         00552870     MOV        ESI,0x6f
    //         00552875     MOV        dword ptr [ESP + local_1bc],ESI
    //         00552879     JMP        LAB_005528f4
    //                               LAB_0055287b                                                 XREF[1]:     0055286e(j)  
    //         0055287b     MOV        EAX,dword ptr [ESP + local_1cc]
    //         0055287f     PUSH       EBP
    //         00552880     DEC        EAX
    //         00552881     PUSH       EBX
    //         00552882     MOV        dword ptr [ESP + local_1cc],EAX
    //         00552886     CALL       FUN_00553070                                     undefined FUN_00553070()
    //         0055288b     ADD        ESP,0x8
    //         0055288e     MOV        EBX,0x30
    //         00552893     JMP        LAB_005528f4
    //                               LAB_00552895                                                 XREF[2]:     0055285c(j), 00552861(j)  
    //         00552895     MOV        ESI,dword ptr [ESP + local_1cc]
    //         00552899     PUSH       EBP
    //         0055289a     INC        ESI
    //         0055289b     MOV        dword ptr [ESP + local_1cc],ESI
    //         0055289f     CALL       FUN_00553040                                     undefined FUN_00553040()
    //         005528a4     MOV        ESI,0x78
    //         005528a9     ADD        ESP,0x4
    //         005528ac     MOV        EBX,EAX
    //         005528ae     MOV        dword ptr [ESP + local_1bc],ESI
    //         005528b2     JMP        LAB_005528f4
    //                               switchD_00552558::caseD_70                                   XREF[2]:     00552558(j), 00552fc8(*)  
    //         005528b4     MOV        byte ptr [ESP + local_1c6],0x1
    //                               switchD_00552558::caseD_6f                                   XREF[4]:     00552558(j), 00552fb4(*), 
    //                               switchD_00552558::caseD_75                                                00552fc4(*), 00552fd0(*)  
    //                               switchD_00552558::caseD_64
    //         005528b9     CMP        EBX,0x2d
    //         005528bc     JNZ        LAB_005528c5
    //         005528be     MOV        byte ptr [ESP + local_1be],0x1
    //         005528c3     JMP        LAB_005528ca
    //                               LAB_005528c5                                                 XREF[1]:     005528bc(j)  
    //         005528c5     CMP        EBX,0x2b
    //         005528c8     JNZ        LAB_005528f4
    //                               LAB_005528ca                                                 XREF[1]:     005528c3(j)  
    //         005528ca     MOV        EAX,dword ptr [ESP + local_1c4]
    //         005528ce     DEC        EAX
    //         005528cf     MOV        dword ptr [ESP + local_1c4],EAX
    //         005528d3     JNZ        LAB_005528e0
    //         005528d5     TEST       ECX,ECX
    //         005528d7     JZ         LAB_005528e0
    //         005528d9     MOV        byte ptr [ESP + local_1cd],0x1
    //         005528de     JMP        LAB_005528f4
    //                               LAB_005528e0                                                 XREF[2]:     005528d3(j), 005528d7(j)  
    //         005528e0     MOV        EBX,dword ptr [ESP + local_1cc]
    //         005528e4     PUSH       EBP
    //         005528e5     INC        EBX
    //         005528e6     MOV        dword ptr [ESP + local_1cc],EBX
    //         005528ea     CALL       FUN_00553040                                     undefined FUN_00553040()
    //         005528ef     ADD        ESP,0x4
    //         005528f2     MOV        EBX,EAX
    //                               LAB_005528f4                                                 XREF[6]:     0055283f(j), 00552879(j), 
    //                                                                                                         00552893(j), 005528b2(j), 
    //                                                                                                         005528c8(j), 005528de(j)  
    //         005528f4     MOV        AL,byte ptr [ESP + local_1cd]
    //         005528f8     TEST       EDI,EDI
    //         005528fa     JZ         LAB_00552a59
    //         00552900     TEST       AL,AL
    //         00552902     JNZ        LAB_00552a31
    //         00552908     MOV        EBP,dword ptr [ESP + Stack[0x4]]
    //         0055290f     MOV        ESI,dword ptr [ESP + local_19c]
    //         00552913     MOV        EDI,dword ptr [ESP + local_198]
    //                               LAB_00552917                                                 XREF[1]:     00552a23(j)  
    //         00552917     MOV        EAX,dword ptr [ESP + local_1bc]
    //         0055291b     CMP        EAX,0x78
    //         0055291e     MOV        EAX,[___mb_cur_max]                              = 00000001h
    //         00552923     JNZ        LAB_0055296a
    //         00552925     CMP        EAX,0x1
    //         00552928     JLE        LAB_0055293a
    //                              language.dll match for 0x80: "Arial"
    //         0055292a     PUSH       0x80
    //         0055292f     PUSH       EBX
    //         00552930     CALL       __isctype                                        undefined __isctype()
    //         00552935     ADD        ESP,0x8
    //         00552938     JMP        LAB_00552947
    //                               LAB_0055293a                                                 XREF[1]:     00552928(j)  
    //         0055293a     MOV        EAX,[__pctype]                                   = 005920da
    //         0055293f     MOV        AL,byte ptr [EAX + EBX*0x2]=>DAT_005920da        = 20h     
    //         00552942     AND        EAX,0x80
    //                               LAB_00552947                                                 XREF[1]:     00552938(j)  
    //         00552947     TEST       EAX,EAX
    //         00552949     JZ         LAB_005529bd
    //         0055294b     MOV        ECX,0x4
    //         00552950     MOV        EAX,ESI
    //         00552952     MOV        EDX,EDI
    //         00552954     CALL       __allshl                                         undefined __allshl()
    //         00552959     PUSH       EBX
    //         0055295a     MOV        ESI,EAX
    //         0055295c     MOV        EDI,EDX
    //         0055295e     CALL       FUN_00553000                                     undefined FUN_00553000()
    //         00552963     ADD        ESP,0x4
    //         00552966     MOV        EBX,EAX
    //         00552968     JMP        LAB_005529c1
    //                               LAB_0055296a                                                 XREF[1]:     00552923(j)  
    //         0055296a     CMP        EAX,0x1
    //         0055296d     JLE        LAB_0055297c
    //         0055296f     PUSH       0x4
    //         00552971     PUSH       EBX
    //         00552972     CALL       __isctype                                        undefined __isctype()
    //         00552977     ADD        ESP,0x8
    //         0055297a     JMP        LAB_00552988
    //                               LAB_0055297c                                                 XREF[1]:     0055296d(j)  
    //         0055297c     MOV        ECX,dword ptr [__pctype]                         = 005920da
    //         00552982     MOV        AL,byte ptr [ECX + EBX*0x2]=>DAT_005920da        = 20h     
    //         00552985     AND        EAX,0x4
    //                               LAB_00552988                                                 XREF[1]:     0055297a(j)  
    //         00552988     TEST       EAX,EAX
    //         0055298a     JZ         LAB_005529bd
    //         0055298c     CMP        dword ptr [ESP + local_1bc],0x6f
    //         00552991     JNZ        LAB_005529ac
    //         00552993     CMP        EBX,0x38
    //         00552996     JGE        LAB_005529bd
    //         00552998     MOV        ECX,0x3
    //         0055299d     MOV        EAX,ESI
    //         0055299f     MOV        EDX,EDI
    //         005529a1     CALL       __allshl                                         undefined __allshl()
    //         005529a6     MOV        ESI,EAX
    //         005529a8     MOV        EDI,EDX
    //         005529aa     JMP        LAB_005529c1
    //                               LAB_005529ac                                                 XREF[1]:     00552991(j)  
    //         005529ac     PUSH       0x0
    //         005529ae     PUSH       0xa
    //         005529b0     PUSH       EDI
    //         005529b1     PUSH       ESI
    //         005529b2     CALL       __allmul                                         undefined __allmul()
    //         005529b7     MOV        ESI,EAX
    //         005529b9     MOV        EDI,EDX
    //         005529bb     JMP        LAB_005529c1
    //                               LAB_005529bd                                                 XREF[3]:     00552949(j), 0055298a(j), 
    //                                                                                                         00552996(j)  
    //         005529bd     INC        byte ptr [ESP + local_1cd]
    //                               LAB_005529c1                                                 XREF[3]:     00552968(j), 005529aa(j), 
    //                                                                                                         005529bb(j)  
    //         005529c1     MOV        AL,byte ptr [ESP + local_1cd]
    //         005529c5     TEST       AL,AL
    //         005529c7     JNZ        LAB_00552a0a
    //         005529c9     MOV        EDX,dword ptr [ESP + local_1a8]
    //         005529cd     LEA        EAX,[EBX + -0x30]
    //         005529d0     INC        EDX
    //         005529d1     MOV        dword ptr [ESP + local_1a8],EDX
    //         005529d5     CDQ
    //         005529d6     ADD        ESI,EAX
    //         005529d8     MOV        EAX,dword ptr [ESP + local_1b0]
    //         005529dc     ADC        EDI,EDX
    //         005529de     TEST       EAX,EAX
    //         005529e0     JZ         LAB_005529f4
    //         005529e2     MOV        EAX,dword ptr [ESP + local_1c4]
    //         005529e6     DEC        EAX
    //         005529e7     MOV        dword ptr [ESP + local_1c4],EAX
    //         005529eb     JNZ        LAB_005529f4
    //         005529ed     MOV        byte ptr [ESP + local_1cd],0x1
    //         005529f2     JMP        LAB_00552a1d
    //                               LAB_005529f4                                                 XREF[2]:     005529e0(j), 005529eb(j)  
    //         005529f4     MOV        EBX,dword ptr [ESP + local_1cc]
    //         005529f8     PUSH       EBP
    //         005529f9     INC        EBX
    //         005529fa     MOV        dword ptr [ESP + local_1cc],EBX
    //         005529fe     CALL       FUN_00553040                                     undefined FUN_00553040()
    //         00552a03     ADD        ESP,0x4
    //         00552a06     MOV        EBX,EAX
    //         00552a08     JMP        LAB_00552a1d
    //                               LAB_00552a0a                                                 XREF[1]:     005529c7(j)  
    //         00552a0a     MOV        EAX,dword ptr [ESP + local_1cc]
    //         00552a0e     PUSH       EBP
    //         00552a0f     DEC        EAX
    //         00552a10     PUSH       EBX
    //         00552a11     MOV        dword ptr [ESP + local_1cc],EAX
    //         00552a15     CALL       FUN_00553070                                     undefined FUN_00553070()
    //         00552a1a     ADD        ESP,0x8
    //                               LAB_00552a1d                                                 XREF[2]:     005529f2(j), 00552a08(j)  
    //         00552a1d     MOV        AL,byte ptr [ESP + local_1cd]
    //         00552a21     TEST       AL,AL
    //         00552a23     JZ         LAB_00552917
    //         00552a29     MOV        dword ptr [ESP + local_198],EDI
    //         00552a2d     MOV        dword ptr [ESP + local_19c],ESI
    //                               LAB_00552a31                                                 XREF[1]:     00552902(j)  
    //         00552a31     MOV        AL,byte ptr [ESP + local_1be]
    //         00552a35     TEST       AL,AL
    //         00552a37     JZ         LAB_00552b60
    //         00552a3d     MOV        EDX,dword ptr [ESP + local_19c]
    //         00552a41     MOV        EAX,dword ptr [ESP + local_198]
    //         00552a45     NEG        EDX
    //         00552a47     ADC        EAX,0x0
    //         00552a4a     MOV        dword ptr [ESP + local_19c],EDX
    //         00552a4e     NEG        EAX
    //         00552a50     MOV        dword ptr [ESP + local_198],EAX
    //         00552a54     JMP        LAB_00552b60
    //                               LAB_00552a59                                                 XREF[1]:     005528fa(j)  
    //         00552a59     MOV        EDI,dword ptr [ESP + local_1a4]
    //         00552a5d     TEST       AL,AL
    //         00552a5f     JNZ        LAB_00552b52
    //                               LAB_00552a65                                                 XREF[1]:     00552b48(j)  
    //         00552a65     CMP        ESI,0x78
    //         00552a68     JZ         LAB_00552aab
    //         00552a6a     CMP        ESI,0x70
    //         00552a6d     JZ         LAB_00552aab
    //         00552a6f     CMP        dword ptr [___mb_cur_max],0x1                    = 00000001h
    //         00552a76     JLE        LAB_00552a85
    //         00552a78     PUSH       0x4
    //         00552a7a     PUSH       EBX
    //         00552a7b     CALL       __isctype                                        undefined __isctype()
    //         00552a80     ADD        ESP,0x8
    //         00552a83     JMP        LAB_00552a91
    //                               LAB_00552a85                                                 XREF[1]:     00552a76(j)  
    //         00552a85     MOV        ECX,dword ptr [__pctype]                         = 005920da
    //         00552a8b     MOV        AL,byte ptr [ECX + EBX*0x2]=>DAT_005920da        = 20h     
    //         00552a8e     AND        EAX,0x4
    //                               LAB_00552a91                                                 XREF[1]:     00552a83(j)  
    //         00552a91     TEST       EAX,EAX
    //         00552a93     JZ         LAB_00552ae6
    //         00552a95     CMP        ESI,0x6f
    //         00552a98     JNZ        LAB_00552aa4
    //         00552a9a     CMP        EBX,0x38
    //         00552a9d     JGE        LAB_00552ae6
    //         00552a9f     SHL        EDI,0x3
    //         00552aa2     JMP        LAB_00552aea
    //                               LAB_00552aa4                                                 XREF[1]:     00552a98(j)  
    //         00552aa4     LEA        EDI,[EDI + EDI*0x4]
    //         00552aa7     SHL        EDI,0x1
    //         00552aa9     JMP        LAB_00552aea
    //                               LAB_00552aab                                                 XREF[2]:     00552a68(j), 00552a6d(j)  
    //         00552aab     CMP        dword ptr [___mb_cur_max],0x1                    = 00000001h
    //         00552ab2     JLE        LAB_00552ac4
    //                              language.dll match for 0x80: "Arial"
    //         00552ab4     PUSH       0x80
    //         00552ab9     PUSH       EBX
    //         00552aba     CALL       __isctype                                        undefined __isctype()
    //         00552abf     ADD        ESP,0x8
    //         00552ac2     JMP        LAB_00552ad2
    //                               LAB_00552ac4                                                 XREF[1]:     00552ab2(j)  
    //         00552ac4     MOV        EDX,dword ptr [__pctype]                         = 005920da
    //         00552aca     MOV        AL,byte ptr [EDX + EBX*0x2]=>DAT_005920da        = 20h     
    //         00552acd     AND        EAX,0x80
    //                               LAB_00552ad2                                                 XREF[1]:     00552ac2(j)  
    //         00552ad2     TEST       EAX,EAX
    //         00552ad4     JZ         LAB_00552ae6
    //         00552ad6     PUSH       EBX
    //         00552ad7     SHL        EDI,0x4
    //         00552ada     CALL       FUN_00553000                                     undefined FUN_00553000()
    //         00552adf     ADD        ESP,0x4
    //         00552ae2     MOV        EBX,EAX
    //         00552ae4     JMP        LAB_00552aea
    //                               LAB_00552ae6                                                 XREF[3]:     00552a93(j), 00552a9d(j), 
    //                                                                                                         00552ad4(j)  
    //         00552ae6     INC        byte ptr [ESP + local_1cd]
    //                               LAB_00552aea                                                 XREF[3]:     00552aa2(j), 00552aa9(j), 
    //                                                                                                         00552ae4(j)  
    //         00552aea     MOV        AL,byte ptr [ESP + local_1cd]
    //         00552aee     TEST       AL,AL
    //         00552af0     JNZ        LAB_00552b2f
    //         00552af2     MOV        ECX,dword ptr [ESP + local_1a8]
    //         00552af6     MOV        EAX,dword ptr [ESP + local_1b0]
    //         00552afa     INC        ECX
    //         00552afb     LEA        EDI,[EDI + EBX*0x1 + -0x30]
    //         00552aff     TEST       EAX,EAX
    //         00552b01     MOV        dword ptr [ESP + local_1a8],ECX
    //         00552b05     JZ         LAB_00552b19
    //         00552b07     MOV        EAX,dword ptr [ESP + local_1c4]
    //         00552b0b     DEC        EAX
    //         00552b0c     MOV        dword ptr [ESP + local_1c4],EAX
    //         00552b10     JNZ        LAB_00552b19
    //         00552b12     MOV        byte ptr [ESP + local_1cd],0x1
    //         00552b17     JMP        LAB_00552b42
    //                               LAB_00552b19                                                 XREF[2]:     00552b05(j), 00552b10(j)  
    //         00552b19     MOV        EBX,dword ptr [ESP + local_1cc]
    //         00552b1d     PUSH       EBP
    //         00552b1e     INC        EBX
    //         00552b1f     MOV        dword ptr [ESP + local_1cc],EBX
    //         00552b23     CALL       FUN_00553040                                     undefined FUN_00553040()
    //         00552b28     ADD        ESP,0x4
    //         00552b2b     MOV        EBX,EAX
    //         00552b2d     JMP        LAB_00552b42
    //                               LAB_00552b2f                                                 XREF[1]:     00552af0(j)  
    //         00552b2f     MOV        EAX,dword ptr [ESP + local_1cc]
    //         00552b33     PUSH       EBP
    //         00552b34     DEC        EAX
    //         00552b35     PUSH       EBX
    //         00552b36     MOV        dword ptr [ESP + local_1cc],EAX
    //         00552b3a     CALL       FUN_00553070                                     undefined FUN_00553070()
    //         00552b3f     ADD        ESP,0x8
    //                               LAB_00552b42                                                 XREF[2]:     00552b17(j), 00552b2d(j)  
    //         00552b42     MOV        AL,byte ptr [ESP + local_1cd]
    //         00552b46     TEST       AL,AL
    //         00552b48     JZ         LAB_00552a65
    //         00552b4e     MOV        dword ptr [ESP + local_1a4],EDI
    //                               LAB_00552b52                                                 XREF[1]:     00552a5f(j)  
    //         00552b52     MOV        AL,byte ptr [ESP + local_1be]
    //         00552b56     TEST       AL,AL
    //         00552b58     JZ         LAB_00552b60
    //         00552b5a     NEG        EDI
    //         00552b5c     MOV        dword ptr [ESP + local_1a4],EDI
    //                               LAB_00552b60                                                 XREF[3]:     00552a37(j), 00552a54(j), 
    //                                                                                                         00552b58(j)  
    //         00552b60     CMP        dword ptr [ESP + local_1bc],0x46
    //         00552b65     JNZ        LAB_00552b6b
    //         00552b67     XOR        EAX,EAX
    //         00552b69     JMP        LAB_00552b6f
    //                               LAB_00552b6b                                                 XREF[1]:     00552b65(j)  
    //         00552b6b     MOV        EAX,dword ptr [ESP + local_1a8]
    //                               LAB_00552b6f                                                 XREF[1]:     00552b69(j)  
    //         00552b6f     TEST       EAX,EAX
    //         00552b71     JZ         LAB_00552f16
    //         00552b77     MOV        AL,byte ptr [ESP + local_1c5]
    //         00552b7b     TEST       AL,AL
    //         00552b7d     JNZ        LAB_00552e41
    //         00552b83     MOV        EAX,dword ptr [ESP + local_1ac]
    //         00552b87     MOV        EBP,dword ptr [ESP + Stack[0x4]]
    //         00552b8e     MOV        ECX,dword ptr [ESP + local_1b8]
    //         00552b92     MOV        EDI,dword ptr [ESP + local_188]
    //         00552b96     INC        EAX
    //         00552b97     MOV        dword ptr [ESP + local_1ac],EAX
    //         00552b9b     MOV        EAX,dword ptr [ESP + local_1a4]
    //         00552b9f     JMP        LAB_00552bb5
    //                               switchD_00552558::caseD_6e                                   XREF[2]:     00552558(j), 00552fc0(*)  
    //         00552ba1     MOV        CL,byte ptr [ESP + local_1c5]
    //         00552ba5     MOV        EAX,dword ptr [ESP + local_1cc]
    //         00552ba9     TEST       CL,CL
    //         00552bab     JNZ        LAB_00552e48
    //         00552bb1     MOV        ECX,dword ptr [ESP + local_1b8]
    //                               LAB_00552bb5                                                 XREF[1]:     00552b9f(j)  
    //         00552bb5     TEST       EDI,EDI
    //         00552bb7     JZ         LAB_00552bcb
    //         00552bb9     MOV        EAX,dword ptr [ESP + local_19c]
    //         00552bbd     MOV        EDX,dword ptr [ESP + local_198]
    //         00552bc1     MOV        dword ptr [ECX],EAX
    //         00552bc3     MOV        dword ptr [ECX + 0x4],EDX
    //         00552bc6     JMP        LAB_00552e48
    //                               LAB_00552bcb                                                 XREF[1]:     00552bb7(j)  
    //         00552bcb     MOV        DL,byte ptr [ESP + local_1c6]
    //         00552bcf     TEST       DL,DL
    //         00552bd1     JZ         LAB_00552bda
    //         00552bd3     MOV        dword ptr [ECX],EAX
    //         00552bd5     JMP        LAB_00552e48
    //                               LAB_00552bda                                                 XREF[1]:     00552bd1(j)  
    //         00552bda     MOV        word ptr [ECX],AX
    //         00552bdd     JMP        LAB_00552e48
    //                               switchD_00552558::caseD_66                                   XREF[2]:     00552558(j), 00552fb8(*)  
    //                               switchD_00552558::caseD_67
    //                               switchD_00552558::caseD_65
    //         00552be2     CMP        EBX,0x2d
    //         00552be5     LEA        ESI=>local_160,[ESP + 0x80]
    //         00552bec     JNZ        LAB_00552bfe
    //         00552bee     MOV        byte ptr [ESP + local_160],BL
    //         00552bf5     LEA        ESI=>local_15f,[ESP + 0x81]
    //         00552bfc     JMP        LAB_00552c03
    //                               LAB_00552bfe                                                 XREF[1]:     00552bec(j)  
    //         00552bfe     CMP        EBX,0x2b
    //         00552c01     JNZ        LAB_00552c20
    //                               LAB_00552c03                                                 XREF[1]:     00552bfc(j)  
    //         00552c03     MOV        EBX,dword ptr [ESP + local_1c4]
    //         00552c07     MOV        EDI,dword ptr [ESP + local_1cc]
    //         00552c0b     DEC        EBX
    //         00552c0c     INC        EDI
    //         00552c0d     PUSH       EBP
    //         00552c0e     MOV        dword ptr [ESP + local_1c4],EBX
    //         00552c12     MOV        dword ptr [ESP + local_1cc],EDI
    //         00552c16     CALL       FUN_00553040                                     undefined FUN_00553040()
    //         00552c1b     ADD        ESP,0x4
    //         00552c1e     MOV        EBX,EAX
    //                               LAB_00552c20                                                 XREF[1]:     00552c01(j)  
    //         00552c20     MOV        EAX,dword ptr [ESP + local_1b0]
    //         00552c24     TEST       EAX,EAX
    //         00552c26     JZ         LAB_00552c32
    //         00552c28     CMP        dword ptr [ESP + local_1c4],0x15d
    //         00552c30     JLE        LAB_00552c3a
    //                               LAB_00552c32                                                 XREF[1]:     00552c26(j)  
    //         00552c32     MOV        dword ptr [ESP + local_1c4],0x15d
    //                               LAB_00552c3a                                                 XREF[1]:     00552c30(j)  
    //         00552c3a     MOV        EDI,dword ptr [ESP + local_1a8]
    //                               LAB_00552c3e                                                 XREF[1]:     00552c8a(j)  
    //         00552c3e     CMP        dword ptr [___mb_cur_max],0x1                    = 00000001h
    //         00552c45     JLE        LAB_00552c54
    //         00552c47     PUSH       0x4
    //         00552c49     PUSH       EBX
    //         00552c4a     CALL       __isctype                                        undefined __isctype()
    //         00552c4f     ADD        ESP,0x8
    //         00552c52     JMP        LAB_00552c5f
    //                               LAB_00552c54                                                 XREF[1]:     00552c45(j)  
    //         00552c54     MOV        EAX,[__pctype]                                   = 005920da
    //         00552c59     MOV        AL,byte ptr [EAX + EBX*0x2]=>DAT_005920da        = 20h     
    //         00552c5c     AND        EAX,0x4
    //                               LAB_00552c5f                                                 XREF[1]:     00552c52(j)  
    //         00552c5f     TEST       EAX,EAX
    //         00552c61     JZ         LAB_00552c8c
    //         00552c63     MOV        EAX,dword ptr [ESP + local_1c4]
    //         00552c67     MOV        ECX,EAX
    //         00552c69     DEC        EAX
    //         00552c6a     TEST       ECX,ECX
    //         00552c6c     MOV        dword ptr [ESP + local_1c4],EAX
    //         00552c70     JZ         LAB_00552c8c
    //         00552c72     MOV        byte ptr [ESI]=>local_15f,BL
    //         00552c74     MOV        EBX,dword ptr [ESP + local_1cc]
    //         00552c78     INC        EDI
    //         00552c79     INC        ESI
    //         00552c7a     INC        EBX
    //         00552c7b     PUSH       EBP
    //         00552c7c     MOV        dword ptr [ESP + local_1cc],EBX
    //         00552c80     CALL       FUN_00553040                                     undefined FUN_00553040()
    //         00552c85     ADD        ESP,0x4
    //         00552c88     MOV        EBX,EAX
    //         00552c8a     JMP        LAB_00552c3e
    //                               LAB_00552c8c                                                 XREF[2]:     00552c61(j), 00552c70(j)  
    //         00552c8c     CMP        byte ptr [___decimal_point],BL                   = 2Eh
    //         00552c92     JNZ        LAB_00552d0e
    //         00552c94     MOV        EAX,dword ptr [ESP + local_1c4]
    //         00552c98     MOV        EDX,EAX
    //         00552c9a     DEC        EAX
    //         00552c9b     TEST       EDX,EDX
    //         00552c9d     MOV        dword ptr [ESP + local_1c4],EAX
    //         00552ca1     JZ         LAB_00552d0e
    //         00552ca3     MOV        EBX,dword ptr [ESP + local_1cc]
    //         00552ca7     PUSH       EBP
    //         00552ca8     INC        EBX
    //         00552ca9     MOV        dword ptr [ESP + local_1cc],EBX
    //         00552cad     CALL       FUN_00553040                                     undefined FUN_00553040()
    //         00552cb2     MOV        EBX,EAX
    //         00552cb4     MOV        AL,[___decimal_point]                            = 2Eh
    //         00552cb9     ADD        ESP,0x4
    //         00552cbc     MOV        byte ptr [ESI]=>local_15e,AL
    //         00552cbe     INC        ESI
    //                               LAB_00552cbf                                                 XREF[1]:     00552d0c(j)  
    //         00552cbf     CMP        dword ptr [___mb_cur_max],0x1                    = 00000001h
    //         00552cc6     JLE        LAB_00552cd5
    //         00552cc8     PUSH       0x4
    //         00552cca     PUSH       EBX
    //         00552ccb     CALL       __isctype                                        undefined __isctype()
    //         00552cd0     ADD        ESP,0x8
    //         00552cd3     JMP        LAB_00552ce1
    //                               LAB_00552cd5                                                 XREF[1]:     00552cc6(j)  
    //         00552cd5     MOV        ECX,dword ptr [__pctype]                         = 005920da
    //         00552cdb     MOV        AL,byte ptr [ECX + EBX*0x2]=>DAT_005920da        = 20h     
    //         00552cde     AND        EAX,0x4
    //                               LAB_00552ce1                                                 XREF[1]:     00552cd3(j)  
    //         00552ce1     TEST       EAX,EAX
    //         00552ce3     JZ         LAB_00552d0e
    //         00552ce5     MOV        EAX,dword ptr [ESP + local_1c4]
    //         00552ce9     MOV        EDX,EAX
    //         00552ceb     DEC        EAX
    //         00552cec     TEST       EDX,EDX
    //         00552cee     MOV        dword ptr [ESP + local_1c4],EAX
    //         00552cf2     JZ         LAB_00552d0e
    //         00552cf4     MOV        byte ptr [ESI]=>local_15d,BL
    //         00552cf6     MOV        EBX,dword ptr [ESP + local_1cc]
    //         00552cfa     INC        EDI
    //         00552cfb     INC        ESI
    //         00552cfc     INC        EBX
    //         00552cfd     PUSH       EBP
    //         00552cfe     MOV        dword ptr [ESP + local_1cc],EBX
    //         00552d02     CALL       FUN_00553040                                     undefined FUN_00553040()
    //         00552d07     ADD        ESP,0x4
    //         00552d0a     MOV        EBX,EAX
    //         00552d0c     JMP        LAB_00552cbf
    //                               LAB_00552d0e                                                 XREF[4]:     00552c92(j), 00552ca1(j), 
    //                                                                                                         00552ce3(j), 00552cf2(j)  
    //         00552d0e     TEST       EDI,EDI
    //         00552d10     JZ         LAB_00552dc1
    //         00552d16     CMP        EBX,0x65
    //         00552d19     JZ         LAB_00552d24
    //         00552d1b     CMP        EBX,0x45
    //         00552d1e     JNZ        LAB_00552dc1
    //                               LAB_00552d24                                                 XREF[1]:     00552d19(j)  
    //         00552d24     MOV        EAX,dword ptr [ESP + local_1c4]
    //         00552d28     MOV        ECX,EAX
    //         00552d2a     DEC        EAX
    //         00552d2b     TEST       ECX,ECX
    //         00552d2d     MOV        dword ptr [ESP + local_1c4],EAX
    //         00552d31     JZ         LAB_00552dc1
    //         00552d37     MOV        EBX,dword ptr [ESP + local_1cc]
    //                              language.dll match for 0x65: "1"
    //         00552d3b     MOV        byte ptr [ESI]=>local_15c,0x65
    //         00552d3e     INC        ESI
    //         00552d3f     INC        EBX
    //         00552d40     PUSH       EBP
    //         00552d41     MOV        dword ptr [ESP + local_1cc],EBX
    //         00552d45     CALL       FUN_00553040                                     undefined FUN_00553040()
    //         00552d4a     MOV        EBX,EAX
    //         00552d4c     ADD        ESP,0x4
    //         00552d4f     CMP        EBX,0x2d
    //         00552d52     JNZ        LAB_00552d59
    //         00552d54     MOV        byte ptr [ESI]=>local_15b,AL
    //         00552d56     INC        ESI
    //         00552d57     JMP        LAB_00552d5e
    //                               LAB_00552d59                                                 XREF[1]:     00552d52(j)  
    //         00552d59     CMP        EBX,0x2b
    //         00552d5c     JNZ        LAB_00552d87
    //                               LAB_00552d5e                                                 XREF[1]:     00552d57(j)  
    //         00552d5e     MOV        EAX,dword ptr [ESP + local_1c4]
    //         00552d62     MOV        EDX,EAX
    //         00552d64     DEC        EAX
    //         00552d65     TEST       EDX,EDX
    //         00552d67     MOV        dword ptr [ESP + local_1c4],EAX
    //         00552d6b     JNZ        LAB_00552d73
    //         00552d6d     MOV        dword ptr [ESP + local_1c4],EDX
    //         00552d71     JMP        LAB_00552d87
    //                               LAB_00552d73                                                 XREF[2]:     00552d6b(j), 00552dbf(j)  
    //         00552d73     MOV        EBX,dword ptr [ESP + local_1cc]
    //         00552d77     PUSH       EBP
    //         00552d78     INC        EBX
    //         00552d79     MOV        dword ptr [ESP + local_1cc],EBX
    //         00552d7d     CALL       FUN_00553040                                     undefined FUN_00553040()
    //         00552d82     ADD        ESP,0x4
    //         00552d85     MOV        EBX,EAX
    //                               LAB_00552d87                                                 XREF[2]:     00552d5c(j), 00552d71(j)  
    //         00552d87     CMP        dword ptr [___mb_cur_max],0x1                    = 00000001h
    //         00552d8e     JLE        LAB_00552d9d
    //         00552d90     PUSH       0x4
    //         00552d92     PUSH       EBX
    //         00552d93     CALL       __isctype                                        undefined __isctype()
    //         00552d98     ADD        ESP,0x8
    //         00552d9b     JMP        LAB_00552da8
    //                               LAB_00552d9d                                                 XREF[1]:     00552d8e(j)  
    //         00552d9d     MOV        EAX,[__pctype]                                   = 005920da
    //         00552da2     MOV        AL,byte ptr [EAX + EBX*0x2]=>DAT_005920da        = 20h     
    //         00552da5     AND        EAX,0x4
    //                               LAB_00552da8                                                 XREF[1]:     00552d9b(j)  
    //         00552da8     TEST       EAX,EAX
    //         00552daa     JZ         LAB_00552dc1
    //         00552dac     MOV        EAX,dword ptr [ESP + local_1c4]
    //         00552db0     MOV        ECX,EAX
    //         00552db2     DEC        EAX
    //         00552db3     TEST       ECX,ECX
    //         00552db5     MOV        dword ptr [ESP + local_1c4],EAX
    //         00552db9     JZ         LAB_00552dc1
    //         00552dbb     INC        EDI
    //         00552dbc     MOV        byte ptr [ESI]=>local_15a,BL
    //         00552dbe     INC        ESI
    //         00552dbf     JMP        LAB_00552d73
    //                               LAB_00552dc1                                                 XREF[5]:     00552d10(j), 00552d1e(j), 
    //                                                                                                         00552d31(j), 00552daa(j), 
    //                                                                                                         00552db9(j)  
    //         00552dc1     MOV        ECX,dword ptr [ESP + local_1cc]
    //         00552dc5     PUSH       EBP
    //         00552dc6     DEC        ECX
    //         00552dc7     PUSH       EBX
    //         00552dc8     MOV        dword ptr [ESP + local_1cc],ECX
    //         00552dcc     CALL       FUN_00553070                                     undefined FUN_00553070()
    //         00552dd1     ADD        ESP,0x8
    //         00552dd4     TEST       EDI,EDI
    //         00552dd6     JZ         LAB_00552f16
    //         00552ddc     MOV        AL,byte ptr [ESP + local_1c5]
    //         00552de0     TEST       AL,AL
    //         00552de2     JNZ        LAB_00552e48
    //         00552de4     MOV        ECX,dword ptr [ESP + local_1ac]
    //         00552de8     MOV        EAX,dword ptr [ESP + local_1b8]
    //         00552dec     INC        ECX
    //         00552ded     LEA        EDX=>local_160,[ESP + 0x80]
    //         00552df4     MOV        dword ptr [ESP + local_1ac],ECX
    //         00552df8     PUSH       EDX
    //         00552df9     MOVSX      ECX,byte ptr [ESP + local_1c6]
    //         00552dfe     DEC        ECX
    //         00552dff     PUSH       EAX
    //         00552e00     PUSH       ECX
    //         00552e01     MOV        byte ptr [ESI]=>local_15a,0x0
    //         00552e04     CALL       dword ptr [->__fptrap]                           undefined __fptrap()
    //                                                                                  = 00558110
    //         00552e0a     ADD        ESP,0xc
    //         00552e0d     JMP        LAB_00552e48
    //                               switchD_00552558::caseD_6a                                   XREF[3]:     0055254a(j), 00552558(j), 
    //                               switchD_00552558::caseD_6b                                                00552fdc(*)  
    //                               switchD_00552558::caseD_6c
    //                               switchD_00552558::caseD_6d
    //                               switchD_00552558::caseD_71
    //                               switchD_00552558::caseD_72
    //                               switchD_00552558::caseD_74
    //                               switchD_00552558::caseD_76
    //                               switchD_00552558::caseD_77
    //                               switchD_00552558::caseD_79
    //                               switchD_00552558::caseD_7a
    //                               switchD_00552558::caseD_68
    //         00552e0f     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         00552e16     XOR        EDX,EDX
    //         00552e18     MOV        DL,byte ptr [EAX]
    //         00552e1a     CMP        EDX,EBX
    //         00552e1c     JNZ        LAB_00552efd
    //         00552e22     MOV        CL,byte ptr [ESP + local_1bf]
    //         00552e26     MOV        AL,byte ptr [ESP + local_1c5]
    //         00552e2a     DEC        CL
    //         00552e2c     TEST       AL,AL
    //         00552e2e     MOV        byte ptr [ESP + local_1bf],CL
    //         00552e32     JNZ        LAB_00552e48
    //         00552e34     MOV        ECX,dword ptr [ESP + local_18c]
    //         00552e38     MOV        dword ptr [ESP + Stack[0xc]],ECX
    //         00552e3f     JMP        LAB_00552e48
    //                               LAB_00552e41                                                 XREF[1]:     00552b7d(j)  
    //         00552e41     MOV        EBP,dword ptr [ESP + Stack[0x4]]
    //                               LAB_00552e48                                                 XREF[12]:    005527ba(j), 005527d0(j), 
    //                                                                                                         005527e7(j), 005527f3(j), 
    //                                                                                                         00552bab(j), 00552bc6(j), 
    //                                                                                                         00552bd5(j), 00552bdd(j), 
    //                                                                                                         00552de2(j), 00552e0d(j), 
    //                                                                                                         00552e32(j), 00552e3f(j)  
    //         00552e48     MOV        CL,byte ptr [ESP + local_1bf]
    //         00552e4c     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         00552e53     INC        CL
    //         00552e55     INC        EAX
    //         00552e56     MOV        byte ptr [ESP + local_1bf],CL
    //         00552e5a     MOV        dword ptr [ESP + Stack[0x8]],EAX
    //         00552e61     XOR        EDI,EDI
    //         00552e63     MOV        ESI,EAX
    //         00552e65     JMP        LAB_00552ec3
    //                               LAB_00552e67                                                 XREF[1]:     00552383(j)  
    //         00552e67     MOV        EAX,dword ptr [ESP + local_1cc]
    //         00552e6b     PUSH       EBP
    //         00552e6c     INC        EAX
    //         00552e6d     MOV        dword ptr [ESP + local_1cc],EAX
    //         00552e71     CALL       FUN_00553040                                     undefined FUN_00553040()
    //         00552e76     XOR        EDX,EDX
    //         00552e78     ADD        ESP,0x4
    //         00552e7b     MOV        DL,byte ptr [ESI]
    //         00552e7d     MOV        EBX,EAX
    //         00552e7f     INC        ESI
    //         00552e80     CMP        EDX,EBX
    //         00552e82     MOV        dword ptr [ESP + Stack[0x8]],ESI
    //         00552e89     JNZ        LAB_00552efd
    //         00552e8b     MOV        ECX,dword ptr [__pctype]                         = 005920da
    //         00552e91     AND        EAX,0xff
    //         00552e96     TEST       byte ptr [ECX + EAX*0x2 + 0x1]=>DAT_005920db,0
    //         00552e9b     JZ         LAB_00552ec3
    //         00552e9d     MOV        ECX,dword ptr [ESP + local_1cc]
    //         00552ea1     PUSH       EBP
    //         00552ea2     INC        ECX
    //         00552ea3     MOV        dword ptr [ESP + local_1cc],ECX
    //         00552ea7     CALL       FUN_00553040                                     undefined FUN_00553040()
    //         00552eac     XOR        EDX,EDX
    //         00552eae     ADD        ESP,0x4
    //         00552eb1     MOV        DL,byte ptr [ESI]
    //         00552eb3     INC        ESI
    //         00552eb4     CMP        EDX,EAX
    //         00552eb6     MOV        dword ptr [ESP + Stack[0x8]],ESI
    //         00552ebd     JNZ        LAB_00552eea
    //         00552ebf     DEC        dword ptr [ESP + local_1cc]
    //                               LAB_00552ec3                                                 XREF[2]:     00552e65(j), 00552e9b(j)  
    //         00552ec3     CMP        EBX,-0x1
    //         00552ec6     JNZ        LAB_00552ede
    //         00552ec8     CMP        byte ptr [ESI],0x25
    //         00552ecb     JNZ        LAB_00552f16
    //         00552ecd     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         00552ed4     CMP        byte ptr [EAX + 0x1],0x6e
    //         00552ed8     JNZ        LAB_00552f16
    //         00552eda     XOR        EDI,EDI
    //         00552edc     MOV        ESI,EAX
    //                               LAB_00552ede                                                 XREF[1]:     00552ec6(j)  
    //         00552ede     MOV        AL,byte ptr [ESI]
    //         00552ee0     TEST       AL,AL
    //         00552ee2     JNZ        LAB_005522fd
    //         00552ee8     JMP        LAB_00552f16
    //                               LAB_00552eea                                                 XREF[1]:     00552ebd(j)  
    //         00552eea     MOV        ESI,dword ptr [ESP + local_1cc]
    //         00552eee     PUSH       EBP
    //         00552eef     DEC        ESI
    //         00552ef0     PUSH       EAX
    //         00552ef1     MOV        dword ptr [ESP + local_1cc],ESI
    //         00552ef5     CALL       FUN_00553070                                     undefined FUN_00553070()
    //         00552efa     ADD        ESP,0x8
    //                               LAB_00552efd                                                 XREF[3]:     0055253a(j), 00552e1c(j), 
    //                                                                                                         00552e89(j)  
    //         00552efd     MOV        ESI,dword ptr [ESP + local_1cc]
    //         00552f01     PUSH       EBP
    //         00552f02     DEC        ESI
    //         00552f03     PUSH       EBX
    //         00552f04     MOV        dword ptr [ESP + local_1cc],ESI
    //         00552f08     CALL       FUN_00553070                                     undefined FUN_00553070()
    //         00552f0d     ADD        ESP,0x8
    //         00552f10     JMP        LAB_00552f16
    //                               LAB_00552f12                                                 XREF[1]:     005522e3(j)  
    //         00552f12     MOV        EBX,dword ptr [ESP + local_18c]
    //                               LAB_00552f16                                                 XREF[8]:     00552696(j), 005527ae(j), 
    //                                                                                                         00552b71(j), 00552dd6(j), 
    //                                                                                                         00552ecb(j), 00552ed8(j), 
    //                                                                                                         00552ee8(j), 00552f10(j)  
    //         00552f16     MOV        EAX,dword ptr [ESP + local_1ac]
    //         00552f1a     CMP        EBX,-0x1
    //         00552f1d     JNZ        LAB_00552f2e
    //         00552f1f     TEST       EAX,EAX
    //         00552f21     JNZ        LAB_00552f2e
    //         00552f23     MOV        CL,byte ptr [ESP + local_1bf]
    //         00552f27     TEST       CL,CL
    //         00552f29     JNZ        LAB_00552f2e
    //         00552f2b     OR         EAX,0xffffffff
    //                               LAB_00552f2e                                                 XREF[3]:     00552f1d(j), 00552f21(j), 
    //                                                                                                         00552f29(j)  
    //         00552f2e     POP        EDI
    //         00552f2f     POP        ESI
    //         00552f30     POP        EBP
    //         00552f31     POP        EBX
    //         00552f32     ADD        ESP,0x1d0
    //         00552f38     RET
}

// Offset: 0x00552F39
undefined FUN_00552f39() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00552f39()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00552f39
    //         00552f39     NOP
    //         00552f3a     MOV        EDI,EDI
    //                               switchD_00552440::switchdataD_00552f3c                       XREF[1]:     __input:00552440(*)  
}

