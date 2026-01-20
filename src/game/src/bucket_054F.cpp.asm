// Auto-generated scaffold unit: bucket_054F.cpp.asm
#include "../include/common.h"

// Offset: 0x0054F020
undefined qsort() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * qsort                                                                                                 *
    //                              *********************************************************************************************************
    //                              undefined __cdecl qsort()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined         Stack[-0x78]:1 local_78                  XREF[1]:     0054f059(*)  
    //              undefined4        Stack[-0x7c]:4 local_7c                  XREF[1]:     0054f0c3(*)  
    //              undefined         Stack[-0xf0]:1 local_f0                  XREF[1]:     0054f055(*)  
    //              undefined4        Stack[-0xf4]:4 local_f4                  XREF[4]:     0054f060(W), 0054f095(R), 0054f0ab(W), 0054f0c1(*)  
    //              undefined4        Stack[-0xf8]:4 local_f8                  XREF[3]:     0054f070(W), 0054f099(R), 0054f0b1(W)  
    //              undefined4        Stack[-0xfc]:4 local_fc                  XREF[4]:     0054f06c(W), 0054f09d(R), 0054f0b5(W), 0054f0bb(R)  
    //              undefined4        Stack[-0x100   local_100                 XREF[3]:     0054f068(W), 0054f0c5(W), 0054f0ee(R)  
    //                               _qsort                                                       XREF[3]:     sort_list:0047eae6(c), 
    //                               qsort                                                                     reset_score_display:0049b286(c), 
    //                                                                                                         set_unit_player:004ab52c(c)  
    //         0054f020     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         0054f024     SUB        ESP,0x100
    //         0054f02a     CMP        EAX,0x2
    //         0054f02d     PUSH       EBX
    //         0054f02e     PUSH       EBP
    //         0054f02f     PUSH       ESI
    //         0054f030     PUSH       EDI
    //         0054f031     JC         LAB_0054f0cd
    //         0054f037     MOV        EBX,dword ptr [ESP + Stack[0xc]]
    //         0054f03e     TEST       EBX,EBX
    //         0054f040     JZ         LAB_0054f0cd
    //         0054f046     LEA        ESI,[EAX + -0x1]
    //         0054f049     MOV        EDI,dword ptr [ESP + Stack[0x4]]
    //         0054f050     IMUL       ESI,EBX
    //         0054f053     ADD        ESI,EDI
    //         0054f055     LEA        EAX=>local_f0,[ESP + 0x20]
    //         0054f059     LEA        ECX=>local_78,[ESP + 0x98]
    //         0054f060     MOV        dword ptr [ESP + local_f4],0x0
    //         0054f068     MOV        dword ptr [ESP + local_100],ESI
    //         0054f06c     MOV        dword ptr [ESP + local_fc],EAX
    //         0054f070     MOV        dword ptr [ESP + local_f8],ECX
    //                               LAB_0054f074                                                 XREF[3]:     0054f0cb(j), 0054f183(j), 
    //                                                                                                         0054f1c0(j)  
    //         0054f074     MOV        EAX,ESI
    //         0054f076     XOR        EDX,EDX
    //         0054f078     SUB        EAX,EDI
    //         0054f07a     DIV        EBX
    //         0054f07c     INC        EAX
    //         0054f07d     CMP        EAX,0x8
    //         0054f080     JA         LAB_0054f0d8
    //         0054f082     MOV        EDX,dword ptr [ESP + Stack[0x10]]
    //         0054f089     PUSH       EDX
    //         0054f08a     PUSH       EBX
    //         0054f08b     PUSH       ESI
    //         0054f08c     PUSH       EDI
    //         0054f08d     CALL       FUN_0054f1d0                                     undefined FUN_0054f1d0()
    //         0054f092     ADD        ESP,0x10
    //                               LAB_0054f095                                                 XREF[2]:     0054f177(j), 0054f1b4(j)  
    //         0054f095     MOV        EAX,dword ptr [ESP + local_f4]
    //         0054f099     MOV        ESI,dword ptr [ESP + local_f8]
    //         0054f09d     MOV        EDX,dword ptr [ESP + local_fc]
    //         0054f0a1     MOV        ECX,0x4
    //         0054f0a6     DEC        EAX
    //         0054f0a7     SUB        ESI,ECX
    //         0054f0a9     SUB        EDX,ECX
    //         0054f0ab     MOV        dword ptr [ESP + local_f4],EAX
    //         0054f0af     TEST       EAX,EAX
    //         0054f0b1     MOV        dword ptr [ESP + local_f8],ESI
    //         0054f0b5     MOV        dword ptr [ESP + local_fc],EDX
    //         0054f0b9     JL         LAB_0054f0cd
    //         0054f0bb     MOV        EAX,dword ptr [ESP + local_fc]
    //         0054f0bf     MOV        EDX,ESI
    //         0054f0c1     MOV        ECX,dword ptr [EAX]=>local_f4
    //         0054f0c3     MOV        EDI,dword ptr [EDX]=>local_7c
    //         0054f0c5     MOV        dword ptr [ESP + local_100],ECX
    //         0054f0c9     MOV        ESI,ECX
    //         0054f0cb     JMP        LAB_0054f074
    //                               LAB_0054f0cd                                                 XREF[3]:     0054f031(j), 0054f040(j), 
    //                                                                                                         0054f0b9(j)  
    //         0054f0cd     POP        EDI
    //         0054f0ce     POP        ESI
    //         0054f0cf     POP        EBP
    //         0054f0d0     POP        EBX
    //         0054f0d1     ADD        ESP,0x100
    //         0054f0d7     RET
    //                               LAB_0054f0d8                                                 XREF[1]:     0054f080(j)  
    //         0054f0d8     SHR        EAX,0x1
    //         0054f0da     IMUL       EAX,EBX
    //         0054f0dd     PUSH       EBX
    //         0054f0de     ADD        EAX,EDI
    //         0054f0e0     PUSH       EDI
    //         0054f0e1     PUSH       EAX
    //         0054f0e2     CALL       FUN_0054f230                                     undefined FUN_0054f230()
    //         0054f0e7     ADD        ESP,0xc
    //         0054f0ea     MOV        EBP,EDI
    //         0054f0ec     ADD        ESI,EBX
    //                               LAB_0054f0ee                                                 XREF[2]:     0054f106(j), 0054f12d(j)  
    //         0054f0ee     MOV        EAX,dword ptr [ESP + local_100]
    //         0054f0f2     ADD        EBP,EBX
    //         0054f0f4     CMP        EBP,EAX
    //         0054f0f6     JA         LAB_0054f108
    //         0054f0f8     PUSH       EDI
    //         0054f0f9     PUSH       EBP
    //         0054f0fa     CALL       dword ptr [ESP + Stack[0x10]]
    //         0054f101     ADD        ESP,0x8
    //         0054f104     TEST       EAX,EAX
    //         0054f106     JLE        LAB_0054f0ee
    //                               LAB_0054f108                                                 XREF[2]:     0054f0f6(j), 0054f11c(j)  
    //         0054f108     SUB        ESI,EBX
    //         0054f10a     CMP        ESI,EDI
    //         0054f10c     JBE        LAB_0054f11e
    //         0054f10e     PUSH       EDI
    //         0054f10f     PUSH       ESI
    //         0054f110     CALL       dword ptr [ESP + 0x128]
    //         0054f117     ADD        ESP,0x8
    //         0054f11a     TEST       EAX,EAX
    //         0054f11c     JGE        LAB_0054f108
    //                               LAB_0054f11e                                                 XREF[1]:     0054f10c(j)  
    //         0054f11e     CMP        ESI,EBP
    //         0054f120     PUSH       EBX
    //         0054f121     PUSH       ESI
    //         0054f122     JC         LAB_0054f12f
    //         0054f124     PUSH       EBP
    //         0054f125     CALL       FUN_0054f230                                     undefined FUN_0054f230()
    //         0054f12a     ADD        ESP,0xc
    //         0054f12d     JMP        LAB_0054f0ee
    //                               LAB_0054f12f                                                 XREF[1]:     0054f122(j)  
    //         0054f12f     PUSH       EDI
    //         0054f130     CALL       FUN_0054f230                                     undefined FUN_0054f230()
    //         0054f135     MOV        EDX,dword ptr [ESP + 0x1c]
    //         0054f139     MOV        ECX,ESI
    //         0054f13b     MOV        EAX,EDX
    //         0054f13d     SUB        ECX,EDI
    //         0054f13f     ADD        ESP,0xc
    //         0054f142     SUB        EAX,EBP
    //         0054f144     DEC        ECX
    //         0054f145     CMP        ECX,EAX
    //         0054f147     JL         LAB_0054f188
    //         0054f149     LEA        EAX,[EDI + EBX*0x1]
    //         0054f14c     CMP        EAX,ESI
    //         0054f14e     JNC        LAB_0054f175
    //         0054f150     MOV        EAX,dword ptr [ESP + 0x18]
    //         0054f154     MOV        ECX,dword ptr [ESP + 0x14]
    //         0054f158     SUB        ESI,EBX
    //         0054f15a     MOV        dword ptr [EAX],EDI
    //         0054f15c     MOV        EDI,dword ptr [ESP + 0x1c]
    //         0054f160     MOV        dword ptr [ECX],ESI
    //         0054f162     INC        EDI
    //         0054f163     ADD        EAX,0x4
    //         0054f166     ADD        ECX,0x4
    //         0054f169     MOV        dword ptr [ESP + 0x1c],EDI
    //         0054f16d     MOV        dword ptr [ESP + 0x18],EAX
    //         0054f171     MOV        dword ptr [ESP + 0x14],ECX
    //                               LAB_0054f175                                                 XREF[1]:     0054f14e(j)  
    //         0054f175     CMP        EBP,EDX
    //         0054f177     JNC        LAB_0054f095
    //         0054f17d     MOV        ESI,dword ptr [ESP + 0x10]
    //         0054f181     MOV        EDI,EBP
    //         0054f183     JMP        LAB_0054f074
    //                               LAB_0054f188                                                 XREF[1]:     0054f147(j)  
    //         0054f188     CMP        EBP,EDX
    //         0054f18a     JNC        LAB_0054f1af
    //         0054f18c     MOV        EAX,dword ptr [ESP + 0x18]
    //         0054f190     MOV        ECX,dword ptr [ESP + 0x14]
    //         0054f194     MOV        dword ptr [EAX],EBP
    //         0054f196     MOV        EBP,dword ptr [ESP + 0x1c]
    //         0054f19a     MOV        dword ptr [ECX],EDX
    //         0054f19c     INC        EBP
    //         0054f19d     ADD        EAX,0x4
    //         0054f1a0     ADD        ECX,0x4
    //         0054f1a3     MOV        dword ptr [ESP + 0x1c],EBP
    //         0054f1a7     MOV        dword ptr [ESP + 0x18],EAX
    //         0054f1ab     MOV        dword ptr [ESP + 0x14],ECX
    //                               LAB_0054f1af                                                 XREF[1]:     0054f18a(j)  
    //         0054f1af     LEA        ECX,[EDI + EBX*0x1]
    //         0054f1b2     CMP        ECX,ESI
    //         0054f1b4     JNC        LAB_0054f095
    //         0054f1ba     SUB        ESI,EBX
    //         0054f1bc     MOV        dword ptr [ESP + 0x10],ESI
    //         0054f1c0     JMP        LAB_0054f074
}

// Offset: 0x0054F1D0
undefined FUN_0054f1d0() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054f1d0()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054f1d0                                                 XREF[1]:     qsort:0054f08d(c)  
    //         0054f1d0     PUSH       EBX
    //         0054f1d1     MOV        EBX,dword ptr [ESP + Stack[0x4]]
    //         0054f1d5     PUSH       EDI
    //         0054f1d6     MOV        EDI,dword ptr [ESP + Stack[0x8]]
    //         0054f1da     CMP        EDI,EBX
    //         0054f1dc     JBE        LAB_0054f226
    //         0054f1de     PUSH       ESI
    //         0054f1df     PUSH       EBP
    //         0054f1e0     MOV        EBP,dword ptr [ESP + Stack[0xc]]
    //         0054f1e4     LEA        EAX,[EBP + EBX*0x1]
    //         0054f1e8     MOV        dword ptr [ESP + Stack[0x8]],EAX
    //         0054f1ec     JMP        LAB_0054f1f2
    //                               LAB_0054f1ee                                                 XREF[1]:     0054f222(j)  
    //         0054f1ee     MOV        EBX,dword ptr [ESP + 0x14]
    //                               LAB_0054f1f2                                                 XREF[1]:     0054f1ec(j)  
    //         0054f1f2     MOV        ESI,dword ptr [ESP + Stack[0x8]]
    //         0054f1f6     CMP        ESI,EDI
    //         0054f1f8     JA         LAB_0054f20f
    //                               LAB_0054f1fa                                                 XREF[1]:     0054f20d(j)  
    //         0054f1fa     PUSH       EBX
    //         0054f1fb     PUSH       ESI
    //         0054f1fc     CALL       dword ptr [ESP + Stack[0x10]]
    //         0054f200     ADD        ESP,0x8
    //         0054f203     TEST       EAX,EAX
    //         0054f205     JLE        LAB_0054f209
    //         0054f207     MOV        EBX,ESI
    //                               LAB_0054f209                                                 XREF[1]:     0054f205(j)  
    //         0054f209     ADD        ESI,EBP
    //         0054f20b     CMP        ESI,EDI
    //         0054f20d     JBE        LAB_0054f1fa
    //                               LAB_0054f20f                                                 XREF[1]:     0054f1f8(j)  
    //         0054f20f     PUSH       EBP
    //         0054f210     PUSH       EDI
    //         0054f211     PUSH       EBX
    //         0054f212     CALL       FUN_0054f230                                     undefined FUN_0054f230()
    //         0054f217     MOV        EAX,dword ptr [ESP + 0x20]
    //         0054f21b     SUB        EDI,EBP
    //         0054f21d     ADD        ESP,0xc
    //         0054f220     CMP        EDI,EAX
    //         0054f222     JA         LAB_0054f1ee
    //         0054f224     POP        EBP
    //         0054f225     POP        ESI
    //                               LAB_0054f226                                                 XREF[1]:     0054f1dc(j)  
    //         0054f226     POP        EDI
    //         0054f227     POP        EBX
    //         0054f228     RET
}

// Offset: 0x0054F230
undefined FUN_0054f230() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054f230()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054f230                                                 XREF[4]:     qsort:0054f0e2(c), 
    //                                                                                                         qsort:0054f125(c), 
    //                                                                                                         qsort:0054f130(c), 
    //                                                                                                         FUN_0054f1d0:0054f212(c)  
    //         0054f230     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054f234     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //         0054f238     CMP        EAX,ECX
    //         0054f23a     PUSH       ESI
    //         0054f23b     JZ         LAB_0054f25a
    //         0054f23d     MOV        EDX,dword ptr [ESP + Stack[0xc]]
    //         0054f241     MOV        ESI,EDX
    //         0054f243     DEC        EDX
    //         0054f244     TEST       ESI,ESI
    //         0054f246     JZ         LAB_0054f25a
    //         0054f248     PUSH       EBX
    //         0054f249     LEA        ESI,[EDX + 0x1]
    //                               LAB_0054f24c                                                 XREF[1]:     0054f257(j)  
    //         0054f24c     MOV        BL,byte ptr [ECX]
    //         0054f24e     MOV        DL,byte ptr [EAX]
    //         0054f250     MOV        byte ptr [EAX],BL
    //         0054f252     INC        EAX
    //         0054f253     MOV        byte ptr [ECX],DL
    //         0054f255     INC        ECX
    //         0054f256     DEC        ESI
    //         0054f257     JNZ        LAB_0054f24c
    //         0054f259     POP        EBX
    //                               LAB_0054f25a                                                 XREF[2]:     0054f23b(j), 0054f246(j)  
    //         0054f25a     POP        ESI
    //         0054f25b     RET
}

// Offset: 0x0054F260
undefined fseek() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * fseek                                                                                                 *
    //                              *********************************************************************************************************
    //                              undefined __cdecl fseek()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _fseek                                                       XREF[1]:     RESFILE_Extract_to_File:0047f54b(c
    //                               fseek
    //         0054f260     PUSH       ESI
    //         0054f261     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         0054f265     PUSH       EDI
    //         0054f266     MOV        EAX,dword ptr [ESI + 0xc]
    //         0054f269     TEST       AL,0x83
    //         0054f26b     JZ         LAB_0054f2e6
    //         0054f26d     MOV        EDI,dword ptr [ESP + Stack[0xc]]
    //         0054f271     TEST       EDI,EDI
    //         0054f273     JZ         LAB_0054f27f
    //         0054f275     CMP        EDI,0x1
    //         0054f278     JZ         LAB_0054f27f
    //         0054f27a     CMP        EDI,0x2
    //         0054f27d     JNZ        LAB_0054f2e6
    //                               LAB_0054f27f                                                 XREF[2]:     0054f273(j), 0054f278(j)  
    //         0054f27f     AND        AL,0xef
    //         0054f281     CMP        EDI,0x1
    //         0054f284     MOV        dword ptr [ESI + 0xc],EAX
    //         0054f287     JNZ        LAB_0054f29e
    //         0054f289     PUSH       ESI
    //         0054f28a     CALL       ftell                                            undefined ftell()
    //         0054f28f     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //         0054f293     ADD        ESP,0x4
    //         0054f296     ADD        ECX,EAX
    //         0054f298     XOR        EDI,EDI
    //         0054f29a     MOV        dword ptr [ESP + Stack[0x8]],ECX
    //                               LAB_0054f29e                                                 XREF[1]:     0054f287(j)  
    //         0054f29e     PUSH       ESI
    //         0054f29f     CALL       __flush                                          undefined __flush()
    //         0054f2a4     MOV        EAX,dword ptr [ESI + 0xc]
    //         0054f2a7     ADD        ESP,0x4
    //         0054f2aa     TEST       AL,0x80
    //         0054f2ac     JZ         LAB_0054f2b5
    //         0054f2ae     AND        AL,0xfc
    //         0054f2b0     MOV        dword ptr [ESI + 0xc],EAX
    //         0054f2b3     JMP        LAB_0054f2c9
    //                               LAB_0054f2b5                                                 XREF[1]:     0054f2ac(j)  
    //         0054f2b5     TEST       AL,0x1
    //         0054f2b7     JZ         LAB_0054f2c9
    //         0054f2b9     TEST       AL,0x8
    //         0054f2bb     JZ         LAB_0054f2c9
    //         0054f2bd     TEST       AH,0x4
    //         0054f2c0     JNZ        LAB_0054f2c9
    //         0054f2c2     MOV        dword ptr [ESI + 0x18],0x200
    //                               LAB_0054f2c9                                                 XREF[4]:     0054f2b3(j), 0054f2b7(j), 
    //                                                                                                         0054f2bb(j), 0054f2c0(j)  
    //         0054f2c9     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         0054f2cd     MOV        ECX,dword ptr [ESI + 0x10]
    //         0054f2d0     PUSH       EDI
    //         0054f2d1     PUSH       EAX
    //         0054f2d2     PUSH       ECX
    //         0054f2d3     CALL       lseek                                            undefined lseek()
    //         0054f2d8     ADD        ESP,0xc
    //         0054f2db     INC        EAX
    //         0054f2dc     NEG        EAX
    //         0054f2de     SBB        EAX,EAX
    //         0054f2e0     NEG        EAX
    //         0054f2e2     DEC        EAX
    //         0054f2e3     POP        EDI
    //         0054f2e4     POP        ESI
    //         0054f2e5     RET
    //                               LAB_0054f2e6                                                 XREF[2]:     0054f26b(j), 0054f27d(j)  
    //         0054f2e6     POP        EDI
    //         0054f2e7     MOV        dword ptr [_errno],0x16                          = align(4)
    //         0054f2f1     OR         EAX,0xffffffff
    //         0054f2f4     POP        ESI
    //         0054f2f5     RET
}

// Offset: 0x0054F300
undefined fwrite() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * fwrite                                                                                                *
    //                              *********************************************************************************************************
    //                              undefined __cdecl fwrite()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     0054f318(W), 0054f41c(R), 0054f434(R)  
    //                               _fwrite                                                      XREF[2]:     RESFILE_Extract_to_File:0047f53c(c
    //                               fwrite                                                                    fputs:0054d8ea(c)  
    //         0054f300     PUSH       ECX
    //         0054f301     PUSH       EBX
    //         0054f302     PUSH       EBP
    //         0054f303     MOV        EBP,dword ptr [ESP + Stack[0xc]]
    //         0054f307     PUSH       ESI
    //         0054f308     IMUL       EBP,dword ptr [ESP + Stack[0x8]]
    //         0054f30d     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         0054f311     PUSH       EDI
    //         0054f312     TEST       EBP,EBP
    //         0054f314     MOV        dword ptr [ESP + Stack[0x4]],ESI
    //         0054f318     MOV        dword ptr [ESP + local_4],EBP
    //         0054f31c     JNZ        LAB_0054f326
    //         0054f31e     XOR        EAX,EAX
    //         0054f320     POP        EDI
    //         0054f321     POP        ESI
    //         0054f322     POP        EBP
    //         0054f323     POP        EBX
    //         0054f324     POP        ECX
    //         0054f325     RET
    //                               LAB_0054f326                                                 XREF[1]:     0054f31c(j)  
    //         0054f326     MOV        EBX,dword ptr [ESP + Stack[0x10]]
    //         0054f32a     TEST       dword ptr [EBX + 0xc],0x10c
    //         0054f331     JZ         LAB_0054f33c
    //         0054f333     MOV        EDI,dword ptr [EBX + 0x18]
    //         0054f336     MOV        dword ptr [ESP + Stack[0x10]],EDI
    //         0054f33a     JMP        LAB_0054f348
    //                               LAB_0054f33c                                                 XREF[1]:     0054f331(j)  
    //         0054f33c     MOV        dword ptr [ESP + Stack[0x10]],0x1000
    //                               LAB_0054f344                                                 XREF[1]:     0054f409(j)  
    //         0054f344     MOV        EDI,dword ptr [ESP + Stack[0x10]]
    //                               LAB_0054f348                                                 XREF[1]:     0054f33a(j)  
    //         0054f348     MOV        ECX,dword ptr [EBX + 0xc]
    //         0054f34b     AND        ECX,0x108
    //         0054f351     JZ         LAB_0054f390
    //         0054f353     MOV        EAX,dword ptr [EBX + 0x4]
    //         0054f356     TEST       EAX,EAX
    //         0054f358     JZ         LAB_0054f390
    //         0054f35a     CMP        EBP,EAX
    //         0054f35c     JNC        LAB_0054f360
    //         0054f35e     MOV        EAX,EBP
    //                               LAB_0054f360                                                 XREF[1]:     0054f35c(j)  
    //         0054f360     MOV        EDI,dword ptr [EBX]
    //         0054f362     MOV        ECX,EAX
    //         0054f364     MOV        EDX,ECX
    //         0054f366     SUB        EBP,EAX
    //         0054f368     SHR        ECX,0x2
    //         0054f36b     MOVSD.REP  ES:EDI,ESI
    //         0054f36d     MOV        ECX,EDX
    //         0054f36f     AND        ECX,0x3
    //         0054f372     MOVSB.REP  ES:EDI,ESI
    //         0054f374     MOV        ESI,dword ptr [EBX + 0x4]
    //         0054f377     MOV        EDX,dword ptr [EBX]
    //         0054f379     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         0054f37d     SUB        ESI,EAX
    //         0054f37f     ADD        EDX,EAX
    //         0054f381     ADD        ECX,EAX
    //         0054f383     MOV        dword ptr [EBX + 0x4],ESI
    //         0054f386     MOV        dword ptr [EBX],EDX
    //         0054f388     MOV        dword ptr [ESP + Stack[0x4]],ECX
    //         0054f38c     MOV        ESI,ECX
    //         0054f38e     JMP        LAB_0054f407
    //                               LAB_0054f390                                                 XREF[2]:     0054f351(j), 0054f358(j)  
    //         0054f390     CMP        EBP,EDI
    //         0054f392     JC         LAB_0054f3dc
    //         0054f394     TEST       ECX,ECX
    //         0054f396     JZ         LAB_0054f3a9
    //         0054f398     PUSH       EBX
    //         0054f399     CALL       __flush                                          undefined __flush()
    //         0054f39e     ADD        ESP,0x4
    //         0054f3a1     TEST       EAX,EAX
    //         0054f3a3     JNZ        LAB_0054f434
    //                               LAB_0054f3a9                                                 XREF[1]:     0054f396(j)  
    //         0054f3a9     TEST       EDI,EDI
    //         0054f3ab     JZ         LAB_0054f3b9
    //         0054f3ad     MOV        EAX,EBP
    //         0054f3af     XOR        EDX,EDX
    //         0054f3b1     DIV        EDI
    //         0054f3b3     MOV        EDI,EBP
    //         0054f3b5     SUB        EDI,EDX
    //         0054f3b7     JMP        LAB_0054f3bb
    //                               LAB_0054f3b9                                                 XREF[1]:     0054f3ab(j)  
    //         0054f3b9     MOV        EDI,EBP
    //                               LAB_0054f3bb                                                 XREF[1]:     0054f3b7(j)  
    //         0054f3bb     MOV        EAX,dword ptr [EBX + 0x10]
    //         0054f3be     PUSH       EDI
    //         0054f3bf     PUSH       ESI
    //         0054f3c0     PUSH       EAX
    //         0054f3c1     CALL       write                                            undefined write()
    //         0054f3c6     ADD        ESP,0xc
    //         0054f3c9     CMP        EAX,-0x1
    //         0054f3cc     JZ         LAB_0054f419
    //         0054f3ce     SUB        EBP,EAX
    //         0054f3d0     ADD        ESI,EAX
    //         0054f3d2     CMP        EAX,EDI
    //         0054f3d4     MOV        dword ptr [ESP + Stack[0x4]],ESI
    //         0054f3d8     JC         LAB_0054f419
    //         0054f3da     JMP        LAB_0054f407
    //                               LAB_0054f3dc                                                 XREF[1]:     0054f392(j)  
    //         0054f3dc     MOVSX      ECX,byte ptr [ESI]
    //         0054f3df     PUSH       EBX
    //         0054f3e0     PUSH       ECX
    //         0054f3e1     CALL       __flsbuf                                         undefined __flsbuf()
    //         0054f3e6     ADD        ESP,0x8
    //         0054f3e9     CMP        EAX,-0x1
    //         0054f3ec     JZ         LAB_0054f434
    //         0054f3ee     MOV        EAX,dword ptr [EBX + 0x18]
    //         0054f3f1     INC        ESI
    //         0054f3f2     DEC        EBP
    //         0054f3f3     MOV        dword ptr [ESP + Stack[0x4]],ESI
    //         0054f3f7     TEST       EAX,EAX
    //         0054f3f9     MOV        dword ptr [ESP + Stack[0x10]],EAX
    //         0054f3fd     JG         LAB_0054f407
    //         0054f3ff     MOV        dword ptr [ESP + Stack[0x10]],0x1
    //                               LAB_0054f407                                                 XREF[3]:     0054f38e(j), 0054f3da(j), 
    //                                                                                                         0054f3fd(j)  
    //         0054f407     TEST       EBP,EBP
    //         0054f409     JNZ        LAB_0054f344
    //         0054f40f     MOV        EAX,dword ptr [ESP + Stack[0xc]]
    //         0054f413     POP        EDI
    //         0054f414     POP        ESI
    //         0054f415     POP        EBP
    //         0054f416     POP        EBX
    //         0054f417     POP        ECX
    //         0054f418     RET
    //                               LAB_0054f419                                                 XREF[2]:     0054f3cc(j), 0054f3d8(j)  
    //         0054f419     MOV        EDX,dword ptr [EBX + 0xc]
    //         0054f41c     MOV        EAX,dword ptr [ESP + local_4]
    //         0054f420     OR         EDX,0x20
    //         0054f423     SUB        EAX,EBP
    //         0054f425     MOV        dword ptr [EBX + 0xc],EDX
    //         0054f428     XOR        EDX,EDX
    //         0054f42a     DIV        dword ptr [ESP + Stack[0x8]]
    //         0054f42e     POP        EDI
    //         0054f42f     POP        ESI
    //         0054f430     POP        EBP
    //         0054f431     POP        EBX
    //         0054f432     POP        ECX
    //         0054f433     RET
    //                               LAB_0054f434                                                 XREF[2]:     0054f3a3(j), 0054f3ec(j)  
    //         0054f434     MOV        EAX,dword ptr [ESP + local_4]
    //         0054f438     XOR        EDX,EDX
    //         0054f43a     SUB        EAX,EBP
    //         0054f43c     DIV        dword ptr [ESP + Stack[0x8]]
    //         0054f440     POP        EDI
    //         0054f441     POP        ESI
    //         0054f442     POP        EBP
    //         0054f443     POP        EBX
    //         0054f444     POP        ECX
    //         0054f445     RET
}

// Offset: 0x0054F450
undefined ceil() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * ceil                                                                                                  *
    //                              *********************************************************************************************************
    //                              undefined __cdecl ceil()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined8        Stack[-0x8]:8  local_8                   XREF[4,1]:   0054f4f5(W), 0054f4f9(R), 0054f51b(R), 0054f52d(R), 
    //                                                                                     0054f529(R)  
    //              undefined8        Stack[-0x20]:8 local_20                  XREF[1]:     0054f4d8(*)  
    //                               _ceil                                                        XREF[10]:    changeInfluenceMap:004c6de0(c), 
    //                               ceil                                                                      changeInfluenceMap:004c6e43(c), 
    //                                                                                                         changeInfluenceMap:004c6e87(c), 
    //                                                                                                         evaluateCivilianDistribution:004f1
    //                                                                                                         setupSoldierGroups:004fc181(c), 
    //                                                                                                         setupSoldierGroups:004fc1d1(c), 
    //                                                                                                         setupSoldierGroups:004fc21d(c), 
    //                                                                                                         setupBoatGroups:004fe621(c), 
    //                                                                                                         setupBoatGroups:004fe671(c), 
    //                                                                                                         setupBoatGroups:004fe6bd(c)  
    //         0054f450     MOV        EAX,[DAT_0058fba0]                               = 00001B3Fh
    //         0054f455     SUB        ESP,0x8
    //         0054f458     PUSH       EBX
    //         0054f459     PUSH       ESI
    //         0054f45a     PUSH       EDI
    //         0054f45b     PUSH       0xffff
    //         0054f460     PUSH       EAX
    //         0054f461     CALL       __ctrlfp                                         undefined __ctrlfp()
    //         0054f466     MOV        ECX,dword ptr [ESP + Stack[0xa]]
    //         0054f46a     MOV        ESI,dword ptr [ESP + Stack[0x8]]
    //         0054f46e     MOV        EDI,dword ptr [ESP + Stack[0x4]]
    //         0054f472     ADD        ESP,0x8
    //         0054f475     AND        ECX,0x7ff0
    //         0054f47b     MOV        EBX,EAX
    //         0054f47d     CMP        ECX,0x7ff0
    //         0054f483     PUSH       ESI
    //         0054f484     PUSH       EDI
    //         0054f485     JNZ        LAB_0054f4f0
    //         0054f487     CALL       __sptype                                         undefined __sptype()
    //         0054f48c     ADD        ESP,0x8
    //         0054f48f     TEST       EAX,EAX
    //         0054f491     JLE        LAB_0054f4ca
    //         0054f493     CMP        EAX,0x2
    //         0054f496     JLE        LAB_0054f4b1
    //         0054f498     CMP        EAX,0x3
    //         0054f49b     JNZ        LAB_0054f4ca
    //         0054f49d     PUSH       EBX
    //         0054f49e     PUSH       ESI
    //         0054f49f     PUSH       EDI
    //         0054f4a0     PUSH       0xc
    //         0054f4a2     CALL       __handle_qnan1                                   undefined __handle_qnan1()
    //         0054f4a7     ADD        ESP,0x10
    //         0054f4aa     POP        EDI
    //         0054f4ab     POP        ESI
    //         0054f4ac     POP        EBX
    //         0054f4ad     ADD        ESP,0x8
    //         0054f4b0     RET
    //                               LAB_0054f4b1                                                 XREF[1]:     0054f496(j)  
    //         0054f4b1     PUSH       0xffff
    //         0054f4b6     PUSH       EBX
    //         0054f4b7     CALL       __ctrlfp                                         undefined __ctrlfp()
    //         0054f4bc     FLD        double ptr [ESP + Stack[0x4]]
    //         0054f4c0     ADD        ESP,0x8
    //         0054f4c3     POP        EDI
    //         0054f4c4     POP        ESI
    //         0054f4c5     POP        EBX
    //         0054f4c6     ADD        ESP,0x8
    //         0054f4c9     RET
    //                               LAB_0054f4ca                                                 XREF[2]:     0054f491(j), 0054f49b(j)  
    //         0054f4ca     FLD        double ptr [ESP + Stack[0x4]]
    //         0054f4ce     FSUB       double ptr [DAT_00577a90]
    //         0054f4d4     PUSH       EBX
    //         0054f4d5     SUB        ESP,0x8
    //         0054f4d8     FSTP       double ptr [ESP]=>local_20
    //         0054f4db     PUSH       ESI
    //         0054f4dc     PUSH       EDI
    //         0054f4dd     PUSH       0xc
    //         0054f4df     PUSH       0x8
    //         0054f4e1     CALL       __except1                                        undefined __except1()
    //         0054f4e6     ADD        ESP,0x1c
    //         0054f4e9     POP        EDI
    //         0054f4ea     POP        ESI
    //         0054f4eb     POP        EBX
    //         0054f4ec     ADD        ESP,0x8
    //         0054f4ef     RET
    //                               LAB_0054f4f0                                                 XREF[1]:     0054f485(j)  
    //         0054f4f0     CALL       __frnd                                           undefined __frnd()
    //         0054f4f5     FSTP       double ptr [ESP + local_8]
    //         0054f4f9     FLD        double ptr [ESP + local_8]
    //         0054f4fd     FCOMP      double ptr [ESP + Stack[0x4]]
    //         0054f501     ADD        ESP,0x8
    //         0054f504     FNSTSW     AX
    //         0054f506     TEST       AH,0x40
    //         0054f509     JNZ        LAB_0054f510
    //         0054f50b     TEST       BL,0x20
    //         0054f50e     JZ         LAB_0054f529
    //                               LAB_0054f510                                                 XREF[1]:     0054f509(j)  
    //         0054f510     PUSH       0xffff
    //         0054f515     PUSH       EBX
    //         0054f516     CALL       __ctrlfp                                         undefined __ctrlfp()
    //         0054f51b     FLD        double ptr [ESP + local_8]
    //         0054f51f     ADD        ESP,0x8
    //         0054f522     POP        EDI
    //         0054f523     POP        ESI
    //         0054f524     POP        EBX
    //         0054f525     ADD        ESP,0x8
    //         0054f528     RET
    //                               LAB_0054f529                                                 XREF[1]:     0054f50e(j)  
    //         0054f529     MOV        EDX,dword ptr [ESP + local_8+0x4]
    //         0054f52d     MOV        EAX,dword ptr [ESP + local_8]
    //         0054f531     PUSH       EBX
    //         0054f532     PUSH       EDX
    //         0054f533     PUSH       EAX
    //         0054f534     PUSH       ESI
    //         0054f535     PUSH       EDI
    //         0054f536     PUSH       0xc
    //         0054f538     PUSH       0x10
    //         0054f53a     CALL       __except1                                        undefined __except1()
    //         0054f53f     ADD        ESP,0x1c
    //         0054f542     POP        EDI
    //         0054f543     POP        ESI
    //         0054f544     POP        EBX
    //         0054f545     ADD        ESP,0x8
    //         0054f548     RET
}

// Offset: 0x0054F550
undefined strnicmp() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __strnicmp()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __strnicmp                                                   XREF[2]:     PlayTauntStr:005094b0(c), 
    //                                                                                                         PlayTauntStr:005094e4(c)  
    //         0054f550     PUSH       EBP
    //         0054f551     MOV        EBP,ESP
    //         0054f553     PUSH       EDI
    //         0054f554     PUSH       ESI
    //         0054f555     PUSH       EBX
    //         0054f556     MOV        ECX,dword ptr [EBP + Stack[0xc]]
    //         0054f559     OR         ECX,ECX
    //         0054f55b     JZ         LAB_0054f5f6
    //         0054f561     MOV        ESI,dword ptr [EBP + Stack[0x4]]
    //         0054f564     MOV        EDI,dword ptr [EBP + Stack[0x8]]
    //         0054f567     LEA        EAX,[___lc_handle]                               = align(8)
    //         0054f56d     CMP        dword ptr [EAX + 0x8]=>DAT_008882c0,0x0
    //         0054f571     JNZ        LAB_0054f5b6
    //         0054f573     MOV        BH,0x41
    //         0054f575     MOV        BL,0x5a
    //         0054f577     MOV        DH,0x20
    //         0054f579     MOV        EAX,EAX
    //                               LAB_0054f57c                                                 XREF[1]:     0054f5a3(j)  
    //         0054f57c     MOV        AH,byte ptr [ESI]
    //         0054f57e     OR         AH,AH
    //         0054f580     MOV        AL,byte ptr [EDI]
    //         0054f582     JZ         LAB_0054f5a5
    //         0054f584     OR         AL,AL
    //         0054f586     JZ         LAB_0054f5a5
    //         0054f588     INC        ESI
    //         0054f589     INC        EDI
    //         0054f58a     CMP        AH,BH
    //         0054f58c     JC         LAB_0054f594
    //         0054f58e     CMP        AH,BL
    //         0054f590     JA         LAB_0054f594
    //         0054f592     ADD        AH,DH
    //                               LAB_0054f594                                                 XREF[2]:     0054f58c(j), 0054f590(j)  
    //         0054f594     CMP        AL,BH
    //         0054f596     JC         LAB_0054f59e
    //         0054f598     CMP        AL,BL
    //         0054f59a     JA         LAB_0054f59e
    //         0054f59c     ADD        AL,DH
    //                               LAB_0054f59e                                                 XREF[2]:     0054f596(j), 0054f59a(j)  
    //         0054f59e     CMP        AH,AL
    //         0054f5a0     JNZ        LAB_0054f5ab
    //         0054f5a2     DEC        ECX
    //         0054f5a3     JNZ        LAB_0054f57c
    //                               LAB_0054f5a5                                                 XREF[2]:     0054f582(j), 0054f586(j)  
    //         0054f5a5     XOR        ECX,ECX
    //         0054f5a7     CMP        AH,AL
    //         0054f5a9     JZ         LAB_0054f5f6
    //                               LAB_0054f5ab                                                 XREF[1]:     0054f5a0(j)  
    //         0054f5ab     MOV        ECX,0xffffffff
    //         0054f5b0     JC         LAB_0054f5f6
    //         0054f5b2     NEG        ECX
    //         0054f5b4     JMP        LAB_0054f5f6
    //                               LAB_0054f5b6                                                 XREF[1]:     0054f571(j)  
    //         0054f5b6     XOR        EAX,EAX
    //         0054f5b8     XOR        EBX,EBX
    //         0054f5ba     MOV        EAX,EAX
    //                               LAB_0054f5bc                                                 XREF[1]:     0054f5e5(j)  
    //         0054f5bc     MOV        AL,byte ptr [ESI]
    //         0054f5be     OR         EAX,EAX
    //         0054f5c0     MOV        BL,byte ptr [EDI]
    //         0054f5c2     JZ         LAB_0054f5e7
    //         0054f5c4     OR         EBX,EBX
    //         0054f5c6     JZ         LAB_0054f5e7
    //         0054f5c8     INC        ESI
    //         0054f5c9     INC        EDI
    //         0054f5ca     PUSH       ECX
    //         0054f5cb     PUSH       EAX
    //         0054f5cc     PUSH       EBX
    //         0054f5cd     CALL       tolower                                          undefined tolower()
    //         0054f5d2     MOV        EBX,EAX
    //         0054f5d4     ADD        ESP,0x4
    //         0054f5d7     CALL       tolower                                          undefined tolower()
    //         0054f5dc     ADD        ESP,0x4
    //         0054f5df     POP        ECX
    //         0054f5e0     CMP        EAX,EBX
    //         0054f5e2     JNZ        LAB_0054f5ed
    //         0054f5e4     DEC        ECX
    //         0054f5e5     JNZ        LAB_0054f5bc
    //                               LAB_0054f5e7                                                 XREF[2]:     0054f5c2(j), 0054f5c6(j)  
    //         0054f5e7     XOR        ECX,ECX
    //         0054f5e9     CMP        EAX,EBX
    //         0054f5eb     JZ         LAB_0054f5f6
    //                               LAB_0054f5ed                                                 XREF[1]:     0054f5e2(j)  
    //         0054f5ed     MOV        ECX,0xffffffff
    //         0054f5f2     JC         LAB_0054f5f6
    //         0054f5f4     NEG        ECX
    //                               LAB_0054f5f6                                                 XREF[6]:     0054f55b(j), 0054f5a9(j), 
    //                                                                                                         0054f5b0(j), 0054f5b4(j), 
    //                                                                                                         0054f5eb(j), 0054f5f2(j)  
    //         0054f5f6     MOV        EAX,ECX
    //         0054f5f8     POP        EBX
    //         0054f5f9     POP        ESI
    //         0054f5fa     POP        EDI
    //         0054f5fb     LEAVE
    //         0054f5fc     RET
}

// Offset: 0x0054F600
undefined strlen() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * strlen                                                                                                *
    //                              *********************************************************************************************************
    //                              undefined __cdecl strlen()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _strlen                                                      XREF[2]:     TRIBE_Tech:0050bd10(c), 
    //                               strlen                                                                    save:0050c054(c)  
    //         0054f600     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         0054f604     TEST       ECX,0x3
    //         0054f60a     JZ         LAB_0054f620
    //                               LAB_0054f60c                                                 XREF[1]:     0054f619(j)  
    //         0054f60c     MOV        AL,byte ptr [ECX]
    //         0054f60e     INC        ECX
    //         0054f60f     TEST       AL,AL
    //         0054f611     JZ         LAB_0054f653
    //         0054f613     TEST       ECX,0x3
    //         0054f619     JNZ        LAB_0054f60c
    //         0054f61b     ADD        EAX,0x0
    //                               LAB_0054f620                                                 XREF[3]:     0054f60a(j), 0054f636(j), 
    //                                                                                                         0054f651(j)  
    //         0054f620     MOV        EAX,dword ptr [ECX]
    //         0054f622     MOV        EDX,0x7efefeff
    //         0054f627     ADD        EDX,EAX
    //         0054f629     XOR        EAX,0xffffffff
    //         0054f62c     XOR        EAX,EDX
    //         0054f62e     ADD        ECX,0x4
    //         0054f631     TEST       EAX,0x81010100
    //         0054f636     JZ         LAB_0054f620
    //         0054f638     MOV        EAX,dword ptr [ECX + -0x4]
    //         0054f63b     TEST       AL,AL
    //         0054f63d     JZ         LAB_0054f671
    //         0054f63f     TEST       AH,AH
    //         0054f641     JZ         LAB_0054f667
    //         0054f643     TEST       EAX,0xff0000
    //         0054f648     JZ         LAB_0054f65d
    //         0054f64a     TEST       EAX,0xff000000
    //         0054f64f     JZ         LAB_0054f653
    //         0054f651     JMP        LAB_0054f620
    //                               LAB_0054f653                                                 XREF[2]:     0054f611(j), 0054f64f(j)  
    //         0054f653     LEA        EAX,[ECX + -0x1]
    //         0054f656     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         0054f65a     SUB        EAX,ECX
    //         0054f65c     RET
    //                               LAB_0054f65d                                                 XREF[1]:     0054f648(j)  
    //         0054f65d     LEA        EAX,[ECX + -0x2]
    //         0054f660     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         0054f664     SUB        EAX,ECX
    //         0054f666     RET
    //                               LAB_0054f667                                                 XREF[1]:     0054f641(j)  
    //         0054f667     LEA        EAX,[ECX + -0x3]
    //         0054f66a     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         0054f66e     SUB        EAX,ECX
    //         0054f670     RET
    //                               LAB_0054f671                                                 XREF[1]:     0054f63d(j)  
    //         0054f671     LEA        EAX,[ECX + -0x4]
    //         0054f674     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         0054f678     SUB        EAX,ECX
    //         0054f67a     RET
}

// Offset: 0x0054F680
undefined cinit() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __cinit()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __cinit                                                      XREF[1]:     entry:0054f921(c)  
    //         0054f680     MOV        EAX,[->__fpmath]                                 = 0054b670
    //         0054f685     TEST       EAX,EAX
    //         0054f687     JZ         LAB_0054f68b
    //         0054f689     CALL       EAX=>__fpmath                                    undefined __fpmath()
    //                               LAB_0054f68b                                                 XREF[1]:     0054f687(j)  
    //         0054f68b     PUSH       ___xi_z
    //         0054f690     PUSH       offset DAT_fffffff8
    //         0054f695     CALL       FUN_0054f7c0                                     undefined FUN_0054f7c0()
    //         0054f69a     ADD        ESP,0x8
    //         0054f69d     PUSH       ___xc_z
    //         0054f6a2     PUSH       offset DAT_fffffff8
    //         0054f6a7     CALL       FUN_0054f7c0                                     undefined FUN_0054f7c0()
    //         0054f6ac     ADD        ESP,0x8
    //         0054f6af     RET
}

// Offset: 0x0054F6B0
undefined exit() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined _exit()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _exit                                                        XREF[2]:     entry:0054f90f(c), 
    //                                                                                                         entry:0054f9b3(c)  
    //         0054f6b0     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054f6b4     PUSH       0x0
    //         0054f6b6     PUSH       0x0
    //         0054f6b8     PUSH       EAX
    //         0054f6b9     CALL       FUN_0054f710                                     undefined FUN_0054f710()
    //         0054f6be     ADD        ESP,0xc
    //         0054f6c1     RET
}

// Offset: 0x0054F6D0
undefined exit() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __exit()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __exit                                                       XREF[5]:     FUN_0054f9cf:0054f9d6(c), 
    //                                                                                                         __amsg_exit:0054fa30(c), 
    //                                                                                                         abort:00557706(c), 
    //                                                                                                         raise:005593c9(c), 0058fbb0(*)  
    //         0054f6d0     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054f6d4     PUSH       0x0
    //         0054f6d6     PUSH       0x1
    //         0054f6d8     PUSH       EAX
    //         0054f6d9     CALL       FUN_0054f710                                     undefined FUN_0054f710()
    //         0054f6de     ADD        ESP,0xc
    //         0054f6e1     RET
}

// Offset: 0x0054F6E2
undefined FUN_0054f6e2() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054f6e2()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054f6e2
    //         0054f6e2     NOP
    //         0054f6e3     NOP
    //         0054f6e4     NOP
    //         0054f6e5     NOP
    //         0054f6e6     NOP
    //         0054f6e7     NOP
    //         0054f6e8     NOP
    //         0054f6e9     NOP
    //         0054f6ea     NOP
    //         0054f6eb     NOP
    //         0054f6ec     NOP
    //         0054f6ed     NOP
    //         0054f6ee     NOP
    //         0054f6ef     NOP
    //                               __cexit
    //         0054f6f0     PUSH       0x1
    //         0054f6f2     PUSH       0x0
    //         0054f6f4     PUSH       0x0
    //         0054f6f6     CALL       FUN_0054f710                                     undefined FUN_0054f710()
    //         0054f6fb     ADD        ESP,0xc
    //         0054f6fe     RET
}

// Offset: 0x0054F6FF
undefined FUN_0054f6ff() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054f6ff()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054f6ff
    //         0054f6ff     NOP
    //                               __c_exit
    //         0054f700     PUSH       0x1
    //         0054f702     PUSH       0x1
    //         0054f704     PUSH       0x0
    //         0054f706     CALL       FUN_0054f710                                     undefined FUN_0054f710()
    //         0054f70b     ADD        ESP,0xc
    //         0054f70e     RET
}

// Offset: 0x0054F710
undefined FUN_0054f710() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054f710()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054f710                                                 XREF[4]:     _exit:0054f6b9(c), 
    //                                                                                                         __exit:0054f6d9(c), 
    //                                                                                                         FUN_0054f6e2:0054f6f6(c), 
    //                                                                                                         FUN_0054f6ff:0054f706(c)  
    //         0054f710     MOV        EAX,[__C_Exit_Done]
    //         0054f715     PUSH       EBX
    //         0054f716     PUSH       EBP
    //         0054f717     MOV        EBP,dword ptr [ESP + Stack[0x4]]
    //         0054f71b     CMP        EAX,0x1
    //         0054f71e     PUSH       ESI
    //         0054f71f     JNZ        LAB_0054f72f
    //         0054f721     PUSH       EBP
    //         0054f722     CALL       dword ptr [->KERNEL32.DLL::GetCurrentProcess]    = 0048b7d6
    //         0054f728     PUSH       EAX
    //         0054f729     CALL       dword ptr [->KERNEL32.DLL::TerminateProcess]     = 0048b7c2
    //                               LAB_0054f72f                                                 XREF[1]:     0054f71f(j)  
    //         0054f72f     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         0054f733     MOV        EBX,dword ptr [ESP + Stack[0xc]]
    //         0054f737     TEST       EAX,EAX
    //         0054f739     MOV        dword ptr [__C_Termination_Done],0x1             = align(4)
    //         0054f743     MOV        byte ptr [__exitflag],BL                         = align(8)
    //         0054f749     JNZ        LAB_0054f789
    //         0054f74b     MOV        ECX,dword ptr [___onexitbegin]
    //         0054f751     TEST       ECX,ECX
    //         0054f753     JZ         LAB_0054f777
    //         0054f755     MOV        ESI,dword ptr [___onexitend]
    //         0054f75b     SUB        ESI,0x4
    //         0054f75e     CMP        ESI,ECX
    //         0054f760     JC         LAB_0054f777
    //                               LAB_0054f762                                                 XREF[1]:     0054f775(j)  
    //         0054f762     MOV        EAX,dword ptr [ESI]
    //         0054f764     TEST       EAX,EAX
    //         0054f766     JZ         LAB_0054f770
    //         0054f768     CALL       EAX
    //         0054f76a     MOV        ECX,dword ptr [___onexitbegin]
    //                               LAB_0054f770                                                 XREF[1]:     0054f766(j)  
    //         0054f770     SUB        ESI,0x4
    //         0054f773     CMP        ESI,ECX
    //         0054f775     JNC        LAB_0054f762
    //                               LAB_0054f777                                                 XREF[2]:     0054f753(j), 0054f760(j)  
    //         0054f777     PUSH       ___xp_z
    //         0054f77c     PUSH       ___xp_a
    //         0054f781     CALL       FUN_0054f7c0                                     undefined FUN_0054f7c0()
    //         0054f786     ADD        ESP,0x8
    //                               LAB_0054f789                                                 XREF[1]:     0054f749(j)  
    //         0054f789     PUSH       ___xt_z
    //         0054f78e     PUSH       ___xt_a
    //         0054f793     CALL       FUN_0054f7c0                                     undefined FUN_0054f7c0()
    //         0054f798     ADD        ESP,0x8
    //         0054f79b     TEST       EBX,EBX
    //         0054f79d     JNZ        LAB_0054f7b0
    //         0054f79f     PUSH       EBP
    //         0054f7a0     MOV        dword ptr [__C_Exit_Done],0x1
    //         0054f7aa     CALL       dword ptr [->KERNEL32.DLL::ExitProcess]          = 0048b7b4
    //                               LAB_0054f7b0                                                 XREF[1]:     0054f79d(j)  
    //         0054f7b0     POP        ESI
    //         0054f7b1     POP        EBP
    //         0054f7b2     POP        EBX
    //         0054f7b3     RET
}

// Offset: 0x0054F7C0
undefined FUN_0054f7c0() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054f7c0()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054f7c0                                                 XREF[4]:     __cinit:0054f695(c), 
    //                                                                                                         __cinit:0054f6a7(c), 
    //                                                                                                         FUN_0054f710:0054f781(c), 
    //                                                                                                         FUN_0054f710:0054f793(c)  
    //         0054f7c0     PUSH       ESI
    //         0054f7c1     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         0054f7c5     PUSH       EDI
    //         0054f7c6     MOV        EDI,dword ptr [ESP + Stack[0x8]]
    //         0054f7ca     CMP        ESI,EDI
    //         0054f7cc     JNC        LAB_0054f7dd
    //                               LAB_0054f7ce                                                 XREF[1]:     0054f7db(j)  
    //         0054f7ce     MOV        EAX,dword ptr [ESI]
    //         0054f7d0     TEST       EAX,EAX
    //         0054f7d2     JZ         LAB_0054f7d6
    //         0054f7d4     CALL       EAX
    //                               LAB_0054f7d6                                                 XREF[1]:     0054f7d2(j)  
    //         0054f7d6     ADD        ESI,0x4
    //         0054f7d9     CMP        ESI,EDI
    //         0054f7db     JC         LAB_0054f7ce
    //                               LAB_0054f7dd                                                 XREF[1]:     0054f7cc(j)  
    //         0054f7dd     POP        EDI
    //         0054f7de     POP        ESI
    //         0054f7df     RET
}

// Offset: 0x0054F7E0
undefined mbsupr() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __mbsupr()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __mbsupr                                                     XREF[1]:     processCheatCode:00527ada(c)  
    //         0054f7e0     PUSH       EBX
    //         0054f7e1     PUSH       ESI
    //         0054f7e2     PUSH       EDI
    //         0054f7e3     MOV        EDI,dword ptr [ESP + Stack[0x4]]
    //         0054f7e7     MOV        ESI,EDI
    //         0054f7e9     CMP        byte ptr [EDI],0x0
    //         0054f7ec     JZ         LAB_0054f85c
    //         0054f7ee     MOV        BL,0x4
    //                               LAB_0054f7f0                                                 XREF[1]:     0054f84e(j)  
    //         0054f7f0     MOV        CL,byte ptr [ESI]
    //         0054f7f2     MOV        EAX,ECX
    //         0054f7f4     AND        EAX,0xff
    //         0054f7f9     TEST       byte ptr [EAX + __mbctype+1],BL
    //         0054f7ff     JZ         LAB_0054f839
    //         0054f801     MOV        EAX,[___mbcodepage]
    //         0054f806     MOV        EDX,dword ptr [___mblcid]
    //         0054f80c     PUSH       EAX
    //         0054f80d     LEA        ECX=>Stack[0x4],[ESP + 0x14]
    //         0054f811     PUSH       0x2
    //         0054f813     PUSH       ECX
    //         0054f814     PUSH       0x2
    //         0054f816     PUSH       ESI
    //         0054f817     PUSH       0x200
    //         0054f81c     PUSH       EDX
    //         0054f81d     CALL       ___crtLCMapStringA                               undefined ___crtLCMapStringA()
    //         0054f822     ADD        ESP,0x1c
    //         0054f825     TEST       EAX,EAX
    //         0054f827     JZ         LAB_0054f856
    //         0054f829     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         0054f82d     CMP        EAX,0x1
    //         0054f830     MOV        byte ptr [ESI],CL
    //         0054f832     JLE        LAB_0054f848
    //         0054f834     INC        ESI
    //         0054f835     MOV        byte ptr [ESI],CH
    //         0054f837     JMP        LAB_0054f848
    //                               LAB_0054f839                                                 XREF[1]:     0054f7ff(j)  
    //         0054f839     CMP        CL,0x61
    //         0054f83c     JC         LAB_0054f846
    //         0054f83e     CMP        CL,0x7a
    //         0054f841     JA         LAB_0054f846
    //         0054f843     ADD        EAX,-0x20
    //                               LAB_0054f846                                                 XREF[2]:     0054f83c(j), 0054f841(j)  
    //         0054f846     MOV        byte ptr [ESI],AL
    //                               LAB_0054f848                                                 XREF[2]:     0054f832(j), 0054f837(j)  
    //         0054f848     MOV        AL,byte ptr [ESI + 0x1]
    //         0054f84b     INC        ESI
    //         0054f84c     TEST       AL,AL
    //         0054f84e     JNZ        LAB_0054f7f0
    //         0054f850     MOV        EAX,EDI
    //         0054f852     POP        EDI
    //         0054f853     POP        ESI
    //         0054f854     POP        EBX
    //         0054f855     RET
    //                               LAB_0054f856                                                 XREF[1]:     0054f827(j)  
    //         0054f856     XOR        EAX,EAX
    //         0054f858     POP        EDI
    //         0054f859     POP        ESI
    //         0054f85a     POP        EBX
    //         0054f85b     RET
    //                               LAB_0054f85c                                                 XREF[1]:     0054f7ec(j)  
    //         0054f85c     MOV        EAX,EDI
    //         0054f85e     POP        EDI
    //         0054f85f     POP        ESI
    //         0054f860     POP        EBX
    //         0054f861     RET
}

// Offset: 0x0054F870
undefined entry() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined entry()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[1]:     0054f8da(W)  
    //              undefined4        Stack[-0x1c]:4 local_1c                  XREF[1]:     0054f893(W)  
    //              undefined4        Stack[-0x30]:4 local_30                  XREF[1]:     0054f98e(R)  
    //              undefined4        Stack[-0x34]:4 local_34                  XREF[2]:     0054f977(W), 0054f988(R)  
    //              undefined         Stack[-0x60]:1 local_60                  XREF[1]:     0054f97e(*)  
    //              undefined4        Stack[-0x64]:4 local_64                  XREF[1]:     0054f9af(W)  
    //              undefined4        Stack[-0x68]:4 local_68                  XREF[6]:     0054f92c(W), 0054f939(W), 0054f959(W), 0054f964(W), 
    //                                                                                     0054f972(W), 0054fa00(W)  
    //                               _WinMainCRTStartup                                           XREF[2]:     Entry Point(*), 004000a8(*)  
    //                               entry
    //         0054f870     PUSH       EBP
    //         0054f871     MOV        EBP,ESP
    //         0054f873     PUSH       -0x1
    //         0054f875     PUSH       DAT_00577a98                                     = FFh
    //         0054f87a     PUSH       __except_handler3
    //         0054f87f     MOV        EAX,FS:[0x0]
    //         0054f885     PUSH       EAX
    //         0054f886     MOV        dword ptr FS:[0x0],ESP
    //         0054f88d     ADD        ESP,-0x58
    //         0054f890     PUSH       EBX
    //         0054f891     PUSH       ESI
    //         0054f892     PUSH       EDI
    //         0054f893     MOV        dword ptr [EBP + local_1c],ESP
    //         0054f896     CALL       dword ptr [->KERNEL32.DLL::GetVersion]           = 0048b80e
    //         0054f89c     XOR        EDX,EDX
    //         0054f89e     MOV        DL,AH
    //         0054f8a0     MOV        dword ptr [__winminor],EDX                       = align(16)
    //         0054f8a6     MOV        ECX,EAX
    //         0054f8a8     AND        ECX,0xff
    //         0054f8ae     MOV        dword ptr [__winmajor],ECX                       = align(20)
    //         0054f8b4     SHL        ECX,0x8
    //         0054f8b7     ADD        ECX,EDX
    //         0054f8b9     MOV        dword ptr [__winver],ECX                         = align(24)
    //         0054f8bf     SHR        EAX,0x10
    //         0054f8c2     MOV        [__osver],EAX                                    = align(28)
    //         0054f8c7     CALL       __heap_init                                      undefined __heap_init()
    //         0054f8cc     TEST       EAX,EAX
    //         0054f8ce     JNZ        LAB_0054f8da
    //         0054f8d0     PUSH       0x1c
    //         0054f8d2     CALL       __amsg_exit                                      undefined __amsg_exit()
    //         0054f8d7     ADD        ESP,0x4
    //                               LAB_0054f8da                                                 XREF[1]:     0054f8ce(j)  
    //         0054f8da     MOV        dword ptr [EBP + local_8],0x0
    //         0054f8e1     CALL       __ioinit                                         undefined __ioinit()
    //         0054f8e6     CALL       ___initmbctable                                  undefined ___initmbctable()
    //         0054f8eb     CALL       dword ptr [->KERNEL32.DLL::GetCommandLineA]      = 0048b7fc
    //         0054f8f1     MOV        [__acmdln],EAX
    //         0054f8f6     CALL       ___crtGetEnvironmentStringsA                     undefined ___crtGetEnvironmentStringsA()
    //         0054f8fb     MOV        [__aenvptr],EAX
    //         0054f900     TEST       EAX,EAX
    //         0054f902     JZ         LAB_0054f90d
    //         0054f904     MOV        EAX,[__acmdln]
    //         0054f909     TEST       EAX,EAX
    //         0054f90b     JNZ        LAB_0054f917
    //                               LAB_0054f90d                                                 XREF[1]:     0054f902(j)  
    //         0054f90d     PUSH       -0x1
    //         0054f90f     CALL       _exit                                            undefined _exit()
    //         0054f914     ADD        ESP,0x4
    //                               LAB_0054f917                                                 XREF[1]:     0054f90b(j)  
    //         0054f917     CALL       __setargv                                        undefined __setargv()
    //         0054f91c     CALL       __setenvp                                        undefined __setenvp()
    //         0054f921     CALL       __cinit                                          undefined __cinit()
    //         0054f926     MOV        ESI,dword ptr [__acmdln]
    //         0054f92c     MOV        dword ptr [EBP + local_68],ESI
    //         0054f92f     CMP        byte ptr [ESI],0x22
    //         0054f932     JNZ        LAB_0054f9f6
    //                               LAB_0054f938                                                 XREF[2]:     0054f956(j), 0054f95c(j)  
    //         0054f938     INC        ESI
    //         0054f939     MOV        dword ptr [EBP + local_68],ESI
    //         0054f93c     MOV        AL,byte ptr [ESI]
    //         0054f93e     CMP        AL,0x22
    //         0054f940     JZ         LAB_0054f95e
    //         0054f942     TEST       AL,AL
    //         0054f944     JZ         LAB_0054f95e
    //         0054f946     AND        EAX,0xff
    //         0054f94b     PUSH       EAX
    //         0054f94c     CALL       __ismbblead                                      undefined __ismbblead()
    //         0054f951     ADD        ESP,0x4
    //         0054f954     TEST       EAX,EAX
    //         0054f956     JZ         LAB_0054f938
    //         0054f958     INC        ESI
    //         0054f959     MOV        dword ptr [EBP + local_68],ESI
    //         0054f95c     JMP        LAB_0054f938
    //                               LAB_0054f95e                                                 XREF[2]:     0054f940(j), 0054f944(j)  
    //         0054f95e     CMP        byte ptr [ESI],0x22
    //         0054f961     JNZ        LAB_0054f967
    //         0054f963     INC        ESI
    //         0054f964     MOV        dword ptr [EBP + local_68],ESI
    //                               LAB_0054f967                                                 XREF[3]:     0054f961(j), 0054f975(j), 
    //                                                                                                         0054f9f9(j)  
    //         0054f967     MOV        AL,byte ptr [ESI]
    //         0054f969     TEST       AL,AL
    //         0054f96b     JZ         LAB_0054f977
    //         0054f96d     CMP        AL,0x20
    //         0054f96f     JA         LAB_0054f977
    //         0054f971     INC        ESI
    //         0054f972     MOV        dword ptr [EBP + local_68],ESI
    //         0054f975     JMP        LAB_0054f967
    //                               LAB_0054f977                                                 XREF[2]:     0054f96b(j), 0054f96f(j)  
    //         0054f977     MOV        dword ptr [EBP + local_34],0x0
    //         0054f97e     LEA        EAX=>local_60,[EBP + -0x5c]
    //         0054f981     PUSH       EAX
    //         0054f982     CALL       dword ptr [->KERNEL32.DLL::GetStartupInfoA]      = 0048b7ea
    //         0054f988     TEST       byte ptr [EBP + local_34],0x1
    //         0054f98c     JZ         LAB_0054f998
    //         0054f98e     MOV        EAX,dword ptr [EBP + local_30]
    //         0054f991     AND        EAX,0xffff
    //         0054f996     JMP        LAB_0054f99d
    //                               LAB_0054f998                                                 XREF[1]:     0054f98c(j)  
    //         0054f998     MOV        EAX,0xa
    //                               LAB_0054f99d                                                 XREF[1]:     0054f996(j)  
    //         0054f99d     PUSH       EAX
    //         0054f99e     PUSH       ESI=>DAT_fffffff8
    //         0054f99f     PUSH       0x0=>DAT_fffffff4
    //         0054f9a1     PUSH       0x0=>DAT_fffffff0
    //         0054f9a3     CALL       dword ptr [->KERNEL32.DLL::GetModuleHandleA]     = 0048ab4c
    //         0054f9a9     PUSH       EAX
    //         0054f9aa     CALL       _WinMain@16                                      undefined _WinMain@16()
    //         0054f9af     MOV        dword ptr [EBP + local_64],EAX
    //         0054f9b2     PUSH       EAX
    //         0054f9b3     CALL       _exit                                            undefined _exit()
    //         0054f9b8     JMP        LAB_0054f9db
}

// Offset: 0x0054F9BA
undefined FUN_0054f9ba() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054f9ba()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054f9ba
    //         0054f9ba     MOV        EAX,dword ptr [EBP + -0x14]
    //         0054f9bd     MOV        ECX,dword ptr [EAX]
    //         0054f9bf     MOV        ECX,dword ptr [ECX]
    //         0054f9c1     MOV        dword ptr [EBP + -0x68],ECX
    //         0054f9c4     PUSH       EAX
    //         0054f9c5     PUSH       ECX
    //         0054f9c6     CALL       __XcptFilter                                     undefined __XcptFilter()
    //         0054f9cb     ADD        ESP,0x8
    //         0054f9ce     RET
}

// Offset: 0x0054F9CF
undefined FUN_0054f9cf() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054f9cf()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054f9cf
    //         0054f9cf     MOV        ESP,dword ptr [EBP + -0x18]
    //         0054f9d2     MOV        EDX,dword ptr [EBP + -0x68]
    //         0054f9d5     PUSH       EDX
    //         0054f9d6     CALL       __exit                                           undefined __exit()
    //                               LAB_0054f9db                                                 XREF[1]:     entry:0054f9b8(j)  
    //         0054f9db     ADD        ESP,0x4
    //         0054f9de     MOV        dword ptr [EBP + -0x4],0xffffffff
    //         0054f9e5     MOV        ECX,dword ptr [EBP + DAT_fffffff0]
    //         0054f9e8     MOV        dword ptr FS:[0x0],ECX
    //         0054f9ef     POP        EDI
    //         0054f9f0     POP        ESI
    //         0054f9f1     POP        EBX
    //         0054f9f2     MOV        ESP,EBP
    //         0054f9f4     POP        EBP
    //         0054f9f5     RET
    //                               LAB_0054f9f6                                                 XREF[2]:     0054f932(j), 0054fa03(j)  
}

// Offset: 0x0054FA10
undefined amsg_exit() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __amsg_exit()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __amsg_exit                                                  XREF[9]:     FUN_0054eb25:0054eb48(c), 
    //                                                                                                         entry:0054f8d2(c), 
    //                                                                                                         FUN_00553eeb:00553f45(c), 
    //                                                                                                         __ioinit:00553fec(c), 
    //                                                                                                         __setenvp:005569c2(c), 
    //                                                                                                         __setenvp:005569fc(c), 
    //                                                                                                         __setargv:00556ac4(c), 
    //                                                                                                         __fptrap:00558112(c), 
    //                                                                                                         FUN_0055a6a0:0055a6de(c)  
    //         0054fa10     CMP        dword ptr [___error_mode],0x1
    //         0054fa17     JNZ        LAB_0054fa1e
    //         0054fa19     CALL       __FF_MSGBANNER                                   undefined __FF_MSGBANNER()
    //                               LAB_0054fa1e                                                 XREF[1]:     0054fa17(j)  
    //         0054fa1e     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054fa22     PUSH       EAX
    //         0054fa23     CALL       __NMSG_WRITE                                     undefined __NMSG_WRITE()
    //         0054fa28     ADD        ESP,0x4
    //         0054fa2b     PUSH       0xff
    //         0054fa30     CALL       dword ptr [->__exit]                             undefined __exit()
    //                                                                                  = 0054f6d0
    //         0054fa36     ADD        ESP,0x4
    //         0054fa39     RET
}

// Offset: 0x0054FA40
undefined InternalCxxFrameHandler() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined ___InternalCxxFrameHandler()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               ___InternalCxxFrameHandler                                   XREF[3]:     ___CxxFrameHandler:0054b2c7(c), 
    //                                                                                                         FUN_0054b360:0054b380(c), 
    //                                                                                                         FUN_0054b460:0054b4ad(c)  
    //         0054fa40     PUSH       ESI
    //         0054fa41     MOV        ESI,dword ptr [ESP + Stack[0x14]]
    //         0054fa45     CMP        dword ptr [ESI],0x19930520
    //         0054fa4b     JZ         LAB_0054fa52
    //         0054fa4d     CALL       _inconsistency                                   void _inconsistency(void)
    //                               LAB_0054fa52                                                 XREF[1]:     0054fa4b(j)  
    //         0054fa52     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054fa56     TEST       byte ptr [EAX + 0x4],0x66
    //         0054fa5a     JZ         LAB_0054fa8f
    //         0054fa5c     MOV        EAX,dword ptr [ESI + 0x4]
    //         0054fa5f     TEST       EAX,EAX
    //         0054fa61     JZ         LAB_0054fb00
    //         0054fa67     MOV        EAX,dword ptr [ESP + Stack[0x18]]
    //         0054fa6b     TEST       EAX,EAX
    //         0054fa6d     JNZ        LAB_0054fb00
    //         0054fa73     MOV        EAX,dword ptr [ESP + Stack[0x10]]
    //         0054fa77     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //         0054fa7b     PUSH       -0x1
    //         0054fa7d     PUSH       ESI
    //         0054fa7e     PUSH       EAX
    //         0054fa7f     PUSH       ECX
    //         0054fa80     CALL       ___FrameUnwindToState                            undefined ___FrameUnwindToState()
    //         0054fa85     ADD        ESP,0x10
    //         0054fa88     MOV        EAX,0x1
    //         0054fa8d     POP        ESI
    //         0054fa8e     RET
    //                               LAB_0054fa8f                                                 XREF[1]:     0054fa5a(j)  
    //         0054fa8f     MOV        ECX,dword ptr [ESI + 0xc]
    //         0054fa92     TEST       ECX,ECX
    //         0054fa94     JZ         LAB_0054fb00
    //         0054fa96     CMP        dword ptr [EAX],0xe06d7363
    //         0054fa9c     JNZ        LAB_0054fad8
    //         0054fa9e     CMP        dword ptr [EAX + 0x14],0x19930520
    //         0054faa5     JBE        LAB_0054fad8
    //         0054faa7     MOV        EDX,dword ptr [EAX + 0x1c]
    //         0054faaa     MOV        ECX,dword ptr [EDX + 0x8]
    //         0054faad     TEST       ECX,ECX
    //         0054faaf     JZ         LAB_0054fad8
    //         0054fab1     MOV        EDX,dword ptr [ESP + Stack[0x20]]
    //         0054fab5     PUSH       EDX
    //         0054fab6     MOV        EDX,dword ptr [ESP + Stack[0x1c]]
    //         0054faba     PUSH       EDX
    //         0054fabb     MOV        EDX,dword ptr [ESP + Stack[0x18]]
    //         0054fabf     PUSH       EDX
    //         0054fac0     MOV        EDX,dword ptr [ESP + Stack[0x10]]
    //         0054fac4     PUSH       ESI
    //         0054fac5     PUSH       EDX
    //         0054fac6     MOV        EDX,dword ptr [ESP + Stack[0xc]]
    //         0054faca     PUSH       EDX
    //         0054facb     MOV        EDX,dword ptr [ESP + Stack[0x8]]
    //         0054facf     PUSH       EDX
    //         0054fad0     PUSH       EAX
    //         0054fad1     CALL       ECX
    //         0054fad3     ADD        ESP,0x20
    //         0054fad6     POP        ESI
    //         0054fad7     RET
    //                               LAB_0054fad8                                                 XREF[3]:     0054fa9c(j), 0054faa5(j), 
    //                                                                                                         0054faaf(j)  
    //         0054fad8     MOV        ECX,dword ptr [ESP + Stack[0x1c]]
    //         0054fadc     MOV        EDX,dword ptr [ESP + Stack[0x18]]
    //         0054fae0     PUSH       ECX
    //         0054fae1     MOV        ECX,dword ptr [ESP + Stack[0x20]]
    //         0054fae5     PUSH       EDX
    //         0054fae6     MOV        EDX,dword ptr [ESP + Stack[0x10]]
    //         0054faea     PUSH       ECX
    //         0054faeb     MOV        ECX,dword ptr [ESP + Stack[0xc]]
    //         0054faef     PUSH       ESI
    //         0054faf0     PUSH       EDX
    //         0054faf1     MOV        EDX,dword ptr [ESP + Stack[0x8]]
    //         0054faf5     PUSH       ECX
    //         0054faf6     PUSH       EDX
    //         0054faf7     PUSH       EAX
    //         0054faf8     CALL       FUN_0054fb10                                     undefined FUN_0054fb10()
    //         0054fafd     ADD        ESP,0x20
    //                               LAB_0054fb00                                                 XREF[3]:     0054fa61(j), 0054fa6d(j), 
    //                                                                                                         0054fa94(j)  
    //         0054fb00     MOV        EAX,0x1
    //         0054fb05     POP        ESI
    //         0054fb06     RET
}

// Offset: 0x0054FB10
undefined FUN_0054fb10() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054fb10()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0054fc38(W), 0054fc3c(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     0054fc34(W), 0054fc40(R)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[3]:     0054fbd5(*), 0054fbef(R), 0054fd48(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[2]:     0054fb21(W), 0054fd3c(R)  
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[3]:     0054fc1f(W), 0054fcf1(R), 0054fcfb(W)  
    //              undefined4        Stack[-0x18]:4 local_18                  XREF[3]:     0054fc46(W), 0054fcdd(R), 0054fce7(W)  
    //              undefined4        Stack[-0x1c]:4 local_1c                  XREF[4]:     0054fbf8(W), 0054fd13(R), 0054fd40(R), 0054fd56(W)  
    //              undefined4        Stack[-0x20]:4 local_20                  XREF[4]:     0054fbd9(*), 0054fbeb(R), 0054fd44(R), 0054fd52(W)  
    //              undefined4        Stack[-0x24]:4 local_24                  XREF[4]:     0054fc1b(W), 0054fc9f(R), 0054fcab(R), 0054fcff(W)  
    //                               FUN_0054fb10                                                 XREF[1]:     ___InternalCxxFrameHandler:0054faf
    //         0054fb10     SUB        ESP,0x24
    //         0054fb13     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         0054fb17     PUSH       EBX
    //         0054fb18     PUSH       EBP
    //         0054fb19     PUSH       ESI
    //         0054fb1a     MOV        EBP,dword ptr [EAX + 0x8]
    //         0054fb1d     PUSH       EDI
    //         0054fb1e     CMP        EBP,-0x1
    //         0054fb21     MOV        dword ptr [ESP + local_10],EBP
    //         0054fb25     JL         LAB_0054fb30
    //         0054fb27     MOV        ECX,dword ptr [ESP + Stack[0x14]]
    //         0054fb2b     CMP        EBP,dword ptr [ECX + 0x4]
    //         0054fb2e     JL         LAB_0054fb35
    //                               LAB_0054fb30                                                 XREF[1]:     0054fb25(j)  
    //         0054fb30     CALL       _inconsistency                                   void _inconsistency(void)
    //                               LAB_0054fb35                                                 XREF[1]:     0054fb2e(j)  
    //         0054fb35     MOV        EBX,dword ptr [ESP + Stack[0x4]]
    //         0054fb39     MOV        ESI,0x3
    //         0054fb3e     MOV        EDI,0x19930520
    //         0054fb43     CMP        dword ptr [EBX],0xe06d7363
    //         0054fb49     JNZ        LAB_0054fd7b
    //         0054fb4f     CMP        dword ptr [EBX + 0x10],ESI
    //         0054fb52     JNZ        LAB_0054fbb3
    //         0054fb54     CMP        dword ptr [EBX + 0x14],EDI
    //         0054fb57     JNZ        LAB_0054fbb3
    //         0054fb59     MOV        EAX,dword ptr [EBX + 0x1c]
    //         0054fb5c     TEST       EAX,EAX
    //         0054fb5e     JNZ        LAB_0054fbb3
    //         0054fb60     MOV        EAX,[_pCurrentException]                         = 00000000
    //         0054fb65     TEST       EAX,EAX
    //         0054fb67     JZ         LAB_0054fdb8
    //         0054fb6d     MOV        EDX,dword ptr [_pCurrentExContext]               = 00000000
    //         0054fb73     MOV        EBX,EAX
    //         0054fb75     PUSH       0x1
    //         0054fb77     PUSH       EBX
    //         0054fb78     MOV        dword ptr [ESP + Stack[0x4]],EBX
    //         0054fb7c     MOV        dword ptr [ESP + Stack[0xc]],EDX
    //         0054fb80     CALL       _ValidateRead                                    int _ValidateRead(void * param_1, uint param_2)
    //         0054fb85     ADD        ESP,0x8
    //         0054fb88     TEST       EAX,EAX
    //         0054fb8a     JNZ        LAB_0054fb91
    //         0054fb8c     CALL       _inconsistency                                   void _inconsistency(void)
    //                               LAB_0054fb91                                                 XREF[1]:     0054fb8a(j)  
    //         0054fb91     CMP        dword ptr [EBX],0xe06d7363
    //         0054fb97     JNZ        LAB_0054fd7b
    //         0054fb9d     CMP        dword ptr [EBX + 0x10],ESI
    //         0054fba0     JNZ        LAB_0054fbb3
    //         0054fba2     CMP        dword ptr [EBX + 0x14],EDI
    //         0054fba5     JNZ        LAB_0054fbb3
    //         0054fba7     MOV        EAX,dword ptr [EBX + 0x1c]
    //         0054fbaa     TEST       EAX,EAX
    //         0054fbac     JNZ        LAB_0054fbb3
    //         0054fbae     CALL       _inconsistency                                   void _inconsistency(void)
    //                               LAB_0054fbb3                                                 XREF[6]:     0054fb52(j), 0054fb57(j), 
    //                                                                                                         0054fb5e(j), 0054fba0(j), 
    //                                                                                                         0054fba5(j), 0054fbac(j)  
    //         0054fbb3     CMP        dword ptr [EBX],0xe06d7363
    //         0054fbb9     JNZ        LAB_0054fd7b
    //         0054fbbf     CMP        dword ptr [EBX + 0x10],ESI
    //         0054fbc2     JNZ        LAB_0054fd7b
    //         0054fbc8     CMP        dword ptr [EBX + 0x14],EDI
    //         0054fbcb     JNZ        LAB_0054fd7b
    //         0054fbd1     MOV        EDX,dword ptr [ESP + Stack[0x1c]]
    //         0054fbd5     LEA        EAX=>local_c,[ESP + 0x28]
    //         0054fbd9     LEA        ECX=>local_20,[ESP + 0x14]
    //         0054fbdd     PUSH       EAX
    //         0054fbde     MOV        EAX,dword ptr [ESP + Stack[0x14]]
    //         0054fbe2     PUSH       ECX
    //         0054fbe3     PUSH       EBP
    //         0054fbe4     PUSH       EDX
    //         0054fbe5     PUSH       EAX
    //         0054fbe6     CALL       _GetRangeOfTrysToCheck                           _s_TryBlockMapEntry * _GetRangeOfTrysToCheck(
    //         0054fbeb     MOV        ECX,dword ptr [ESP + local_20]
    //         0054fbef     MOV        EDX,dword ptr [ESP + local_c]
    //         0054fbf3     ADD        ESP,0x14
    //         0054fbf6     CMP        ECX,EDX
    //         0054fbf8     MOV        dword ptr [ESP + local_1c],EAX
    //         0054fbfc     JNC        LAB_0054fd60
    //                               LAB_0054fc02                                                 XREF[1]:     0054fd5a(j)  
    //         0054fc02     CMP        dword ptr [EAX],EBP
    //         0054fc04     JG         LAB_0054fd44
    //         0054fc0a     CMP        EBP,dword ptr [EAX + 0x4]
    //         0054fc0d     JG         LAB_0054fd44
    //         0054fc13     MOV        ECX,dword ptr [EAX + 0xc]
    //         0054fc16     MOV        ESI,dword ptr [EAX + 0x10]
    //         0054fc19     TEST       ECX,ECX
    //         0054fc1b     MOV        dword ptr [ESP + local_24],ESI
    //         0054fc1f     MOV        dword ptr [ESP + local_14],ECX
    //         0054fc23     JLE        LAB_0054fd40
    //         0054fc29     MOV        EAX,dword ptr [EBX + 0x1c]
    //         0054fc2c     MOV        EAX,dword ptr [EAX + 0xc]
    //         0054fc2f     LEA        EDX,[EAX + 0x4]
    //         0054fc32     MOV        EAX,dword ptr [EAX]
    //         0054fc34     MOV        dword ptr [ESP + local_8],EDX
    //         0054fc38     MOV        dword ptr [ESP + local_4],EAX
    //                               LAB_0054fc3c                                                 XREF[1]:     0054fd03(j)  
    //         0054fc3c     MOV        EAX,dword ptr [ESP + local_4]
    //         0054fc40     MOV        EBP,dword ptr [ESP + local_8]
    //         0054fc44     TEST       EAX,EAX
    //         0054fc46     MOV        dword ptr [ESP + local_18],EAX
    //         0054fc4a     JLE        LAB_0054fcf5
    //         0054fc50     MOV        EDX,dword ptr [ESI + 0x4]
    //                               LAB_0054fc53                                                 XREF[1]:     0054fceb(j)  
    //         0054fc53     MOV        EDI,dword ptr [EBP]
    //         0054fc56     TEST       EDX,EDX
    //         0054fc58     JZ         LAB_0054fcd4
    //         0054fc5a     MOV        CL,byte ptr [EDX + 0x8]
    //         0054fc5d     LEA        EAX,[EDX + 0x8]
    //         0054fc60     TEST       CL,CL
    //         0054fc62     JZ         LAB_0054fcd4
    //         0054fc64     MOV        ECX,dword ptr [EDI + 0x4]
    //         0054fc67     CMP        EDX,ECX
    //         0054fc69     JZ         LAB_0054fcaf
    //         0054fc6b     LEA        ESI,[ECX + 0x8]
    //                               LAB_0054fc6e                                                 XREF[1]:     0054fc8c(j)  
    //         0054fc6e     MOV        BL,byte ptr [EAX]
    //         0054fc70     MOV        CL,BL
    //         0054fc72     CMP        BL,byte ptr [ESI]
    //         0054fc74     JNZ        LAB_0054fc92
    //         0054fc76     TEST       CL,CL
    //         0054fc78     JZ         LAB_0054fc8e
    //         0054fc7a     MOV        BL,byte ptr [EAX + 0x1]
    //         0054fc7d     MOV        CL,BL
    //         0054fc7f     CMP        BL,byte ptr [ESI + 0x1]
    //         0054fc82     JNZ        LAB_0054fc92
    //         0054fc84     ADD        EAX,0x2
    //         0054fc87     ADD        ESI,0x2
    //         0054fc8a     TEST       CL,CL
    //         0054fc8c     JNZ        LAB_0054fc6e
    //                               LAB_0054fc8e                                                 XREF[1]:     0054fc78(j)  
    //         0054fc8e     XOR        EAX,EAX
    //         0054fc90     JMP        LAB_0054fc97
    //                               LAB_0054fc92                                                 XREF[2]:     0054fc74(j), 0054fc82(j)  
    //         0054fc92     SBB        EAX,EAX
    //         0054fc94     SBB        EAX,-0x1
    //                               LAB_0054fc97                                                 XREF[1]:     0054fc90(j)  
    //         0054fc97     TEST       EAX,EAX
    //         0054fc99     JZ         LAB_0054fca7
    //         0054fc9b     MOV        EBX,dword ptr [ESP + Stack[0x4]]
    //         0054fc9f     MOV        ESI,dword ptr [ESP + local_24]
    //         0054fca3     XOR        EAX,EAX
    //         0054fca5     JMP        LAB_0054fcd9
    //                               LAB_0054fca7                                                 XREF[1]:     0054fc99(j)  
    //         0054fca7     MOV        EBX,dword ptr [ESP + Stack[0x4]]
    //         0054fcab     MOV        ESI,dword ptr [ESP + local_24]
    //                               LAB_0054fcaf                                                 XREF[1]:     0054fc69(j)  
    //         0054fcaf     TEST       byte ptr [EDI],0x2
    //         0054fcb2     JZ         LAB_0054fcb9
    //         0054fcb4     TEST       byte ptr [ESI],0x8
    //         0054fcb7     JZ         LAB_0054fcd0
    //                               LAB_0054fcb9                                                 XREF[1]:     0054fcb2(j)  
    //         0054fcb9     MOV        EAX,dword ptr [EBX + 0x1c]
    //         0054fcbc     MOV        EAX,dword ptr [EAX]
    //         0054fcbe     TEST       AL,0x1
    //         0054fcc0     JZ         LAB_0054fcc7
    //         0054fcc2     TEST       byte ptr [ESI],0x1
    //         0054fcc5     JZ         LAB_0054fcd0
    //                               LAB_0054fcc7                                                 XREF[1]:     0054fcc0(j)  
    //         0054fcc7     TEST       AL,0x2
    //         0054fcc9     JZ         LAB_0054fcd4
    //         0054fccb     TEST       byte ptr [ESI],0x2
    //         0054fcce     JNZ        LAB_0054fcd4
    //                               LAB_0054fcd0                                                 XREF[2]:     0054fcb7(j), 0054fcc5(j)  
    //         0054fcd0     XOR        EAX,EAX
    //         0054fcd2     JMP        LAB_0054fcd9
    //                               LAB_0054fcd4                                                 XREF[4]:     0054fc58(j), 0054fc62(j), 
    //                                                                                                         0054fcc9(j), 0054fcce(j)  
    //         0054fcd4     MOV        EAX,0x1
    //                               LAB_0054fcd9                                                 XREF[2]:     0054fca5(j), 0054fcd2(j)  
    //         0054fcd9     TEST       EAX,EAX
    //         0054fcdb     JNZ        LAB_0054fd0b
    //         0054fcdd     MOV        EAX,dword ptr [ESP + local_18]
    //         0054fce1     ADD        EBP,0x4
    //         0054fce4     DEC        EAX
    //         0054fce5     TEST       EAX,EAX
    //         0054fce7     MOV        dword ptr [ESP + local_18],EAX
    //         0054fceb     JG         LAB_0054fc53
    //         0054fcf1     MOV        ECX,dword ptr [ESP + local_14]
    //                               LAB_0054fcf5                                                 XREF[1]:     0054fc4a(j)  
    //         0054fcf5     DEC        ECX
    //         0054fcf6     ADD        ESI,0x10
    //         0054fcf9     TEST       ECX,ECX
    //         0054fcfb     MOV        dword ptr [ESP + local_14],ECX
    //         0054fcff     MOV        dword ptr [ESP + local_24],ESI
    //         0054fd03     JG         LAB_0054fc3c
    //         0054fd09     JMP        LAB_0054fd3c
    //                               LAB_0054fd0b                                                 XREF[1]:     0054fcdb(j)  
    //         0054fd0b     MOV        ECX,dword ptr [ESP + Stack[0x20]]
    //         0054fd0f     MOV        EDX,dword ptr [ESP + Stack[0x1c]]
    //         0054fd13     MOV        EAX,dword ptr [ESP + local_1c]
    //         0054fd17     PUSH       ECX
    //         0054fd18     MOV        ECX,dword ptr [EBP]
    //         0054fd1b     PUSH       EDX
    //         0054fd1c     MOV        EDX,dword ptr [ESP + Stack[0x14]]
    //         0054fd20     PUSH       EAX
    //         0054fd21     MOV        EAX,dword ptr [ESP + Stack[0x10]]
    //         0054fd25     PUSH       ECX
    //         0054fd26     MOV        ECX,dword ptr [ESP + Stack[0xc]]
    //         0054fd2a     PUSH       ESI
    //         0054fd2b     PUSH       EDX
    //         0054fd2c     MOV        EDX,dword ptr [ESP + Stack[0x8]]
    //         0054fd30     PUSH       EAX
    //         0054fd31     PUSH       ECX
    //         0054fd32     PUSH       EDX
    //         0054fd33     PUSH       EBX
    //         0054fd34     CALL       FUN_0054ff70                                     undefined FUN_0054ff70()
    //         0054fd39     ADD        ESP,0x28
    //                               LAB_0054fd3c                                                 XREF[1]:     0054fd09(j)  
    //         0054fd3c     MOV        EBP,dword ptr [ESP + local_10]
    //                               LAB_0054fd40                                                 XREF[1]:     0054fc23(j)  
    //         0054fd40     MOV        EAX,dword ptr [ESP + local_1c]
    //                               LAB_0054fd44                                                 XREF[2]:     0054fc04(j), 0054fc0d(j)  
    //         0054fd44     MOV        ECX,dword ptr [ESP + local_20]
    //         0054fd48     MOV        EDX,dword ptr [ESP + local_c]
    //         0054fd4c     INC        ECX
    //         0054fd4d     ADD        EAX,0x14
    //         0054fd50     CMP        ECX,EDX
    //         0054fd52     MOV        dword ptr [ESP + local_20],ECX
    //         0054fd56     MOV        dword ptr [ESP + local_1c],EAX
    //         0054fd5a     JC         LAB_0054fc02
    //                               LAB_0054fd60                                                 XREF[1]:     0054fbfc(j)  
    //         0054fd60     MOV        AL,byte ptr [ESP + Stack[0x18]]
    //         0054fd64     TEST       AL,AL
    //         0054fd66     JZ         LAB_0054fdb8
    //         0054fd68     PUSH       0x1
    //         0054fd6a     PUSH       EBX
    //         0054fd6b     CALL       _DestructExceptionObject                         void _DestructExceptionObject(EHExceptionReco
    //         0054fd70     ADD        ESP,0x8
    //         0054fd73     POP        EDI
    //         0054fd74     POP        ESI
    //         0054fd75     POP        EBP
    //         0054fd76     POP        EBX
    //         0054fd77     ADD        ESP,0x24
    //         0054fd7a     RET
    //                               LAB_0054fd7b                                                 XREF[5]:     0054fb49(j), 0054fb97(j), 
    //                                                                                                         0054fbb9(j), 0054fbc2(j), 
    //                                                                                                         0054fbcb(j)  
    //         0054fd7b     MOV        AL,byte ptr [ESP + Stack[0x18]]
    //         0054fd7f     TEST       AL,AL
    //         0054fd81     JNZ        LAB_0054fdb3
    //         0054fd83     MOV        EAX,dword ptr [ESP + Stack[0x20]]
    //         0054fd87     MOV        ECX,dword ptr [ESP + Stack[0x1c]]
    //         0054fd8b     MOV        EDX,dword ptr [ESP + Stack[0x14]]
    //         0054fd8f     PUSH       EAX
    //         0054fd90     MOV        EAX,dword ptr [ESP + Stack[0x10]]
    //         0054fd94     PUSH       ECX
    //         0054fd95     MOV        ECX,dword ptr [ESP + Stack[0xc]]
    //         0054fd99     PUSH       EBP
    //         0054fd9a     PUSH       EDX
    //         0054fd9b     MOV        EDX,dword ptr [ESP + Stack[0x8]]
    //         0054fd9f     PUSH       EAX
    //         0054fda0     PUSH       ECX
    //         0054fda1     PUSH       EDX
    //         0054fda2     PUSH       EBX
    //         0054fda3     CALL       FUN_0054fdc0                                     undefined FUN_0054fdc0()
    //         0054fda8     ADD        ESP,0x20
    //         0054fdab     POP        EDI
    //         0054fdac     POP        ESI
    //         0054fdad     POP        EBP
    //         0054fdae     POP        EBX
    //         0054fdaf     ADD        ESP,0x24
    //         0054fdb2     RET
    //                               LAB_0054fdb3                                                 XREF[1]:     0054fd81(j)  
    //         0054fdb3     CALL       terminate                                        void terminate(void)
    //                               LAB_0054fdb8                                                 XREF[2]:     0054fb67(j), 0054fd66(j)  
    //         0054fdb8     POP        EDI
    //         0054fdb9     POP        ESI
    //         0054fdba     POP        EBP
    //         0054fdbb     POP        EBX
    //         0054fdbc     ADD        ESP,0x24
    //         0054fdbf     RET
}

// Offset: 0x0054FDC0
undefined FUN_0054fdc0() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054fdc0()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054fdc0                                                 XREF[1]:     FUN_0054fb10:0054fda3(c)  
    //         0054fdc0     MOV        EAX,[__pSETranslator]                            = 00000000
    //         0054fdc5     PUSH       EBX
    //         0054fdc6     MOV        EBX,dword ptr [ESP + Stack[0x14]]
    //         0054fdca     PUSH       EBP
    //         0054fdcb     MOV        EBP,dword ptr [ESP + Stack[0x20]]
    //         0054fdcf     PUSH       ESI
    //         0054fdd0     PUSH       EDI
    //         0054fdd1     MOV        EDI,dword ptr [ESP + Stack[0x1c]]
    //         0054fdd5     TEST       EAX,EAX
    //         0054fdd7     JZ         LAB_0054fe00
    //         0054fdd9     MOV        EAX,dword ptr [ESP + Stack[0x10]]
    //         0054fddd     MOV        ECX,dword ptr [ESP + Stack[0xc]]
    //         0054fde1     MOV        EDX,dword ptr [ESP + Stack[0x8]]
    //         0054fde5     PUSH       EBP
    //         0054fde6     PUSH       EDI
    //         0054fde7     PUSH       EBX
    //         0054fde8     PUSH       EAX
    //         0054fde9     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054fded     PUSH       ECX
    //         0054fdee     PUSH       EDX
    //         0054fdef     PUSH       EAX
    //         0054fdf0     CALL       _CallSETranslator                                int _CallSETranslator(EHExceptionRecord * par
    //         0054fdf5     ADD        ESP,0x1c
    //         0054fdf8     TEST       EAX,EAX
    //         0054fdfa     JNZ        LAB_0054fe89
    //                               LAB_0054fe00                                                 XREF[1]:     0054fdd7(j)  
    //         0054fe00     MOV        EAX,dword ptr [ESP + Stack[0x18]]
    //         0054fe04     LEA        ECX=>Stack[0x1c],[ESP + 0x2c]
    //         0054fe08     LEA        EDX=>Stack[0x20],[ESP + 0x30]
    //         0054fe0c     PUSH       ECX
    //         0054fe0d     PUSH       EDX
    //         0054fe0e     PUSH       EAX
    //         0054fe0f     PUSH       EDI
    //         0054fe10     PUSH       EBX
    //         0054fe11     CALL       _GetRangeOfTrysToCheck                           _s_TryBlockMapEntry * _GetRangeOfTrysToCheck(
    //         0054fe16     MOV        ECX,dword ptr [ESP + Stack[0x20]]
    //         0054fe1a     MOV        ESI,EAX
    //         0054fe1c     MOV        EAX,dword ptr [ESP + Stack[0x1c]]
    //         0054fe20     ADD        ESP,0x14
    //         0054fe23     CMP        ECX,EAX
    //         0054fe25     JNC        LAB_0054fe89
    //                               LAB_0054fe27                                                 XREF[1]:     0054fe87(j)  
    //         0054fe27     MOV        EAX,dword ptr [ESP + Stack[0x18]]
    //         0054fe2b     MOV        ECX,dword ptr [ESI]
    //         0054fe2d     CMP        EAX,ECX
    //         0054fe2f     JL         LAB_0054fe75
    //         0054fe31     CMP        EAX,dword ptr [ESI + 0x4]
    //         0054fe34     JG         LAB_0054fe75
    //         0054fe36     MOV        EDX,dword ptr [ESI + 0xc]
    //         0054fe39     MOV        EAX,dword ptr [ESI + 0x10]
    //         0054fe3c     SHL        EDX,0x4
    //         0054fe3f     ADD        EAX,EDX
    //         0054fe41     MOV        ECX,dword ptr [EAX + -0xc]
    //         0054fe44     TEST       ECX,ECX
    //         0054fe46     JZ         LAB_0054fe4f
    //         0054fe48     MOV        DL,byte ptr [ECX + 0x8]
    //         0054fe4b     TEST       DL,DL
    //         0054fe4d     JNZ        LAB_0054fe75
    //                               LAB_0054fe4f                                                 XREF[1]:     0054fe46(j)  
    //         0054fe4f     MOV        ECX,dword ptr [ESP + Stack[0x10]]
    //         0054fe53     MOV        EDX,dword ptr [ESP + Stack[0xc]]
    //         0054fe57     PUSH       EBP
    //         0054fe58     PUSH       EDI
    //         0054fe59     PUSH       ESI
    //         0054fe5a     ADD        EAX,-0x10
    //         0054fe5d     PUSH       0x0
    //         0054fe5f     PUSH       EAX
    //         0054fe60     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         0054fe64     PUSH       EBX
    //         0054fe65     PUSH       ECX
    //         0054fe66     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         0054fe6a     PUSH       EDX
    //         0054fe6b     PUSH       EAX
    //         0054fe6c     PUSH       ECX
    //         0054fe6d     CALL       FUN_0054ff70                                     undefined FUN_0054ff70()
    //         0054fe72     ADD        ESP,0x28
    //                               LAB_0054fe75                                                 XREF[3]:     0054fe2f(j), 0054fe34(j), 
    //                                                                                                         0054fe4d(j)  
    //         0054fe75     MOV        EAX,dword ptr [ESP + Stack[0x20]]
    //         0054fe79     MOV        ECX,dword ptr [ESP + Stack[0x1c]]
    //         0054fe7d     INC        EAX
    //         0054fe7e     ADD        ESI,0x14
    //         0054fe81     CMP        EAX,ECX
    //         0054fe83     MOV        dword ptr [ESP + Stack[0x20]],EAX
    //         0054fe87     JC         LAB_0054fe27
    //                               LAB_0054fe89                                                 XREF[2]:     0054fdfa(j), 0054fe25(j)  
    //         0054fe89     POP        EDI
    //         0054fe8a     POP        ESI
    //         0054fe8b     POP        EBP
    //         0054fe8c     POP        EBX
    //         0054fe8d     RET
}

// Offset: 0x0054FE90
undefined FrameUnwindToState() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined ___FrameUnwindToState()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     0054fed6(W), 0054fef4(W)  
    //              undefined4        Stack[-0x14]:4 local_14
    //              undefined4        Stack[-0x1c]:4 local_1c                  XREF[1]:     0054feb3(W)  
    //              undefined4        Stack[-0x20]:4 local_20                  XREF[2]:     0054febc(W), 0054ff01(W)  
    //                               ___FrameUnwindToState                                        XREF[3]:     FUN_0054b2dc:0054b2f2(c), 
    //                                                                                                         ___InternalCxxFrameHandler:0054fa8
    //                                                                                                         FUN_0054ff70:0054ffb8(c)  
    //         0054fe90     PUSH       EBP
    //         0054fe91     MOV        EBP,ESP
    //         0054fe93     PUSH       -0x1
    //         0054fe95     PUSH       DAT_00577aa8                                     = FFh
    //         0054fe9a     PUSH       __except_handler3
    //         0054fe9f     MOV        EAX,FS:[0x0]
    //         0054fea5     PUSH       EAX
    //         0054fea6     MOV        dword ptr FS:[0x0],ESP
    //         0054fead     ADD        ESP,-0xc
    //         0054feb0     PUSH       EBX
    //         0054feb1     PUSH       ESI
    //         0054feb2     PUSH       EDI
    //         0054feb3     MOV        dword ptr [EBP + local_1c],ESP
    //         0054feb6     MOV        EBX,dword ptr [EBP + Stack[0x4]]
    //         0054feb9     MOV        ESI,dword ptr [EBX + 0x8]
    //         0054febc     MOV        dword ptr [EBP + local_20],ESI
    //         0054febf     MOV        EDI,dword ptr [EBP + Stack[0xc]]
    //                               LAB_0054fec2                                                 XREF[2]:     0054ff04(j), 
    //                                                                                                         FUN_0054ff13:0054ff2f(j)  
    //         0054fec2     CMP        ESI,dword ptr [EBP + Stack[0x10]]
    //         0054fec5     JZ         LAB_0054ff31
    //         0054fec7     CMP        ESI,-0x1
    //         0054feca     JLE        LAB_0054fed1
    //         0054fecc     CMP        ESI,dword ptr [EDI + 0x4]
    //         0054fecf     JL         LAB_0054fed6
    //                               LAB_0054fed1                                                 XREF[1]:     0054feca(j)  
    //         0054fed1     CALL       _inconsistency                                   void _inconsistency(void)
    //                               LAB_0054fed6                                                 XREF[1]:     0054fecf(j)  
    //         0054fed6     MOV        dword ptr [EBP + local_8],0x0
    //         0054fedd     MOV        EAX,dword ptr [EDI + 0x8]
    //         0054fee0     MOV        EAX,dword ptr [EAX + ESI*0x8 + 0x4]
    //         0054fee4     TEST       EAX,EAX
    //         0054fee6     JZ         LAB_0054fef4
    //         0054fee8     PUSH       0x103
    //         0054feed     PUSH       EBX
    //         0054feee     PUSH       EAX
    //         0054feef     CALL       __CallSettingFrame@12                            undefined __CallSettingFrame@12()
    //                               LAB_0054fef4                                                 XREF[1]:     0054fee6(j)  
    //         0054fef4     MOV        dword ptr [EBP + local_8],0xffffffff
    //         0054fefb     MOV        EDX,dword ptr [EDI + 0x8]
    //         0054fefe     MOV        ESI,dword ptr [EDX + ESI*0x8]
    //         0054ff01     MOV        dword ptr [EBP + local_20],ESI
    //         0054ff04     JMP        LAB_0054fec2
}

// Offset: 0x0054FF06
undefined FUN_0054ff06() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054ff06()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054ff06
    //         0054ff06     MOV        ECX,dword ptr [EBP + -0x14]
    //         0054ff09     PUSH       ECX
    //         0054ff0a     CALL       FUN_0054ff50                                     undefined FUN_0054ff50()
    //         0054ff0f     ADD        ESP,0x4
    //         0054ff12     RET
}

// Offset: 0x0054FF13
undefined FUN_0054ff13() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054ff13()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054ff13
    //         0054ff13     MOV        ESP,dword ptr [EBP + -0x18]
    //         0054ff16     MOV        dword ptr [EBP + -0x4],0xffffffff
    //         0054ff1d     MOV        EDI,dword ptr [EBP + 0x10]
    //         0054ff20     MOV        EBX,dword ptr [EBP + 0x8]
    //         0054ff23     MOV        ESI,dword ptr [EBP + -0x1c]
    //         0054ff26     MOV        EDX,dword ptr [EDI + 0x8]
    //         0054ff29     MOV        ESI,dword ptr [EDX + ESI*0x8]
    //         0054ff2c     MOV        dword ptr [EBP + -0x1c],ESI
    //         0054ff2f     JMP        LAB_0054fec2
    //                               LAB_0054ff31                                                 XREF[1]:     ___FrameUnwindToState:0054fec5(j)  
    //         0054ff31     MOV        dword ptr [EBX + 0x8],ESI
    //         0054ff34     MOV        ECX,dword ptr [EBP + -0x10]
    //         0054ff37     MOV        dword ptr FS:[0x0],ECX
    //         0054ff3e     POP        EDI
    //         0054ff3f     POP        ESI
    //         0054ff40     POP        EBX
    //         0054ff41     MOV        ESP,EBP
    //         0054ff43     POP        EBP
    //         0054ff44     RET
}

// Offset: 0x0054FF50
undefined FUN_0054ff50() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054ff50()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054ff50                                                 XREF[1]:     FUN_0054ff06:0054ff0a(c)  
    //         0054ff50     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054ff54     MOV        ECX,dword ptr [EAX]
    //         0054ff56     CMP        dword ptr [ECX],0xe06d7363
    //         0054ff5c     JNZ        LAB_0054ff63
    //         0054ff5e     CALL       terminate                                        void terminate(void)
    //                               LAB_0054ff63                                                 XREF[1]:     0054ff5c(j)  
    //         0054ff63     XOR        EAX,EAX
    //         0054ff65     RET
}

// Offset: 0x0054FF70
undefined FUN_0054ff70() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054ff70()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054ff70                                                 XREF[2]:     FUN_0054fb10:0054fd34(c), 
    //                                                                                                         FUN_0054fdc0:0054fe6d(c)  
    //         0054ff70     MOV        EAX,dword ptr [ESP + Stack[0x1c]]
    //         0054ff74     PUSH       EBX
    //         0054ff75     PUSH       EBP
    //         0054ff76     MOV        EBP,dword ptr [ESP + Stack[0x4]]
    //         0054ff7a     PUSH       ESI
    //         0054ff7b     MOV        ESI,dword ptr [ESP + Stack[0x8]]
    //         0054ff7f     TEST       EAX,EAX
    //         0054ff81     PUSH       EDI
    //         0054ff82     JZ         LAB_0054ff94
    //         0054ff84     PUSH       EAX
    //         0054ff85     MOV        EAX,dword ptr [ESP + Stack[0x18]]
    //         0054ff89     PUSH       EAX
    //         0054ff8a     PUSH       ESI
    //         0054ff8b     PUSH       EBP
    //         0054ff8c     CALL       FUN_00550180                                     undefined FUN_00550180()
    //         0054ff91     ADD        ESP,0x10
    //                               LAB_0054ff94                                                 XREF[1]:     0054ff82(j)  
    //         0054ff94     MOV        EAX,dword ptr [ESP + Stack[0x28]]
    //         0054ff98     PUSH       EBP
    //         0054ff99     TEST       EAX,EAX
    //         0054ff9b     JNZ        LAB_0054ffa0
    //         0054ff9d     PUSH       ESI
    //         0054ff9e     JMP        LAB_0054ffa1
    //                               LAB_0054ffa0                                                 XREF[1]:     0054ff9b(j)  
    //         0054ffa0     PUSH       EAX
    //                               LAB_0054ffa1                                                 XREF[1]:     0054ff9e(j)  
    //         0054ffa1     CALL       _UnwindNestedFrames                              void _UnwindNestedFrames(EHRegistrationNode *
    //         0054ffa6     MOV        EDI,dword ptr [ESP + Stack[0x20]]
    //         0054ffaa     MOV        EBX,dword ptr [ESP + Stack[0x14]]
    //         0054ffae     MOV        EDX,dword ptr [ESP + Stack[0x10]]
    //         0054ffb2     MOV        ECX,dword ptr [EDI]
    //         0054ffb4     PUSH       ECX
    //         0054ffb5     PUSH       EBX
    //         0054ffb6     PUSH       EDX
    //         0054ffb7     PUSH       ESI
    //         0054ffb8     CALL       ___FrameUnwindToState                            undefined ___FrameUnwindToState()
    //         0054ffbd     MOV        EAX,dword ptr [EDI + 0x4]
    //         0054ffc0     MOV        EDX,dword ptr [ESP + Stack[0x18]]
    //         0054ffc4     MOV        ECX,dword ptr [ESP + Stack[0x24]]
    //         0054ffc8     ADD        ESP,0x10
    //         0054ffcb     INC        EAX
    //         0054ffcc     MOV        dword ptr [ESI + 0x8],EAX
    //         0054ffcf     MOV        EAX,dword ptr [EDX + 0xc]
    //         0054ffd2     PUSH       0x100
    //         0054ffd7     PUSH       ECX
    //         0054ffd8     MOV        ECX,dword ptr [ESP + Stack[0xc]]
    //         0054ffdc     PUSH       EAX
    //         0054ffdd     PUSH       EBX
    //         0054ffde     PUSH       ECX
    //         0054ffdf     PUSH       ESI
    //         0054ffe0     PUSH       EBP
    //         0054ffe1     CALL       FUN_00550000                                     undefined FUN_00550000()
    //         0054ffe6     ADD        ESP,0x1c
    //         0054ffe9     TEST       EAX,EAX
    //         0054ffeb     JZ         LAB_0054fff4
    //         0054ffed     PUSH       ESI
    //         0054ffee     PUSH       EAX
    //         0054ffef     CALL       _JumpToContinuation                              void _JumpToContinuation(void * param_1, EHRe
    //                               LAB_0054fff4                                                 XREF[1]:     0054ffeb(j)  
    //         0054fff4     POP        EDI
    //         0054fff5     POP        ESI
    //         0054fff6     POP        EBP
    //         0054fff7     POP        EBX
    //         0054fff8     RET
}

