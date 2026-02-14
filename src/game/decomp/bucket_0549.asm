// Auto-generated scaffold unit: bucket_0549.asm
#include "../include/common.h"

// Offset: 0x00549020
undefined FUN_00549020() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00549020()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00549020                                                 XREF[2]:     FUN_00548d60:00548e80(c), 
    //                                                                                                         FUN_00548d60:00548eab(c)  
    //         00549020     MOV        EDX,dword ptr [ESP + Stack[0xc]]
    //         00549024     PUSH       ESI
    //         00549025     TEST       EDX,EDX
    //         00549027     JZ         LAB_0054903e
    //         00549029     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054902d     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //                               LAB_00549031                                                 XREF[1]:     0054903c(j)  
    //         00549031     MOV        ESI,dword ptr [ECX]
    //         00549033     ADD        ECX,0x4
    //         00549036     MOV        dword ptr [EAX],ESI
    //         00549038     ADD        EAX,0x4
    //         0054903b     DEC        EDX
    //         0054903c     JNZ        LAB_00549031
    //                               LAB_0054903e                                                 XREF[1]:     00549027(j)  
    //         0054903e     POP        ESI
    //         0054903f     RET
}

// Offset: 0x00549040
undefined FUN_00549040() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00549040()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00549040                                                 XREF[4]:     FUN_00548d60:00548f09(c), 
    //                                                                                                         FUN_00548d60:00548f45(c), 
    //                                                                                                         FUN_00548d60:00548f6d(c), 
    //                                                                                                         FUN_00548d60:00548f88(c)  
    //         00549040     PUSH       ESI
    //         00549041     MOV        EAX,[DAT_00887a80]
    //         00549046     MOV        ESI,dword ptr [ESP + Stack[0xc]]
    //         0054904a     CMP        ESI,0x3
    //         0054904d     JGE        LAB_00549073
    //         0054904f     MOV        EDX,dword ptr [ESP + Stack[0x8]]
    //         00549053     MOV        ECX,ESI
    //         00549055     ADD        dword ptr [EAX + EDX*0x4 + 0x36c20],ESI
    //         0054905c     DEC        ESI
    //         0054905d     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00549061     TEST       ECX,ECX
    //         00549063     JZ         LAB_00549091
    //                               LAB_00549065                                                 XREF[1]:     0054906f(j)  
    //         00549065     MOV        dword ptr [EAX],EDX
    //         00549067     ADD        EAX,0x4
    //         0054906a     MOV        ECX,ESI
    //         0054906c     DEC        ESI
    //         0054906d     TEST       ECX,ECX
    //         0054906f     JNZ        LAB_00549065
    //         00549071     POP        ESI
    //         00549072     RET
    //                               LAB_00549073                                                 XREF[1]:     0054904d(j)  
    //         00549073     SUB        ESI,0x3
    //         00549076     INC        dword ptr [EAX + 0x36c60]
    //         0054907c     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00549080     ADD        EAX,0x4
    //         00549083     MOV        dword ptr [EAX + -0x4],0x10
    //         0054908a     MOV        dword ptr [EAX],ESI
    //         0054908c     ADD        EAX,0x4
    //         0054908f     POP        ESI
    //         00549090     RET
    //                               LAB_00549091                                                 XREF[1]:     00549063(j)  
    //         00549091     POP        ESI
    //         00549092     RET
}

// Offset: 0x005490A0
undefined FUN_005490a0() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005490a0()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005490a0                                                 XREF[3]:     FUN_00548d60:00548f1e(c), 
    //                                                                                                         FUN_00548d60:00548f30(c), 
    //                                                                                                         FUN_00548d60:00548f98(c)  
    //         005490a0     MOV        EDX,dword ptr [ESP + Stack[0x8]]
    //         005490a4     CMP        EDX,0x3
    //         005490a7     JGE        LAB_005490d0
    //         005490a9     MOV        EAX,[DAT_00887a80]
    //         005490ae     MOV        ECX,EDX
    //         005490b0     ADD        dword ptr [EAX + 0x36c20],EDX
    //         005490b6     DEC        EDX
    //         005490b7     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         005490bb     TEST       ECX,ECX
    //         005490bd     JZ         LAB_00549114
    //                               LAB_005490bf                                                 XREF[1]:     005490cd(j)  
    //         005490bf     MOV        dword ptr [EAX],0x0
    //         005490c5     ADD        EAX,0x4
    //         005490c8     MOV        ECX,EDX
    //         005490ca     DEC        EDX
    //         005490cb     TEST       ECX,ECX
    //         005490cd     JNZ        LAB_005490bf
    //         005490cf     RET
    //                               LAB_005490d0                                                 XREF[1]:     005490a7(j)  
    //         005490d0     MOV        EAX,[DAT_00887a80]
    //         005490d5     CMP        EDX,0xa
    //         005490d8     JG         LAB_005490f7
    //         005490da     SUB        EDX,0x3
    //         005490dd     INC        dword ptr [EAX + 0x36c64]
    //         005490e3     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         005490e7     ADD        EAX,0x4
    //         005490ea     MOV        dword ptr [EAX + -0x4],0x11
    //         005490f1     MOV        dword ptr [EAX],EDX
    //         005490f3     ADD        EAX,0x4
    //         005490f6     RET
    //                               LAB_005490f7                                                 XREF[1]:     005490d8(j)  
    //         005490f7     SUB        EDX,0xb
    //         005490fa     INC        dword ptr [EAX + 0x36c68]
    //         00549100     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00549104     ADD        EAX,0x4
    //         00549107     MOV        dword ptr [EAX + -0x4],0x12
    //         0054910e     MOV        dword ptr [EAX],EDX
    //         00549110     ADD        EAX,0x4
    //         00549113     RET
    //                               LAB_00549114                                                 XREF[1]:     005490bd(j)  
    //         00549114     RET
}

// Offset: 0x00549120
undefined FUN_00549120() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00549120()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00549120                                                 XREF[6]:     FUN_005480b0:0054812d(c), 
    //                                                                                                         FUN_005480b0:005481be(c), 
    //                                                                                                         FUN_005480b0:0054825b(c), 
    //                                                                                                         FUN_005480b0:00548295(c), 
    //                                                                                                         FUN_005480b0:005482d7(c), 
    //                                                                                                         FUN_005480b0:00548340(c)  
    //         00549120     PUSH       0x2
    //         00549122     PUSH       0x2
    //         00549124     CALL       FUN_00547d80                                     undefined FUN_00547d80()
    //         00549129     ADD        ESP,0x8
    //         0054912c     TEST       EAX,EAX
    //         0054912e     JZ         LAB_00549136
    //         00549130     MOV        EAX,0x1
    //         00549135     RET
    //                               LAB_00549136                                                 XREF[1]:     0054912e(j)  
    //         00549136     CALL       FUN_00549150                                     undefined FUN_00549150()
    //         0054913b     CMP        EAX,0x1
    //         0054913e     SBB        EAX,EAX
    //         00549140     INC        EAX
    //         00549141     RET
}

// Offset: 0x00549150
undefined FUN_00549150() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00549150()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00549150                                                 XREF[1]:     FUN_00549120:00549136(c)  
    //         00549150     PUSH       ESI
    //         00549151     MOV        EAX,[DAT_00887a80]
    //         00549156     PUSH       EDI
    //         00549157     PUSH       0x5
    //         00549159     MOV        EAX,dword ptr [EAX + 0x38108]
    //         0054915f     SUB        EAX,0x101
    //         00549164     PUSH       EAX
    //         00549165     CALL       FUN_00547d80                                     undefined FUN_00547d80()
    //         0054916a     ADD        ESP,0x8
    //         0054916d     TEST       EAX,EAX
    //         0054916f     JZ         LAB_00549179
    //         00549171     MOV        EAX,0x1
    //         00549176     POP        EDI
    //         00549177     POP        ESI
    //         00549178     RET
    //                               LAB_00549179                                                 XREF[1]:     0054916f(j)  
    //         00549179     PUSH       0x5
    //         0054917b     MOV        EAX,[DAT_00887a80]
    //         00549180     MOV        EAX,dword ptr [EAX + 0x3810c]
    //         00549186     DEC        EAX
    //         00549187     PUSH       EAX
    //         00549188     CALL       FUN_00547d80                                     undefined FUN_00547d80()
    //         0054918d     ADD        ESP,0x8
    //         00549190     TEST       EAX,EAX
    //         00549192     JZ         LAB_0054919c
    //         00549194     MOV        EAX,0x1
    //         00549199     POP        EDI
    //         0054919a     POP        ESI
    //         0054919b     RET
    //                               LAB_0054919c                                                 XREF[1]:     00549192(j)  
    //         0054919c     MOV        ESI,0x12
    //         005491a1     XOR        EAX,EAX
    //                               LAB_005491a3                                                 XREF[1]:     005491bb(j)  
    //         005491a3     XOR        EDX,EDX
    //         005491a5     MOV        ECX,dword ptr [DAT_00887a80]
    //         005491ab     MOV        DL,byte ptr [ESI + 0x58ef30]=>DAT_0058ef42       = 01h
    //                                                                                  = 0Fh
    //         005491b1     CMP        dword ptr [ECX + EDX*0x4 + 0x3716c],EAX
    //         005491b8     JNZ        LAB_005491bd
    //         005491ba     DEC        ESI
    //         005491bb     JNS        LAB_005491a3
    //                               LAB_005491bd                                                 XREF[1]:     005491b8(j)  
    //         005491bd     INC        ESI
    //         005491be     CMP        ESI,0x4
    //         005491c1     JG         LAB_005491c8
    //         005491c3     MOV        ESI,0x4
    //                               LAB_005491c8                                                 XREF[1]:     005491c1(j)  
    //         005491c8     PUSH       0x4
    //         005491ca     LEA        EAX,[ESI + -0x4]
    //         005491cd     PUSH       EAX
    //         005491ce     CALL       FUN_00547d80                                     undefined FUN_00547d80()
    //         005491d3     ADD        ESP,0x8
    //         005491d6     TEST       EAX,EAX
    //         005491d8     JZ         LAB_005491e2
    //         005491da     MOV        EAX,0x1
    //         005491df     POP        EDI
    //         005491e0     POP        ESI
    //         005491e1     RET
    //                               LAB_005491e2                                                 XREF[1]:     005491d8(j)  
    //         005491e2     XOR        EDI,EDI
    //         005491e4     TEST       ESI,ESI
    //         005491e6     JLE        LAB_00549210
    //                               LAB_005491e8                                                 XREF[1]:     0054920e(j)  
    //         005491e8     PUSH       0x3
    //         005491ea     XOR        ECX,ECX
    //         005491ec     MOV        CL,byte ptr [EDI + DAT_0058ef30]                 = 10h
    //                                                                                  = 11h
    //         005491f2     MOV        EAX,[DAT_00887a80]
    //         005491f7     MOV        EDX,dword ptr [EAX + ECX*0x4 + 0x3716c]
    //         005491fe     PUSH       EDX
    //         005491ff     CALL       FUN_00547d80                                     undefined FUN_00547d80()
    //         00549204     ADD        ESP,0x8
    //         00549207     TEST       EAX,EAX
    //         00549209     JNZ        LAB_0054927c
    //         0054920b     INC        EDI
    //         0054920c     CMP        EDI,ESI
    //         0054920e     JL         LAB_005491e8
    //                               LAB_00549210                                                 XREF[1]:     005491e6(j)  
    //         00549210     MOV        ESI,dword ptr [DAT_00887a80]
    //         00549216     ADD        ESI,0x37c04
    //                               LAB_0054921c                                                 XREF[4]:     00549272(j), 0054929d(j), 
    //                                                                                                         005492ae(j), 005492c8(j)  
    //         0054921c     MOV        EAX,[DAT_00887a80]
    //         00549221     CMP        dword ptr [EAX + 0x38104],ESI
    //         00549227     JBE        LAB_005492de
    //         0054922d     MOV        EDI,dword ptr [ESI]
    //         0054922f     ADD        ESI,0x4
    //         00549232     LEA        EAX,[EDI*0x4 + 0x0]
    //         00549239     ADD        EAX,dword ptr [DAT_00887a80]
    //         0054923f     MOV        ECX,dword ptr [EAX + 0x3716c]
    //         00549245     MOV        EDX,dword ptr [EAX + 0x376b8]
    //         0054924b     PUSH       ECX
    //         0054924c     PUSH       EDX
    //         0054924d     CALL       FUN_00547d80                                     undefined FUN_00547d80()
    //         00549252     ADD        ESP,0x8
    //         00549255     TEST       EAX,EAX
    //         00549257     JNZ        LAB_005492d6
    //         00549259     CMP        EDI,0x10
    //         0054925c     JNZ        LAB_00549284
    //         0054925e     MOV        ECX,dword ptr [ESI]
    //         00549260     MOV        EAX,ESI
    //         00549262     ADD        ESI,0x4
    //         00549265     PUSH       0x2
    //         00549267     PUSH       ECX
    //         00549268     CALL       FUN_00547d80                                     undefined FUN_00547d80()
    //         0054926d     ADD        ESP,0x8
    //         00549270     TEST       EAX,EAX
    //         00549272     JZ         LAB_0054921c
    //         00549274     MOV        EAX,0x1
    //         00549279     POP        EDI
    //         0054927a     POP        ESI
    //         0054927b     RET
    //                               LAB_0054927c                                                 XREF[1]:     00549209(j)  
    //         0054927c     MOV        EAX,0x1
    //         00549281     POP        EDI
    //         00549282     POP        ESI
    //         00549283     RET
    //                               LAB_00549284                                                 XREF[1]:     0054925c(j)  
    //         00549284     CMP        EDI,0x11
    //         00549287     JNZ        LAB_005492ab
    //         00549289     MOV        ECX,dword ptr [ESI]
    //         0054928b     MOV        EAX,ESI
    //         0054928d     ADD        ESI,0x4
    //         00549290     PUSH       0x3
    //         00549292     PUSH       ECX
    //         00549293     CALL       FUN_00547d80                                     undefined FUN_00547d80()
    //         00549298     ADD        ESP,0x8
    //         0054929b     TEST       EAX,EAX
    //         0054929d     JZ         LAB_0054921c
    //         005492a3     MOV        EAX,0x1
    //         005492a8     POP        EDI
    //         005492a9     POP        ESI
    //         005492aa     RET
    //                               LAB_005492ab                                                 XREF[1]:     00549287(j)  
    //         005492ab     CMP        EDI,0x12
    //         005492ae     JNZ        LAB_0054921c
    //         005492b4     MOV        ECX,dword ptr [ESI]
    //         005492b6     MOV        EAX,ESI
    //         005492b8     ADD        ESI,0x4
    //         005492bb     PUSH       0x7
    //         005492bd     PUSH       ECX
    //         005492be     CALL       FUN_00547d80                                     undefined FUN_00547d80()
    //         005492c3     ADD        ESP,0x8
    //         005492c6     TEST       EAX,EAX
    //         005492c8     JZ         LAB_0054921c
    //         005492ce     MOV        EAX,0x1
    //         005492d3     POP        EDI
    //         005492d4     POP        ESI
    //         005492d5     RET
    //                               LAB_005492d6                                                 XREF[1]:     00549257(j)  
    //         005492d6     MOV        EAX,0x1
    //         005492db     POP        EDI
    //         005492dc     POP        ESI
    //         005492dd     RET
    //                               LAB_005492de                                                 XREF[1]:     00549227(j)  
    //         005492de     XOR        EAX,EAX
    //         005492e0     POP        EDI
    //         005492e1     POP        ESI
    //         005492e2     RET
}

// Offset: 0x005492F0
undefined FUN_005492f0() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005492f0()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005492f0                                                 XREF[2]:     FUN_005480b0:0054821a(c), 
    //                                                                                                         FUN_005480b0:00548330(c)  
    //         005492f0     PUSH       ESI
    //         005492f1     PUSH       EDI
    //         005492f2     PUSH       0x2
    //         005492f4     PUSH       0x0
    //         005492f6     CALL       FUN_00547d80                                     undefined FUN_00547d80()
    //         005492fb     ADD        ESP,0x8
    //         005492fe     TEST       EAX,EAX
    //         00549300     JZ         LAB_0054930a
    //         00549302     MOV        EAX,0x1
    //         00549307     POP        EDI
    //         00549308     POP        ESI
    //         00549309     RET
    //                               LAB_0054930a                                                 XREF[1]:     00549300(j)  
    //         0054930a     CALL       FUN_00547d50                                     undefined FUN_00547d50()
    //         0054930f     TEST       EAX,EAX
    //         00549311     JZ         LAB_0054931b
    //         00549313     MOV        EAX,0x1
    //         00549318     POP        EDI
    //         00549319     POP        ESI
    //         0054931a     RET
    //                               LAB_0054931b                                                 XREF[2]:     00549311(j), 00549330(j)  
    //         0054931b     DEC        dword ptr [DAT_00887a88]
    //         00549321     JNS        LAB_0054933a
    //         00549323     INC        dword ptr [DAT_00887a88]
    //         00549329     CALL       FUN_00547cf0                                     undefined FUN_00547cf0()
    //         0054932e     TEST       EAX,EAX
    //         00549330     JZ         LAB_0054931b
    //         00549332     MOV        EAX,0x1
    //         00549337     POP        EDI
    //         00549338     POP        ESI
    //         00549339     RET
    //                               LAB_0054933a                                                 XREF[1]:     00549321(j)  
    //         0054933a     MOV        EAX,[DAT_00887a80]
    //         0054933f     MOV        EDX,dword ptr [DAT_00887a90]
    //         00549345     MOV        CL,byte ptr [EAX + 0x3671c]
    //         0054934b     MOV        byte ptr [EDX],CL
    //         0054934d     INC        dword ptr [DAT_00887a90]
    //                               LAB_00549353                                                 XREF[1]:     00549368(j)  
    //         00549353     DEC        dword ptr [DAT_00887a88]
    //         00549359     JNS        LAB_00549372
    //         0054935b     INC        dword ptr [DAT_00887a88]
    //         00549361     CALL       FUN_00547cf0                                     undefined FUN_00547cf0()
    //         00549366     TEST       EAX,EAX
    //         00549368     JZ         LAB_00549353
    //         0054936a     MOV        EAX,0x1
    //         0054936f     POP        EDI
    //         00549370     POP        ESI
    //         00549371     RET
    //                               LAB_00549372                                                 XREF[1]:     00549359(j)  
    //         00549372     MOV        EAX,[DAT_00887a80]
    //         00549377     MOV        EDX,dword ptr [DAT_00887a90]
    //         0054937d     MOV        ECX,dword ptr [EAX + 0x3671c]
    //         00549383     MOV        byte ptr [EDX],CH
    //         00549385     INC        dword ptr [DAT_00887a90]
    //                               LAB_0054938b                                                 XREF[1]:     005493a0(j)  
    //         0054938b     DEC        dword ptr [DAT_00887a88]
    //         00549391     JNS        LAB_005493aa
    //         00549393     INC        dword ptr [DAT_00887a88]
    //         00549399     CALL       FUN_00547cf0                                     undefined FUN_00547cf0()
    //         0054939e     TEST       EAX,EAX
    //         005493a0     JZ         LAB_0054938b
    //         005493a2     MOV        EAX,0x1
    //         005493a7     POP        EDI
    //         005493a8     POP        ESI
    //         005493a9     RET
    //                               LAB_005493aa                                                 XREF[1]:     00549391(j)  
    //         005493aa     MOV        EAX,[DAT_00887a80]
    //         005493af     MOV        ECX,dword ptr [EAX + 0x3671c]
    //         005493b5     MOV        EAX,[DAT_00887a90]
    //         005493ba     NOT        CL
    //         005493bc     MOV        byte ptr [EAX],CL
    //         005493be     INC        dword ptr [DAT_00887a90]
    //                               LAB_005493c4                                                 XREF[1]:     005493d9(j)  
    //         005493c4     DEC        dword ptr [DAT_00887a88]
    //         005493ca     JNS        LAB_005493e3
    //         005493cc     INC        dword ptr [DAT_00887a88]
    //         005493d2     CALL       FUN_00547cf0                                     undefined FUN_00547cf0()
    //         005493d7     TEST       EAX,EAX
    //         005493d9     JZ         LAB_005493c4
    //         005493db     MOV        EAX,0x1
    //         005493e0     POP        EDI
    //         005493e1     POP        ESI
    //         005493e2     RET
    //                               LAB_005493e3                                                 XREF[1]:     005493ca(j)  
    //         005493e3     MOV        EAX,[DAT_00887a80]
    //         005493e8     MOV        ECX,dword ptr [EAX + 0x3671c]
    //         005493ee     MOV        EAX,[DAT_00887a90]
    //         005493f3     SAR        ECX,0x8
    //         005493f6     NOT        CL
    //         005493f8     MOV        byte ptr [EAX],CL
    //         005493fa     MOV        EDX,dword ptr [DAT_00887a80]
    //         00549400     INC        dword ptr [DAT_00887a90]
    //         00549406     MOV        ESI,dword ptr [EDX + 0x36714]
    //         0054940c     MOV        EDI,dword ptr [EDX + 0x3671c]
    //                               LAB_00549412                                                 XREF[1]:     00549453(j)  
    //         00549412     TEST       EDI,EDI
    //         00549414     JLE        LAB_00549455
    //                               LAB_00549416                                                 XREF[1]:     0054942b(j)  
    //         00549416     DEC        dword ptr [DAT_00887a88]
    //         0054941c     JNS        LAB_00549435
    //         0054941e     INC        dword ptr [DAT_00887a88]
    //         00549424     CALL       FUN_00547cf0                                     undefined FUN_00547cf0()
    //         00549429     TEST       EAX,EAX
    //         0054942b     JZ         LAB_00549416
    //         0054942d     MOV        EAX,0x1
    //         00549432     POP        EDI
    //         00549433     POP        ESI
    //         00549434     RET
    //                               LAB_00549435                                                 XREF[1]:     0054941c(j)  
    //         00549435     MOV        EAX,[DAT_00887a94]
    //         0054943a     MOV        EDX,dword ptr [DAT_00887a90]
    //         00549440     MOV        CL,byte ptr [EAX + ESI*0x1]
    //         00549443     INC        ESI
    //         00549444     DEC        EDI
    //         00549445     AND        ESI,0x7fff
    //         0054944b     MOV        byte ptr [EDX],CL
    //         0054944d     INC        dword ptr [DAT_00887a90]
    //         00549453     JMP        LAB_00549412
    //                               LAB_00549455                                                 XREF[1]:     00549414(j)  
    //         00549455     XOR        EAX,EAX
    //         00549457     POP        EDI
    //         00549458     POP        ESI
    //         00549459     RET
}

// Offset: 0x00549460
undefined FUN_00549460() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00549460()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00549460                                                 XREF[1]:     FUN_00547b30:00547bbf(c)  
    //         00549460     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         00549464     MOV        EAX,[DAT_00887a80]
    //         00549469     SUB        ECX,dword ptr [EAX + 0x38120]
    //         0054946f     AND        ECX,0x7fff
    //         00549475     ADD        dword ptr [EAX + 0x38124],ECX
    //         0054947b     MOV        EAX,[DAT_00887a80]
    //         00549480     MOV        EAX,dword ptr [EAX + 0x38120]
    //         00549486     ADD        EAX,ECX
    //         00549488     MOV        ECX,dword ptr [DAT_00887a80]
    //         0054948e     ADD        EAX,0xefd
    //         00549493     MOV        dword ptr [ECX + 0x38128],EAX
    //         00549499     JMP        FUN_005494a0                                     undefined FUN_005494a0()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x005494A0
undefined FUN_005494a0() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005494a0()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005494a0                                                 XREF[2]:     FUN_00549460:00549499(c), 
    //                                                                                                         FUN_0054a360:0054a36f(c)  
    //         005494a0     MOV        EAX,[DAT_00887a80]
    //         005494a5     CMP        dword ptr [EAX + 0x3813c],0x0
    //         005494ac     JZ         LAB_005494c1
    //         005494ae     CMP        dword ptr [DAT_00886c60],0x4
    //         005494b5     JGE        LAB_005494bc
    //         005494b7     JMP        FUN_00549f40                                     undefined FUN_00549f40()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
    //                               LAB_005494bc                                                 XREF[1]:     005494b5(j)  
    //         005494bc     JMP        FUN_00549b70                                     undefined FUN_00549b70()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
    //                               LAB_005494c1                                                 XREF[1]:     005494ac(j)  
    //         005494c1     JMP        LAB_005494d0
    //         005494c6     align      align(10)
    //                               LAB_005494d0                                                 XREF[1]:     005494c1(j)  
    //         005494d0     PUSH       EBX
    //         005494d1     PUSH       ESI
    //         005494d2     PUSH       EDI
    //         005494d3     XOR        EBX,EBX
    //         005494d5     PUSH       EBP
    //         005494d6     MOV        EBP,0x2
    //                               LAB_005494db                                                 XREF[10]:    00549586(j), 00549593(j), 
    //                                                                                                         0054962c(j), 00549639(j), 
    //                                                                                                         005497e0(j), 005497ed(j), 
    //                                                                                                         00549894(j), 005498a1(j), 
    //                                                                                                         0054993a(j), 00549947(j)  
    //         005494db     MOV        EAX,[DAT_00887a80]
    //         005494e0     CMP        dword ptr [EAX + 0x38124],EBX
    //         005494e6     JZ         LAB_00549957
    //         005494ec     LEA        ESI,[EAX + 0x38120]
    //         005494f2     MOV        EDX,dword ptr [ESI]
    //         005494f4     CMP        dword ptr [EAX + 0x38128],EDX
    //         005494fa     JBE        LAB_00549957
    //         00549500     MOV        EAX,EDX
    //         00549502     MOV        ECX,dword ptr [DAT_00886cf0]
    //         00549508     AND        EAX,0x7fff
    //         0054950d     CMP        word ptr [ECX + EAX*0x2],0xffff
    //         00549513     JNZ        LAB_005495a3
    //         00549519     MOV        EAX,[DAT_00887a94]
    //         0054951e     MOV        CL,byte ptr [EAX + EDX*0x1]
    //         00549521     MOV        EDX,dword ptr [DAT_00887a80]
    //         00549527     MOV        EAX,dword ptr [EDX + 0x36104]
    //         0054952d     MOV        byte ptr [EAX],CL
    //         0054952f     MOV        EDX,dword ptr [DAT_00887a80]
    //         00549535     INC        dword ptr [EDX + 0x38120]
    //         0054953b     MOV        EDX,dword ptr [DAT_00887a80]
    //         00549541     INC        dword ptr [EDX + 0x36104]
    //         00549547     MOV        EDX,dword ptr [DAT_00887a80]
    //         0054954d     DEC        dword ptr [EDX + 0x38124]
    //         00549553     MOV        EDX,dword ptr [DAT_00887a80]
    //         00549559     INC        dword ptr [EDX + 0x3671c]
    //         0054955f     MOV        EDX,dword ptr [DAT_00887a80]
    //         00549565     MOV        EAX,dword ptr [EDX + 0x3670c]
    //         0054956b     SHL        dword ptr [EAX],0x1
    //         0054956e     MOV        EDX,dword ptr [DAT_00887a80]
    //         00549574     DEC        dword ptr [EDX + 0x36710]
    //         0054957a     MOV        EDX,dword ptr [DAT_00887a80]
    //         00549580     CMP        dword ptr [EDX + 0x36710],EBX
    //         00549586     JNZ        LAB_005494db
    //         0054958c     CALL       FUN_00549b20                                     undefined FUN_00549b20()
    //         00549591     TEST       EAX,EAX
    //         00549593     JZ         LAB_005494db
    //         00549599     MOV        EAX,0x1
    //         0054959e     POP        EBP
    //         0054959f     POP        EDI
    //         005495a0     POP        ESI
    //         005495a1     POP        EBX
    //         005495a2     RET
    //                               LAB_005495a3                                                 XREF[1]:     00549513(j)  
    //         005495a3     MOV        dword ptr [DAT_00887b1c],EBP
    //         005495a9     MOV        EAX,dword ptr [ESI]
    //         005495ab     PUSH       EAX
    //         005495ac     CALL       FUN_00549970                                     undefined FUN_00549970()
    //         005495b1     ADD        ESP,0x4
    //         005495b4     CMP        dword ptr [DAT_00887b1c],EBP
    //         005495ba     JNZ        LAB_00549649
    //         005495c0     MOV        EAX,[DAT_00887a80]
    //         005495c5     MOV        ECX,dword ptr [DAT_00887a94]
    //         005495cb     MOV        EDX,dword ptr [EAX + 0x38120]
    //         005495d1     MOV        CL,byte ptr [EDX + ECX*0x1]
    //         005495d4     MOV        EDX,dword ptr [EAX + 0x36104]
    //         005495da     MOV        byte ptr [EDX],CL
    //         005495dc     MOV        EAX,[DAT_00887a80]
    //         005495e1     INC        dword ptr [EAX + 0x38120]
    //         005495e7     MOV        EAX,[DAT_00887a80]
    //         005495ec     INC        dword ptr [EAX + 0x36104]
    //         005495f2     MOV        EAX,[DAT_00887a80]
    //         005495f7     DEC        dword ptr [EAX + 0x38124]
    //         005495fd     MOV        EAX,[DAT_00887a80]
    //         00549602     INC        dword ptr [EAX + 0x3671c]
    //         00549608     MOV        EAX,[DAT_00887a80]
    //         0054960d     MOV        ECX,dword ptr [EAX + 0x3670c]
    //         00549613     SHL        dword ptr [ECX],0x1
    //         00549616     MOV        EAX,[DAT_00887a80]
    //         0054961b     DEC        dword ptr [EAX + 0x36710]
    //         00549621     MOV        EAX,[DAT_00887a80]
    //         00549626     CMP        dword ptr [EAX + 0x36710],EBX
    //         0054962c     JNZ        LAB_005494db
    //         00549632     CALL       FUN_00549b20                                     undefined FUN_00549b20()
    //         00549637     TEST       EAX,EAX
    //         00549639     JZ         LAB_005494db
    //         0054963f     MOV        EAX,0x1
    //         00549644     POP        EBP
    //         00549645     POP        EDI
    //         00549646     POP        ESI
    //         00549647     POP        EBX
    //         00549648     RET
    //                               LAB_00549649                                                 XREF[1]:     005495ba(j)  
    //         00549649     MOV        ESI,dword ptr [DAT_00887b1c]
    //         0054964f     MOV        EDI,dword ptr [DAT_00887fa8]
    //                               LAB_00549655                                                 XREF[2]:     0054973a(j), 00549747(j)  
    //         00549655     CMP        ESI,0x80
    //         0054965b     JGE        LAB_00549757
    //         00549661     MOV        EAX,[DAT_00887a80]
    //         00549666     MOV        EDX,dword ptr [DAT_00886cf0]
    //         0054966c     MOV        EAX,dword ptr [EAX + 0x38120]
    //         00549672     INC        EAX
    //         00549673     MOV        ECX,EAX
    //         00549675     AND        ECX,0x7fff
    //         0054967b     CMP        word ptr [EDX + ECX*0x2],0xffff
    //         00549681     JZ         LAB_00549757
    //         00549687     PUSH       EAX
    //         00549688     CALL       FUN_00549970                                     undefined FUN_00549970()
    //         0054968d     ADD        ESP,0x4
    //         00549690     MOV        EAX,[DAT_00887a80]
    //         00549695     MOV        EAX,dword ptr [EAX + 0x38124]
    //         0054969b     DEC        EAX
    //         0054969c     CMP        dword ptr [DAT_00887b1c],EAX
    //         005496a2     JLE        LAB_005496a9
    //         005496a4     MOV        [DAT_00887b1c],EAX
    //                               LAB_005496a9                                                 XREF[1]:     005496a2(j)  
    //         005496a9     CMP        dword ptr [DAT_00887b1c],ESI
    //         005496af     JLE        LAB_00549757
    //         005496b5     MOV        EAX,[DAT_00887a80]
    //         005496ba     MOV        ECX,dword ptr [DAT_00887a94]
    //         005496c0     MOV        ESI,dword ptr [DAT_00887b1c]
    //         005496c6     MOV        EDI,dword ptr [DAT_00887fa8]
    //         005496cc     MOV        EDX,dword ptr [EAX + 0x38120]
    //         005496d2     MOV        AL,byte ptr [EDX + ECX*0x1]
    //         005496d5     MOV        EDX,dword ptr [DAT_00887a80]
    //         005496db     MOV        ECX,dword ptr [EDX + 0x36104]
    //         005496e1     MOV        byte ptr [ECX],AL
    //         005496e3     MOV        EDX,dword ptr [DAT_00887a80]
    //         005496e9     INC        dword ptr [EDX + 0x38120]
    //         005496ef     MOV        EDX,dword ptr [DAT_00887a80]
    //         005496f5     INC        dword ptr [EDX + 0x36104]
    //         005496fb     MOV        EDX,dword ptr [DAT_00887a80]
    //         00549701     DEC        dword ptr [EDX + 0x38124]
    //         00549707     MOV        EDX,dword ptr [DAT_00887a80]
    //         0054970d     INC        dword ptr [EDX + 0x3671c]
    //         00549713     MOV        EDX,dword ptr [DAT_00887a80]
    //         00549719     MOV        EAX,dword ptr [EDX + 0x3670c]
    //         0054971f     SHL        dword ptr [EAX],0x1
    //         00549722     MOV        EDX,dword ptr [DAT_00887a80]
    //         00549728     DEC        dword ptr [EDX + 0x36710]
    //         0054972e     MOV        EDX,dword ptr [DAT_00887a80]
    //         00549734     CMP        dword ptr [EDX + 0x36710],EBX
    //         0054973a     JNZ        LAB_00549655
    //         00549740     CALL       FUN_00549b20                                     undefined FUN_00549b20()
    //         00549745     TEST       EAX,EAX
    //         00549747     JZ         LAB_00549655
    //         0054974d     MOV        EAX,0x1
    //         00549752     POP        EBP
    //         00549753     POP        EDI
    //         00549754     POP        ESI
    //         00549755     POP        EBX
    //         00549756     RET
    //                               LAB_00549757                                                 XREF[3]:     0054965b(j), 00549681(j), 
    //                                                                                                         005496af(j)  
    //         00549757     MOV        EAX,[DAT_00887a80]
    //         0054975c     MOV        EAX,dword ptr [EAX + 0x38124]
    //         00549762     CMP        ESI,EAX
    //         00549764     JLE        LAB_005497fd
    //         0054976a     CMP        EAX,EBP
    //         0054976c     MOV        ESI,EAX
    //         0054976e     JG         LAB_005497fd
    //         00549774     MOV        EAX,[DAT_00887a80]
    //         00549779     MOV        ECX,dword ptr [DAT_00887a94]
    //         0054977f     MOV        EDX,dword ptr [EAX + 0x38120]
    //         00549785     MOV        CL,byte ptr [EDX + ECX*0x1]
    //         00549788     MOV        EDX,dword ptr [EAX + 0x36104]
    //         0054978e     MOV        byte ptr [EDX],CL
    //         00549790     MOV        EAX,[DAT_00887a80]
    //         00549795     INC        dword ptr [EAX + 0x38120]
    //         0054979b     MOV        EAX,[DAT_00887a80]
    //         005497a0     INC        dword ptr [EAX + 0x36104]
    //         005497a6     MOV        EAX,[DAT_00887a80]
    //         005497ab     DEC        dword ptr [EAX + 0x38124]
    //         005497b1     MOV        EAX,[DAT_00887a80]
    //         005497b6     INC        dword ptr [EAX + 0x3671c]
    //         005497bc     MOV        EAX,[DAT_00887a80]
    //         005497c1     MOV        ECX,dword ptr [EAX + 0x3670c]
    //         005497c7     SHL        dword ptr [ECX],0x1
    //         005497ca     MOV        EAX,[DAT_00887a80]
    //         005497cf     DEC        dword ptr [EAX + 0x36710]
    //         005497d5     MOV        EAX,[DAT_00887a80]
    //         005497da     CMP        dword ptr [EAX + 0x36710],EBX
    //         005497e0     JNZ        LAB_005494db
    //         005497e6     CALL       FUN_00549b20                                     undefined FUN_00549b20()
    //         005497eb     TEST       EAX,EAX
    //         005497ed     JZ         LAB_005494db
    //         005497f3     MOV        EAX,0x1
    //         005497f8     POP        EBP
    //         005497f9     POP        EDI
    //         005497fa     POP        ESI
    //         005497fb     POP        EBX
    //         005497fc     RET
    //                               LAB_005497fd                                                 XREF[2]:     00549764(j), 0054976e(j)  
    //         005497fd     MOV        EAX,[DAT_00887a80]
    //         00549802     MOV        EDX,dword ptr [EAX + 0x38120]
    //         00549808     MOV        ECX,EDX
    //         0054980a     SUB        ECX,EDI
    //         0054980c     AND        ECX,0x7fff
    //         00549812     CMP        ESI,0x3
    //         00549815     JNZ        LAB_005498b1
    //         0054981b     CMP        ECX,0x4000
    //         00549821     JL         LAB_005498b1
    //         00549827     MOV        EAX,[DAT_00887a94]
    //         0054982c     MOV        CL,byte ptr [EAX + EDX*0x1]
    //         0054982f     MOV        EDX,dword ptr [DAT_00887a80]
    //         00549835     MOV        EAX,dword ptr [EDX + 0x36104]
    //         0054983b     MOV        byte ptr [EAX],CL
    //         0054983d     MOV        EDX,dword ptr [DAT_00887a80]
    //         00549843     INC        dword ptr [EDX + 0x38120]
    //         00549849     MOV        EDX,dword ptr [DAT_00887a80]
    //         0054984f     INC        dword ptr [EDX + 0x36104]
    //         00549855     MOV        EDX,dword ptr [DAT_00887a80]
    //         0054985b     DEC        dword ptr [EDX + 0x38124]
    //         00549861     MOV        EDX,dword ptr [DAT_00887a80]
    //         00549867     INC        dword ptr [EDX + 0x3671c]
    //         0054986d     MOV        EDX,dword ptr [DAT_00887a80]
    //         00549873     MOV        EAX,dword ptr [EDX + 0x3670c]
    //         00549879     SHL        dword ptr [EAX],0x1
    //         0054987c     MOV        EDX,dword ptr [DAT_00887a80]
    //         00549882     DEC        dword ptr [EDX + 0x36710]
    //         00549888     MOV        EDX,dword ptr [DAT_00887a80]
    //         0054988e     CMP        dword ptr [EDX + 0x36710],EBX
    //         00549894     JNZ        LAB_005494db
    //         0054989a     CALL       FUN_00549b20                                     undefined FUN_00549b20()
    //         0054989f     TEST       EAX,EAX
    //         005498a1     JZ         LAB_005494db
    //         005498a7     MOV        EAX,0x1
    //         005498ac     POP        EBP
    //         005498ad     POP        EDI
    //         005498ae     POP        ESI
    //         005498af     POP        EBX
    //         005498b0     RET
    //                               LAB_005498b1                                                 XREF[2]:     00549815(j), 00549821(j)  
    //         005498b1     LEA        EAX,[ESI + -0x3]
    //         005498b4     MOV        EDX,dword ptr [DAT_00887a80]
    //         005498ba     MOV        EDI,dword ptr [EDX + 0x36104]
    //         005498c0     MOV        byte ptr [EDI],AL
    //         005498c2     MOV        EDX,dword ptr [DAT_00887a80]
    //         005498c8     INC        dword ptr [EDX + 0x36104]
    //         005498ce     MOV        EDX,dword ptr [DAT_00887a80]
    //         005498d4     MOV        EDI,dword ptr [EDX + 0x36104]
    //         005498da     MOV        word ptr [EDI],CX
    //         005498dd     MOV        EDX,dword ptr [DAT_00887a80]
    //         005498e3     ADD        dword ptr [EDX + 0x36104],EBP
    //         005498e9     MOV        EDX,dword ptr [DAT_00887a80]
    //         005498ef     ADD        dword ptr [EDX + 0x38120],ESI
    //         005498f5     MOV        EDX,dword ptr [DAT_00887a80]
    //         005498fb     SUB        dword ptr [EDX + 0x38124],ESI
    //         00549901     MOV        EDX,dword ptr [DAT_00887a80]
    //         00549907     ADD        dword ptr [EDX + 0x3671c],ESI
    //         0054990d     MOV        EDX,dword ptr [DAT_00887a80]
    //         00549913     MOV        EAX,dword ptr [EDX + 0x3670c]
    //         00549919     MOV        ECX,dword ptr [EAX]
    //         0054991b     ADD        ECX,ECX
    //         0054991d     OR         ECX,0x1
    //         00549920     MOV        dword ptr [EAX],ECX
    //         00549922     MOV        EDX,dword ptr [DAT_00887a80]
    //         00549928     DEC        dword ptr [EDX + 0x36710]
    //         0054992e     MOV        EDX,dword ptr [DAT_00887a80]
    //         00549934     CMP        dword ptr [EDX + 0x36710],EBX
    //         0054993a     JNZ        LAB_005494db
    //         00549940     CALL       FUN_00549b20                                     undefined FUN_00549b20()
    //         00549945     TEST       EAX,EAX
    //         00549947     JZ         LAB_005494db
    //         0054994d     MOV        EAX,0x1
    //         00549952     POP        EBP
    //         00549953     POP        EDI
    //         00549954     POP        ESI
    //         00549955     POP        EBX
    //         00549956     RET
    //                               LAB_00549957                                                 XREF[2]:     005494e6(j), 005494fa(j)  
    //         00549957     MOV        EAX,[DAT_00887a80]
    //         0054995c     POP        EBP
    //         0054995d     POP        EDI
    //         0054995e     POP        ESI
    //         0054995f     AND        dword ptr [EAX + 0x38120],0x7fff
    //         00549969     XOR        EAX,EAX
    //         0054996b     POP        EBX
    //         0054996c     RET
}

// Offset: 0x00549970
undefined FUN_00549970() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00549970()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     00549997(W), 005499a0(R), 00549a68(R), 00549abe(R)  
    //              undefined2        Stack[-0x6]:2  local_6                   XREF[6]:     005499b0(W), 005499e5(R), 00549a04(R), 00549a23(R), 
    //                                                                                     00549a43(R), 00549afb(W)  
    //              undefined2        Stack[-0x8]:2  local_8                   XREF[2]:     005499ba(W), 00549a52(R)  
    //                               FUN_00549970                                                 XREF[3]:     FUN_005494a0:005495ac(c), 
    //                                                                                                         FUN_005494a0:00549688(c), 
    //                                                                                                         FUN_00549b70:00549c52(c)  
    //         00549970     MOV        EDX,dword ptr [ESP + Stack[0x4]]
    //         00549974     SUB        ESP,0x8
    //         00549977     MOV        ECX,dword ptr [DAT_00886c60]
    //         0054997d     AND        EDX,0x7fff
    //         00549983     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00549987     PUSH       EBX
    //         00549988     PUSH       ESI
    //         00549989     ADD        EAX,dword ptr [DAT_00887a94]
    //         0054998f     PUSH       EDI
    //         00549990     PUSH       EBP
    //         00549991     MOV        ESI,dword ptr [DAT_00887a94]
    //         00549997     MOV        dword ptr [ESP + local_4],EAX
    //         0054999b     MOV        EAX,[DAT_00887b1c]
    //         005499a0     MOV        EBX,dword ptr [ESP + local_4]
    //         005499a4     MOV        BP,word ptr [EBX]
    //         005499a7     ADD        EAX,dword ptr [ESP + Stack[0x4]]
    //         005499ab     MOV        AX,word ptr [EAX + ESI*0x1 + -0x1]
    //         005499b0     MOV        word ptr [ESP + local_6],AX
    //         005499b5     MOV        EAX,[DAT_00887b1c]
    //         005499ba     MOV        word ptr [ESP + local_8],BP
    //         005499bf     LEA        ESI,[EAX + ESI*0x1 + -0x1]
    //                               LAB_005499c3                                                 XREF[4]:     00549a4c(j), 00549a62(j), 
    //                                                                                                         00549acf(j), 00549b00(j)  
    //         005499c3     TEST       ECX,ECX
    //         005499c5     JLE        LAB_00549b15
    //         005499cb     DEC        ECX
    //         005499cc     MOV        EDI,dword ptr [DAT_00886cf0]
    //         005499d2     XOR        EAX,EAX
    //         005499d4     MOV        AX,word ptr [EDI + EDX*0x2]
    //         005499d8     CMP        EAX,0xffff
    //         005499dd     MOV        EDX,EAX
    //         005499df     JZ         LAB_00549b15
    //         005499e5     MOV        AX,word ptr [ESP + local_6]
    //         005499ea     CMP        word ptr [ESI + EDX*0x1],AX
    //         005499ee     JZ         LAB_00549a52
    //         005499f0     DEC        ECX
    //         005499f1     XOR        EAX,EAX
    //         005499f3     MOV        AX,word ptr [EDI + EDX*0x2]
    //         005499f7     CMP        EAX,0xffff
    //         005499fc     MOV        EDX,EAX
    //         005499fe     JZ         LAB_00549b15
    //         00549a04     MOV        AX,word ptr [ESP + local_6]
    //         00549a09     CMP        word ptr [ESI + EDX*0x1],AX
    //         00549a0d     JZ         LAB_00549a52
    //         00549a0f     DEC        ECX
    //         00549a10     XOR        EAX,EAX
    //         00549a12     MOV        AX,word ptr [EDI + EDX*0x2]
    //         00549a16     CMP        EAX,0xffff
    //         00549a1b     MOV        EDX,EAX
    //         00549a1d     JZ         LAB_00549b15
    //         00549a23     MOV        AX,word ptr [ESP + local_6]
    //         00549a28     CMP        word ptr [ESI + EDX*0x1],AX
    //         00549a2c     JZ         LAB_00549a52
    //         00549a2e     DEC        ECX
    //         00549a2f     XOR        EBX,EBX
    //         00549a31     MOV        BX,word ptr [EDI + EDX*0x2]
    //         00549a35     CMP        EBX,0xffff
    //         00549a3b     MOV        EDX,EBX
    //         00549a3d     JZ         LAB_00549b15
    //         00549a43     MOV        AX,word ptr [ESP + local_6]
    //         00549a48     CMP        word ptr [ESI + EDX*0x1],AX
    //         00549a4c     JNZ        LAB_005499c3
    //                               LAB_00549a52                                                 XREF[3]:     005499ee(j), 00549a0d(j), 
    //                                                                                                         00549a2c(j)  
    //         00549a52     MOV        BP,word ptr [ESP + local_8]
    //         00549a57     MOV        EBX,dword ptr [DAT_00887a94]
    //         00549a5d     ADD        EBX,EDX
    //         00549a5f     CMP        word ptr [EBX],BP
    //         00549a62     JNZ        LAB_005499c3
    //         00549a68     MOV        EDI,dword ptr [ESP + local_4]
    //         00549a6c     MOV        EAX,0x20
    //                               LAB_00549a71                                                 XREF[1]:     00549ab0(j)  
    //         00549a71     MOV        BP,word ptr [EDI + 0x2]
    //         00549a75     ADD        EDI,0x2
    //         00549a78     ADD        EBX,0x2
    //         00549a7b     CMP        word ptr [EBX],BP
    //         00549a7e     JNZ        LAB_00549ab2
    //         00549a80     MOV        BP,word ptr [EDI + 0x2]
    //         00549a84     ADD        EDI,0x2
    //         00549a87     ADD        EBX,0x2
    //         00549a8a     CMP        word ptr [EBX],BP
    //         00549a8d     JNZ        LAB_00549ab2
    //         00549a8f     MOV        BP,word ptr [EDI + 0x2]
    //         00549a93     ADD        EDI,0x2
    //         00549a96     ADD        EBX,0x2
    //         00549a99     CMP        word ptr [EBX],BP
    //         00549a9c     JNZ        LAB_00549ab2
    //         00549a9e     MOV        BP,word ptr [EDI + 0x2]
    //         00549aa2     ADD        EDI,0x2
    //         00549aa5     ADD        EBX,0x2
    //         00549aa8     CMP        word ptr [EBX],BP
    //         00549aab     JNZ        LAB_00549ab2
    //         00549aad     DEC        EAX
    //         00549aae     TEST       EAX,EAX
    //         00549ab0     JG         LAB_00549a71
    //                               LAB_00549ab2                                                 XREF[4]:     00549a7e(j), 00549a8d(j), 
    //                                                                                                         00549a9c(j), 00549aab(j)  
    //         00549ab2     TEST       EAX,EAX
    //         00549ab4     JZ         LAB_00549b05
    //         00549ab6     MOV        AL,byte ptr [EBX]
    //         00549ab8     SUB        AL,byte ptr [EDI]
    //         00549aba     CMP        AL,0x1
    //         00549abc     SBB        EAX,EAX
    //         00549abe     SUB        EDI,dword ptr [ESP + local_4]
    //         00549ac2     NEG        EAX
    //         00549ac4     AND        EDI,0xfffffffe
    //         00549ac7     ADD        EDI,EAX
    //         00549ac9     CMP        EDI,dword ptr [DAT_00887b1c]
    //         00549acf     JLE        LAB_005499c3
    //         00549ad5     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         00549ad9     MOV        EAX,[DAT_00887a94]
    //         00549ade     ADD        ESI,EDI
    //         00549ae0     MOV        EBX,dword ptr [DAT_00887a94]
    //         00549ae6     MOV        dword ptr [DAT_00887fa8],EDX
    //         00549aec     MOV        dword ptr [DAT_00887b1c],EDI
    //         00549af2     MOV        AX,word ptr [ESI + EAX*0x1 + -0x1]
    //         00549af7     LEA        ESI,[EDI + EBX*0x1 + -0x1]
    //         00549afb     MOV        word ptr [ESP + local_6],AX
    //         00549b00     JMP        LAB_005499c3
    //                               LAB_00549b05                                                 XREF[1]:     00549ab4(j)  
    //         00549b05     MOV        dword ptr [DAT_00887b1c],0x102
    //         00549b0f     MOV        dword ptr [DAT_00887fa8],EDX
    //                               LAB_00549b15                                                 XREF[5]:     005499c5(j), 005499df(j), 
    //                                                                                                         005499fe(j), 00549a1d(j), 
    //                                                                                                         00549a3d(j)  
    //         00549b15     POP        EBP
    //         00549b16     POP        EDI
    //         00549b17     POP        ESI
    //         00549b18     POP        EBX
    //         00549b19     ADD        ESP,0x8
    //         00549b1c     RET
}

// Offset: 0x00549B20
undefined FUN_00549b20() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00549b20()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00549b20                                                 XREF[16]:    FUN_005494a0:0054958c(c), 
    //                                                                                                         FUN_005494a0:00549632(c), 
    //                                                                                                         FUN_005494a0:00549740(c), 
    //                                                                                                         FUN_005494a0:005497e6(c), 
    //                                                                                                         FUN_005494a0:0054989a(c), 
    //                                                                                                         FUN_005494a0:00549940(c), 
    //                                                                                                         FUN_00549b70:00549c32(c), 
    //                                                                                                         FUN_00549b70:00549ce5(c), 
    //                                                                                                         FUN_00549b70:00549d9a(c), 
    //                                                                                                         FUN_00549b70:00549e55(c), 
    //                                                                                                         FUN_00549b70:00549f10(c), 
    //                                                                                                         FUN_00549f40:0054a013(c), 
    //                                                                                                         FUN_00549f40:0054a0aa(c), 
    //                                                                                                         FUN_00549f40:0054a1ce(c), 
    //                                                                                                         FUN_00549f40:0054a27a(c), 
    //                                                                                                         FUN_00549f40:0054a333(c)  
    //         00549b20     MOV        EAX,[DAT_00887a80]
    //         00549b25     ADD        dword ptr [EAX + 0x3670c],0x4
    //         00549b2c     MOV        EAX,[DAT_00887a80]
    //         00549b31     MOV        dword ptr [EAX + 0x36710],0x20
    //         00549b3b     MOV        EAX,[DAT_00887a80]
    //         00549b40     ADD        dword ptr [EAX + 0x36108],0x20
    //         00549b47     MOV        EAX,[DAT_00887a80]
    //         00549b4c     CMP        dword ptr [EAX + 0x36108],0x3000
    //         00549b56     JNZ        LAB_00549b63
    //         00549b58     PUSH       0x0
    //         00549b5a     CALL       FUN_005480b0                                     undefined FUN_005480b0()
    //         00549b5f     ADD        ESP,0x4
    //         00549b62     RET
    //                               LAB_00549b63                                                 XREF[1]:     00549b56(j)  
    //         00549b63     XOR        EAX,EAX
    //         00549b65     RET
}

// Offset: 0x00549B70
undefined FUN_00549b70() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00549b70()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00549b70                                                 XREF[1]:     FUN_005494a0:005494bc(c)  
    //         00549b70     PUSH       EBX
    //         00549b71     PUSH       ESI
    //         00549b72     PUSH       EDI
    //         00549b73     XOR        ESI,ESI
    //         00549b75     PUSH       EBP
    //         00549b76     MOV        EDI,0x2
    //         00549b7b     MOV        EBX,0x3
    //                               LAB_00549b80                                                 XREF[10]:    00549c2c(j), 00549c39(j), 
    //                                                                                                         00549cdf(j), 00549cec(j), 
    //                                                                                                         00549d94(j), 00549da1(j), 
    //                                                                                                         00549e4f(j), 00549e5c(j), 
    //                                                                                                         00549f0a(j), 00549f17(j)  
    //         00549b80     MOV        EAX,[DAT_00887a80]
    //         00549b85     CMP        dword ptr [EAX + 0x38124],ESI
    //         00549b8b     JZ         LAB_00549f27
    //         00549b91     LEA        EDX,[EAX + 0x38120]
    //         00549b97     MOV        ECX,dword ptr [EDX]
    //         00549b99     CMP        dword ptr [EAX + 0x38128],ECX
    //         00549b9f     JBE        LAB_00549f27
    //         00549ba5     MOV        EAX,ECX
    //         00549ba7     MOV        EBP,dword ptr [DAT_00886cf0]
    //         00549bad     AND        EAX,0x7fff
    //         00549bb2     CMP        word ptr [EBP + EAX*0x2],0xffff
    //         00549bb9     JNZ        LAB_00549c49
    //         00549bbf     MOV        EAX,[DAT_00887a94]
    //         00549bc4     MOV        AL,byte ptr [EAX + ECX*0x1]
    //         00549bc7     MOV        ECX,dword ptr [DAT_00887a80]
    //         00549bcd     MOV        EDX,dword ptr [ECX + 0x36104]
    //         00549bd3     MOV        byte ptr [EDX],AL
    //         00549bd5     MOV        ECX,dword ptr [DAT_00887a80]
    //         00549bdb     INC        dword ptr [ECX + 0x38120]
    //         00549be1     MOV        ECX,dword ptr [DAT_00887a80]
    //         00549be7     INC        dword ptr [ECX + 0x36104]
    //         00549bed     MOV        ECX,dword ptr [DAT_00887a80]
    //         00549bf3     DEC        dword ptr [ECX + 0x38124]
    //         00549bf9     MOV        ECX,dword ptr [DAT_00887a80]
    //         00549bff     INC        dword ptr [ECX + 0x3671c]
    //         00549c05     MOV        ECX,dword ptr [DAT_00887a80]
    //         00549c0b     MOV        EAX,dword ptr [ECX + 0x3670c]
    //         00549c11     SHL        dword ptr [EAX],0x1
    //         00549c14     MOV        ECX,dword ptr [DAT_00887a80]
    //         00549c1a     DEC        dword ptr [ECX + 0x36710]
    //         00549c20     MOV        ECX,dword ptr [DAT_00887a80]
    //         00549c26     CMP        dword ptr [ECX + 0x36710],ESI
    //         00549c2c     JNZ        LAB_00549b80
    //         00549c32     CALL       FUN_00549b20                                     undefined FUN_00549b20()
    //         00549c37     TEST       EAX,EAX
    //         00549c39     JZ         LAB_00549b80
    //         00549c3f     MOV        EAX,0x1
    //         00549c44     POP        EBP
    //         00549c45     POP        EDI
    //         00549c46     POP        ESI
    //         00549c47     POP        EBX
    //         00549c48     RET
    //                               LAB_00549c49                                                 XREF[1]:     00549bb9(j)  
    //         00549c49     MOV        dword ptr [DAT_00887b1c],EDI
    //         00549c4f     MOV        EAX,dword ptr [EDX]
    //         00549c51     PUSH       EAX
    //         00549c52     CALL       FUN_00549970                                     undefined FUN_00549970()
    //         00549c57     ADD        ESP,0x4
    //         00549c5a     MOV        EAX,[DAT_00887a80]
    //         00549c5f     CMP        dword ptr [DAT_00887b1c],EDI
    //         00549c65     JNZ        LAB_00549cfc
    //         00549c6b     MOV        EDX,dword ptr [EAX + 0x38120]
    //         00549c71     MOV        ECX,dword ptr [DAT_00887a94]
    //         00549c77     MOV        AL,byte ptr [EDX + ECX*0x1]
    //         00549c7a     MOV        EDX,dword ptr [DAT_00887a80]
    //         00549c80     MOV        ECX,dword ptr [EDX + 0x36104]
    //         00549c86     MOV        byte ptr [ECX],AL
    //         00549c88     MOV        EDX,dword ptr [DAT_00887a80]
    //         00549c8e     INC        dword ptr [EDX + 0x38120]
    //         00549c94     MOV        EDX,dword ptr [DAT_00887a80]
    //         00549c9a     INC        dword ptr [EDX + 0x36104]
    //         00549ca0     MOV        EDX,dword ptr [DAT_00887a80]
    //         00549ca6     DEC        dword ptr [EDX + 0x38124]
    //         00549cac     MOV        EDX,dword ptr [DAT_00887a80]
    //         00549cb2     INC        dword ptr [EDX + 0x3671c]
    //         00549cb8     MOV        EDX,dword ptr [DAT_00887a80]
    //         00549cbe     MOV        EAX,dword ptr [EDX + 0x3670c]
    //         00549cc4     SHL        dword ptr [EAX],0x1
    //         00549cc7     MOV        EDX,dword ptr [DAT_00887a80]
    //         00549ccd     DEC        dword ptr [EDX + 0x36710]
    //         00549cd3     MOV        EDX,dword ptr [DAT_00887a80]
    //         00549cd9     CMP        dword ptr [EDX + 0x36710],ESI
    //         00549cdf     JNZ        LAB_00549b80
    //         00549ce5     CALL       FUN_00549b20                                     undefined FUN_00549b20()
    //         00549cea     TEST       EAX,EAX
    //         00549cec     JZ         LAB_00549b80
    //         00549cf2     MOV        EAX,0x1
    //         00549cf7     POP        EBP
    //         00549cf8     POP        EDI
    //         00549cf9     POP        ESI
    //         00549cfa     POP        EBX
    //         00549cfb     RET
    //                               LAB_00549cfc                                                 XREF[1]:     00549c65(j)  
    //         00549cfc     MOV        EAX,dword ptr [EAX + 0x38124]
    //         00549d02     CMP        dword ptr [DAT_00887b1c],EAX
    //         00549d08     JLE        LAB_00549db1
    //         00549d0e     MOV        [DAT_00887b1c],EAX
    //         00549d13     CMP        EAX,EDI
    //         00549d15     JG         LAB_00549db1
    //         00549d1b     MOV        EAX,[DAT_00887a80]
    //         00549d20     MOV        ECX,dword ptr [DAT_00887a94]
    //         00549d26     MOV        EDX,dword ptr [EAX + 0x38120]
    //         00549d2c     MOV        AL,byte ptr [EDX + ECX*0x1]
    //         00549d2f     MOV        EDX,dword ptr [DAT_00887a80]
    //         00549d35     MOV        ECX,dword ptr [EDX + 0x36104]
    //         00549d3b     MOV        byte ptr [ECX],AL
    //         00549d3d     MOV        EDX,dword ptr [DAT_00887a80]
    //         00549d43     INC        dword ptr [EDX + 0x38120]
    //         00549d49     MOV        EDX,dword ptr [DAT_00887a80]
    //         00549d4f     INC        dword ptr [EDX + 0x36104]
    //         00549d55     MOV        EDX,dword ptr [DAT_00887a80]
    //         00549d5b     DEC        dword ptr [EDX + 0x38124]
    //         00549d61     MOV        EDX,dword ptr [DAT_00887a80]
    //         00549d67     INC        dword ptr [EDX + 0x3671c]
    //         00549d6d     MOV        EDX,dword ptr [DAT_00887a80]
    //         00549d73     MOV        EAX,dword ptr [EDX + 0x3670c]
    //         00549d79     SHL        dword ptr [EAX],0x1
    //         00549d7c     MOV        EDX,dword ptr [DAT_00887a80]
    //         00549d82     DEC        dword ptr [EDX + 0x36710]
    //         00549d88     MOV        EDX,dword ptr [DAT_00887a80]
    //         00549d8e     CMP        dword ptr [EDX + 0x36710],ESI
    //         00549d94     JNZ        LAB_00549b80
    //         00549d9a     CALL       FUN_00549b20                                     undefined FUN_00549b20()
    //         00549d9f     TEST       EAX,EAX
    //         00549da1     JZ         LAB_00549b80
    //         00549da7     MOV        EAX,0x1
    //         00549dac     POP        EBP
    //         00549dad     POP        EDI
    //         00549dae     POP        ESI
    //         00549daf     POP        EBX
    //         00549db0     RET
    //                               LAB_00549db1                                                 XREF[2]:     00549d08(j), 00549d15(j)  
    //         00549db1     MOV        EAX,[DAT_00887a80]
    //         00549db6     MOV        EDX,dword ptr [EAX + 0x38120]
    //         00549dbc     MOV        ECX,EDX
    //         00549dbe     SUB        ECX,dword ptr [DAT_00887fa8]
    //         00549dc4     AND        ECX,0x7fff
    //         00549dca     CMP        dword ptr [DAT_00887b1c],EBX
    //         00549dd0     JNZ        LAB_00549e6c
    //         00549dd6     CMP        ECX,0x4000
    //         00549ddc     JL         LAB_00549e6c
    //         00549de2     MOV        EAX,[DAT_00887a94]
    //         00549de7     MOV        ECX,dword ptr [DAT_00887a80]
    //         00549ded     MOV        AL,byte ptr [EAX + EDX*0x1]
    //         00549df0     MOV        EDX,dword ptr [ECX + 0x36104]
    //         00549df6     MOV        byte ptr [EDX],AL
    //         00549df8     MOV        ECX,dword ptr [DAT_00887a80]
    //         00549dfe     INC        dword ptr [ECX + 0x38120]
    //         00549e04     MOV        ECX,dword ptr [DAT_00887a80]
    //         00549e0a     INC        dword ptr [ECX + 0x36104]
    //         00549e10     MOV        ECX,dword ptr [DAT_00887a80]
    //         00549e16     DEC        dword ptr [ECX + 0x38124]
    //         00549e1c     MOV        ECX,dword ptr [DAT_00887a80]
    //         00549e22     INC        dword ptr [ECX + 0x3671c]
    //         00549e28     MOV        ECX,dword ptr [DAT_00887a80]
    //         00549e2e     MOV        EAX,dword ptr [ECX + 0x3670c]
    //         00549e34     SHL        dword ptr [EAX],0x1
    //         00549e37     MOV        ECX,dword ptr [DAT_00887a80]
    //         00549e3d     DEC        dword ptr [ECX + 0x36710]
    //         00549e43     MOV        ECX,dword ptr [DAT_00887a80]
    //         00549e49     CMP        dword ptr [ECX + 0x36710],ESI
    //         00549e4f     JNZ        LAB_00549b80
    //         00549e55     CALL       FUN_00549b20                                     undefined FUN_00549b20()
    //         00549e5a     TEST       EAX,EAX
    //         00549e5c     JZ         LAB_00549b80
    //         00549e62     MOV        EAX,0x1
    //         00549e67     POP        EBP
    //         00549e68     POP        EDI
    //         00549e69     POP        ESI
    //         00549e6a     POP        EBX
    //         00549e6b     RET
    //                               LAB_00549e6c                                                 XREF[2]:     00549dd0(j), 00549ddc(j)  
    //         00549e6c     MOV        EAX,[DAT_00887b1c]
    //         00549e71     MOV        EDX,dword ptr [DAT_00887a80]
    //         00549e77     SUB        AL,0x3
    //         00549e79     MOV        EBP,dword ptr [EDX + 0x36104]
    //         00549e7f     MOV        byte ptr [EBP],AL
    //         00549e82     MOV        EDX,dword ptr [DAT_00887a80]
    //         00549e88     INC        dword ptr [EDX + 0x36104]
    //         00549e8e     MOV        EDX,dword ptr [DAT_00887a80]
    //         00549e94     MOV        EBP,dword ptr [EDX + 0x36104]
    //         00549e9a     MOV        word ptr [EBP],CX
    //         00549e9e     MOV        EDX,dword ptr [DAT_00887a80]
    //         00549ea4     ADD        dword ptr [EDX + 0x36104],EDI
    //         00549eaa     MOV        EDX,dword ptr [DAT_00887a80]
    //         00549eb0     MOV        EAX,[DAT_00887b1c]
    //         00549eb5     ADD        dword ptr [EDX + 0x38120],EAX
    //         00549ebb     MOV        EDX,dword ptr [DAT_00887a80]
    //         00549ec1     MOV        EAX,[DAT_00887b1c]
    //         00549ec6     SUB        dword ptr [EDX + 0x38124],EAX
    //         00549ecc     MOV        EDX,dword ptr [DAT_00887a80]
    //         00549ed2     MOV        EAX,[DAT_00887b1c]
    //         00549ed7     ADD        dword ptr [EDX + 0x3671c],EAX
    //         00549edd     MOV        EDX,dword ptr [DAT_00887a80]
    //         00549ee3     MOV        EAX,dword ptr [EDX + 0x3670c]
    //         00549ee9     MOV        ECX,dword ptr [EAX]
    //         00549eeb     ADD        ECX,ECX
    //         00549eed     OR         ECX,0x1
    //         00549ef0     MOV        dword ptr [EAX],ECX
    //         00549ef2     MOV        EDX,dword ptr [DAT_00887a80]
    //         00549ef8     DEC        dword ptr [EDX + 0x36710]
    //         00549efe     MOV        EDX,dword ptr [DAT_00887a80]
    //         00549f04     CMP        dword ptr [EDX + 0x36710],ESI
    //         00549f0a     JNZ        LAB_00549b80
    //         00549f10     CALL       FUN_00549b20                                     undefined FUN_00549b20()
    //         00549f15     TEST       EAX,EAX
    //         00549f17     JZ         LAB_00549b80
    //         00549f1d     MOV        EAX,0x1
    //         00549f22     POP        EBP
    //         00549f23     POP        EDI
    //         00549f24     POP        ESI
    //         00549f25     POP        EBX
    //         00549f26     RET
    //                               LAB_00549f27                                                 XREF[2]:     00549b8b(j), 00549b9f(j)  
    //         00549f27     MOV        EAX,[DAT_00887a80]
    //         00549f2c     POP        EBP
    //         00549f2d     POP        EDI
    //         00549f2e     POP        ESI
    //         00549f2f     AND        dword ptr [EAX + 0x38120],0x7fff
    //         00549f39     XOR        EAX,EAX
    //         00549f3b     POP        EBX
    //         00549f3c     RET
}

// Offset: 0x00549F40
undefined FUN_00549f40() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00549f40()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00549f40                                                 XREF[1]:     FUN_005494a0:005494b7(c)  
    //         00549f40     PUSH       EBX
    //         00549f41     PUSH       ESI
    //         00549f42     PUSH       EDI
    //         00549f43     XOR        ESI,ESI
    //         00549f45     PUSH       EBP
    //         00549f46     MOV        EDI,0x2
    //                               LAB_00549f4b                                                 XREF[10]:    0054a00d(j), 0054a01a(j), 
    //                                                                                                         0054a0a4(j), 0054a0b1(j), 
    //                                                                                                         0054a1c8(j), 0054a1d5(j), 
    //                                                                                                         0054a274(j), 0054a281(j), 
    //                                                                                                         0054a32d(j), 0054a33a(j)  
    //         00549f4b     MOV        EDX,dword ptr [DAT_00887a80]
    //         00549f51     ADD        EDX,0x38124
    //         00549f57     CMP        dword ptr [EDX],ESI
    //         00549f59     JZ         LAB_0054a34a
    //         00549f5f     MOV        ECX,dword ptr [DAT_00887a80]
    //         00549f65     MOV        EAX,[DAT_00887a80]
    //         00549f6a     MOV        EBX,dword ptr [ECX + 0x38120]
    //         00549f70     ADD        ECX,0x38120
    //         00549f76     CMP        dword ptr [EAX + 0x38128],EBX
    //         00549f7c     JBE        LAB_0054a34a
    //         00549f82     AND        EBX,0x7fff
    //         00549f88     MOV        EBP,dword ptr [DAT_00886cf0]
    //         00549f8e     XOR        EAX,EAX
    //         00549f90     MOV        AX,word ptr [EBP + EBX*0x2]
    //         00549f95     MOV        [DAT_00887fa8],EAX
    //         00549f9a     CMP        EAX,0xffff
    //         00549f9f     JNZ        LAB_0054a02a
    //         00549fa5     MOV        EAX,dword ptr [ECX]
    //         00549fa7     MOV        ECX,dword ptr [DAT_00887a94]
    //         00549fad     MOV        CL,byte ptr [EAX + ECX*0x1]
    //         00549fb0     MOV        EAX,[DAT_00887a80]
    //         00549fb5     MOV        EDX,dword ptr [EAX + 0x36104]
    //         00549fbb     MOV        byte ptr [EDX],CL
    //         00549fbd     MOV        EAX,[DAT_00887a80]
    //         00549fc2     INC        dword ptr [EAX + 0x38120]
    //         00549fc8     MOV        EAX,[DAT_00887a80]
    //         00549fcd     INC        dword ptr [EAX + 0x36104]
    //         00549fd3     MOV        EAX,[DAT_00887a80]
    //         00549fd8     DEC        dword ptr [EAX + 0x38124]
    //         00549fde     MOV        EAX,[DAT_00887a80]
    //         00549fe3     INC        dword ptr [EAX + 0x3671c]
    //         00549fe9     MOV        EAX,[DAT_00887a80]
    //         00549fee     MOV        ECX,dword ptr [EAX + 0x3670c]
    //         00549ff4     SHL        dword ptr [ECX],0x1
    //         00549ff7     MOV        EAX,[DAT_00887a80]
    //         00549ffc     DEC        dword ptr [EAX + 0x36710]
    //         0054a002     MOV        EAX,[DAT_00887a80]
    //         0054a007     CMP        dword ptr [EAX + 0x36710],ESI
    //         0054a00d     JNZ        LAB_00549f4b
    //         0054a013     CALL       FUN_00549b20                                     undefined FUN_00549b20()
    //         0054a018     TEST       EAX,EAX
    //         0054a01a     JZ         LAB_00549f4b
    //         0054a020     MOV        EAX,0x1
    //         0054a025     POP        EBP
    //         0054a026     POP        EDI
    //         0054a027     POP        ESI
    //         0054a028     POP        EBX
    //         0054a029     RET
    //                               LAB_0054a02a                                                 XREF[1]:     00549f9f(j)  
    //         0054a02a     MOV        EBP,dword ptr [DAT_00887fa8]
    //         0054a030     MOV        EAX,dword ptr [ECX]
    //         0054a032     ADD        EBP,dword ptr [DAT_00887a94]
    //         0054a038     ADD        EAX,dword ptr [DAT_00887a94]
    //         0054a03e     MOV        BX,word ptr [EAX]
    //         0054a041     CMP        word ptr [EBP],BX
    //         0054a045     JZ         LAB_0054a0c1
    //         0054a047     MOV        EAX,[DAT_00887a80]
    //         0054a04c     MOV        EDX,dword ptr [EAX + 0x36104]
    //         0054a052     MOV        byte ptr [EDX],BL
    //         0054a054     MOV        EAX,[DAT_00887a80]
    //         0054a059     INC        dword ptr [EAX + 0x38120]
    //         0054a05f     MOV        EAX,[DAT_00887a80]
    //         0054a064     INC        dword ptr [EAX + 0x36104]
    //         0054a06a     MOV        EAX,[DAT_00887a80]
    //         0054a06f     DEC        dword ptr [EAX + 0x38124]
    //         0054a075     MOV        EAX,[DAT_00887a80]
    //         0054a07a     INC        dword ptr [EAX + 0x3671c]
    //         0054a080     MOV        EAX,[DAT_00887a80]
    //         0054a085     MOV        ECX,dword ptr [EAX + 0x3670c]
    //         0054a08b     SHL        dword ptr [ECX],0x1
    //         0054a08e     MOV        EAX,[DAT_00887a80]
    //         0054a093     DEC        dword ptr [EAX + 0x36710]
    //         0054a099     MOV        EAX,[DAT_00887a80]
    //         0054a09e     CMP        dword ptr [EAX + 0x36710],ESI
    //         0054a0a4     JNZ        LAB_00549f4b
    //         0054a0aa     CALL       FUN_00549b20                                     undefined FUN_00549b20()
    //         0054a0af     TEST       EAX,EAX
    //         0054a0b1     JZ         LAB_00549f4b
    //         0054a0b7     MOV        EAX,0x1
    //         0054a0bc     POP        EBP
    //         0054a0bd     POP        EDI
    //         0054a0be     POP        ESI
    //         0054a0bf     POP        EBX
    //         0054a0c0     RET
    //                               LAB_0054a0c1                                                 XREF[1]:     0054a045(j)  
    //         0054a0c1     MOV        dword ptr [DAT_00887b1c],0x20
    //                               LAB_0054a0cb                                                 XREF[1]:     0054a10b(j)  
    //         0054a0cb     ADD        EBP,EDI
    //         0054a0cd     ADD        EAX,EDI
    //         0054a0cf     MOV        BX,word ptr [EBP]
    //         0054a0d3     CMP        word ptr [EAX],BX
    //         0054a0d6     JNZ        LAB_0054a10d
    //         0054a0d8     ADD        EBP,EDI
    //         0054a0da     ADD        EAX,EDI
    //         0054a0dc     MOV        BX,word ptr [EBP]
    //         0054a0e0     CMP        word ptr [EAX],BX
    //         0054a0e3     JNZ        LAB_0054a10d
    //         0054a0e5     ADD        EBP,EDI
    //         0054a0e7     ADD        EAX,EDI
    //         0054a0e9     MOV        BX,word ptr [EBP]
    //         0054a0ed     CMP        word ptr [EAX],BX
    //         0054a0f0     JNZ        LAB_0054a10d
    //         0054a0f2     ADD        EBP,EDI
    //         0054a0f4     ADD        EAX,EDI
    //         0054a0f6     MOV        BX,word ptr [EBP]
    //         0054a0fa     CMP        word ptr [EAX],BX
    //         0054a0fd     JNZ        LAB_0054a10d
    //         0054a0ff     DEC        dword ptr [DAT_00887b1c]
    //         0054a105     CMP        dword ptr [DAT_00887b1c],ESI
    //         0054a10b     JG         LAB_0054a0cb
    //                               LAB_0054a10d                                                 XREF[4]:     0054a0d6(j), 0054a0e3(j), 
    //                                                                                                         0054a0f0(j), 0054a0fd(j)  
    //         0054a10d     CMP        dword ptr [DAT_00887b1c],ESI
    //         0054a113     JNZ        LAB_0054a121
    //         0054a115     MOV        dword ptr [DAT_00887b1c],0x102
    //         0054a11f     JMP        LAB_0054a145
    //                               LAB_0054a121                                                 XREF[1]:     0054a113(j)  
    //         0054a121     MOV        EBX,EBP
    //         0054a123     MOV        AL,byte ptr [EAX]
    //         0054a125     SUB        EBX,dword ptr [DAT_00887fa8]
    //         0054a12b     SUB        AL,byte ptr [EBP]
    //         0054a12e     SUB        EBX,dword ptr [DAT_00887a94]
    //         0054a134     AND        EBX,0xfffffffe
    //         0054a137     CMP        AL,0x1
    //         0054a139     SBB        EAX,EAX
    //         0054a13b     NEG        EAX
    //         0054a13d     ADD        EBX,EAX
    //         0054a13f     MOV        dword ptr [DAT_00887b1c],EBX
    //                               LAB_0054a145                                                 XREF[1]:     0054a11f(j)  
    //         0054a145     MOV        EAX,dword ptr [EDX]
    //         0054a147     CMP        dword ptr [DAT_00887b1c],EAX
    //         0054a14d     JLE        LAB_0054a1e5
    //         0054a153     MOV        [DAT_00887b1c],EAX
    //         0054a158     CMP        EAX,EDI
    //         0054a15a     JG         LAB_0054a1e5
    //         0054a160     MOV        EAX,dword ptr [ECX]
    //         0054a162     MOV        ECX,dword ptr [DAT_00887a94]
    //         0054a168     MOV        CL,byte ptr [EAX + ECX*0x1]
    //         0054a16b     MOV        EAX,[DAT_00887a80]
    //         0054a170     MOV        EDX,dword ptr [EAX + 0x36104]
    //         0054a176     MOV        byte ptr [EDX],CL
    //         0054a178     MOV        EAX,[DAT_00887a80]
    //         0054a17d     INC        dword ptr [EAX + 0x38120]
    //         0054a183     MOV        EAX,[DAT_00887a80]
    //         0054a188     INC        dword ptr [EAX + 0x36104]
    //         0054a18e     MOV        EAX,[DAT_00887a80]
    //         0054a193     DEC        dword ptr [EAX + 0x38124]
    //         0054a199     MOV        EAX,[DAT_00887a80]
    //         0054a19e     INC        dword ptr [EAX + 0x3671c]
    //         0054a1a4     MOV        EAX,[DAT_00887a80]
    //         0054a1a9     MOV        ECX,dword ptr [EAX + 0x3670c]
    //         0054a1af     SHL        dword ptr [ECX],0x1
    //         0054a1b2     MOV        EAX,[DAT_00887a80]
    //         0054a1b7     DEC        dword ptr [EAX + 0x36710]
    //         0054a1bd     MOV        EAX,[DAT_00887a80]
    //         0054a1c2     CMP        dword ptr [EAX + 0x36710],ESI
    //         0054a1c8     JNZ        LAB_00549f4b
    //         0054a1ce     CALL       FUN_00549b20                                     undefined FUN_00549b20()
    //         0054a1d3     TEST       EAX,EAX
    //         0054a1d5     JZ         LAB_00549f4b
    //         0054a1db     MOV        EAX,0x1
    //         0054a1e0     POP        EBP
    //         0054a1e1     POP        EDI
    //         0054a1e2     POP        ESI
    //         0054a1e3     POP        EBX
    //         0054a1e4     RET
    //                               LAB_0054a1e5                                                 XREF[2]:     0054a14d(j), 0054a15a(j)  
    //         0054a1e5     MOV        EAX,dword ptr [ECX]
    //         0054a1e7     MOV        ECX,EAX
    //         0054a1e9     SUB        ECX,dword ptr [DAT_00887fa8]
    //         0054a1ef     AND        ECX,0x7fff
    //         0054a1f5     CMP        dword ptr [DAT_00887b1c],0x3
    //         0054a1fc     JNZ        LAB_0054a291
    //         0054a202     CMP        ECX,0x4000
    //         0054a208     JL         LAB_0054a291
    //         0054a20e     MOV        ECX,dword ptr [DAT_00887a94]
    //         0054a214     MOV        CL,byte ptr [ECX + EAX*0x1]
    //         0054a217     MOV        EAX,[DAT_00887a80]
    //         0054a21c     MOV        EDX,dword ptr [EAX + 0x36104]
    //         0054a222     MOV        byte ptr [EDX],CL
    //         0054a224     MOV        EAX,[DAT_00887a80]
    //         0054a229     INC        dword ptr [EAX + 0x38120]
    //         0054a22f     MOV        EAX,[DAT_00887a80]
    //         0054a234     INC        dword ptr [EAX + 0x36104]
    //         0054a23a     MOV        EAX,[DAT_00887a80]
    //         0054a23f     DEC        dword ptr [EAX + 0x38124]
    //         0054a245     MOV        EAX,[DAT_00887a80]
    //         0054a24a     INC        dword ptr [EAX + 0x3671c]
    //         0054a250     MOV        EAX,[DAT_00887a80]
    //         0054a255     MOV        ECX,dword ptr [EAX + 0x3670c]
    //         0054a25b     SHL        dword ptr [ECX],0x1
    //         0054a25e     MOV        EAX,[DAT_00887a80]
    //         0054a263     DEC        dword ptr [EAX + 0x36710]
    //         0054a269     MOV        EAX,[DAT_00887a80]
    //         0054a26e     CMP        dword ptr [EAX + 0x36710],ESI
    //         0054a274     JNZ        LAB_00549f4b
    //         0054a27a     CALL       FUN_00549b20                                     undefined FUN_00549b20()
    //         0054a27f     TEST       EAX,EAX
    //         0054a281     JZ         LAB_00549f4b
    //         0054a287     MOV        EAX,0x1
    //         0054a28c     POP        EBP
    //         0054a28d     POP        EDI
    //         0054a28e     POP        ESI
    //         0054a28f     POP        EBX
    //         0054a290     RET
    //                               LAB_0054a291                                                 XREF[2]:     0054a1fc(j), 0054a208(j)  
    //         0054a291     MOV        EAX,[DAT_00887b1c]
    //         0054a296     MOV        EDX,dword ptr [DAT_00887a80]
    //         0054a29c     SUB        AL,0x3
    //         0054a29e     MOV        EBX,dword ptr [EDX + 0x36104]
    //         0054a2a4     MOV        byte ptr [EBX],AL
    //         0054a2a6     MOV        EDX,dword ptr [DAT_00887a80]
    //         0054a2ac     INC        dword ptr [EDX + 0x36104]
    //         0054a2b2     MOV        EDX,dword ptr [DAT_00887a80]
    //         0054a2b8     MOV        EBX,dword ptr [EDX + 0x36104]
    //         0054a2be     MOV        word ptr [EBX],CX
    //         0054a2c1     MOV        EDX,dword ptr [DAT_00887a80]
    //         0054a2c7     ADD        dword ptr [EDX + 0x36104],EDI
    //         0054a2cd     MOV        EDX,dword ptr [DAT_00887a80]
    //         0054a2d3     MOV        EAX,[DAT_00887b1c]
    //         0054a2d8     ADD        dword ptr [EDX + 0x38120],EAX
    //         0054a2de     MOV        EDX,dword ptr [DAT_00887a80]
    //         0054a2e4     MOV        EAX,[DAT_00887b1c]
    //         0054a2e9     SUB        dword ptr [EDX + 0x38124],EAX
    //         0054a2ef     MOV        EDX,dword ptr [DAT_00887a80]
    //         0054a2f5     MOV        EAX,[DAT_00887b1c]
    //         0054a2fa     ADD        dword ptr [EDX + 0x3671c],EAX
    //         0054a300     MOV        EDX,dword ptr [DAT_00887a80]
    //         0054a306     MOV        EAX,dword ptr [EDX + 0x3670c]
    //         0054a30c     MOV        ECX,dword ptr [EAX]
    //         0054a30e     ADD        ECX,ECX
    //         0054a310     OR         ECX,0x1
    //         0054a313     MOV        dword ptr [EAX],ECX
    //         0054a315     MOV        EDX,dword ptr [DAT_00887a80]
    //         0054a31b     DEC        dword ptr [EDX + 0x36710]
    //         0054a321     MOV        EDX,dword ptr [DAT_00887a80]
    //         0054a327     CMP        dword ptr [EDX + 0x36710],ESI
    //         0054a32d     JNZ        LAB_00549f4b
    //         0054a333     CALL       FUN_00549b20                                     undefined FUN_00549b20()
    //         0054a338     TEST       EAX,EAX
    //         0054a33a     JZ         LAB_00549f4b
    //         0054a340     MOV        EAX,0x1
    //         0054a345     POP        EBP
    //         0054a346     POP        EDI
    //         0054a347     POP        ESI
    //         0054a348     POP        EBX
    //         0054a349     RET
    //                               LAB_0054a34a                                                 XREF[2]:     00549f59(j), 00549f7c(j)  
    //         0054a34a     MOV        EAX,[DAT_00887a80]
    //         0054a34f     POP        EBP
    //         0054a350     POP        EDI
    //         0054a351     POP        ESI
    //         0054a352     AND        dword ptr [EAX + 0x38120],0x7fff
    //         0054a35c     XOR        EAX,EAX
    //         0054a35e     POP        EBX
    //         0054a35f     RET
}

