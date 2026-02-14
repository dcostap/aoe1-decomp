// Auto-generated scaffold unit: bucket_0556.asm
#include "../include/common.h"

// Offset: 0x00556005
undefined FUN_00556005() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00556005()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00556005
    //         00556005     NOP
    //         00556006     NOP
    //         00556007     NOP
    //         00556008     NOP
    //         00556009     NOP
    //         0055600a     NOP
    //         0055600b     NOP
    //         0055600c     NOP
    //         0055600d     NOP
    //         0055600e     NOP
    //         0055600f     NOP
    //                               __add_exp
    //         00556010     MOV        EAX,dword ptr [ESP + Stack[0xa]]
    //         00556014     MOV        ECX,dword ptr [ESP + Stack[0xc]]
    //         00556018     SHR        EAX,0x4
    //         0055601b     AND        EAX,0x7ff
    //         00556020     LEA        EDX,[EAX + ECX*0x1 + 0xfffffc02]
    //         00556027     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         0055602b     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         0055602f     PUSH       EDX
    //         00556030     PUSH       EAX
    //         00556031     PUSH       ECX
    //         00556032     CALL       __set_exp                                        undefined __set_exp()
    //         00556037     ADD        ESP,0xc
    //         0055603a     RET
}

// Offset: 0x0055603B
undefined FUN_0055603b() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055603b()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined8        Stack[-0x8]:8  local_8                   XREF[2,2]:   0055604f(*), 0055606b(*), 00556062(W), 00556066(W)  
    //                               FUN_0055603b
    //         0055603b     NOP
    //         0055603c     NOP
    //         0055603d     NOP
    //         0055603e     NOP
    //         0055603f     NOP
    //                               __set_bexp
    //         00556040     SUB        ESP,0x8
    //         00556043     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00556047     MOV        EDX,dword ptr [ESP + Stack[0xa]]
    //         0055604b     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //         0055604f     MOV        dword ptr [ESP]=>local_8,EAX
    //         00556053     MOV        EAX,dword ptr [ESP + Stack[0xc]]
    //         00556057     AND        EDX,0x800f
    //         0055605d     SHL        EAX,0x4
    //         00556060     OR         EDX,EAX
    //         00556062     MOV        dword ptr [ESP + local_8+0x4],ECX
    //         00556066     MOV        word ptr [ESP + local_8+0x6],DX
    //         0055606b     FLD        double ptr [ESP]=>local_8
    //         0055606f     ADD        ESP,0x8
    //         00556072     RET
}

// Offset: 0x00556080
undefined sptype() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __sptype()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __sptype                                                     XREF[2]:     floor:0054e8f7(c), 
    //                                                                                                         ceil:0054f487(c)  
    //         00556080     MOV        EDX,dword ptr [ESP + Stack[0x8]]
    //         00556084     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         00556088     CMP        EDX,0x7ff00000
    //         0055608e     JNZ        LAB_0055609a
    //         00556090     TEST       ECX,ECX
    //         00556092     JNZ        LAB_0055609a
    //         00556094     MOV        EAX,0x1
    //         00556099     RET
    //                               LAB_0055609a                                                 XREF[2]:     0055608e(j), 00556092(j)  
    //         0055609a     CMP        EDX,0xfff00000
    //         005560a0     JNZ        LAB_005560ac
    //         005560a2     TEST       ECX,ECX
    //         005560a4     JNZ        LAB_005560ac
    //         005560a6     MOV        EAX,0x2
    //         005560ab     RET
    //                               LAB_005560ac                                                 XREF[2]:     005560a0(j), 005560a4(j)  
    //         005560ac     MOV        EAX,dword ptr [ESP + Stack[0xa]]
    //         005560b0     AND        EAX,0x7ff8
    //         005560b5     CMP        AX,0x7ff8
    //         005560b9     JNZ        LAB_005560c1
    //         005560bb     MOV        EAX,0x3
    //         005560c0     RET
    //                               LAB_005560c1                                                 XREF[1]:     005560b9(j)  
    //         005560c1     CMP        AX,0x7ff0
    //         005560c5     JNZ        LAB_005560d9
    //         005560c7     TEST       EDX,0x7ffff
    //         005560cd     JNZ        LAB_005560d3
    //         005560cf     TEST       ECX,ECX
    //         005560d1     JZ         LAB_005560d9
    //                               LAB_005560d3                                                 XREF[1]:     005560cd(j)  
    //         005560d3     MOV        EAX,0x4
    //         005560d8     RET
    //                               LAB_005560d9                                                 XREF[2]:     005560c5(j), 005560d1(j)  
    //         005560d9     XOR        EAX,EAX
    //         005560db     RET
}

// Offset: 0x005560E0
undefined decomp() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __decomp()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __decomp                                                     XREF[1]:     __handle_exc:00555d5e(c)  
    //         005560e0     FLD        double ptr [ESP + Stack[0x4]]
    //         005560e4     FCOMP      double ptr [null_00577ce0]                       = align(8)
    //         005560ea     PUSH       EBX
    //         005560eb     PUSH       ESI
    //         005560ec     PUSH       EDI
    //         005560ed     FNSTSW     AX
    //         005560ef     TEST       AH,0x40
    //         005560f2     JZ         LAB_00556114
    //         005560f4     MOV        ECX,dword ptr [ESP + Stack[0xc]]
    //         005560f8     MOV        dword ptr [ESP + Stack[0x4]],0x0
    //         00556100     MOV        dword ptr [ESP + Stack[0x8]],0x0
    //         00556108     XOR        ESI,ESI
    //         0055610a     FLD        double ptr [ESP + Stack[0x4]]
    //         0055610e     MOV        dword ptr [ECX],ESI
    //         00556110     POP        EDI
    //         00556111     POP        ESI
    //         00556112     POP        EBX
    //         00556113     RET
    //                               LAB_00556114                                                 XREF[1]:     005560f2(j)  
    //         00556114     MOV        ESI,dword ptr [ESP + Stack[0xa]]
    //         00556118     MOV        EDX,dword ptr [ESP + Stack[0x8]]
    //         0055611c     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         00556120     TEST       ESI,0x7ff0
    //         00556126     JNZ        LAB_005561b3
    //         0055612c     TEST       EDX,0xfffff
    //         00556132     JNZ        LAB_00556138
    //         00556134     TEST       ECX,ECX
    //         00556136     JZ         LAB_005561b3
    //                               LAB_00556138                                                 XREF[1]:     00556132(j)  
    //         00556138     FLD        double ptr [ESP + Stack[0x4]]
    //         0055613c     FCOMP      double ptr [null_00577ce0]                       = align(8)
    //         00556142     MOV        ESI,0xfffffc03
    //         00556147     FNSTSW     AX
    //         00556149     TEST       AH,0x1
    //         0055614c     JZ         LAB_00556155
    //         0055614e     MOV        EDI,0x1
    //         00556153     JMP        LAB_00556157
    //                               LAB_00556155                                                 XREF[1]:     0055614c(j)  
    //         00556155     XOR        EDI,EDI
    //                               LAB_00556157                                                 XREF[1]:     00556153(j)  
    //         00556157     MOV        BL,byte ptr [ESP + Stack[0xa]]
    //         0055615b     MOV        AL,0x10
    //         0055615d     TEST       AL,BL
    //         0055615f     JNZ        LAB_00556181
    //                               LAB_00556161                                                 XREF[1]:     0055617f(j)  
    //         00556161     SHL        EDX,0x1
    //         00556163     TEST       ECX,0x80000000
    //         00556169     MOV        dword ptr [ESP + Stack[0x8]],EDX
    //         0055616d     JZ         LAB_00556176
    //         0055616f     OR         EDX,0x1
    //         00556172     MOV        dword ptr [ESP + Stack[0x8]],EDX
    //                               LAB_00556176                                                 XREF[1]:     0055616d(j)  
    //         00556176     MOV        BL,byte ptr [ESP + Stack[0xa]]
    //         0055617a     SHL        ECX,0x1
    //         0055617c     DEC        ESI
    //         0055617d     TEST       AL,BL
    //         0055617f     JZ         LAB_00556161
    //                               LAB_00556181                                                 XREF[1]:     0055615f(j)  
    //         00556181     AND        word ptr [ESP + Stack[0xa]],0xffef
    //         00556188     TEST       EDI,EDI
    //         0055618a     JZ         LAB_00556191
    //         0055618c     OR         byte ptr [ESP + Stack[0xb]],0x80
    //                               LAB_00556191                                                 XREF[1]:     0055618a(j)  
    //         00556191     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         00556195     PUSH       0x0
    //         00556197     PUSH       EAX
    //         00556198     PUSH       ECX
    //         00556199     CALL       __set_exp                                        undefined __set_exp()
    //         0055619e     MOV        ECX,dword ptr [ESP + Stack[0xc]]
    //         005561a2     ADD        ESP,0xc
    //         005561a5     FSTP       double ptr [ESP + Stack[0x4]]
    //         005561a9     FLD        double ptr [ESP + Stack[0x4]]
    //         005561ad     MOV        dword ptr [ECX],ESI
    //         005561af     POP        EDI
    //         005561b0     POP        ESI
    //         005561b1     POP        EBX
    //         005561b2     RET
    //                               LAB_005561b3                                                 XREF[2]:     00556126(j), 00556136(j)  
    //         005561b3     PUSH       0x0
    //         005561b5     PUSH       EDX
    //         005561b6     PUSH       ECX
    //         005561b7     CALL       __set_exp                                        undefined __set_exp()
    //         005561bc     MOV        ECX,dword ptr [ESP + Stack[0xc]]
    //         005561c0     ADD        ESP,0xc
    //         005561c3     FSTP       double ptr [ESP + Stack[0x4]]
    //         005561c7     SHR        ESI,0x4
    //         005561ca     FLD        double ptr [ESP + Stack[0x4]]
    //         005561ce     AND        ESI,0x7ff
    //         005561d4     POP        EDI
    //         005561d5     SUB        ESI,0x3fe
    //         005561db     MOV        dword ptr [ECX],ESI
    //         005561dd     POP        ESI
    //         005561de     POP        EBX
    //         005561df     RET
}

// Offset: 0x005561E0
undefined statfp() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __statfp()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined2        Stack[-0x6]:2  local_6                   XREF[2]:     005561e4(W), 005561e8(R)  
    //                               __statfp                                                     XREF[1]:     __raise_exc:005558eb(c)  
    //         005561e0     PUSH       EBP
    //         005561e1     MOV        EBP,ESP
    //         005561e3     PUSH       ECX
    //         005561e4     FSTSW      word ptr [EBP + local_6]
    //         005561e8     MOVSX      EAX,word ptr [EBP + local_6]
    //         005561ec     MOV        ESP,EBP
    //         005561ee     POP        EBP
    //         005561ef     RET
}

// Offset: 0x005561F0
undefined clrfp() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __clrfp()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined2        Stack[-0x6]:2  local_6                   XREF[2]:     005561f4(W), 005561f9(R)  
    //                               __clrfp                                                      XREF[1]:     __raise_exc:00555a3d(c)  
    //         005561f0     PUSH       EBP
    //         005561f1     MOV        EBP,ESP
    //         005561f3     PUSH       ECX
    //         005561f4     FNSTSW     word ptr [EBP + local_6]
    //         005561f7     FNCLEX
    //         005561f9     MOVSX      EAX,word ptr [EBP + local_6]
    //         005561fd     MOV        ESP,EBP
    //         005561ff     POP        EBP
    //         00556200     RET
}

// Offset: 0x00556210
undefined ctrlfp() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __ctrlfp()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     00556214(W), 00556222(R)  
    //                               __ctrlfp                                                     XREF[12]:    floor:0054e8d1(c), 
    //                                                                                                         floor:0054e927(c), 
    //                                                                                                         floor:0054e986(c), 
    //                                                                                                         ceil:0054f461(c), 
    //                                                                                                         ceil:0054f4b7(c), 
    //                                                                                                         ceil:0054f516(c), 
    //                                                                                                         __handle_qnan1:005555b2(c), 
    //                                                                                                         FUN_005555bf:00555622(c), 
    //                                                                                                         __except1:005556ea(c), 
    //                                                                                                         FUN_005556fc:005557d7(c), 
    //                                                                                                         __umatherr:00555ebb(c), 
    //                                                                                                         __umatherr:00555ef0(c)  
    //         00556210     PUSH       EBP
    //         00556211     MOV        EBP,ESP
    //         00556213     PUSH       ECX
    //         00556214     FSTCW      word ptr [EBP + local_8]
    //         00556218     MOV        EAX,dword ptr [EBP + Stack[0x8]]
    //         0055621b     MOV        ECX,dword ptr [EBP + Stack[0x4]]
    //         0055621e     MOV        EDX,EAX
    //         00556220     AND        EDX,ECX
    //         00556222     MOV        ECX,dword ptr [EBP + local_8]
    //         00556225     NOT        EAX
    //         00556227     AND        EAX,ECX
    //         00556229     OR         EDX,EAX
    //         0055622b     MOV        dword ptr [EBP + Stack[0x8]],EDX
    //         0055622e     FLDCW      word ptr [EBP + Stack[0x8]]
    //         00556231     MOVSX      EAX,CX
    //         00556234     MOV        ESP,EBP
    //         00556236     POP        EBP
    //         00556237     RET
}

// Offset: 0x00556240
undefined set_statfp() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __set_statfp()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined8        Stack[-0xc]:8  local_c                   XREF[3]:     00556266(W), 00556278(W), 00556291(W)  
    //                               __set_statfp                                                 XREF[5]:     __handle_exc:00555b57(c), 
    //                                                                                                         __handle_exc:00555b78(c), 
    //                                                                                                         __handle_exc:00555b9e(c), 
    //                                                                                                         __handle_exc:00555e22(c), 
    //                                                                                                         __handle_exc:00555e47(c)  
    //         00556240     PUSH       EBP
    //         00556241     MOV        EBP,ESP
    //         00556243     SUB        ESP,0x8
    //         00556246     MOV        CL,byte ptr [EBP + Stack[0x4]]
    //         00556249     TEST       CL,0x1
    //         0055624c     JZ         LAB_00556258
    //         0055624e     FLD        extended double ptr [DAT_00592558]
    //         00556254     FISTP      dword ptr [EBP + Stack[0x4]]
    //         00556257     WAIT
    //                               LAB_00556258                                                 XREF[1]:     0055624c(j)  
    //         00556258     TEST       CL,0x8
    //         0055625b     JZ         LAB_0055626d
    //         0055625d     FSTSW      AX
    //         00556260     FLD        extended double ptr [DAT_00592558]
    //         00556266     FSTP       double ptr [EBP + local_c]
    //         00556269     WAIT
    //         0055626a     FSTSW      AX
    //                               LAB_0055626d                                                 XREF[1]:     0055625b(j)  
    //         0055626d     TEST       CL,0x10
    //         00556270     JZ         LAB_0055627c
    //         00556272     FLD        extended double ptr [DAT_00592568]               = 01h
    //         00556278     FSTP       double ptr [EBP + local_c]
    //         0055627b     WAIT
    //                               LAB_0055627c                                                 XREF[1]:     00556270(j)  
    //         0055627c     TEST       CL,0x4
    //         0055627f     JZ         LAB_0055628a
    //         00556281     FLDZ
    //         00556283     FLD1
    //         00556285     FDIVRP
    //         00556287     FSTP       ST0
    //         00556289     WAIT
    //                               LAB_0055628a                                                 XREF[1]:     0055627f(j)  
    //         0055628a     TEST       CL,0x20
    //         0055628d     JZ         LAB_00556295
    //         0055628f     FLDPI
    //         00556291     FSTP       double ptr [EBP + local_c]
    //         00556294     WAIT
    //                               LAB_00556295                                                 XREF[1]:     0055628d(j)  
    //         00556295     MOV        ESP,EBP
    //         00556297     POP        EBP
    //         00556298     RET
}

// Offset: 0x005562A0
undefined realloc() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * realloc                                                                                               *
    //                              *********************************************************************************************************
    //                              undefined __cdecl realloc()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     0055630a(*), 00556333(R), 0055638d(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[3]:     00556306(*), 0055632f(R), 00556389(R)  
    //                               _realloc                                                     XREF[3]:     __onexit:0054eaca(c), 
    //                               realloc                                                                   ___crtsetenv:0055a542(c), 
    //                                                                                                         ___crtsetenv:0055a5f2(c)  
    //         005562a0     SUB        ESP,0x8
    //         005562a3     PUSH       EBX
    //         005562a4     PUSH       EBP
    //         005562a5     PUSH       ESI
    //         005562a6     PUSH       EDI
    //         005562a7     MOV        EDI,dword ptr [ESP + Stack[0x4]]
    //         005562ab     TEST       EDI,EDI
    //         005562ad     JNZ        LAB_005562c4
    //         005562af     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         005562b3     PUSH       EAX
    //         005562b4     CALL       malloc                                           undefined malloc()
    //         005562b9     ADD        ESP,0x4
    //         005562bc     POP        EDI
    //         005562bd     POP        ESI
    //         005562be     POP        EBP
    //         005562bf     POP        EBX
    //         005562c0     ADD        ESP,0x8
    //         005562c3     RET
    //                               LAB_005562c4                                                 XREF[1]:     005562ad(j)  
    //         005562c4     MOV        EBP,dword ptr [ESP + Stack[0x8]]
    //         005562c8     TEST       EBP,EBP
    //         005562ca     JNZ        LAB_005562df
    //         005562cc     PUSH       EDI
    //         005562cd     CALL       free                                             undefined free()
    //         005562d2     ADD        ESP,0x4
    //         005562d5     XOR        EAX,EAX
    //         005562d7     POP        EDI
    //         005562d8     POP        ESI
    //         005562d9     POP        EBP
    //         005562da     POP        EBX
    //         005562db     ADD        ESP,0x8
    //         005562de     RET
    //                               LAB_005562df                                                 XREF[1]:     005562ca(j)  
    //         005562df     CMP        EBP,-0x20
    //         005562e2     JA         LAB_005562fb
    //         005562e4     TEST       EBP,EBP
    //         005562e6     JBE        LAB_005562f0
    //         005562e8     ADD        EBP,0xf
    //         005562eb     AND        EBP,0xfffffff0
    //         005562ee     JMP        LAB_005562fb
    //                               LAB_005562f0                                                 XREF[1]:     005562e6(j)  
    //         005562f0     MOV        EBP,0x10
    //         005562f5     JMP        LAB_005562fb
    //                               LAB_005562f7                                                 XREF[1]:     00556422(j)  
    //         005562f7     MOV        EDI,dword ptr [ESP + 0x1c]
    //                               LAB_005562fb                                                 XREF[3]:     005562e2(j), 005562ee(j), 
    //                                                                                                         005562f5(j)  
    //         005562fb     XOR        EBX,EBX
    //         005562fd     CMP        EBP,-0x20
    //         00556300     JA         LAB_0055640a
    //         00556306     LEA        ECX=>local_8,[ESP + 0x10]
    //         0055630a     LEA        EDX=>local_4,[ESP + 0x14]
    //         0055630e     PUSH       ECX
    //         0055630f     PUSH       EDX
    //         00556310     PUSH       EDI
    //         00556311     CALL       ___sbh_find_block                                undefined ___sbh_find_block()
    //         00556316     MOV        ESI,EAX
    //         00556318     ADD        ESP,0xc
    //         0055631b     TEST       ESI,ESI
    //         0055631d     MOV        dword ptr [ESP + Stack[0x8]],ESI
    //         00556321     JZ         LAB_005563f8
    //         00556327     CMP        EBP,dword ptr [___sbh_threshold]                 = 000001E0h
    //         0055632d     JNC        LAB_0055639f
    //         0055632f     MOV        EAX,dword ptr [ESP + local_8]
    //         00556333     MOV        ECX,dword ptr [ESP + local_4]
    //         00556337     MOV        EDI,EBP
    //         00556339     SHR        EDI,0x4
    //         0055633c     PUSH       EDI
    //         0055633d     PUSH       ESI
    //         0055633e     PUSH       EAX
    //         0055633f     PUSH       ECX
    //         00556340     CALL       ___sbh_resize_block                              undefined ___sbh_resize_block()
    //         00556345     ADD        ESP,0x10
    //         00556348     TEST       EAX,EAX
    //         0055634a     JZ         LAB_00556352
    //         0055634c     MOV        EBX,dword ptr [ESP + Stack[0x4]]
    //         00556350     JMP        LAB_0055639f
    //                               LAB_00556352                                                 XREF[1]:     0055634a(j)  
    //         00556352     PUSH       EDI
    //         00556353     CALL       ___sbh_alloc_block                               undefined ___sbh_alloc_block()
    //         00556358     MOV        EBX,EAX
    //         0055635a     ADD        ESP,0x4
    //         0055635d     TEST       EBX,EBX
    //         0055635f     JZ         LAB_005563a7
    //         00556361     XOR        EAX,EAX
    //         00556363     MOV        AL,byte ptr [ESI]
    //         00556365     SHL        EAX,0x4
    //         00556368     CMP        EAX,EBP
    //         0055636a     JC         LAB_0055636e
    //         0055636c     MOV        EAX,EBP
    //                               LAB_0055636e                                                 XREF[1]:     0055636a(j)  
    //         0055636e     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         00556372     MOV        ECX,EAX
    //         00556374     MOV        EDX,ECX
    //         00556376     MOV        EDI,EBX
    //         00556378     SHR        ECX,0x2
    //         0055637b     MOVSD.REP  ES:EDI,ESI
    //         0055637d     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         00556381     MOV        ECX,EDX
    //         00556383     AND        ECX,0x3
    //         00556386     PUSH       EAX
    //         00556387     MOVSB.REP  ES:EDI,ESI
    //         00556389     MOV        ECX,dword ptr [ESP + local_8]
    //         0055638d     MOV        EDX,dword ptr [ESP + local_4]
    //         00556391     PUSH       ECX
    //         00556392     PUSH       EDX
    //         00556393     CALL       ___sbh_free_block                                undefined ___sbh_free_block()
    //         00556398     MOV        ESI,dword ptr [ESP + Stack[0x8]]
    //         0055639c     ADD        ESP,0xc
    //                               LAB_0055639f                                                 XREF[2]:     0055632d(j), 00556350(j)  
    //         0055639f     TEST       EBX,EBX
    //         005563a1     JNZ        LAB_00556430
    //                               LAB_005563a7                                                 XREF[1]:     0055635f(j)  
    //         005563a7     MOV        EAX,[__crtheap]
    //         005563ac     PUSH       EBP
    //         005563ad     PUSH       0x0
    //         005563af     PUSH       EAX
    //         005563b0     CALL       dword ptr [->KERNEL32.DLL::HeapAlloc]            = 0048b6ac
    //         005563b6     MOV        EBX,EAX
    //         005563b8     TEST       EBX,EBX
    //         005563ba     JZ         LAB_0055640e
    //         005563bc     XOR        EAX,EAX
    //         005563be     MOV        AL,byte ptr [ESI]
    //         005563c0     SHL        EAX,0x4
    //         005563c3     CMP        EAX,EBP
    //         005563c5     JC         LAB_005563c9
    //         005563c7     MOV        EAX,EBP
    //                               LAB_005563c9                                                 XREF[1]:     005563c5(j)  
    //         005563c9     MOV        ESI,dword ptr [ESP + 0x1c]
    //         005563cd     MOV        ECX,EAX
    //         005563cf     MOV        EDX,ECX
    //         005563d1     MOV        EDI,EBX
    //         005563d3     SHR        ECX,0x2
    //         005563d6     MOVSD.REP  ES:EDI,ESI
    //         005563d8     MOV        EAX,dword ptr [ESP + 0x20]
    //         005563dc     MOV        ECX,EDX
    //         005563de     AND        ECX,0x3
    //         005563e1     PUSH       EAX
    //         005563e2     MOVSB.REP  ES:EDI,ESI
    //         005563e4     MOV        ECX,dword ptr [ESP + 0x14]
    //         005563e8     MOV        EDX,dword ptr [ESP + 0x18]
    //         005563ec     PUSH       ECX
    //         005563ed     PUSH       EDX
    //         005563ee     CALL       ___sbh_free_block                                undefined ___sbh_free_block()
    //         005563f3     ADD        ESP,0xc
    //         005563f6     JMP        LAB_0055640a
    //                               LAB_005563f8                                                 XREF[1]:     00556321(j)  
    //         005563f8     MOV        EAX,[__crtheap]
    //         005563fd     PUSH       EBP
    //         005563fe     PUSH       EDI
    //         005563ff     PUSH       0x0
    //         00556401     PUSH       EAX
    //         00556402     CALL       dword ptr [->KERNEL32.DLL::HeapReAlloc]          = 0048b942
    //         00556408     MOV        EBX,EAX
    //                               LAB_0055640a                                                 XREF[2]:     00556300(j), 005563f6(j)  
    //         0055640a     TEST       EBX,EBX
    //         0055640c     JNZ        LAB_00556430
    //                               LAB_0055640e                                                 XREF[1]:     005563ba(j)  
    //         0055640e     MOV        EAX,[__newmode]
    //         00556413     TEST       EAX,EAX
    //         00556415     JZ         LAB_00556430
    //         00556417     PUSH       EBP
    //         00556418     CALL       __callnewh                                       undefined __callnewh()
    //         0055641d     ADD        ESP,0x4
    //         00556420     TEST       EAX,EAX
    //         00556422     JNZ        LAB_005562f7
    //         00556428     POP        EDI
    //         00556429     POP        ESI
    //         0055642a     POP        EBP
    //         0055642b     POP        EBX
    //         0055642c     ADD        ESP,0x8
    //         0055642f     RET
    //                               LAB_00556430                                                 XREF[3]:     005563a1(j), 0055640c(j), 
    //                                                                                                         00556415(j)  
    //         00556430     POP        EDI
    //         00556431     POP        ESI
    //         00556432     MOV        EAX,EBX
    //         00556434     POP        EBP
    //         00556435     POP        EBX
    //         00556436     ADD        ESP,0x8
    //         00556439     RET
}

// Offset: 0x00556440
undefined msize() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __msize()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined         Stack[-0x4]:1  local_4                   XREF[1]:     0055644a(*)  
    //                               __msize                                                      XREF[2]:     __onexit:0054ea97(c), 
    //                                                                                                         __onexit:0054eab7(c)  
    //         00556440     PUSH       ECX
    //         00556441     LEA        EAX=>Stack[0x4],[ESP + 0x8]
    //         00556445     PUSH       ESI
    //         00556446     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         0055644a     LEA        ECX=>local_4,[ESP + 0x4]
    //         0055644e     PUSH       EAX
    //         0055644f     PUSH       ECX
    //         00556450     PUSH       ESI
    //         00556451     CALL       ___sbh_find_block                                undefined ___sbh_find_block()
    //         00556456     ADD        ESP,0xc
    //         00556459     TEST       EAX,EAX
    //         0055645b     JZ         LAB_00556469
    //         0055645d     XOR        EDX,EDX
    //         0055645f     MOV        DL,byte ptr [EAX]
    //         00556461     MOV        EAX,EDX
    //         00556463     SHL        EAX,0x4
    //         00556466     POP        ESI
    //         00556467     POP        ECX
    //         00556468     RET
    //                               LAB_00556469                                                 XREF[1]:     0055645b(j)  
    //         00556469     MOV        EAX,[__crtheap]
    //         0055646e     PUSH       ESI
    //         0055646f     PUSH       0x0
    //         00556471     PUSH       EAX
    //         00556472     CALL       dword ptr [->KERNEL32.DLL::HeapSize]             = 0048b950
    //         00556478     POP        ESI
    //         00556479     POP        ECX
    //         0055647a     RET
}

// Offset: 0x00556480
undefined ftell() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * ftell                                                                                                 *
    //                              *********************************************************************************************************
    //                              undefined __cdecl ftell()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[6]:     005564ad(W), 00556519(R), 0055653c(R), 00556582(R), 
    //                                                                                     005565f1(RW), 005565f5(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[4]:     005564e2(W), 00556515(W), 00556542(W), 005565ed(R)  
    //                               _ftell                                                       XREF[1]:     fseek:0054f28a(c)  
    //                               ftell
    //         00556480     SUB        ESP,0x8
    //         00556483     PUSH       EBX
    //         00556484     PUSH       EBP
    //         00556485     PUSH       ESI
    //         00556486     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         0055648a     PUSH       EDI
    //         0055648b     MOV        EAX,dword ptr [ESI + 0x4]
    //         0055648e     MOV        EBX,dword ptr [ESI + 0x10]
    //         00556491     TEST       EAX,EAX
    //         00556493     JGE        LAB_0055649c
    //         00556495     MOV        dword ptr [ESI + 0x4],0x0
    //                               LAB_0055649c                                                 XREF[1]:     00556493(j)  
    //         0055649c     PUSH       0x1
    //         0055649e     PUSH       0x0
    //         005564a0     PUSH       EBX
    //         005564a1     CALL       lseek                                            undefined lseek()
    //         005564a6     MOV        ECX,EAX
    //         005564a8     ADD        ESP,0xc
    //         005564ab     TEST       ECX,ECX
    //         005564ad     MOV        dword ptr [ESP + local_4],ECX
    //         005564b1     JGE        LAB_005564be
    //         005564b3     OR         EAX,0xffffffff
    //         005564b6     POP        EDI
    //         005564b7     POP        ESI
    //         005564b8     POP        EBP
    //         005564b9     POP        EBX
    //         005564ba     ADD        ESP,0x8
    //         005564bd     RET
    //                               LAB_005564be                                                 XREF[1]:     005564b1(j)  
    //         005564be     MOV        EAX,dword ptr [ESI + 0xc]
    //         005564c1     TEST       EAX,0x108
    //         005564c6     JNZ        LAB_005564d7
    //         005564c8     MOV        EAX,ECX
    //         005564ca     MOV        ECX,dword ptr [ESI + 0x4]
    //         005564cd     SUB        EAX,ECX
    //         005564cf     POP        EDI
    //         005564d0     POP        ESI
    //         005564d1     POP        EBP
    //         005564d2     POP        EBX
    //         005564d3     ADD        ESP,0x8
    //         005564d6     RET
    //                               LAB_005564d7                                                 XREF[1]:     005564c6(j)  
    //         005564d7     MOV        ECX,dword ptr [ESI]
    //         005564d9     MOV        EBP,dword ptr [ESI + 0x8]
    //         005564dc     MOV        EDX,ECX
    //         005564de     SUB        EDX,EBP
    //         005564e0     TEST       AL,0x3
    //         005564e2     MOV        dword ptr [ESP + local_8],EDX
    //         005564e6     JZ         LAB_00556604
    //         005564ec     MOV        EAX,EBX
    //         005564ee     MOV        EDI,EBX
    //         005564f0     SAR        EAX,0x5
    //         005564f3     AND        EDI,0x1f
    //         005564f6     MOV        EAX,dword ptr [EAX*0x4 + ___pioinfo]
    //         005564fd     TEST       byte ptr [EAX + EDI*0x8 + 0x4],0x80
    //         00556502     JZ         LAB_00556519
    //         00556504     MOV        EAX,EBP
    //         00556506     CMP        EAX,ECX
    //         00556508     JNC        LAB_00556519
    //                               LAB_0055650a                                                 XREF[1]:     00556513(j)  
    //         0055650a     CMP        byte ptr [EAX],0xa
    //         0055650d     JNZ        LAB_00556510
    //         0055650f     INC        EDX
    //                               LAB_00556510                                                 XREF[1]:     0055650d(j)  
    //         00556510     INC        EAX
    //         00556511     CMP        EAX,ECX
    //         00556513     JC         LAB_0055650a
    //         00556515     MOV        dword ptr [ESP + local_8],EDX
    //                               LAB_00556519                                                 XREF[3]:     00556502(j), 00556508(j), 
    //                                                                                                         00556606(j)  
    //         00556519     MOV        EAX,dword ptr [ESP + local_4]
    //         0055651d     TEST       EAX,EAX
    //         0055651f     JNZ        LAB_0055652b
    //         00556521     MOV        EAX,EDX
    //         00556523     POP        EDI
    //         00556524     POP        ESI
    //         00556525     POP        EBP
    //         00556526     POP        EBX
    //         00556527     ADD        ESP,0x8
    //         0055652a     RET
    //                               LAB_0055652b                                                 XREF[1]:     0055651f(j)  
    //         0055652b     TEST       byte ptr [ESI + 0xc],0x1
    //         0055652f     JZ         LAB_005565f5
    //         00556535     MOV        EAX,dword ptr [ESI + 0x4]
    //         00556538     TEST       EAX,EAX
    //         0055653a     JNZ        LAB_00556551
    //         0055653c     MOV        ECX,dword ptr [ESP + local_4]
    //         00556540     MOV        EDX,EAX
    //         00556542     MOV        dword ptr [ESP + local_8],EAX
    //         00556546     LEA        EAX,[ECX + EDX*0x1]
    //         00556549     POP        EDI
    //         0055654a     POP        ESI
    //         0055654b     POP        EBP
    //         0055654c     POP        EBX
    //         0055654d     ADD        ESP,0x8
    //         00556550     RET
    //                               LAB_00556551                                                 XREF[1]:     0055653a(j)  
    //         00556551     LEA        EDI,[ECX + EAX*0x1]
    //         00556554     MOV        ECX,EBX
    //         00556556     SAR        ECX,0x5
    //         00556559     SUB        EDI,EBP
    //         0055655b     MOV        ESI,EBX
    //         0055655d     MOV        EAX,dword ptr [ECX*0x4 + ___pioinfo]
    //         00556564     LEA        EBP,[ECX*0x4 + ___pioinfo]
    //         0055656b     AND        ESI,0x1f
    //         0055656e     SHL        ESI,0x3
    //         00556571     TEST       byte ptr [ESI + EAX*0x1 + 0x4],0x80
    //         00556576     JZ         LAB_005565f1
    //         00556578     PUSH       0x2
    //         0055657a     PUSH       0x0
    //         0055657c     PUSH       EBX
    //         0055657d     CALL       lseek                                            undefined lseek()
    //         00556582     MOV        ECX,dword ptr [ESP + local_4]
    //         00556586     ADD        ESP,0xc
    //         00556589     CMP        EAX,ECX
    //         0055658b     JNZ        LAB_005565b0
    //         0055658d     MOV        EDX,dword ptr [ESP + Stack[0x4]]
    //         00556591     MOV        EAX,dword ptr [EDX + 0x8]
    //         00556594     LEA        ECX,[EDI + EAX*0x1]
    //         00556597     CMP        EAX,ECX
    //         00556599     JNC        LAB_005565a6
    //                               LAB_0055659b                                                 XREF[1]:     005565a4(j)  
    //         0055659b     CMP        byte ptr [EAX],0xa
    //         0055659e     JNZ        LAB_005565a1
    //         005565a0     INC        EDI
    //                               LAB_005565a1                                                 XREF[1]:     0055659e(j)  
    //         005565a1     INC        EAX
    //         005565a2     CMP        EAX,ECX
    //         005565a4     JC         LAB_0055659b
    //                               LAB_005565a6                                                 XREF[1]:     00556599(j)  
    //         005565a6     MOV        EAX,dword ptr [EDX + 0xc]
    //         005565a9     TEST       AH,0x20
    //         005565ac     JZ         LAB_005565ed
    //         005565ae     JMP        LAB_005565ec
    //                               LAB_005565b0                                                 XREF[1]:     0055658b(j)  
    //         005565b0     PUSH       0x0
    //         005565b2     PUSH       ECX
    //         005565b3     PUSH       EBX
    //         005565b4     CALL       lseek                                            undefined lseek()
    //         005565b9     ADD        ESP,0xc
    //         005565bc     CMP        EDI,0x200
    //         005565c2     JA         LAB_005565db
    //         005565c4     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         005565c8     MOV        EAX,dword ptr [ECX + 0xc]
    //         005565cb     TEST       AL,0x8
    //         005565cd     JZ         LAB_005565db
    //         005565cf     TEST       AH,0x4
    //         005565d2     JNZ        LAB_005565db
    //         005565d4     MOV        EDI,0x200
    //         005565d9     JMP        LAB_005565e2
    //                               LAB_005565db                                                 XREF[3]:     005565c2(j), 005565cd(j), 
    //                                                                                                         005565d2(j)  
    //         005565db     MOV        EDX,dword ptr [ESP + Stack[0x4]]
    //         005565df     MOV        EDI,dword ptr [EDX + 0x18]
    //                               LAB_005565e2                                                 XREF[1]:     005565d9(j)  
    //         005565e2     MOV        EAX,dword ptr [EBP]=>___pioinfo
    //         005565e5     TEST       byte ptr [ESI + EAX*0x1 + 0x4],0x4
    //         005565ea     JZ         LAB_005565ed
    //                               LAB_005565ec                                                 XREF[1]:     005565ae(j)  
    //         005565ec     INC        EDI
    //                               LAB_005565ed                                                 XREF[2]:     005565ac(j), 005565ea(j)  
    //         005565ed     MOV        EDX,dword ptr [ESP + local_8]
    //                               LAB_005565f1                                                 XREF[1]:     00556576(j)  
    //         005565f1     SUB        dword ptr [ESP + local_4],EDI
    //                               LAB_005565f5                                                 XREF[1]:     0055652f(j)  
    //         005565f5     MOV        ECX,dword ptr [ESP + local_4]
    //         005565f9     LEA        EAX,[ECX + EDX*0x1]
    //         005565fc     POP        EDI
    //         005565fd     POP        ESI
    //         005565fe     POP        EBP
    //         005565ff     POP        EBX
    //         00556600     ADD        ESP,0x8
    //         00556603     RET
    //                               LAB_00556604                                                 XREF[1]:     005564e6(j)  
    //         00556604     TEST       AL,0x80
    //         00556606     JNZ        LAB_00556519
    //         0055660c     POP        EDI
    //         0055660d     POP        ESI
    //         0055660e     POP        EBP
    //         0055660f     MOV        dword ptr [_errno],0x16                          = align(4)
    //         00556619     OR         EAX,0xffffffff
    //         0055661c     POP        EBX
    //         0055661d     ADD        ESP,0x8
    //         00556620     RET
}

// Offset: 0x00556630
undefined XcptFilter() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __XcptFilter()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __XcptFilter                                                 XREF[1]:     FUN_0054f9ba:0054f9c6(c)  
    //         00556630     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00556634     PUSH       EBX
    //         00556635     PUSH       EBP
    //         00556636     PUSH       ESI
    //         00556637     PUSH       EAX
    //         00556638     CALL       FUN_00556770                                     undefined FUN_00556770()
    //         0055663d     ADD        ESP,0x4
    //         00556640     TEST       EAX,EAX
    //         00556642     JZ         LAB_0055675f
    //         00556648     MOV        EBX,dword ptr [EAX + 0x8]
    //         0055664b     TEST       EBX,EBX
    //         0055664d     JZ         LAB_0055675f
    //         00556653     CMP        EBX,0x5
    //         00556656     JNZ        LAB_00556668
    //         00556658     MOV        dword ptr [EAX + 0x8],0x0
    //         0055665f     MOV        EAX,0x1
    //         00556664     POP        ESI
    //         00556665     POP        EBP
    //         00556666     POP        EBX
    //         00556667     RET
    //                               LAB_00556668                                                 XREF[1]:     00556656(j)  
    //         00556668     CMP        EBX,0x1
    //         0055666b     JNZ        LAB_00556674
    //         0055666d     OR         EAX,0xffffffff
    //         00556670     POP        ESI
    //         00556671     POP        EBP
    //         00556672     POP        EBX
    //         00556673     RET
    //                               LAB_00556674                                                 XREF[1]:     0055666b(j)  
    //         00556674     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //         00556678     MOV        EBP,dword ptr [__pxcptinfoptrs]
    //         0055667e     MOV        dword ptr [__pxcptinfoptrs],ECX
    //         00556684     MOV        ECX,dword ptr [EAX + 0x4]
    //         00556687     CMP        ECX,0x8
    //         0055668a     JNZ        LAB_00556745
    //         00556690     MOV        ESI,dword ptr [__First_FPE_Indx]                 = 00000003h
    //         00556696     MOV        EDX,dword ptr [__Num_FPE]                        = 00000007h
    //         0055669c     ADD        EDX,ESI
    //         0055669e     CMP        ESI,EDX
    //         005566a0     JGE        LAB_005566ba
    //         005566a2     LEA        ECX,[ESI + ESI*0x2]
    //         005566a5     SUB        EDX,ESI
    //         005566a7     LEA        ECX,[ECX*0x4 + 0x592580]=>DAT_005925a4
    //                               LAB_005566ae                                                 XREF[1]:     005566b8(j)  
    //         005566ae     MOV        dword ptr [ECX]=>DAT_005925a4,0x0
    //         005566b4     ADD        ECX,0xc
    //         005566b7     DEC        EDX
    //         005566b8     JNZ        LAB_005566ae
    //                               LAB_005566ba                                                 XREF[1]:     005566a0(j)  
    //         005566ba     MOV        EAX,dword ptr [EAX]
    //         005566bc     MOV        ECX,dword ptr [__fpecode]                        = 0000008Ch
    //         005566c2     CMP        EAX,0xc000008e
    //         005566c7     MOV        ESI,ECX
    //         005566c9     JNZ        LAB_005566d2
    //         005566cb     MOV        ECX,0x83
    //         005566d0     JMP        LAB_00556724
    //                               LAB_005566d2                                                 XREF[1]:     005566c9(j)  
    //         005566d2     CMP        EAX,0xc0000090
    //         005566d7     JNZ        LAB_005566e0
    //         005566d9     MOV        ECX,0x81
    //         005566de     JMP        LAB_00556724
    //                               LAB_005566e0                                                 XREF[1]:     005566d7(j)  
    //         005566e0     CMP        EAX,0xc0000091
    //         005566e5     JNZ        LAB_005566ee
    //         005566e7     MOV        ECX,0x84
    //         005566ec     JMP        LAB_00556724
    //                               LAB_005566ee                                                 XREF[1]:     005566e5(j)  
    //         005566ee     CMP        EAX,0xc0000093
    //         005566f3     JNZ        LAB_005566fc
    //         005566f5     MOV        ECX,0x85
    //         005566fa     JMP        LAB_00556724
    //                               LAB_005566fc                                                 XREF[1]:     005566f3(j)  
    //         005566fc     CMP        EAX,0xc000008d
    //         00556701     JNZ        LAB_0055670a
    //                              language.dll match for 0x82: "B"
    //         00556703     MOV        ECX,0x82
    //         00556708     JMP        LAB_00556724
    //                               LAB_0055670a                                                 XREF[1]:     00556701(j)  
    //         0055670a     CMP        EAX,0xc000008f
    //         0055670f     JNZ        LAB_00556718
    //         00556711     MOV        ECX,0x86
    //         00556716     JMP        LAB_00556724
    //                               LAB_00556718                                                 XREF[1]:     0055670f(j)  
    //         00556718     CMP        EAX,0xc0000092
    //         0055671d     JNZ        LAB_0055672a
    //         0055671f     MOV        ECX,0x8a
    //                               LAB_00556724                                                 XREF[6]:     005566d0(j), 005566de(j), 
    //                                                                                                         005566ec(j), 005566fa(j), 
    //                                                                                                         00556708(j), 00556716(j)  
    //         00556724     MOV        dword ptr [__fpecode],ECX                        = 0000008Ch
    //                               LAB_0055672a                                                 XREF[1]:     0055671d(j)  
    //         0055672a     PUSH       ECX
    //         0055672b     PUSH       0x8
    //         0055672d     CALL       EBX
    //         0055672f     ADD        ESP,0x8
    //         00556732     MOV        dword ptr [__fpecode],ESI                        = 0000008Ch
    //         00556738     MOV        dword ptr [__pxcptinfoptrs],EBP
    //         0055673e     OR         EAX,0xffffffff
    //         00556741     POP        ESI
    //         00556742     POP        EBP
    //         00556743     POP        EBX
    //         00556744     RET
    //                               LAB_00556745                                                 XREF[1]:     0055668a(j)  
    //         00556745     PUSH       ECX
    //         00556746     MOV        dword ptr [EAX + 0x8],0x0
    //         0055674d     CALL       EBX
    //         0055674f     ADD        ESP,0x4
    //         00556752     MOV        dword ptr [__pxcptinfoptrs],EBP
    //         00556758     OR         EAX,0xffffffff
    //         0055675b     POP        ESI
    //         0055675c     POP        EBP
    //         0055675d     POP        EBX
    //         0055675e     RET
    //                               LAB_0055675f                                                 XREF[2]:     00556642(j), 0055664d(j)  
    //         0055675f     MOV        EDX,dword ptr [ESP + Stack[0x8]]
    //         00556763     PUSH       EDX
    //         00556764     CALL       dword ptr [->KERNEL32.DLL::UnhandledExceptionF   = 0048b95c
    //         0055676a     POP        ESI
    //         0055676b     POP        EBP
    //         0055676c     POP        EBX
    //         0055676d     RET
}

// Offset: 0x00556770
undefined FUN_00556770() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00556770()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00556770                                                 XREF[1]:     __XcptFilter:00556638(c)  
    //         00556770     MOV        EDX,dword ptr [ESP + Stack[0x4]]
    //         00556774     MOV        ECX,dword ptr [__XcptActTab]                     = C0000005h
    //         0055677a     PUSH       ESI
    //         0055677b     MOV        ESI,dword ptr [__XcptActTabCount]                = 0000000Ah
    //         00556781     CMP        ECX,EDX
    //         00556783     MOV        EAX,__XcptActTab                                 = C0000005h
    //         00556788     JZ         LAB_0055679f
    //         0055678a     LEA        ECX,[ESI + ESI*0x2]
    //         0055678d     LEA        ECX,[ECX*0x4 + 0x592578]=>__First_FPE_Indx       = 00000003h
    //                               LAB_00556794                                                 XREF[1]:     0055679d(j)  
    //         00556794     ADD        EAX=>DAT_00592584,0xc                            = C000001Dh
    //         00556797     CMP        EAX,ECX
    //         00556799     JNC        LAB_0055679f
    //         0055679b     CMP        dword ptr [EAX]=>DAT_00592584,EDX                = C000001Dh
    //                                                                                  = C0000096h
    //         0055679d     JNZ        LAB_00556794
    //                               LAB_0055679f                                                 XREF[2]:     00556788(j), 00556799(j)  
    //         0055679f     LEA        ECX,[ESI + ESI*0x2]
    //         005567a2     LEA        ECX,[ECX*0x4 + 0x592578]=>__First_FPE_Indx       = 00000003h
    //         005567a9     CMP        EAX,ECX
    //         005567ab     JNC        LAB_005567b1
    //         005567ad     CMP        dword ptr [EAX]=>DAT_00592584,EDX                = C0000005h
    //                                                                                  = C000001Dh
    //                                                                                  = C0000096h
    //         005567af     JZ         LAB_005567b3
    //                               LAB_005567b1                                                 XREF[1]:     005567ab(j)  
    //         005567b1     XOR        EAX,EAX
    //                               LAB_005567b3                                                 XREF[1]:     005567af(j)  
    //         005567b3     POP        ESI
    //         005567b4     RET
}

// Offset: 0x005567B5
undefined FUN_005567b5() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005567b5()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005567b5
    //         005567b5     NOP
    //         005567b6     NOP
    //         005567b7     NOP
    //         005567b8     NOP
    //         005567b9     NOP
    //         005567ba     NOP
    //         005567bb     NOP
    //         005567bc     NOP
    //         005567bd     NOP
    //         005567be     NOP
    //         005567bf     NOP
    //                               __ismbbkalnum
    //         005567c0     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         005567c4     PUSH       0x1
    //         005567c6     PUSH       0x0
    //         005567c8     PUSH       EAX
    //         005567c9     CALL       FUN_00556930                                     undefined FUN_00556930()
    //         005567ce     ADD        ESP,0xc
    //         005567d1     RET
}

// Offset: 0x005567D2
undefined FUN_005567d2() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005567d2()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005567d2
    //         005567d2     NOP
    //         005567d3     NOP
    //         005567d4     NOP
    //         005567d5     NOP
    //         005567d6     NOP
    //         005567d7     NOP
    //         005567d8     NOP
    //         005567d9     NOP
    //         005567da     NOP
    //         005567db     NOP
    //         005567dc     NOP
    //         005567dd     NOP
    //         005567de     NOP
    //         005567df     NOP
    //                               __ismbbkprint
    //         005567e0     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         005567e4     PUSH       0x3
    //         005567e6     PUSH       0x0
    //         005567e8     PUSH       EAX
    //         005567e9     CALL       FUN_00556930                                     undefined FUN_00556930()
    //         005567ee     ADD        ESP,0xc
    //         005567f1     RET
}

// Offset: 0x005567F2
undefined FUN_005567f2() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005567f2()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005567f2
    //         005567f2     NOP
    //         005567f3     NOP
    //         005567f4     NOP
    //         005567f5     NOP
    //         005567f6     NOP
    //         005567f7     NOP
    //         005567f8     NOP
    //         005567f9     NOP
    //         005567fa     NOP
    //         005567fb     NOP
    //         005567fc     NOP
    //         005567fd     NOP
    //         005567fe     NOP
    //         005567ff     NOP
    //                               __ismbbkpunct
    //         00556800     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00556804     PUSH       0x2
    //         00556806     PUSH       0x0
    //         00556808     PUSH       EAX
    //         00556809     CALL       FUN_00556930                                     undefined FUN_00556930()
    //         0055680e     ADD        ESP,0xc
    //         00556811     RET
}

// Offset: 0x00556812
undefined FUN_00556812() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00556812()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00556812
    //         00556812     NOP
    //         00556813     NOP
    //         00556814     NOP
    //         00556815     NOP
    //         00556816     NOP
    //         00556817     NOP
    //         00556818     NOP
    //         00556819     NOP
    //         0055681a     NOP
    //         0055681b     NOP
    //         0055681c     NOP
    //         0055681d     NOP
    //         0055681e     NOP
    //         0055681f     NOP
    //                               __ismbbalnum
    //         00556820     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00556824     PUSH       0x1
    //         00556826     PUSH       0x107
    //         0055682b     PUSH       EAX
    //         0055682c     CALL       FUN_00556930                                     undefined FUN_00556930()
    //         00556831     ADD        ESP,0xc
    //         00556834     RET
}

// Offset: 0x00556835
undefined FUN_00556835() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00556835()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00556835
    //         00556835     NOP
    //         00556836     NOP
    //         00556837     NOP
    //         00556838     NOP
    //         00556839     NOP
    //         0055683a     NOP
    //         0055683b     NOP
    //         0055683c     NOP
    //         0055683d     NOP
    //         0055683e     NOP
    //         0055683f     NOP
    //                               __ismbbalpha
    //         00556840     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00556844     PUSH       0x1
    //         00556846     PUSH       0x103
    //         0055684b     PUSH       EAX
    //         0055684c     CALL       FUN_00556930                                     undefined FUN_00556930()
    //         00556851     ADD        ESP,0xc
    //         00556854     RET
}

// Offset: 0x00556855
undefined FUN_00556855() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00556855()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00556855
    //         00556855     NOP
    //         00556856     NOP
    //         00556857     NOP
    //         00556858     NOP
    //         00556859     NOP
    //         0055685a     NOP
    //         0055685b     NOP
    //         0055685c     NOP
    //         0055685d     NOP
    //         0055685e     NOP
    //         0055685f     NOP
    //                               __ismbbgraph
    //         00556860     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00556864     PUSH       0x3
    //         00556866     PUSH       0x117
    //         0055686b     PUSH       EAX
    //         0055686c     CALL       FUN_00556930                                     undefined FUN_00556930()
    //         00556871     ADD        ESP,0xc
    //         00556874     RET
}

// Offset: 0x00556875
undefined FUN_00556875() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00556875()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00556875
    //         00556875     NOP
    //         00556876     NOP
    //         00556877     NOP
    //         00556878     NOP
    //         00556879     NOP
    //         0055687a     NOP
    //         0055687b     NOP
    //         0055687c     NOP
    //         0055687d     NOP
    //         0055687e     NOP
    //         0055687f     NOP
    //                               __ismbbprint
    //         00556880     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00556884     PUSH       0x3
    //         00556886     PUSH       0x157
    //         0055688b     PUSH       EAX
    //         0055688c     CALL       FUN_00556930                                     undefined FUN_00556930()
    //         00556891     ADD        ESP,0xc
    //         00556894     RET
}

// Offset: 0x00556895
undefined FUN_00556895() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00556895()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00556895
    //         00556895     NOP
    //         00556896     NOP
    //         00556897     NOP
    //         00556898     NOP
    //         00556899     NOP
    //         0055689a     NOP
    //         0055689b     NOP
    //         0055689c     NOP
    //         0055689d     NOP
    //         0055689e     NOP
    //         0055689f     NOP
    //                               __ismbbpunct
    //         005568a0     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         005568a4     PUSH       0x2
    //         005568a6     PUSH       0x10
    //         005568a8     PUSH       EAX
    //         005568a9     CALL       FUN_00556930                                     undefined FUN_00556930()
    //         005568ae     ADD        ESP,0xc
    //         005568b1     RET
}

// Offset: 0x005568C0
undefined ismbblead() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __ismbblead()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __ismbblead                                                  XREF[1]:     entry:0054f94c(c)  
    //         005568c0     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         005568c4     PUSH       0x4
    //         005568c6     PUSH       0x0
    //         005568c8     PUSH       EAX
    //         005568c9     CALL       FUN_00556930                                     undefined FUN_00556930()
    //         005568ce     ADD        ESP,0xc
    //         005568d1     RET
}

// Offset: 0x005568D2
undefined FUN_005568d2() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005568d2()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005568d2
    //         005568d2     NOP
    //         005568d3     NOP
    //         005568d4     NOP
    //         005568d5     NOP
    //         005568d6     NOP
    //         005568d7     NOP
    //         005568d8     NOP
    //         005568d9     NOP
    //         005568da     NOP
    //         005568db     NOP
    //         005568dc     NOP
    //         005568dd     NOP
    //         005568de     NOP
    //         005568df     NOP
    //                               __ismbbtrail
    //         005568e0     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         005568e4     PUSH       0x8
    //         005568e6     PUSH       0x0
    //         005568e8     PUSH       EAX
    //         005568e9     CALL       FUN_00556930                                     undefined FUN_00556930()
    //         005568ee     ADD        ESP,0xc
    //         005568f1     RET
}

// Offset: 0x005568F2
undefined FUN_005568f2() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005568f2()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005568f2
    //         005568f2     NOP
    //         005568f3     NOP
    //         005568f4     NOP
    //         005568f5     NOP
    //         005568f6     NOP
    //         005568f7     NOP
    //         005568f8     NOP
    //         005568f9     NOP
    //         005568fa     NOP
    //         005568fb     NOP
    //         005568fc     NOP
    //         005568fd     NOP
    //         005568fe     NOP
    //         005568ff     NOP
    //                               __ismbbkana
    //         00556900     CMP        dword ptr [___mbcodepage],0x3a4
    //         0055690a     JNZ        LAB_00556927
    //         0055690c     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00556910     PUSH       0x3
    //         00556912     PUSH       0x0
    //         00556914     PUSH       EAX
    //         00556915     CALL       FUN_00556930                                     undefined FUN_00556930()
    //         0055691a     ADD        ESP,0xc
    //         0055691d     TEST       EAX,EAX
    //         0055691f     JZ         LAB_00556927
    //         00556921     MOV        EAX,0x1
    //         00556926     RET
    //                               LAB_00556927                                                 XREF[2]:     0055690a(j), 0055691f(j)  
    //         00556927     XOR        EAX,EAX
    //         00556929     RET
}

// Offset: 0x00556930
undefined FUN_00556930() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00556930()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00556930                                                 XREF[11]:    FUN_005567b5:005567c9(c), 
    //                                                                                                         FUN_005567d2:005567e9(c), 
    //                                                                                                         FUN_005567f2:00556809(c), 
    //                                                                                                         FUN_00556812:0055682c(c), 
    //                                                                                                         FUN_00556835:0055684c(c), 
    //                                                                                                         FUN_00556855:0055686c(c), 
    //                                                                                                         FUN_00556875:0055688c(c), 
    //                                                                                                         FUN_00556895:005568a9(c), 
    //                                                                                                         __ismbblead:005568c9(c), 
    //                                                                                                         FUN_005568d2:005568e9(c), 
    //                                                                                                         FUN_005568f2:00556915(c)  
    //         00556930     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00556934     MOV        CL,byte ptr [ESP + Stack[0xc]]
    //         00556938     AND        EAX,0xff
    //         0055693d     TEST       byte ptr [EAX + __mbctype+1],CL
    //         00556943     JNZ        LAB_00556964
    //         00556945     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //         00556949     TEST       ECX,ECX
    //         0055694b     JZ         LAB_0055695d
    //         0055694d     XOR        EDX,EDX
    //         0055694f     MOV        DX,word ptr [EAX*0x2 + DAT_005920da]             = 20h     
    //         00556957     MOV        EAX,EDX
    //         00556959     AND        EAX,ECX
    //         0055695b     JMP        LAB_0055695f
    //                               LAB_0055695d                                                 XREF[1]:     0055694b(j)  
    //         0055695d     XOR        EAX,EAX
    //                               LAB_0055695f                                                 XREF[1]:     0055695b(j)  
    //         0055695f     TEST       EAX,EAX
    //         00556961     JNZ        LAB_00556964
    //         00556963     RET
    //                               LAB_00556964                                                 XREF[2]:     00556943(j), 00556961(j)  
    //         00556964     MOV        EAX,0x1
    //         00556969     RET
}

// Offset: 0x00556970
undefined setenvp() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __setenvp()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     005569b4(W), 00556a0d(R), 00556a2a(W)  
    //                               __setenvp                                                    XREF[1]:     entry:0054f91c(c)  
    //         00556970     PUSH       ECX
    //         00556971     MOV        EDX,dword ptr [__aenvptr]
    //         00556977     PUSH       EBX
    //         00556978     PUSH       EBP
    //         00556979     PUSH       ESI
    //         0055697a     MOV        AL,byte ptr [EDX]
    //         0055697c     XOR        ESI,ESI
    //         0055697e     TEST       AL,AL
    //         00556980     PUSH       EDI
    //         00556981     JZ         LAB_005569a0
    //                               LAB_00556983                                                 XREF[1]:     0055699e(j)  
    //         00556983     CMP        AL,0x3d
    //         00556985     JZ         LAB_00556988
    //         00556987     INC        ESI
    //                               LAB_00556988                                                 XREF[1]:     00556985(j)  
    //         00556988     MOV        EDI,EDX
    //         0055698a     OR         ECX,0xffffffff
    //         0055698d     XOR        EAX,EAX
    //         0055698f     SCASB.RE   ES:EDI
    //         00556991     NOT        ECX
    //         00556993     DEC        ECX
    //         00556994     MOV        AL,byte ptr [EDX + ECX*0x1 + 0x1]
    //         00556998     LEA        EDX,[EDX + ECX*0x1 + 0x1]
    //         0055699c     TEST       AL,AL
    //         0055699e     JNZ        LAB_00556983
    //                               LAB_005569a0                                                 XREF[1]:     00556981(j)  
    //         005569a0     LEA        EAX,[ESI*0x4 + 0x4]
    //         005569a7     PUSH       EAX
    //         005569a8     CALL       malloc                                           undefined malloc()
    //         005569ad     MOV        ESI,EAX
    //         005569af     ADD        ESP,0x4
    //         005569b2     TEST       ESI,ESI
    //         005569b4     MOV        dword ptr [ESP + local_4],ESI
    //         005569b8     MOV        dword ptr [__environ],ESI
    //         005569be     JNZ        LAB_005569ca
    //         005569c0     PUSH       0x9
    //         005569c2     CALL       __amsg_exit                                      undefined __amsg_exit()
    //         005569c7     ADD        ESP,0x4
    //                               LAB_005569ca                                                 XREF[1]:     005569be(j)  
    //         005569ca     MOV        EBP,dword ptr [__aenvptr]
    //         005569d0     MOV        DL,byte ptr [EBP]
    //         005569d3     TEST       DL,DL
    //         005569d5     JZ         LAB_00556a3a
    //                               LAB_005569d7                                                 XREF[1]:     00556a38(j)  
    //         005569d7     MOV        EDI,EBP
    //         005569d9     OR         ECX,0xffffffff
    //         005569dc     XOR        EAX,EAX
    //         005569de     SCASB.RE   ES:EDI
    //         005569e0     NOT        ECX
    //         005569e2     DEC        ECX
    //         005569e3     MOV        EBX,ECX
    //         005569e5     INC        EBX
    //         005569e6     CMP        DL,0x3d
    //         005569e9     JZ         LAB_00556a30
    //         005569eb     PUSH       EBX
    //         005569ec     CALL       malloc                                           undefined malloc()
    //         005569f1     ADD        ESP,0x4
    //         005569f4     MOV        dword ptr [ESI],EAX
    //         005569f6     TEST       EAX,EAX
    //         005569f8     JNZ        LAB_00556a04
    //         005569fa     PUSH       0x9
    //         005569fc     CALL       __amsg_exit                                      undefined __amsg_exit()
    //         00556a01     ADD        ESP,0x4
    //                               LAB_00556a04                                                 XREF[1]:     005569f8(j)  
    //         00556a04     MOV        EDI,EBP
    //         00556a06     OR         ECX,0xffffffff
    //         00556a09     XOR        EAX,EAX
    //         00556a0b     SCASB.RE   ES:EDI
    //         00556a0d     MOV        EAX,dword ptr [ESP + local_4]
    //         00556a11     NOT        ECX
    //         00556a13     SUB        EDI,ECX
    //         00556a15     MOV        EDX,ECX
    //         00556a17     MOV        ESI,EDI
    //         00556a19     MOV        EDI,dword ptr [EAX]
    //         00556a1b     SHR        ECX,0x2
    //         00556a1e     MOVSD.REP  ES:EDI,ESI
    //         00556a20     MOV        ECX,EDX
    //         00556a22     AND        ECX,0x3
    //         00556a25     ADD        EAX,0x4
    //         00556a28     MOVSB.REP  ES:EDI,ESI
    //         00556a2a     MOV        dword ptr [ESP + local_4],EAX
    //         00556a2e     MOV        ESI,EAX
    //                               LAB_00556a30                                                 XREF[1]:     005569e9(j)  
    //         00556a30     MOV        DL,byte ptr [EBP + EBX*0x1]
    //         00556a34     ADD        EBP,EBX
    //         00556a36     TEST       DL,DL
    //         00556a38     JNZ        LAB_005569d7
    //                               LAB_00556a3a                                                 XREF[1]:     005569d5(j)  
    //         00556a3a     MOV        EAX,[__aenvptr]
    //         00556a3f     PUSH       EAX
    //         00556a40     CALL       free                                             undefined free()
    //         00556a45     ADD        ESP,0x4
    //         00556a48     MOV        dword ptr [__aenvptr],0x0
    //         00556a52     MOV        dword ptr [ESI],0x0
    //         00556a58     POP        EDI
    //         00556a59     POP        ESI
    //         00556a5a     POP        EBP
    //         00556a5b     POP        EBX
    //         00556a5c     POP        ECX
    //         00556a5d     RET
}

// Offset: 0x00556A60
undefined setargv() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __setargv()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __setargv                                                    XREF[1]:     entry:0054f917(c)  
    //         00556a60     SUB        ESP,0x8
    //         00556a63     PUSH       ESI
    //         00556a64     PUSH       EDI
    //         00556a65     PUSH       0x104
    //         00556a6a     PUSH       DAT_008882d8                                     = align(264)
    //         00556a6f     PUSH       0x0
    //         00556a71     CALL       dword ptr [->KERNEL32.DLL::GetModuleFileNameA]   = 0048b978
    //         00556a77     MOV        EDI,dword ptr [__acmdln]
    //         00556a7d     MOV        dword ptr [__pgmptr],DAT_008882d8                = align(264)
    //         00556a87     CMP        byte ptr [EDI],0x0
    //         00556a8a     JNZ        LAB_00556a91
    //         00556a8c     MOV        EDI,DAT_008882d8                                 = align(264)
    //                               LAB_00556a91                                                 XREF[1]:     00556a8a(j)  
    //         00556a91     LEA        EAX,[ESP + 0xc]
    //         00556a95     LEA        ECX,[ESP + 0x8]
    //         00556a99     PUSH       EAX
    //         00556a9a     PUSH       ECX=>DAT_fffffff8
    //         00556a9b     PUSH       0x0=>DAT_fffffff4
    //         00556a9d     PUSH       0x0=>DAT_fffffff0
    //         00556a9f     PUSH       EDI=>DAT_008882d8                                = align(264)
    //         00556aa0     CALL       FUN_00556b00                                     undefined FUN_00556b00()
    //         00556aa5     MOV        EDX,dword ptr [ESP + 0x20]
    //         00556aa9     MOV        EAX,dword ptr [ESP + 0x1c]
    //         00556aad     ADD        ESP,0x14
    //         00556ab0     LEA        ECX,[EDX + EAX*0x4]
    //         00556ab3     PUSH       ECX
    //         00556ab4     CALL       malloc                                           undefined malloc()
    //         00556ab9     MOV        ESI,EAX
    //         00556abb     ADD        ESP,0x4
    //         00556abe     TEST       ESI,ESI
    //         00556ac0     JNZ        LAB_00556acc
    //         00556ac2     PUSH       0x8
    //         00556ac4     CALL       __amsg_exit                                      undefined __amsg_exit()
    //         00556ac9     ADD        ESP,0x4
    //                               LAB_00556acc                                                 XREF[1]:     00556ac0(j)  
    //         00556acc     MOV        ECX,dword ptr [ESP + 0x8]
    //         00556ad0     LEA        EDX,[ESP + 0xc]
    //         00556ad4     PUSH       EDX
    //         00556ad5     LEA        EAX,[ESP + 0xc]
    //         00556ad9     LEA        EDX,[ESI + ECX*0x4]
    //         00556adc     PUSH       EAX=>DAT_fffffff8
    //         00556add     PUSH       EDX=>DAT_fffffff4
    //         00556ade     PUSH       ESI=>DAT_fffffff0
    //         00556adf     PUSH       EDI=>DAT_008882d8                                = align(264)
    //         00556ae0     CALL       FUN_00556b00                                     undefined FUN_00556b00()
    //         00556ae5     MOV        EAX,dword ptr [ESP + 0x1c]
    //         00556ae9     ADD        ESP,0x14
    //         00556aec     DEC        EAX
    //         00556aed     MOV        dword ptr [___argv],ESI                          = align(8)
    //         00556af3     POP        EDI
    //         00556af4     MOV        [___argc],EAX                                    = align(12)
    //         00556af9     POP        ESI
    //         00556afa     ADD        ESP,0x8
    //         00556afd     RET
}

// Offset: 0x00556B00
undefined FUN_00556b00() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00556b00()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00556b00                                                 XREF[2]:     __setargv:00556aa0(c), 
    //                                                                                                         __setargv:00556ae0(c)  
    //         00556b00     MOV        EAX,dword ptr [ESP + Stack[0x10]]
    //         00556b04     PUSH       EBX
    //         00556b05     PUSH       EBP
    //         00556b06     MOV        EBP,dword ptr [ESP + Stack[0x8]]
    //         00556b0a     PUSH       ESI
    //         00556b0b     MOV        ESI,dword ptr [ESP + Stack[0xc]]
    //         00556b0f     PUSH       EDI
    //         00556b10     MOV        EDI,dword ptr [ESP + Stack[0x14]]
    //         00556b14     TEST       EBP,EBP
    //         00556b16     MOV        dword ptr [EDI],0x0
    //         00556b1c     MOV        dword ptr [EAX],0x1
    //         00556b22     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00556b26     MOV        EBX,0x4
    //         00556b2b     JZ         LAB_00556b36
    //         00556b2d     MOV        dword ptr [EBP],ESI
    //         00556b30     ADD        EBP,EBX
    //         00556b32     MOV        dword ptr [ESP + Stack[0x8]],EBP
    //                               LAB_00556b36                                                 XREF[1]:     00556b2b(j)  
    //         00556b36     CMP        byte ptr [EAX],0x22
    //         00556b39     JNZ        LAB_00556b91
    //         00556b3b     MOV        CL,byte ptr [EAX + 0x1]
    //         00556b3e     INC        EAX
    //         00556b3f     CMP        CL,0x22
    //         00556b42     JZ         LAB_00556b7c
    //                               LAB_00556b44                                                 XREF[1]:     00556b7a(j)  
    //         00556b44     TEST       CL,CL
    //         00556b46     JZ         LAB_00556b7c
    //         00556b48     AND        ECX,0xff
    //         00556b4e     TEST       byte ptr [ECX + __mbctype+1],BL
    //         00556b54     JZ         LAB_00556b65
    //         00556b56     MOV        EDX,dword ptr [EDI]
    //         00556b58     INC        EDX
    //         00556b59     TEST       ESI,ESI
    //         00556b5b     MOV        dword ptr [EDI],EDX
    //         00556b5d     JZ         LAB_00556b65
    //         00556b5f     MOV        CL,byte ptr [EAX]
    //         00556b61     MOV        byte ptr [ESI],CL
    //         00556b63     INC        ESI
    //         00556b64     INC        EAX
    //                               LAB_00556b65                                                 XREF[2]:     00556b54(j), 00556b5d(j)  
    //         00556b65     MOV        EDX,dword ptr [EDI]
    //         00556b67     INC        EDX
    //         00556b68     TEST       ESI,ESI
    //         00556b6a     MOV        dword ptr [EDI],EDX
    //         00556b6c     JZ         LAB_00556b73
    //         00556b6e     MOV        DL,byte ptr [EAX]
    //         00556b70     MOV        byte ptr [ESI],DL
    //         00556b72     INC        ESI
    //                               LAB_00556b73                                                 XREF[1]:     00556b6c(j)  
    //         00556b73     MOV        CL,byte ptr [EAX + 0x1]
    //         00556b76     INC        EAX
    //         00556b77     CMP        CL,0x22
    //         00556b7a     JNZ        LAB_00556b44
    //                               LAB_00556b7c                                                 XREF[2]:     00556b42(j), 00556b46(j)  
    //         00556b7c     MOV        EDX,dword ptr [EDI]
    //         00556b7e     INC        EDX
    //         00556b7f     TEST       ESI,ESI
    //         00556b81     MOV        dword ptr [EDI],EDX
    //         00556b83     JZ         LAB_00556b89
    //         00556b85     MOV        byte ptr [ESI],0x0
    //         00556b88     INC        ESI
    //                               LAB_00556b89                                                 XREF[1]:     00556b83(j)  
    //         00556b89     CMP        byte ptr [EAX],0x22
    //         00556b8c     JNZ        LAB_00556be4
    //         00556b8e     INC        EAX
    //         00556b8f     JMP        LAB_00556be4
    //                               LAB_00556b91                                                 XREF[2]:     00556b39(j), 00556bd3(j)  
    //         00556b91     MOV        EDX,dword ptr [EDI]
    //         00556b93     INC        EDX
    //         00556b94     TEST       ESI,ESI
    //         00556b96     MOV        dword ptr [EDI],EDX
    //         00556b98     JZ         LAB_00556b9f
    //         00556b9a     MOV        CL,byte ptr [EAX]
    //         00556b9c     MOV        byte ptr [ESI],CL
    //         00556b9e     INC        ESI
    //                               LAB_00556b9f                                                 XREF[1]:     00556b98(j)  
    //         00556b9f     MOV        CL,byte ptr [EAX]
    //         00556ba1     INC        EAX
    //         00556ba2     MOV        byte ptr [ESP + Stack[0x14]],CL
    //         00556ba6     MOV        EDX,dword ptr [ESP + Stack[0x14]]
    //         00556baa     AND        EDX,0xff
    //         00556bb0     TEST       byte ptr [EDX + __mbctype+1],BL
    //         00556bb6     JZ         LAB_00556bc7
    //         00556bb8     MOV        EDX,dword ptr [EDI]
    //         00556bba     INC        EDX
    //         00556bbb     TEST       ESI,ESI
    //         00556bbd     MOV        dword ptr [EDI],EDX
    //         00556bbf     JZ         LAB_00556bc6
    //         00556bc1     MOV        DL,byte ptr [EAX]
    //         00556bc3     MOV        byte ptr [ESI],DL
    //         00556bc5     INC        ESI
    //                               LAB_00556bc6                                                 XREF[1]:     00556bbf(j)  
    //         00556bc6     INC        EAX
    //                               LAB_00556bc7                                                 XREF[1]:     00556bb6(j)  
    //         00556bc7     CMP        CL,0x20
    //         00556bca     JZ         LAB_00556bd5
    //         00556bcc     TEST       CL,CL
    //         00556bce     JZ         LAB_00556bd9
    //         00556bd0     CMP        CL,0x9
    //         00556bd3     JNZ        LAB_00556b91
    //                               LAB_00556bd5                                                 XREF[1]:     00556bca(j)  
    //         00556bd5     TEST       CL,CL
    //         00556bd7     JNZ        LAB_00556bdc
    //                               LAB_00556bd9                                                 XREF[1]:     00556bce(j)  
    //         00556bd9     DEC        EAX
    //         00556bda     JMP        LAB_00556be4
    //                               LAB_00556bdc                                                 XREF[1]:     00556bd7(j)  
    //         00556bdc     TEST       ESI,ESI
    //         00556bde     JZ         LAB_00556be4
    //         00556be0     MOV        byte ptr [ESI + -0x1],0x0
    //                               LAB_00556be4                                                 XREF[4]:     00556b8c(j), 00556b8f(j), 
    //                                                                                                         00556bda(j), 00556bde(j)  
    //         00556be4     XOR        EDX,EDX
    //         00556be6     MOV        dword ptr [ESP + Stack[0x14]],EDX
    //                               LAB_00556bea                                                 XREF[1]:     00556cf1(j)  
    //         00556bea     CMP        byte ptr [EAX],0x0
    //         00556bed     JZ         LAB_00556cf6
    //                               LAB_00556bf3                                                 XREF[1]:     00556c00(j)  
    //         00556bf3     MOV        CL,byte ptr [EAX]
    //         00556bf5     CMP        CL,0x20
    //         00556bf8     JZ         LAB_00556bff
    //         00556bfa     CMP        CL,0x9
    //         00556bfd     JNZ        LAB_00556c02
    //                               LAB_00556bff                                                 XREF[1]:     00556bf8(j)  
    //         00556bff     INC        EAX
    //         00556c00     JMP        LAB_00556bf3
    //                               LAB_00556c02                                                 XREF[1]:     00556bfd(j)  
    //         00556c02     CMP        byte ptr [EAX],0x0
    //         00556c05     JZ         LAB_00556cf6
    //         00556c0b     TEST       EBP,EBP
    //         00556c0d     JZ         LAB_00556c18
    //         00556c0f     MOV        dword ptr [EBP],ESI
    //         00556c12     ADD        EBP,EBX
    //         00556c14     MOV        dword ptr [ESP + Stack[0x8]],EBP
    //                               LAB_00556c18                                                 XREF[1]:     00556c0d(j)  
    //         00556c18     MOV        ECX,dword ptr [ESP + Stack[0x10]]
    //         00556c1c     INC        dword ptr [ECX]
    //                               LAB_00556c1e                                                 XREF[2]:     00556cb9(j), 00556cd6(j)  
    //         00556c1e     MOV        BL,byte ptr [EAX]
    //         00556c20     XOR        ECX,ECX
    //         00556c22     CMP        BL,0x5c
    //         00556c25     MOV        EBP,0x1
    //         00556c2a     JNZ        LAB_00556c36
    //                               LAB_00556c2c                                                 XREF[1]:     00556c34(j)  
    //         00556c2c     MOV        BL,byte ptr [EAX + 0x1]
    //         00556c2f     INC        EAX
    //         00556c30     INC        ECX
    //         00556c31     CMP        BL,0x5c
    //         00556c34     JZ         LAB_00556c2c
    //                               LAB_00556c36                                                 XREF[1]:     00556c2a(j)  
    //         00556c36     CMP        byte ptr [EAX],0x22
    //         00556c39     JNZ        LAB_00556c60
    //         00556c3b     TEST       CL,0x1
    //         00556c3e     JNZ        LAB_00556c5e
    //         00556c40     TEST       EDX,EDX
    //         00556c42     JZ         LAB_00556c4d
    //         00556c44     CMP        byte ptr [EAX + 0x1],0x22
    //         00556c48     JNZ        LAB_00556c4d
    //         00556c4a     INC        EAX
    //         00556c4b     JMP        LAB_00556c4f
    //                               LAB_00556c4d                                                 XREF[2]:     00556c42(j), 00556c48(j)  
    //         00556c4d     XOR        EBP,EBP
    //                               LAB_00556c4f                                                 XREF[1]:     00556c4b(j)  
    //         00556c4f     MOV        EBX,dword ptr [ESP + Stack[0x14]]
    //         00556c53     XOR        EDX,EDX
    //         00556c55     TEST       EBX,EBX
    //         00556c57     SETZ       DL
    //         00556c5a     MOV        dword ptr [ESP + Stack[0x14]],EDX
    //                               LAB_00556c5e                                                 XREF[1]:     00556c3e(j)  
    //         00556c5e     SHR        ECX,0x1
    //                               LAB_00556c60                                                 XREF[1]:     00556c39(j)  
    //         00556c60     MOV        EBX,ECX
    //         00556c62     DEC        ECX
    //         00556c63     TEST       EBX,EBX
    //         00556c65     JZ         LAB_00556c78
    //         00556c67     INC        ECX
    //                               LAB_00556c68                                                 XREF[1]:     00556c76(j)  
    //         00556c68     TEST       ESI,ESI
    //         00556c6a     JZ         LAB_00556c70
    //         00556c6c     MOV        byte ptr [ESI],0x5c
    //         00556c6f     INC        ESI
    //                               LAB_00556c70                                                 XREF[1]:     00556c6a(j)  
    //         00556c70     MOV        EBX,dword ptr [EDI]
    //         00556c72     INC        EBX
    //         00556c73     DEC        ECX
    //         00556c74     MOV        dword ptr [EDI],EBX
    //         00556c76     JNZ        LAB_00556c68
    //                               LAB_00556c78                                                 XREF[1]:     00556c65(j)  
    //         00556c78     MOV        CL,byte ptr [EAX]
    //         00556c7a     TEST       CL,CL
    //         00556c7c     JZ         LAB_00556cdb
    //         00556c7e     TEST       EDX,EDX
    //         00556c80     JNZ        LAB_00556c8c
    //         00556c82     CMP        CL,0x20
    //         00556c85     JZ         LAB_00556cdb
    //         00556c87     CMP        CL,0x9
    //         00556c8a     JZ         LAB_00556cdb
    //                               LAB_00556c8c                                                 XREF[1]:     00556c80(j)  
    //         00556c8c     TEST       EBP,EBP
    //         00556c8e     JZ         LAB_00556cd5
    //         00556c90     TEST       ESI,ESI
    //         00556c92     JZ         LAB_00556cbe
    //         00556c94     MOV        EBX,ECX
    //         00556c96     AND        EBX,0xff
    //         00556c9c     TEST       byte ptr [EBX + __mbctype+1],0x4
    //         00556ca3     JZ         LAB_00556cae
    //         00556ca5     MOV        byte ptr [ESI],CL
    //         00556ca7     MOV        ECX,dword ptr [EDI]
    //         00556ca9     INC        ESI
    //         00556caa     INC        EAX
    //         00556cab     INC        ECX
    //         00556cac     MOV        dword ptr [EDI],ECX
    //                               LAB_00556cae                                                 XREF[1]:     00556ca3(j)  
    //         00556cae     MOV        CL,byte ptr [EAX]
    //         00556cb0     MOV        byte ptr [ESI],CL
    //         00556cb2     MOV        ECX,dword ptr [EDI]
    //         00556cb4     INC        ESI
    //         00556cb5     INC        ECX
    //         00556cb6     MOV        dword ptr [EDI],ECX
    //         00556cb8     INC        EAX
    //         00556cb9     JMP        LAB_00556c1e
    //                               LAB_00556cbe                                                 XREF[1]:     00556c92(j)  
    //         00556cbe     AND        ECX,0xff
    //         00556cc4     TEST       byte ptr [ECX + __mbctype+1],0x4
    //         00556ccb     JZ         LAB_00556cd3
    //         00556ccd     MOV        ECX,dword ptr [EDI]
    //         00556ccf     INC        EAX
    //         00556cd0     INC        ECX
    //         00556cd1     MOV        dword ptr [EDI],ECX
    //                               LAB_00556cd3                                                 XREF[1]:     00556ccb(j)  
    //         00556cd3     INC        dword ptr [EDI]
    //                               LAB_00556cd5                                                 XREF[1]:     00556c8e(j)  
    //         00556cd5     INC        EAX
    //         00556cd6     JMP        LAB_00556c1e
    //                               LAB_00556cdb                                                 XREF[3]:     00556c7c(j), 00556c85(j), 
    //                                                                                                         00556c8a(j)  
    //         00556cdb     TEST       ESI,ESI
    //         00556cdd     JZ         LAB_00556ce3
    //         00556cdf     MOV        byte ptr [ESI],0x0
    //         00556ce2     INC        ESI
    //                               LAB_00556ce3                                                 XREF[1]:     00556cdd(j)  
    //         00556ce3     MOV        ECX,dword ptr [EDI]
    //         00556ce5     MOV        EBP,dword ptr [ESP + Stack[0x8]]
    //         00556ce9     INC        ECX
    //         00556cea     MOV        EBX,0x4
    //         00556cef     MOV        dword ptr [EDI],ECX
    //         00556cf1     JMP        LAB_00556bea
    //                               LAB_00556cf6                                                 XREF[2]:     00556bed(j), 00556c05(j)  
    //         00556cf6     TEST       EBP,EBP
    //         00556cf8     JZ         LAB_00556d01
    //         00556cfa     MOV        dword ptr [EBP],0x0
    //                               LAB_00556d01                                                 XREF[1]:     00556cf8(j)  
    //         00556d01     MOV        EAX,dword ptr [ESP + Stack[0x10]]
    //         00556d05     POP        EDI
    //         00556d06     POP        ESI
    //         00556d07     POP        EBP
    //         00556d08     MOV        ECX,dword ptr [EAX]
    //         00556d0a     POP        EBX
    //         00556d0b     INC        ECX
    //         00556d0c     MOV        dword ptr [EAX],ECX
    //         00556d0e     RET
}

// Offset: 0x00556D0F
undefined FUN_00556d0f() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00556d0f()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00556d30(W)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[1]:     00556d2c(W)  
    //                               FUN_00556d0f
    //         00556d0f     NOP
    //                               ___crtGetEnvironmentStringsW
    //         00556d10     SUB        ESP,0x8
    //         00556d13     MOV        EAX,[null_008883dc]                              = align(4)
    //         00556d18     PUSH       EBX
    //         00556d19     PUSH       EBP
    //         00556d1a     PUSH       ESI
    //         00556d1b     MOV        ESI,dword ptr [->KERNEL32.DLL::GetEnvironmentS   = 0048b9da
    //         00556d21     XOR        EBX,EBX
    //         00556d23     PUSH       EDI
    //         00556d24     MOV        EDI,dword ptr [->KERNEL32.DLL::GetEnvironmentS   = 0048b9c2
    //         00556d2a     TEST       EAX,EAX
    //         00556d2c     MOV        dword ptr [ESP + local_8],EBX
    //         00556d30     MOV        dword ptr [ESP + local_4],EBX
    //         00556d34     JNZ        LAB_00556d63
    //         00556d36     CALL       ESI=>KERNEL32.DLL::GetEnvironmentStringsW
    //         00556d38     TEST       EAX,EAX
    //         00556d3a     MOV        dword ptr [ESP + 0x10],EAX
    //         00556d3e     JZ         LAB_00556d47
    //         00556d40     MOV        EAX,0x1
    //         00556d45     JMP        LAB_00556d5a
    //                               LAB_00556d47                                                 XREF[1]:     00556d3e(j)  
    //         00556d47     CALL       EDI=>KERNEL32.DLL::GetEnvironmentStrings
    //         00556d49     TEST       EAX,EAX
    //         00556d4b     MOV        dword ptr [ESP + 0x10],EAX
    //         00556d4f     JZ         LAB_00556f02
    //         00556d55     MOV        EAX,0x2
    //                               LAB_00556d5a                                                 XREF[1]:     00556d45(j)  
    //         00556d5a     MOV        EBX,dword ptr [ESP + 0x10]
    //         00556d5e     MOV        [null_008883dc],EAX                              = align(4)
    //                               LAB_00556d63                                                 XREF[1]:     00556d34(j)  
    //         00556d63     CMP        EAX,0x1
    //         00556d66     JNZ        LAB_00556dec
    //         00556d6c     TEST       EBX,EBX
    //         00556d6e     JNZ        LAB_00556d86
    //         00556d70     CALL       ESI=>KERNEL32.DLL::GetEnvironmentStringsW
    //         00556d72     TEST       EAX,EAX
    //         00556d74     MOV        dword ptr [ESP + 0x10],EAX
    //         00556d78     JNZ        LAB_00556d82
    //         00556d7a     POP        EDI
    //         00556d7b     POP        ESI
    //         00556d7c     POP        EBP
    //         00556d7d     POP        EBX
    //         00556d7e     ADD        ESP,0x8
    //         00556d81     RET
    //                               LAB_00556d82                                                 XREF[1]:     00556d78(j)  
    //         00556d82     MOV        EBX,dword ptr [ESP + 0x10]
    //                               LAB_00556d86                                                 XREF[1]:     00556d6e(j)  
    //         00556d86     CMP        word ptr [EBX],0x0
    //         00556d8a     MOV        EAX,EBX
    //         00556d8c     JZ         LAB_00556da0
    //                               LAB_00556d8e                                                 XREF[2]:     00556d95(j), 00556d9e(j)  
    //         00556d8e     ADD        EAX,0x2
    //         00556d91     CMP        word ptr [EAX],0x0
    //         00556d95     JNZ        LAB_00556d8e
    //         00556d97     ADD        EAX,0x2
    //         00556d9a     CMP        word ptr [EAX],0x0
    //         00556d9e     JNZ        LAB_00556d8e
    //                               LAB_00556da0                                                 XREF[1]:     00556d8c(j)  
    //         00556da0     SUB        EAX,EBX
    //         00556da2     ADD        EAX,0x2
    //         00556da5     MOV        ESI,EAX
    //         00556da7     PUSH       ESI
    //         00556da8     CALL       malloc                                           undefined malloc()
    //         00556dad     MOV        EBP,EAX
    //         00556daf     ADD        ESP,0x4
    //         00556db2     TEST       EBP,EBP
    //         00556db4     JNZ        LAB_00556dc7
    //         00556db6     PUSH       EBX
    //         00556db7     CALL       dword ptr [->KERNEL32.DLL::FreeEnvironmentStri   = 0048b9a8
    //         00556dbd     XOR        EAX,EAX
    //         00556dbf     POP        EDI
    //         00556dc0     POP        ESI
    //         00556dc1     POP        EBP
    //         00556dc2     POP        EBX
    //         00556dc3     ADD        ESP,0x8
    //         00556dc6     RET
    //                               LAB_00556dc7                                                 XREF[1]:     00556db4(j)  
    //         00556dc7     MOV        ECX,ESI
    //         00556dc9     MOV        ESI,EBX
    //         00556dcb     MOV        EAX,ECX
    //         00556dcd     MOV        EDI,EBP
    //         00556dcf     SHR        ECX,0x2
    //         00556dd2     MOVSD.REP  ES:EDI,ESI
    //         00556dd4     MOV        ECX,EAX
    //         00556dd6     PUSH       EBX
    //         00556dd7     AND        ECX,0x3
    //         00556dda     MOVSB.REP  ES:EDI,ESI
    //         00556ddc     CALL       dword ptr [->KERNEL32.DLL::FreeEnvironmentStri   = 0048b9a8
    //         00556de2     MOV        EAX,EBP
    //         00556de4     POP        EDI
    //         00556de5     POP        ESI
    //         00556de6     POP        EBP
    //         00556de7     POP        EBX
    //         00556de8     ADD        ESP,0x8
    //         00556deb     RET
    //                               LAB_00556dec                                                 XREF[1]:     00556d66(j)  
    //         00556dec     CMP        EAX,0x2
    //         00556def     JNZ        LAB_00556ee6
    //         00556df5     TEST       EBX,EBX
    //         00556df7     JNZ        LAB_00556e0f
    //         00556df9     CALL       EDI=>KERNEL32.DLL::GetEnvironmentStrings
    //         00556dfb     TEST       EAX,EAX
    //         00556dfd     MOV        dword ptr [ESP + 0x10],EAX
    //         00556e01     JNZ        LAB_00556e0b
    //         00556e03     POP        EDI
    //         00556e04     POP        ESI
    //         00556e05     POP        EBP
    //         00556e06     POP        EBX
    //         00556e07     ADD        ESP,0x8
    //         00556e0a     RET
    //                               LAB_00556e0b                                                 XREF[1]:     00556e01(j)  
    //         00556e0b     MOV        EBX,dword ptr [ESP + 0x10]
    //                               LAB_00556e0f                                                 XREF[1]:     00556df7(j)  
    //         00556e0f     MOV        AL,byte ptr [EBX]
    //         00556e11     MOV        ESI,EBX
    //         00556e13     TEST       AL,AL
    //         00556e15     JZ         LAB_00556e57
    //                               LAB_00556e17                                                 XREF[1]:     00556e55(j)  
    //         00556e17     MOV        ECX,dword ptr [___lc_codepage]
    //         00556e1d     PUSH       0x0
    //         00556e1f     PUSH       0x0=>DAT_fffffff8
    //         00556e21     PUSH       offset DAT_fffffff4
    //         00556e23     PUSH       ESI=>DAT_fffffff0
    //         00556e24     PUSH       0x1
    //         00556e26     PUSH       ECX
    //         00556e27     CALL       dword ptr [->KERNEL32.DLL::MultiByteToWideChar]  = 0048b8da
    //         00556e2d     TEST       EAX,EAX
    //         00556e2f     JZ         LAB_00556f02
    //         00556e35     MOV        EBP,dword ptr [ESP + 0x14]
    //         00556e39     MOV        EDI,ESI
    //         00556e3b     ADD        EBP,EAX
    //         00556e3d     OR         ECX,0xffffffff
    //         00556e40     XOR        EAX,EAX
    //         00556e42     MOV        dword ptr [ESP + 0x14],EBP
    //         00556e46     SCASB.RE   ES:EDI
    //         00556e48     NOT        ECX
    //         00556e4a     DEC        ECX
    //         00556e4b     MOV        AL,byte ptr [ESI + ECX*0x1 + 0x1]
    //         00556e4f     LEA        ESI,[ESI + ECX*0x1 + 0x1]
    //         00556e53     TEST       AL,AL
    //         00556e55     JNZ        LAB_00556e17
    //                               LAB_00556e57                                                 XREF[1]:     00556e15(j)  
    //         00556e57     MOV        EAX,dword ptr [ESP + 0x14]
    //         00556e5b     INC        EAX
    //         00556e5c     MOV        dword ptr [ESP + 0x14],EAX
    //         00556e60     LEA        EDX,[EAX + EAX*0x1]
    //         00556e63     PUSH       EDX
    //         00556e64     CALL       malloc                                           undefined malloc()
    //         00556e69     MOV        EBP,EAX
    //         00556e6b     ADD        ESP,0x4
    //         00556e6e     TEST       EBP,EBP
    //         00556e70     JNZ        LAB_00556e83
    //         00556e72     PUSH       EBX
    //         00556e73     CALL       dword ptr [->KERNEL32.DLL::FreeEnvironmentStri   = 0048b98e
    //         00556e79     XOR        EAX,EAX
    //         00556e7b     POP        EDI
    //         00556e7c     POP        ESI
    //         00556e7d     POP        EBP
    //         00556e7e     POP        EBX
    //         00556e7f     ADD        ESP,0x8
    //         00556e82     RET
    //                               LAB_00556e83                                                 XREF[1]:     00556e70(j)  
    //         00556e83     MOV        EAX,dword ptr [ESP + 0x10]
    //         00556e87     MOV        ESI,EBP
    //         00556e89     CMP        byte ptr [EAX],0x0
    //         00556e8c     JZ         LAB_00556ed4
    //                               LAB_00556e8e                                                 XREF[1]:     00556ed2(j)  
    //         00556e8e     MOV        EDX,dword ptr [ESP + 0x14]
    //         00556e92     MOV        ECX,ESI
    //         00556e94     SUB        ECX,EBP
    //         00556e96     MOV        EAX,[___lc_codepage]
    //         00556e9b     SAR        ECX,0x1
    //         00556e9d     SUB        EDX,ECX
    //         00556e9f     PUSH       EDX
    //         00556ea0     PUSH       ESI=>DAT_fffffff8
    //         00556ea1     PUSH       offset DAT_fffffff4
    //         00556ea3     PUSH       EBX=>DAT_fffffff0
    //         00556ea4     PUSH       0x1
    //         00556ea6     PUSH       EAX
    //         00556ea7     CALL       dword ptr [->KERNEL32.DLL::MultiByteToWideChar]  = 0048b8da
    //         00556ead     TEST       EAX,EAX
    //         00556eaf     JZ         LAB_00556eee
    //         00556eb1     MOV        EDI,EBX
    //         00556eb3     OR         ECX,0xffffffff
    //         00556eb6     XOR        EAX,EAX
    //         00556eb8     PUSH       ESI
    //         00556eb9     SCASB.RE   ES:EDI
    //         00556ebb     NOT        ECX
    //         00556ebd     DEC        ECX
    //         00556ebe     LEA        EBX,[EBX + ECX*0x1 + 0x1]
    //         00556ec2     CALL       wcslen                                           undefined wcslen()
    //         00556ec7     LEA        ESI,[ESI + EAX*0x2 + 0x2]
    //         00556ecb     MOV        AL,byte ptr [EBX]
    //         00556ecd     ADD        ESP,0x4
    //         00556ed0     TEST       AL,AL
    //         00556ed2     JNZ        LAB_00556e8e
    //                               LAB_00556ed4                                                 XREF[1]:     00556e8c(j)  
    //         00556ed4     MOV        EDX,dword ptr [ESP + 0x10]
    //         00556ed8     MOV        word ptr [ESI],0x0
    //         00556edd     PUSH       EDX
    //         00556ede     CALL       dword ptr [->KERNEL32.DLL::FreeEnvironmentStri   = 0048b98e
    //         00556ee4     MOV        EAX,EBP
    //                               LAB_00556ee6                                                 XREF[1]:     00556def(j)  
    //         00556ee6     POP        EDI
    //         00556ee7     POP        ESI
    //         00556ee8     POP        EBP
    //         00556ee9     POP        EBX
    //         00556eea     ADD        ESP,0x8
    //         00556eed     RET
    //                               LAB_00556eee                                                 XREF[1]:     00556eaf(j)  
    //         00556eee     PUSH       EBP
    //         00556eef     CALL       free                                             undefined free()
    //         00556ef4     MOV        ECX,dword ptr [ESP + 0x14]
    //         00556ef8     ADD        ESP,0x4
    //         00556efb     PUSH       ECX
    //         00556efc     CALL       dword ptr [->KERNEL32.DLL::FreeEnvironmentStri   = 0048b98e
    //                               LAB_00556f02                                                 XREF[2]:     00556d4f(j), 00556e2f(j)  
    //         00556f02     POP        EDI
    //         00556f03     POP        ESI
    //         00556f04     POP        EBP
    //         00556f05     XOR        EAX,EAX
    //         00556f07     POP        EBX
    //         00556f08     ADD        ESP,0x8
    //         00556f0b     RET
}

// Offset: 0x00556F10
undefined crtGetEnvironmentStringsA() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined ___crtGetEnvironmentStringsA()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               ___crtGetEnvironmentStringsA                                 XREF[1]:     entry:0054f8f6(c)  
    //         00556f10     MOV        EAX,[DAT_008883e0]
    //         00556f15     PUSH       EBX
    //         00556f16     PUSH       EBP
    //         00556f17     MOV        EBP,dword ptr [->KERNEL32.DLL::GetEnvironmentS   = 0048b9c2
    //         00556f1d     PUSH       ESI
    //         00556f1e     XOR        ESI,ESI
    //         00556f20     XOR        EBX,EBX
    //         00556f22     PUSH       EDI
    //         00556f23     MOV        EDI,dword ptr [->KERNEL32.DLL::GetEnvironmentS   = 0048b9da
    //         00556f29     TEST       EAX,EAX
    //         00556f2b     JNZ        LAB_00556f52
    //         00556f2d     CALL       EDI=>KERNEL32.DLL::GetEnvironmentStringsW
    //         00556f2f     MOV        ESI,EAX
    //         00556f31     TEST       ESI,ESI
    //         00556f33     JZ         LAB_00556f3c
    //         00556f35     MOV        EAX,0x1
    //         00556f3a     JMP        LAB_00556f4d
    //                               LAB_00556f3c                                                 XREF[1]:     00556f33(j)  
    //         00556f3c     CALL       EBP=>KERNEL32.DLL::GetEnvironmentStrings
    //         00556f3e     MOV        EBX,EAX
    //         00556f40     TEST       EBX,EBX
    //         00556f42     JZ         LAB_0055705f
    //         00556f48     MOV        EAX,0x2
    //                               LAB_00556f4d                                                 XREF[1]:     00556f3a(j)  
    //         00556f4d     MOV        [DAT_008883e0],EAX
    //                               LAB_00556f52                                                 XREF[1]:     00556f2b(j)  
    //         00556f52     CMP        EAX,0x1
    //         00556f55     JNZ        LAB_00556ff2
    //         00556f5b     TEST       ESI,ESI
    //         00556f5d     JNZ        LAB_00556f6b
    //         00556f5f     CALL       EDI=>KERNEL32.DLL::GetEnvironmentStringsW
    //         00556f61     MOV        ESI,EAX
    //         00556f63     TEST       ESI,ESI
    //         00556f65     JZ         LAB_0055705f
    //                               LAB_00556f6b                                                 XREF[1]:     00556f5d(j)  
    //         00556f6b     CMP        word ptr [ESI],0x0
    //         00556f6f     MOV        EAX,ESI
    //         00556f71     JZ         LAB_00556f85
    //                               LAB_00556f73                                                 XREF[2]:     00556f7a(j), 00556f83(j)  
    //         00556f73     ADD        EAX,0x2
    //         00556f76     CMP        word ptr [EAX],0x0
    //         00556f7a     JNZ        LAB_00556f73
    //         00556f7c     ADD        EAX,0x2
    //         00556f7f     CMP        word ptr [EAX],0x0
    //         00556f83     JNZ        LAB_00556f73
    //                               LAB_00556f85                                                 XREF[1]:     00556f71(j)  
    //         00556f85     SUB        EAX,ESI
    //         00556f87     PUSH       0x0
    //         00556f89     SAR        EAX,0x1
    //         00556f8b     INC        EAX
    //         00556f8c     PUSH       0x0=>DAT_fffffff8
    //         00556f8e     MOV        EBP,EAX
    //         00556f90     PUSH       0x0=>DAT_fffffff4
    //         00556f92     PUSH       0x0=>DAT_fffffff0
    //         00556f94     PUSH       EBP
    //         00556f95     PUSH       ESI
    //         00556f96     PUSH       0x0
    //         00556f98     PUSH       0x0
    //         00556f9a     CALL       dword ptr [->KERNEL32.DLL::WideCharToMultiByte]  = 0048b8a0
    //         00556fa0     MOV        EDI,EAX
    //         00556fa2     TEST       EDI,EDI
    //         00556fa4     JZ         LAB_00556fe4
    //         00556fa6     PUSH       EDI
    //         00556fa7     CALL       malloc                                           undefined malloc()
    //         00556fac     MOV        EBX,EAX
    //         00556fae     ADD        ESP,0x4
    //         00556fb1     TEST       EBX,EBX
    //         00556fb3     JZ         LAB_00556fe4
    //         00556fb5     PUSH       0x0
    //         00556fb7     PUSH       0x0=>DAT_fffffff8
    //         00556fb9     PUSH       EDI=>DAT_fffffff4
    //         00556fba     PUSH       EBX=>DAT_fffffff0
    //         00556fbb     PUSH       EBP
    //         00556fbc     PUSH       ESI
    //         00556fbd     PUSH       0x0
    //         00556fbf     PUSH       0x0
    //         00556fc1     CALL       dword ptr [->KERNEL32.DLL::WideCharToMultiByte]  = 0048b8a0
    //         00556fc7     TEST       EAX,EAX
    //         00556fc9     JNZ        LAB_00556fd6
    //         00556fcb     PUSH       EBX
    //         00556fcc     CALL       free                                             undefined free()
    //         00556fd1     ADD        ESP,0x4
    //         00556fd4     XOR        EBX,EBX
    //                               LAB_00556fd6                                                 XREF[1]:     00556fc9(j)  
    //         00556fd6     PUSH       ESI
    //         00556fd7     CALL       dword ptr [->KERNEL32.DLL::FreeEnvironmentStri   = 0048b9a8
    //         00556fdd     MOV        EAX,EBX
    //         00556fdf     POP        EDI
    //         00556fe0     POP        ESI
    //         00556fe1     POP        EBP
    //         00556fe2     POP        EBX
    //         00556fe3     RET
    //                               LAB_00556fe4                                                 XREF[2]:     00556fa4(j), 00556fb3(j)  
    //         00556fe4     PUSH       ESI
    //         00556fe5     CALL       dword ptr [->KERNEL32.DLL::FreeEnvironmentStri   = 0048b9a8
    //         00556feb     XOR        EAX,EAX
    //         00556fed     POP        EDI
    //         00556fee     POP        ESI
    //         00556fef     POP        EBP
    //         00556ff0     POP        EBX
    //         00556ff1     RET
    //                               LAB_00556ff2                                                 XREF[1]:     00556f55(j)  
    //         00556ff2     CMP        EAX,0x2
    //         00556ff5     JNZ        LAB_0055705f
    //         00556ff7     TEST       EBX,EBX
    //         00556ff9     JNZ        LAB_00557003
    //         00556ffb     CALL       EBP=>KERNEL32.DLL::GetEnvironmentStrings
    //         00556ffd     MOV        EBX,EAX
    //         00556fff     TEST       EBX,EBX
    //         00557001     JZ         LAB_0055705f
    //                               LAB_00557003                                                 XREF[1]:     00556ff9(j)  
    //         00557003     MOV        CL,byte ptr [EBX]
    //         00557005     MOV        EAX,EBX
    //         00557007     TEST       CL,CL
    //         00557009     JZ         LAB_0055701b
    //                               LAB_0055700b                                                 XREF[2]:     00557011(j), 00557019(j)  
    //         0055700b     MOV        CL,byte ptr [EAX + 0x1]
    //         0055700e     INC        EAX
    //         0055700f     TEST       CL,CL
    //         00557011     JNZ        LAB_0055700b
    //         00557013     MOV        CL,byte ptr [EAX + 0x1]
    //         00557016     INC        EAX
    //         00557017     TEST       CL,CL
    //         00557019     JNZ        LAB_0055700b
    //                               LAB_0055701b                                                 XREF[1]:     00557009(j)  
    //         0055701b     SUB        EAX,EBX
    //         0055701d     INC        EAX
    //         0055701e     MOV        ESI,EAX
    //         00557020     PUSH       ESI
    //         00557021     CALL       malloc                                           undefined malloc()
    //         00557026     MOV        EBP,EAX
    //         00557028     ADD        ESP,0x4
    //         0055702b     TEST       EBP,EBP
    //         0055702d     JNZ        LAB_0055703d
    //         0055702f     PUSH       EBX
    //         00557030     CALL       dword ptr [->KERNEL32.DLL::FreeEnvironmentStri   = 0048b98e
    //         00557036     XOR        EAX,EAX
    //         00557038     POP        EDI
    //         00557039     POP        ESI
    //         0055703a     POP        EBP
    //         0055703b     POP        EBX
    //         0055703c     RET
    //                               LAB_0055703d                                                 XREF[1]:     0055702d(j)  
    //         0055703d     MOV        ECX,ESI
    //         0055703f     MOV        ESI,EBX
    //         00557041     MOV        EAX,ECX
    //         00557043     MOV        EDI,EBP
    //         00557045     SHR        ECX,0x2
    //         00557048     MOVSD.REP  ES:EDI,ESI
    //         0055704a     MOV        ECX,EAX
    //         0055704c     PUSH       EBX
    //         0055704d     AND        ECX,0x3
    //         00557050     MOVSB.REP  ES:EDI,ESI
    //         00557052     CALL       dword ptr [->KERNEL32.DLL::FreeEnvironmentStri   = 0048b98e
    //         00557058     MOV        EAX,EBP
    //         0055705a     POP        EDI
    //         0055705b     POP        ESI
    //         0055705c     POP        EBP
    //         0055705d     POP        EBX
    //         0055705e     RET
    //                               LAB_0055705f                                                 XREF[4]:     00556f42(j), 00556f65(j), 
    //                                                                                                         00556ff5(j), 00557001(j)  
    //         0055705f     POP        EDI
    //         00557060     POP        ESI
    //         00557061     POP        EBP
    //         00557062     XOR        EAX,EAX
    //         00557064     POP        EBX
    //         00557065     RET
}

