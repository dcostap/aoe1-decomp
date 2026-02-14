// Auto-generated scaffold unit: bucket_0551.asm
#include "../include/common.h"

// Offset: 0x00551230
undefined sbh_alloc_block_from_page() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined ___sbh_alloc_block_from_page()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               ___sbh_alloc_block_from_page                                 XREF[2]:     ___sbh_alloc_block:00551039(c), 
    //                                                                                                         ___sbh_alloc_block:00551074(c)  
    //         00551230     MOV        EDX,dword ptr [ESP + Stack[0xc]]
    //         00551234     PUSH       EBX
    //         00551235     PUSH       EBP
    //         00551236     PUSH       ESI
    //         00551237     PUSH       EDI
    //         00551238     MOV        EDI,dword ptr [ESP + Stack[0x4]]
    //         0055123c     MOV        EAX,dword ptr [EDI + 0x4]
    //         0055123f     MOV        ECX,dword ptr [EDI]
    //         00551241     CMP        EAX,EDX
    //         00551243     MOV        dword ptr [ESP + Stack[0x4]],ECX
    //         00551247     MOV        ESI,ECX
    //         00551249     LEA        EBX,[EDI + 0xf8]
    //         0055124f     JC         LAB_0055128b
    //         00551251     LEA        EAX,[ECX + EDX*0x1]
    //         00551254     MOV        byte ptr [ECX],DL
    //         00551256     CMP        EAX,EBX
    //         00551258     JNC        LAB_0055126a
    //         0055125a     MOV        ESI,dword ptr [EDI]
    //         0055125c     MOV        EAX,dword ptr [EDI + 0x4]
    //         0055125f     ADD        ESI,EDX
    //         00551261     SUB        EAX,EDX
    //         00551263     MOV        dword ptr [EDI],ESI
    //         00551265     MOV        dword ptr [EDI + 0x4],EAX
    //         00551268     JMP        LAB_00551276
    //                               LAB_0055126a                                                 XREF[1]:     00551258(j)  
    //         0055126a     LEA        EDX,[EDI + 0x8]
    //         0055126d     MOV        dword ptr [EDI + 0x4],0x0
    //         00551274     MOV        dword ptr [EDI],EDX
    //                               LAB_00551276                                                 XREF[1]:     00551268(j)  
    //         00551276     LEA        EAX,[EDI + EDI*0x2]
    //         00551279     LEA        EAX,[EAX + EAX*0x4]
    //         0055127c     MOV        EDX,EAX
    //         0055127e     LEA        EAX,[ECX + 0x8]
    //         00551281     SHL        EAX,0x4
    //         00551284     SUB        EAX,EDX
    //         00551286     POP        EDI
    //         00551287     POP        ESI
    //         00551288     POP        EBP
    //         00551289     POP        EBX
    //         0055128a     RET
    //                               LAB_0055128b                                                 XREF[1]:     0055124f(j)  
    //         0055128b     ADD        EAX,ECX
    //         0055128d     CMP        byte ptr [EAX],0x0
    //         00551290     JZ         LAB_00551294
    //         00551292     MOV        ESI,EAX
    //                               LAB_00551294                                                 XREF[1]:     00551290(j)  
    //         00551294     LEA        EAX,[ESI + EDX*0x1]
    //         00551297     CMP        EAX,EBX
    //         00551299     MOV        EBX,dword ptr [ESP + Stack[0x8]]
    //         0055129d     JNC        LAB_00551314
    //                               LAB_0055129f                                                 XREF[1]:     005512f3(j)  
    //         0055129f     MOV        AL,byte ptr [ESI]
    //         005512a1     TEST       AL,AL
    //         005512a3     JNZ        LAB_005512e1
    //         005512a5     CMP        byte ptr [ESI + 0x1],0x0
    //         005512a9     LEA        EAX,[ESI + 0x1]
    //         005512ac     MOV        ECX,0x1
    //         005512b1     JNZ        LAB_005512ba
    //                               LAB_005512b3                                                 XREF[1]:     005512b8(j)  
    //         005512b3     INC        EAX
    //         005512b4     INC        ECX
    //         005512b5     CMP        byte ptr [EAX],0x0
    //         005512b8     JZ         LAB_005512b3
    //                               LAB_005512ba                                                 XREF[1]:     005512b1(j)  
    //         005512ba     CMP        ECX,EDX
    //         005512bc     JNC        LAB_005512f7
    //         005512be     MOV        EBP,dword ptr [ESP + Stack[0x4]]
    //         005512c2     CMP        ESI,EBP
    //         005512c4     JNZ        LAB_005512cf
    //         005512c6     MOV        dword ptr [EDI + 0x4],ECX
    //         005512c9     MOV        ESI,EAX
    //         005512cb     MOV        ECX,EBP
    //         005512cd     JMP        LAB_005512e8
    //                               LAB_005512cf                                                 XREF[1]:     005512c4(j)  
    //         005512cf     SUB        EBX,ECX
    //         005512d1     CMP        EBX,EDX
    //         005512d3     JC         LAB_0055139b
    //         005512d9     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         005512dd     MOV        ESI,EAX
    //         005512df     JMP        LAB_005512e8
    //                               LAB_005512e1                                                 XREF[1]:     005512a3(j)  
    //         005512e1     AND        EAX,0xff
    //         005512e6     ADD        ESI,EAX
    //                               LAB_005512e8                                                 XREF[2]:     005512cd(j), 005512df(j)  
    //         005512e8     LEA        EBP,[ESI + EDX*0x1]
    //         005512eb     LEA        EAX,[EDI + 0xf8]
    //         005512f1     CMP        EBP,EAX
    //         005512f3     JC         LAB_0055129f
    //         005512f5     JMP        LAB_00551314
    //                               LAB_005512f7                                                 XREF[1]:     005512bc(j)  
    //         005512f7     LEA        EAX,[ESI + EDX*0x1]
    //         005512fa     LEA        EBX,[EDI + 0xf8]
    //         00551300     CMP        EAX,EBX
    //         00551302     JNC        LAB_0055130d
    //         00551304     SUB        ECX,EDX
    //         00551306     MOV        dword ptr [EDI],EAX
    //         00551308     MOV        dword ptr [EDI + 0x4],ECX
    //         0055130b     JMP        LAB_00551386
    //                               LAB_0055130d                                                 XREF[1]:     00551302(j)  
    //         0055130d     LEA        ECX,[EDI + 0x8]
    //         00551310     MOV        dword ptr [EDI],ECX
    //         00551312     JMP        LAB_0055137f
    //                               LAB_00551314                                                 XREF[2]:     0055129d(j), 005512f5(j)  
    //         00551314     LEA        EBP,[EDI + 0x8]
    //         00551317     MOV        ESI,EBP
    //         00551319     CMP        ESI,ECX
    //         0055131b     JNC        LAB_0055139b
    //                               LAB_0055131d                                                 XREF[1]:     0055135e(j)  
    //         0055131d     LEA        ECX,[ESI + EDX*0x1]
    //         00551320     LEA        EAX,[EDI + 0xf8]
    //         00551326     CMP        ECX,EAX
    //         00551328     JNC        LAB_0055139b
    //         0055132a     MOV        AL,byte ptr [ESI]
    //         0055132c     TEST       AL,AL
    //         0055132e     JNZ        LAB_00551353
    //         00551330     CMP        byte ptr [ESI + 0x1],0x0
    //         00551334     LEA        EAX,[ESI + 0x1]
    //         00551337     MOV        ECX,0x1
    //         0055133c     JNZ        LAB_00551345
    //                               LAB_0055133e                                                 XREF[1]:     00551343(j)  
    //         0055133e     INC        EAX
    //         0055133f     INC        ECX
    //         00551340     CMP        byte ptr [EAX],0x0
    //         00551343     JZ         LAB_0055133e
    //                               LAB_00551345                                                 XREF[1]:     0055133c(j)  
    //         00551345     CMP        ECX,EDX
    //         00551347     JNC        LAB_00551367
    //         00551349     SUB        EBX,ECX
    //         0055134b     CMP        EBX,EDX
    //         0055134d     JC         LAB_0055139b
    //         0055134f     MOV        ESI,EAX
    //         00551351     JMP        LAB_0055135a
    //                               LAB_00551353                                                 XREF[1]:     0055132e(j)  
    //         00551353     AND        EAX,0xff
    //         00551358     ADD        ESI,EAX
    //                               LAB_0055135a                                                 XREF[1]:     00551351(j)  
    //         0055135a     CMP        ESI,dword ptr [ESP + Stack[0x4]]
    //         0055135e     JC         LAB_0055131d
    //         00551360     XOR        EAX,EAX
    //         00551362     POP        EDI
    //         00551363     POP        ESI
    //         00551364     POP        EBP
    //         00551365     POP        EBX
    //         00551366     RET
    //                               LAB_00551367                                                 XREF[1]:     00551347(j)  
    //         00551367     LEA        EAX,[ESI + EDX*0x1]
    //         0055136a     LEA        EBX,[EDI + 0xf8]
    //         00551370     CMP        EAX,EBX
    //         00551372     JNC        LAB_0055137d
    //         00551374     SUB        ECX,EDX
    //         00551376     MOV        dword ptr [EDI],EAX
    //         00551378     MOV        dword ptr [EDI + 0x4],ECX
    //         0055137b     JMP        LAB_00551386
    //                               LAB_0055137d                                                 XREF[1]:     00551372(j)  
    //         0055137d     MOV        dword ptr [EDI],EBP
    //                               LAB_0055137f                                                 XREF[1]:     00551312(j)  
    //         0055137f     MOV        dword ptr [EDI + 0x4],0x0
    //                               LAB_00551386                                                 XREF[2]:     0055130b(j), 0055137b(j)  
    //         00551386     LEA        EAX,[EDI + EDI*0x2]
    //         00551389     MOV        byte ptr [ESI],DL
    //         0055138b     LEA        EDX,[EAX + EAX*0x4]
    //         0055138e     LEA        EAX,[ESI + 0x8]
    //         00551391     SHL        EAX,0x4
    //         00551394     SUB        EAX,EDX
    //         00551396     POP        EDI
    //         00551397     POP        ESI
    //         00551398     POP        EBP
    //         00551399     POP        EBX
    //         0055139a     RET
    //                               LAB_0055139b                                                 XREF[4]:     005512d3(j), 0055131b(j), 
    //                                                                                                         00551328(j), 0055134d(j)  
    //         0055139b     POP        EDI
    //         0055139c     POP        ESI
    //         0055139d     POP        EBP
    //         0055139e     XOR        EAX,EAX
    //         005513a0     POP        EBX
    //         005513a1     RET
}

// Offset: 0x005513B0
undefined sbh_resize_block() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined ___sbh_resize_block()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               ___sbh_resize_block                                          XREF[1]:     realloc:00556340(c)  
    //         005513b0     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         005513b4     PUSH       EBX
    //         005513b5     PUSH       EBP
    //         005513b6     MOV        EBP,dword ptr [ESP + Stack[0x8]]
    //         005513ba     PUSH       ESI
    //         005513bb     PUSH       EDI
    //         005513bc     MOV        EDI,dword ptr [ECX + 0x10]
    //         005513bf     MOV        EDX,EBP
    //         005513c1     SUB        EDX,EDI
    //         005513c3     MOV        EDI,dword ptr [ESP + Stack[0xc]]
    //         005513c7     SAR        EDX,0xc
    //         005513ca     MOV        EBX,dword ptr [ESP + Stack[0x10]]
    //         005513ce     XOR        EAX,EAX
    //         005513d0     LEA        ECX,[ECX + EDX*0x8 + 0x18]
    //         005513d4     XOR        EDX,EDX
    //         005513d6     MOV        DL,byte ptr [EDI]
    //         005513d8     MOV        dword ptr [ESP + Stack[0x8]],ECX
    //         005513dc     MOV        ESI,EDX
    //         005513de     CMP        ESI,EBX
    //         005513e0     JBE        LAB_005513fd
    //         005513e2     MOV        byte ptr [EDI],BL
    //         005513e4     MOV        EAX,dword ptr [ECX]
    //         005513e6     SUB        ESI,EBX
    //         005513e8     MOV        dword ptr [ECX + 0x4],0xf1
    //         005513ef     ADD        EAX,ESI
    //         005513f1     MOV        dword ptr [ECX],EAX
    //         005513f3     MOV        EAX,0x1
    //         005513f8     POP        EDI
    //         005513f9     POP        ESI
    //         005513fa     POP        EBP
    //         005513fb     POP        EBX
    //         005513fc     RET
    //                               LAB_005513fd                                                 XREF[1]:     005513e0(j)  
    //         005513fd     JNC        LAB_0055146f
    //         005513ff     LEA        ECX,[EBX + EDI*0x1]
    //         00551402     LEA        EDX,[EBP + 0xf8]
    //         00551408     CMP        ECX,EDX
    //         0055140a     JA         LAB_0055146f
    //         0055140c     LEA        EDX,[ESI + EDI*0x1]
    //         0055140f     CMP        EDX,ECX
    //         00551411     JNC        LAB_0055141f
    //                               LAB_00551413                                                 XREF[1]:     0055141b(j)  
    //         00551413     CMP        byte ptr [EDX],0x0
    //         00551416     JNZ        LAB_0055141d
    //         00551418     INC        EDX
    //         00551419     CMP        EDX,ECX
    //         0055141b     JC         LAB_00551413
    //                               LAB_0055141d                                                 XREF[1]:     00551416(j)  
    //         0055141d     CMP        EDX,ECX
    //                               LAB_0055141f                                                 XREF[1]:     00551411(j)  
    //         0055141f     JNZ        LAB_0055146f
    //         00551421     MOV        byte ptr [EDI],BL
    //         00551423     MOV        EAX,dword ptr [EBP]
    //         00551426     CMP        EDI,EAX
    //         00551428     JA         LAB_0055145e
    //         0055142a     CMP        ECX,EAX
    //         0055142c     JBE        LAB_0055145e
    //         0055142e     LEA        EAX,[EBP + 0xf8]
    //         00551434     CMP        ECX,EAX
    //         00551436     JNC        LAB_00551451
    //         00551438     MOV        dword ptr [EBP],ECX
    //         0055143b     MOV        DL,byte ptr [ECX]
    //         0055143d     XOR        EAX,EAX
    //         0055143f     TEST       DL,DL
    //         00551441     JNZ        LAB_0055144c
    //                               LAB_00551443                                                 XREF[1]:     0055144a(j)  
    //         00551443     MOV        DL,byte ptr [EAX + ECX*0x1 + 0x1]
    //         00551447     INC        EAX
    //         00551448     TEST       DL,DL
    //         0055144a     JZ         LAB_00551443
    //                               LAB_0055144c                                                 XREF[1]:     00551441(j)  
    //         0055144c     MOV        dword ptr [EBP + 0x4],EAX
    //         0055144f     JMP        LAB_0055145e
    //                               LAB_00551451                                                 XREF[1]:     00551436(j)  
    //         00551451     LEA        EAX,[EBP + 0x8]
    //         00551454     MOV        dword ptr [EBP + 0x4],0x0
    //         0055145b     MOV        dword ptr [EBP],EAX
    //                               LAB_0055145e                                                 XREF[3]:     00551428(j), 0055142c(j), 
    //                                                                                                         0055144f(j)  
    //         0055145e     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         00551462     SUB        ESI,EBX
    //         00551464     MOV        ECX,dword ptr [EAX]
    //         00551466     ADD        ECX,ESI
    //         00551468     MOV        dword ptr [EAX],ECX
    //         0055146a     MOV        EAX,0x1
    //                               LAB_0055146f                                                 XREF[3]:     005513fd(j), 0055140a(j), 
    //                                                                                                         0055141f(j)  
    //         0055146f     POP        EDI
    //         00551470     POP        ESI
    //         00551471     POP        EBP
    //         00551472     POP        EBX
    //         00551473     RET
}

// Offset: 0x00551474
undefined FUN_00551474() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00551474()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     005514be(W), 00551569(R), 005515b5(W)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[3]:     005514b3(W), 00551597(R), 005515b1(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[3]:     0055148e(W), 0055149e(RW), 00551638(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[3]:     00551492(W), 00551591(R), 005515c7(W)  
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[4]:     00551500(W), 00551515(R), 0055151b(W), 0055157b(R)  
    //              undefined4        Stack[-0x18]:4 local_18                  XREF[4]:     005514fc(W), 0055150c(W), 00551539(W), 0055156f(R)  
    //              undefined4        Stack[-0x1c]:4 local_1c                  XREF[3]:     005514b7(W), 005514c7(R), 005514d6(RW)  
    //                               FUN_00551474
    //         00551474     NOP
    //         00551475     NOP
    //         00551476     NOP
    //         00551477     NOP
    //         00551478     NOP
    //         00551479     NOP
    //         0055147a     NOP
    //         0055147b     NOP
    //         0055147c     NOP
    //         0055147d     NOP
    //         0055147e     NOP
    //         0055147f     NOP
    //                               ___sbh_heap_check
    //         00551480     SUB        ESP,0x1c
    //         00551483     PUSH       EBX
    //         00551484     PUSH       EBP
    //         00551485     PUSH       ESI
    //         00551486     PUSH       EDI
    //         00551487     XOR        EDI,EDI
    //         00551489     MOV        EDX,___small_block_heap                          = 0058fbe8
    //         0055148e     MOV        dword ptr [ESP + local_c],EDI
    //         00551492     MOV        dword ptr [ESP + local_10],EDX=>___small_block   = 0058fbe8
    //                               LAB_00551496                                                 XREF[1]:     005515cd(j)  
    //         00551496     CMP        dword ptr [->___small_block_heap],EDX            = 0058fbe8
    //         0055149c     JNZ        LAB_005514a2
    //         0055149e     INC        dword ptr [ESP + local_c]
    //                               LAB_005514a2                                                 XREF[1]:     0055149c(j)  
    //         005514a2     MOV        ECX,dword ptr [EDX + 0x10]=>DAT_0058fbf8         = FFFFFFFFh
    //         005514a5     CMP        ECX,-0x1
    //         005514a8     JZ         LAB_005515bf
    //         005514ae     MOV        EBX,ECX
    //         005514b0     LEA        EAX,[EDX + 0x18]=>DAT_0058fc00                   = 000000F0h
    //         005514b3     MOV        dword ptr [ESP + local_8],EDI
    //         005514b7     MOV        dword ptr [ESP + local_1c],EDI
    //         005514bb     LEA        EBP,[EBX + 0x8]
    //         005514be     MOV        dword ptr [ESP + local_4],EAX=>DAT_0058fc00      = 000000F0h
    //                               LAB_005514c2                                                 XREF[1]:     005515b9(j)  
    //         005514c2     CMP        dword ptr [EAX]=>DAT_0058fc00,-0x1               = 000000F0h
    //         005514c5     JNZ        LAB_005514df
    //         005514c7     CMP        dword ptr [ESP + local_1c],EDI
    //         005514cb     JNZ        LAB_005514d6
    //         005514cd     CMP        dword ptr [EDX + 0xc]=>PTR_DAT_0058fbf4,EAX      = 0058fc00
    //         005514d0     JNZ        LAB_005515d2
    //                               LAB_005514d6                                                 XREF[1]:     005514cb(j)  
    //         005514d6     INC        dword ptr [ESP + local_1c]
    //         005514da     JMP        LAB_00551597
    //                               LAB_005514df                                                 XREF[1]:     005514c5(j)  
    //         005514df     MOV        EDX,dword ptr [EBX]
    //         005514e1     LEA        ECX,[EBP + 0xf0]
    //         005514e7     CMP        EDX,ECX
    //         005514e9     JNC        LAB_005515dd
    //         005514ef     CMP        byte ptr [ECX]=>DAT_000000f7,0xff
    //         005514f2     JNZ        LAB_005515ea
    //         005514f8     XOR        EDX,EDX
    //         005514fa     XOR        ECX,ECX
    //         005514fc     MOV        dword ptr [ESP + local_18],ECX
    //         00551500     MOV        dword ptr [ESP + local_14],EDI
    //                               LAB_00551504                                                 XREF[1]:     00551579(j)  
    //         00551504     LEA        ESI,[EDX + EBP*0x1]
    //         00551507     CMP        ESI,dword ptr [EBX]
    //         00551509     JNZ        LAB_00551510
    //         0055150b     INC        ECX
    //         0055150c     MOV        dword ptr [ESP + local_18],ECX
    //                               LAB_00551510                                                 XREF[1]:     00551509(j)  
    //         00551510     CMP        byte ptr [ESI],0x0
    //         00551513     JNZ        LAB_00551522
    //         00551515     MOV        ESI,dword ptr [ESP + local_14]
    //         00551519     INC        ESI
    //         0055151a     INC        EDI
    //         0055151b     MOV        dword ptr [ESP + local_14],ESI
    //         0055151f     INC        EDX
    //         00551520     JMP        LAB_00551573
    //                               LAB_00551522                                                 XREF[1]:     00551513(j)  
    //         00551522     CMP        EDI,dword ptr [EAX + 0x4]=>DAT_0058fc04          = 000000F1h
    //         00551525     JGE        LAB_005515f7
    //         0055152b     CMP        ECX,0x1
    //         0055152e     JNZ        LAB_00551541
    //         00551530     CMP        EDI,dword ptr [EBP + -0x4]
    //         00551533     JL         LAB_00551604
    //         00551539     MOV        dword ptr [ESP + local_18],0x2
    //                               LAB_00551541                                                 XREF[1]:     0055152e(j)  
    //         00551541     XOR        EAX,EAX
    //         00551543     LEA        ECX,[EDX + 0x1]
    //         00551546     MOV        AL,byte ptr [ESI]
    //         00551548     MOV        ESI,EDX
    //         0055154a     ADD        ESI,EAX
    //         0055154c     XOR        EDI,EDI
    //         0055154e     CMP        ECX,ESI
    //         00551550     JGE        LAB_00551569
    //                               LAB_00551552                                                 XREF[1]:     00551567(j)  
    //         00551552     CMP        byte ptr [ECX + EBP*0x1],0x0
    //         00551556     JNZ        LAB_00551611
    //         0055155c     XOR        EAX,EAX
    //         0055155e     INC        ECX
    //         0055155f     MOV        AL,byte ptr [EDX + EBX*0x1 + 0x8]
    //         00551563     ADD        EAX,EDX
    //         00551565     CMP        ECX,EAX
    //         00551567     JL         LAB_00551552
    //                               LAB_00551569                                                 XREF[1]:     00551550(j)  
    //         00551569     MOV        EAX,dword ptr [ESP + local_4]
    //         0055156d     MOV        EDX,ECX
    //         0055156f     MOV        ECX,dword ptr [ESP + local_18]
    //                               LAB_00551573                                                 XREF[1]:     00551520(j)  
    //         00551573     CMP        EDX,0xf0
    //         00551579     JL         LAB_00551504
    //         0055157b     MOV        EDX,dword ptr [ESP + local_14]
    //         0055157f     MOV        ESI,dword ptr [EAX]=>DAT_0058fc00                = 000000F0h
    //         00551581     CMP        EDX,ESI
    //         00551583     JNZ        LAB_0055161e
    //         00551589     TEST       ECX,ECX
    //         0055158b     JZ         LAB_0055162b
    //         00551591     MOV        EDX,dword ptr [ESP + local_10]
    //         00551595     XOR        EDI,EDI
    //                               LAB_00551597                                                 XREF[1]:     005514da(j)  
    //         00551597     MOV        ECX,dword ptr [ESP + local_8]
    //         0055159b     ADD        EAX,0x8
    //         0055159e     INC        ECX
    //         0055159f     ADD        EBX,0x1000
    //         005515a5     ADD        EBP,0x1000
    //         005515ab     CMP        ECX,0x400
    //         005515b1     MOV        dword ptr [ESP + local_8],ECX
    //         005515b5     MOV        dword ptr [ESP + local_4],EAX=>DAT_0058fc08
    //         005515b9     JL         LAB_005514c2
    //                               LAB_005515bf                                                 XREF[1]:     005514a8(j)  
    //         005515bf     MOV        EDX=>->___small_block_heap,dword ptr [EDX]       = 0058fbe8
    //         005515c1     CMP        EDX,___small_block_heap                          = 0058fbe8
    //         005515c7     MOV        dword ptr [ESP + local_10],EDX=>___small_block   = 0058fbe8
    //         005515cb     JZ         LAB_00551638
    //         005515cd     JMP        LAB_00551496
    //                               LAB_005515d2                                                 XREF[1]:     005514d0(j)  
    //         005515d2     OR         EAX,0xffffffff
    //         005515d5     POP        EDI
    //         005515d6     POP        ESI
    //         005515d7     POP        EBP
    //         005515d8     POP        EBX
    //         005515d9     ADD        ESP,0x1c
    //         005515dc     RET
    //                               LAB_005515dd                                                 XREF[1]:     005514e9(j)  
    //         005515dd     MOV        EAX,DAT_fffffffe
    //         005515e2     POP        EDI
    //         005515e3     POP        ESI
    //         005515e4     POP        EBP
    //         005515e5     POP        EBX
    //         005515e6     ADD        ESP,0x1c
    //         005515e9     RET
    //                               LAB_005515ea                                                 XREF[1]:     005514f2(j)  
    //         005515ea     MOV        EAX,DAT_fffffffd
    //         005515ef     POP        EDI
    //         005515f0     POP        ESI
    //         005515f1     POP        EBP
    //         005515f2     POP        EBX
    //         005515f3     ADD        ESP,0x1c
    //         005515f6     RET
    //                               LAB_005515f7                                                 XREF[1]:     00551525(j)  
    //         005515f7     MOV        EAX,DAT_fffffffc
    //         005515fc     POP        EDI
    //         005515fd     POP        ESI
    //         005515fe     POP        EBP
    //         005515ff     POP        EBX
    //         00551600     ADD        ESP,0x1c
    //         00551603     RET
    //                               LAB_00551604                                                 XREF[1]:     00551533(j)  
    //         00551604     MOV        EAX,DAT_fffffffb
    //         00551609     POP        EDI
    //         0055160a     POP        ESI
    //         0055160b     POP        EBP
    //         0055160c     POP        EBX
    //         0055160d     ADD        ESP,0x1c
    //         00551610     RET
    //                               LAB_00551611                                                 XREF[1]:     00551556(j)  
    //         00551611     MOV        EAX,DAT_fffffffa
    //         00551616     POP        EDI
    //         00551617     POP        ESI
    //         00551618     POP        EBP
    //         00551619     POP        EBX
    //         0055161a     ADD        ESP,0x1c
    //         0055161d     RET
    //                               LAB_0055161e                                                 XREF[1]:     00551583(j)  
    //         0055161e     MOV        EAX,DAT_fffffff9
    //         00551623     POP        EDI
    //         00551624     POP        ESI
    //         00551625     POP        EBP
    //         00551626     POP        EBX
    //         00551627     ADD        ESP,0x1c
    //         0055162a     RET
    //                               LAB_0055162b                                                 XREF[1]:     0055158b(j)  
    //         0055162b     MOV        EAX,DAT_fffffff8
    //         00551630     POP        EDI
    //         00551631     POP        ESI
    //         00551632     POP        EBP
    //         00551633     POP        EBX
    //         00551634     ADD        ESP,0x1c
    //         00551637     RET
    //                               LAB_00551638                                                 XREF[1]:     005515cb(j)  
    //         00551638     MOV        EAX,dword ptr [ESP + local_c]
    //         0055163c     POP        EDI
    //         0055163d     NEG        EAX
    //         0055163f     SBB        EAX,EAX
    //         00551641     POP        ESI
    //         00551642     AND        EAX,0x9
    //         00551645     POP        EBP
    //         00551646     ADD        EAX,-0x9
    //         00551649     POP        EBX
    //         0055164a     ADD        ESP,0x1c
    //         0055164d     RET
}

// Offset: 0x00551650
undefined stbuf() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __stbuf()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __stbuf                                                      XREF[2]:     fprintf:0054b828(c), 
    //                                                                                                         fputs:0054d8db(c)  
    //         00551650     PUSH       ESI
    //         00551651     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         00551655     PUSH       EDI
    //         00551656     MOV        EAX,dword ptr [ESI + 0x10]
    //         00551659     PUSH       EAX
    //         0055165a     CALL       __isatty                                         undefined __isatty()
    //         0055165f     ADD        ESP,0x4
    //         00551662     TEST       EAX,EAX
    //         00551664     JZ         LAB_005516ea
    //         0055166a     CMP        ESI,DAT_00591e68
    //         00551670     JNZ        LAB_00551676
    //         00551672     XOR        EDI,EDI
    //         00551674     JMP        LAB_00551683
    //                               LAB_00551676                                                 XREF[1]:     00551670(j)  
    //         00551676     CMP        ESI,DAT_00591e88
    //         0055167c     JNZ        LAB_005516ea
    //         0055167e     MOV        EDI,0x1
    //                               LAB_00551683                                                 XREF[1]:     00551674(j)  
    //         00551683     MOV        ECX,dword ptr [__cflush]
    //         00551689     INC        ECX
    //         0055168a     MOV        dword ptr [__cflush],ECX
    //         00551690     MOV        EAX,dword ptr [ESI + 0xc]
    //         00551693     TEST       EAX,0x10c
    //         00551698     JNZ        LAB_005516ea
    //         0055169a     MOV        EAX,dword ptr [EDI*0x4 + __stdbuf]
    //         005516a1     TEST       EAX,EAX
    //         005516a3     JNZ        LAB_005516bd
    //         005516a5     PUSH       0x1000
    //         005516aa     CALL       malloc                                           undefined malloc()
    //         005516af     ADD        ESP,0x4
    //         005516b2     MOV        dword ptr [EDI*0x4 + __stdbuf],EAX
    //         005516b9     TEST       EAX,EAX
    //         005516bb     JZ         LAB_005516ea
    //                               LAB_005516bd                                                 XREF[1]:     005516a3(j)  
    //         005516bd     MOV        EAX,dword ptr [EDI*0x4 + __stdbuf]
    //         005516c4     MOV        dword ptr [ESI + 0x18],0x1000
    //         005516cb     MOV        dword ptr [ESI + 0x8],EAX
    //         005516ce     MOV        dword ptr [ESI],EAX
    //         005516d0     MOV        EAX,dword ptr [ESI + 0xc]
    //         005516d3     MOV        dword ptr [ESI + 0x4],0x1000
    //         005516da     OR         EAX,0x1102
    //         005516df     MOV        dword ptr [ESI + 0xc],EAX
    //         005516e2     MOV        EAX,0x1
    //         005516e7     POP        EDI
    //         005516e8     POP        ESI
    //         005516e9     RET
    //                               LAB_005516ea                                                 XREF[4]:     00551664(j), 0055167c(j), 
    //                                                                                                         00551698(j), 005516bb(j)  
    //         005516ea     POP        EDI
    //         005516eb     XOR        EAX,EAX
    //         005516ed     POP        ESI
    //         005516ee     RET
}

// Offset: 0x005516F0
undefined ftbuf() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __ftbuf()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __ftbuf                                                      XREF[2]:     fprintf:0054b849(c), 
    //                                                                                                         fputs:0054d8f6(c)  
    //         005516f0     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         005516f4     PUSH       ESI
    //         005516f5     TEST       EAX,EAX
    //         005516f7     JZ         LAB_0055172d
    //         005516f9     MOV        ESI,dword ptr [ESP + Stack[0x8]]
    //         005516fd     MOV        EAX,dword ptr [ESI + 0xc]
    //         00551700     TEST       AH,0x10
    //         00551703     JZ         LAB_00551742
    //         00551705     PUSH       ESI
    //         00551706     CALL       __flush                                          undefined __flush()
    //         0055170b     MOV        EAX,dword ptr [ESI + 0xc]
    //         0055170e     ADD        ESP,0x4
    //         00551711     AND        AH,0xee
    //         00551714     MOV        dword ptr [ESI + 0x18],0x0
    //         0055171b     MOV        dword ptr [ESI + 0xc],EAX
    //         0055171e     MOV        dword ptr [ESI],0x0
    //         00551724     MOV        dword ptr [ESI + 0x8],0x0
    //         0055172b     POP        ESI
    //         0055172c     RET
    //                               LAB_0055172d                                                 XREF[1]:     005516f7(j)  
    //         0055172d     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         00551731     MOV        ECX,dword ptr [EAX + 0xc]
    //         00551734     TEST       CH,0x10
    //         00551737     JZ         LAB_00551742
    //         00551739     PUSH       EAX
    //         0055173a     CALL       __flush                                          undefined __flush()
    //         0055173f     ADD        ESP,0x4
    //                               LAB_00551742                                                 XREF[2]:     00551703(j), 00551737(j)  
    //         00551742     POP        ESI
    //         00551743     RET
}

// Offset: 0x00551750
undefined output() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __output()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined2        Stack[-0x2]:2  local_2                   XREF[2,4]:   00551e6d(*), 00551f2f(*), 00551de7(*), 00551e3e(*), 
    //                                                                                     00551e4b(*), 00551e5e(*)  
    //              undefined         Stack[-0x200   local_200                 XREF[6]:     00551a15(*), 00551a28(*), 00551a4d(W), 00551a56(*), 
    //                                                                                     00551bc6(*), 00551c22(*)  
    //              undefined4        Stack[-0x204   local_204                 XREF[2]:     00551e0e(W), 00551e17(R)  
    //              undefined4        Stack[-0x20c   local_20c                 XREF[1]:     00551c19(W)  
    //              undefined4        Stack[-0x210   local_210                 XREF[2]:     00551c0e(W), 00551c27(*)  
    //              undefined         Stack[-0x214   local_214                 XREF[2]:     00551f32(*), 00551f55(*)  
    //              undefined4        Stack[-0x218   local_218                 XREF[3]:     005517d4(W), 00551bb7(W), 00551c15(R)  
    //              undefined4        Stack[-0x21c   local_21c                 XREF[3]:     0055176e(W), 00551959(R), 00551f96(W)  
    //              undefined4        Stack[-0x220   local_220                 XREF[3]:     00551789(R), 005517c3(W), 0055194c(W)  
    //              undefined4        Stack[-0x224   local_224                 XREF[4]:     00551cc0(W), 00551cca(W), 00551ce2(R), 00551e32(R)  
    //              undefined4        Stack[-0x228   local_228                 XREF[5]:     005517d8(W), 00551a2c(W), 00551b94(W), 00551ba8(W), 
    //                                                                                     00551e70(R)  
    //              undefined4        Stack[-0x22c   local_22c                 XREF[5]:     00551c9e(W), 00551cae(W), 00551cd6(W), 00551d00(W), 
    //                                                                                     00551e03(R)  
    //              undefined4        Stack[-0x230   local_230                 XREF[6]:     005517f0(W), 00551955(W), 00551a8e(W), 00551aa0(W), 
    //                                                                                     00551b22(W), 00551f14(R)  
    //              undefined4        Stack[-0x234   local_234                 XREF[7]:     0055177f(R), 00551785(R), 005517dc(W), 00551877(W), 
    //                                                                                     00551890(W), 005518a3(W), 00551eaf(R)  
    //              undefined4        Stack[-0x238   local_238                 XREF[6]:     005517e0(W), 00551cee(W), 00551ddf(W), 00551ea7(W), 
    //                                                                                     00551eb3(R), 00551ee1(R)  
    //              undefined1        Stack[-0x239   local_239                 XREF[1]:     00551cf6(W)  
    //              undefined1        Stack[-0x23a   local_23a                 XREF[5]:     00551ce6(W), 00551e8a(W), 00551e96(W), 00551ea2(W), 
    //                                                                                     00551eeb(*)  
    //              undefined4        Stack[-0x240   local_240                 XREF[13]:    00551765(W), 0055178d(R), 00551971(*), 00551994(*), 
    //                                                                                     00551b8f(R), 00551ba4(R), 00551ec7(*), 00551ee5(*), 
    //                                                                                     00551f03(*), 00551f4e(*), 00551f79(*), 00551fa7(R), 
    //                                                                                     00551fba(*)  
    //              undefined4        Stack[-0x244   local_244                 XREF[15]:    005517e8(W), 005518ac(W), 005518ca(W), 005518d6(W), 
    //                                                                                     005518e3(R), 005518f1(W), 00551ade(R), 00551bce(R), 
    //                                                                                     00551bdd(W), 00551bee(W), 00551bfd(R), 00551cb8(W), 
    //                                                                                     00551dc3(R), 00551df7(W), 00551e3a(R)  
    //              undefined4        Stack[-0x248   local_248                 XREF[16]:    00551a34(W), 00551a5a(W), 00551a8a(W), 00551aa8(W), 
    //                                                                                     00551abc(W), 00551b04(W), 00551b19(W), 00551b53(W), 
    //                                                                                     00551bca(W), 00551dee(W), 00551e36(R), 00551e41(W), 
    //                                                                                     00551e58(W), 00551e69(W), 00551f28(R), 00551fb6(R)  
    //              undefined4        Stack[-0x24c   local_24c                 XREF[43]:    005517e4(W), 00551817(R), 0055181d(W), 00551826(R), 
    //                                                                                     0055182c(W), 00551835(R), 0055183b(W), 00551844(R), 
    //                                                                                     0055184a(W), 00551853(R), 00551859(W), 00551883(R), 
    //                                                                                     0055188c(W), 00551918(R), 0055191e(W), 00551932(R), 
    //                                                                                     00551943(W), 005519ab(R), 005519b1(W), 005519ba(R)  
    //                               __output                                                     XREF[3]:     fprintf:0054b83d(c), 
    //                                                                                                         sprintf:0054bbef(c), 
    //                                                                                                         vsprintf:0054c1ff(c)  
    //         00551750     SUB        ESP,0x24c
    //         00551756     PUSH       EBX
    //         00551757     PUSH       EBP
    //         00551758     PUSH       ESI
    //         00551759     PUSH       EDI
    //         0055175a     MOV        EDI,dword ptr [ESP + Stack[0x8]]
    //         00551761     XOR        ECX,ECX
    //         00551763     XOR        EBP,EBP
    //         00551765     MOV        dword ptr [ESP + local_240],ECX
    //         00551769     MOV        BL,byte ptr [EDI]
    //         0055176b     INC        EDI
    //         0055176c     TEST       BL,BL
    //         0055176e     MOV        byte ptr [ESP + local_21c],BL
    //         00551772     MOV        dword ptr [ESP + Stack[0x8]],EDI
    //         00551779     JZ         LAB_00551fa7
    //         0055177f     MOV        ESI,dword ptr [ESP + local_234]
    //         00551783     JMP        LAB_0055178d
    //                               LAB_00551785                                                 XREF[1]:     00551fa1(j)  
    //         00551785     MOV        ESI,dword ptr [ESP + local_234]
    //         00551789     MOV        ECX,dword ptr [ESP + local_220]
    //                               LAB_0055178d                                                 XREF[1]:     00551783(j)  
    //         0055178d     MOV        EAX,dword ptr [ESP + local_240]
    //         00551791     XOR        EDX,EDX
    //         00551793     CMP        EAX,EDX
    //         00551795     JL         LAB_00551fa7
    //         0055179b     CMP        BL,0x20
    //         0055179e     JL         LAB_005517b3
    //         005517a0     CMP        BL,0x78
    //         005517a3     JG         LAB_005517b3
    //         005517a5     MOVSX      EAX,BL
    //         005517a8     MOV        AL,byte ptr [EAX + s_t_00577b28+24]              = "t"
    //         005517ae     AND        EAX,0xf
    //         005517b1     JMP        LAB_005517b5
    //                               LAB_005517b3                                                 XREF[2]:     0055179e(j), 005517a3(j)  
    //         005517b3     XOR        EAX,EAX
    //                               LAB_005517b5                                                 XREF[1]:     005517b1(j)  
    //         005517b5     MOVSX      EAX,byte ptr [ECX + EAX*0x8 + ___lookuptable]    = 06h
    //         005517bd     SAR        EAX,0x4
    //         005517c0     CMP        EAX,0x7
    //         005517c3     MOV        dword ptr [ESP + local_220],EAX
    //         005517c7     JA         switchD_005517cd::default
    //                               switchD_005517cd::switchD
    //         005517cd     JMP        dword ptr [EAX*0x4 + switchD_005517cd::switchd   = 00551950
    //                               switchD_005517cd::caseD_1                                    XREF[2]:     005517cd(j), 00551fd0(*)  
    //         005517d4     MOV        dword ptr [ESP + local_218],EDX
    //         005517d8     MOV        dword ptr [ESP + local_228],EDX
    //         005517dc     MOV        dword ptr [ESP + local_234],EDX
    //         005517e0     MOV        dword ptr [ESP + local_238],EDX
    //         005517e4     MOV        dword ptr [ESP + local_24c],EDX
    //         005517e8     MOV        dword ptr [ESP + local_244],0xffffffff
    //         005517f0     MOV        dword ptr [ESP + local_230],EDX
    //         005517f4     JMP        switchD_005517cd::default
    //                               switchD_005517cd::caseD_2                                    XREF[2]:     005517cd(j), 00551fd4(*)  
    //         005517f9     MOVSX      EAX,BL
    //         005517fc     ADD        EAX,-0x20
    //         005517ff     CMP        EAX,0x10
    //         00551802     JA         switchD_005517cd::default
    //         00551808     XOR        ECX,ECX
    //         0055180a     MOV        CL,byte ptr [EAX + 0x552004]=>PTR_caseD_6_0055   = 005518fa
    //                               switchD_00551810::switchD
    //         00551810     JMP        dword ptr [ECX*0x4 + switchD_00551810::switchd   = 00551835
    //                               switchD_00551810::caseD_2d                                   XREF[2]:     00551810(j), 00551ff8(*)  
    //         00551817     MOV        EAX,dword ptr [ESP + local_24c]
    //         0055181b     OR         AL,0x4
    //         0055181d     MOV        dword ptr [ESP + local_24c],EAX
    //         00551821     JMP        switchD_005517cd::default
    //                               switchD_00551810::caseD_2b                                   XREF[2]:     00551810(j), 00551ff4(*)  
    //         00551826     MOV        EAX,dword ptr [ESP + local_24c]
    //         0055182a     OR         AL,0x1
    //         0055182c     MOV        dword ptr [ESP + local_24c],EAX
    //         00551830     JMP        switchD_005517cd::default
    //                               switchD_00551810::caseD_20                                   XREF[2]:     00551810(j), 00551fec(*)  
    //         00551835     MOV        EAX,dword ptr [ESP + local_24c]
    //         00551839     OR         AL,0x2
    //         0055183b     MOV        dword ptr [ESP + local_24c],EAX
    //         0055183f     JMP        switchD_005517cd::default
    //                               switchD_00551810::caseD_23                                   XREF[2]:     00551810(j), 00551ff0(*)  
    //         00551844     MOV        EAX,dword ptr [ESP + local_24c]
    //         00551848     OR         AL,0x80
    //         0055184a     MOV        dword ptr [ESP + local_24c],EAX
    //         0055184e     JMP        switchD_005517cd::default
    //                               switchD_00551810::caseD_30                                   XREF[2]:     00551810(j), 00551ffc(*)  
    //         00551853     MOV        EAX,dword ptr [ESP + local_24c]
    //         00551857     OR         AL,0x8
    //         00551859     MOV        dword ptr [ESP + local_24c],EAX
    //         0055185d     JMP        switchD_005517cd::default
    //                               switchD_005517cd::caseD_3                                    XREF[2]:     005517cd(j), 00551fd8(*)  
    //         00551862     CMP        BL,0x2a
    //         00551865     JNZ        LAB_00551899
    //         00551867     LEA        EDX=>Stack[0xc],[ESP + 0x268]
    //         0055186e     PUSH       EDX
    //         0055186f     CALL       FUN_005521b0                                     undefined FUN_005521b0()
    //         00551874     ADD        ESP,0x4
    //         00551877     MOV        dword ptr [ESP + local_234],EAX
    //         0055187b     TEST       EAX,EAX
    //         0055187d     JGE        switchD_005517cd::default
    //         00551883     MOV        EDX,dword ptr [ESP + local_24c]
    //         00551887     OR         EDX,0x4
    //         0055188a     NEG        EAX
    //         0055188c     MOV        dword ptr [ESP + local_24c],EDX
    //         00551890     MOV        dword ptr [ESP + local_234],EAX
    //         00551894     JMP        switchD_005517cd::default
    //                               LAB_00551899                                                 XREF[1]:     00551865(j)  
    //         00551899     MOVSX      ECX,BL
    //         0055189c     LEA        EAX,[ESI + ESI*0x4]
    //         0055189f     LEA        EDX,[ECX + EAX*0x2 + -0x30]
    //         005518a3     MOV        dword ptr [ESP + local_234],EDX
    //         005518a7     JMP        switchD_005517cd::default
    //                               switchD_005517cd::caseD_4                                    XREF[2]:     005517cd(j), 00551fdc(*)  
    //         005518ac     MOV        dword ptr [ESP + local_244],EDX
    //         005518b0     JMP        switchD_005517cd::default
    //                               switchD_005517cd::caseD_5                                    XREF[2]:     005517cd(j), 00551fe0(*)  
    //         005518b5     CMP        BL,0x2a
    //         005518b8     JNZ        LAB_005518e3
    //         005518ba     LEA        EAX=>Stack[0xc],[ESP + 0x268]
    //         005518c1     PUSH       EAX
    //         005518c2     CALL       FUN_005521b0                                     undefined FUN_005521b0()
    //         005518c7     ADD        ESP,0x4
    //         005518ca     MOV        dword ptr [ESP + local_244],EAX
    //         005518ce     TEST       EAX,EAX
    //         005518d0     JGE        switchD_005517cd::default
    //         005518d6     MOV        dword ptr [ESP + local_244],0xffffffff
    //         005518de     JMP        switchD_005517cd::default
    //                               LAB_005518e3                                                 XREF[1]:     005518b8(j)  
    //         005518e3     MOV        EAX,dword ptr [ESP + local_244]
    //         005518e7     MOVSX      EDX,BL
    //         005518ea     LEA        ECX,[EAX + EAX*0x4]
    //         005518ed     LEA        EAX,[EDX + ECX*0x2 + -0x30]
    //         005518f1     MOV        dword ptr [ESP + local_244],EAX
    //         005518f5     JMP        switchD_005517cd::default
    //                               switchD_005517cd::caseD_6                                    XREF[2]:     005517cd(j), 00551fe4(*)  
    //         005518fa     MOVSX      EAX,BL
    //         005518fd     ADD        EAX,-0x49
    //         00551900     CMP        EAX,0x2e
    //         00551903     JA         switchD_005517cd::default
    //         00551909     XOR        ECX,ECX
    //         0055190b     MOV        CL,byte ptr [EAX + 0x55202c]=>PTR_caseD_5_0055
    //                               switchD_00551911::switchD
    //         00551911     JMP        dword ptr [ECX*0x4 + switchD_00551911::switchd   = 00551927
    //                               switchD_00551911::caseD_6c                                   XREF[2]:     00551911(j), 00552020(*)  
    //         00551918     MOV        EAX,dword ptr [ESP + local_24c]
    //         0055191c     OR         AL,0x10
    //         0055191e     MOV        dword ptr [ESP + local_24c],EAX
    //         00551922     JMP        switchD_005517cd::default
    //                               switchD_00551911::caseD_49                                   XREF[2]:     00551911(j), 00552018(*)  
    //         00551927     CMP        byte ptr [EDI],0x36
    //         0055192a     JNZ        LAB_0055194c
    //         0055192c     CMP        byte ptr [EDI + 0x1],0x34
    //         00551930     JNZ        LAB_0055194c
    //         00551932     MOV        EAX,dword ptr [ESP + local_24c]
    //         00551936     ADD        EDI,0x2
    //         00551939     OR         AH,0x80
    //         0055193c     MOV        dword ptr [ESP + Stack[0x8]],EDI
    //         00551943     MOV        dword ptr [ESP + local_24c],EAX
    //         00551947     JMP        switchD_005517cd::default
    //                               LAB_0055194c                                                 XREF[2]:     0055192a(j), 00551930(j)  
    //         0055194c     MOV        dword ptr [ESP + local_220],EDX
    //                               switchD_005517cd::caseD_0                                    XREF[2]:     005517cd(j), 00551fcc(*)  
    //         00551950     MOV        EAX,[__pctype]                                   = 005920da
    //         00551955     MOV        dword ptr [ESP + local_230],EDX
    //         00551959     MOV        EDX,dword ptr [ESP + local_21c]
    //         0055195d     AND        EDX,0xff
    //         00551963     TEST       byte ptr [EAX + EDX*0x2 + 0x1]=>DAT_005920db,0
    //         00551968     JZ         LAB_0055198d
    //         0055196a     MOV        EDX,dword ptr [ESP + Stack[0x4]]
    //         00551971     LEA        ECX=>local_240,[ESP + 0x1c]
    //         00551975     MOVSX      EAX,BL
    //         00551978     PUSH       ECX
    //         00551979     PUSH       EDX
    //         0055197a     PUSH       EAX
    //         0055197b     CALL       FUN_005520e0                                     undefined FUN_005520e0()
    //         00551980     MOV        BL,byte ptr [EDI]
    //         00551982     ADD        ESP,0xc
    //         00551985     INC        EDI
    //         00551986     MOV        dword ptr [ESP + Stack[0x8]],EDI
    //                               LAB_0055198d                                                 XREF[1]:     00551968(j)  
    //         0055198d     MOV        EDX,dword ptr [ESP + Stack[0x4]]
    //         00551994     LEA        ECX=>local_240,[ESP + 0x1c]
    //         00551998     MOVSX      EAX,BL
    //         0055199b     PUSH       ECX
    //         0055199c     PUSH       EDX
    //         0055199d     PUSH       EAX
    //         0055199e     CALL       FUN_005520e0                                     undefined FUN_005520e0()
    //         005519a3     ADD        ESP,0xc
    //         005519a6     JMP        switchD_005517cd::default
    //                               switchD_00551911::caseD_68                                   XREF[2]:     00551911(j), 0055201c(*)  
    //         005519ab     MOV        EAX,dword ptr [ESP + local_24c]
    //         005519af     OR         AL,0x20
    //         005519b1     MOV        dword ptr [ESP + local_24c],EAX
    //         005519b5     JMP        switchD_005517cd::default
    //                               switchD_00551911::caseD_77                                   XREF[2]:     00551911(j), 00552024(*)  
    //         005519ba     MOV        EAX,dword ptr [ESP + local_24c]
    //         005519be     OR         AH,0x8
    //         005519c1     MOV        dword ptr [ESP + local_24c],EAX
    //         005519c5     JMP        switchD_005517cd::default
    //                               switchD_005517cd::caseD_7                                    XREF[2]:     005517cd(j), 00551fe8(*)  
    //         005519ca     MOVSX      EAX,BL
    //         005519cd     ADD        EAX,-0x43
    //         005519d0     CMP        EAX,0x35
    //         005519d3     JA         switchD_005519e1::caseD_44
    //         005519d9     XOR        ECX,ECX
    //         005519db     MOV        CL,byte ptr [EAX + 0x5520a0]=>switchdataD_0055
    //                               switchD_005519e1::switchD
    //         005519e1     JMP        dword ptr [ECX*0x4 + switchD_005519e1::switchd   = 005519e8
    //                               switchD_005519e1::caseD_43                                   XREF[2]:     005519e1(j), 0055205c(*)  
    //         005519e8     MOV        EAX,dword ptr [ESP + local_24c]
    //         005519ec     TEST       EAX,0x830
    //         005519f1     JNZ        switchD_005519e1::caseD_63
    //         005519f3     OR         AH,0x8
    //         005519f6     MOV        dword ptr [ESP + local_24c],EAX
    //                               switchD_005519e1::caseD_63                                   XREF[3]:     005519e1(j), 005519f1(j), 
    //                                                                                                         00552074(*)  
    //         005519fa     TEST       dword ptr [ESP + local_24c],0x810
    //         00551a02     JZ         LAB_00551a3d
    //         00551a04     LEA        EDX=>Stack[0xc],[ESP + 0x268]
    //         00551a0b     PUSH       EDX
    //         00551a0c     CALL       FUN_005521f0                                     undefined FUN_005521f0()
    //         00551a11     ADD        ESP,0x4
    //         00551a14     PUSH       EAX
    //         00551a15     LEA        EAX=>local_200,[ESP + 0x60]
    //         00551a19     PUSH       EAX
    //         00551a1a     CALL       wctomb                                           undefined wctomb()
    //         00551a1f     MOV        EBP,EAX
    //         00551a21     ADD        ESP,0x8
    //         00551a24     TEST       EBP,EBP
    //         00551a26     JGE        LAB_00551a56
    //         00551a28     LEA        EDX=>local_200,[ESP + 0x5c]
    //         00551a2c     MOV        dword ptr [ESP + local_228],0x1
    //         00551a34     MOV        dword ptr [ESP + local_248],EDX
    //         00551a38     JMP        switchD_005519e1::caseD_44
    //                               LAB_00551a3d                                                 XREF[1]:     00551a02(j)  
    //         00551a3d     LEA        ECX=>Stack[0xc],[ESP + 0x268]
    //         00551a44     PUSH       ECX
    //         00551a45     CALL       FUN_005521b0                                     undefined FUN_005521b0()
    //         00551a4a     ADD        ESP,0x4
    //         00551a4d     MOV        byte ptr [ESP + local_200],AL
    //         00551a51     MOV        EBP,0x1
    //                               LAB_00551a56                                                 XREF[1]:     00551a26(j)  
    //         00551a56     LEA        EDX=>local_200,[ESP + 0x5c]
    //         00551a5a     MOV        dword ptr [ESP + local_248],EDX
    //         00551a5e     JMP        switchD_005519e1::caseD_44
    //                               switchD_005519e1::caseD_5a                                   XREF[2]:     005519e1(j), 00552070(*)  
    //         00551a63     LEA        EAX=>Stack[0xc],[ESP + 0x268]
    //         00551a6a     PUSH       EAX
    //         00551a6b     CALL       FUN_005521b0                                     undefined FUN_005521b0()
    //         00551a70     ADD        ESP,0x4
    //         00551a73     TEST       EAX,EAX
    //         00551a75     JZ         LAB_00551ab1
    //         00551a77     MOV        ECX,dword ptr [EAX + 0x4]
    //         00551a7a     TEST       ECX,ECX
    //         00551a7c     JZ         LAB_00551ab1
    //         00551a7e     MOV        EDX,dword ptr [ESP + local_24c]
    //         00551a82     TEST       DH,0x8
    //         00551a85     JZ         LAB_00551a9d
    //         00551a87     MOVSX      EBP,word ptr [EAX]
    //         00551a8a     MOV        dword ptr [ESP + local_248],ECX
    //         00551a8e     MOV        dword ptr [ESP + local_230],0x1
    //         00551a96     SHR        EBP,0x1
    //         00551a98     JMP        switchD_005519e1::caseD_44
    //                               LAB_00551a9d                                                 XREF[1]:     00551a85(j)  
    //         00551a9d     MOVSX      EBP,word ptr [EAX]
    //         00551aa0     MOV        dword ptr [ESP + local_230],0x0
    //         00551aa8     MOV        dword ptr [ESP + local_248],ECX
    //         00551aac     JMP        switchD_005519e1::caseD_44
    //                               LAB_00551ab1                                                 XREF[2]:     00551a75(j), 00551a7c(j)  
    //         00551ab1     MOV        EDI,dword ptr [->s_(null)]                       = 00577bcc
    //         00551ab7     OR         ECX,0xffffffff
    //         00551aba     XOR        EAX,EAX
    //         00551abc     MOV        dword ptr [ESP + local_248],EDI=>s_(null)        = 28h
    //         00551ac0     SCASB.RE   ES:EDI=>s_(null)                                 = 28h
    //                                                                                  = "null)"
    //         00551ac2     NOT        ECX
    //         00551ac4     DEC        ECX
    //         00551ac5     MOV        EBP,ECX
    //         00551ac7     JMP        switchD_005519e1::caseD_44
    //                               switchD_005519e1::caseD_53                                   XREF[2]:     005519e1(j), 00552068(*)  
    //         00551acc     MOV        EAX,dword ptr [ESP + local_24c]
    //         00551ad0     TEST       EAX,0x830
    //         00551ad5     JNZ        switchD_005519e1::caseD_73
    //         00551ad7     OR         AH,0x8
    //         00551ada     MOV        dword ptr [ESP + local_24c],EAX
    //                               switchD_005519e1::caseD_73                                   XREF[3]:     005519e1(j), 00551ad5(j), 
    //                                                                                                         00552090(*)  
    //         00551ade     MOV        EAX,dword ptr [ESP + local_244]
    //         00551ae2     MOV        ESI,0x7fffffff
    //         00551ae7     CMP        EAX,-0x1
    //         00551aea     JZ         LAB_00551aee
    //         00551aec     MOV        ESI,EAX
    //                               LAB_00551aee                                                 XREF[1]:     00551aea(j)  
    //         00551aee     LEA        ECX=>Stack[0xc],[ESP + 0x268]
    //         00551af5     PUSH       ECX
    //         00551af6     CALL       FUN_005521b0                                     undefined FUN_005521b0()
    //         00551afb     MOV        ECX,EAX
    //         00551afd     MOV        EAX,dword ptr [ESP + local_24c]
    //         00551b01     ADD        ESP,0x4
    //         00551b04     MOV        dword ptr [ESP + local_248],ECX
    //         00551b08     TEST       EAX,0x810
    //         00551b0d     JZ         LAB_00551b49
    //         00551b0f     TEST       ECX,ECX
    //         00551b11     JNZ        LAB_00551b1d
    //         00551b13     MOV        ECX,dword ptr [->u_(null)]                       = 00577bbc
    //         00551b19     MOV        dword ptr [ESP + local_248],ECX=>u_(null)        = 0028h
    //                               LAB_00551b1d                                                 XREF[1]:     00551b11(j)  
    //         00551b1d     MOV        EDX,ESI
    //         00551b1f     DEC        ESI
    //         00551b20     TEST       EDX,EDX
    //         00551b22     MOV        dword ptr [ESP + local_230],0x1
    //         00551b2a     MOV        EAX,ECX
    //         00551b2c     JZ         LAB_00551b3e
    //                               LAB_00551b2e                                                 XREF[1]:     00551b3c(j)  
    //         00551b2e     CMP        word ptr [EAX]=>u_(null),0x0                     = 0028h
    //                                                                                  = u"null)"
    //         00551b32     JZ         LAB_00551b3e
    //         00551b34     ADD        EAX,0x2
    //         00551b37     MOV        EDX,ESI
    //         00551b39     DEC        ESI
    //         00551b3a     TEST       EDX,EDX
    //         00551b3c     JNZ        LAB_00551b2e
    //                               LAB_00551b3e                                                 XREF[2]:     00551b2c(j), 00551b32(j)  
    //         00551b3e     SUB        EAX,ECX
    //         00551b40     SAR        EAX,0x1
    //         00551b42     MOV        EBP,EAX
    //         00551b44     JMP        switchD_005519e1::caseD_44
    //                               LAB_00551b49                                                 XREF[1]:     00551b0d(j)  
    //         00551b49     TEST       ECX,ECX
    //         00551b4b     JNZ        LAB_00551b57
    //         00551b4d     MOV        ECX,dword ptr [->s_(null)]                       = 00577bcc
    //         00551b53     MOV        dword ptr [ESP + local_248],ECX=>s_(null)        = 28h
    //                               LAB_00551b57                                                 XREF[1]:     00551b4b(j)  
    //         00551b57     MOV        EDX,ESI
    //         00551b59     DEC        ESI
    //         00551b5a     TEST       EDX,EDX
    //         00551b5c     MOV        EAX,ECX
    //         00551b5e     JZ         LAB_00551b6d
    //                               LAB_00551b60                                                 XREF[1]:     00551b6b(j)  
    //         00551b60     CMP        byte ptr [EAX]=>s_(null),0x0                     = 28h
    //                                                                                  = "null)"
    //         00551b63     JZ         LAB_00551b6d
    //         00551b65     INC        EAX
    //         00551b66     MOV        EDX,ESI
    //         00551b68     DEC        ESI
    //         00551b69     TEST       EDX,EDX
    //         00551b6b     JNZ        LAB_00551b60
    //                               LAB_00551b6d                                                 XREF[2]:     00551b5e(j), 00551b63(j)  
    //         00551b6d     SUB        EAX,ECX
    //         00551b6f     MOV        EBP,EAX
    //         00551b71     JMP        switchD_005519e1::caseD_44
    //                               switchD_005519e1::caseD_6e                                   XREF[2]:     005519e1(j), 00552084(*)  
    //         00551b76     LEA        EAX=>Stack[0xc],[ESP + 0x268]
    //         00551b7d     PUSH       EAX
    //         00551b7e     CALL       FUN_005521b0                                     undefined FUN_005521b0()
    //         00551b83     MOV        CL,byte ptr [ESP + local_24c]
    //         00551b87     ADD        ESP,0x4
    //         00551b8a     TEST       CL,0x20
    //         00551b8d     JZ         LAB_00551ba4
    //         00551b8f     MOV        CX,word ptr [ESP + local_240]
    //         00551b94     MOV        dword ptr [ESP + local_228],0x1
    //         00551b9c     MOV        word ptr [EAX],CX
    //         00551b9f     JMP        switchD_005519e1::caseD_44
    //                               LAB_00551ba4                                                 XREF[1]:     00551b8d(j)  
    //         00551ba4     MOV        EDX,dword ptr [ESP + local_240]
    //         00551ba8     MOV        dword ptr [ESP + local_228],0x1
    //         00551bb0     MOV        dword ptr [EAX],EDX
    //         00551bb2     JMP        switchD_005519e1::caseD_44
    //                               switchD_005519e1::caseD_47                                   XREF[3]:     005519e1(j), 00552060(*), 
    //                               switchD_005519e1::caseD_45                                                00552064(*)  
    //         00551bb7     MOV        dword ptr [ESP + local_218],0x1
    //         00551bbf     ADD        BL,0x20
    //                               switchD_005519e1::caseD_66                                   XREF[2]:     005519e1(j), 0055207c(*)  
    //                               switchD_005519e1::caseD_67
    //                               switchD_005519e1::caseD_65
    //         00551bc2     MOV        EDX,dword ptr [ESP + local_24c]
    //         00551bc6     LEA        EAX=>local_200,[ESP + 0x5c]
    //         00551bca     MOV        dword ptr [ESP + local_248],EAX
    //         00551bce     MOV        EAX,dword ptr [ESP + local_244]
    //         00551bd2     OR         EDX,0x40
    //         00551bd5     TEST       EAX,EAX
    //         00551bd7     MOV        dword ptr [ESP + local_24c],EDX
    //         00551bdb     JGE        LAB_00551be7
    //         00551bdd     MOV        dword ptr [ESP + local_244],0x6
    //         00551be5     JMP        LAB_00551bf6
    //                               LAB_00551be7                                                 XREF[1]:     00551bdb(j)  
    //         00551be7     JNZ        LAB_00551bf6
    //         00551be9     CMP        BL,0x67
    //         00551bec     JNZ        LAB_00551bf6
    //         00551bee     MOV        dword ptr [ESP + local_244],0x1
    //                               LAB_00551bf6                                                 XREF[3]:     00551be5(j), 00551be7(j), 
    //                                                                                                         00551bec(j)  
    //         00551bf6     MOV        EAX,dword ptr [ESP + Stack[0xc]]
    //         00551bfd     MOV        EDI,dword ptr [ESP + local_244]
    //         00551c01     ADD        EAX,0x8
    //         00551c04     MOV        dword ptr [ESP + Stack[0xc]],EAX
    //         00551c0b     MOV        ECX,dword ptr [EAX + -0x8]
    //         00551c0e     MOV        dword ptr [ESP + local_210],ECX
    //         00551c12     MOV        EDX,dword ptr [EAX + -0x4]
    //         00551c15     MOV        EAX,dword ptr [ESP + local_218]
    //         00551c19     MOV        dword ptr [ESP + local_20c],EDX
    //         00551c1d     MOVSX      ECX,BL
    //         00551c20     PUSH       EAX
    //         00551c21     PUSH       EDI
    //         00551c22     LEA        EDX=>local_200,[ESP + 0x64]
    //         00551c26     PUSH       ECX
    //         00551c27     LEA        EAX=>local_210,[ESP + 0x58]
    //         00551c2b     PUSH       EDX
    //         00551c2c     PUSH       EAX
    //         00551c2d     CALL       dword ptr [->__fptrap]                           undefined __fptrap()
    //                                                                                  = 00558110
    //         00551c33     MOV        ESI,dword ptr [ESP + 0x24]
    //         00551c37     ADD        ESP,0x14
    //         00551c3a     AND        ESI,0x80
    //         00551c40     JZ         LAB_00551c54
    //         00551c42     TEST       EDI,EDI
    //         00551c44     JNZ        LAB_00551c54
    //         00551c46     LEA        ECX,[ESP + 0x5c]
    //         00551c4a     PUSH       ECX
    //         00551c4b     CALL       dword ptr [->__fptrap]                           undefined __fptrap()
    //                                                                                  = 00558110
    //         00551c51     ADD        ESP,0x4
    //                               LAB_00551c54                                                 XREF[2]:     00551c40(j), 00551c44(j)  
    //         00551c54     CMP        BL,0x67
    //         00551c57     JNZ        LAB_00551c6b
    //         00551c59     TEST       ESI,ESI
    //         00551c5b     JNZ        LAB_00551c6b
    //         00551c5d     LEA        EDX,[ESP + 0x5c]
    //         00551c61     PUSH       EDX
    //         00551c62     CALL       dword ptr [->__fptrap]                           undefined __fptrap()
    //                                                                                  = 00558110
    //         00551c68     ADD        ESP,0x4
    //                               LAB_00551c6b                                                 XREF[2]:     00551c57(j), 00551c5b(j)  
    //         00551c6b     CMP        byte ptr [ESP + 0x5c],0x2d
    //         00551c70     JNZ        LAB_00551c85
    //         00551c72     MOV        EAX,dword ptr [ESP + 0x10]
    //         00551c76     OR         AH,0x1
    //         00551c79     MOV        dword ptr [ESP + 0x10],EAX
    //         00551c7d     LEA        EAX,[ESP + 0x5d]
    //         00551c81     MOV        dword ptr [ESP + 0x14],EAX
    //                               LAB_00551c85                                                 XREF[1]:     00551c70(j)  
    //         00551c85     MOV        EDI,dword ptr [ESP + 0x14]
    //         00551c89     OR         ECX,0xffffffff
    //         00551c8c     XOR        EAX,EAX
    //         00551c8e     SCASB.RE   ES:EDI
    //         00551c90     NOT        ECX
    //         00551c92     DEC        ECX
    //         00551c93     MOV        EBP,ECX
    //         00551c95     JMP        switchD_005519e1::caseD_44
    //                               switchD_005519e1::caseD_69                                   XREF[3]:     005519e1(j), 00552078(*), 
    //                               switchD_005519e1::caseD_64                                                00552080(*)  
    //         00551c9a     MOV        EAX,dword ptr [ESP + local_24c]
    //         00551c9e     MOV        dword ptr [ESP + local_22c],0xa
    //         00551ca6     OR         AL,0x40
    //         00551ca8     MOV        dword ptr [ESP + local_24c],EAX
    //         00551cac     JMP        LAB_00551d17
    //                               switchD_005519e1::caseD_75                                   XREF[2]:     005519e1(j), 00552094(*)  
    //         00551cae     MOV        dword ptr [ESP + local_22c],0xa
    //         00551cb6     JMP        LAB_00551d17
    //                               switchD_005519e1::caseD_70                                   XREF[2]:     005519e1(j), 0055208c(*)  
    //         00551cb8     MOV        dword ptr [ESP + local_244],0x8
    //                               switchD_005519e1::caseD_58                                   XREF[2]:     005519e1(j), 0055206c(*)  
    //         00551cc0     MOV        dword ptr [ESP + local_224],0x7
    //         00551cc8     JMP        LAB_00551cd2
    //                               switchD_005519e1::caseD_78                                   XREF[2]:     005519e1(j), 00552098(*)  
    //         00551cca     MOV        dword ptr [ESP + local_224],0x27
    //                               LAB_00551cd2                                                 XREF[1]:     00551cc8(j)  
    //         00551cd2     MOV        AL,byte ptr [ESP + local_24c]
    //         00551cd6     MOV        dword ptr [ESP + local_22c],0x10
    //         00551cde     TEST       AL,0x80
    //         00551ce0     JZ         LAB_00551d17
    //         00551ce2     MOV        CL,byte ptr [ESP + local_224]
    //         00551ce6     MOV        byte ptr [ESP + local_23a],0x30
    //         00551ceb     ADD        CL,0x51
    //         00551cee     MOV        dword ptr [ESP + local_238],0x2
    //         00551cf6     MOV        byte ptr [ESP + local_239],CL
    //         00551cfa     JMP        LAB_00551d17
    //                               switchD_005519e1::caseD_6f                                   XREF[2]:     005519e1(j), 00552088(*)  
    //         00551cfc     MOV        AL,byte ptr [ESP + local_24c]
    //         00551d00     MOV        dword ptr [ESP + local_22c],0x8
    //         00551d08     TEST       AL,0x80
    //         00551d0a     JZ         LAB_00551d17
    //         00551d0c     MOV        EAX,dword ptr [ESP + local_24c]
    //         00551d10     OR         AH,0x2
    //         00551d13     MOV        dword ptr [ESP + local_24c],EAX
    //                               LAB_00551d17                                                 XREF[5]:     00551cac(j), 00551cb6(j), 
    //                                                                                                         00551ce0(j), 00551cfa(j), 
    //                                                                                                         00551d0a(j)  
    //         00551d17     MOV        EBX,dword ptr [ESP + local_24c]
    //         00551d1b     TEST       BH,0x80
    //         00551d1e     JZ         LAB_00551d32
    //         00551d20     LEA        EDX=>Stack[0xc],[ESP + 0x268]
    //         00551d27     PUSH       EDX
    //         00551d28     CALL       FUN_005521d0                                     undefined FUN_005521d0()
    //         00551d2d     ADD        ESP,0x4
    //         00551d30     JMP        LAB_00551d94
    //                               LAB_00551d32                                                 XREF[1]:     00551d1e(j)  
    //         00551d32     TEST       BL,0x20
    //         00551d35     JZ         LAB_00551d6a
    //         00551d37     TEST       BL,0x40
    //         00551d3a     JZ         LAB_00551d52
    //         00551d3c     LEA        EAX=>Stack[0xc],[ESP + 0x268]
    //         00551d43     PUSH       EAX
    //         00551d44     CALL       FUN_005521b0                                     undefined FUN_005521b0()
    //         00551d49     MOVSX      EAX,AX
    //         00551d4c     ADD        ESP,0x4
    //         00551d4f     CDQ
    //         00551d50     JMP        LAB_00551d94
    //                               LAB_00551d52                                                 XREF[1]:     00551d3a(j)  
    //         00551d52     LEA        ECX=>Stack[0xc],[ESP + 0x268]
    //         00551d59     PUSH       ECX
    //         00551d5a     CALL       FUN_005521b0                                     undefined FUN_005521b0()
    //         00551d5f     ADD        ESP,0x4
    //         00551d62     AND        EAX,0xffff
    //         00551d67     CDQ
    //         00551d68     JMP        LAB_00551d94
    //                               LAB_00551d6a                                                 XREF[1]:     00551d35(j)  
    //         00551d6a     TEST       BL,0x40
    //         00551d6d     JZ         LAB_00551d82
    //         00551d6f     LEA        EDX=>Stack[0xc],[ESP + 0x268]
    //         00551d76     PUSH       EDX
    //         00551d77     CALL       FUN_005521b0                                     undefined FUN_005521b0()
    //         00551d7c     ADD        ESP,0x4
    //         00551d7f     CDQ
    //         00551d80     JMP        LAB_00551d94
    //                               LAB_00551d82                                                 XREF[1]:     00551d6d(j)  
    //         00551d82     LEA        EAX=>Stack[0xc],[ESP + 0x268]
    //         00551d89     PUSH       EAX
    //         00551d8a     CALL       FUN_005521b0                                     undefined FUN_005521b0()
    //         00551d8f     ADD        ESP,0x4
    //         00551d92     XOR        EDX,EDX
    //                               LAB_00551d94                                                 XREF[4]:     00551d30(j), 00551d50(j), 
    //                                                                                                         00551d68(j), 00551d80(j)  
    //         00551d94     TEST       BL,0x40
    //         00551d97     JZ         LAB_00551db7
    //         00551d99     TEST       EDX,EDX
    //         00551d9b     JG         LAB_00551db7
    //         00551d9d     JL         LAB_00551da3
    //         00551d9f     TEST       EAX,EAX
    //         00551da1     JNC        LAB_00551db7
    //                               LAB_00551da3                                                 XREF[1]:     00551d9d(j)  
    //         00551da3     NEG        EAX
    //         00551da5     ADC        EDX,0x0
    //         00551da8     MOV        ESI,EAX
    //         00551daa     NEG        EDX
    //         00551dac     OR         BH,0x1
    //         00551daf     MOV        EDI,EDX
    //         00551db1     MOV        dword ptr [ESP + local_24c],EBX
    //         00551db5     JMP        LAB_00551dbb
    //                               LAB_00551db7                                                 XREF[3]:     00551d97(j), 00551d9b(j), 
    //                                                                                                         00551da1(j)  
    //         00551db7     MOV        ESI,EAX
    //         00551db9     MOV        EDI,EDX
    //                               LAB_00551dbb                                                 XREF[1]:     00551db5(j)  
    //         00551dbb     TEST       BH,0x80
    //         00551dbe     JNZ        LAB_00551dc3
    //         00551dc0     AND        EDI,0x0
    //                               LAB_00551dc3                                                 XREF[1]:     00551dbe(j)  
    //         00551dc3     MOV        ECX,dword ptr [ESP + local_244]
    //         00551dc7     TEST       ECX,ECX
    //         00551dc9     JGE        LAB_00551dd2
    //         00551dcb     MOV        ECX,0x1
    //         00551dd0     JMP        LAB_00551dd9
    //                               LAB_00551dd2                                                 XREF[1]:     00551dc9(j)  
    //         00551dd2     AND        EBX,0xfffffff7
    //         00551dd5     MOV        dword ptr [ESP + local_24c],EBX
    //                               LAB_00551dd9                                                 XREF[1]:     00551dd0(j)  
    //         00551dd9     MOV        EDX,ESI
    //         00551ddb     OR         EDX,EDI
    //         00551ddd     JNZ        LAB_00551de7
    //         00551ddf     MOV        dword ptr [ESP + local_238],0x0
    //                               LAB_00551de7                                                 XREF[1]:     00551ddd(j)  
    //         00551de7     LEA        EAX=>local_2+0x1,[ESP + 0x25b]
    //         00551dee     MOV        dword ptr [ESP + local_248],EAX
    //                               LAB_00551df2                                                 XREF[1]:     00551e45(j)  
    //         00551df2     MOV        EDX,ECX
    //         00551df4     DEC        ECX
    //         00551df5     TEST       EDX,EDX
    //         00551df7     MOV        dword ptr [ESP + local_244],ECX
    //         00551dfb     JG         LAB_00551e03
    //         00551dfd     MOV        ECX,ESI
    //         00551dff     OR         ECX,EDI
    //         00551e01     JZ         LAB_00551e47
    //                               LAB_00551e03                                                 XREF[1]:     00551dfb(j)  
    //         00551e03     MOV        EAX,dword ptr [ESP + local_22c]
    //         00551e07     CDQ
    //         00551e08     MOV        EBP,EAX
    //         00551e0a     PUSH       EDX
    //         00551e0b     PUSH       EBP
    //         00551e0c     PUSH       EDI
    //         00551e0d     PUSH       ESI
    //         00551e0e     MOV        dword ptr [ESP + local_204],EDX
    //         00551e12     CALL       __aullrem                                        undefined __aullrem()
    //         00551e17     MOV        EDX,dword ptr [ESP + local_204]
    //         00551e1b     MOV        EBX,EAX
    //         00551e1d     PUSH       EDX
    //         00551e1e     PUSH       EBP
    //         00551e1f     PUSH       EDI
    //         00551e20     PUSH       ESI
    //         00551e21     ADD        EBX,0x30
    //         00551e24     CALL       __aulldiv                                        undefined __aulldiv()
    //         00551e29     CMP        EBX,0x39
    //         00551e2c     MOV        ESI,EAX
    //         00551e2e     MOV        EDI,EDX
    //         00551e30     JLE        LAB_00551e36
    //         00551e32     ADD        EBX,dword ptr [ESP + local_224]
    //                               LAB_00551e36                                                 XREF[1]:     00551e30(j)  
    //         00551e36     MOV        EAX,dword ptr [ESP + local_248]
    //         00551e3a     MOV        ECX,dword ptr [ESP + local_244]
    //         00551e3e     MOV        byte ptr [EAX]=>local_2+0x1,BL
    //         00551e40     DEC        EAX
    //         00551e41     MOV        dword ptr [ESP + local_248],EAX
    //         00551e45     JMP        LAB_00551df2
    //                               LAB_00551e47                                                 XREF[1]:     00551e01(j)  
    //         00551e47     MOV        ECX,dword ptr [ESP + local_24c]
    //         00551e4b     LEA        EBP=>local_2+0x1,[ESP + 0x25b]
    //         00551e52     SUB        EBP,EAX
    //         00551e54     INC        EAX
    //         00551e55     TEST       CH,0x2
    //         00551e58     MOV        dword ptr [ESP + local_248],EAX
    //         00551e5c     JZ         switchD_005519e1::caseD_44
    //         00551e5e     CMP        byte ptr [EAX]=>local_2+0x1,0x30
    //         00551e61     JNZ        LAB_00551e67
    //         00551e63     TEST       EBP,EBP
    //         00551e65     JNZ        switchD_005519e1::caseD_44
    //                               LAB_00551e67                                                 XREF[1]:     00551e61(j)  
    //         00551e67     DEC        EAX
    //         00551e68     INC        EBP
    //         00551e69     MOV        dword ptr [ESP + local_248],EAX
    //         00551e6d     MOV        byte ptr [EAX]=>local_2,0x30
    //                               switchD_005519e1::caseD_46                                   XREF[15]:    005519d3(j), 005519e1(j), 
    //                               switchD_005519e1::caseD_48                                                00551a38(j), 00551a5e(j), 
    //                               switchD_005519e1::caseD_49                                                00551a98(j), 00551aac(j), 
    //                               switchD_005519e1::caseD_4a                                                00551ac7(j), 00551b44(j), 
    //                               switchD_005519e1::caseD_4b                                                00551b71(j), 00551b9f(j), 
    //                               switchD_005519e1::caseD_4c                                                00551bb2(j), 00551c95(j), 
    //                               switchD_005519e1::caseD_4d                                                00551e5c(j), 00551e65(j), 
    //                               switchD_005519e1::caseD_4e                                                0055209c(*)  
    //                               switchD_005519e1::caseD_4f
    //                               switchD_005519e1::caseD_50
    //                               switchD_005519e1::caseD_51
    //                               switchD_005519e1::caseD_52
    //                               switchD_005519e1::caseD_54
    //                               switchD_005519e1::caseD_55
    //                               switchD_005519e1::caseD_56
    //                               switchD_005519e1::caseD_57
    //                               switchD_005519e1::caseD_59
    //                               switchD_005519e1::caseD_5b
    //                               switchD_005519e1::caseD_5c
    //                               switchD_005519e1::caseD_5d
    //                               switchD_005519e1::caseD_5e
    //                               switchD_005519e1::caseD_5f
    //                               switchD_005519e1::caseD_60
    //                               switchD_005519e1::caseD_61
    //                               switchD_005519e1::caseD_62
    //                               switchD_005519e1::caseD_68
    //                               switchD_005519e1::caseD_6a
    //                               switchD_005519e1::caseD_6b
    //                               switchD_005519e1::caseD_6c
    //                               switchD_005519e1::caseD_6d
    //                               switchD_005519e1::caseD_71
    //                               switchD_005519e1::caseD_72
    //                               switchD_005519e1::caseD_74
    //                               switchD_005519e1::caseD_76
    //                               switchD_005519e1::caseD_77
    //                               switchD_005519e1::caseD_44
    //         00551e70     MOV        EAX,dword ptr [ESP + local_228]
    //         00551e74     TEST       EAX,EAX
    //         00551e76     JNZ        switchD_005517cd::default
    //         00551e7c     MOV        EBX,dword ptr [ESP + local_24c]
    //         00551e80     TEST       BL,0x40
    //         00551e83     JZ         LAB_00551eaf
    //         00551e85     TEST       BH,0x1
    //         00551e88     JZ         LAB_00551e91
    //         00551e8a     MOV        byte ptr [ESP + local_23a],0x2d
    //         00551e8f     JMP        LAB_00551ea7
    //                               LAB_00551e91                                                 XREF[1]:     00551e88(j)  
    //         00551e91     TEST       BL,0x1
    //         00551e94     JZ         LAB_00551e9d
    //         00551e96     MOV        byte ptr [ESP + local_23a],0x2b
    //         00551e9b     JMP        LAB_00551ea7
    //                               LAB_00551e9d                                                 XREF[1]:     00551e94(j)  
    //         00551e9d     TEST       BL,0x2
    //         00551ea0     JZ         LAB_00551eaf
    //         00551ea2     MOV        byte ptr [ESP + local_23a],0x20
    //                               LAB_00551ea7                                                 XREF[2]:     00551e8f(j), 00551e9b(j)  
    //         00551ea7     MOV        dword ptr [ESP + local_238],0x1
    //                               LAB_00551eaf                                                 XREF[2]:     00551e83(j), 00551ea0(j)  
    //         00551eaf     MOV        EDI,dword ptr [ESP + local_234]
    //         00551eb3     MOV        EDX,dword ptr [ESP + local_238]
    //         00551eb7     SUB        EDI,EDX
    //         00551eb9     SUB        EDI,EBP
    //         00551ebb     TEST       BL,0xc
    //         00551ebe     JNZ        LAB_00551eda
    //         00551ec0     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         00551ec7     LEA        EAX=>local_240,[ESP + 0x1c]
    //         00551ecb     PUSH       EAX
    //         00551ecc     PUSH       ESI
    //         00551ecd     PUSH       EDI
    //         00551ece     PUSH       0x20
    //         00551ed0     CALL       FUN_00552130                                     undefined FUN_00552130()
    //         00551ed5     ADD        ESP,0x10
    //         00551ed8     JMP        LAB_00551ee1
    //                               LAB_00551eda                                                 XREF[1]:     00551ebe(j)  
    //         00551eda     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //                               LAB_00551ee1                                                 XREF[1]:     00551ed8(j)  
    //         00551ee1     MOV        EDX,dword ptr [ESP + local_238]
    //         00551ee5     LEA        ECX=>local_240,[ESP + 0x1c]
    //         00551ee9     PUSH       ECX
    //         00551eea     PUSH       ESI
    //         00551eeb     LEA        EAX=>local_23a,[ESP + 0x2a]
    //         00551eef     PUSH       EDX
    //         00551ef0     PUSH       EAX
    //         00551ef1     CALL       FUN_00552170                                     undefined FUN_00552170()
    //         00551ef6     ADD        ESP,0x10
    //         00551ef9     TEST       BL,0x8
    //         00551efc     JZ         LAB_00551f14
    //         00551efe     TEST       BL,0x4
    //         00551f01     JNZ        LAB_00551f14
    //         00551f03     LEA        ECX=>local_240,[ESP + 0x1c]
    //         00551f07     PUSH       ECX
    //         00551f08     PUSH       ESI
    //         00551f09     PUSH       EDI
    //         00551f0a     PUSH       0x30
    //         00551f0c     CALL       FUN_00552130                                     undefined FUN_00552130()
    //         00551f11     ADD        ESP,0x10
    //                               LAB_00551f14                                                 XREF[2]:     00551efc(j), 00551f01(j)  
    //         00551f14     MOV        EAX,dword ptr [ESP + local_230]
    //         00551f18     TEST       EAX,EAX
    //         00551f1a     JZ         LAB_00551fb6
    //         00551f20     TEST       EBP,EBP
    //         00551f22     JLE        LAB_00551fb6
    //         00551f28     MOV        ESI,dword ptr [ESP + local_248]
    //         00551f2c     LEA        EBX,[EBP + -0x1]
    //                               LAB_00551f2f                                                 XREF[1]:     00551f67(j)  
    //         00551f2f     MOV        AX,word ptr [ESI]=>local_2
    //         00551f32     LEA        EDX=>local_214,[ESP + 0x48]
    //         00551f36     PUSH       EAX
    //         00551f37     PUSH       EDX
    //         00551f38     ADD        ESI,0x2
    //         00551f3b     CALL       wctomb                                           undefined wctomb()
    //         00551f40     ADD        ESP,0x8
    //         00551f43     TEST       EAX,EAX
    //         00551f45     JLE        LAB_00551f69
    //         00551f47     MOV        EDX,dword ptr [ESP + Stack[0x4]]
    //         00551f4e     LEA        ECX=>local_240,[ESP + 0x1c]
    //         00551f52     PUSH       ECX
    //         00551f53     PUSH       EDX
    //         00551f54     PUSH       EAX
    //         00551f55     LEA        EAX=>local_214,[ESP + 0x54]
    //         00551f59     PUSH       EAX
    //         00551f5a     CALL       FUN_00552170                                     undefined FUN_00552170()
    //         00551f5f     ADD        ESP,0x10
    //         00551f62     MOV        ECX,EBX
    //         00551f64     DEC        EBX
    //         00551f65     TEST       ECX,ECX
    //         00551f67     JNZ        LAB_00551f2f
    //                               LAB_00551f69                                                 XREF[1]:     00551f45(j)  
    //         00551f69     MOV        EBX,dword ptr [ESP + local_24c]
    //                               LAB_00551f6d                                                 XREF[1]:     00551fca(j)  
    //         00551f6d     TEST       BL,0x4
    //         00551f70     JZ         switchD_005517cd::default
    //         00551f72     MOV        EDX,dword ptr [ESP + Stack[0x4]]
    //         00551f79     LEA        ECX=>local_240,[ESP + 0x1c]
    //         00551f7d     PUSH       ECX
    //         00551f7e     PUSH       EDX
    //         00551f7f     PUSH       EDI
    //         00551f80     PUSH       0x20
    //         00551f82     CALL       FUN_00552130                                     undefined FUN_00552130()
    //         00551f87     ADD        ESP,0x10
    //                               switchD_00551911::caseD_4a                                   XREF[27]:    005517c7(j), 005517f4(j), 
    //                               switchD_00551911::caseD_4b                                                00551802(j), 0055187d(j), 
    //                               switchD_00551911::caseD_4c                                                00551894(j), 005518a7(j), 
    //                               switchD_00551911::caseD_4d                                                005518b0(j), 005518d0(j), 
    //                               switchD_00551911::caseD_4e                                                005518de(j), 005518f5(j), 
    //                               switchD_00551911::caseD_4f                                                00551903(j), 00551911(j), 
    //                               switchD_00551911::caseD_50                                                00551922(j), 00551947(j), 
    //                               switchD_00551911::caseD_51                                                005519a6(j), 005519b5(j), 
    //                               switchD_00551911::caseD_52                                                005519c5(j), 00551e76(j), 
    //                               switchD_00551911::caseD_53                                                00551f70(j), 00552000(*), [more]
    //                               switchD_00551911::caseD_54
    //                               switchD_00551911::caseD_55
    //                               switchD_00551911::caseD_56
    //                               switchD_00551911::caseD_57
    //                               switchD_00551911::caseD_58
    //                               switchD_00551911::caseD_59
    //                               switchD_00551911::caseD_5a
    //                               switchD_00551911::caseD_5b
    //                               switchD_00551911::caseD_5c
    //                               switchD_00551911::caseD_5d
    //                               switchD_00551911::caseD_5e
    //                               switchD_00551911::caseD_5f
    //                               switchD_00551911::caseD_60
    //                               switchD_00551911::caseD_61
    //                               switchD_00551911::caseD_62
    //                               switchD_00551911::caseD_63
    //                               switchD_00551911::caseD_64
    //                               switchD_00551911::caseD_65
    //                               switchD_00551911::caseD_66
    //                               switchD_00551911::caseD_67
    //                               switchD_00551911::caseD_69
    //                               switchD_00551911::caseD_6a
    //                               switchD_00551911::caseD_6b
    //                               switchD_00551911::caseD_6d
    //                               switchD_00551911::caseD_6e
    //                               switchD_00551911::caseD_6f
    //                               switchD_00551911::caseD_70
    //                               switchD_00551911::caseD_71
    //                               switchD_00551911::caseD_72
    //                               switchD_00551911::caseD_73
    //                               switchD_00551911::caseD_74
    //                               switchD_00551911::caseD_75
    //                               switchD_00551911::caseD_76
    //                               switchD_00551810::caseD_21
    //                               switchD_00551810::caseD_22
    //                               switchD_00551810::caseD_24
    //                               switchD_00551810::caseD_25
    //                               switchD_00551810::caseD_26
    //                               switchD_00551810::caseD_27
    //                               switchD_00551810::caseD_28
    //                               switchD_00551810::caseD_29
    //                               switchD_00551810::caseD_2a
    //                               switchD_00551810::caseD_2c
    //                               switchD_00551810::caseD_2e
    //                               switchD_00551810::caseD_2f
    //                               switchD_005517cd::default
    //         00551f8a     MOV        EDI,dword ptr [ESP + Stack[0x8]]
    //         00551f91     MOV        BL,byte ptr [EDI]
    //         00551f93     INC        EDI
    //         00551f94     TEST       BL,BL
    //         00551f96     MOV        byte ptr [ESP + local_21c],BL
    //         00551f9a     MOV        dword ptr [ESP + Stack[0x8]],EDI
    //         00551fa1     JNZ        LAB_00551785
    //                               LAB_00551fa7                                                 XREF[2]:     00551779(j), 00551795(j)  
    //         00551fa7     MOV        EAX,dword ptr [ESP + local_240]
    //         00551fab     POP        EDI
    //         00551fac     POP        ESI
    //         00551fad     POP        EBP
    //         00551fae     POP        EBX
    //         00551faf     ADD        ESP,0x24c
    //         00551fb5     RET
    //                               LAB_00551fb6                                                 XREF[2]:     00551f1a(j), 00551f22(j)  
    //         00551fb6     MOV        EAX,dword ptr [ESP + local_248]
    //         00551fba     LEA        EDX=>local_240,[ESP + 0x1c]
    //         00551fbe     PUSH       EDX
    //         00551fbf     PUSH       ESI
    //         00551fc0     PUSH       EBP
    //         00551fc1     PUSH       EAX
    //         00551fc2     CALL       FUN_00552170                                     undefined FUN_00552170()
    //         00551fc7     ADD        ESP,0x10
    //         00551fca     JMP        LAB_00551f6d
    //                               switchD_005517cd::switchdataD_00551fcc                       XREF[1]:     __output:005517cd(*)  
}

